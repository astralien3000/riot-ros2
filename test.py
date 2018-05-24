#!/usr/bin/env python3

# Copyright (C) 2018 Inria
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.

import pytun
from pypacker.layer12 import ethernet
import socket
import select

sock_addr = '127.0.0.1'
sock_port = 3000

tap = pytun.TunTapDevice(name="tap1",flags=pytun.IFF_TAP)
tap.up()

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((sock_addr, sock_port))

while True:
	r,w,x = select.select([tap, sock],[],[])
	if tap in r:
		buf = tap.read(tap.mtu)
		eth = ethernet.Ethernet(buf[4:])
		print(buf[:4])
		print("TAP")
		print(eth.body_bytes)
		print(eth)
		sock.sendto(eth.body_bytes, (sock_addr, 6363))
	if sock in r:
		data, addr = sock.recvfrom(1024)
		print("SOCK")
		print(data)
		eth = ethernet.Ethernet()
		eth.dst = b'\xff\xff\xff\xff\xff\xff'
		eth.src = tap.hwaddr
		eth.type = 0x8624
		eth.body_bytes = data
		print(eth)
		tap.write(b'\x00\x00\x86$' + eth.bin())

