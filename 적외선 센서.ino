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
      digitalWrite(13, LOW);
      digitalWrite(p1, LOW);
      digitalWrite(p2, HIGH);
      if(val == 45)
      {
        digitalWrite(13, LOW);
        digitalWrite(p1, LOW);
        digitalWrite(p2, LOW);
        break;
      }
    }
    delay(100);     
}
//거리측정
  
