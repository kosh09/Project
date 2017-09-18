#!/usr/bin/env python3

import bluetooth
import serial
import struct
import time
import __ULT_DIST__ as U
import os
import math

signal   = [116, 117, 118, 119, 120, 121, 134, 135, 136, 137, 138, 139]
start    = [116, 139]
stop     = [117, 138]
Fast     = [118, 137]
Slow     = [119, 136]
reboot   = [120, 135]
shutdown = [121, 134]
Find     = [122, 133]
distance = [123, 132]
Front    = [52, 83]
Back     = [53, 82]

os.system("sudo chmod 777 /dev/ttyACM0")
os.system("sudo chmod 777 /dev/ttyACM1")

# Controller
try:
    bd_addr = "98:D3:37:00:8D:39" # The address from the HC-05 sensor
    port = 1
    sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
    sock.connect((bd_addr,port))
except:
    os.system("mpg321 /home/odroid/MP3/Controller_connection_error_has_been_occured._5seconds_for_resolution.mp3")
    time.sleep(5)
    bd_addr = "98:D3:37:00:8D:39" # The address from the HC-05 sensor
    port = 1
    sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
    sock.connect((bd_addr,port))
os.system("mpg321 /home/odroid/MP3/Controller_connection_is_succeeded.mp3")

# Arduino
try:
    ser = serial.Serial("/dev/ttyACM0", 57600)
except:
    os.system("mpg321 /home/odroid/MP3/First_arduino_connection_error_has_been_occured._5seconds_for_resolution.mp3")
    time.sleep(5)
    ser = serial.Serial("/dev/ttyACM0", 57600)
os.system("mpg321 /home/odroid/MP3/First_arduino_connection_is_succeeded.mp3")


# Arduino
try:
    ser_1 = serial.Serial("/dev/ttyACM1", 9600)
except:
    os.system("mpg321 /home/odroid/MP3/Second_arduino_connection_error_has_been_occured._5seconds_for_resolution.mp3")
    time.sleep(5)
    ser_1 = serial.Serial("/dev/ttyACM1", 9600)
os.system("mpg321 /home/odroid/MP3/Second_arduino_connection_is_succeeded.mp3")

def DRIVING():
    data=[0,0]
    data2 = [0,0]
    os.system("mpg321 /home/odroid/MP3/Start_the_Driving_sequence.mp3")
    time.sleep(1)
    os.system("mpg321 /home/odroid/MP3/engine_start.mp3")
    start_recv()
    while True:
        for i in range(0,2):
            data[i] = sock.recv(1)
            ser.write(data[i])
            data2[i] = ord(data[i])
        if data2[0] + data2[1] == 255:
            print("First value: ",data2[0],"Second Value: ",data2[1], "Checksum okay")
            if data2[0] in stop:
                os.system("mpg321 /home/odroid/MP3/Stop_the_driving_sequence.mp3")
                break
            elif data2[0] in Fast:
                os.system("mpg321 /home/odroid/MP3/Execute_the_fast_driving_mode.mp3")
            elif data2[0] in Slow:
                os.system("mpg321 /home/odroid/MP3/Execute_the_slow_driving_mode.mp3")
            elif data2[0] in Find:
                os.system("mpg321 /home/odroid/MP3/Searching.mp3")
                stop_recv()
                Find_Parking()
                start_recv()
            elif data2[0] in distance:
                os.system("mpg321 /home/odroid/MP3/Calculating.mp3")
                stop_recv()
                Calculating()
                start_recv()
            elif data2[0] in shutdown:
                stop_recv()
                os.system("mpg321 /home/odroid/MP3/shutdown.mp3")
                time.sleep(1)
                os.system("sudo shutdown now -h")
            elif data2[0] in reboot:
                stop_recv()
                os.system("mpg321 /home/odroid/MP3/reboot.mp3")
                time.sleep(1)
                os.system("sudo reboot")

def start_recv():
    sig = struct.pack('!B', 254)
    for i in range(0,4):
        sock.send(sig)

def stop_recv():
    sig = struct.pack('!B',253)
    for i in range(0,4):
        sock.send(sig)

def buzzer_on():
    strings1 = ""
    strings2 = ""
    strings1 = struct.pack('!B',50)
    strings2 = struct.pack('!B',85)
    ser_1.flushOutput()
    for i in range(0,3):
        ser_1.write(strings1)
        ser_1.write(strings2)

