#!/bin/bash
set -e

# Create interaces
export USER=micro-ros && /root/ros2_riot_ws/install/RIOT/dist/tools/tapsetup/tapsetup
# Compile and run a native talker
cd /root/ros2_riot_ws/install/talker_c && make PORT=tap0 all term

exec "$@"
