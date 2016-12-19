
import serial

port = "/dev/ttyACM0"
ser = serial.Serial(port, 38400)
Value=[0, 0, 0, 0]

ser.flushInput()

def distance():
    while True:
        if(ser.inWaiting()>0):
            for i in range(0,4):
                Value[i]=ord(ser.read())
            return Value[0], Value[1], Value[2], Value[3]

Serial = [0, 0, 0, 0]
while True:
    Serial = distance()
    print("전방: ",Serial[0])
    print("후방: ",Serial[1])
    print("좌측: ",Serial[2])
    print("우측: ",Serial[3])
    print("")
