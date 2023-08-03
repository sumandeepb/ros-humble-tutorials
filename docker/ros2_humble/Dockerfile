FROM nvidia/cuda:12.2.0-devel-ubuntu22.04

# essential tools
RUN apt update
RUN apt install -y build-essential software-properties-common apt-transport-https wget git net-tools python3-pip curl gnupg2 lsb-release

# set locale
ENV LANG C.UTF-8
ENV LC_ALL C.UTF-8

# install ROS Humble desktop
RUN add-apt-repository universe && apt update
RUN curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
RUN echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | tee /etc/apt/sources.list.d/ros2.list > /dev/null
RUN apt update
RUN DEBIAN_FRONTEND=noninteractive apt install -y ros-humble-desktop
RUN apt install -y ros-dev-tools
