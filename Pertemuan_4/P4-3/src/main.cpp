#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_INA219.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_INA219 ina219;
Adafruit_SSD1306 display(128, 64, &Wire, -1);
#define BUZZER_PIN 26

void setup() {
  Serial.begin(9600);
  Wire.begin(21, 22);
  ina219.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  pinMode(BUZZER_PIN, OUTPUT);
} 

void loop() {
  float arus = ina219.getCurrent_mA();
  float tegangan_V = ina219.getBusVoltage_V();
  float daya_mW = ina219.getPower_mW();

  if (arus > 500) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(500);
    
  } else {
    digitalWrite(BUZZER_PIN, LOW);
    delay(500);
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.println("===========");
  display.print("Tegangan(V): ");
  display.println(tegangan_V);
  display.print("Arus(mA): ");
  display.println(arus);
  display.print("Daya(mW): ");
  display.println(daya_mW);
  display.display();
  
  Serial.println("===========");
  Serial.print("Tegangan(V): ");
  Serial.println(tegangan_V);
  Serial.print("Arus(mA): ");
  Serial.println(arus);
  Serial.print("Daya(mW): ");
  Serial.println(daya_mW);
  delay(1000);
}