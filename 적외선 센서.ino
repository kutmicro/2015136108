int analogPin = A1;

void setup(){
  Serial.begin(9600);     
}
void loop(){
    int val;
    int volt = analogRead(analogPin);
    val = (6762/(volt-9))-4;
    Serial.println(val);
    delay(100);     
}
//거리측정
