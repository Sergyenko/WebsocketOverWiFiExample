# Example of usage Websocket over WiFi

Considering:
ESP8266 WIFI MODULE - https://www.adafruit.com/products/2282

Arduino WiFi Shield - https://www.arduino.cc/en/Main/ArduinoWiFiShield

## Examples

```
WebSocketClient client;

void setup() {
  Serial.begin(9600);
  client.connect(server);
  client.setDataArrivedDelegate(dataArrived);
  client.send("Hello World!");
}

void loop() {
  client.monitor();
}

void dataArrived(WebSocketClient client, String data) {
  Serial.println("Data Arrived: " + data);
}
```
