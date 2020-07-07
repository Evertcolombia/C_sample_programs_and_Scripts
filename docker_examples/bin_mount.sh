#!/bin/bash

#use the host filesystem and mount it on the container using -v flag with the run command.

sudo docker run -it -v <absolute_path>:<folder_path_or_new_folder_name> <image_name>

# To mount the file system as read-only, use ro flag. 

sudo docker run -it -v <aboslute_path>:<folder_path_or_new_folder_name>:ro <image_name>

# Bind mount has some limitations and is dependent on the host’s file system. If a folder is accidentally deleted from the host, Docker can’t do anything.

