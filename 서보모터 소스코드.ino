
    //still colleting

    #include <SoftwareSerial.h> //시리얼 통신 라이브러리 호출
    #include "Servo.h" //서보 라이브러리
 
    Servo myservo; //서보객체
    int blueTx=14;   //Tx (블투 보내는핀 설정)
    int blueRx=15;   //Rx (블투 받는핀 설정)
    SoftwareSerial mySerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언
    int curAngle = 90
 
    void setup() {
      myservo.attach(9);   //서보 시그널 핀설정
      myservo.write(curAngle);     //서보 초기각도 90도 설정
      mySerial.begin(9600); //블루투스 시리얼 개방
    }
 
    void loop() {
      if(mySerial.available()){
        char data = mySerial.read();
          {
              if(data == 'a') // left
              {
                  for (pos = curAngle ; pos > = 0; pos -=3) {    
                    curAngle = pos;
                    servo.write(pos);     
                    delay(15);    
                  }

              }
              if(data == 'b') // forward
              {
                  servo.write(90);
              }
              if(data == 'c') // right
              {
                  for (pos = curAngle; pos <= 0; pos +=3) {
                    curAngle = pos;
                    servo.write(pos);     
                    delay(15);    
                  }
                  delay(100);
              }
              if(data == 'e') // back
              {
                  servo.write(0);
              }
              if(data == 'g') // stop
              {
              }
          }
      }
    }
             
