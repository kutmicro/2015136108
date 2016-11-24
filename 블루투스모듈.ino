/*#include <SoftwareSerial.h>
SoftwareSerial
BTSerial(14, 15); //아두이노 D2에 TXD, D3에 RXD를 연결한다는  
void setup()  
{  
  Serial.begin(9600);
  BTSerial.begin(9600);
}
void loop()
{  
  if(BTSerial.available())
    Serial.write(BTSerial.read());
  
  if(Serial.available())
    BTSerial.write(Serial.read());  
}*/




#include <SoftwareSerial.h> //시리얼 통신 라이브러리 호출
 
int blueTx=14;   //Tx (보내는핀 설정)
int blueRx=15;   //Rx (받는핀 설정)
SoftwareSerial mySerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언
String myString=""; //받는 문자열
 
void setup() {
  Serial.begin(9600);   //시리얼모니터 
  mySerial.begin(9600); //블루투스 시리얼 개방
 
}
 
void loop() {
  while(mySerial.available())  //mySerial에 전송된 값이 있으면
  {
    char myChar = (char)mySerial.read();  //mySerial int 값을 char 형식으로 변환
    myString+=myChar;   //수신되는 문자를 myString에 모두 붙임 (1바이트씩 전송되는 것을 연결)
    delay(5);           //수신 문자열 끊김 방지
  }
  if(!myString.equals(""))  //myString 값이 있다면
  {
    myString="";  //myString 변수값 초기화
  }
}

