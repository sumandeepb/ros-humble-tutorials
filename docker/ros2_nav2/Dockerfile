FROM osrf/ros:humble-desktop-full-jammy

# install additional tools
RUN apt update && apt upgrade -y
RUN apt install -y git wget python3-pip vim

# install ros2 & nav2 tools
RUN apt install -y ros-dev-tools
RUN apt install -y ros-humble-navigation2 ros-humble-nav2-bringup 
RUN apt install -y ros-humble-turtlebot3*

# runtime env
ENV TURTLEBOT3_MODEL=waffle
ENV GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:/opt/ros/humble/share/turtlebot3_gazebo/models
ENV DISPLAY=novnc:0.0
RUN touch /root/.bashrc && echo "source /opt/ros/humble/setup.bash" >> /root/.bashrc
