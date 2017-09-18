###################################################################
###############################  전방  #############################
###################################################################
############     U.d1()       U.Front()          U.d2()    ########
###################################################################
###################################################################
############     U.d8()     ###############     U.d7()     ########
###################################################################
###################################################################
###########     U.d3()        B.Back()          U.d5()     ########
###################################################################
##############################  후방  #############################
###################################################################

import __ULT_DIST__ as U
import __BLUETOOTH__ as B
import time
import os

start =    [139,116]
shutdown = [121 ,134]
reboot =   [120, 135]
All =      [116, 120, 121, 134, 135, 139]

def Park():
    B.stop_recv()
    time.sleep(0.5)
    B.buzzer_on()
    time.sleep(0.5)
    B.Initialize()
    time.sleep(0.5)
    os.system("mpg321 /home/odroid/MP3/Start_the_Parking_sequence.mp3")
    time.sleep(2)
    B.parking_state()
    while True:
        print("R--Front: ",U.d2()," Middle: ",U.d7()," Back: ",U.d5())
        print("L--Front: ",U.d1()," Middle: ",U.d8()," Back: ",U.d3())

        # 우측 직각주차 /단장장/단장단/단단장/
        if (16<U.d2()<27 and 65<U.d7()<76 and 65<U.d5()<76) or (16<U.d2()<27 and 65<U.d7()<76 and 16<U.d5()<27) or (16<U.d2()<27 and 16<U.d7()<27 and 65<U.d5()<76):
            while not 65<U.d2()<76:
                B.BS_00(1)
                print("우측 전방: ",U.d2())
            while not 16<U.d7()<27:
                B.BS_00(1)
                print("우측 중앙: ",U.d7())
            for i in range(0,2):
                B.FS00()
                time.sleep(0.2)
                B.HS00()
                time.sleep(0.2)
            B.HS00()
            time.sleep(2)
            B.HL50()
            time.sleep(2)
            B.FL50()
            time.sleep(1.5)
            B.BL50()
            time.sleep(0.01)
            B.HL50()
            time.sleep(2)
            B.HR50()
            time.sleep(2)
            B.BR50()
            time.sleep(1.52)
            B.FR50()
            time.sleep(0.01)
            B.HR50()
            time.sleep(2)
            B.HS00()
            time.sleep(2)
            while True:
                B.BS00()
                time.sleep(0.2)
                B.HS00()
                time.sleep(0.2)
                print("후빙거리: ",B.Back())
                if B.Back() < 7:
                    break
            B.HS00()
            time.sleep(2)
            B.buzzer_off()
            os.system("mpg321 /home/odroid/MP3/Finish_the_parking_sequence.mp3")
            B.driving_state()
            B.start_recv()
            while True:
                if B.SIGNAL() in start:
                    B.stop_recv()
                    break
                elif B.SIGNAL() in shutdown:
                    B.stop_recv()
                    os.system("mpg321 /home/odroid/MP3/shutdown.mp3")
                    time.sleep(1)
                    os.system("sudo shutdown now -h")
                elif B.SIGNAL() in reboot:
                    B.stop_recv()
                    os.system("mpg321 /home/odroid/MP3/reboot.mp3")
                    time.sleep(1)
                    os.system("sudo reboot")
            break

###################################################################################################################

        #우측 직각주차 /장단단/장장단/
        elif (65<U.d2()<76 and 16<U.d7()<27 and 16<U.d5()<27) or (65<U.d2()<76 and 65<U.d7()<76 and 16<U.d5()<27):
            while not 65<U.d7()<76:
                B.BS_00(1)
                print("우측 중앙: ",U.d7())
            time.sleep(2)
            while not 16<U.d7()<27:
                B.BS_00(1)
                print("우측 중앙: ",U.d7())
                time.sleep(1)
            for i in range(0,2):
                B.FS00()
                time.sleep(0.2)
                B.HS00()
                time.sleep(0.2)
            B.HS00()
            time.sleep(2)
            B.HL50()
            time.sleep(2)
            B.FL50()
            time.sleep(1.5)
            B.BL50()
            time.sleep(0.01)
            B.HL50()
            time.sleep(2)
            B.HR50()
            time.sleep(2)
            B.BR50()
            time.sleep(1.52)
            B.FR50()
            time.sleep(0.01)
            B.HR50()
            time.sleep(2)
            B.HS00()
            time.sleep(2)
            while True:
                B.BS00()
                time.sleep(0.2)
                B.HS00()
                time.sleep(0.2)
                print("후빙거리: ",B.Back())
                if B.Back() < 7:
                    break
            B.HS00()
            time.sleep(2)
            B.buzzer_off()
            os.system("mpg321 /home/odroid/MP3/Finish_the_parking_sequence.mp3")
            B.driving_state()
            B.start_recv()
            while True:
                if B.SIGNAL() in start:
                    B.stop_recv()
                    break
                elif B.SIGNAL() in shutdown:
                    B.stop_recv()
                    os.system("mpg321 /home/odroid/MP3/shutdown.mp3")
                    os.system("sudo shutdown now -h")
                elif B.SIGNAL() in reboot:
                    B.stop_recv()
                    os.system("mpg321 /home/odroid/MP3/reboot.mp3")
                    os.system("sudo reboot")
            break

