#!/bin/bash

docker login
#put user name
#put password

docker tag flask_app:0.1 elfantasma/flask_app:0.1
docker push elfantasma/flask_app:0.1

