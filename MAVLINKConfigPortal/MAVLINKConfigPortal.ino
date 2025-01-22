#include <WiFi.h>
#include <WiFiUdp.h>
#include <MAVLink.h>
#include <mavlink.h>
#include <HardwareSerial.h>

//TBS
const char* ssid     = "ExpressLRS TX Backpack 5BFAF3"; // Change this to your WiFi SSID of your crossfire /tango2
const char* password = "expresslrs"; // NONE!
const char* host = "10.0.0.1";


//Port
const int port = 14550;


WiFiUDP Udp;
char packetBuffer[255];
mavlink_message_t msg;
mavlink_status_t status;

mavlink_gps_raw_int_t gps_raw_int;
mavlink_global_position_int_t global_position_int;

void setup() {
  Serial.begin(115200);
  delay(10);

  WiFi.begin(ssid, password);

  Serial.print("Connecting to ");
  Serial.print(ssid);
  Serial.println("...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Udp.begin(port);  // Local port to listen on
  Serial.print("Listening on UDP port ");
  Serial.println(port);
}

void loop() {
  if (Udp.parsePacket() >0) {
    int packetSize = Udp.available();
    char packet[packetSize];
    Udp.read(packet, packetSize);
    Serial.write(packet, packetSize);
  }
}
