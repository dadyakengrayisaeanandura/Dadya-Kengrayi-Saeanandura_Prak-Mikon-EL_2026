#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>

const char* ssid = "Lmao";
const char* password = "lmaooooo";

const char* mqtt_server = "2d5cd8d3bcbd425a8865b60469b32931.s1.eu.hivemq.cloud";
const int mqtt_port = 8883;
const char* mqtt_user = "Praktikan25";
const char* mqtt_pass = "Mikrokontroler2026";

const char* topic_cmd = "ugm/mikon/kel67/cmd";      // SESUAIKAN KELOMPOK
const char* topic_status = "ugm/mikon/kel67/status";

const int servoPin = 16;
const int servoChannel = 0;
const int servoFreq = 50;
const int servoResolution = 12;

WiFiClientSecure espClient;
PubSubClient client(espClient);

void setServo(int angle) {
  angle = constrain(angle, 0, 180);
  int duty = map(angle, 0, 180, 102, 512);
  ledcWrite(servoChannel, duty);
}

void callback(char* topic, byte* payload, unsigned int length) {
  char message[32];
  if (length >= sizeof(message)) length = sizeof(message) - 1;
  memcpy(message, payload, length);
  message[length] = '\0';

  Serial.print("Pesan masuk: ");
  Serial.println(message);

  if (strcmp(message, "MIN") == 0) {
    setServo(0);
  } else if (strcmp(message, "MID") == 0) {
    setServo(90);
  } else if (strcmp(message, "MAX") == 0) {
    setServo(180);
  }
}

void setup_wifi() {
  Serial.print("Koneksi WiFi...");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Terhubung!");
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Koneksi MQTT...");
    String clientId = "ESP32-Servo-Kel-" + String(random(1000, 9999));
    if (client.connect(clientId.c_str(), mqtt_user, mqtt_pass)) {
      Serial.println(" Terhubung!");
      client.subscribe(topic_cmd);
      client.publish(topic_status, "Tugas 1: Ready");
    } else {
      delay(3000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  ledcSetup(servoChannel, servoFreq, servoResolution);
  ledcAttachPin(servoPin, servoChannel);
  setServo(90);

  setup_wifi();
  espClient.setInsecure();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) reconnect();
  client.loop();
}