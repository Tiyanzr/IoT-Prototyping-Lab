# EXP-NodeRed-MQTT-Relay

## Overview
This experiment demonstrates a fundamental Internet of Things (IoT) control loop. It configures a microcontroller to connect to a local WiFi network, establish a connection with an MQTT Broker, and subscribe to a specific command topic. 

While the ultimate goal is to control this system via a Node-RED dashboard, the core focus of this module is the reliable parsing of MQTT payloads to actuate hardware (in this case, toggling the built-in LED as a substitute for a physical relay).

## How It Works
1. **Network Connection:** The microcontroller connects to the local WiFi and assigns itself an IP address.
2. **Broker Connection:** It connects to the MQTT broker (e.g., Mosquitto) running on a local server or laptop.
3. **Subscription:** It subscribes to the topic `esp32/led/set`.
4. **Actuation:** Upon receiving a string payload of `"1"`, it turns the LED on. Upon receiving `"0"`, it turns the LED off.
   * *Note: The Wemos D1 Mini uses inverted logic for its built-in LED. The code handles this by setting the pin `LOW` to turn it on and `HIGH` to turn it off.*

## Projects Requirements
* **Framework:** Arduino framework via PlatformIO.
* **Dependencies:** `PubSubClient` (for MQTT communication).
* **Infrastructure:** A running MQTT Broker (e.g., Mosquitto) on the same local network.

## Configuration & Setup
This project uses a secure credential system to prevent private network details from being uploaded to version control.

### For Public Users (Cloning the Repository)
If you have cloned this repository, you do not need to create any extra files.
1. Open the `src/main.cpp` file.
2. Locate the **Configuration Section** at the top.
3. Replace the placeholder strings (`"INPUT_YOUR_WIFI_SSID"`, `"INPUT_YOUR_WIFI_PASSWORD"`, `"INPUT_YOUR_MQTT_IP"`) with your actual network credentials.
4. Compile and upload using PlatformIO.

