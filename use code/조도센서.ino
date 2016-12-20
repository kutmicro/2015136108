/* not bluetooth

#define POT_PIN A0 
#define LED1_PIN 22
#define LED2_PIN 24
#define LED3_PIN 26 
#define LED4_PIN 28 

void setup()
{
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);
  
}
void loop()
{

      digitalWrite(LED1_PIN, HIGH);
      digitalWrite(LED2_PIN, HIGH);
      digitalWrite(LED3_PIN, HIGH);
      digitalWrite(LED4_PIN, HIGH);

      delay(500);
        
      digitalWrite(LED1_PIN,LOW); 
      digitalWrite(LED2_PIN,LOW);
      digitalWrite(LED3_PIN,LOW);
      digitalWrite(LED4_PIN,LOW)
      
}*/






// before change
#define POT_PIN A0 
#define LED1_PIN 22
#define LED2_PIN 24
#define LED3_PIN 26 
#define LED4_PIN 28 

void setup()
{
  Serial3.begin(9600);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);
  
}
void loop()
{
  int val = 0;
  
  if(Serial3.available())
  {
    char c = Serial3.read();
    
    if(c == 'o') // if turn on the switch
    {
      digitalWrite(LED1_PIN, HIGH);
      digitalWrite(LED2_PIN, HIGH);
      digitalWrite(LED3_PIN, HIGH);
      digitalWrite(LED4_PIN, HIGH);
    }
    else if(c == 'f') // if turn off the switch
    {
      digitalWrite(LED1_PIN,LOW); // turn off the LED
      digitalWrite(LED2_PIN,LOW);
      digitalWrite(LED3_PIN,LOW);
      digitalWrite(LED4_PIN,LOW);
    }
  delay(500);
}