def buzzer_off():
    strings1 = ""
    strings2 = ""
    strings1 = struct.pack('!B',51)
    strings2 = struct.pack('!B',84)
    ser_1.flushOutput()
    for i in range(0,3):
        ser_1.write(strings1)
        ser_1.write(strings2)

def Back():
    strings1 = ""
    strings2 = ""
    strings1 = struct.pack('!B',52)
    strings2 = struct.pack('!B',83)
    ser_1.flushOutput()
    ser_1.flushInput()
    for i in range(0,3):
        ser_1.write(strings1)
        ser_1.write(strings2)
    data = ord(ser_1.read(1))
    data = int(data)
    return data

def Front():
    strings1 = ""
    strings2 = ""
    strings1 = struct.pack('!B',53)
    strings2 = struct.pack('!B',82)
    ser_1.flushOutput()
    ser_1.flushInput()
    for i in range(0,3):
        ser_1.write(strings1)
        ser_1.write(strings2)
    data = ord(ser_1.read(1))
    data = int(data)
    return data

def Initialize():
    strings1 = ""
    strings2 = ""
    strings1 = struct.pack('!B',54)
    strings2 = struct.pack('!B',81)
    ser_1.flushOutput()
    ser_1.flushInput()
    for i in range(0,3):
        ser_1.write(strings1)
        ser_1.write(strings2)


def L_Angle():
    strings1 = ""
    strings2 = ""
    strings1 = struct.pack('!B',55)
    strings2 = struct.pack('!B',80)
    ser_1.flushOutput()
    for i in range(0,3):
        ser_1.write(strings1)
        ser_1.write(strings2)

def R_Angle():
    strings1 = ""
    strings2 = ""
    strings1 = struct.pack('!B',56)
    strings2 = struct.pack('!B',79)
    ser_1.flushOutput()
    for i in range(0,3):
        ser_1.write(strings1)
        ser_1.write(strings2)

def L_Parallel():
    strings1 = ""
    strings2 = ""
    strings1 = struct.pack('!B',57)
    strings2 = struct.pack('!B',78)
    ser_1.flushOutput()
    for i in range(0,3):
        ser_1.write(strings1)
        ser_1.write(strings2)

def R_Parallel():
    strings1 = ""
    strings2 = ""
    strings1 = struct.pack('!B',58)
    strings2 = struct.pack('!B',77)
    ser_1.flushOutput()
    for i in range(0,3):
        ser_1.write(strings1)
        ser_1.write(strings2)

def Init_num_Rotate():
    strings1 = ""
    strings2 = ""
    strings1 = struct.pack('!B',60)
    strings2 = struct.pack('!B',75)
    ser_1.flushOutput()
    for i in range(0,3):
        ser_1.write(strings1)
        ser_1.write(strings2)

def num_Rotate(num):
    strings1 = ""
    strings2 = ""
    strings1 = struct.pack('!B',59)
    strings2 = struct.pack('!B',76)
    ser_1.flushInput()
    ser_1.flushOutput()
    for i in range(0,3):
        ser_1.write(strings1)
        ser_1.write(strings2)
    data = ord(ser_1.read(1))
    Radian = round(((5*2*math.pi)/12)*data,2)
    if num == 0:
        return data
    elif num == 1:
        return Radian


