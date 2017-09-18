#include <Servo.h>

//---------------------------------------------------------------- PIN Declare
Servo myservo;
int Led1 = 4;
int Led2 = 5;
int Servo_Pin =  6;
int Motor_pwm = 11;
int Motor_dir = 12;
int data[2];
boolean Parking_State=false;

//입력전압의 값을 계산하기 위한 변수들
int value;
float vout = 0.0;
float vin = 0.0;
float R1 = 100000.0;
float R2 = 10000.0;
float Parking_PWM;

//---------------------------------------------------------------- Initialisation
void setup()
{
  Serial.begin(57600);
  myservo.attach(Servo_Pin);

  //-------------------------------------------------------------- PINMODE Setting
  pinMode(Motor_dir, OUTPUT);
  pinMode(Motor_pwm, OUTPUT);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  
  digitalWrite(Led1,LOW);
  digitalWrite(Led2,LOW);

  myservo.write(95);
  analogWrite(Motor_pwm,0);
  Serial.flush();
}

void Parking_state(int Var)
{
  if(Var == 4 || Var == 251)
    Parking_State = false;
  else if(Var == 5 || Var == 250)
    Parking_State =  true;
}

float Parking_pwm()
{
  value = analogRead(A0);
  vout = (value * 5.0) / 1024.0;
  vin = vout / (R2/(R1+R2));
  float PWM = 30*vin/11.15;
  return PWM;
}

struct DriveControllData
{
  byte Var;
  byte Degree;
  byte Direction;
  byte MotorPWM;
  byte LED1;
  byte LED2;
};

#define DRIVE_SIZE 91

