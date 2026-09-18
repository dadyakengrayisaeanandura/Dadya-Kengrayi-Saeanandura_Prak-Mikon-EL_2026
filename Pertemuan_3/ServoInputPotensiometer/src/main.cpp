#include <Arduino.h>

const int servoPin = 16;
const int potPin = 7;
const int freq = 50;
const int channel = 0;
const int res = 12;

void setup() {
  ledcSetup(channel, freq, res);
  ledcAttachPin(servoPin, channel);
  Serial.begin(115200);
}

void loop() {
  int potValue = analogRead(potPin);
  int pwmValue = map(potValue, 0, 4095, 102, 512);

  ledcWrite(servoPin, pwmValue);
  delay(15);

  Serial.print("Nilai analog Potensiometer: ");
  Serial.println(potValue);
}