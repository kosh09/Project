

//---------------------------------------------------------------- HEADER Declare
#include <Servo.h>

//---------------------------------------------------------------- PIN Declare

Servo myservo;
int ServoPin = 6;
int Motor_direction = 13;
int Motor_pwm = 11;
int Motor_break = 8;
byte Serial_data;

//---------------------------------------------------------------- Initialisation( same baudrate as python script)
void setup()
{
  Serial.begin(38400);                                        
  myservo.attach(servoPin);

  //-------------------------------------------------------------- PINMODE Setting
  pinMode(Motor_direction, OUTPUT);
  pinMode(Motor_pwm, OUTPUT);
  pinMode(Motor_break, OUTPUT);
}

void loop()
{
  if(Serial.available())
  {
    Serial_data = (Serial.read());
    Serial_algorithm(Serial_data);
  }
}

//---------------------------------------------------------------- Fuction_Serial --> for BT to Serial
void Serial_algorithm(byte _data)
{
  if(_data == "<10>"){digitalWrite(Motor_direction, HIGH); digitalWrite(Motor_pwm, 230); digitalWrite(Motor_break, LOW); myservo.write(120);}       // FR30
  else if(_data == "<11>"){digitalWrite(Motor_direction, HIGH); digitalWrite(Motor_pwm, 230); digitalWrite(Motor_break, LOW); myservo.write(115);}  // FR25
  else if(_data == "<12>"){digitalWrite(Motor_direction, HIGH); digitalWrite(Motor_pwm, 230); digitalWrite(Motor_break, LOW); myservo.write(110);}  // FR20
  else if(_data == "<13>"){digitalWrite(Motor_direction, HIGH); digitalWrite(Motor_pwm, 230); digitalWrite(Motor_break, LOW); myservo.write(105);}  // FR15
  else if(_data == "<14>"){digitalWrite(Motor_direction, HIGH); digitalWrite(Motor_pwm, 230); digitalWrite(Motor_break, LOW); myservo.write(100);}  // FR10
  else if(_data == "<15>"){digitalWrite(Motor_direction, HIGH); digitalWrite(Motor_pwm, 230); digitalWrite(Motor_break, LOW); myservo.write(95);}   // FR05
  else if(_data == "<16>"){digitalWrite(Motor_direction, HIGH); digitalWrite(Motor_pwm, 230); digitalWrite(Motor_break, LOW); myservo.write(90);}   // FS00
  else if(_data == "<17>"){digitalWrite(Motor_direction, HIGH); digitalWrite(Motor_pwm, 230); digitalWrite(Motor_break, LOW); myservo.write(85);}   // FL05
  else if(_data == "<18>"){digitalWrite(Motor_direction, HIGH); digitalWrite(Motor_pwm, 230); digitalWrite(Motor_break, LOW); myservo.write(80);}   // FL10
  else if(_data == "<19>"){digitalWrite(Motor_direction, HIGH); digitalWrite(Motor_pwm, 230); digitalWrite(Motor_break, LOW); myservo.write(75);}   // FL15
  else if(_data == "<20>"){digitalWrite(Motor_direction, HIGH); digitalWrite(Motor_pwm, 230); digitalWrite(Motor_break, LOW); myservo.write(70);}   // FL20
  else if(_data == "<21>"){digitalWrite(Motor_direction, HIGH); digitalWrite(Motor_pwm, 230); digitalWrite(Motor_break, LOW); myservo.write(65);}   // FL25
  else if(_data == "<22>"){digitalWrite(Motor_direction, HIGH); digitalWrite(Motor_pwm, 230); digitalWrite(Motor_break, LOW); myservo.write(60);}   // FL30

  else if(_data == "<23>"){digitalWrite(Motor_direction, NULL); digitalWrite(Motor_pwm, 0); digitalWrite(Motor_break, HIGH); myservo.write(120);}   // HR30
  else if(_data == "<24>"){digitalWrite(Motor_direction, NULL); digitalWrite(Motor_pwm, 0); digitalWrite(Motor_break, HIGH); myservo.write(115);}   // HR25
  else if(_data == "<25>"){digitalWrite(Motor_direction, NULL); digitalWrite(Motor_pwm, 0); digitalWrite(Motor_break, HIGH); myservo.write(110);}   // HR20
  else if(_data == "<26>"){digitalWrite(Motor_direction, NULL); digitalWrite(Motor_pwm, 0); digitalWrite(Motor_break, HIGH); myservo.write(105);}   // HR15
  else if(_data == "<27>"){digitalWrite(Motor_direction, NULL); digitalWrite(Motor_pwm, 0); digitalWrite(Motor_break, HIGH); myservo.write(100);}   // HR10
  else if(_data == "<28>"){digitalWrite(Motor_direction, NULL); digitalWrite(Motor_pwm, 0); digitalWrite(Motor_break, HIGH); myservo.write(95);}    // HR05
  else if(_data == "<29>"){digitalWrite(Motor_direction, NULL); digitalWrite(Motor_pwm, 0); digitalWrite(Motor_break, HIGH); myservo.write(90);}    // HS00
  else if(_data == "<30>"){digitalWrite(Motor_direction, NULL); digitalWrite(Motor_pwm, 0); digitalWrite(Motor_break, HIGH); myservo.write(85);}    // HL05
  else if(_data == "<31>"){digitalWrite(Motor_direction, NULL); digitalWrite(Motor_pwm, 0); digitalWrite(Motor_break, HIGH); myservo.write(80);}    // HL10
  else if(_data == "<32>"){digitalWrite(Motor_direction, NULL); digitalWrite(Motor_pwm, 0); digitalWrite(Motor_break, HIGH); myservo.write(75);}    // HL15
  else if(_data == "<33>"){digitalWrite(Motor_direction, NULL); digitalWrite(Motor_pwm, 0); digitalWrite(Motor_break, HIGH); myservo.write(70);}    // HL20
  else if(_data == "<34>"){digitalWrite(Motor_direction, NULL); digitalWrite(Motor_pwm, 0); digitalWrite(Motor_break, HIGH); myservo.write(65);}    // HL25
  else if(_data == "<35>"){digitalWrite(Motor_direction, NULL); digitalWrite(Motor_pwm, 0); digitalWrite(Motor_break, HIGH); myservo.write(60);}    // HL30

  else if(_data == "<36>"){digitalWrite(Motor_direction, NULL); digitalWrite(Motor_pwm, 230); digitalWrite(Motor_break, LOW); myservo.write(120);}   // BR30
  else if(_data == "<37>"){digitalWrite(Motor_direction, NULL); digitalWrite(Motor_pwm, 230); digitalWrite(Motor_break, LOW); myservo.write(120);}   // BR25
  else if(_data == "<38>"){digitalWrite(Motor_direction, NULL); digitalWrite(Motor_pwm, 230); digitalWrite(Motor_break, LOW); myservo.write(120);}   // BR20
  else if(_data == "<39>"){digitalWrite(Motor_direction, NULL); digitalWrite(Motor_pwm, 230); digitalWrite(Motor_break, LOW); myservo.write(120);}   // BR15
  else if(_data == "<40>"){digitalWrite(Motor_direction, NULL); digitalWrite(Motor_pwm, 230); digitalWrite(Motor_break, LOW); myservo.write(120);}   // BR10
  else if(_data == "<41>"){digitalWrite(Motor_direction, NULL); digitalWrite(Motor_pwm, 230); digitalWrite(Motor_break, LOW); myservo.write(120);}   // BR05
  else if(_data == "<42>"){digitalWrite(Motor_direction, NULL); digitalWrite(Motor_pwm, 230); digitalWrite(Motor_break, LOW); myservo.write(120);}   // BS00
  else if(_data == "<43>"){digitalWrite(Motor_direction, NULL); digitalWrite(Motor_pwm, 230); digitalWrite(Motor_break, LOW); myservo.write(120);}   // BL05
  else if(_data == "<44>"){digitalWrite(Motor_direction, NULL); digitalWrite(Motor_pwm, 230); digitalWrite(Motor_break, LOW); myservo.write(120);}   // BL10
  else if(_data == "<45>"){digitalWrite(Motor_direction, NULL); digitalWrite(Motor_pwm, 230); digitalWrite(Motor_break, LOW); myservo.write(120);}   // BL15
  else if(_data == "<46>"){digitalWrite(Motor_direction, NULL); digitalWrite(Motor_pwm, 230); digitalWrite(Motor_break, LOW); myservo.write(120);}   // BL20
  else if(_data == "<47>"){digitalWrite(Motor_direction, NULL); digitalWrite(Motor_pwm, 230); digitalWrite(Motor_break, LOW); myservo.write(120);}   // BL25
  else if(_data == "<48>"){digitalWrite(Motor_direction, NULL); digitalWrite(Motor_pwm, 230); digitalWrite(Motor_break, LOW); myservo.write(120);}   // BL30
  


}

