/* not bluetooth
#include <SoftwareSerial.h>

int distance;
int trig = 44;
int echo = 46;

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
int trig = 44;
int echo = 46;

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

  Serial3.write(distance);

  
  delay(500);
  
  f(distance <= 10)
    {
      Lfmotor.run(BACKWARD);
      Rfmotor.run(BACKWARD);
      Lbmotor.run(BACKWARD);
      Rbmotor.run(BACKWARD);
    }
}
