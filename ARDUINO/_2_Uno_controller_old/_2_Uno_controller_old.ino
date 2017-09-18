
//---------------------------------------------------------------- HEADER Declare
#include <SoftwareSerial.h>

//---------------------------------------------------------------- BLUETOOTH Declare
SoftwareSerial BTSerial(2, 3); // RX, TX

//---------------------------------------------------------------- PIN Declare
int PIN_ANALOG_X = 0;
int PIN_ANALOG_Y = 1;
int PIN_BUTTON_DOWN = 4;
int PIN_BUTTON_LEFT = 5;

int LED = 13;
boolean STATE_L = true;
boolean STATE_D = false;

int DOWN;
int LEFT;
int X;
int Y;

//---------------------------------------------------------------- Initialisation( same baudrate as python script)
void setup() 
{
  //Serial.begin(9600);
  BTSerial.begin(57600);

  //-------------------------------------------------------------- PINMODE Setting
  pinMode(PIN_BUTTON_LEFT, INPUT_PULLUP);
  pinMode(PIN_BUTTON_DOWN, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  digitalWrite(LED,HIGH);
}
  

void loop()
{  
  Read_Data();
  Send_Joystick(X,Y);
  Send_Button();
  delay(20);
}

//---------------------------------------------------------------- FUNCTION Declare

//---------------------------------------------------------------- Read the analog and digital value that I want
void Read_Data()
{
  X = analogRead(PIN_ANALOG_X);
  Y = analogRead(PIN_ANALOG_Y);
}

//---------------------------------------------------------------- Show the value of Joystick analogvalue and etc
/*void write_Data()
{
  Serial.print("LEFT: ");
  Serial.print(LEFT);

  Serial.print(" X: ");
  Serial.print(X);

  Serial.print(" Y");
  Serial.print(Y);

  Serial.print(" STATE: ");
  Serial.print(STATE);
  Serial.println();
}*/

//---------------------------------------------------------------- Show what will be sent via Bluetooth (shows in Serial monitor)
/*
void What_will_send(int X, int Y)
{  
    if(800 <= X && X < 1023 && 700 <= Y && Y < 1025){Serial.println("FR30");}
    else if(600 <= X && X < 800 && 700 <= Y && Y < 1025){Serial.println("FR15");}
    else if(400 <= X && X < 600 && 700 <= Y && Y < 1025){Serial.println("FS00");}
    else if(200 <= X && X < 400 && 700 <= Y && Y < 1025){Serial.println("FL15");}
    else if(0 <= X && X < 200 && 700 <= Y && Y < 1025){  Serial.println("FL30");}

    else if(800 <= X && X < 1025 && 300 <= Y && Y < 700){Serial.println("HR30");}
    else if(600 <= X && X < 800 && 300 <= Y && Y < 700){Serial.println("HR15");}
    else if(400 <= X && X < 600 && 300 <= Y && Y < 700){Serial.println("HS00");}
    else if(200 <= X && X < 400 && 300 <= Y && Y < 700){Serial.println("HL15");}        
    else if(0 <= X && X < 200 && 300 <= Y && Y < 700){  Serial.println("HL30");}

    else if(800 <= X && X < 1025 && 0 <= Y && Y < 300){Serial.println("BR30");}
    else if(600 <= X && X < 800 && 0 <= Y && Y < 300){Serial.println("BR15");}
    else if(400 <= X && X < 600 && 0 <= Y && Y < 300){Serial.println("BS00");}
    else if(200 <= X && X < 400 && 0 <= Y && Y < 300){Serial.println("BL15");}
    else if(0 <= X && X < 200 && 0 <= Y && Y < 300){  Serial.println("BL30");}
}
*/
//---------------------------------------------------------------- Send data to main board via Bluetooth
void Send_Joystick(int X, int Y)
{

      if(800 <= X && X < 1023 && 700 <= Y && Y < 1025){ BTSerial.write(10);}
  else if(600 <= X && X < 800 && 700 <= Y && Y < 1025){ BTSerial.write(11);}
  else if(400 <= X && X < 600 && 700 <= Y && Y < 1025){ BTSerial.write(12);}
  else if(200 <= X && X < 400 && 700 <= Y && Y < 1025){ BTSerial.write(13);}
  else if(0 <= X && X < 200 && 700 <= Y && Y < 1025){   BTSerial.write(14);}

  else if(800 <= X && X < 1025 && 300 <= Y && Y < 700){ BTSerial.write(15);}
  else if(600 <= X && X < 800 && 300 <= Y && Y < 700){  BTSerial.write(16);}
  else if(400 <= X && X < 600 && 300 <= Y && Y < 700){  BTSerial.write(17);}
  else if(200 <= X && X < 400 && 300 <= Y && Y < 700){  BTSerial.write(18);}        
  else if(0 <= X && X < 200 && 300 <= Y && Y < 700){    BTSerial.write(19);}

  else if(800 <= X && X < 1025 && 0 <= Y && Y < 300){   BTSerial.write(20);}
  else if(600 <= X && X < 800 && 0 <= Y && Y < 300){    BTSerial.write(21);}
  else if(400 <= X && X < 600 && 0 <= Y && Y < 300){    BTSerial.write(22);}
  else if(200 <= X && X < 400 && 0 <= Y && Y < 300){    BTSerial.write(23);}
  else if(0 <= X && X < 200 && 0 <= Y && Y < 300){      BTSerial.write(24);}

} 

//---------------------------------------------------------------- Change STATE and light when click LEFT button
void Send_Button()
{ 
  LEFT = digitalRead(PIN_BUTTON_LEFT);
  DOWN = digitalRead(PIN_BUTTON_DOWN);
  
  if(LEFT == 0)
  {
    STATE_L = !STATE_L;
    if(STATE_L == true){ digitalWrite(LED, HIGH); BTSerial.write(25);}
    if(STATE_L == false){digitalWrite(LED, LOW);  BTSerial.write(26);}
  }
  
  if(DOWN == 0)
  {
    STATE_D = !STATE_D;
    if(STATE_D == true){BTSerial.write(27);}
    if(STATE_D == false){BTSerial.write(28);}
  }
}



