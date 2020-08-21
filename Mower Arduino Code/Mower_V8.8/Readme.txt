ReP_AL 3D Printed Robot Lawn Mower
----------------------------------

Code V8.8  21.08.2020
----------------------

Upload the MEGA code to the Arduino MEGA
Upload the Nano code to the Arduino Nano
Upload the NodeMCU code to the NodeMCU Board   (includes new code)
Upload the TFT Code to the TFT MEGA Shield
Upload the ESP32_Rover Code to the ESP32 Board (GPS)
Upload the BMP Files to the TFT SD Card
Upload the ESP WebCAM to the FPV Camera


Features of 8.8
---------------

- Fixes a bug if too high an amp setting was chosen it was missaved to EEPROM
- TFT Display functions improved
- Fixed errors whereby TFT screen shows the wrong menu when mowing
- BETA version of GPS navigation (lots to improve)
- Improved reconnect of WIFI on GPS and FPV Camera.
- I included the FPV software in the download (web page version which is the one I use)


Known Issues of 8.8
--------------------
- Mower can sometimes stop due the miss-communication between MEGA mower and TFT.


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


 
