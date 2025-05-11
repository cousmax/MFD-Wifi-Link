# MFD-Wifi-Link

A project to transmit MAVLink data to your MFD Mini Crossbow using an ESP32. This code sets up a Wi-Fi connection and listens for MAVLink messages over UDP, making it easy to integrate with your flight systems.

---

## Features

- Captive Wi-Fi portal for easy configuration of Wi-Fi credentials.
- UDP communication to receive MAVLink messages.
- Watchdog timer to ensure the ESP32 remains responsive.
- Debugging options for troubleshooting.

---

## Requirements

### Hardware
- **ESP32**: The microcontroller used for this project.
- **MFD Mini Crossbow**: The target device for receiving MAVLink data.

### Software
- **Arduino IDE** or **PlatformIO**: For uploading the code to the ESP32.
- **WiFiManager Library**: For managing Wi-Fi credentials.
- **MAVLink Library**: For parsing MAVLink messages.

---

## Setup Instructions

1. **Install Required Libraries**:
   - Open the Arduino IDE.
   - Go to **Tools > Manage Libraries**.
   - Search for and install the following libraries:
     - `WiFiManager`
     - `MAVLink`

2. **Configure the Code**:
   - Open the `MAVLINKConfigPortal.ino` file.
   - Modify the following lines if needed:
     ```cpp
     const int port = 14550; // Change the UDP port if required
     ```

3. **Upload the Code**:
   - Connect your ESP32 to your computer.
   - Select the correct board and port in the Arduino IDE.
   - Upload the code to the ESP32.

4. **Connect to the Captive Portal**:
   - Power on the ESP32.
   - Connect to the Wi-Fi network named `MAVLINK_Config_Portal`.
   - Follow the on-screen instructions to configure your Wi-Fi credentials.

5. **Start Receiving MAVLink Data**:
   - Once connected, the ESP32 will listen for MAVLink messages on the specified UDP port.
   - Use the serial monitor to debug or view incoming data.

---

## Usage

- **Debugging**:
  - Enable or disable debugging by modifying the `DEBUG` macro in the code:
    ```cpp
    #define DEBUG true
    ```

- **Reset Wi-Fi Credentials**:
  - Uncomment the following line in the code to reset saved Wi-Fi credentials:
    ```cpp
    wifiManager.resetSettings();
    ```

- **MAVLink Parsing**:
  - The code currently receives MAVLink messages but does not process them. You can add custom parsing logic in the `loop()` function.

---

## Future Improvements

- Add a web-based interface for configuring additional settings.
- Implement full MAVLink message parsing and handling.
- Add support for sending MAVLink messages back to the flight controller.

---

## License

This project is open-source and available under the [MIT License](LICENSE).

---

## Acknowledgments

- Special thanks to Katz for the initial inspiration and guidance.
- Built using the ESP32 platform and MAVLink protocol.
