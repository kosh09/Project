import os
import wiringpi2 as GPIO
import time
GPIO.wiringPiSetup()

def d2():
    pulse_start = 0
    pulse_end = 0

    TRIG = 2
    ECHO = 3

    GPIO.pinMode(TRIG,1)
    GPIO.pinMode(ECHO,0)

    GPIO.digitalWrite(TRIG, 0)
    time.sleep(0.1)

    GPIO.digitalWrite(TRIG, 1)
    time.sleep(0.0001)
    GPIO.digitalWrite(TRIG, 0)

    while GPIO.digitalRead(ECHO)==0:
        pulse_start = time.time()

    while GPIO.digitalRead(ECHO)==1:
        pulse_end = time.time()

    pulse_duration = pulse_end - pulse_start

    distance = pulse_duration * 17150
    distance = round(distance,3)

    return distance

def d5():
    pulse_start = 0
    pulse_end = 0

    TRIG = 4
    ECHO = 5

    GPIO.pinMode(TRIG,1)
    GPIO.pinMode(ECHO,0)

    GPIO.digitalWrite(TRIG, 0)
    time.sleep(0.1)

    GPIO.digitalWrite(TRIG, 1)
    time.sleep(0.0001)
    GPIO.digitalWrite(TRIG, 0)

    while GPIO.digitalRead(ECHO)==0:
        pulse_start = time.time()

    while GPIO.digitalRead(ECHO)==1:
        pulse_end = time.time()

    pulse_duration = pulse_end - pulse_start

    distance = pulse_duration * 17150
    distance = round(distance,3)

    return distance

def d8():
    pulse_start = 0
    pulse_end = 0

    TRIG = 21
    ECHO = 22

    GPIO.pinMode(TRIG,1)
    GPIO.pinMode(ECHO,0)

    GPIO.digitalWrite(TRIG, 0)
    time.sleep(0.1)

    GPIO.digitalWrite(TRIG, 1)
    time.sleep(0.0001)
    GPIO.digitalWrite(TRIG, 0)

    while GPIO.digitalRead(ECHO)==0:
        pulse_start = time.time()

    while GPIO.digitalRead(ECHO)==1:
        pulse_end = time.time()

    pulse_duration = pulse_end - pulse_start

    distance = pulse_duration * 17150
    distance = round(distance,3)

    return distance

def d7():
    pulse_start = 0
    pulse_end = 0

    TRIG = 6
    ECHO = 11

    GPIO.pinMode(TRIG,1)
    GPIO.pinMode(ECHO,0)

    GPIO.digitalWrite(TRIG, 0)
    time.sleep(0.1)

    GPIO.digitalWrite(TRIG, 1)
    time.sleep(0.0001)
    GPIO.digitalWrite(TRIG, 0)

    while GPIO.digitalRead(ECHO) == 0:
        pulse_start = time.time()

    while GPIO.digitalRead(ECHO) == 1:
        pulse_end = time.time()

    pulse_duration = pulse_end - pulse_start

    distance = pulse_duration * 17150
    distance = round(distance,3)

    return distance

def d1():
    pulse_start = 0
    pulse_end = 0

    TRIG = 26
    ECHO = 27

    GPIO.pinMode(TRIG,1)
    GPIO.pinMode(ECHO,0)

    GPIO.digitalWrite(TRIG, 0)
    time.sleep(0.1)

    GPIO.digitalWrite(TRIG, 1)
    time.sleep(0.0001)
    GPIO.digitalWrite(TRIG, 0)

    while GPIO.digitalRead(ECHO) == 0:
        pulse_start = time.time()

    while GPIO.digitalRead(ECHO) == 1:
        pulse_end = time.time()

    pulse_duration = pulse_end - pulse_start

    distance = pulse_duration * 17150
    distance = round(distance,3)

    return distance

def d3():
    pulse_start = 0
    pulse_end = 0

    TRIG = 1
    ECHO = 23

    GPIO.pinMode(TRIG,1)
    GPIO.pinMode(ECHO,0)

    GPIO.digitalWrite(TRIG, 0)
    time.sleep(0.1)

    GPIO.digitalWrite(TRIG, 1)
    time.sleep(0.0001)
    GPIO.digitalWrite(TRIG, 0)

    while GPIO.digitalRead(ECHO) == 0:
        pulse_start = time.time()

    while GPIO.digitalRead(ECHO) == 1:
        pulse_end = time.time()

    pulse_duration = pulse_end - pulse_start

    distance = pulse_duration * 17150
    distance = round(distance,3)

    return distance