def Find_Parking():
    print("R -- Front: ",U.d2()," Middle: ",U.d7()," Back: ",U.d5())
    print("L -- Front: ",U.d1()," Middle: ",U.d8()," Back: ",U.d3())
    time.sleep(1)
    #오른쪽직각주차.
    if (14<U.d2()<42 and 65< U.d7()<91 and 65<U.d5()<91) or (14<U.d2()<42 and 65< U.d7()<91 and 14<U.d5()<42) or (14<U.d2()<42 and 14< U.d7()<42 and 65<U.d5()<91) or (65<U.d2()<91 and 14<U.d7()<42 and 65<U.d5()<91) or (65<U.d2()<91 and 65<U.d7()<91 and 14<U.d5()<42):
        os.system("mpg321 /home/odroid/MP3/execute_the_left_side,_perpendicular_parking,_guidance_point.mp3")
        time.sleep(0.01)
        R_Angle()
        time.sleep(1)

    #왼쪽직각주차
    elif (14<U.d1()<42 and 65< U.d8()<91 and 65<U.d3()<91) or (14<U.d1()<42 and 65< U.d8()<91 and 14<U.d3()<42) or (14<U.d1()<42 and 14< U.d8()<42 and 65<U.d3()<91) or (65<U.d1()<91 and 14<U.d8()<42 and 65<U.d3()<91) or (65<U.d1()<91 and 65<U.d8()<91 and 14<U.d3()<42):
        os.system("mpg321 /home/odroid/MP3/execute_the_right_side,_perpendicular_parking,_guidance_point.mp3")
        time.sleep(0.01)
        L_Angle()
        time.sleep(1)

    #오른쪽 평행주차
    elif (0<U.d2()<26 and 0< U.d7()<26 and 37<U.d5()<65) or (0<U.d2()<26 and 37< U.d7()<65 and 37<U.d5()<65) or (37<U.d2()<65 and 37< U.d7()<65 and 37<U.d5()<65) or (37<U.d2()<65 and 37<U.d7()<65 and 0<U.d5()<26) or (37<U.d2()<65 and 0<U.d7()<26 and 0<U.d5()<26):
        os.system("mpg321 /home/odroid/MP3/execute_the_right_side,_parallel_parking,_guidance_point.mp3")
        time.sleep(0.01)
        R_Parallel()
        time.sleep(1)

    #왼쪽 평행주차
    elif (0<U.d1()<26 and 0< U.d8()<26 and 37<U.d3()<65) or (0<U.d1()<26 and 37< U.d8()<65 and 37<U.d3()<65) or (37<U.d1()<65 and 37< U.d8()<65 and 37<U.d3()<65) or (37<U.d1()<65 and 37<U.d8()<65 and 0<U.d3()<26) or (37<U.d1()<65 and 0<U.d8()<26 and 0<U.d3()<26):
        os.system("mpg321 /home/odroid/MP3/execute_the_left_side,_parallel_parking,_guidance_point.mp3")
        time.sleep(0.01)
        L_Parallel()
        time.sleep(1)

    else:
        os.system("mpg321 /home/odroid/MP3/could_not_know,_parking_availability.mp3")

def Calculating():
    parking_state()
    print("** Right **")
    print("U.d2(): ",U.d2()," U.d7(): ",U.d7()," U.d5(): ",U.d5())
    print("** Left **")
    print("U.d1(): ",U.d1()," U.d8(): ",U.d8()," U.d3: ",U.d3())
    # 우측직각 단장장, 단장단, 단단장
    if (16<U.d2()<27 and 65<U.d7()<76 and 65<U.d5()<76) or (16<U.d2()<27 and 65<U.d7()<76 and 16<U.d5()<27) or (16<U.d2()<27 and 16<U.d7()<27 and 65<U.d5()<76):
        while not 65<U.d2()<76:
            BS_00(1)
        while not 16<U.d7()<26:
            FS_00(1)
        while not 65<U.d7()<76:
            BS_00(1)
        Init_num_Rotate()
        time.sleep(1)
        while not 16<U.d7()<27:
            BS00()
        FS00()
        time.sleep(0.01)
        HS00()
        time.sleep(0.5)
        time.sleep(2)
        dist = num_Rotate(1)
        print("이동거리: ",dist," cm")
        driving_state()
        if dist > 55:
            os.system("mpg321 /home/odroid/MP3/large_enough_to_park.mp3")
            return True
        else:
            os.system("mpg321 /home/odroid/MP3/not_large_enough_to_park._please,_search_other_place_to_park.mp3")
            return False


    # 우측직각 장단단, 장장단
    elif (65<U.d2()<76 and 16<U.d7()<27 and 16<U.d5()<27) or (65<U.d2()<76 and 65<U.d7()<76 and 16<U.d5()<27):
        while not 65<U.d7()<76:
            FS_00(1)
        while not 16<U.d7()<27:
            BS_00(1)
        while not 65<U.d7()<76:
            FS_00(1)
        Init_num_Rotate()
        time.sleep(1)
        while not 16<U.d7()<27:
            FS00()
        BS00()
        time.sleep(0.01)
        HS00()
        time.sleep(0.5)
        time.sleep(2)
        dist = num_Rotate(1)
        print("이동거리: ",dist," cm")
        driving_state()
        if dist > 55:
            os.system("mpg321 /home/odroid/MP3/large_enough_to_park.mp3")
            return True
        else:
            os.system("mpg321 /home/odroid/MP3/not_large_enough_to_park._please,_search_other_place_to_park.mp3")
            return False

