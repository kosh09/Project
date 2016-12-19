#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3); // RX, TX

const byte PIN_BUTTON_RIGHT = 3;
const byte PIN_BUTTON_UP = 2;
const byte PIN_BUTTON_LEFT = 5;
const byte PIN_ANALOG_X = 0;
const byte PIN_ANALOG_Y = 1;

int RL;
int FB;
int switch1;
int switch2;

void setup() 
{
  // Serial.begin(57600);
  BTSerial.begin(57600);
  
  pinMode(PIN_BUTTON_RIGHT, INPUT);  
  digitalWrite(PIN_BUTTON_RIGHT, HIGH);
  pinMode(PIN_BUTTON_LEFT, INPUT);  
  digitalWrite(PIN_BUTTON_LEFT, HIGH);
  pinMode(PIN_BUTTON_UP, INPUT);  
  digitalWrite(PIN_BUTTON_UP, HIGH);
}


void loop()
{
  
  const int UP = digitalRead(PIN_BUTTON_UP);
  const int RIGHT = digitalRead(PIN_BUTTON_RIGHT);
  const int LEFT = digitalRead(PIN_BUTTON_LEFT);
  const int X = analogRead(PIN_ANALOG_X);
  const int Y = analogRead(PIN_ANALOG_Y);

/*
  Serial.print("UP: ");
  Serial.print(UP);

  Serial.print(" RIGHT: ");
  Serial.print(RIGHT);

  Serial.print(" LEFT: ");
  Serial.print(LEFT);

  Serial.print(" X: ");
  Serial.print(X);

  Serial.print(" Y");
  Serial.print(Y);
  Serial.println(); */

//###########################//
//### 좌/우를 선택하는 부분 ###//
//###########################//

  if(0 <= X && X < 134){
   // Serial.print("L30 ");
    RL = 130;
  }
  if(134 <= X && X < 198){
  //  Serial.print("L25 ");
    RL = 125; 
  }
  if(198 <= X && X < 262){
  //  Serial.print("L20 ");
    RL = 120;
  }
  if(262 <= X && X < 326){
    RL = 115;
  }
  if(326 <= X && X < 390){
  //  Serial.print("L10 ");
    RL = 110;
  }
  if(390 <= X && X < 454){
  //  Serial.print("L05 ");
    RL = 105;
  }
    if(454 <= X && X < 554){
  //  Serial.print("S ");
    RL = 200;
  }
  if(554 <= X && X < 632){
  //  Serial.print("R05 ");
    RL = 305;
  }
  if(632 <= X && X < 710){
  //  Serial.print("R10 ");
    RL = 310;
  }
  if(710 <= X && X < 788){
    RL = 315;
  //  Serial.print(RL);
  }
  if(788 <= X && X < 866){
    RL = 320;
  //  Serial.print(RL);
  }
  if(866 <= X && X < 944){
    RL = 325;
  //  Serial.print(RL);
  }
  if(944 <= X && X < 1025){
    RL = 330;
   // Serial.print(RL);
  }

//###########################//
//### 앞/뒤를 선택하는 부분 ###//
//###########################//

  if(583 <= Y && Y < 1025){
   // Serial.print("F ");
    FB = 400;
  }
  if(473 <= Y && Y < 583){
    FB = 500;
   // Serial.print("H ");
  }
  if(0 <= Y && Y < 473){
    FB = 600;
    // Serial.print("B ");
  }

//###########################//
//### 버튼을 선택하는 부분 ###//
//###########################//  

  if(LEFT == 0){
    switch1 = 1;
    // Serial.print("PA ");
    }
   // 아래가 클릭이 안된 상태이다.
   if(LEFT == 1){
    switch1 = 0;
    // Serial.print("NA"); 
    }
    
   if(RIGHT == 0){
    switch2 = 1;
    // Serial.print("DR ");
    }
   // 아래가 클릭이 되지않은 상태이다. 
   if(RIGHT == 1){
    switch2 = 0;
    // Serial.print("DR ");
    }


    BTSerial.write(RL);
    delay(10);
    BTSerial.write(FB);
    delay(10);
    BTSerial.write(switch1);
    delay(10);
    BTSerial.write(switch2);
    delay(100);
   }
