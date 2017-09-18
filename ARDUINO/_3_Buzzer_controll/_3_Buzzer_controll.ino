const int Front_echo = 4;
const int LED1 = 5;
const int Front_trig = 7;
const int Back_echo = 8;
const int Back_trig = 9;
const int Buzz = 6;
float Front_Distance;
float Back_Distance;
boolean state = false;
int data[2];

int ledState = HIGH;
unsigned long previousMillis = 0;
const long interval = 500;

void setup(){
  Serial.begin(57600);
  pinMode(LED1, OUTPUT);
  pinMode(Back_echo, INPUT);
  pinMode(Back_trig, OUTPUT);
  pinMode(Front_echo, INPUT);
  pinMode(Front_trig, OUTPUT);
  pinMode(Buzz, OUTPUT);
  Serial.flush();
}

void loop() {
  Change_state();
  Back_Distance = Back_Ultra();
  if(state == true){Buzzer(Back_Distance); Blinking();Serial.write(int(Back_Distance));}
  else if(state == false){digitalWrite(LED1,HIGH);}
}
float Back_Ultra(){
  float duration, distance;
  digitalWrite(Back_trig, HIGH);
  delay(10);
  digitalWrite(Back_trig, LOW);
  duration = pulseIn(Back_echo, HIGH);
  distance = ((float)(340 * duration) / 10000) / 2;
  return distance;
}
float Front_Ultra(){
  float duration, distance;
  digitalWrite(Front_trig, HIGH);
  delay(10);
  digitalWrite(Front_trig, LOW);
  duration = pulseIn(Front_echo, HIGH);
  distance = ((float)(340 * duration) / 10000) / 2;
  return distance;
}
void Change_state() {
  for(int i = 0; i < 2; i++){data[i] = Serial.read();}
  if(data[0] + data[1] == 135){
    if(data[0] == 50 || data[0] == 85){state = true;}
    else if(data[0] == 51 || data[0] == 84){state = false;}
    else if(data[0] == 52 || data[0] == 83){Serial.write((int)Front_Distance);}
    else if(data[0] == 53 || data[0] == 82){Serial.write((int)Back_Distance);}}
}
void Buzzer(float A) {
  if(1 < A && A < 20){
    analogWrite(Buzz, 80);
    delay((A/20)*100);
    analogWrite(Buzz, 0);
    delay((A/20)*100);}
}
void Blinking() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if (ledState == HIGH) {ledState = LOW;}
    else {ledState = HIGH;}
    digitalWrite(LED1, ledState);}
}
