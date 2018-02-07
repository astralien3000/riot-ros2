# RIOT-ROS2

This project enables ROS2 to run on microcontrollers using the RIOT Operating System.

# Package support

ROS2 is composed of several layers. Some have been modified to be able to run on microcontroller.
Here is a summary of the main difference between the ROS2 stack and the RIOT-ROS2 stack :

| Layer | Package | ROS2 | RIOT-ROS2 |
|-|-|-|-|
| ROS Client Library bindings | rclc   | no [(open PR)](https://github.com/ros2/rclc/pull/8) | yes |
|                             | rclcpp | yes | no |
|                             | rclpy  | yes | no |
| ROS Client Library | rcl | yes | yes |
| ROS MiddleWare | rmw_fastrtps | yes | no |
|                | rmw_ndn      | no | yes |
| ROS IDL Generators | rosidl_generator_c   | yes | yes |
|                    | rosidl_generator_cpp | yes | no  |
|                    | rosidl_generator_py  | yes | no  |
| ROS IDL Type Support | rosidl_typesupport_introspection_c   | yes | no  |
|                      | rosidl_typesupport_introspection_cpp | yes | no  |
|                      | rosidl_typesupport_cbor              | no  | yes |
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
wget https://raw.githubusercontent.com/astralien3000/riot-ros2/master/riot-ros2.repos
wget https://raw.githubusercontent.com/astralien3000/riot-ros2/master/ament2riot.cmake
vcs import src < riot-ros2.repos
```

Some downloaded package are not supported, you may run these commands to disable them : 

```sh
touch src/ros2/rcl_interfaces/test_msgs/AMENT_IGNORE
```

## Get the tools

`riot-ros2` is meant for cross-compilation.
But some ROS2 tools need to be compiled for your current architecture.

```sh
mkdir -p ~/ros2_riot_ws/tools/src
cd ~/ros2_riot_ws/tools
wget https://raw.githubusercontent.com/astralien3000/riot-ros2/master/riot-ros2-tools.repos
vcs import src < riot-ros2-tools.repos
./src/ament/ament_tools/scripts/ament.py build --symlink-install
```

Once built, you can run this command to use `ament` and other ROS2 tools.
(This is only needed for the first build)

```sh
. ~/ros2_riot_ws/tools/install/setup.bash
```

## Two build phase

ROS2 and RIOT have 2 very different build systems. To be able to use them together, you need to build applications in 2 steps : using Ament, as a ROS2 user would normally do (but in the case of cross compilation), and then compiling each application for it's target microcontroller with RIOT's Makefiles.

First phase :

```sh
cd ~/ros2_riot_ws
ament build --symlink-install --force-cmake-configure --cmake-args -DCMAKE_TOOLCHAIN_FILE=`pwd`/ament2riot.cmake
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
