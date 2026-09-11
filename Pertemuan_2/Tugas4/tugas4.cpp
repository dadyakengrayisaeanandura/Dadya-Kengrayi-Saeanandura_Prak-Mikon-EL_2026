#include <Arduino.h>

int buttonPin = 27;
int ledPinM = 35;
int ledPinK = 32;
int ledPinP = 33;

const int potPin = 26;

bool buttonState = false;

void setup()
{
    pinMode(ledPinM, OUTPUT);
    pinMode(ledPinK, OUTPUT);
    pinMode(ledPinP, OUTPUT);
    pinMode(buttonPin, INPUT_PULLDOWN);

    analogReadResolution(12);
    analogSetAttenuation(ADC_11db);
}

void loop()
{
    buttonState = digitalRead(buttonPin);
    int rawADC = analogRead(potPin);

    if (buttonState == HIGH)
    {
        digitalWrite(ledPinM, LOW);
        digitalWrite(ledPinK, LOW);
        digitalWrite(ledPinP, LOW);
    }
    else if (rawADC < 1365)
    {
        digitalWrite(ledPinM, HIGH);
        digitalWrite(ledPinK, LOW);
        digitalWrite(ledPinP, LOW);
    }
    else if (rawADC < 2730)
    {
        digitalWrite(ledPinM, LOW);
        digitalWrite(ledPinK, HIGH);
        digitalWrite(ledPinP, LOW);
    }
    else
    {
        digitalWrite(ledPinM, LOW);
        digitalWrite(ledPinK, LOW);
        digitalWrite(ledPinP, HIGH);
    }

    delay(100);
}