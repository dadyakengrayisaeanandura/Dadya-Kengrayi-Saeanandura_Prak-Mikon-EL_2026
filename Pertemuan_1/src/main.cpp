#include <Arduino.h>

// Pin connected to the LED
const int ledPin = 5;
// Setup function runs once the start 
void setup() {
// Initialize the digital pin as an output 
pinMode(ledPin, OUTPUT);
}
// Loop functuion runs repeatedly
void loop() {
// Turn the LED on 
digitalWrite(ledPin, HIGH);
// Wait for 1 second
delay(1000);
// Turn the LED off
digitalWrite(ledPin, LOW);
// Wait for 1 second
delay(1000);
}