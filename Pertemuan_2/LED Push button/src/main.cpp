#include <Arduino.h>

int buttonPin = 27;
int ledPinM = 35;
int ledPinK = 32;
int ledPinP = 33;
bool buttonState = false;

void setup() {
  pinMode(ledPinM, OUTPUT);
  pinMode(ledPinK, OUTPUT);
  pinMode(ledPinP, OUTPUT);
  pinMode(buttonPin, INPUT_PULLDOWN);
}

void loop() {

  buttonState = digitalRead(buttonPin);


  if (buttonState == HIGH){
    digitalWrite(ledPinM, HIGH);
    digitalWrite(ledPinK, HIGH);
    digitalWrite(ledPinP, HIGH);
  } else {

    digitalWrite(ledPinM, LOW);
    digitalWrite(ledPinK, LOW);
    digitalWrite(ledPinP, LOW);
  }
}
