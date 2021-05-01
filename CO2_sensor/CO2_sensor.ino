const int CO2 = A1;
double CO2Value = 0;

void setup()  {
  Serial.begin(38400);
}

void loop() {
  Serial.print("Sensor Value : ");
  CO2Value = analogRead(CO2) / 0.0004;
  Serial.print(CO2Value);
  Serial.println(" ppm");
  delay(1000);
}
