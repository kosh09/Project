import cv2
from numpy import *
import math
import sys

sys.setrecursionlimit(1500)

def laser1():
    #variables
    loop = 1
    dot_dist = 0

    cv2.namedWindow("preview")
    vc = cv2.VideoCapture(1) #내 카메라가 몇번인지 알고 숫자를 수정해주어야한다.

    if vc.isOpened():
        rval, frame = vc.read()

    else:
        rval = False

    if rval == 1 :

        while loop == 1:
                cv2.imshow("preview", frame)
                rval, frame = vc.read()
                key = cv2.waitKey(20)
                if key == 27: # exit on ESC
                    loop = 0
                num = (frame[...,...,2] > 236)
                xy_val =  num.nonzero()

                y_val = median(xy_val[0])
                x_val = median(xy_val[1])

                #dist = ((x_val - 320)**2 + (y_val - 240)**2 )**0.5 # distance of dot from center pixel
                dist = abs(x_val - 320) # distance of dot from center x_axis only

                theta =0.0011450*dist + 0.0154
                tan_theheta=math.tan(theta)

                if tan_theta > 0:
                    obj_dist =  int(5.33 / tan_theta)

                return obj_dist
    elif rval == 0:
            laser1()


def laser2():
    loop = 1
    dot_dist = 0

    cv2.namedWindow("preview")
    vc = cv2.VideoCapture(5) #내 카메라가 몇번인지 알고 숫자를 수정해주어야한다.

    if vc.isOpened():
        rval, frame = vc.read()

    else:
        rval = False

    if rval == 1 :

        while loop == 1:
                cv2.imshow("preview", frame)
                rval, frame = vc.read()
                key = cv2.waitKey(20)
                if key == 27:
                    loop = 0
                num = (frame[...,...,2] > 236)
                xy_val =  num.nonzero()

                y_val = median(xy_val[0])
                x_val = median(xy_val[1])

                #dist = ((x_val - 320)**2 + (y_val - 240)**2 )**0.5 # distance of dot from center pixel
                dist = abs(x_val - 320) # distance of dot from center x_axis only

                theta =0.0011450*dist + 0.0154
                tan_theheta = math.tan(theta)

                if tan_theta > 0:
                    obj_dist =  int(5.33 / tan_theta)

                return obj_dist
    elif rval == 0:
            laser2()            

def laser3():
    #variables
    loop = 1
    dot_dist = 0

    cv2.namedWindow("preview")
    vc = cv2.VideoCapture(2) #내 카메라가 몇번인지 알고 숫자를 수정해주어야한다.

    if vc.isOpened(): # try to get the first frame
        rval, frame = vc.read()

    else:
        rval = False

    if rval == 1 :

        while loop == 1:
                cv2.imshow("preview", frame)
                rval, frame = vc.read()
                key = cv2.waitKey(20)
                if key == 27: 
                    loop = 0
                num = (frame[...,...,2] > 236)
                xy_val =  num.nonzero()

                y_val = median(xy_val[0])
                x_val = median(xy_val[1])

                #dist = ((x_val - 320)**2 + (y_val - 240)**2 )**0.5 # distance of dot from center pixel
                dist = abs(x_val - 320) # distance of dot from center x_axis onl
                
                theta =0.0011450*dist + 0.0154
                tan_theheta=math.tan(theta)

                if tan_theta > 0:
                    obj_dist =  int(5.33 / tan_theta)

                return obj_dist
    elif rval == 0:
            laser3()


def laser4():
    loop = 1
    dot_dist = 0

    cv2.namedWindow("preview")
    vc = cv2.VideoCapture(3) #내 카메라가 몇번인지 알고 숫자를 수정해주어야한다.

    if vc.isOpened():
        rval, frame = vc.read()

    else:
        rval = False

    if rval == 1 :

        while loop == 1:
                cv2.imshow("preview", frame)
                rval, frame = vc.read()
                key = cv2.waitKey(20)
                if key == 27: # exit on ESC
                    loop = 0
                num = (frame[...,...,2] > 236)
                xy_val =  num.nonzero()

                y_val = median(xy_val[0])
                x_val = median(xy_val[1])

                #dist = ((x_val - 320)**2 + (y_val - 240)**2 )**0.5 # distance of dot from center pixel
                dist = abs(x_val - 320) # distance of dot from center x_axis only

                theta =0.0011450*dist + 0.0154
                tan_theheta=math.tan(theta)

                if tan_theta > 0: 
                    obj_dist =  int(5.33 / tan_theta)

                return obj_dist
    elif rval == 0:
            laser4()            
