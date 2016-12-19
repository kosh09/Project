
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(4, 5); // RX, TX


const int PIN = 3;  // 3번핀은 오른쪽과 동시에 되므로 오른쪽 키를 사용하지 말
const int PIN_BUTTON_UP = 2;
const int PIN_BUTTON_LEFT = 5;
const int PIN_ANALOG_X = 0;
const int PIN_ANALOG_Y = 1;

int button[] = {2,5};

void serialEvent(){
  // digitalWrite(?, 13);   시리얼통신이 연결이 되면 불이 켜져있게 LED를 하나 연결하자 
} // serialEvent() 함수같은 경우에는 시리얼 통신이 시작되면 자동으로 호출이 된다.
  // 우리가 정의를 하지 않아도 무조건 호출은 됩니다.

void setup() 
{
  Serial.begin(57600);
  BTSerial.begin(9600);
  
  for(int i = 0; i < 2; i++){pinMode(button[i], INPUT_PULLUP);}
}


void loop()
{
  const int UP = digitalRead(PIN_BUTTON_UP);
  const int LEFT = digitalRead(PIN_BUTTON_LEFT);
  const int X = analogRead(PIN_ANALOG_X);
  const int Y = analogRead(PIN_ANALOG_Y);

/*##############################################################################*/
/*############################# 좌/우를 선택하는 부분 #############################*/
/*##############################################################################*/
  if(BTSerial.read() == "a"){
    if(Serial.available())
    {if(Serial.find("OKAY")){
        // 부저울려라
        delay(3000);}}
    if(UP == LOW){
      Serial.println("MODE");
      BTSerial.write("MODE");}
    else if(0 <= X && X < 134 && 583 <= Y && Y < 1025){
      Serial.println("FL30 ");
      BTSerial.write("FL30");}
    else if(134 <= X && X < 198 && 583 <= Y && Y < 1025){
      Serial.println("FL25 ");
      BTSerial.write("FL25");}
    else if(198 <= X && X < 262 && 583 <= Y && Y < 1025){
      Serial.println("FL20 ");
      BTSerial.write("FL20");}
    else if(262 <= X && X < 326 && 583 <= Y && Y < 1025){
      Serial.println("FL15");
      BTSerial.write("FL15");}
    else if(326 <= X && X < 390 && 583 <= Y && Y < 1025){
      Serial.println("FL10 ");
      BTSerial.write("FL10");}
    else if(390 <= X && X < 454 && 583 <= Y && Y < 1025){
      Serial.println("FL05 ");
      BTSerial.write("FL05");}
    else if(454 <= X && X < 554 && 583 <= Y && Y < 1025){
      Serial.println("FS00");
      BTSerial.write("FS00)");}
    else if(554 <= X && X < 632 && 583 <= Y && Y < 1025){
      Serial.println("FR05");
      BTSerial.write("FR05");}
    else if(632 <= X && X < 710 && 583 <= Y && Y < 1025){
      Serial.println("FR10 ");
      BTSerial.write("FR10");}
    else if(710 <= X && X < 788 && 583 <= Y && Y < 1025){
      Serial.println("FR15");
      BTSerial.write("FR15");}
    else if(788 <= X && X < 866 && 583 <= Y && Y < 1025){
      Serial.println("FR20");
      BTSerial.write("FR20");}
    else if(866 <= X && X < 944 && 583 <= Y && Y < 1025){
      Serial.println("FR25");
      BTSerial.write("FR25");}
    else if(944 <= X && X < 1025 && 583 <= Y && Y < 1025){
      Serial.println("FR30");
      BTSerial.write("FR30");}
  
  
    else if(0 <= X && X < 134 && 473 <= Y && Y < 583){
      Serial.println("HL30 ");
      BTSerial.write("HL30");}
    else if(134 <= X && X < 198 && 473 <= Y && Y < 583){
      Serial.println("HL25 ");
      BTSerial.write("HL25");}
    else if(198 <= X && X < 262 && 473 <= Y && Y < 583){
      Serial.println("HL20 ");
      BTSerial.write("HL20");}
    else if(262 <= X && X < 326 && 473 <= Y && Y < 583){
      Serial.println("HL15");
      BTSerial.write("HL15");}
    else if(326 <= X && X < 390 && 473 <= Y && Y < 583){
      Serial.println("HL10 ");
      BTSerial.write("HL10");}
    else if(390 <= X && X < 454 && 473 <= Y && Y < 583){
      Serial.println("HL05 ");
      BTSerial.write("HL05");}
    else if(454 <= X && X < 554 && 473 <= Y && Y < 583){
      Serial.println("HS00");
      BTSerial.write("HS00");}
    else if(554 <= X && X < 632 && 473 <= Y && Y < 583){
      Serial.println("HR05 ");
      BTSerial.write("HR05");}
    else if(632 <= X && X < 710 && 473 <= Y && Y < 583){
      Serial.println("HR10 ");
      BTSerial.write("HR10");}
    else if(710 <= X && X < 788 && 473 <= Y && Y < 583){
      Serial.println("HR15");
      BTSerial.write("HR15");}
    else if(788 <= X && X < 866 && 473 <= Y && Y < 583){
      Serial.println("HR20");
      BTSerial.write("HR20");}
    else if(866 <= X && X < 944 && 473 <= Y && Y < 583){
      Serial.println("HR25");
      BTSerial.write("HR25");}
    else if(944 <= X && X < 1025 && 473 <= Y && Y < 583){
      Serial.println("HR30");
      BTSerial.write("HR30");}
  
    else if(0 <= X && X < 134 && 0 <= Y && Y < 473){
      Serial.println("BL30");
      BTSerial.write("BL30");}
    else if(134 <= X && X < 198 && 0 <= Y && Y < 473){
      Serial.println("BL25");
      BTSerial.write("BL25");}
    else if(198 <= X && X < 262 && 0 <= Y && Y < 473){
      Serial.println("BL20");
      BTSerial.write("BL20");}
    else if(262 <= X && X < 326 && 0 <= Y && Y < 473){
      Serial.println("BL15");
      BTSerial.write("BL15");}
    else if(326 <= X && X < 390 && 0 <= Y && Y < 473){
      Serial.println("BL10");
      BTSerial.write("BL10");}
    else if(390 <= X && X < 454 && 0 <= Y && Y < 473){
      Serial.println("BL05");
      BTSerial.write("BL05");}
    else if(454 <= X && X < 554 && 0 <= Y && Y < 473){
      Serial.println("BS00");
      BTSerial.write("BS00");}
    else if(554 <= X && X < 632 && 0 <= Y && Y < 473){
      Serial.println("BR05 ");
      BTSerial.write("BR05");}
    else if(632 <= X && X < 710 && 0 <= Y && Y < 473){
      Serial.println("BR10 ");
      BTSerial.write("BR10");}
    else if(710 <= X && X < 788 && 0 <= Y && Y < 473){
      Serial.println("BR15");
      BTSerial.write("BR15");}
    else if(788 <= X && X < 866 && 0 <= Y && Y < 473){
      Serial.println("BR20");
      BTSerial.write("BR20");}
    else if(866 <= X && X < 944 && 0 <= Y && Y < 473){
      Serial.println("BR25");
      BTSerial.write("BR25");}
    else if(944 <= X && X < 1025 && 0 <= Y && Y < 473){
      Serial.println("BR30");
      BTSerial.write("BR30");}
  }
}
