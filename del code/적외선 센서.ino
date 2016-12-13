int analogPin = A1;

void setup(){
  Serial.begin(9600);     
}
void loop(){
    int val;
    int volt = analogRead(analogPin);
    val = (6762/(volt-9))-4;
    if(val <= 45)
    {
      Lfmotor.run(BACKWARD);
      Rfmotor.run(BACKWARD);
      Lbmotor.run(BACKWARD);
      Rbmotor.run(BACKWARD);
      if(val => 42 && val <= 48)
      {
       Lfmotor.run(RELEASE);
       Rfmotor.run(RELEASE);
       Lbmotor.run(BACKWARD);
       Rbmotor.run(BACKWARD);
        break;
      }
    }
    delay(100);     
}
//거리측정
  
