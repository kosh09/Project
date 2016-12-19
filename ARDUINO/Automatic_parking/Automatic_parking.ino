#include <Servo.h>

Servo myservo; // 서보모터 선언

int buzzer = 2;
int motor_direction = 13;
int motor_pwm = 11;
int motor_break = 8;

int trigPin1 = 23; // 전방 우측 센서
int echoPin1 = 22;
int trigPin2 = 25; // 전방 중앙 센서
int echoPin2 = 24;
int trigPin3 = 27; // 전방 좌측 센서
int echoPin3 = 26;
int trigPin4 = 48; // 후방 좌측 센서
int echoPin4 = 49;
int trigPin5 = 50; // 후방 중앙 센서
int echoPin5 = 51;
int trigPin6 = 52; // 후방 우측 센서
int echoPin6 = 53;


void setup()
{
  myservo.attach(5); // 서보모터를 5번핀에 연결
  myservo.write(90);  // 90'가 중심각도 여기서 +,- 30~31'가 조향임.
                      // 서보모터 회전정도를 정함 30~31이 최고임.

  Serial.begin(9600);
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
  float distance1 = duration1 /29.0/2.0;

  digitalWrite(trigPin2, LOW);  
  digitalWrite(echoPin2, LOW);
  delay(2);          
  digitalWrite(trigPin2, HIGH);   
  delay(10);       
  digitalWrite(trigPin2, LOW);
  unsigned long duration2 = pulseIn(echoPin2, HIGH);
  float distance2 = duration2 /29.0/2.0;
  
  digitalWrite(trigPin3, LOW);  
  digitalWrite(echoPin3, LOW);
  delay(2);          
  digitalWrite(trigPin3, HIGH);   
  delay(10);       
  digitalWrite(trigPin3, LOW);
  unsigned long duration3 = pulseIn(echoPin3, HIGH);
  float distance3 = duration3 /29.0/2.0;

  digitalWrite(trigPin4, LOW);  
  digitalWrite(echoPin4, LOW);
  delay(2);          
  digitalWrite(trigPin4, HIGH);   
  delay(10);       
  digitalWrite(trigPin4, LOW);
  unsigned long duration4 = pulseIn(echoPin4, HIGH);
  float distance4 = duration4 /29.0/2.0;

  digitalWrite(trigPin5, LOW);  
  digitalWrite(echoPin5, LOW);
  delay(2);          
  digitalWrite(trigPin5, HIGH);   
  delay(10);       
  digitalWrite(trigPin5, LOW);
  unsigned long duration5 = pulseIn(echoPin5, HIGH);
  float distance5 = duration5 /29.0/2.0;

  long duration6, distance6;    
  digitalWrite(trigPin6, LOW);  
  delay(2);          
  digitalWrite(trigPin6, HIGH);   
  delay(10);       
  digitalWrite(trigPin6, LOW);
  duration6 = pulseIn(echoPin6, HIGH);
  distance6 = duration6 * 17 / 1000;

  Serial.print("\nDistance1: ");
  Serial.print(distance1);
  Serial.print("cm\n\n");

  Serial.print("\nDistance2: ");
  Serial.print(distance2);
  Serial.print("cm\n\n");
  
  Serial.print("\nDistance3: ");
  Serial.print(distance3);
  Serial.print("cm\n\n");
  
  Serial.print("\nDistance4: ");
  Serial.print(distance4);
  Serial.print("cm\n\n");
  
  Serial.print("\nDistance5: ");
  Serial.print(distance5);
  Serial.print("cm\n\n");
  
  Serial.print("\nDistance6: ");
  Serial.print(distance6);
  Serial.print("cm\n\n");

   
  }
  

