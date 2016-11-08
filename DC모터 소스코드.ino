// 수정전
#include <SoftwareSerial.h>

SoftwareSerial btSerial(2, 3); 

//Motor
AF_DCMotor Lmotor(1);
AF_DCMotor Rmotor(2);

int pwm =190;

void setup()
{
  btSerial.begin(9600);
 //Motor 
  Lmotor.setSpeed(200);
  Lmotor.run(RELEASE);
  Rmotor.setSpeed(200);
  Rmotor.run(RELEASE);
}

void loop()
{
  
        
  if (btSerial.available()) 
  {
    char c = btSerial.read();
    analogWrite(en, pwm);
    //속도제어
    if (c == '1') {
      pwm = 50;
    } else if (c == '2') {
      pwm = 150;
    } else if (c == '3') {
      pwm = 230;
    }

    //회전 방향 제어
    switch (c)
    {
      case 'a':
      case 'b':
      case 'c': //a,b,c인 경우, forword
        digitalWrite(13, HIGH);
        digitalWrite(p1, HIGH);
        digitalWrite(p2, LOW);
        break;
      case 'e'://d,e,f인경우, back
        digitalWrite(13, LOW);
        digitalWrite(p1, LOW);
        digitalWrite(p2, HIGH);
        break;
      case 'g': // stop
        digitalWrite(13, LOW);
        digitalWrite(p1, LOW);
        digitalWrite(p2, LOW);
      case '\r':  break;
      case '\n':  break;
//      default:  //이도저도 아니면
//        digitalWrite(13, LOW);
//        digitalWrite(p1, LOW);
//        digitalWrite(p2, LOW);
//        break;
    }
  }
}
