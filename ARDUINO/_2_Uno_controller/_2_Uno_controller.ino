
//---------------------------------------------------------------- HEADER Declare
#include <SoftwareSerial.h>
#include <Button.h>

//---------------------------------------------------------------- BLUETOOTH Declare
SoftwareSerial BTSerial(2, 3); // Rx, Tx

//---------------------------------------------------------------- PIN Declare
Button DOWN(4);
Button LEFT(5);
Button F_(7);
Button E_(8);

int PIN_ANALOG_X = A0;
int PIN_ANALOG_Y = A1;

int LED_1 = 12;
int LED_2 = 13;
boolean STATE_L = true;
boolean STATE_D = true;
boolean old_STATE_L;
boolean old_STATE_D;

boolean Sending_state = false;

int X;
int Y;

//---------------------------------------------------------------- Initialisation( same baudrate as python script)
void setup(){
  BTSerial.begin(115200);

  //-------------------------------------------------------------- PINMODE Setting
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);

  pinMode(PIN_ANALOG_X, INPUT);
  pinMode(PIN_ANALOG_Y, INPUT);
}

void loop(){
  Read_sock();
  if(Sending_state == true){
    Read_Data();
    delay(1);
    if(STATE_D == true){Send_Joystick_1(X, Y);}
    else if(STATE_D == false){Send_Joystick_2(X, Y);}
    delay(1);
    Send_Button();
    delay(1);
  }
}

//---------------------------------------------------------------- FUNCTION Declare

void Read_sock(){
  int Temp_data = (BTSerial.read()).toInt();
      
       if(Temp_data == 254){Sending_state = true);}
  else if(Temp_data == 253){Sending_state = false);} 
}

//---------------------------------------------------------------- Read the analog and digital value that I want
void Read_Data(){
  X = analogRead(PIN_ANALOG_X);
  Y = analogRead(PIN_ANALOG_Y);
}

