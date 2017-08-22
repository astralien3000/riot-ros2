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
| rosidl | DDS, introspection | custom, serlialisation based on cbor |

# Examples

 - [talker_c](/examples/talker_c/main.c)
 - [listener_c](/examples/listener_c/main.c)

# Usage

## Requirements

### Ubuntu (tested on 16.04)

```
sudo apt install cmake git python3-pip python3-empy g++-multilib
pip3 install vcstool
```

### Others

Only Linux (preferred) and OSX (missing features) are supported. Please, follow the requirements for [ros2 official installation instructions](https://github.com/ros2/ros2/wiki/Installation).

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
## --symlink-install is very important, second step would fail otherwise
./src/ament/ament_tools/scripts/ament.py build --symlink-install
```

## Second build phase

### Example

First, setup the tap interface :
```sh
# Don't use twice
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