########################################################################################################################################################################################################################

    # 좌측직각 단장장, 단장단, 단단장
    if (16<U.d1()<27 and 65<U.d8()<76 and 65<U.d3()<76) or (16<U.d1()<27 and 65<U.d8()<76 and 16<U.d3()<27) or (16<U.d1()<27 and 16<U.d8()<27 and 65<U.d3()<76):
        while not 65<U.d1()<76:
            BS_00(1)
        while not 16<U.d8()<27:
            FS_00(1)
        while not 65<U.d8()<76:
            BS_00(1)
        Init_num_Rotate()
        time.sleep(1)
        while not 16<U.d8()<27:
            BS00()
        FS00()
        time.sleep(0.01)
        HS00()
        time.sleep(0.5)
        time.sleep(2)
        dist = num_Rotate(1)
        print("이동거리: ",dist," cm")
        driving_state()
        if dist > 55:
            os.system("mpg321 /home/odroid/MP3/large_enough_to_park.mp3")
            return True
        else:
            os.system("mpg321 /home/odroid/MP3/not_large_enough_to_park._please,_search_other_place_to_park.mp3")
            return False

    # 좌측직각 장단단, 장장단
    elif (65<U.d1()<76 and 16<U.d8()<27 and 16<U.d3()<27) or (65<U.d1()<76 and 65<U.d8()<76 and 16<U.d3()<27):
        while not 65<U.d8()<76:
            FS_00(1)
        while not 16<U.d8()<27:
            BS_00(1)
        while not 65<U.d8()<76:
            FS_00(1)
        Init_num_Rotate()
        time.sleep(1)
        while not 16<U.d8()<27:
            FS00()
        BS00()
        time.sleep(0.01)
        HS00()
        time.sleep(0.5)
        time.sleep(2)
        dist = num_Rotate(1)
        print("이동거리: ",dist," cm")
        driving_state()
        if dist > 55:
            os.system("mpg321 /home/odroid/MP3/large_enough_to_park.mp3")
            return True
        else:
            os.system("mpg321 /home/odroid/MP3/not_large_enough_to_park._please,_search_other_place_to_park.mp3")
            return False

########################################################################################################################################################################################################################

    # 우측평행 단단장, 단장장
    elif (7<U.d2()<16 and 7<U.d7()<16 and 47<U.d5()<56) or (7<U.d2()<16 and 47< U.d7()<56 and 47<U.d5()<56):
        while not 7<U.d5()<16:
            BS_00(1)
        while not 7<U.d7()<16:
            BS_00(1)
        while not 47<U.d7()<56:
            FS_00(1)
        Init_num_Rotate()
        time.sleep(1)
        while not 7<U.d7()<16:
            FS00()
        BS00()
        time.sleep(0.01)
        HS00()
        time.sleep(0.5)
        time.sleep(2)
        dist = num_Rotate(1)
        print("이동거리: ",dist," cm")
        driving_state()
        if dist > 75:
            os.system("mpg321 /home/odroid/MP3/large_enough_to_park.mp3")
            return True
        else:
            return False

    # 우측평행 장장장, 장장단, 장단단
    elif (47<U.d2()<56 and 47< U.d7()<56 and 47<U.d5()<56) or (47<U.d2()<56 and 47<U.d7()<56 and 7<U.d5()<16) or (47<U.d2()<56 and 7<U.d7()<16 and 7<U.d5()<16):
        while not 7<U.d2()<16:
            BS_00(1)
        while not 47<U.d2()<56:
            FS_00(1)
        Init_num_Rotate()
        time.sleep(1)
        while not 7<U.d2()<16:
            FS00()
        BS00()
        time.sleep(0.01)
        HS00()
        time.sleep(0.5)
        time.sleep(2)
        dist = num_Rotate(1)
        print("이동거리: ",dist," cm")
        driving_state()
        if dist > 75:
            os.system("mpg321 /home/odroid/MP3/large_enough_to_park.mp3")
            return True
        else:
            os.system("mpg321 /home/odroid/MP3/not_large_enough_to_park._please,_search_other_place_to_park.mp3")
            return False

