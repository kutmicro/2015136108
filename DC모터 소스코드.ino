// 수정전
#include <SoftwareSerial.h>

SoftwareSerial btSerial(14, 15); 

//Motor
AF_DCMotor Lmotor(1);
AF_DCMotor Rmotor(2);


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
   
    }

    //회전 방향 제어
    switch (c)
    {
      case 'a':
      case 'b':
      case 'c': //a,b,c인 경우, forword
        Lmotor.run(FORWARD);
        Rmotor.run(FORWARD);
        break;
      case 'e'://d,e,f인경우, back
        Lmotor.run(BACKWARD);
        Rmotor.run(BACKWARD);
        break;
      case 'g': // stop
        Lmotor.run(RELEASE);
        Rmotor.run(RELEASE);
      case '\r':  break;
      case '\n':  break;
//      default:  //이도저도 아니면
//        Lmotor.run(RELEASE);
//        Rmotor.run(RELEASE);
//        break;
    }
  }
}
