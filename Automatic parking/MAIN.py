#!/usr/bin/env python3
import __BLUETOOTH__ as B
import __PARKING__ as P
import time
import os

os.system("mpg321 /home/odroid/MP3/Welcome_to_the_Automatic_parking_system..mp3")
time.sleep(2)

while True:
    B.DRIVING()
    time.sleep(1.5)
    P.Park()
    time.sleep(1.5)