DriveControllData DriveControllDataTable[DRIVE_SIZE] =
{
  {245,  45, HIGH, 60,  LOW,  LOW}, // 6FR50
  {238,  45, HIGH, 57,  LOW,  LOW}, // 5FR50
  {231,  45, HIGH, 45,  LOW,  LOW}, // 4FR50
  {224,  45, HIGH, 40,  LOW,  LOW}, // 3FR50
  {217,  45, HIGH, 35,  LOW,  LOW}, // 2FR50
  {210,  45, HIGH, 30,  LOW,  LOW}, // 1FR50
  {203,  45, NULL,  0, HIGH, HIGH}, // 0HR50
  {196,  45,  LOW, 30,  LOW,  LOW}, // 1BR50
  {189,  45,  LOW, 35,  LOW,  LOW}, // 2BR50
  {182,  45,  LOW, 40,  LOW,  LOW}, // 3BR50
  {175,  45,  LOW, 45,  LOW,  LOW}, // 4BR50
  {168,  45,  LOW, 57,  LOW,  LOW}, // 5BR50
  {161,  45,  LOW, 60,  LOW,  LOW}, // 6BR50

  {244,  60, HIGH, 60,  LOW,  LOW}, // 6FR35
  {237,  60, HIGH, 57,  LOW,  LOW}, // 5FR35
  {230,  60, HIGH, 45,  LOW,  LOW}, // 4FR35
  {223,  60, HIGH, 40,  LOW,  LOW}, // 3FR35
  {216,  60, HIGH, 35,  LOW,  LOW}, // 2FR35
  {209,  60, HIGH, 30,  LOW,  LOW}, // 1FR35
  {202,  60, NULL,  0, HIGH, HIGH}, // 0HR35
  {195,  60,  LOW, 30,  LOW,  LOW}, // 1BR35
  {188,  60,  LOW, 35,  LOW,  LOW}, // 2BR35
  {181,  60,  LOW, 40,  LOW,  LOW}, // 3BR35
  {174,  60,  LOW, 45,  LOW,  LOW}, // 4BR35
  {167,  60,  LOW, 57,  LOW,  LOW}, // 5BR35
  {160,  60,  LOW, 60,  LOW,  LOW}, // 6BR35
  
  {243,  80, HIGH, 60,  LOW,  LOW}, // 6FR15
  {236,  80, HIGH, 57,  LOW,  LOW}, // 5FR15
  {229,  80, HIGH, 45,  LOW,  LOW}, // 4FR15
  {222,  80, HIGH, 40,  LOW,  LOW}, // 3FR15
  {215,  80, HIGH, 35,  LOW,  LOW}, // 2FR15
  {208,  80, HIGH, 30,  LOW,  LOW}, // 1FR15
  {201,  80, NULL,  0, HIGH, HIGH}, // 0HR15
  {194,  80,  LOW, 30,  LOW,  LOW}, // 1BR15
  {187,  80,  LOW, 35,  LOW,  LOW}, // 2BR15
  {180,  80,  LOW, 40,  LOW,  LOW}, // 3BR15
  {173,  80,  LOW, 45,  LOW,  LOW}, // 4BR15
  {166,  80,  LOW, 57,  LOW,  LOW}, // 5BR15
  {159,  80,  LOW, 60,  LOW,  LOW}, // 6BR15
  
  {242,  95, HIGH, 60,  LOW,  LOW}, // 6FS00
  {235,  95, HIGH, 57,  LOW,  LOW}, // 5FS00
  {228,  95, HIGH, 45,  LOW,  LOW}, // 4FS00
  {221,  95, HIGH, 40,  LOW,  LOW}, // 3FS00
  {214,  95, HIGH, 35,  LOW,  LOW}, // 2FS00
  {207,  95, HIGH, 30,  LOW,  LOW}, // 1FS00
  {200,  95, NULL,  0, HIGH, HIGH}, // 0HS00
  {193,  95,  LOW, 30,  LOW,  LOW}, // 1BS00
  {186,  95,  LOW, 35,  LOW,  LOW}, // 2BS00
  {179,  95,  LOW, 40,  LOW,  LOW}, // 3BS00
  {172,  95,  LOW, 45,  LOW,  LOW}, // 4BS00
  {165,  95,  LOW, 57,  LOW,  LOW}, // 5BS00
  {158,  95,  LOW, 60,  LOW,  LOW}, // 6BS00
  
  {241, 110, HIGH, 60,  LOW,  LOW}, // 6FL15
  {234, 110, HIGH, 57,  LOW,  LOW}, // 5FL15
  {227, 110, HIGH, 45,  LOW,  LOW}, // 4FL15
  {220, 110, HIGH, 40,  LOW,  LOW}, // 3FL15
  {213, 110, HIGH, 35,  LOW,  LOW}, // 2FL15
  {206, 110, HIGH, 30,  LOW,  LOW}, // 1FL15
  {199, 110, NULL,  0, HIGH, HIGH}, // 0HF15
  {192, 110,  LOW, 30,  LOW,  LOW}, // 1BL15
  {185, 110,  LOW, 35,  LOW,  LOW}, // 2BL15
  {178, 110,  LOW, 40,  LOW,  LOW}, // 3BL15
  {171, 110,  LOW, 45,  LOW,  LOW}, // 4BL15
  {164, 110,  LOW, 57,  LOW,  LOW}, // 5BL15
  {157, 110,  LOW, 60,  LOW,  LOW}, // 6BL15
  
  {240, 130, HIGH, 60,  LOW,  LOW}, // 6FL35
  {233, 130, HIGH, 57,  LOW,  LOW}, // 5FL35
  {226, 130, HIGH, 45,  LOW,  LOW}, // 4FL35
  {219, 130, HIGH, 40,  LOW,  LOW}, // 3FL35
  {212, 130, HIGH, 35,  LOW,  LOW}, // 2FL35
  {205, 130, HIGH, 30,  LOW,  LOW}, // 1FL35
  {198, 130, NULL,  0, HIGH, HIGH}, // 0HL35
  {191, 130,  LOW, 30,  LOW,  LOW}, // 1BL35
  {184, 130,  LOW, 35,  LOW,  LOW}, // 2BL35
  {177, 130,  LOW, 40,  LOW,  LOW}, // 3BL35
  {170, 130,  LOW, 45,  LOW,  LOW}, // 4BL35
  {163, 130,  LOW, 57,  LOW,  LOW}, // 5BL35
  {156, 130,  LOW, 60,  LOW,  LOW}, // 6BL35
  
  {239, 145, HIGH, 60,  LOW,  LOW}, // 6FL50
  {232, 145, HIGH, 57,  LOW,  LOW}, // 5FL50
  {225, 145, HIGH, 45,  LOW,  LOW}, // 4FL50
  {218, 145, HIGH, 40,  LOW,  LOW}, // 3FL50
  {211, 145, HIGH, 35,  LOW,  LOW}, // 2FL50
  {204, 145, HIGH, 30,  LOW,  LOW}, // 1FL50
  {197, 145, NULL,  0, HIGH, HIGH}, // 0HL50
  {190, 145,  LOW, 30,  LOW,  LOW}, // 1BL50
  {183, 145,  LOW, 35,  LOW,  LOW}, // 2BL50
  {176, 145,  LOW, 40,  LOW,  LOW}, // 3BL50
  {169, 145,  LOW, 45,  LOW,  LOW}, // 4BL50
  {162, 145,  LOW, 57,  LOW,  LOW}, // 5BL50
  {157, 145,  LOW, 60,  LOW,  LOW}, // 6BL50
};

