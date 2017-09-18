
#include <SoftwareSerial.h>
#include <Button.h>

SoftwareSerial BTSerial(8, 9);

Button UP(2);    // execute the laser
Button RIGHT(3); // Searching the distance
Button DOWN(4);  // OFF: slow driving mode, ON: fast driving mode.
Button LEFT(5);  // Stop the Driving sequence
Button E_(6);    // Shutdown the system
Button F_(7);    // Reboot the system

int PIN_ANALOG_X = A0;
int PIN_ANALOG_Y = A1;

int LED_1 = 12;
int LED_2 = 13;

boolean STATE_L = true;
boolean STATE_D = true;
boolean old_STATE_L;
boolean old_STATE_D;
boolean Sending_state = false;

unsigned long interval = 500;
unsigned long previousMillis = 0;
int LED_State = HIGH;

int X;
int Y;

void setup(){
  BTSerial.begin(115200);

  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);

  pinMode(PIN_ANALOG_X, INPUT);
  pinMode(PIN_ANALOG_Y, INPUT);

  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_2, HIGH);
}

void loop(){
  Read_sock();
  if(Sending_state == true){
    Read_Data();
    delay(1);
    if(STATE_D == true)
      Send_Joystick_1(X, Y);
    else if(STATE_D == false)
      Send_Joystick_2(X, Y);
    delay(1);
    Send_Button();
    delay(1);
  }
  else
    Blinking()
}

void Read_Data(){
  X = analogRead(PIN_ANALOG_X);
  Y = analogRead(PIN_ANALOG_Y);
}

void Read_sock(){
  int Recv_data = BTSerial.read();
      
  if(Recv_data == 254)
    Sending_state = true;
  else if(Recv_data == 253)
    Sending_state = false; 
}

#define TABLE_SIZE_1 91

struct Joystick_Data1
{
  int Xmin;
  int Xmax;
  int Ymin;
  int Ymax;
  int Var1;
  int Var2;
};

