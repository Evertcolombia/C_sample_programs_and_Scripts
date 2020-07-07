#!/bin/bash
#skeleton to do a docker image commit
#this script must be updated
sudo docker commit -m "message" <conainer_id/name> <new_image_name>:<version>

# push your image to your docker hub acount
sudo docker tag <image_name> <docker_hub_username>/<image_name>:<version>
sudo docker push <docker_hub_username>/<image_name>:<version>
