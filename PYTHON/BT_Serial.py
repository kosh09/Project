import serial

Value = [0, 0, 0, 0]
print("Start")
bluetooth = serial.Serial(port="/dev/rfcomm0", baudrate=57600,timeout=0.1)
print("Connected")

def RL_BUTTON():
    return Value[0]

def FB_BUTTON():
    return Value[1]

def RIGT_BUTTON():
    return Value[2]

def LEFT_BUTTON():
    return Value[3]

while True:
    for i in range(0,4):
        Value[i]=bluetooth.readline()
        print("String",i+1,": ",Value[i])
    print("\n")

