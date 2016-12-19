  #include <Servo.h>

  const int servoPin = 6;
  Servo myservo; // 서보모터 선언
  
  const int motor_direction = 13;
  const int motor_pwm = 11;
  const int motor_break = 8;  // HIGH 일때 강제정지

//****************************************************//
//**** 위의 설정은 DC모터의 B쪽에 연결을 했을때입니다. ****//
//****************************************************//

  const int trigPin1 =  2; // 전방센서
  const int echoPin1 =  3;
  const int trigPin2 =  4; // 후방센서
  const int echoPin2 =  5;
  const int trigPin3 =  7; // 좌측센서
  const int echoPin3 =  9;
  const int trigPin4 = 10; // 우측센서
  const int echoPin4 = 12;

void setup()
{
  Serial.begin(38400);  
  myservo.attach(servoPin); // 서보모터를 6번핀에 연결
  myservo.write(90);        // 90'가 중심각도 여기서 +,- 30~31'가 조향임.
                            // 서보모터 회전정도를 정함 30~31이 최고임.
  

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
}



void loop()
{
    digitalWrite(trigPin1, LOW);  
  digitalWrite(echoPin1, LOW);
  delay(2);          
  digitalWrite(trigPin1, HIGH);   
  delay(10);       
  digitalWrite(trigPin1, LOW);
  unsigned long duration1 = pulseIn(echoPin1, HIGH);
  int distance1 = duration1 /29.0/2.0;

  digitalWrite(trigPin2, LOW);  
  digitalWrite(echoPin2, LOW);
  delay(2);          
  digitalWrite(trigPin2, HIGH);   
  delay(10);       
  digitalWrite(trigPin2, LOW);
  unsigned long duration2 = pulseIn(echoPin2, HIGH);
  int distance2 = duration2 /29.0/2.0;
  
  digitalWrite(trigPin3, LOW);  
  digitalWrite(echoPin3, LOW);
  delay(2);          
  digitalWrite(trigPin3, HIGH);   
  delay(10);       
  digitalWrite(trigPin3, LOW);
  unsigned long duration3 = pulseIn(echoPin3, HIGH);
  int distance3 = duration3 /29.0/2.0;

  digitalWrite(trigPin4, LOW);  
  digitalWrite(echoPin4, LOW);
  delay(2);          
  digitalWrite(trigPin4, HIGH);   
  delay(10);       
  digitalWrite(trigPin4, LOW);
  unsigned long duration4 = pulseIn(echoPin4, HIGH);
  int distance4 = duration4 /29.0/2.0;


  Serial.write(distance1);
  delay(5);
  Serial.write(distance2);
  delay(5);  
  Serial.write(distance3);
  delay(5);
  Serial.write(distance4);
  delay(5);
/*

  if(Serial.find("R30")){myservo.write(120);}
  if(Serial.find("R25")){myservo.write(115);}
  if(Serial.find("R20")){myservo.write(110);}
  if(Serial.find("R15")){myservo.write(105);}
  if(Serial.find("R10")){myservo.write(100);}
  if(Serial.find("R05")){myservo.write(95);}
  if(Serial.find("S")){myservo.write(90);
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


  if(Serial.find("F")){  // 앞으로 가는 문자열 넣어주면 된다.
    digitalWrite(motor_pwm, 200);
    digitalWrite(motor_direction, HIGH);
    digitalWrite(motor_break, LOW);
    }
  if(Serial.find("H")){  // 정지하는 문자열 넣어주면 된다.
    digitalWrite(motor_pwm, 0);
    digitalWrite(motor_direction, HIGH);
    digitalWrite(motor_break, HIGH);
  
    }
  if(Serial.find("B")){ // 뒤로가는 문자열 넣어주면 도니다.
    digitalWrite(motor_pwm, 200);
    digitalWrite(motor_direction, LOW);
    digitalWrite(motor_break, LOW);
    }
*/
}
