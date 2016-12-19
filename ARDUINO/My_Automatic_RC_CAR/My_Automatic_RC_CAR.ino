
  #include <Servo.h>

  Servo myservo; // 서보모터 선언

  const int buzzer = 2;
  
  const int motor_direction = 13;
  const int motor_pwm = 11;
  const int motor_break = 8;  // HIGH 일때 강제정지

  const int trigPin1 = 23; // 전방 우측 센서
  const int echoPin1 = 22;
  const int trigPin2 = 25; // 전방 중앙 센서
  const int echoPin2 = 24;
  const int trigPin3 = 27; // 전방 좌측 센서
  const int echoPin3 = 26;
  const int trigPin4 = 48; // 후방 좌측 센서
  const int echoPin4 = 49;
  const int trigPin5 = 50; // 후방 중앙 센서
  const int echoPin5 = 51;
  const int trigPin6 = 52; // 후방 우측 센서
  const int echoPin6 = 53;

void setup()
{
  myservo.attach(5); // 서보모터를 5번핀에 연결
  myservo.write(90);  // 90'가 중심각도 여기서 +,- 30~31'가 조향임.
                      // 서보모터 회전정도를 정함 30~31이 최고임.
  
  pinMode(buzzer, OUTPUT);

  pinMode(motor_direction, OUTPUT);
  pinMode(motor_pwm, OUTPUT);
  pinMode(motor_break, OUTPUT);
  
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
  pinMode(trigPin5, OUTPUT);
  pinMode(echoPin5, INPUT);
  pinMode(trigPin6, OUTPUT);
  pinMode(echoPin6, INPUT);

  Serial.begin(38400);
  while(!Serial){
    ; // Serial port가 연결될때까지 기다린다.
    }
}



void loop()
{
  int duration1, distance1;    
  digitalWrite(trigPin1, LOW);  
  delay(2);          
  digitalWrite(trigPin1, HIGH);   
  delay(10);       
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1 * 17 / 1000;
  
  int duration2, distance2;    
  digitalWrite(trigPin2, LOW);  
  delay(2);          
  digitalWrite(trigPin2, HIGH);   
  delay(10);       
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 * 17 / 1000;
  
  int duration3, distance3;    
  digitalWrite(trigPin3, LOW);  
  delay(2);          
  digitalWrite(trigPin3, HIGH);   
  delay(10);       
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distance3 = duration3 * 17 / 1000;
  
  int duration4, distance4;    
  digitalWrite(trigPin4, LOW);  
  delay(2);          
  digitalWrite(trigPin4, HIGH);   
  delay(10);       
  digitalWrite(trigPin4, LOW);
  duration4 = pulseIn(echoPin4, HIGH);
  distance4 = duration4 * 17 / 1000;
  
  int duration5, distance5;    
  digitalWrite(trigPin5, LOW);  
  delay(2);          
  digitalWrite(trigPin5, HIGH);   
  delay(10);       
  digitalWrite(trigPin5, LOW);
  duration5 = pulseIn(echoPin5, HIGH);
  distance5 = duration5 * 17 / 1000;
  
  int duration6, distance6;    
  digitalWrite(trigPin6, LOW);  
  delay(2);          
  digitalWrite(trigPin6, HIGH);   
  delay(10);       
  digitalWrite(trigPin6, LOW);
  duration6 = pulseIn(echoPin6, HIGH);
  distance6 = duration6 * 17 / 1000;  
  
  Serial.write(distance1);
  delay(100);
  
  Serial.write(distance2);
  delay(100);
  
  Serial.write(distance3);
  delay(100);
  
  Serial.write(distance4);
  delay(100);
  
  Serial.write(distance5);
  delay(100);
  
  Serial.write(distance6);
  delay(100);

  if(Serial.available())
  {
    if(Serial.find("R30")){
      myservo.write(120);
      }
    if(Serial.find("R25")){
      myservo.write(115);
      }
    if(Serial.find("R20")){
      myservo.write(110);
      }
    if(Serial.find("R15")){
      myservo.write(105);
      }
    if(Serial.find("R10")){
      myservo.write(100);
      }
    if(Serial.find("R05")){
      myservo.write(95);
      }
    if(Serial.find("S")){
      myservo.write(90);
      }
    if(Serial.find("L05")){
      myservo.write(85);
      }
    if(Serial.find("L10")){
      myservo.write(80);
      }
    if(Serial.find("L15")){
      myservo.write(75);
      }
    if(Serial.find("L20")){
      myservo.write(70);
      }
    if(Serial.find("L25")){
      myservo.write(65);
      }
    if(Serial.find("L30")){
      myservo.write(60);
      }


    if(Serial.find("F")){
      digitalWrite(motor_pwm, 200);
      digitalWrite(motor_direction, HIGH);
      digitalWrite(motor_break, LOW);
      }
    if(Serial.find("H")){
      digitalWrite(motor_pwm, 0);
      digitalWrite(motor_direction, HIGH);
      digitalWrite(motor_break, HIGH);
    
      }
    if(Serial.find("B")){
      digitalWrite(motor_pwm, 200);
      digitalWrite(motor_direction, LOW);
      digitalWrite(motor_break, LOW)
      }
    }

    if(distance5 < 20)
    {
      tone(buzzer, 3000, distance5*50)
      // 후방거리가 20cm일때부터 울리도록하자.
    }
 
}
