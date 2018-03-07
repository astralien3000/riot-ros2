FROM ubuntu:16.04

#--------------------
# General setup
#--------------------
# setup download url
ENV DOWNLOAD_URL https://raw.githubusercontent.com/astralien3000/riot-ros2/master

# setup environment
ENV LANG C.UTF-8
ENV LC_ALL C.UTF-8

# setup keys
RUN apt-key adv --keyserver ha.pool.sks-keyservers.net --recv-keys 421C365BD9FF1F717815A3895523BAEEB01FA116

# setup sources.list
RUN echo "deb http://packages.ros.org/ros/ubuntu xenial main" > /etc/apt/sources.list.d/ros-latest.list

RUN apt-get update
RUN apt install -y cmake git python3 python3-pip python3-empy g++-multilib
RUN pip3 install vcstool

#--------------------
# Install cross-compiler
# TODO: this will need to be board dependendant.
#--------------------
RUN apt-get install -y software-properties-common python-software-properties
RUN add-apt-repository ppa:team-gcc-arm-embedded/ppa
RUN apt-get update
RUN apt install -y gcc-arm-embedded
RUN apt install -y wget

#--------------------
# Sources
#--------------------
WORKDIR /root
RUN mkdir -p /root/ros2_riot_ws/src
RUN cd /root/ros2_riot_ws && wget ${DOWNLOAD_URL}/riot-ros2.repos
RUN cd /root/ros2_riot_ws && wget ${DOWNLOAD_URL}/ament2riot.cmake
RUN cd /root/ros2_riot_ws && vcs import src < riot-ros2.repos
# AMENT_IGNORE test_msgs package
RUN cd /root/ros2_riot_ws && touch src/ros2/rcl_interfaces/test_msgs/AMENT_IGNORE

# #--------------------
# # Tooling and compiling (split but altogether)
# #--------------------
# RUN mkdir -p /root/ros2_riot_ws/tools/src
# RUN cd /root/ros2_riot_ws/tools && wget ${DOWNLOAD_URL}/riot-ros2-tools.repos
# RUN cd /root/ros2_riot_ws/tools && vcs import src < riot-ros2-tools.repos
# RUN pip3 install pyparsing
# RUN cd /root/ros2_riot_ws/tools && ./src/ament/ament_tools/scripts/ament.py build --symlink-install
# RUN source /root/ros2_riot_ws/tools/install/setup.bash
# RUN cd /root/ros2_riot_ws && ament build --symlink-install --force-cmake-configure --cmake-args -DCMAKE_TOOLCHAIN_FILE=`pwd`/ament2riot.cmake

#--------------------
# Tooling
#--------------------
# RUN mkdir -p /root/ros2_riot_ws/tools/src
RUN cd /root/ros2_riot_ws && wget ${DOWNLOAD_URL}/riot-ros2-tools.repos
RUN cd /root/ros2_riot_ws && vcs import src < riot-ros2-tools.repos
RUN pip3 install pyparsing

#--------------------
# Cross-compiling (phase 1)
#--------------------
# Phase 1: cross-compile everything through ament
RUN cd /root/ros2_riot_ws && ./src/ament/ament_tools/scripts/ament.py build --symlink-install --force-cmake-configure --cmake-args -DCMAKE_TOOLCHAIN_FILE=`pwd`/ament2riot.cmake

#--------------------
# Compiling for platform (phase 2)
#    only preparing the env.
#--------------------
# Phase 2: compiling each application for it's target microcontroller with RIOT's Makefiles.
# setup the tap interface
RUN ls
COPY patches /root
RUN patch /root/ros2_riot_ws/install/RIOT/dist/tools/tapsetup/tapsetup /root/sudo-tapsetup.patch
RUN patch -R /root/ros2_riot_ws/install/RIOT/dist/tools/tapsetup/tapsetup /root/docker-tapsetup.patch

RUN apt-get install -y unzip bsdmainutils
# Configure exemplary git credentials to run native examples
RUN git config --global user.email "you@example.com"
RUN git config --global user.name "micro-ROS"


#--------------------
# Entry point
#--------------------
COPY entrypoint.sh /

ENTRYPOINT ["/entrypoint.sh"]
CMD ["bash"]
