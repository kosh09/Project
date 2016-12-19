 // SoftwareSerial 처리 함수 시작
#include <SoftwareSerial.h>
// SoftwareSerial의 입력을 문자열로 반환
String getSerialInput(SoftwareSerial & SoftSerial)
{
  String str;
  while (SoftSerial.available() > 0)    // Serial에 수신 문자가 있는 동안만
    str += (char)SoftSerial.read();    // 문자열 str에 문자를 더함
  str.trim();    // 문자열 str의 양쪽에 있는 공백을 제거함
  return str;
}
// SoftwareSerial 처리 함수 끝
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// String 처리 함수 시작
#define BUF_SIZE 101    // char buf[BUF_SIZE]에 쓰는 buffer의 크기
// Serial port의 입력을 문자열로 반환
String getSerialInput()
{
  String str;
  while (Serial.available() > 0)    // Serial에 수신 문자가 있는 동안만
    str += (char)Serial.read();    // 문자열 str에 문자를 더함
  str.trim();    // 문자열 str의 양쪽에 있는 공백을 제거함
  return str;
}
// 정지 문자인지 여부 판단
boolean isDelimit(char ch)
{
  static const char pChar[] = " +-*/";    // 구문 분석을 정지할 문자들
  int nChar = strlen(pChar);
  for (int i = 0; i < nChar; i++)
    if (ch == pChar[i])  return true;  // 정지 문자가 나오면 true 반환
  return false;    // 정지 문자가 아니면 false 반환
}
// 문자열에서 token을 추출
String getToken(String & sInput, int & nPos)
{
  int nInput = sInput.length();
  while (sInput[nPos] == ' ')  nPos++;    // 공백 문자는 건너뛰기
  String str;
  if (nPos >= nInput)  return str;    // 문자열 크기보다 nPos가 크면 공 문자열 반환
  str += sInput[nPos], nPos++;    // 첫번째 문자를 str에 저장
  if (isDelimit(str[0]))  return str;    // 만약 정지 문자면 그대로 str 반환
  while (nPos < nInput)
  {
    if (isDelimit(sInput[nPos]))  return str;
    str += sInput[nPos], nPos++;    // 정지 문자가 아니라면 문자열 str에 현재 문자를 붙임
  }
  return str;
}
// 문자열을 실수로 변환
double atof(String & str)
{
  char buf[BUF_SIZE];    // 문자열을 실수로 바꿀 때 필요한 buffer 정의
  str.toCharArray(buf, BUF_SIZE);
  return atof(buf);    // 문자 배열을 실수로 변환
}
// 문자열을  정수로 변환
int atoi(String & str)
{
  char buf[BUF_SIZE];    // 문자열을 실수로 바꿀 때 필요한 buffer 정의
  str.toCharArray(buf, BUF_SIZE);
  return atoi(buf);    // 문자 배열을 정수로 변환
}
boolean isEmpty(String & str)  {  return str.length() == 0;  }



// String 처리 함수 끝

