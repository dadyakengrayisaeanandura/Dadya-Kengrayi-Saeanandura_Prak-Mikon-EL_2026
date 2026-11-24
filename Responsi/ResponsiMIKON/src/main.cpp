#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

Adafruit_BME280 bme;
float suhu;
const int pwmPin = 18;
const int freq = 5000;
const int pwmChannel = 0;
const int resolution = 8;
const int BUZZER_PIN = 26; 

void setup() {
  Wire.begin();
  bme.begin(0x76); // Alamat I2C default BME280
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  float suhu = bme.readTemperature();
  Serial.begin(115200);
  Serial.print("Suhu: ");
  Serial.print(suhu);
  Serial.println(" *C");
  // Gunakan variabel suhu untuk mengatur PWM aktuator

  if (suhu >28){
  digitalWrite(BUZZER_PIN, HIGH); // Buzzer Menyala
  delay(500);
  }

  if (suhu >28){
  digitalWrite(BUZZER_PIN, LOW); // Buzzer Mati
  delay(500);
  }

}