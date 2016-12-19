#include <SoftwareSerial.h>
#include <AFMotor.h>

#define POT_PIN A0 
#define LED1_PIN 22
#define LED2_PIN 24
#define LED3_PIN 26 
#define LED4_PIN 28  

int distance;
int trig = 44;
int echo = 46;


//Motor
AF_DCMotor Lfmotor(2);
AF_DCMotor Rfmotor(1);
AF_DCMotor Lbmotor(3);
AF_DCMotor Rbmotor(4);


void setup()
{
  Serial3.begin(9600);
 //Motor 
  Lfmotor.setSpeed(200);
  Lfmotor.run(RELEASE);
  Lbmotor.setSpeed(200);
  Lbmotor.run(RELEASE);
  
  Rfmotor.setSpeed(200);
  Rfmotor.run(RELEASE);
  Rbmotor.setSpeed(200);
  Rbmotor.run(RELEASE);

  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);
  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
}

void loop()
{
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);

    distance = pulseIn(echo,HIGH) / 58;

    Serial3.write(distance);

    delay(500);
    
    if(distance <= 10)
    {
      Lfmotor.run(BACKWARD);
      Rfmotor.run(BACKWARD);
      Lbmotor.run(BACKWARD);
      Rbmotor.run(BACKWARD);
    }
        
  if (Serial3.available()) 
  {
    char c = Serial3.read();

    //회전 방향 제어
    switch (c)
    {
      case 'a': // left
        Lfmotor.run(RELEASE);
        Rfmotor.run(FORWARD);
        Lbmotor.run(RELEASE);
        Rbmotor.run(FORWARD);
        break;
      case 'b': // forword
        Lfmotor.run(FORWARD);
        Rfmotor.run(FORWARD);
        Lbmotor.run(FORWARD);
        Rbmotor.run(FORWARD);
        break;
      case 'c': //right
        Lfmotor.run(FORWARD);
        Rfmotor.run(RELEASE);
        Lbmotor.run(FORWARD);
        Rbmotor.run(RELEASE);
        break;
        
      case 'e':// back
        Lfmotor.run(BACKWARD);
        Rfmotor.run(BACKWARD);
        Lbmotor.run(BACKWARD);
        Rbmotor.run(BACKWARD);
        break;
      case 'g': // stop
        Lfmotor.run(RELEASE);
        Rfmotor.run(RELEASE);
        Lbmotor.run(RELEASE);
        Rbmotor.run(RELEASE);
      case '\r':  break;
      case '\n':  break;
    }
    
    if(c == 'o') // if turn on the switch
    {
      digitalWrite(LED1_PIN, HIGH);
      digitalWrite(LED2_PIN, HIGH);
      digitalWrite(LED3_PIN, HIGH);
      digitalWrite(LED4_PIN, HIGH);
    }
    else if(c == 'f') // if turn off the switch
    {
      digitalWrite(LED1_PIN,LOW); // turn off the LED
      digitalWrite(LED2_PIN,LOW);
      digitalWrite(LED3_PIN,LOW);
      digitalWrite(LED4_PIN,LOW);
    }
    }
  }
