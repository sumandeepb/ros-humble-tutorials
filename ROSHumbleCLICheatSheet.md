### **Install ROS Humble Hawksbill**

* ROS2 Distribution with LTS <https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debians.html>
* ROS Humble Tutorials <https://docs.ros.org/en/humble/Tutorials.html>

### CLI Tools

* Source Commands: `echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc`
* Check ENV: `printenv | grep -i ROS`
* Set Domain ID: `echo "export ROS_DOMAIN_ID=\<your_domain_id\>" \>\> \~/.bashrc`
* Resolve Dependencies
    ```
    sudo rosdep init
    rosdep update
    rosdep install -i --from-path src --rosdistro humble -y
    ```
* Check package installation: `ros2 pkg executables \<package_name\>`
* Start TurtleSim: `ros2 run turtlesim turtlesim_node`
  * Control TurtleSim: `ros2 run turtlesim turtle_teleop_key`
* Check Active Entities:

    ```
    ros2 node list
    ros2 topic list
    ros2 service list
    ros2 action list
    ```
* GUI Tools Framework: `rqt`
  * Plugins \> Services \> Service Caller
  * Visualize nodes/topics/actions etc: `rqt_graph`
    * Nodes are oval
    * Topics are rectangular
    * Actions are ??
* Nodes
  * Remapping Node: `ros2 run turtlesim turtlesim_node --ros-args --remap __node:=my_turtle`
  * Get Node Info: `ros2 node info \<node_name\>`
* Topics
  * 
  * Topic types: `ros2 topic list -t`
  * Topic data: `ros2 topic echo \<topic_name\>`
  * Topic Info: `ros2 topic info \<topic_name\>`
  * Topic Message Type: `ros2 interface show \<topic_type\>`
  * Publish Topic Data: `ros2 topic pub \<topic_name\> \<msg_type\> '\<args\>'`
    * Flags:
      * `pub --once`
      * `pub --rate n`
  * Get Publish Rate: `ros2 topic hz \<topic_name\>`
* Services
  * Service Type: `ros2 service type \<service_name\>`
  * Service Types: `ros2 service list -t`
  * Service Search by Type: `ros2 service find \<type_name\>`
  * Service Message Type: `ros2 interface show \<type_name\>`
  * Call Service with Arguments: `ros2 service call \<service_name\> \<service_type\> \<arguments\>`
* Parameters
  * `ros2 param list`
  * `ros2 param get \<node_name\> \<parameter_name\>`
  * `ros2 param set \<node_name\> \<parameter_name\> \<value\>`
  * `ros2 param dump \<node_name\> \> \<parameter_file\>`
  * `ros2 param load \<node_name\> \<parameter_file\>`
  * `ros2 run \<package_name\> \<executable_name\> --ros-args --params-file \<file_name\>`
* Actions
  * `ros2 action list -t`
  * `ros2 action info \<action_name\>`
  * `ros2 interface show \<action_type\>`
  * `ros2 action send_goal \<action_name\> \<action_type\> \<values\>`
    * argument `--feedback` for continuous feedback
* Debugging from Logs
  * `ros2 run rqt_console rqt_console`
  * `ros2 run turtlesim turtlesim_node --ros-args --log-level WARN`
* Launch Files
  * `ros2 launch \<package_name\> \<launch_file_name\> OR ros2 launch \<path_to_launch_file\>`
    * Use Python, XML or YAML
* Record & Play Data
  * `ros2 bag record \<topic_name\>`
    * `ros2 bag record -o subset /turtle1/cmd_vel /turtle1/pose`
  * `ros2 bag info \<bag_file_name\>`
  * `ros2 bag play \<bag_file_name\>`