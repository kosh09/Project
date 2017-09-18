
#include <Servo.h>

Servo myservo;

const byte Led1 = 4;
const byte Led2 = 5;
const byte ServoPin =  6;
const byte Motor_pwm = 11;
const byte Motor_dir = 12;

int data[2];

boolean Parking_State = false;

float PWM = 0.0;
float *pointerPWM;
int value;
float VOUT;
float vout = 0.0;
float vin = 0.0;
float R1 = 100000.0;
float R2 = 10000.0;

/********************************************************************************************************************/

void setup()
{
  Serial.begin(57600);
  myservo.attach(ServoPin);

  pinMode(A0, INPUT);
  pinMode(Motor_dir, OUTPUT);
  pinMode(Motor_pwm, OUTPUT);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  digitalWrite(Led1,HIGH);
  digitalWrite(Led2,HIGH);

  myservo.write(96);
  analogWrite(Motor_pwm,0);
  Serial.flush();
  pointerPWM = &PWM;
}

/*******************************************************************************************************************************/

void loop(){
  for(int i = 0; i < 2; i++){
    data[i] = Serial.read();
    delay(3);
  }
  PWM = Parking_pwm();
  if(data[0] + data[1] ==255){
    Choose_Parking_State(data[0]);
    if(Parking_State == false)
      Driving_algorithm(data[0]);
    else if(Parking_State == true)
      Parking_algorithm(data[0]);
  }
}

/********************************************************************************************************************/

void Choose_Parking_State(int Var){
  if(Var == 251 || Var == 4)
    Parking_State = false;
  else if(Var == 250 || Var == 5)
    Parking_State = true;
}

struct CarControlData_1
{
  int Var;
  byte Degree;
  byte Direction;
  float MotorPWM;
  byte LED1;
  byte LED2;
};

#define DRIVE_SIZE 91

