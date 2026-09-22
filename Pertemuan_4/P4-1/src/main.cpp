#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

void setup() {
  Serial.begin(9600);
  Wire.begin(32, 27);
  ina219.begin();
} 

void loop() {
  float arus = ina219.getCurrent_mA();
  float tegangan_V = ina219.getBusVoltage_V();
  float daya_mW = ina219.getPower_mW();

  Serial.println("===========");
  Serial.print("Tegangan(V): ");
  Serial.println(tegangan_V);
  Serial.print("Arus(mA): ");
  Serial.println(arus);
  Serial.print("Daya(mW): ");
  Serial.println(daya_mW);
  delay(1000);
}