###################################################################################################################

        # 왼쪽 직각주차 /장단단/장장단/
        elif (65<U.d1()<76 and 16<U.d8()<27 and 16<U.d3()<27) or (65<U.d1()<76 and 65<U.d8()<76 and 16<U.d3()<27):
            while not 65<U.d1()<76:
                B.BS_00(1)
                print("좌측전방: ",U.d1())
            while not 16<U.d8()<27:
                B.BS_00(1)
                print("좌측중앙: ",U.d8())
            for i in range(0,2):
                B.FS00()
                time.sleep(0.2)
                B.HS00()
                time.sleep(0.2)
            B.HS00()
            time.sleep(2)
            B.HR50()
            time.sleep(2)
            B.FR50()
            time.sleep(1.5)
            B.BR50()
            time.sleep(0.01)
            B.HR50()
            time.sleep(2)
            B.HL50()
            time.sleep(2)
            B.BL50()
            time.sleep(1.52)
            B.FL50()
            time.sleep(0.01)
            B.HL50()
            time.sleep(2)
            B.HS00()
            time.sleep(2)
            while True:
                B.BS00()
                time.sleep(0.2)
                B.HS00()
                time.sleep(0.2)
                print("후빙거리: ",B.Back())
                if B.Back() < 7:
                    break
            B.HS00()
            time.sleep(2)
            B.buzzer_off()
            os.system("mpg321 /home/odroid/MP3/Finish_the_parking_sequence.mp3")
            B.driving_state()
            B.start_recv()
            while True:
                if B.SIGNAL() in start:
                    B.stop_recv()
                    break
                elif B.SIGNAL() in shutdown:
                    B.stop_recv()
                    os.system("mpg321 /home/odroid/MP3/shutdown.mp3")
                    time.sleep(1)
                    os.system("sudo shutdown now -h")
                elif B.SIGNAL() in reboot:
                    B.stop_recv()
                    os.system("mpg321 /home/odroid/MP3/reboot.mp3")
                    time.sleep(1)
                    os.system("sudo reboot")
            break

###################################################################################################################

        #왼쪽 직각주차 /단장장/단장단/단단장/
        elif (16<U.d1()<27 and 65<U.d8()<76 and 65<U.d3()<76) or (16<U.d1()<27 and 65<U.d8()<76 and 16<U.d3()<27) or (17<U.d1()<26 and 17<U.d8()<26 and 65<U.d3()<76):
            while not 65<U.d1()<76:
                B.BS_00(1)
                print("좌측전방: ",U.d1())
            time.sleep(1)
            while not 16<U.d8()<27:
                B.BS_00(1)
                print("좌측중앙: ",U.d8())
            time.sleep(1)
            for i in range(0,2):
                B.FS00()
                time.sleep(0.2)
                B.HS00()
                time.sleep(0.2)
            B.HS00()
            time.sleep(2)
            B.HR50()
            time.sleep(2)
            B.FR50()
            time.sleep(1.5)
            B.BR50()
            time.sleep(0.01)
            B.HR50()
            time.sleep(2)
            B.HL50()
            time.sleep(2)
            B.BL50()
            time.sleep(1.52)
            B.FL50()
            time.sleep(0.01)
            B.HL50()
            time.sleep(2)
            B.HS00()
            time.sleep(2)
            while True:
                B.BS00()
                time.sleep(0.2)
                B.HS00()
                time.sleep(0.2)
                print("후방거리: ",B.Back())
                if B.Back() < 7:
                    break
            B.HS00()
            time.sleep(2)
            B.buzzer_off()
            os.system("mpg321 /home/odroid/MP3/Finish_the_parking_sequence.mp3")
            B.driving_state()
            B.start_recv()
            while True:
                if B.SIGNAL() in start:
                    B.stop_recv()
                    break
                elif B.SIGNAL() in shutdown:
                    B.stop_recv()
                    os.system("mpg321 /home/odroid/MP3/shutdown.mp3")
                    os.system("sudo shutdown now -h")
                elif B.SIGNAL() in reboot:
                    B.stop_recv()
                    os.system("mpg321 /home/odroid/MP3/reboot.mp3")
                    os.system("sudo reboot")
            break

