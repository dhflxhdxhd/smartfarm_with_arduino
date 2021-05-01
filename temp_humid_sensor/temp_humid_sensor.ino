#include <SHT1x.h>
#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

#define dataPin 9
#define clockPin 10

SHT1x sht1x(dataPin, clockPin);

void setup()
{
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("temp_Humidity");
  //lcd.setCursor(1,1);
  //lcd.print();
}


void loop()
{
  float temp_C;
  float humidity;

  temp_C = sht1x.readTemperatureC();
  humidity = sht1x.readHumidity();
  
  Serial.print("Temperature: ");
  Serial.print(temp_C,DEC);
  Serial.println("C");
  Serial.print("Humidity: ");
  Serial.print(humidity,DEC);
  Serial.println("%");
  
  delay(500);
  
}
