import wiringpi2
import time

wiringpi2.wiringPiSetup() # IO 핀을 사용하기 위해서는 이 3개중 하나는 무조건 선언이 되어야한다.
speedSound = 33100 + (0.6*20)
# 사실 정확한 거리를 위해서는 저 온도값을 정확히 넣어줘야하겠지만
# 그정도의 정확한 거리가 필요한것은 아니므로 20이라고 맞추고 하자

# TRIG = 2 / 13
# ECHO = 3 / 15

def distance2():                     # 전방센서
    while True:                      
        wiringpi2.pinMode(2, 1)      # wpi상에서 2번핀이고 보드상에서는 13번이다. OUTPUT은 1이다.
        wiringpi2.pinMode(3, 0)      # wpi상에서 3번핀이고 보드상에서는 15번이다. INPUT은 0이다.
        wiringpi2.digitalWrite(2, 0) # trigpin -- 13 , LOW -- 0 & HIGH -- 1
        time.sleep(0.5)
        wiringpi2.digitalWrite(2, 1)
        time.sleep(0.00001)
        wiringpi2.digitalWrite(2, 0)
        start = time.time()

        while wiringpi2.digitalRead(3) == 0:
            start = time.time()
        while wiringpi2.digitalRead(3) == 1:
            stop = time.time()

        elapsed = stop - start

        distance = elapsed * speedSound
        distance = distance/2
        distance = int(distance)
        return distance

# TRIG = 4 / 16
# ECHO = 5 / 18
     
def distance5():                     # 후방센서
    while True:
        wiringpi2.pinMode(4, 1)      # wpi상에서 4번핀이고 보드상에서는 16번이다. OUTPUT은 1이다.
        wiringpi2.pinMode(5, 0)      # wpi상에서 5번핀이고 보드상에서는 18번이다. INPUT은 0이다.
        wiringpi2.digitalWrite(4, 0) # trigpin -- 16 , LOW -- 0 & HIGH -- 1
        time.sleep(0.5)
        wiringpi2.digitalWrite(4, 1)
        time.sleep(0.00001)
        wiringpi2.digitalWrite(4, 0)
        start = time.time()

        while wiringpi2.digitalRead(5) == 0:
            start = time.time()
        while wiringpi2.digitalRead(5) == 1:
            stop = time.time()

        elapsed = stop - start

        distance = elapsed * speedSound
        distance = distance/2
        distance = int(distance)
        return distance

# TRIG = 21 / 29
# ECHO = 22 / 31

def distance8():                      # 좌측센서   
    while True:
        wiringpi2.pinMode(21, 1)      # wpi상에서 21번핀이고 보드상에서는 29번이다. OUTPUT은 1이다.
        wiringpi2.pinMode(22, 0)      # wpi상에서 22번핀이고 보드상에서는 31번이다. INPUT은 0이다.
        wiringpi2.digitalWrite(21, 0) # trigpin -- 28 , LOW -- 0 & HIGH -- 1
        time.sleep(0.5)
        wiringpi2.digitalWrite(21, 1)
        time.sleep(0.00001)
        wiringpi2.digitalWrite(21, 0)
        start = time.time()

        while wiringpi2.digitalRead(22) == 0:
            start = time.time()
        while wiringpi2.digitalRead(22) == 1:
            stop = time.time()

        elapsed = stop - start

        distance = elapsed * speedSound
        distance = distance/2
        distance = int(distance)
        return distance

# TRIG =  6 / 22
# ECHO = 11 / 26

def distance7():                     # 우측센서
    while True:
        wiringpi2.pinMode(6, 1)      # wpi상에서 6번핀이고 보드상에서는 22번이다. OUTPUT은 1이다.
        wiringpi2.pinMode(11, 0)     # wpi상에서 11번핀이고 보드상에서는 26번이다. INPUT은 0이다.
        wiringpi2.digitalWrite(6, 0) # trigpin -- 22, LOW -- 0 & HIGH -- 1
        time.sleep(0.5)
        wiringpi2.digitalWrite(6, 1)
        time.sleep(0.00001)
        wiringpi2.digitalWrite(6, 0)
        start = time.time()

        while wiringpi2.digitalRead(11) == 0:
            start = time.time()
        while wiringpi2.digitalRead(11) == 1:
            stop = time.time()

        elapsed = stop - start

        distance = elapsed * speedSound
        distance = distance/2
        distance = int(distance)
        return distance
