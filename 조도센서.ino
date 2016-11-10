// before change
#define POT_PIN A0 
#define LED_PIN 22 
int blueTx=14;   //Tx (블투 보내는핀 설정) 
int blueRx=15;   //Rx (블투 받는핀 설정) 
SoftwareSerial mySerial(blueTx, blueRx); 


void setup()
{
  pinMode(LED_PIN, OUTPUT);
  
}
void loop()
{
  int val = 0;
  val = analogRead(POT_PIN); 
  
  if(Serial.available())
  {
    char data = Serial.read();
    if(data == o) // if turn on the switch
    {
      //조도센서 값이 100미만이면 LED를 켠다
     if(val < 100) {
      digitalWrite(LED_PIN, HIGH);
      } else {
      digitalWrite(LED_PIN, LOW);
      }
    }
    else if(data == f) // if turn off the switch
    {
      digitalWrite(LED_PIN,LOW); // turn off the LED
    }
  delay(500);
}
