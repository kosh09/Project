# 모든 전송하는 데이터의 크기는 3byte로 맞추고 하자

def Stop():
    ser.write('00H'.encode()) # H를 전송시에는 멈춘다.

def Foward():
    ser.write('00F'.encode()) # F를 전송해서 앞으로 간다.

def Back():
    ser.write('00B'.encode()) # B를 전송해서 뒤로 간다.

def Stra():
    ser.write('00S'.encode()) # S를 전송해서 곧은 방향.

def Left05():
    ser.write('L05'.encode()) # L을 전송해서 왼쪽으로 방향.

def Left10():
    ser.write('L10'.encode()) # L을 전송해서 왼쪽으로 방향.

def Left15():
    ser.write('L15'.encode()) # L을 전송해서 왼쪽으로 방향.

def Left20():
    ser.write('L20'.encode()) # L을 전송해서 왼쪽으로 방향.

def Left25():
    ser.write('L25'.encode()) # L을 전송해서 왼쪽으로 방향.

def Left30():
    ser.write('L30'.encode()) # L을 전송해서 왼쪽으로 방향.

def Right05():
    ser.write('R05'.encode()) # R을 전송해서 오른쪽 방향.

def Right10():
    ser.write('R10'.encode()) # R을 전송해서 오른쪽 방향.

def Right15():
    ser.write('R15'.encode()) # R을 전송해서 오른쪽 방향.
    
def Right20():
    ser.write('R20'.encode()) # R을 전송해서 오른쪽 방향.

def Right25():
    ser.write('R25'.encode()) # R을 전송해서 오른쪽 방향.

def Right30():
    ser.write('R30'.encode()) # R을 전송해서 오른쪽 방향.

# 한번에 값이 2개씩 들어오는 경우가 있는 것 같으니 생각해보자.

