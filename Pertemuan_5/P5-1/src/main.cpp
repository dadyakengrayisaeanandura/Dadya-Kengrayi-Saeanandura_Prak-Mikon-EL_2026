#include <WiFi.h>

const char* ssid = "Lmao";
const char* pass = "lmaooooo";

void setup() {
    Serial.begin(9600);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, pass);
    Serial.println("Connecting");
    while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
}
    Serial.println("WiFi Connected!");
    Serial.println(WiFi.localIP());
}

void loop() {
    Serial.println("WiFi Connected!");
    Serial.println(WiFi.localIP());
    delay(1000);
}