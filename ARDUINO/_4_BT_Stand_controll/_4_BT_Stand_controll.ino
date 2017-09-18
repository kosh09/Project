
#include <SoftwareSerial.h>
#include<util/delay.h>

#define RX_PIN 4
#define TX_PIN 5
#define RELAY 6
#define SWITCH 9
#define DELAY 230

SoftwareSerial BT(RX_PIN, TX_PIN);
int BT_Data; 

void setup(){
  BT.begin(9600);
  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, LOW);
  pinMode(SWITCH, INPUT_PULLUP);
}

void loop(){

  if (BT.available()){
    BT_Data = BT.read();
    if (BT_Data == '1'){digitalWrite(RELAY, HIGH);}
    if (BT_Data == '2'){digitalWrite(RELAY, LOW);}}

  _delay_ms(DELAY); // 디바운싱을 위해서 해준다
  if (digitalRead(SWITCH) == LOW){digitalWrite(RELAY, !digitalRead(RELAY));}

  delay(10);
}

