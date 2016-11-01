
    //still colleting

    #include <SoftwareSerial.h> //시리얼 통신 라이브러리 호출
    #include "Servo.h" //서보 라이브러리
 
    Servo myservo; //서보객체
    int blueTx=2;   //Tx (블투 보내는핀 설정)
    int blueRx=3;   //Rx (블투 받는핀 설정)
    SoftwareSerial mySerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언
    String myString=""; //받는 문자열
 
    void setup() {
      myservo.attach(12);   //서보 시그널 핀설정
      myservo.write(0);     //서보 초기각도 0도 설정
      mySerial.begin(9600); //블루투스 시리얼 개방
    }
 
    void loop() {
      if(mySerial.available()){
        char data = mySerial.read();
          {
              if(data == 'a') // left
              {
              }
              if(data == 'b') // forward
              {
              }
              if(data == 'c') // right
              {
              }
              if(data == 'd') // left back
              {              
              }
              if(data == 'e') // back
              {
              }
              if(data == 'f') // right back
              {
              }
              if(data == 'g') // stop
              {
              }
          }
      }
    }
             