Joystick_Data1 Joystick1_DataTable[TABLE_SIZE_1]=
{
  {880, 1025,    0,   70, 245, 10}, // 6BR50
  {740,  880,    0,   70, 244, 11}, // 6BR35
  {600,  740,    0,   70, 243, 12}, // 6BR15
  {440,  600,    0,   70, 242, 13}, // 6BS00
  {300,  440,    0,   70, 241, 14}, // 6BL15
  {160,  300,    0,   70, 240, 15}, // 6BL35
  {  0,  160,    0,   70, 239, 16}, // 6BL50

  {880, 1025,   70,  140, 238, 17}, // 5BR50
  {740,  880,   70,  140, 237, 18}, // 5BR35
  {600,  740,   70,  140, 236, 19}, // 5BR15
  {440,  600,   70,  140, 235, 20}, // 5BS00
  {300,  440,   70,  140, 234, 21}, // 5BL15
  {160,  300,   70,  140, 233, 22}, // 5BL35
  {  0,  160,   70,  140, 232, 23}, // 5BL50

  {880, 1025,  140,  210, 231, 24}, // 4BR50
  {740,  880,  140,  210, 230, 25}, // 4BR35
  {600,  740,  140,  210, 229, 26}, // 4BR15
  {440,  600,  140,  210, 228, 27}, // 4BS00
  {300,  440,  140,  210, 227, 28}, // 4BL15
  {160,  300,  140,  210, 226, 29}, // 4BL35
  {  0,  160,  140,  210, 225, 30}, // 4BL50
  
  {880, 1025,  210,  280, 224, 31}, // 3BR50
  {740,  880,  210,  280, 223, 32}, // 3BR35
  {600,  740,  210,  280, 222, 33}, // 3BR15
  {440,  600,  210,  280, 221, 34}, // 3BS00
  {300,  440,  210,  280, 220, 35}, // 3BL15
  {160,  300,  210,  280, 219, 36}, // 3BL35
  {  0,  160,  210,  280, 218, 37}, // 3BL50
  
  {880, 1025,  280,  350, 217, 38}, // 2BR50
  {740,  880,  280,  350, 216, 39}, // 2BR35
  {600,  740,  280,  350, 215, 40}, // 2BR15
  {440,  600,  280,  350, 214, 41}, // 2BS00
  {300,  440,  280,  350, 213, 42}, // 2BL15
  {160,  300,  280,  350, 212, 43}, // 2BL35
  {  0,  160,  280,  350, 211, 44}, // 2BL50
  
  {880, 1025,  350,  420, 210, 45},  // 1BR50
  {740,  880,  350,  420, 209, 46},  // 1BR35
  {600,  740,  350,  420, 208, 47},  // 1BR15
  {440,  600,  350,  420, 207, 48},  // 1BS00
  {300,  440,  350,  420, 206, 49},  // 1BL15
  {160,  300,  350,  420, 205, 50},  // 1BL35
  {  0,  160,  350,  420, 204, 51},  // 1BL50

  {880, 1025,  420,  605, 203, 52},  // 0HR50
  {740,  880,  420,  605, 202, 53},  // 0HR35
  {600,  740,  420,  605, 201, 54},  // 0HR15
  {440,  600,  420,  605, 200, 55},  // 0HS00
  {300,  440,  420,  605, 199, 56},  // 0HL15
  {160,  300,  420,  605, 198, 57},  // 0HL35
  {  0,  160,  420,  605, 197, 58},  // 0HL50
  
  {880, 1025,  605,  675, 196, 59},  // 1BR50
  {740,  880,  605,  675, 195, 60},  // 1BR35
  {600,  740,  605,  675, 194, 61},  // 1BR15
  {440,  600,  605,  675, 193, 62},  // 1BS00
  {300,  440,  605,  675, 192, 63},  // 1BL15
  {160,  300,  605,  675, 191, 64},  // 1BL35
  {  0,  160,  605,  675, 190, 65},  // 1BL50
   
  {880, 1025,  675,  745, 189, 66},  // 2BR50
  {740,  880,  675,  745, 188, 67},  // 2BR35
  {600,  740,  675,  745, 187, 68},  // 2BR15
  {440,  600,  675,  745, 186, 69},  // 2BS00
  {300,  440,  675,  745, 185, 70},  // 2BL15
  {160,  300,  675,  745, 184, 71},  // 2BL35
  {  0,  160,  675,  745, 183, 72},  // 2BL50
   
  {880, 1025,  745,  815, 182, 73},  // 3BR50
  {740,  880,  745,  815, 181, 74},  // 3BR35
  {600,  740,  745,  815, 180, 75},  // 3BR15
  {440,  600,  745,  815, 179, 76},  // 3BS00
  {300,  440,  745,  815, 178, 77},  // 3BL15
  {160,  300,  745,  815, 177, 78},  // 3BL35
  {  0,  160,  745,  815, 176, 79},  // 3BL50
  
  {880, 1025,  815,  885, 175, 80},  // 4BR50
  {740,  880,  815,  885, 174, 81},  // 4BR35
  {600,  740,  815,  885, 173, 82},  // 4BR15
  {440,  600,  815,  885, 172, 83},  // 4BS00
  {300,  440,  815,  885, 171, 84},  // 4BL15
  {160,  300,  815,  885, 170, 85},  // 4BL35
  {  0,  160,  815,  885, 169, 86},  // 4BL50
  
  {880, 1025,  885,  955, 168, 87},  // 5BR50
  {740,  880,  885,  955, 167, 88},  // 5BR35
  {600,  740,  885,  955, 166, 89},  // 5BR15
  {440,  600,  885,  955, 165, 91},  // 5BS00
  {300,  440,  885,  955, 164, 91},  // 5BL15
  {160,  300,  885,  955, 163, 92},  // 5BL35
  {  0,  160,  885,  955, 162, 93},  // 5BL50
  
  {880, 1025,  955, 1025, 161, 94},  // 6BR50
  {740,  880,  955, 1025, 160, 95},  // 6BR35
  {600,  740,  955, 1025, 159, 96},  // 6BR15
  {440,  600,  955, 1025, 158, 97},  // 6BS00
  {300,  440,  955, 1025, 157, 98},  // 6BL15
  {160,  300,  955, 1025, 156, 99},  // 6BL35
  {  0,  160,  955, 1025, 155,100}   // 6BL50
};

