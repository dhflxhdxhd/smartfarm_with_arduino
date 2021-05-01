const int sensorMin = 0;   // sensor minimum우적
const int sensorMax = 1024;  // sensor maximum우적
const int CO2 = A1;//CO2
double CO2Value = 0;
#include <Sensirion.h>
const uint8_t dataPin  =  9;
const uint8_t clockPin =  10;
float temperature;
float humidity;
float dewpoint;
Sensirion tempSensor = Sensirion(dataPin, clockPin);
void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);// 토양수분
  pinMode(A2,INPUT);// 우적
  Serial.print(",");
  Serial.println("Rain State, Rain *,Moisture *, Temperature *C, Humidity %, Dewpoint *C, CO2 *PPM");

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  
  int h = analogRead(A0);//토양수분
  //Serial.println();
  int r = analogRead(A2);//우적
  int range = map(r, sensorMin, sensorMax, 0, 3);


  if (isnan(h) || isnan(r)) {
    Serial.println("Failed to read from Sensor!");
    return;
    }
    
  tempSensor.measure(&temperature, &humidity, &dewpoint);

  Serial.print(",");
  switch (range) {
    case 0:  // Sensor getting wet
    Serial.print("Flood");
    break;
    case 1:  // Sensor getting wet
    Serial.print("Rain Warning");
    break;
    case 2:  // Sensor dry - To shut this up delete the " Serial.println("Not Raining"); " below.
    Serial.print("Not Raining");
    break;
    }
    delay(1);  // delay between reads

  CO2Value = analogRead(CO2) / 0.0004;
  Serial.print(CO2Value);


  Serial.print(",");
  Serial.print(r);
  Serial.print(",");
  Serial.print(h);
  Serial.print(",");
  Serial.print(temperature);
  Serial.print(",");
  Serial.print(humidity);
  Serial.print(",");
  Serial.print(dewpoint);
  Serial.print(",");
  Serial.println(CO2Value);
}
