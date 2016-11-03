// 수정전
#include <SoftwareSerial.h>

SoftwareSerial btSerial(2, 3); 

//Motor
int p1 = 7;
int p2 = 8;
int en = 9; // speed control

int pwm =190;

void setup()
{
  pinMode(13, OUTPUT);
  btSerial.begin(9600);

 //Motor
 pinMode(p1, OUTPUT);
 pinMode(p2, OUTPUT);
 pinMode(en, OUTPUT);

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
      case 'd':
      case 'e':
      case 'f'://d,e,f인경우, back
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
