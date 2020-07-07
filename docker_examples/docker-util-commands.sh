#!/bin/bash

# see if a port is occuped by other thing
lsof -i TCP:<PORT>

# see how much space is used by programs 
df -h
# see how much spaced is usebb by Docker
docker system df

# temove unuse containers
docker system prune
docker contianer prune
docker images prune
docker network prune