###################################################################################################################

        # 오른쪽 평행주차 단단장, 단장장
        elif (7<U.d2()<16 and 7<U.d7()<16 and 47<U.d5()<56) or (7<U.d2()<16 and 47<U.d7()<56 and 47<U.d5()<56):
            while not 47<U.d5()<56:
                B.BS_00(1)
                print("우측후방: ",U.d5())
            B.FS_00(2)
            time.sleep(1)
            B.HR50()
            time.sleep(1)
            B.BR50()        # 뒤로들어가는 과정
            time.sleep(1.6) #
            B.FR50()        #
            time.sleep(0.1) #
            B.HR50()        #
            time.sleep(1)   #
            B.HL50()        # 반대방향으로 나머지 들어가는과정
            time.sleep(1)   #
            B.BL50()        #
            time.sleep(1.5) #
            B.FL50()        #
            time.sleep(0.1) #
            B.HL50()        #
            time.sleep(1)   #
            B.HS00()
            while True:
                front = B.Front()
                back = B.Back()
                dist = (front + back)/2
                print("전방: ",B.Front(),"후방: ",B.Back())
                if front > dist+3:
                    while not front <= dist:
                        B.FS_00(1)
                elif back > dist +3:
                    while not back <= dist:
                        B.BS_00(1)
                else:
                    break
            time.sleep(2)
            B.buzzer_off()
            os.system("mpg321 /home/odroid/MP3/Finish_the_parking_sequence.mp3")
            B.driving_state()
            B.start_recv()
            while True:
                if B.SIGNAL() in start:
                    B.stop_recv()
                    break
                elif B.SIGNAL() in shutdown:
                    B.stop_recv()
                    os.system("mpg321 /home/odroid/MP3/shutdown.mp3")
                    os.system("sudo shutdown now -h")
                elif B.SIGNAL() in reboot:
                    B.stop_recv()
                    os.system("mpg321 /home/odroid/MP3/reboot.mp3")
                    os.system("sudo reboot")
            break

###################################################################################################################

            #오른쪽 평행주차/ 장장장, 장장단, 장단단
        elif (47<U.d2()<56 and 47<U.d7()<56 and 47<U.d5()<56) or (47 < U.d2() < 56 and 47 < U.d7() < 56 and 7<U.d5()<16) or (47<U.d2()<56 and 7<U.d7()<16 and 7<U.d5()<16):
            while not 48 < U.d2() < 55:
                B.FS00()
                time.sleep(0.2)
                B.BH00()
                time.sleep(1)
            time.sleep(2)
            while not 48 < U.d5() < 55:
                B.FS00()
                time.sleep(0.2)
                B.BH00()
                time.sleep(1)
            B.FS_00(2)
            time.sleep(1)
            B.HR50()
            time.sleep(1)
            B.BR50()        # 뒤로들어가는 과정
            time.sleep(1.4) #
            B.FR50()        #
            time.sleep(0.1) #
            B.HR50()        #
            time.sleep(1)   #
            B.HL50()        # 반대방향으로 나머지 들어가는과정
            time.sleep(1)   #
            B.BL50()        #
            time.sleep(1.4) #
            B.FL50()        #
            time.sleep(0.1) #
            B.HL50()        #
            time.sleep(1)   #
            B.HS00()
            while True:
                front = B.Front()
                back = B.Back()
                dist = (front + back)/2
                print("전방: ",B.Front(),"후방: ",B.Back())
                if front > dist+3:
                    while not front <= dist:
                        B.FS_00(1)
                elif back > dist +3:
                    while not back <= dist:
                        B.BS_00(1)
                else:
                    break

            time.sleep(2)
            B.buzzer_off()
            os.system("mpg321 /home/odroid/MP3/Finish_the_parking_sequence.mp3")
            B.driving_state()
            B.start_recv()
            while True:
                if B.SIGNAL() in start:
                    B.stop_recv()
                    break
                elif B.SIGNAL() in shutdown:
                    B.stop_recv()
                    os.system("mpg321 /home/odroid/MP3/shutdown.mp3")
                    os.system("sudo shutdown now -h")
                elif B.SIGNAL() in reboot:
                    B.stop_recv()
                    os.system("mpg321 /home/odroid/MP3/reboot.mp3")
                    os.system("sudo reboot")
            break

