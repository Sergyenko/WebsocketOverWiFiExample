#include <SPI.h>
#include <WiFi.h>
#include <WebSocketClient.h>

char ssid[] = "robohub"; //  your network SSID (name)
char pass[] = "fwrobots";

char server[] = "192.168.43.115";
char path[] = "/sergey_robo";
int port = 3000;

int status = WL_IDLE_STATUS;

WebSocketClient client;
WiFiClient wifi;

void setup() {
  Serial.begin(9600);
  pinMode(A0, OUTPUT);

  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    WiFi.begin(ssid, pass);
    // wait 10 seconds for connection:
    delay(10000);
  }
  Serial.print("Connected to: ");
  Serial.println(ssid);

  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  client.connect(server, path, port);
  client.setDataArrivedDelegate(dataArrived);
}

void loop() {
  client.monitor();
  client.send("hello");
}

void dataArrived(WebSocketClient client, String data) {
  int val = 0;
  val = digitalRead(A0);
  val ? digitalWrite(A0, LOW) : digitalWrite(A0, HIGH);
  Serial.println("Data Arrived at: " + data);
}
