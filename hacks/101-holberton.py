#!/usr/bin/python3

import random
import sys
from time import sleep

i = 0
while True:
    sleep(1)
    sys.stdout.write("[{}] {}\n".format(i, "Holberton"))
    i += 1
    sys.stdout.flush()
