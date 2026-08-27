# IoT-Prototyping-Lab

Hello. 

This repository serves as a monorepo workspace where I collect various experiments, prototypes, and learning modules related to the Internet of Things (IoT) and embedded systems. From simple remote LED control to more complex sensor network architectures, everything here is built with a focus on efficiency, clear documentation, and reproducibility.

---

## Tech Stack & Hardware
The experiments in this lab primarily involve the following hardware and software:
* **Microcontrollers:** Wemos D1 Mini (ESP8266), ESP32, Arduino Uno/Mega.
* **Environment:** PlatformIO (VS Code).
* **Communication:** MQTT (Mosquitto), HTTP/REST, Serial.
* **Dashboard/GUI:** Node-RED.

---

## Repository Structure
To keep everything organized and easy to navigate, this repository uses a directory naming system with a standardized three-letter prefix. 

Here is the navigation guide:

| Prefix | Category | Description |
| :--- | :--- | :--- |
| **`EXP`** | Experiment | Single feature testing, new sensor trials, or trial and error projects (e.g., `EXP-NodeRed-MQTT-Relay`). |
| **`PRJ`** | Project | Complete, functional, and larger-scale main projects. |
| **`ASG`** | Assignment | Projects related to specific academic tasks or prototype development. |
| **`CRS`** | Course | Notes, scripts, or source code tied to specific university courses and learning materials. |

> **Important Note:** Each project folder usually contains a standalone PlatformIO environment. Please do not open this parent repository directly as a PlatformIO project. Open the specific sub-folder (e.g., `EXP-NodeRed-MQTT-Relay/Wemos-D1`) to avoid library conflicts.

---

## Configuration & Credentials
Security is handled seamlessly. Network credentials are isolated so that your private information stays out of version control while remaining plug-and-play for anyone who clones the repository.

Before compiling any network-dependent project:
1. Open the `src/main.cpp` file of the project.
2. Locate the configuration section at the top.
3. Replace the placeholder text (`INPUT_YOUR_WIFI_SSID`, `INPUT_YOUR_WIFI_PASSWORD`, and `INPUT_YOUR_MQTT_IP`) directly with your actual network details.

*Note for local development: If you manage a private credential header locally, it is completely ignored by `.gitignore` to ensure your data is never pushed to GitHub.*

---

## How to Use
If you want to try out one of the projects here:
1. Clone this repository: `git clone https://github.com/Tiyanzr/IoT-Prototyping-Lab.git`
2. Open the desired project folder using **VS Code**.
3. Ensure the **PlatformIO** extension is installed.
4. Set up your network configuration directly in `src/main.cpp` following the guide above.
5. Connect your microcontroller, then click **Upload** via PlatformIO.

---

## License
All code and documentation in this repository are distributed under the **MIT License**. You are highly encouraged to freely use, modify, and redistribute these projects, especially for educational purposes and technological development.

---
*Maintained by* **Tiyan Zahran Razzaq**