CarControlData_1 DriveControlDataTable[DRIVE_SIZE] =
{
  {245,  51, HIGH, 30,  LOW,  LOW}, // 6FR50
  {238,  51, HIGH, 25,  LOW,  LOW}, // 5FR50
  {231,  51, HIGH, 20,  LOW,  LOW}, // 4FR50
  {224,  51, HIGH, 15,  LOW,  LOW}, // 3FR50
  {217,  51, HIGH, 10,  LOW,  LOW}, // 2FR50
  {210,  51, HIGH,  5,  LOW,  LOW}, // 1FR50
  {203,  51, NULL,-42, HIGH, HIGH}, // 0HR50
  {196,  51,  LOW,  5,  LOW,  LOW}, // 1BR50
  {189,  51,  LOW, 10,  LOW,  LOW}, // 2BR50
  {182,  51,  LOW, 15,  LOW,  LOW}, // 3BR50
  {175,  51,  LOW, 20,  LOW,  LOW}, // 4BR50
  {168,  51,  LOW, 25,  LOW,  LOW}, // 5BR50
  {161,  51,  LOW, 30,  LOW,  LOW}, // 6BR50

  {244,  66, HIGH, 30,  LOW,  LOW}, // 6FR35
  {237,  66, HIGH, 25,  LOW,  LOW}, // 5FR35
  {230,  66, HIGH, 20,  LOW,  LOW}, // 4FR35
  {223,  66, HIGH, 15,  LOW,  LOW}, // 3FR35
  {216,  66, HIGH, 10,  LOW,  LOW}, // 2FR35
  {209,  66, HIGH,  5,  LOW,  LOW}, // 1FR35
  {202,  66, NULL,-42, HIGH, HIGH}, // 0HR35
  {195,  66,  LOW,  5,  LOW,  LOW}, // 1BR35
  {188,  66,  LOW, 10,  LOW,  LOW}, // 2BR35
  {181,  66,  LOW, 15,  LOW,  LOW}, // 3BR35
  {174,  66,  LOW, 20,  LOW,  LOW}, // 4BR35
  {167,  66,  LOW, 25,  LOW,  LOW}, // 5BR35
  {160,  66,  LOW, 30,  LOW,  LOW}, // 6BR35

  {243,  81, HIGH, 30,  LOW,  LOW}, // 6FR15
  {236,  81, HIGH, 25,  LOW,  LOW}, // 5FR15
  {229,  81, HIGH, 20,  LOW,  LOW}, // 4FR15
  {222,  81, HIGH, 15,  LOW,  LOW}, // 3FR15
  {215,  81, HIGH, 10,  LOW,  LOW}, // 2FR15
  {208,  81, HIGH,  5,  LOW,  LOW}, // 1FR15
  {201,  81, NULL,-42, HIGH, HIGH}, // 0HR15
  {194,  81,  LOW,  5,  LOW,  LOW}, // 1BR15
  {187,  81,  LOW, 10,  LOW,  LOW}, // 2BR15
  {180,  81,  LOW, 15,  LOW,  LOW}, // 3BR15
  {173,  81,  LOW, 20,  LOW,  LOW}, // 4BR15
  {166,  81,  LOW, 25,  LOW,  LOW}, // 5BR15
  {159,  81,  LOW, 30,  LOW,  LOW}, // 6BR15

  {242,  96, HIGH, 30,  LOW,  LOW}, // 6FS00
  {235,  96, HIGH, 25,  LOW,  LOW}, // 5FS00
  {228,  96, HIGH, 20,  LOW,  LOW}, // 4FS00
  {221,  96, HIGH, 15,  LOW,  LOW}, // 3FS00
  {214,  96, HIGH, 10,  LOW,  LOW}, // 2FS00
  {207,  96, HIGH,  5,  LOW,  LOW}, // 1FS00
  {200,  96, NULL,-42, HIGH, HIGH}, // 0HS00
  {193,  96,  LOW,  5,  LOW,  LOW}, // 1BS00
  {186,  96,  LOW, 10,  LOW,  LOW}, // 2BS00
  {179,  96,  LOW, 15,  LOW,  LOW}, // 3BS00
  {172,  96,  LOW, 20,  LOW,  LOW}, // 4BS00
  {165,  96,  LOW, 25,  LOW,  LOW}, // 5BS00
  {158,  96,  LOW, 30,  LOW,  LOW}, // 6BS00

  {241, 111, HIGH, 30,  LOW,  LOW}, // 6FL15
  {234, 111, HIGH, 25,  LOW,  LOW}, // 5FL15
  {227, 111, HIGH, 20,  LOW,  LOW}, // 4FL15
  {220, 111, HIGH, 15,  LOW,  LOW}, // 3FL15
  {213, 111, HIGH, 10,  LOW,  LOW}, // 2FL15
  {206, 111, HIGH,  5,  LOW,  LOW}, // 1FL15
  {199, 111, NULL,-42, HIGH, HIGH}, // 0HF15
  {192, 111,  LOW,  5,  LOW,  LOW}, // 1BL15
  {185, 111,  LOW, 10,  LOW,  LOW}, // 2BL15
  {178, 111,  LOW, 15,  LOW,  LOW}, // 3BL15
  {171, 111,  LOW, 20,  LOW,  LOW}, // 4BL15
  {164, 111,  LOW, 25,  LOW,  LOW}, // 5BL15
  {157, 111,  LOW, 30,  LOW,  LOW}, // 6BL15

  {240, 126, HIGH, 30,  LOW,  LOW}, // 6FL35
  {233, 126, HIGH, 25,  LOW,  LOW}, // 5FL35
  {226, 126, HIGH, 20,  LOW,  LOW}, // 4FL35
  {219, 126, HIGH, 15,  LOW,  LOW}, // 3FL35
  {212, 126, HIGH, 10,  LOW,  LOW}, // 2FL35
  {205, 126, HIGH,  5,  LOW,  LOW}, // 1FL35
  {198, 126, NULL,-42, HIGH, HIGH}, // 0HL35
  {191, 126,  LOW,  5,  LOW,  LOW}, // 1BL35
  {184, 126,  LOW, 10,  LOW,  LOW}, // 2BL35
  {177, 126,  LOW, 15,  LOW,  LOW}, // 3BL35
  {170, 126,  LOW, 20,  LOW,  LOW}, // 4BL35
  {163, 126,  LOW, 25,  LOW,  LOW}, // 5BL35
  {156, 126,  LOW, 30,  LOW,  LOW}, // 6BL35

  {239, 141, HIGH, 30,  LOW,  LOW}, // 6FL50
  {232, 141, HIGH, 25,  LOW,  LOW}, // 5FL50
  {225, 141, HIGH, 20,  LOW,  LOW}, // 4FL50
  {218, 141, HIGH, 15,  LOW,  LOW}, // 3FL50
  {211, 141, HIGH, 10,  LOW,  LOW}, // 2FL50
  {204, 141, HIGH,  5,  LOW,  LOW}, // 1FL50
  {197, 141, NULL,-42, HIGH, HIGH}, // 0HL50
  {190, 141,  LOW,  5,  LOW,  LOW}, // 1BL50
  {183, 141,  LOW, 10,  LOW,  LOW}, // 2BL50
  {176, 141,  LOW, 15,  LOW,  LOW}, // 3BL50
  {169, 141,  LOW, 20,  LOW,  LOW}, // 4BL50
  {162, 141,  LOW, 25,  LOW,  LOW}, // 5BL50
  {155, 141,  LOW, 30,  LOW,  LOW}, // 6BL50
};

