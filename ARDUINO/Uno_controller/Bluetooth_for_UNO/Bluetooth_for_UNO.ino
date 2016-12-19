
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3);   //bluetooth module Tx:Digital 2 Rx:Digital 3


const byte PIN_BUTTON_RIGHT = 3;
const byte PIN_BUTTON_UP = 2;
const byte PIN_BUTTON_LEFT = 5; 
const byte PIN_ANALOG_X = 0;
const byte PIN_ANALOG_Y = 1;


void setup() {
  Serial.begin(9600);
  BTSerial.begin(38400);

  pinMode(PIN_BUTTON_RIGHT, INPUT);  
  digitalWrite(PIN_BUTTON_RIGHT, HIGH);
 
  pinMode(PIN_BUTTON_LEFT, INPUT);  
  digitalWrite(PIN_BUTTON_LEFT, HIGH);
 
  pinMode(PIN_BUTTON_UP, INPUT);  
  digitalWrite(PIN_BUTTON_UP, HIGH);
}


void loop() {
  
  if(PIN_BUTTON_LEFT == LOW){
    // 주차모드가 발동되도록 한다.---> 주행프로세스 종료, 주차프로세스 실행
    Serial.write(BTSerial.write("JC"));
  }

  if(PIN_BUTTON_RIGHT == LOW){
    // 주행모드가 발동되도록 한다.---> 주차프로세스 종료, 주행프로세스 실행
    BTSerial.write("JH");
  }

//### 좌/우 방향을 결정하는 부분 ###//

  if(0 <= PIN_ANALOG_X < 84){
    BTSerial.write("L30");
  }
  if(84 <= PIN_ANALOG_X < 168){
    BTSerial.write("L25");
  }
  if(168 <= PIN_ANALOG_X < 252){
    BTSerial.write("L20");
  }
  if(252 <= PIN_ANALOG_X < 336){
    BTSerial.write("L15");
  }
  if(336 <= PIN_ANALOG_X < 420){
   BTSerial.write("L10");
  }
  if(420 <= PIN_ANALOG_X < 474){
   BTSerial.write("L5");
  }
  if(474 <= PIN_ANALOG_X < 534){
    BTSerial.write('S');
  }
  if(534 <= PIN_ANALOG_X < 588){
    BTSerial.write("R5");
  }
  if(588 <= PIN_ANALOG_X < 672){
    BTSerial.write("R10");
  }
  if(672 <= PIN_ANALOG_X < 756){
    BTSerial.write("R15");
  }
  if(756 <= PIN_ANALOG_X < 840){
    BTSerial.write("R20");
  }
  if(840 <= PIN_ANALOG_X < 924){
    BTSerial.write("R25");
  }
  if(924 <= PIN_ANALOG_X < 1008){
    BTSerial.write("R30");
  }   

//### 앞/뒤 방향을 결정하는 부분 ###//
  if(540 < PIN_ANALOG_Y <= 1025){
    BTSerial.write("F");
  }
  if(0 <= PIN_ANALOG_Y < 507){
    BTSerial.write("B");
  } 
}
