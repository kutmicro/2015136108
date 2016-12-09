#include <SoftwareSerial.h>

int distance;

int trig = 7;

int echo = 6;




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

}
