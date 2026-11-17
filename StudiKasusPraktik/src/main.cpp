#include <Wire.h>
#include <Adafruit_INA219.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_INA219 ina219;
Adafruit_SSD1306 display(128, 64, &Wire, -1);

const int in1 = 15;
const int in2 = 18;
const int pwmPin = 5;
const int stby = 19;
const int potPin = 34;


void setup() {
 pinMode(in1, OUTPUT);
 pinMode(in2, OUTPUT);
 pinMode(stby, OUTPUT);
 digitalWrite(stby, HIGH); // Aktifkan driver
 digitalWrite(in1, HIGH); // Atur arah putaran maju
 digitalWrite(in2, LOW);
 ledcSetup(0, 5000, 8);
 ledcAttachPin(pwmPin, 0); 
 
 Serial.begin(115200);
 ina219.begin();
 display.begin(SSD1306_SWITCHCAPVCC, 0x3C);




}
void loop() {
 int potValue = analogRead(potPin); // Hasil: 0 - 4095
 int pwmValue = map(potValue, 0, 4095, 0, 255); // Konversi ke 0 - 255
 ledcWrite(0, 200); // Set kecepatan motor (0-255)
 delay(15); 
 
  float arus = ina219.getCurrent_mA();
 float tegangan_V = ina219.getBusVoltage_V();
 float daya_mW = ina219.getPower_mW();
 delay(1000);

 display.clearDisplay();
 display.display();

}