########################################################################################################################################################################################################################

    # 좌측평행 단단장, 단장장
    elif (7<U.d1()<16 and 7< U.d8()<16 and 47<U.d3()<56) or (7<U.d1()<16 and 47<U.d8()<56 and 47<U.d3()<56):
        while not 7<U.d3()<16:
            BS_00(1)
        while not 7<U.d8()<16:
            BS_00(1)
        while not 47<U.d8()<56:
            FS_00(1)
        Init_num_Rotate()
        time.sleep(1)
        while not 8<U.d8()<15:
            FS00()
        BS00()
        time.sleep(0.01)
        HS00()
        time.sleep(0.5)
        time.sleep(2)
        dist = num_Rotate(1)
        print("이동거리: ",dist," cm")
        driving_state()
        if dist > 75:
            os.system("mpg321 /home/odroid/MP3/large_enough_to_park.mp3")
            return True
        else:
            os.system("mpg321 /home/odroid/MP3/not_large_enough_to_park._please,_search_other_place_to_park.mp3")
            return False

    # 좌측평행 장장장, 장장단, 장단단
    elif (47<U.d1()<56 and 47< U.d8()<56 and 47<U.d3()<56) or (47<U.d1()<56 and 47<U.d8()<56 and 7<U.d3()<16) or (47<U.d1()<56 and 7< U.d8()<16 and 7<U.d3()<16):
        while not 7<U.d1()<16:
            BS_00(1)
        while not 47<U.d8()<56:
            FS_00(1)
        Init_num_Rotate()
        time.sleep(1)
        while not 7<U.d1()<16:
            FS00()
        BS00()
        time.sleep(0.01)
        HS00()
        time.sleep(0.5)
        time.sleep(2)
        dist = num_Rotate(1)
        print("이동거리: ",dist," cm")
        driving_state()
        if dist > 75:
            os.system("mpg321 /home/odroid/MP3/large_enough_to_park.mp3")
            return True
        else:
            os.system("mpg321 /home/odroid/MP3/not_large_enough_to_park._please,_search_other_place_to_park.mp3")
            return False

    else:
        os.system("mpg321 /home/odroid/MP3/could_not_know,_parking_availability.mp3")
        driving_state()
########################################################################################################################################################################################################################

def SIGNAL():
    Real_Data = 0
    data_S = [0,0]
    while True:
        for i in range(0,2):
            data_S[i] = ord(sock.recv(1))
        print("Real_Data is ",Real_Data)
        if data_S[0] + data_S[1] == 255 and data_S[0] in signal:
            Real_Data = data_S[0]
            break
    return Real_Data

def driving_state():
    string1 = ""
    string2 = ""
    string1 = struct.pack('!B', 251)
    string2 = struct.pack('!B', 4)
    ser.flushOutput()
    for i in range(0,3):
        ser.write(string1)
        ser.write(string2)

def parking_state():
    string1 = ""
    string2 = ""
    string1 = struct.pack('!B', 250)
    string2 = struct.pack('!B', 5)
    ser.flushOutput()
    for i in range(0,3):
        ser.write(string1)
        ser.write(string2)

def FR_50(num):
    ser.flushOutput()
    for i in range(0,num):
        FR50()
        time.sleep(0.2)
        HR50()
        time.sleep(0.5)

def BR_50(num):
    ser.flushOutput()
    for i in range(0,num):
        FR50()
        time.sleep(0.2)
        HR50()
        time.sleep(0.5)

def FR_25(num):
    ser.flushOutput()
    for i in range(0,num):
        FR25()
        time.sleep(0.2)
        HR25()
        time.sleep(0.5)

def BR_25(num):
    ser.flushOutput()
    for i in range(0,num):
        FR25()
        time.sleep(0.2)
        HR25()
        time.sleep(0.5)

def FL_50(num):
    ser.flushOutput()
    for i in range(0,num):
        FL50()
        time.sleep(0.2)
        HL50()
        time.sleep(0.5)

def BL_50(num):
    ser.flushOutput()
    for i in range(0,num):
        BL50()
        time.sleep(0.2)
        HL50()
        time.sleep(0.5)

