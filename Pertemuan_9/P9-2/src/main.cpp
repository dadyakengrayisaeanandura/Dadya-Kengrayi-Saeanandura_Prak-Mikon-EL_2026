#include <Arduino.h>
#include <WiFi.h>
#include <CTBot.h>

CTBot myBot;
String ssid = "NARUTO SEASON 7 JANUARY";
String pass = "bapaknyadevfor";
String token  = "9057904990:AAGc8yWjqzCxllL0xJL_qPhPuuy4it5-SDE";

const int pinLED = 18;

void setup() {
  Serial.begin(115200);
  pinMode(pinLED, OUTPUT);
  digitalWrite(pinLED, LOW);

  myBot.wifiConnect(ssid, pass);
  myBot.setTelegramToken(token);

  if (myBot.testConnection())
    Serial.println("Telegram OK");
  else
    Serial.println("Telegram GAGAL");
}

void loop() {
  TBMessage msg;
  if (myBot.getNewMessage(msg)) {
    Serial.print("Pesan masuk: ");
    Serial.println(msg.text);

    if (msg.text.equalsIgnoreCase("LED ON")) {
      digitalWrite(pinLED, HIGH);
      myBot.sendMessage(msg.sender.id, "LED menyala");
    } else if (msg.text.equalsIgnoreCase("LED OFF")) {
      digitalWrite(pinLED, LOW);
      myBot.sendMessage(msg.sender.id, "LED mati");
    } else {
      myBot.sendMessage(msg.sender.id, "Kirim LED ON atau LED OFF");
    }
  }
  delay(500);
}