###################################################################################################################

        # 왼쪽 평행주차 단단장, 단장장
        elif (7<U.d1()<16 and 7<U.d8()<16 and 47<U.d3()<56) or (7<U.d1()<16 and 47<U.d8()<56 and 47<U.d3()<56):
            while not 48 < U.d3() < 55:
                B.FS00()
                time.sleep(0.2)
                B.BH00()
                time.sleep(1)
            B.FS_00(2)
            time.sleep(1)
            B.HR50()
            time.sleep(1)
            B.BR50()        # 뒤로들어가는 과정
            time.sleep(1.4) #
            B.FR50()        #
            time.sleep(0.1) #
            B.HR50()        #
            time.sleep(1)   #
            B.HL50()        # 반대방향으로 나머지 들어가는과정
            time.sleep(1)   #
            B.BL50()        #
            time.sleep(1.4) #
            B.FL50()        #
            time.sleep(0.1) #
            B.HL50()        #
            time.sleep(1)   #
            B.HS00()
            while True:
                front = B.Front()
                back = B.Back()
                dist = (front + back)/2
                print("전방: ",B.Front(),"후방: ",B.Back())
                if front > dist+3:
                    while not front <= dist:
                        B.FS_00(1)
                elif back > dist +3:
                    while not back <= dist:
                        B.BS_00(1)
                else:
                    break
            time.sleep(2)
            B.buzzer_off()
            os.system("mpg321 /home/odroid/MP3/Finish_the_parking_sequence.mp3")
            B.driving_state()
            B.start_recv()
            while True:
                if B.SIGNAL() in start:
                    B.stop_recv()
                    break
                elif B.SIGNAL() in shutdown:
                    B.stop_recv()
                    os.system("mpg321 /home/odroid/MP3/shutdown.mp3")
                    os.system("sudo shutdown now -h")
                elif B.SIGNAL() in reboot:
                    B.stop_recv()
                    os.system("mpg321 /home/odroid/MP3/reboot.mp3")
                    os.system("sudo reboot")
            break

###################################################################################################################

            #왼쪽 평행주차/ 장장장, 장장단, 장단단
        elif (47<U.d1()<56 and 47<U.d8()<56 and 47<U.d3()<56) or (47<U.d1()<56 and 47<U.d8()<56 and 7<U.d3()<16) or (47<U.d1()<56 and 7<U.d8()<16 and 7<U.d3()<16):
            while not 48 < U.d1() < 55:
                B.FS00()
                time.sleep(0.2)
                B.BH00()
                time.sleep(1)
            time.sleep(2)
            while not 48 < U.d3() < 55:
                B.FS00()
                time.sleep(0.2)
                B.BH00()
                time.sleep(1)
            B.FS_00(2)
            time.sleep(1)
            B.HR50()
            time.sleep(1)
            B.BR50()        # 뒤로들어가는 과정
            time.sleep(1.4) #
            B.FR50()        #
            time.sleep(0.1) #
            B.HR50()        #
            time.sleep(1)   #
            B.HL50()        # 반대방향으로 나머지 들어가는과정
            time.sleep(1)   #
            B.BL50()        #
            time.sleep(1.4) #
            B.FL50()        #
            time.sleep(0.1) #
            B.HL50()        #
            time.sleep(1)   #
            B.HS00()
            while True:
                front = B.Front()
                back = B.Back()
                dist = (front + back)/2
                print("전방: ",B.Front(),"후방: ",B.Back())
                if front > dist+3:
                    while not front <= dist:
                        B.FS_00(1)
                elif back > dist +3:
                    while not back <= dist:
                        B.BS_00(1)
                else:
                    break
            time.sleep(2)
            B.buzzer_off()
            os.system("mpg321 /home/odroid/MP3/Finish_the_parking_sequence.mp3")
            B.driving_state()
            B.start_recv()
            while True:
                if B.SIGNAL() in start:
                    B.stop_recv()
                    break
                elif B.SIGNAL() in shutdown:
                    B.stop_recv()
                    os.system("mpg321 /home/odroid/MP3/shutdown.mp3")
                    os.system("sudo shutdown now -h")
                elif B.SIGNAL() in reboot:
                    B.stop_recv()
                    os.system("mpg321 /home/odroid/MP3/reboot.mp3")
                    os.system("sudo reboot")
            break
