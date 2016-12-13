/* not bluetooth
#include <SoftwareSerial.h>

int distance;
int trig = 46;
int echo = 44;

void setup() {

  Serial.begin(9600);
  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}




void loop() {

  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);


  distance = pulseIn(echo,HIGH) / 58;


  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(1000);

}

*/






#include <SoftwareSerial.h>

int distance;
int trig = 46;
int echo = 44;

void setup() {

  Serial.begin(9600);
  Serial3.begin(9600);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}




void loop() {

  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);


  distance = pulseIn(echo,HIGH) / 58;


  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");

  Serial3.write(distance);

  
  delay(1000);
  
  if(distance <= 45)
    {
      Lfmotor.run(BACKWARD);
      Rfmotor.run(BACKWARD);
      Lbmotor.run(BACKWARD);
      Rbmotor.run(BACKWARD);
      /*if(distance => 42 && distance <= 48)
      {
       Lfmotor.run(RELEASE);
       Rfmotor.run(RELEASE);
       Lbmotor.run(RELEASE);
       Rbmotor.run(RELEASE);
        break;
      }*/
    }

}
