#include <Servo.h>

Servo DownServo;
Servo UpServo;

boolean B_state = false;
volatile int count = 0;
const int Hall_D = 2;
const byte Hall_sensor = A0;

int Light_sensor = A1;
int Interrupt_Light_State = 3;
int Front_Light = 8;

const int Laser = 4;

const int UpServoPin = 5;    /* Using PWM */
const int DownServoPin = 9;  /* Using PWM */
const int Buzz = 6;          /* Using PWM */

const int LED1 = 7;
int ledState = LOW;
unsigned long previousMillis = 0;
const long interval = 450;

const int Back_echo = 10;
const int Back_trig = 11;
const int Front_echo = 12;
const int Front_trig = 13;

float Front_Distance;
float Back_Distance;
int data[2];

/*****************************************************************************************************************************************/

void setup(){
  Serial.begin(9600);

  DownServo.attach(DownServoPin);
  UpServo.attach(UpServoPin);
  DownServo.write(90);
  UpServo.write(85);

  pinMode(Laser, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(Back_echo, INPUT);
  pinMode(Back_trig, OUTPUT);
  pinMode(Front_echo, INPUT);
  pinMode(Front_trig, OUTPUT);
  pinMode(Buzz, OUTPUT);
  pinMode(Hall_D, INPUT);
  pinMode(Hall_sensor, INPUT);
  pinMode(Light_sensor, INPUT);
  pinMode(Front_Light, OUTPUT);

  digitalWrite(LED1,ledState);
  analogWrite(Buzz,0);
  Serial.flush();

  int value = analogRead(Light_sensor);
  if(value > 1000)
    digitalWrite(Front_Light, LOW);
  else
    digitalWrite(Front_Light, HIGH);

  attachInterrupt(digitalPinToInterrupt(Hall_D), Calculation, RISING);
}

/*****************************************************************************************************************************************/

void loop() {
  Light_Calculation();
  for(int i = 0; i < 2; i++){
    data[i] = Serial.read();
    delay(2);
  }
  Change_state(data[0]);
  if(B_state == true) { Buzzer(); Blinking(); }
  else if(B_state == false){ digitalWrite(LED1, HIGH); analogWrite(Buzz,0); }
  if(count > 250){count = 0;}
}

/*****************************************************************************************************************************************/

float Back_Ultra(){
  float duration, distance;
  digitalWrite(Back_trig, HIGH);
  delay(10);
  digitalWrite(Back_trig, LOW);
  duration = pulseIn(Back_echo, HIGH);
  distance = ((340 * duration) / 10000) / 2;
  return distance;
}

/*****************************************************************************************************************************************/

float Front_Ultra(){
  float duration, distance;
  digitalWrite(Front_trig, HIGH);
  delay(10);
  digitalWrite(Front_trig, LOW);
  duration = pulseIn(Front_echo, HIGH);
  distance = ((340 * duration) / 10000) / 2;
  return distance;
}

/*****************************************************************************************************************************************/

void Change_state(int Var1)
{
       if(Var1 == 50 || Var1 == 85){B_state = true;}  // 부저함수로 거리비례를 한다.
  else if(Var1 == 51 || Var1 == 84){B_state = false;} // LED 반짝임을 끈다.
  else if(Var1 == 52 || Var1 == 83){
    float dist[3];
    for(int i =0;i<3;i++){
      dist[i] = Back_Ultra();
    }
    int distance = (dist[0] + dist[1] + dist[2])/3;
    Serial.write(distance); 
  }
  else if(Var1 == 53 || Var1 == 82){
    float dist[3];
    for(int i =0;i<3;i++){
      dist[i] = Front_Ultra();
    }
    int distance = (dist[0] + dist[1] + dist[2])/3;
    Serial.write(distance);
  }
  else if(Var1 == 54 || Var1 == 81){ digitalWrite(Laser, LOW);  DownServo.write(85); UpServo.write(85); }   // Nothing
  else if(Var1 == 55 || Var1 == 80){ digitalWrite(Laser, HIGH); DownServo.write(85); UpServo.write(120); }   // 왼쪽직각
  else if(Var1 == 56 || Var1 == 79){ digitalWrite(Laser, HIGH); DownServo.write(85); UpServo.write(112);}   // 오른쪽직각
  else if(Var1 == 57 || Var1 == 78){ digitalWrite(Laser, HIGH); DownServo.write(85); UpServo.write(60); }   // 왼쪽평행
  else if(Var1 == 58 || Var1 == 77){ digitalWrite(Laser, HIGH); DownServo.write(85); UpServo.write(124); }   // 오른쪽평행
  else if(Var1 == 59 || Var1 == 76){Serial.write(int(count)); }   // 회전횟수
  else if(Var1 == 60 || Var1 == 75){count = 0;}
 
}

/*****************************************************************************************************************************************/

void Buzzer() {
  float dist = Back_Ultra();
  if(dist <= 26)
  {
    analogWrite(Buzz, 70);
    delay((dist/26)*100);
    analogWrite(Buzz,0);
    delay((dist/26)*100);
  }
  else
    analogWrite(Buzz,0);
}

/*****************************************************************************************************************************************/

void Blinking() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if (ledState == LOW) {ledState = HIGH;}
    else {ledState = LOW;}
    digitalWrite(LED1, ledState);}
}
/*****************************************************************************************************************************************/

void Calculation(){
  count += 1;
}

/*****************************************************************************************************************************************/

void Light_Calculation(){ // 어두워질수록 센서값이 커진다.
  int value = analogRead(Light_sensor);
  if(value > 900)
    digitalWrite(Front_Light, LOW);
  else
    digitalWrite(Front_Light, HIGH);
}

/*****************************************************************************************************************************************/
