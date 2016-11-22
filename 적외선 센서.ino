int analogPin = A1;

void setup(){
  Serial.begin(9600);     
}
void loop(){
    int val;
    int volt = analogRead(analogPin);
    val = (6762/(volt-9))-4;
    Serial.println(val);
    if(val <= 45)
    {
      Lmotor.run(BACKWARD);
      Rmotor.run(BACKWARD);
      if(val => 42 && val <= 48)
      {
       Lmotor.run(RELEASE);
       Rmotor.run(RELEASE);
        break;
      }
    }
    delay(100);     
}
//거리측정
  