void Send_Joystick_1(int X, int Y){
  for(int i = 0; i < TABLE_SIZE_1; i++)
  {
    Joystick_Data1 Joystick1_DataItem = Joystick1_DataTable[i]; 
    if(Joystick1_DataItem.Xmin <= X && X < Joystick1_DataItem.Xmax && Joystick1_DataItem.Ymin <= Y && Y < Joystick1_DataItem.Ymax)
    {
      BTSerial.write(int(Joystick1_DataItem.Var1));
      BTSerial.write(int(Joystick1_DataItem.Var2));
    }
  }
}

#define TABLE_SIZE_2 9

struct Joystick_Data2
{
  int Xmin;
  int Xmax;
  int Ymin;
  int Ymax;
  int Var1;
  int Var2;
};

Joystick_Data2 Joystick2_DataTable[TABLE_SIZE_2]=
{
  {600, 1025, 605,  1025, 195, 60},  // 1BR35
  {440,  600, 605,  1025, 193, 62},  // 1BS00
  {  0,  440, 605,  1025, 191, 64},  // 1BL35

  {600, 1025, 420,  605, 202, 53},  // 0HR35
  {440,  600, 420,  605, 200, 55},  // 0HS00
  {  0,  440, 420,  605, 198, 57},  // 0HL35

  {600, 1025,   0,  420, 209, 46},  // 1FR35
  {440,  600,   0,  420, 207, 48},  // 1FS00
  {  0,  440,   0,  420, 205, 50}   // 1FL35
};

void Send_Joystick_2(int X, int Y){
  for(int i = 0; i < TABLE_SIZE_2; i++)
  {
    Joystick_Data2 Joystick2_DataItem = Joystick2_DataTable[i];
    if(Joystick2_DataItem.Xmin <= X && X < Joystick2_DataItem.Xmax && Joystick2_DataItem.Ymin <= Y && Y < Joystick2_DataItem.Ymax)
    {
      BTSerial.write(int(Joystick2_DataItem.Var1));
      BTSerial.write(int(Joystick2_DataItem.Var2));
    }
  }
}

void Send_Button(){
  old_STATE_D = STATE_D;
  old_STATE_L = STATE_L;

  if(LEFT.pressed())
    STATE_L = !STATE_L;
  else if(DOWN.pressed())
    STATE_D = !STATE_D;
  else if(F_.pressed()){
    BTSerial.write(120);
    BTSerial.write(135);
  }
  else if(E_.pressed()){
    BTSerial.write(121);
    BTSerial.write(134);
  }
  else if(UP.pressed()){
    BTSerial.write(122);
    BTSerial.write(133);
  }
  else if(RIGHT.pressed()){
    BTSerial.write(123);
    BTSerial.write(132);
  }
  
  if(old_STATE_L != STATE_L && STATE_L == true ){
    BTSerial.write(116);
    BTSerial.write(139);
    delay(10);
  }
  else if(old_STATE_L != STATE_L && STATE_L == false){
    BTSerial.write(117);
    BTSerial.write(138);
    delay(10);
  }
  if(old_STATE_D != STATE_D && STATE_D == true ){
    BTSerial.write(118);
    BTSerial.write(137);
    delay(10);
  }
  else if(old_STATE_D != STATE_D && STATE_D == false){
    BTSerial.write(119);
    BTSerial.write(136);
    delay(10);
  }

  if(STATE_L == true)
    digitalWrite(LED_2,HIGH);
  else if(STATE_L == false)
    digitalWrite(LED_2,LOW);
  if(STATE_D == true)
    digitalWrite(LED_1,HIGH);
  else if(STATE_D == false)
    digitalWrite(LED_1, LOW);
}

void Blinking(){
  unsigned long currentMillis = millis();
    if(currentMillis - previousMillis >= interval){
      previousMillis = currentMillis;
      if(LED_State == LOW)
        LED_State = HIGH;
      else
        LED_State = LOW;
        
      digitalWrite(LED_1, LED_State);
      digitalWrite(LED_2, LED_State);
    }
}
