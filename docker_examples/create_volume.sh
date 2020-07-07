#!/bin/bash

# Docker volumes are mostly created to share data within different containers, rather than sharing data with host and container.

sudo docker volume create <volume_name>

#can inspect the docker volume
docker volume isnpect <volume_name>

#we will run the container with a created volume attached to the container named “first_container”.
docker run -it --name "first_container" -v  <volume_name>:/<project_path> <image>:<version>

# OR USER IT

# lets run the container using this volume
docker run -it -v <volume_name>:/<project> <image_name>:<version>

# We have successfully mounted the volume onto the container file system. Now, let’s share this volume with another container so that the newly-created app folder should be accessible to the newly-created container.
docker run -it -v <volume_name>:/<project_in_second> --name <second_container> <image_name>:<version>
