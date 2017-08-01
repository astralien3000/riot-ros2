# RIOT-ROS2

This project enables ROS2 to run on microcontrollers using the RIOT Operating System.

# Architecture

ROS2 is composed of sevral layers. Some have been modified to be able to run on microcontroller.
Here is a summary of the main difference between the ROS2 stack and the RIOT-ROS2 stack :

| Layers | ROS2 | RIOT-ROS2 |
|-|-|-|
| RCLC (ROS Client Library for C) | API only | implemented, following the API |
| RCLCPP (ROS Client Library for C++) | implemented | only supported on `native` board |
| RCLPY (ROS Client Library for Python) | implemented | not supported |
| RCL (ROS Client Library) | implemented | `timer.c` modified |
| RMW (ROS MiddleWare) | Based on DDS | 2 implementations : `ndn-riot` and `emcute` |
| rosidl | DDS, introspection | only introspection |

# Examples

 - [talker_c](/examples/talker_c/main.c)
 - [listener_c](/examples/listener_c/main.c)

# Usage

## Clone the project

```sh
git clone https://github.com/astralien3000/riot-ros2.git --recursive
cd riot-ros2
```

Despite there is a Makefile at the root of the repository, you cannot call `make`.

## Linux example : NDN

First, setup the tap interface :
```sh
# Don't use twice
./RIOT/dist/tools/tapsetup/tapsetup
```

On a first terminal : 
```sh
(cd examples/talker_c && make PORT=tap0 all term)
```

On a second terminal : 
```sh
(cd examples/listener_c && make PORT=tap1 all term)
```

## Linux example : emcute (MQTT-SN)

[A more complete tutorial about emcute usage](https://github.com/RIOT-OS/RIOT/tree/3d48eee0955e9452662af3b732516f8437f53092/examples/emcute)

On a first terminal, setup the tap interface :
```sh
# Don't use twice
./RIOT/dist/tools/tapsetup/tapsetup
sudo ip a a fec0:affe::1/64 dev tapbr0
```

Compile and run the broker :
```sh
(cd mosquitto.rsmb/rsmb/src/ && make)
(./mosquitto.rsmb/rsmb/src/broker_mqtts broker.conf)
```

On a second terminal :
```sh
(cd examples/talker_c && make RMW=rmw_mqtt PORT=tap0 MYADDR=fec0:affe::2 all term)
```

On a third terminal :
```sh
(cd examples/listener_c && make RMW=rmw_mqtt PORT=tap1 MYADDR=fec0:affe::3 all term)
```

# Troubleshooting

If this command fails :
```sh
> ./RIOT/dist/tools/tapsetup/tapsetup
creating tapbr0
RTNETLINK answers: File exists
```
Maybe it's because you already called it.
It is not supposed to be called twice.

Try :
```sh
./RIOT/dist/tools/tapsetup/tapsetup -d
```
