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

Only Linux (preferred) and OSX (missing features) are supported.

This project needs **ROS2 beta1** to be installed on your computer, please, follow the [official installation instructions](https://github.com/ros2/ros2/wiki/Installation).

```
cd ~/ros2_ws
. ./install/setup.bash
```

Also, you need to create an overlay workspace [as described in this tutorial](https://github.com/ros2/ros2/wiki/Ament-Tutorial) : 

```
mkdir -p ~/ros2_riot_ws/src
```

## Clone the project

```sh
cd ~/ros2_riot_ws/src
git clone https://github.com/astralien3000/riot-ros2.git --recursive
```

## First build phase

ROS2 and RIOT have 2 very different build systems.
To be able to use them together, you need to build applications in 2 steps : 
using Ament, as a ROS2 user would normally do, 
and then compiling each application for it's target microcontroller with RIOT's Makefiles.

First phase : 

```sh
cd ~/ros2_riot_ws
## --symlink-install is very important, second step would fail otherwise
ament build --symlink-install
```

## Second build phase

### Example

First, setup the tap interface :
```sh
cd ~/ros2_riot_ws
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
