#!/bin/bash

#Remove any older versions of docker
sudo apt-get -y remove docker docker-engine docker.io containerd runc
# Update package index
sudo apt-get -y update
sudo apt-get install apt-transport-https ca-certificates curl \
	    gnupg-agent \
	        software-properties-common
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | apt-key add -
sudo add-apt-repository \
	   "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
	      $(lsb_release -cs) \
	         stable"
sudo apt-get -y update
sudo apt-get -y install docker-ce docker-ce-cli containerd.io

#If you don’t want to use sudo for every Docker command, add your current user in the Docker group using

#sudo groupadd docker
#sudo usermod -aG docker $USER
sudo docker run hello-world
