#include <LiquidCrystal.h>
#include <dht.h>
 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int greenPin = 13;
dht sensor;
int buzz = 10;
 
void setup()
{
  lcd.begin(16,2); //16 by 2 character display
  pinMode(buzz,OUTPUT);
  digitalWrite(buzz,LOW);
}
 
void loop()
{
  delay(1000); //wait a sec (recommended for DHT11)
  sensor.read11(greenPin);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Humidity = ");
  lcd.print(sensor.humidity);
  lcd.setCursor(0,1);
  lcd.print("Temp = ");
  lcd.print(sensor.temperature*1.8+32);
  float t = (sensor.temperature*1.8+32);
    {
      if (t>30)
      {
            digitalWrite(buzz,HIGH);
      } else
              digitalWrite(buzz,LOW);
}}
