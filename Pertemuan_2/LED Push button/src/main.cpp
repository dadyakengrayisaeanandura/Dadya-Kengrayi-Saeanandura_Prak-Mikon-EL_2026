#include <Arduino.h>

int buttonPin = 27;
int ledPinM = 35;
int ledPinK = 32;
int ledPinP = 33;
bool buttonState = false;

void setup() {
  pinMode(ledPinM, OUTPUT);    // LED pin as an output.
  pinMode(ledPinK, OUTPUT);
  pinMode(ledPinP, OUTPUT);
  pinMode(buttonPin, INPUT_PULLDOWN);  // Button pin as an input.
}

void loop() {
  // Read the state of the button
  buttonState = digitalRead(buttonPin);

  // Check if the button is pressed
  if (buttonState == HIGH){
    digitalWrite(ledPinM, HIGH);   // Turn LED on.
    digitalWrite(ledPinK, HIGH);
    digitalWrite(ledPinP, HIGH);
  } else {
    // Tombol dilepas: Ketiga LED mati
    digitalWrite(ledPinM, LOW);
    digitalWrite(ledPinK, LOW);
    digitalWrite(ledPinP, LOW);
  }
}