void Driving_algorithm(int Var)
{
  int Var2 = 255 - Var;
  for(int i =0; i < DRIVE_SIZE; i++)
  {
    DriveControllData DriveControllDataItem = DriveControllDataTable[i];
    
    if(Var == DriveControllDataItem.Var || Var2 == DriveControllDataItem.Var)
    {
      myservo.write(DriveControllDataItem.Degree);
      digitalWrite(Motor_dir,DriveControllDataItem.Direction);
      analogWrite(Motor_pwm, DriveControllDataItem.MotorPWM);
      digitalWrite(Led1,DriveControllDataItem.LED1);
      digitalWrite(Led2,DriveControllDataItem.LED2);
    }
  }
}

#define PARK_SIZE 15

struct ParkControllData
{
  byte Var;
  byte Degree;
  byte Direction;
  byte MotorPWM;
  byte LED1;
  byte LED2;
};

ParkControllData ParkControllDataTable[PARK_SIZE] =
{
  {154,  45,  LOW, Parking_PWM,  LOW,  LOW},
  {153,  45, NULL, Parking_PWM, HIGH, HIGH},
  {152,  45, HIGH, Parking_PWM,  LOW,  LOW},
  
  {151,  70,  LOW, Parking_PWM,  LOW,  LOW},
  {150,  70, NULL, Parking_PWM, HIGH, HIGH},
  {149,  70, HIGH, Parking_PWM,  LOW,  LOW},
  
  {148,  95,  LOW, Parking_PWM,  LOW,  LOW},
  {147,  95, NULL, Parking_PWM, HIGH, HIGH},
  {146,  95, HIGH, Parking_PWM,  LOW,  LOW},
  
  {145, 120,  LOW, Parking_PWM,  LOW,  LOW},
  {144, 120, NULL, Parking_PWM, HIGH, HIGH},
  {143, 120, HIGH, Parking_PWM,  LOW,  LOW},
  
  {142, 145,  LOW, Parking_PWM,  LOW,  LOW},
  {141, 145, NULL, Parking_PWM, HIGH, HIGH},
  {140, 145, HIGH, Parking_PWM,  LOW,  LOW}
};

void Parking_algorithm(int Var)
{
  int Var2 = 255 - Var;
  for(int i =0; i < PARK_SIZE; i++)
  {
    ParkControllData ParkControllDataItem = ParkControllDataTable[i];
    
    if(Var == ParkControllDataItem.Var || Var2 == ParkControllDataItem.Var)
    {
      myservo.write(ParkControllDataItem.Degree);
      digitalWrite(Motor_dir,ParkControllDataItem.Direction);
      analogWrite(Motor_pwm, ParkControllDataItem.MotorPWM);
      digitalWrite(Led1,ParkControllDataItem.LED1);
      digitalWrite(Led2,ParkControllDataItem.LED2);
    }
  }
}

void loop(){
    for(int i = 0; i < 2; i++)
    {
      data[i] = Serial.read();
      delay(1);
    }
    if(data[0] + data[1] == 255)
    {
      Parking_state(data[0]);
      if(Parking_State == false)
        Driving_algorithm(data[0]);
      else if(Parking_State == true) 
      {
        Parking_PWM = Parking_pwm();
        Parking_algorithm(data[0]);
      }
    }
}
