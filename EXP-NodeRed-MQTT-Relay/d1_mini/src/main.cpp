#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// ==============================================================================
// CONFIGURATION SECTION
// Replace the text inside the quotation marks with your actual network details.
// ==============================================================================

#if __has_include("INPUT_YOUR_WIFI_SSID.h")
  #include "INPUT_YOUR_WIFI_SSID.h"
#else
  const char* ssid = "INPUT_YOUR_WIFI_SSID";         // Replace with your WiFi SSID
  const char* password = "INPUT_YOUR_WIFI_PASSWORD"; // Replace with your WiFi Password
  const char* mqtt_server = "INPUT_YOUR_MQTT_IP";    // Replace with your MQTT Broker IP
#endif

// Topic remains static to match the Node-RED dashboard setup
const char* mqtt_topic = "esp32/led/set"; 

// ==============================================================================
// GLOBAL VARIABLES & OBJECTS
// ==============================================================================
WiFiClient espClient;
PubSubClient client(espClient);

// Built-in LED pin on the Wemos D1 Mini
const int ledPin = LED_BUILTIN; 

// ==============================================================================
// FUNCTIONS
// ==============================================================================

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to WiFi: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected!");
  Serial.print("IP Wemos D1 Mini: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  String messageTemp;
  for (int i = 0; i < length; i++) {
    messageTemp += (char)payload[i];
  }
  
  Serial.print("Message arrived: ");
  Serial.println(messageTemp);

  if (String(topic) == mqtt_topic) {
    // Note: Wemos D1 Mini uses inverted logic for its built-in LED (LOW = ON)
    if (messageTemp == "1") {
      Serial.println("-> Turning LED ON");
      digitalWrite(ledPin, LOW); 
    }
    else if (messageTemp == "0") {
      Serial.println("-> Turning LED OFF");
      digitalWrite(ledPin, HIGH);
    }
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    
    // Create a random client ID
    String clientId = "WemosClient-";
    clientId += String(random(0xffff), HEX);
    
    if (client.connect(clientId.c_str())) {
      Serial.println(" Connected successfully!");
      client.subscribe(mqtt_topic);
    } else {
      Serial.print(" Failed, error code: ");
      Serial.print(client.state());
      Serial.println(" - Trying again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  // Initialize the LED pin as an output and turn it off initially (HIGH = OFF)
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); 
  
  Serial.begin(115200);
  setup_wifi();
  
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}