
//---------------------------------------------------------------- HEADER Declare
#include <Servo.h>
#include <LEDEffect.h>


//---------------------------------------------------------------- PIN Declare
Servo myservo;
int Servo_Pin =  6;
int Motor_brk =  9;
int Motor_dir = 10;
int Motor_pwm = 11;
int LASER = 8;
int Data;

boolean STATE_1 = false;
boolean STATE_2 = false;


LEDEffect Blink_LED(12);
LEDEffect Const_LED(13);

//---------------------------------------------------------------- Initialisation( same baudrate as python script)
void setup()
{
  Serial.begin(57600);
  myservo.attach(Servo_Pin);
  Const_LED.on();

  //-------------------------------------------------------------- PINMODE Setting
  pinMode(Motor_dir, OUTPUT);
  pinMode(Motor_pwm, OUTPUT);
  pinMode(Motor_brk, OUTPUT);
  pinMode(LASER, OUTPUT);
  myservo.write(95);
}

void loop()
{
  if(Serial.available())
  {
    Data = Serial.read();
    Serial_algorithm(Data);
    SIGNAL_(Data);
   }
}

//---------------------------------------------------------------- Fuction_Serial
void Serial_algorithm(int A)
{
       if(A == 10){myservo.write(145); digitalWrite(Motor_dir, HIGH);analogWrite(Motor_pwm, 250); }  // FFFR50
  else if(A == 11){myservo.write(145); digitalWrite(Motor_dir, HIGH);analogWrite(Motor_pwm, 180); }  //  FFR50
  else if(A == 12){myservo.write(145); digitalWrite(Motor_dir, HIGH);analogWrite(Motor_pwm, 120); }  //   FR50
  else if(A == 13){myservo.write(145); digitalWrite(Motor_dir, NULL);analogWrite(Motor_pwm,   0); } //   HR50
  else if(A == 14){myservo.write(145); digitalWrite(Motor_dir, LOW); analogWrite(Motor_pwm, 120); }  //   BR50
  else if(A == 15){myservo.write(145); digitalWrite(Motor_dir, LOW); analogWrite(Motor_pwm, 180); }  //  BBR50
  else if(A == 16){myservo.write(145); digitalWrite(Motor_dir, LOW); analogWrite(Motor_pwm, 250); }  // BBBR50

  else if(A == 17){myservo.write(130); digitalWrite(Motor_dir, HIGH);analogWrite(Motor_pwm, 250); }  // FFFR35
  else if(A == 18){myservo.write(130); digitalWrite(Motor_dir, HIGH);analogWrite(Motor_pwm, 180); }  //  FFR35
  else if(A == 19){myservo.write(130); digitalWrite(Motor_dir, HIGH);analogWrite(Motor_pwm, 120); }  //   FR35
  else if(A == 20){myservo.write(130); digitalWrite(Motor_dir, NULL);analogWrite(Motor_pwm,   0); } //   HR35
  else if(A == 21){myservo.write(130); digitalWrite(Motor_dir, LOW); analogWrite(Motor_pwm, 120); }  //   BR35
  else if(A == 22){myservo.write(130); digitalWrite(Motor_dir, LOW); analogWrite(Motor_pwm, 180); }  //  BBR35
  else if(A == 23){myservo.write(130); digitalWrite(Motor_dir, LOW); analogWrite(Motor_pwm, 250); }  // BBBR35

  else if(A == 24){myservo.write(110); digitalWrite(Motor_dir, HIGH);analogWrite(Motor_pwm, 250); }  // FFFR15
  else if(A == 25){myservo.write(110); digitalWrite(Motor_dir, HIGH);analogWrite(Motor_pwm, 180); }  //  FFR15
  else if(A == 26){myservo.write(110); digitalWrite(Motor_dir, HIGH);analogWrite(Motor_pwm, 120); }  //   FR15
  else if(A == 27){myservo.write(110); digitalWrite(Motor_dir, NULL);analogWrite(Motor_pwm,   0); } //   HR15
  else if(A == 28){myservo.write(110); digitalWrite(Motor_dir, LOW); analogWrite(Motor_pwm, 120); }  //   BR15
  else if(A == 29){myservo.write(110); digitalWrite(Motor_dir, LOW); analogWrite(Motor_pwm, 180); }  //  BBR15
  else if(A == 30){myservo.write(110); digitalWrite(Motor_dir, LOW); analogWrite(Motor_pwm, 250); }  // BBBR15

  else if(A == 31){myservo.write(95); digitalWrite(Motor_dir, HIGH); analogWrite(Motor_pwm, 250); }  // FFFS00
  else if(A == 32){myservo.write(95); digitalWrite(Motor_dir, HIGH); analogWrite(Motor_pwm, 180); }  //  FFS00
  else if(A == 33){myservo.write(95); digitalWrite(Motor_dir, HIGH); analogWrite(Motor_pwm, 120); }  //   FS00
  else if(A == 34){myservo.write(95); digitalWrite(Motor_dir, NULL); analogWrite(Motor_pwm,   0); } //   HS00
  else if(A == 35){myservo.write(95); digitalWrite(Motor_dir, LOW);  analogWrite(Motor_pwm, 120); }  //   BS00
  else if(A == 36){myservo.write(95); digitalWrite(Motor_dir, LOW);  analogWrite(Motor_pwm, 180); }  //  BBS00
  else if(A == 37){myservo.write(95); digitalWrite(Motor_dir, LOW);  analogWrite(Motor_pwm, 250); }  // BBBS00

  else if(A == 38){myservo.write(80); digitalWrite(Motor_dir, HIGH); analogWrite(Motor_pwm, 250); }  // FFFL15
  else if(A == 39){myservo.write(80); digitalWrite(Motor_dir, HIGH); analogWrite(Motor_pwm, 180); }  //  FFL15
  else if(A == 40){myservo.write(80); digitalWrite(Motor_dir, HIGH); analogWrite(Motor_pwm, 120); }  //   FL15
  else if(A == 41){myservo.write(80); digitalWrite(Motor_dir, NULL); analogWrite(Motor_pwm,   0); } //   HL15
  else if(A == 42){myservo.write(80); digitalWrite(Motor_dir, LOW);  analogWrite(Motor_pwm, 120); }  //   BL15
  else if(A == 43){myservo.write(80); digitalWrite(Motor_dir, LOW);  analogWrite(Motor_pwm, 180); }  //  BBL15
  else if(A == 44){myservo.write(80); digitalWrite(Motor_dir, LOW);  analogWrite(Motor_pwm, 250); }  // BBBL15

  else if(A == 45){myservo.write(60); digitalWrite(Motor_dir, HIGH); analogWrite(Motor_pwm, 250); }  // FFFL35
  else if(A == 46){myservo.write(60); digitalWrite(Motor_dir, HIGH); analogWrite(Motor_pwm, 180); }  //  FFL35
  else if(A == 47){myservo.write(60); digitalWrite(Motor_dir, HIGH); analogWrite(Motor_pwm, 120); }  //   FL35
  else if(A == 48){myservo.write(60); digitalWrite(Motor_dir, NULL); analogWrite(Motor_pwm,   0); } //   HL35
  else if(A == 49){myservo.write(60); digitalWrite(Motor_dir, LOW);  analogWrite(Motor_pwm, 120); }  //   BL35
  else if(A == 50){myservo.write(60); digitalWrite(Motor_dir, LOW);  analogWrite(Motor_pwm, 180); }  //  BBL35
  else if(A == 51){myservo.write(60); digitalWrite(Motor_dir, LOW);  analogWrite(Motor_pwm, 250); }  // BBBL35

  else if(A == 52){myservo.write(45); digitalWrite(Motor_dir, HIGH); analogWrite(Motor_pwm, 250); }  // FFFL50
  else if(A == 53){myservo.write(45); digitalWrite(Motor_dir, HIGH); analogWrite(Motor_pwm, 180); }  //  FFL50
  else if(A == 54){myservo.write(45); digitalWrite(Motor_dir, HIGH); analogWrite(Motor_pwm, 120); }  //   FL50
  else if(A == 55){myservo.write(45); digitalWrite(Motor_dir, NULL); analogWrite(Motor_pwm,   0); } //   HL50
  else if(A == 56){myservo.write(45); digitalWrite(Motor_dir, LOW);  analogWrite(Motor_pwm, 120); }  //   BL50
  else if(A == 57){myservo.write(45); digitalWrite(Motor_dir, LOW);  analogWrite(Motor_pwm, 180); }  //  BBL50
  else if(A == 58){myservo.write(45); digitalWrite(Motor_dir, LOW);  analogWrite(Motor_pwm, 250); }  // BBBL50

  else if(A == 59){myservo.write(145); digitalWrite(Motor_dir, HIGH);  analogWrite(Motor_pwm, 120); }  //   FR50
  else if(A == 60){myservo.write(145); digitalWrite(Motor_dir, NULL);  analogWrite(Motor_pwm,   0); } //   HR50
  else if(A == 61){myservo.write(145); digitalWrite(Motor_dir, LOW);   analogWrite(Motor_pwm, 120); }  //   BR50

  else if(A == 62){myservo.write(130); digitalWrite(Motor_dir, HIGH);  analogWrite(Motor_pwm, 120); }  //   FR35
  else if(A == 63){myservo.write(130); digitalWrite(Motor_dir, NULL);  analogWrite(Motor_pwm,   0); } //   HR35
  else if(A == 64){myservo.write(130); digitalWrite(Motor_dir, LOW);   analogWrite(Motor_pwm, 120); }  //   BR35

  else if(A == 65){myservo.write(110); digitalWrite(Motor_dir, HIGH);  analogWrite(Motor_pwm, 120); }  //   FR15
  else if(A == 66){myservo.write(110); digitalWrite(Motor_dir, NULL);  analogWrite(Motor_pwm,   0); } //   HR15
  else if(A == 67){myservo.write(110); digitalWrite(Motor_dir, LOW);   analogWrite(Motor_pwm, 120); }  //   BR15

  else if(A == 68){myservo.write(95); digitalWrite(Motor_dir, HIGH);   analogWrite(Motor_pwm, 120); }  //   FS00
  else if(A == 69){myservo.write(95); digitalWrite(Motor_dir, NULL);   analogWrite(Motor_pwm,   0); } //   HS00
  else if(A == 70){myservo.write(95); digitalWrite(Motor_dir, LOW);    analogWrite(Motor_pwm, 120); }  //   BS00

  else if(A == 71){myservo.write(80); digitalWrite(Motor_dir, HIGH);   analogWrite(Motor_pwm, 120); }  //   FL15
  else if(A == 72){myservo.write(80); digitalWrite(Motor_dir, NULL);   analogWrite(Motor_pwm,   0); } //   HL15
  else if(A == 73){myservo.write(80); digitalWrite(Motor_dir, LOW);    analogWrite(Motor_pwm, 120); }  //   BL15

  else if(A == 74){myservo.write(60); digitalWrite(Motor_dir, HIGH);   analogWrite(Motor_pwm, 120); }  //   FL35
  else if(A == 75){myservo.write(60); digitalWrite(Motor_dir, NULL);   analogWrite(Motor_pwm,   0); } //   HL35
  else if(A == 76){myservo.write(60); digitalWrite(Motor_dir, LOW);    analogWrite(Motor_pwm, 120); }  //   BL35

  else if(A == 77){myservo.write(45); digitalWrite(Motor_dir, HIGH);   analogWrite(Motor_pwm, 120); }  //   FL50
  else if(A == 78){myservo.write(45); digitalWrite(Motor_dir, NULL);   analogWrite(Motor_pwm,   0); } //   HL50
  else if(A == 79){myservo.write(45); digitalWrite(Motor_dir, LOW);    analogWrite(Motor_pwm, 120); }  //   BL50
}

void SIGNAL_(int A)
{
  if(A == 80){STATE_1 = false;}       // STATE_1 for LED Blink
  else if(A == 81){STATE_1 = true;}   // STATE_2 for LASER ON/OFF
  else if(A == 82){STATE_2 = true;}
  else if(A == 83){STATE_2 = false;}
  else;

  if(STATE_1 == false){Blink_LED.off();}
  if(STATE_1 == true) {Blink_LED.blink(500);}
  
  if(STATE_2 == false){digitalWrite(LASER,HIGH);}
  if(STATE_2 == true){digitalWrite(LASER,LOW);} 
}
