# Usage Instructions
Install Docker
```
https://docs.docker.com/engine/install/ubuntu/
```

Create Docker Network
```
$ docker network create ros
```

Fetch noVNC Container
```
$ docker pull theasp/novnc:latest
```

Run noVNC Container
```
$ docker run -d --rm --net=ros \
    --env="DISPLAY_WIDTH=2560" \
    --env="DISPLAY_HEIGHT=1440" \
    --env="RUN_XTERM=no" \
    --name=novnc -p=8080:8080 \
    theasp/novnc:latest
```

Run noVNC Desktop
```
http://localhost:8080/vnc.html
```

Build ros2_nav2 Container
```
$ docker build -t ros2_nav2 .
```

Run ros2_nav2 Container
```
$ docker run \
	-it \
	--net=ros \
	--name ros2_nav2 \
	ros2_nav2 \
	bash
```

Connect to ros2_nav2 Container
```
$ docker exec -it ros2_nav2 /bin/bash
```

Run on ros2_nav2 Container
```
$ source /opt/ros/humble/setup.sh
```
