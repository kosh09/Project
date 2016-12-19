
import serial
import time

def write_serial():
    port = "/dev/ttyACM0"
    ser = serial.Serial(port, 38400)

    while True:
        ser.write(b"L20")
        ser.write(b"R20")

write_serial()
