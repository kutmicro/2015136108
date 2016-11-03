#include <SoftwareSerial.h>
SoftwareSerial
BTSerial(2, 3); //아두이노 D2에 TXD, D3에 RXD를 연결한다는  
void setup()  
{  
  Serial.begin(9600);
  BTSerial.begin(9600);
}
void loop()
{  
  if(BTSerial.available())
    Serial.write(BTSerial.read());
  
  if(Serial.available())
    BTSerial.write(Serial.read());  
}