void Send_Joystick_2(int X, int Y){
       if(600 <= X && X < 1025 && 420 <= Y && Y <  605){BTSerial.write(int(202)); BTSerial.write(int(53));}  //HR50
  else if(440 <= X && X < 600  && 420 <= Y && Y <  605){BTSerial.write(int(200)); BTSerial.write(int(55));}  //HS00
  else if(  0 <= X && X < 440  && 420 <= Y && Y <  605){BTSerial.write(int(198)); BTSerial.write(int(57));}  //HL50
  else if(600 <= X && X < 1025 && 605 <= Y && Y < 1025){BTSerial.write(int(195)); BTSerial.write(int(60));}  //FR50 195 60
  else if(440 <= X && X < 600  && 605 <= Y && Y < 1025){BTSerial.write(int(193)); BTSerial.write(int(62));}  //FS00 193 62
  else if(  0 <= X && X < 440  && 605 <= Y && Y < 1025){BTSerial.write(int(191)); BTSerial.write(int(64));}  //FL50 191 64
  else if(600 <= X && X < 1025 &&   0 <= Y && Y <  420){BTSerial.write(int(209)); BTSerial.write(int(46));}  //BR50 209 46
  else if(440 <= X && X < 600  &&   0 <= Y && Y <  420){BTSerial.write(int(207)); BTSerial.write(int(48));}  //BS00 207 48
  else if(  0 <= X && X < 440  &&   0 <= Y && Y <  420){BTSerial.write(int(205)); BTSerial.write(int(50));}  //BL50 205 50
}
//---------------------------------------------------------------- Send data to main board via Bluetooth
/* 155~245 사용*/
void Send_Joystick_1(int X, int Y){
       if(880 <= X && X < 1025 &&   0 <= Y && Y < 70){ BTSerial.write(int(10));BTSerial.write(int(245));}   //BBBBBBB..R30
  else if(740 <= X && X < 880  &&   0 <= Y && Y < 70){ BTSerial.write(int(11));BTSerial.write(int(244));}   //BBBBBBB..R20
  else if(600 <= X && X < 740  &&   0 <= Y && Y < 70){ BTSerial.write(int(12));BTSerial.write(int(243));}   //BBBBBBB..R10
  else if(440 <= X && X < 600  &&   0 <= Y && Y < 70){ BTSerial.write(int(13));BTSerial.write(int(242));}   //BBBBBBB..S
  else if(300 <= X && X < 440  &&   0 <= Y && Y < 70){ BTSerial.write(int(14));BTSerial.write(int(241));}   //BBBBBBB..L10
  else if(160 <= X && X < 300  &&   0 <= Y && Y < 70){ BTSerial.write(int(15));BTSerial.write(int(240));}   //BBBBBBB..L20
  else if(  0 <= X && X < 160  &&   0 <= Y && Y < 70){ BTSerial.write(int(16));BTSerial.write(int(239));}   //BBBBBBB..L30

  else if(880 <= X && X < 1025 && 70 <= Y && Y < 140){ BTSerial.write(int(17));BTSerial.write(int(238));}   //BBBBBB..R30
  else if(740 <= X && X < 880  && 70 <= Y && Y < 140){ BTSerial.write(int(18));BTSerial.write(int(237));}   //BBBBBB..R20
  else if(600 <= X && X < 740  && 70 <= Y && Y < 140){ BTSerial.write(int(19));BTSerial.write(int(236));}   //BBBBBB..R10
  else if(440 <= X && X < 600  && 70 <= Y && Y < 140){ BTSerial.write(int(20));BTSerial.write(int(235));}   //BBBBBB..S
  else if(300 <= X && X < 440  && 70 <= Y && Y < 140){ BTSerial.write(int(21));BTSerial.write(int(234));}   //BBBBBB..L10
  else if(160 <= X && X < 300  && 70 <= Y && Y < 140){ BTSerial.write(int(22));BTSerial.write(int(233));}   //BBBBBB..L20
  else if(  0 <= X && X < 160  && 70 <= Y && Y < 140){ BTSerial.write(int(23));BTSerial.write(int(232));}   //BBBBBB..L30

  else if(880 <= X && X < 1025 && 140 <= Y && Y < 210){ BTSerial.write(int(24));BTSerial.write(int(231));}  //BBBBB..R30
  else if(740 <= X && X < 880  && 140 <= Y && Y < 210){ BTSerial.write(int(25));BTSerial.write(int(230));}  //BBBBB..R20
  else if(600 <= X && X < 740  && 140 <= Y && Y < 210){ BTSerial.write(int(26));BTSerial.write(int(229));}  //BBBBB..R10
  else if(440 <= X && X < 600  && 140 <= Y && Y < 210){ BTSerial.write(int(27));BTSerial.write(int(228));}  //BBBBB..S
  else if(300 <= X && X < 440  && 140 <= Y && Y < 210){ BTSerial.write(int(28));BTSerial.write(int(227));}  //BBBBB..L10
  else if(160 <= X && X < 300  && 140 <= Y && Y < 210){ BTSerial.write(int(29));BTSerial.write(int(226));}  //BBBBB..L20
  else if(  0 <= X && X < 160  && 140 <= Y && Y < 210){ BTSerial.write(int(30));BTSerial.write(int(225));}  //BBBBB..L30

  else if(880 <= X && X < 1025 && 210 <= Y && Y < 280){ BTSerial.write(int(31));BTSerial.write(int(224));}  //BBBB..R30
  else if(740 <= X && X < 880  && 210 <= Y && Y < 280){ BTSerial.write(int(32));BTSerial.write(int(223));}  //BBBB..R20
  else if(600 <= X && X < 740  && 210 <= Y && Y < 280){ BTSerial.write(int(33));BTSerial.write(int(222));}  //BBBB..R10
  else if(440 <= X && X < 600  && 210 <= Y && Y < 280){ BTSerial.write(int(34));BTSerial.write(int(221));}  //BBBB..S
  else if(300 <= X && X < 440  && 210 <= Y && Y < 280){ BTSerial.write(int(35));BTSerial.write(int(220));}  //BBBB..L10
  else if(160 <= X && X < 300  && 210 <= Y && Y < 280){ BTSerial.write(int(36));BTSerial.write(int(219));}  //BBBB..L20
  else if(  0 <= X && X < 160  && 210 <= Y && Y < 280){ BTSerial.write(int(37));BTSerial.write(int(218));}  //BBBB..L30

  else if(880 <= X && X < 1025 && 280 <= Y && Y < 350){ BTSerial.write(int(38));BTSerial.write(int(217));}  //BBB..R30
  else if(740 <= X && X < 880  && 280 <= Y && Y < 350){ BTSerial.write(int(39));BTSerial.write(int(216));}  //BBB..R20
  else if(600 <= X && X < 740  && 280 <= Y && Y < 350){ BTSerial.write(int(40));BTSerial.write(int(215));}  //BBB..R10
  else if(440 <= X && X < 600  && 280 <= Y && Y < 350){ BTSerial.write(int(41));BTSerial.write(int(214));}  //BBB..S
  else if(300 <= X && X < 440  && 280 <= Y && Y < 350){ BTSerial.write(int(42));BTSerial.write(int(213));}  //BBB..L10
  else if(160 <= X && X < 300  && 280 <= Y && Y < 350){ BTSerial.write(int(43));BTSerial.write(int(212));}  //BBB..L20
  else if(  0 <= X && X < 160  && 280 <= Y && Y < 350){ BTSerial.write(int(44));BTSerial.write(int(211));}  //BBB..L30

  else if(880 <= X && X < 1025 && 350 <= Y && Y < 420){ BTSerial.write(int(45));BTSerial.write(int(210));}  //BB..R30
  else if(740 <= X && X < 880  && 350 <= Y && Y < 420){ BTSerial.write(int(46));BTSerial.write(int(209));}  //BB..R20
  else if(600 <= X && X < 740  && 350 <= Y && Y < 420){ BTSerial.write(int(47));BTSerial.write(int(208));}  //BB..R10
  else if(440 <= X && X < 600  && 350 <= Y && Y < 420){ BTSerial.write(int(48));BTSerial.write(int(207));}  //BB..S
  else if(300 <= X && X < 440  && 350 <= Y && Y < 420){ BTSerial.write(int(49));BTSerial.write(int(206));}  //BB..L10
  else if(160 <= X && X < 300  && 350 <= Y && Y < 420){ BTSerial.write(int(50));BTSerial.write(int(205));}  //BB..L20
  else if(  0 <= X && X < 160  && 350 <= Y && Y < 420){ BTSerial.write(int(51));BTSerial.write(int(204));}  //BB..L30

  else if(880 <= X && X < 1025 && 420 <= Y && Y < 605){ BTSerial.write(int(52));BTSerial.write(int(203));}  //H..R30
  else if(740 <= X && X < 880  && 420 <= Y && Y < 605){ BTSerial.write(int(53));BTSerial.write(int(202));}  //H..R20
  else if(600 <= X && X < 740  && 420 <= Y && Y < 605){ BTSerial.write(int(54));BTSerial.write(int(201));}  //H..R10
  else if(440 <= X && X < 600  && 420 <= Y && Y < 605){ BTSerial.write(int(55));BTSerial.write(int(200));}  //H..S
  else if(300 <= X && X < 440  && 420 <= Y && Y < 605){ BTSerial.write(int(56));BTSerial.write(int(199));}  //H..L10
  else if(160 <= X && X < 300  && 420 <= Y && Y < 605){ BTSerial.write(int(57));BTSerial.write(int(198));}  //H..L20
  else if(  0 <= X && X < 160  && 420 <= Y && Y < 605){ BTSerial.write(int(58));BTSerial.write(int(197));}  //H..L30

  else if(880 <= X && X < 1025 && 605 <= Y && Y < 675){ BTSerial.write(int(59));BTSerial.write(int(196));}  //F..R30
  else if(740 <= X && X < 880  && 605 <= Y && Y < 675){ BTSerial.write(int(60));BTSerial.write(int(195));}  //F..R20
  else if(600 <= X && X < 740  && 605 <= Y && Y < 675){ BTSerial.write(int(61));BTSerial.write(int(194));}  //F..R10
  else if(440 <= X && X < 600  && 605 <= Y && Y < 675){ BTSerial.write(int(62));BTSerial.write(int(193));}  //F..S
  else if(300 <= X && X < 440  && 605 <= Y && Y < 675){ BTSerial.write(int(63));BTSerial.write(int(192));}  //F..L10
  else if(160 <= X && X < 300  && 605 <= Y && Y < 675){ BTSerial.write(int(64));BTSerial.write(int(191));}  //F..L20
  else if(  0 <= X && X < 160  && 605 <= Y && Y < 675){ BTSerial.write(int(65));BTSerial.write(int(190));}  //F..L30

  else if(880 <= X && X < 1025 && 675 <= Y && Y < 745){ BTSerial.write(int(66));BTSerial.write(int(189));}  //FF..R30
  else if(740 <= X && X < 880  && 675 <= Y && Y < 745){ BTSerial.write(int(67));BTSerial.write(int(188));}  //FF..R20
  else if(600 <= X && X < 740  && 675 <= Y && Y < 745){ BTSerial.write(int(68));BTSerial.write(int(187));}  //FF..R10
  else if(440 <= X && X < 600  && 675 <= Y && Y < 745){ BTSerial.write(int(69));BTSerial.write(int(186));}  //FF..S
  else if(300 <= X && X < 440  && 675 <= Y && Y < 745){ BTSerial.write(int(70));BTSerial.write(int(185));}  //FF..L10
  else if(160 <= X && X < 300  && 675 <= Y && Y < 745){ BTSerial.write(int(71));BTSerial.write(int(184));}  //FF..L20
  else if(  0 <= X && X < 160  && 675 <= Y && Y < 745){ BTSerial.write(int(72));BTSerial.write(int(183));}  //FF..L30

  else if(880 <= X && X < 1025 && 745 <= Y && Y < 815){ BTSerial.write(int(73));BTSerial.write(int(182));}  //FFF..R30
  else if(740 <= X && X < 880  && 745 <= Y && Y < 815){ BTSerial.write(int(74));BTSerial.write(int(181));}  //FFF..R20
  else if(600 <= X && X < 740  && 745 <= Y && Y < 815){ BTSerial.write(int(75));BTSerial.write(int(180));}  //FFF..R10
  else if(440 <= X && X < 600  && 745 <= Y && Y < 815){ BTSerial.write(int(76));BTSerial.write(int(179));}  //FFF..S
  else if(300 <= X && X < 440  && 745 <= Y && Y < 815){ BTSerial.write(int(77));BTSerial.write(int(178));}  //FFF..L10
  else if(160 <= X && X < 300  && 745 <= Y && Y < 815){ BTSerial.write(int(78));BTSerial.write(int(177));}  //FFF..L20
  else if(  0 <= X && X < 160  && 745 <= Y && Y < 815){ BTSerial.write(int(79));BTSerial.write(int(176));}  //FFF..L30

  else if(880 <= X && X < 1025 && 815 <= Y && Y < 885){ BTSerial.write(int(80));BTSerial.write(int(175));}  //FFFF..R30
  else if(740 <= X && X < 880  && 815 <= Y && Y < 885){ BTSerial.write(int(81));BTSerial.write(int(174));}  //FFFF..R20
  else if(600 <= X && X < 740  && 815 <= Y && Y < 885){ BTSerial.write(int(82));BTSerial.write(int(173));}  //FFFF..R10
  else if(440 <= X && X < 600  && 815 <= Y && Y < 885){ BTSerial.write(int(83));BTSerial.write(int(172));}  //FFFF..S
  else if(300 <= X && X < 440  && 815 <= Y && Y < 885){ BTSerial.write(int(84));BTSerial.write(int(171));}  //FFFF..L10
  else if(160 <= X && X < 300  && 815 <= Y && Y < 885){ BTSerial.write(int(85));BTSerial.write(int(170));}  //FFFF..L20
  else if(  0 <= X && X < 160  && 815 <= Y && Y < 885){ BTSerial.write(int(86));BTSerial.write(int(169));}  //FFFF..L30

  else if(880 <= X && X < 1025 && 885 <= Y && Y < 955){ BTSerial.write(int(87));BTSerial.write(int(168));}  //FFFFF..R30
  else if(740 <= X && X < 880  && 885 <= Y && Y < 955){ BTSerial.write(int(88));BTSerial.write(int(167));}  //FFFFF..R20
  else if(600 <= X && X < 740  && 885 <= Y && Y < 955){ BTSerial.write(int(89));BTSerial.write(int(166));}  //FFFFF..R10
  else if(440 <= X && X < 600  && 885 <= Y && Y < 955){ BTSerial.write(int(90));BTSerial.write(int(165));}  //FFFFF..S
  else if(300 <= X && X < 440  && 885 <= Y && Y < 955){ BTSerial.write(int(91));BTSerial.write(int(164));}  //FFFFF..L10
  else if(160 <= X && X < 300  && 885 <= Y && Y < 955){ BTSerial.write(int(92));BTSerial.write(int(163));}  //FFFFF..L20
  else if(  0 <= X && X < 160  && 885 <= Y && Y < 955){ BTSerial.write(int(93));BTSerial.write(int(162));} //FFFFF..L30

  else if(880 <= X && X < 1025 && 955 <= Y && Y < 1025){ BTSerial.write(int(94));BTSerial.write(int(161));} //FFFFFF..R30
  else if(740 <= X && X < 880  && 955 <= Y && Y < 1025){ BTSerial.write(int(95));BTSerial.write(int(160));} //FFFFFF..R20
  else if(600 <= X && X < 740  && 955 <= Y && Y < 1025){ BTSerial.write(int(96));BTSerial.write(int(159));} //FFFFFF..R10
  else if(440 <= X && X < 600  && 955 <= Y && Y < 1025){ BTSerial.write(int(97));BTSerial.write(int(158));} //FFFFFF..S
  else if(300 <= X && X < 440  && 955 <= Y && Y < 1025){ BTSerial.write(int(98));BTSerial.write(int(157));} //FFFFFF..L10
  else if(160 <= X && X < 300  && 955 <= Y && Y < 1025){ BTSerial.write(int(99));BTSerial.write(int(156));} //FFFFFF..L20
  else if(  0 <= X && X < 160  && 955 <= Y && Y < 1025){ BTSerial.write(int(100));BTSerial.write(int(155));} //FFFFFF..L30
}
//---------------------------------------------------------------- Change STATE and light when click LEFT button
void Send_Button(){
  old_STATE_D = STATE_D;
  old_STATE_L = STATE_L;

  if(LEFT.pressed()){STATE_L = !STATE_L;}                              // L → Choose parking and driving
  if(DOWN.pressed()){STATE_D = !STATE_D;}                              // R → Turn on/off laser
  if(F_.pressed()){BTSerial.write(120); BTSerial.write(135);}
  if(E_.pressed()){BTSerial.write(121); BTSerial.write(134);}
  
       if(old_STATE_L != STATE_L && STATE_L == true ){BTSerial.write(int(116));BTSerial.write(int(139));} // Driving mode
  else if(old_STATE_L != STATE_L && STATE_L == false){BTSerial.write(int(117));BTSerial.write(int(138));} // Parking mode
       if(old_STATE_D != STATE_D && STATE_D == true ){BTSerial.write(int(118));BTSerial.write(int(137));delay(10);} // Turn on  LED
  else if(old_STATE_D != STATE_D && STATE_D == false){BTSerial.write(int(119));BTSerial.write(int(136));delay(10);} // Turn off LED

       if(STATE_L == true) {digitalWrite(LED_2,HIGH);}
  else if(STATE_L == false){digitalWrite(LED_2,LOW);}
       if(STATE_D == true) {digitalWrite(LED_1,HIGH);}
  else if(STATE_D == false){digitalWrite(LED_1, LOW);}
}
