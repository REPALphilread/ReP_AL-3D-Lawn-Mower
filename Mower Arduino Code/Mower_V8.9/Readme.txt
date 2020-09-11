ReP_AL 3D Printed Robot Lawn Mower
----------------------------------

Code V8.9  06.09.2020
----------------------

Upload the MEGA code to the Arduino MEGA
Upload the Nano code to the Arduino Nano
Upload the NodeMCU code to the NodeMCU Board   (includes new code)
Upload the TFT Code to the TFT MEGA Shield
Upload the ESP32_Rover Code to the ESP32 Board (GPS)
Upload the BMP Files to the TFT SD Card


Features of 8.9
---------------

- Added option of NodeMCU gaurding of Mower Arduino MEGA
- Added WIFI Switch to the NodeMCU to turn ON/OFF components within the mower via Blynk App
- Fixed miscommunication between the nano and wheel amp sensors which gave false positives of wheels blocked
- Fixed WIFI_Enabled in the LCD Menu 
- Started adding additonal NodeMCU settings options to control Mower settings via the WIFI APP.
- Removed all other compass options as the GY282 is working fine with the DFRobot Code.



Known Issues of 8.9
--------------------
- Communication of button posiitons in the WIFI app not perfected.
- GYRO control not optimised.


Planned for next release
------------------------
- GYRO / Compass options (which device will control the mower)


NodeMCU Board URL:
------------------
Use this URL to add the NodeMCU board 1.0 to the boards menu.

http://arduino.esp8266.com/stable/package_esp8266com_index.json

ESP32 Board URL:
------------------
Use this URL to add the ESP32 DOITDev1.0 board to the boards menu.
https://dl.espressif.com/dl/package_esp32_index.json, http://arduino.esp8266.com/stable/package_esp8266com_index.json


 
