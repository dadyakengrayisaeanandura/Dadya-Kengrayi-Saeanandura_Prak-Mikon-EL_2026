#include <Arduino.h>

const int potPin = 26;
const float maxResistance = 10000.0;

void setup() {

  Serial.begin(9600);
  delay(1000);

  analogReadResolution(12);

  analogSetAttenuation(ADC_11db);
}

void loop() {
  int rawADC = analogRead(potPin);
  float tegangan = (rawADC / 4095.0) * 3.3;
  float hambatan = (rawADC / 4095.0) * maxResistance;

  Serial.print("Raw ADC: ");
  Serial.print(rawADC);
  
  Serial.print("Tegangan: ");
  Serial.print(tegangan, 2);
  Serial.print(" V");
  
  Serial.print("Hambatan: ");
  Serial.print(hambatan, 0);
  Serial.println(" Ohm");

  delay(500);
}