SoftwareSerial mySerial(8,5);   // Rx : D8, Tx : D5
String sId, sPartnerId; //ID 입력 저장변수
boolean bId, bPartnerId; //ID 입력 확인 변수
void setup(){
  Serial.begin(9600);  //시리얼포트 속도 9600으로 제어
  mySerial.begin(9600);  //파트너포트 속도 9600으로 제어
}
void loop(){
  //기본 정보 입력
  bId = !isEmpty(sId);  //false로 저장
  bPartnerId = !isEmpty(sPartnerId);  //false로 저장
  if(!bId){
    Serial.println("Insert your ID: ");
    sId = getSerialInput();  //ID입력
    if(!isEmpty(sId)){
      Serial.println(sId);  //ID출력
      mySerial.println(sId); 
    }
    delay(1000);
  }
  if(!bPartnerId){
    sPartnerId = getSerialInput(mySerial);  //상대방 입력 ID 저장
    if(!isEmpty(sPartnerId)){
      Serial.print("Partner ID: "), Serial.println(sPartnerId);  //상대방 입력 ID 출력
    }
  }
  if(bId & bPartnerId){
  //송신
  String sMsg = getSerialInput();  //메세지 입력
  mySerial.println(sMsg);  //메세지 보냄
  if(!isEmpty(sMsg)){Serial.print(sId),Serial.print(" > "),Serial.println(sMsg);
  }
  //수신
  String sPartnerMsg = getSerialInput(mySerial);  //상대방 메세지 저장
  if(!isEmpty(sPartnerMsg)){Serial.print(sPartnerId),Serial.print(" > "),Serial.println(sPartnerMsg);
  }
  }
  delay(1000);
}  // SoftwareSerial 처리 함수 시작
#include <SoftwareSerial.h>
// SoftwareSerial의 입력을 문자열로 반환
String getSerialInput(SoftwareSerial & SoftSerial)
{
  String str;
  while (SoftSerial.available() > 0)    // Serial에 수신 문자가 있는 동안만
    str += (char)SoftSerial.read();    // 문자열 str에 문자를 더함
  str.trim();    // 문자열 str의 양쪽에 있는 공백을 제거함
  return str;
}
// SoftwareSerial 처리 함수 끝
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// String 처리 함수 시작
#define BUF_SIZE 101    // char buf[BUF_SIZE]에 쓰는 buffer의 크기
// Serial port의 입력을 문자열로 반환
String getSerialInput()
{
  String str;
  while (Serial.available() > 0)    // Serial에 수신 문자가 있는 동안만
    str += (char)Serial.read();    // 문자열 str에 문자를 더함
  str.trim();    // 문자열 str의 양쪽에 있는 공백을 제거함
  return str;
}
// 정지 문자인지 여부 판단
boolean isDelimit(char ch)
{
  static const char pChar[] = " +-*/";    // 구문 분석을 정지할 문자들
  int nChar = strlen(pChar);
  for (int i = 0; i < nChar; i++)
    if (ch == pChar[i])  return true;  // 정지 문자가 나오면 true 반환
  return false;    // 정지 문자가 아니면 false 반환
}
// 문자열에서 token을 추출
String getToken(String & sInput, int & nPos)
{
  int nInput = sInput.length();
  while (sInput[nPos] == ' ')  nPos++;    // 공백 문자는 건너뛰기
  String str;
  if (nPos >= nInput)  return str;    // 문자열 크기보다 nPos가 크면 공 문자열 반환
  str += sInput[nPos], nPos++;    // 첫번째 문자를 str에 저장
  if (isDelimit(str[0]))  return str;    // 만약 정지 문자면 그대로 str 반환
  while (nPos < nInput)
  {
    if (isDelimit(sInput[nPos]))  return str;
    str += sInput[nPos], nPos++;    // 정지 문자가 아니라면 문자열 str에 현재 문자를 붙임
  }
  return str;
}
// 문자열을 실수로 변환
double atof(String & str)
{
  char buf[BUF_SIZE];    // 문자열을 실수로 바꿀 때 필요한 buffer 정의
  str.toCharArray(buf, BUF_SIZE);
  return atof(buf);    // 문자 배열을 실수로 변환
}
// 문자열을  정수로 변환
int atoi(String & str)
{
  char buf[BUF_SIZE];    // 문자열을 실수로 바꿀 때 필요한 buffer 정의
  str.toCharArray(buf, BUF_SIZE);
  return atoi(buf);    // 문자 배열을 정수로 변환
}
boolean isEmpty(String & str)  {  return str.length() == 0;  }



// String 처리 함수 끝

SoftwareSerial mySerial(8,5);   // Rx : D8, Tx : D5
String sId, sPartnerId; //ID 입력 저장변수
boolean bId, bPartnerId; //ID 입력 확인 변수
void setup(){
  Serial.begin(9600);  //시리얼포트 속도 9600으로 제어
  mySerial.begin(9600);  //파트너포트 속도 9600으로 제어
}
void loop(){
  //기본 정보 입력
  bId = !isEmpty(sId);  //false로 저장
  bPartnerId = !isEmpty(sPartnerId);  //false로 저장
  if(!bId){
    Serial.println("Insert your ID: ");
    sId = getSerialInput();  //ID입력
    if(!isEmpty(sId)){
      Serial.println(sId);  //ID출력
      mySerial.println(sId); 
    }
    delay(1000);
  }
  if(!bPartnerId){
    sPartnerId = getSerialInput(mySerial);  //상대방 입력 ID 저장
    if(!isEmpty(sPartnerId)){
      Serial.print("Partner ID: "), Serial.println(sPartnerId);  //상대방 입력 ID 출력
    }
  }
  if(bId & bPartnerId){
  //송신
  String sMsg = getSerialInput();  //메세지 입력
  mySerial.println(sMsg);  //메세지 보냄
  if(!isEmpty(sMsg)){Serial.print(sId),Serial.print(" > "),Serial.println(sMsg);
  }
  //수신
  String sPartnerMsg = getSerialInput(mySerial);  //상대방 메세지 저장
  if(!isEmpty(sPartnerMsg)){Serial.print(sPartnerId),Serial.print(" > "),Serial.println(sPartnerMsg);
  }
  }
  delay(1000);
} 
