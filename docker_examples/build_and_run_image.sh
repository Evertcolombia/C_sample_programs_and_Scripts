#!/bin/bash

#this script will be runs where is the DockerFile stored or kmow the absolute path

# it will builds a image called flask_app version 0.1 and looks for docker file at . path
docker build -t flask_app:1.0 .

# run the image -p flag helps to create a pipe between the contaniner and our machine so we can see the app mounted

docker run -p 5000:5000 flask_app:0.1

# if you want inmediantly change ae reflected so run with this command

# docker run -it -v /home/fantasma/docker:/code flask_app:0.1
