# RIOT-ROS2

This project enables ROS2 to run on microcontrollers using the RIOT Operating System.

# Architecture

ROS2 is composed of several layers. Some have been modified to be able to run on microcontroller.
Here is a summary of the main difference between the ROS2 stack and the RIOT-ROS2 stack :

| Layers | ROS2 | RIOT-ROS2 |
|-|-|-|
| RCLC (ROS Client Library for C) | API only | implemented, following the API |
| RCL (ROS Client Library) | implemented | `timer.c` modified |
| RMW (ROS MiddleWare) | Based on DDS | 2 implementations : `ndn-riot` and `emcute` |
| rosidl | DDS, introspection | custom, serialisation based on `cbor` |

# Examples

All examples should be able to handle any RMW implementation (see Usage).

## std_msgs::String

- [talker_c](/examples/talker_c/main.c)
- [listener_c](/examples/listener_c/main.c)

## std_msgs::Int32

- [pub_int32_c](/examples/pub_int32_c/main.c)
- [sub_int32_c](/examples/sub_int32_c/main.c)

# Usage

## Requirements

Only Linux (preferred) and OSX (missing features) are supported.

### Ubuntu

```
sudo apt install cmake git python3-pip python3-empy g++-multilib
pip3 install vcstool
```

If your arm-none-eabi-gcc is too old (< gcc 5) : 

```
sudo add-apt-repository ppa:team-gcc-arm-embedded/ppa
sudo apt-get update
sudo apt install gcc-arm-embedded
```

### Others

Please, follow the requirements for [ros2 official installation instructions](https://github.com/ros2/ros2/wiki/Installation).

## Get the sources

```
mkdir -p ~/ros2_riot_ws/src
cd ~/ros2_riot_ws
wget https://raw.githubusercontent.com/astralien3000/riot-ros2/master/riot-ros2.repos
vcs import src < riot-ros2.repos
(cd src/ros2/riot/ && git submodule update --init)
```

## First build phase

ROS2 and RIOT have 2 very different build systems.
To be able to use them together, you need to build applications in 2 steps : 
using Ament, as a ROS2 user would normally do, 
and then compiling each application for it's target microcontroller with RIOT's Makefiles.

First phase : 

```sh
./src/ament/ament_tools/scripts/ament.py build --symlink-install
```

## Second build phase

### Linux example : NDN

First, setup the tap interface :
```sh
./install/RIOT/dist/tools/tapsetup/tapsetup
```

On a first terminal : 
```sh
(cd install/talker_c && make PORT=tap0 all term)
```

On a second terminal : 
```sh
(cd install/listener_c && make PORT=tap1 all term)
```

### Linux example : MQTT

[Usage of MQTT in RIOT](https://github.com/RIOT-OS/RIOT/tree/3d48eee0955e9452662af3b732516f8437f53092/examples/emcute)

Setup the tap interface :
```sh
./install/RIOT/dist/tools/tapsetup/tapsetup
sudo ip a a fec0:affe::1/64 dev tapbr0
```

Download, compile and run the broker :
```sh
git clone https://github.com/eclipse/mosquitto.rsmb.git
(cd mosquitto.rsmb/rsmb/src/ && make)
./mosquitto.rsmb/rsmb/src/broker_mqtts ~/ros2_riot_ws/src/ros2/riot/broker.conf
```

On a second terminal :
```sh
(cd install/talker_c && make RMW=rmw_mqtt PORT=tap0 MYADDR=fec0:affe::2 all term)
```

On a third terminal :
```sh
(cd install/listener_c && make RMW=rmw_mqtt PORT=tap1 MYADDR=fec0:affe::3 all term)
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
