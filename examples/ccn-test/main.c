/*
 * Copyright (C) 2015 Inria
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     examples
 * @{
 *
 * @file
 * @brief       Basic ccn-lite relay example (produce and consumer via shell)
 *
 * @author      Oliver Hahm <oliver.hahm@inria.fr>
 *
 * @}
 */

#include <stdio.h>

#include "tlsf-malloc.h"
#include "msg.h"
#include "shell.h"
#include "ccn-lite-riot.h"
#include "net/gnrc/netif.h"

#include "random.h"
#include "sched.h"
#include "ccnl-pkt-ndntlv.h"

/* main thread's message queue */
#define MAIN_QUEUE_SIZE     (8)
static msg_t _main_msg_queue[MAIN_QUEUE_SIZE];

/* 10kB buffer for the heap should be enough for everyone */
#define TLSF_BUFFER     (10240 / sizeof(uint32_t))
static uint32_t _tlsf_heap[TLSF_BUFFER];

static char _name[32] = "test";

static int ros_set_name(int argc, char** argv) {
  if(argc != 2) {
    printf("usage : %s name", argv[0]);
    return -1;
  }
  
  strncpy(_name, argv[1], sizeof(_name));
  
  return 0;
}

#define BUF_SIZE (128)

static int ros_subscribe(int argc, char** argv) {
  if(argc != 2) {
    printf("usage : %s topic\n", argv[0]);
    return -1;
  }
  
  char* topic = argv[1];
  char uri[BUF_SIZE] = {0};
  snprintf(uri, BUF_SIZE, "%s/sync/%s", topic, _name);
  
  unsigned char _int_buf[BUF_SIZE] = {0};
  char _cont_buf[BUF_SIZE] = {0};

  gnrc_netreg_entry_t _ne =
      GNRC_NETREG_ENTRY_INIT_PID(GNRC_NETREG_DEMUX_CTX_ALL,
                                 sched_active_pid);
  /* register for content chunks */
  gnrc_netreg_register(GNRC_NETTYPE_CCN_CHUNK, &_ne);

  struct ccnl_prefix_s *prefix = ccnl_URItoPrefix(uri, CCNL_SUITE_NDNTLV, NULL, 0);
  ccnl_send_interest(prefix, _int_buf, BUF_SIZE);
  if (ccnl_wait_for_chunk(_cont_buf, BUF_SIZE, 0) > 0) {
      printf("Current sequence number : %s\n", _cont_buf);
  }
  else {
      printf("No sync answer for topic : %s.\n", topic);
      return -1;
  }
  free_prefix(prefix);
  gnrc_netreg_unregister(GNRC_NETTYPE_CCN_CHUNK, &_ne);
  
  return 0;
}

static unsigned char _out[CCNL_MAX_PACKET_SIZE];

int pub_prod(struct ccnl_relay_s *relay, struct ccnl_face_s *from, struct ccnl_pkt_s *pkt) {
  (void)relay;
  (void)from;
  (void)pkt;
  
  printf("pfx.compcnt : %i\n", (int)pkt->pfx->compcnt);
  for(int i = 0 ; i < pkt->pfx->compcnt ; i++) {
    printf("[%i]\n", i);
    printf("\tpfx.namelen : %i\n", (int)pkt->pfx->complen[i]);
    printf("\tpfx.comp : %s\n", pkt->pfx->comp[i]);
  }
  
  char body[BUF_SIZE] = {0};
  snprintf(body, sizeof(body), "%i", 666);
  
  int offs = CCNL_MAX_PACKET_SIZE;
  int arg_len = ccnl_ndntlv_prependContent(pkt->pfx, (unsigned char*)body, strlen(body), NULL, NULL, &offs, _out);

  unsigned char *olddata;
  unsigned char *data = olddata = _out + offs;

  int len;
  unsigned typ;

  if (ccnl_ndntlv_dehead(&data, &arg_len, (int*) &typ, &len) || typ != NDN_TLV_Data) {
    puts("ERROR");
    return -1;
  }

  struct ccnl_content_s *c = 0;
  struct ccnl_pkt_s *pk = ccnl_ndntlv_bytes2pkt(typ, olddata, &data, &arg_len);
  c = ccnl_content_new(relay, &pk);
  ccnl_content_add2cache(relay, c);
  c->flags |= CCNL_CONTENT_FLAGS_STATIC;
  
  puts("OK!!!");
  return 0;
}

static int ros_publish(int argc, char** argv) {
  if(argc != 2) {
    printf("usage : %s topic\n", argv[0]);
    return -1;
  }
  
  char* topic = argv[1];
  (void) topic;

  ccnl_set_local_producer(pub_prod);
  
  while(1);
  
  return 0;
}


const shell_command_t command_list[] = {
  {"name", "set the node name", ros_set_name},
  {"sub", "subscribe to a topic", ros_subscribe},
  {"pub", "publish on a topic", ros_publish},
  {NULL, NULL, NULL},
};

int main(void)
{
    tlsf_create_with_pool(_tlsf_heap, sizeof(_tlsf_heap));
    msg_init_queue(_main_msg_queue, MAIN_QUEUE_SIZE);

    puts("Basic CCN-Lite example");

    ccnl_core_init();

    ccnl_start();

    /* get the default interface */
    kernel_pid_t ifs[GNRC_NETIF_NUMOF];

    /* set the relay's PID, configure the interface to use CCN nettype */
    if ((gnrc_netif_get(ifs) == 0) || (ccnl_open_netif(ifs[0], GNRC_NETTYPE_CCN) < 0)) {
        puts("Error registering at network interface!");
        return -1;
    }

    char line_buf[SHELL_DEFAULT_BUFSIZE];
    shell_run(command_list, line_buf, SHELL_DEFAULT_BUFSIZE);
    return 0;
}
