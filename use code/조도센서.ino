/* not module

#define POT_PIN A0 
#define LED_PIN 22 

void setup()
{
  Serial3.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  
}
void loop()
{
  int val = 0;
 
  if(Serial3.available())
  {
    char data = Serial3.read();
    if(data == 'o') // if turn on the switch
    {
      digitalWrite(LED_PIN, HIGH);
    }
    else if(data == 'f') // if turn off the switch
    {
      digitalWrite(LED_PIN,LOW); // turn off the LED
    }
  delay(500);



*/








// before change
#define POT_PIN A0 
#define LED_PIN 22 

void setup()
{
  Serial3.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  
}
void loop()
{
  int val = 0;
  
  if(Serial3.available())
  {
    char data = Serial3.read();
    
    if(data == o) // if turn on the switch
    {
      digitalWrite(LED_PIN, HIGH);
    }
    else if(data == f) // if turn off the switch
    {
      digitalWrite(LED_PIN,LOW); // turn off the LED
    }
  delay(500);
}
