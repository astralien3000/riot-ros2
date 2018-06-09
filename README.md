# RIOT-ROS2

This project enables ROS2 to run on microcontrollers using the RIOT Operating System and the NDN protocol.
More information about the [design](https://github.com/astralien3000/riot-ros2/wiki/Design) of this project is available in the [wiki](https://github.com/astralien3000/riot-ros2/wiki).

# Package support

ROS2 is composed of several layers. Some have been modified to be able to run on microcontroller.
Here is a summary of the main difference between the ROS2 stack and the RIOT-ROS2 stack :

| Layer | Package | ROS2 | RIOT-ROS2 |
|-|-|-|-|
| ROS Client Library bindings | rclc   | no [(open PR)](https://github.com/ros2/rclc/pull/8) | yes |
|                             | rclcpp | yes | no |
| ROS Client Library | rcl | yes | yes |
| ROS MiddleWare | rmw_fastrtps | yes | no |
|                | rmw_ndn      | no | yes |
| ROS IDL Generators | generator_c   | yes | yes |
|                    | generator_cpp | yes | no  |
| ROS IDL Type Support | introspection_c   | yes | no  |
|                      | introspection_cpp | yes | no  |
|                      | cbor              | no  | yes |
| ROS IDL Interfaces | common_interfaces | yes | yes |
|                    | rcl_interfaces    | yes | yes, excepted test_msgs |


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

### Ubuntu

```bash
sudo apt install cmake git python3-pip python3-empy g++-multilib
pip3 install vcstool
```

If your arm-none-eabi-gcc is too old (< gcc 5) : 

```bash
sudo add-apt-repository ppa:team-gcc-arm-embedded/ppa
sudo apt-get update
sudo apt install gcc-arm-embedded
```

### Fedora

Required for ROS2 :

```bash
sudo dnf install cmake git python3-pip python3-empy python3-pyparsing
pip3 install vcstool
# if g++ is not already installed
sudo dnf install gcc-c++
```

Required for RIOT (native) :

```bash
sudo dnf install glibc-devel.i686
```

### Others

Please, follow the requirements for [ros2 official installation instructions](https://github.com/ros2/ros2/wiki/Installation).

## Get the sources

```sh
mkdir -p ~/ros2_riot_ws/src
cd ~/ros2_riot_ws
wget https://raw.githubusercontent.com/astralien3000/riot-ros2/master/ros2.repos
wget https://raw.githubusercontent.com/astralien3000/riot-ros2/master/ament2riot.cmake
vcs import src < ros2.repos
```

Some downloaded package are not supported, you may run these commands to disable them : 

```sh
touch src/ros2/rcl_interfaces/test_msgs/AMENT_IGNORE
```

## Two build phase

ROS2 and RIOT have 2 very different build systems. To be able to use them together, you need to build applications in 2 steps : using Ament, as a ROS2 user would normally do (but in the case of cross compilation), and then compiling each application for it's target microcontroller with RIOT's Makefiles.

First phase :

```sh
cd ~/ros2_riot_ws
./src/ament/ament_tools/scripts/ament.py build --symlink-install --cmake-args -DCMAKE_TOOLCHAIN_FILE=`pwd`/ament2riot.cmake
```

After that, you can go to the second build phase.

### Linux native 2nd build phase example

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

### Board to Linux example

This example have been tested with a [samr21-xpro](https://github.com/RIOT-OS/RIOT/wiki/Board%3A-SAMR21-xpro), but should work with any RIOT-supported board that can communicate via UART with a computer.

Setup the tap interface :
```sh
./install/RIOT/dist/tools/tapsetup/tapsetup
```

To flash the board, and enable the serial link :
```sh
(cd install/talker_c && make BOARD=samr21-xpro PORT=tap0 flash term)
```

To run the native application :
```sh
(cd install/listener_c && make BOARD=native PORT=tap1 all term)
```

The `talker_c` and `listener_c` apps should be seamlessly switchable between the board and native.

# Troubleshooting

If this command fails :
```sh
> ./install/RIOT/dist/tools/tapsetup/tapsetup
creating tapbr0
RTNETLINK answers: File exists
```
Maybe it's because you already called it.
It is not supposed to be called twice.

Try :
```sh
./install/RIOT/dist/tools/tapsetup/tapsetup -d
```
