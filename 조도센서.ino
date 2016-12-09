// before change
#define POT_PIN A0 
#define LED_PIN 22 

void setup()
{
  Serial3.begin(9600_;
  pinMode(LED_PIN, OUTPUT);
  
}
void loop()
{
  int val = 0;
  val = analogRead(POT_PIN); 
  
  if(Serial3.available())
  {
    char data = Serial3.read();
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