def FL_25(num):
    ser.flushOutput()
    for i in range(0,num):
        FL25()
        time.sleep(0.2)
        HL25()
        time.sleep(0.5)

def BL_25(num):
    ser.flushOutput()
    for i in range(0,num):
        BL25()
        time.sleep(0.2)
        HL25()
        time.sleep(0.5)

def FS_00(num):
    ser.flushOutput()
    for i in range(0,num):
        FS00()
        time.sleep(0.2)
        HS00()
        time.sleep(0.5)

def BS_00(num):
    ser.flushOutput()
    for i in range(0,num):
        BS00()
        time.sleep(0.2)
        HS00()
        time.sleep(0.5)

def FR50():
    string2 = ''
    string3 = ''
    string2 = struct.pack('!B',101)
    string3 = struct.pack('!B',154)
    ser.flushOutput()
    for i in range(0,3):
        ser.write(string2)
        ser.write(string3)

def HR50():
    string2 = ''
    string3 = ''
    string2 = struct.pack('!B',102)
    string3 = struct.pack('!B',153)
    ser.flushOutput()
    for i in range(0,3):
        ser.write(string2)
        ser.write(string3)

def BR50():
    string2 = " "
    string3 = " "
    string2 = struct.pack('!B',103)
    string3 = struct.pack('!B',152)
    ser.flushOutput()
    for i in range(0,3):
        ser.write(string2)
        ser.write(string3)

def FR25():
    string2 = ''
    string3 = ''
    string2 = struct.pack('!B',104)
    string3 = struct.pack('!B',151)
    ser.flushOutput()
    for i in range(0,3):
        ser.write(string2)
        ser.write(string3)

def HR25():
    string2 = ''
    string3 = ''
    string2 = struct.pack('!B',105)
    string3 = struct.pack('!B',150)
    ser.flushOutput()
    for i in range(0,3):
        ser.write(string2)
        ser.write(string3)

def BR25():
    string2 = ''
    string3 = ''
    string2 = struct.pack('!B',106)
    string3 = struct.pack('!B',149)
    ser.flushOutput()
    for i in range(0,2):
        ser.write(string2)
        ser.write(string3)

def FS00():
    string2 = ''
    string3 = ''
    string2 = struct.pack('!B',107)
    string3 = struct.pack('!B',148)
    ser.flushOutput()
    for i in range(0,3):
        ser.write(string2)
        ser.write(string3)

def HS00():
    string2 = ''
    string3 = ''
    string2 = struct.pack('!B',108)
    string3 = struct.pack('!B',147)
    ser.flushOutput()
    for i in range(0,3):
        ser.write(string2)
        ser.write(string3)

def BS00():
    string2 = ''
    string3 = ''
    string2 = struct.pack('!B',109)
    string3 = struct.pack('!B',146)
    ser.flushOutput()
    for i in range(0,3):
        ser.write(string2)
        ser.write(string3)

def FL25():
    string2 = ''
    string3 = ''
    string2 = struct.pack('!B',110)
    string3 = struct.pack('!B',145)
    ser.flushOutput()
    for i in range(0,3):
        ser.write(string2)
        ser.write(string3)

def HL25():
    string2 = ''
    string3 = ''
    string2 = struct.pack('!B',111)
    string3 = struct.pack('!B',144)
    ser.flushOutput()
    for i in range(0,3):
        ser.write(string2)
        ser.write(string3)

def BL25():
    string2 = ''
    string3 = ''
    string2 = struct.pack('!B',112)
    string3 = struct.pack('!B',143)
    ser.flushOutput()
    for i in range(0,3):
        ser.write(string2)
        ser.write(string3)

def FL50():
    string2 = ''
    string3 = ''
    string2 = struct.pack('!B',113)
    string3 = struct.pack('!B',142)
    ser.flushOutput()
    for i in range(0,3):
        ser.write(string2)
        ser.write(string3)

def HL50():
    string2 = ''
    string3 = ''
    string2 = struct.pack('!B',114)
    string3 = struct.pack('!B',141)
    ser.flushOutput()
    for i in range(0,3):
        ser.write(string2)
        ser.write(string3)

def BL50():
    string2 = ''
    string3 = ''
    string2 = struct.pack('!B',115)
    string3 = struct.pack('!B',140)
    ser.flushOutput()
    for i in range(0,3):
        ser.write(string2)
        ser.write(string3)
