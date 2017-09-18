
#include <CurieBLE.h>

BLEPeripheral blePeripheral;
BLEService heartRateService("180D");
BLECharacteristic heartRateChar("2A37" ,BLERead | BLENotify, 2);  
    
int heartRate = 0;
int oldHeartRate = 0;
long previousMillis = 0;

int PIN = 3;
int PIN_BUTTON_UP = 2;
int PIN_BUTTON_LEFT = 5;
int PIN_ANALOG_X = 0;
int PIN_ANALOG_Y = 1;
int button[] = {2,5};

int *pX;
int *pY;


void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);

  blePeripheral.setLocalName("Seok_hyun");
  blePeripheral.setAdvertisedServiceUuid(heartRateService.uuid());
  blePeripheral.addAttribute(heartRateService);
  blePeripheral.addAttribute(heartRateChar);
  blePeripheral.begin();
  Serial.println("Bluetooth device active, waiting for connections...");

  for(int i = 0; i < 2; i++){pinMode(button[i], INPUT_PULLUP);}
}

void loop() {
  int UP = digitalRead(PIN_BUTTON_UP);
  int LEFT = digitalRead(PIN_BUTTON_LEFT);
  int X = analogRead(PIN_ANALOG_X);
  int Y = analogRead(PIN_ANALOG_Y);

  pX = &X;
  pY = &Y;
  
  BLECentral central = blePeripheral.central();
  if(central)
  {
    Serial.print("Connected to central: ");
    Serial.println(central.address());
    digitalWrite(13, HIGH);

    while (central.connected())
    {
      long currentMillis = millis();
      if (currentMillis - previousMillis >= 50)
      {
        previousMillis = currentMillis;
        updateHeartRate();
      }
    }
    digitalWrite(13, LOW);
    Serial.print("Disconnected from central: ");
    Serial.println(central.address());
  }
}

void updateHeartRate() {
    heartRate = controller(*pX,*pY);
    if(heartRate != oldHeartRate) 
    {
      Serial.print("Heart Rate is now: ");
      Serial.println(heartRate);
      const unsigned char heartRateCharArray[2] = { 0, (char)heartRate };
      heartRateChar.setValue(heartRateCharArray, 2);
      oldHeartRate = heartRate;
    }
}

int controller(int X, int Y)
  {
    int _data;
    if(0 <= X && X < 134 && 583 <= Y && Y < 1025){_data = 10;}         // FL30
    else if(134 <= X && X < 198 && 583 <= Y && Y < 1025){_data = 11;}  // FL25
    else if(198 <= X && X < 262 && 583 <= Y && Y < 1025){_data = 12;}  // FL20
    else if(262 <= X && X < 326 && 583 <= Y && Y < 1025){_data = 13;}  // FL15 
    else if(326 <= X && X < 390 && 583 <= Y && Y < 1025){_data = 14;}  // FL10
    else if(390 <= X && X < 454 && 583 <= Y && Y < 1025){_data = 15;}  // FL05
    else if(454 <= X && X < 554 && 583 <= Y && Y < 1025){_data = 16;}  // FS00
    else if(554 <= X && X < 632 && 583 <= Y && Y < 1025){_data = 17;}  // FR05
    else if(632 <= X && X < 710 && 583 <= Y && Y < 1025){_data = 18;}  // FR10
    else if(710 <= X && X < 788 && 583 <= Y && Y < 1025){_data = 19;}  // FR15
    else if(788 <= X && X < 866 && 583 <= Y && Y < 1025){_data = 20;}  // FR20
    else if(866 <= X && X < 944 && 583 <= Y && Y < 1025){_data = 21;}  // FR25
    else if(944 <= X && X < 1025 && 583 <= Y && Y < 1025){_data = 22;} // FR30
  
  
    else if(0 <= X && X < 134 && 473 <= Y && Y < 583){_data = 23;}     // HL30
    else if(134 <= X && X < 198 && 473 <= Y && Y < 583){_data = 24;}   // HL25
    else if(198 <= X && X < 262 && 473 <= Y && Y < 583){_data = 25;}   // HL20
    else if(262 <= X && X < 326 && 473 <= Y && Y < 583){_data = 26;}   // HL15
    else if(326 <= X && X < 390 && 473 <= Y && Y < 583){_data = 27;}   // HL10
    else if(390 <= X && X < 454 && 473 <= Y && Y < 583){_data = 28;}   // HL05
    else if(454 <= X && X < 554 && 473 <= Y && Y < 583){_data = 29;}   // HS00
    else if(554 <= X && X < 632 && 473 <= Y && Y < 583){_data = 30;}   // HR05
    else if(632 <= X && X < 710 && 473 <= Y && Y < 583){_data = 31;}   // HR10
    else if(710 <= X && X < 788 && 473 <= Y && Y < 583){_data = 32;}   // HR15
    else if(788 <= X && X < 866 && 473 <= Y && Y < 583){_data = 33;}   // HR20
    else if(866 <= X && X < 944 && 473 <= Y && Y < 583){_data = 34;}   // HR25
    else if(944 <= X && X < 1025 && 473 <= Y && Y < 583){_data = 35;}  // HR30
  
    else if(0 <= X && X < 134 && 0 <= Y && Y < 473){_data = 36;}       // BL30
    else if(134 <= X && X < 198 && 0 <= Y && Y < 473){_data = 37;}     // BL25
    else if(198 <= X && X < 262 && 0 <= Y && Y < 473){_data = 38;}     // BL20
    else if(262 <= X && X < 326 && 0 <= Y && Y < 473){_data = 39;}     // BL15
    else if(326 <= X && X < 390 && 0 <= Y && Y < 473){_data = 40;}     // BL10
    else if(390 <= X && X < 454 && 0 <= Y && Y < 473){_data = 41;}     // BL05
    else if(454 <= X && X < 554 && 0 <= Y && Y < 473){_data = 42;}     // BS00
    else if(554 <= X && X < 632 && 0 <= Y && Y < 473){_data = 43;}     // BR05
    else if(632 <= X && X < 710 && 0 <= Y && Y < 473){_data = 44;}     // BR10
    else if(710 <= X && X < 788 && 0 <= Y && Y < 473){_data = 45;}     // BR15
    else if(788 <= X && X < 866 && 0 <= Y && Y < 473){_data = 46;}     // BR20
    else if(866 <= X && X < 944 && 0 <= Y && Y < 473){_data = 47;}     // BR25
    else if(944 <= X && X < 1025 && 0 <= Y && Y < 473){_data= 48;}     // BR30

    return _data;
  }
