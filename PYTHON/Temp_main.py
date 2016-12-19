from multiprocessing import Process, Queue, Pipe

import Laser_Distance as LD       # 레이저로 거리재는 함수
import numpy as np                # 배열을 저장하기 위한 공식 모듈
import Definition as DEF          # 정의들을 해놓은 모듈
import Serial_Sensor as SS        # 오드로이드의 초음파 센서 2개의 값을 받는 부분
import Serial_Motor as SM         # 오드로이드가 모터와의 시리얼 통신을 하는 부분
import BT_Serial as BT            # 블루투스 컨트롤러와의 통신을 위한 모듈
import Parking_algorithm as Pa    # 주차시퀸스가 설명되어 있는 부분이다.

###########################################################################
######################          함 수 정 의           ######################
###########################################################################

def serial_con():     # 시리얼 통신이 이루어지고 있다.
    Serial_connection.distance_serial()
def dist1():          # 카메라를 통해서 영상처리가 이루어지고 있다.
    dis1 = detect_color_from_openCV.cam_dist1()
def dist2():
    
def dist3():
    dis2 = detect_color_from_openCV.cam_dist2()
def dist4():
    dis3 = detect_color_from_openCV.cam_dist3()
def dist5():
    
def dist6():
    dis4 = detect_color_from_openCV.cam_dist4()
def dist7():

def dist(8):
    
###########################################################################
######################          주 차 부 분           ######################
###########################################################################

def DRIVING():
    


###########################################################################
######################          주 행 부 분           ######################
###########################################################################





