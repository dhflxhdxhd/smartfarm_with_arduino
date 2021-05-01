#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

void setup(){
  Serial.begin(9600);
  pinMode(A0,INPUT);
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Soil Humidity");
  //lcd.setCursor(1,1);
  //lcd.print();

}
void loop(){
  int soil_water = analogRead(A0);
  //int soil_humidity = map(soil_water,0,1023,100,0);
  Serial.print("soil_water:");
  Serial.println(soil_water);
 // Serial.print("soil_humidity=");
  //Serial.print(soil_humidity);
  //Serial.print("%");
  
  delay(1000);
}