void Driving_algorithm(int Var)
{
  int Var2 = 255 - Var;
  for(int i =0; i < DRIVE_SIZE; i++)
  {
    CarControlData_1 DriveControlDataItem = DriveControlDataTable[i];

    if(Var == DriveControlDataItem.Var || Var2 == DriveControlDataItem.Var)
    {
      if(DriveControlDataItem.MotorPWM + (*pointerPWM) <= 0)
      {
        myservo.write(DriveControlDataItem.Degree);
        digitalWrite(Motor_dir,DriveControlDataItem.Direction);
        analogWrite(Motor_pwm, 0);
        digitalWrite(Led1,DriveControlDataItem.LED1);
        digitalWrite(Led2,DriveControlDataItem.LED2);
      }
      else
      {
        myservo.write(DriveControlDataItem.Degree);
        digitalWrite(Motor_dir,DriveControlDataItem.Direction);
        analogWrite(Motor_pwm, DriveControlDataItem.MotorPWM + (*pointerPWM));
        digitalWrite(Led1,DriveControlDataItem.LED1);
        digitalWrite(Led2,DriveControlDataItem.LED2);
      }
    }
  }
}

/********************************************************************************************************************/

struct CarControlData_2
{
  int Var;
  byte Degree;
  byte Direction;
  float MotorPWM;
  byte LED1;
  byte LED2;
};

#define PARK_SIZE 25

CarControlData_1 ParkControlDataTable[PARK_SIZE] =
{
  {154,  51,  LOW,   0,  LOW,  LOW},  // FR50
  {153,  51, NULL, -42, HIGH, HIGH},  // HR50
  {152,  51, HIGH,   0,  LOW,  LOW},  // BR50

  {151,  76,  LOW,   0,  LOW,  LOW},  // FR25
  {150,  76, NULL, -42, HIGH, HIGH},  // HR25
  {149,  76, HIGH,   0,  LOW,  LOW},  // BR25

  {148,  96,  LOW,   0,  LOW,  LOW},  // FS00
  {147,  96, NULL, -42, HIGH, HIGH},  // HS00
  {146,  96, HIGH,   0,  LOW,  LOW},  // BS00

  {145, 116,  LOW,   0,  LOW,  LOW},  // FL25
  {144, 116, NULL, -42, HIGH, HIGH},  // HL25
  {143, 116, HIGH,   0,  LOW,  LOW},  // BL25

  {142, 141,  LOW,   0,  LOW,  LOW},  // FL50
  {141, 141, NULL, -42, HIGH, HIGH},  // HL50
  {140, 141, HIGH,   0,  LOW,  LOW},   // BL50

  {155,  51,  LOW,  15,  LOW,  LOW},  // FFR50
  {156,  51, HIGH,  15,  LOW,  LOW},  // BBR50

  {157,  76,  LOW,  15,  LOW,  LOW},  // FFR25
  {158,  76, HIGH,  15,  LOW,  LOW},  // BBR25

  {159,  96,  LOW,  15,  LOW,  LOW},  // FFS00
  {160,  96, HIGH,  15,  LOW,  LOW},  // BBS00

  {161, 116,  LOW,  15,  LOW,  LOW},  // FFL25
  {162, 116, HIGH,  15,  LOW,  LOW},  // BBL25

  {163, 141,  LOW,  15,  LOW,  LOW},  // FFL50
  {164, 141, HIGH,  15,  LOW,  LOW}   // BBL50
};

void Parking_algorithm(int Var)
{
  int Var2 = 255 - Var;
  for(int i =0; i < PARK_SIZE; i++)
  {
    CarControlData_1 ParkControlDataItem = ParkControlDataTable[i];

    if(Var == ParkControlDataItem.Var || Var2 == ParkControlDataItem.Var)
    {
      if(ParkControlDataItem.MotorPWM + (*pointerPWM) <= 0)
      {
        myservo.write(ParkControlDataItem.Degree);
        digitalWrite(Motor_dir,ParkControlDataItem.Direction);
        analogWrite(Motor_pwm, 0);
        digitalWrite(Led1,ParkControlDataItem.LED1);
        digitalWrite(Led2,ParkControlDataItem.LED2);
      }
      else
      {
        myservo.write(ParkControlDataItem.Degree);
        digitalWrite(Motor_dir,ParkControlDataItem.Direction);
        analogWrite(Motor_pwm, ParkControlDataItem.MotorPWM+(*pointerPWM));
        digitalWrite(Led1,ParkControlDataItem.LED1);
        digitalWrite(Led2,ParkControlDataItem.LED2);
      }
    }
  }
}

/********************************************************************************************************************/

float Parking_pwm()
{
  value = analogRead(A0);
  vout = (value * 5.0) / 1024.0;
  vin = vout / (R2/(R1+R2));
  float voltage = (38/255.0) * 12.00;
  float pwm = (voltage * 255.0) / vin;
  return pwm;
}
