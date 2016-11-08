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
      // 후진 후 정지
      if(val == 45)
      {
        
      }
    }
    delay(100);     
}
//거리측정
