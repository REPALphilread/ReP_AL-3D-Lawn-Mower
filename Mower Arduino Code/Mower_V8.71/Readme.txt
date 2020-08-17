ReP_AL 3D Printed Robot Lawn Mower
----------------------------------

Code V8.71  17.08.2020
----------------------

Upload the MEGA code to the Arduino MEGA
Upload the Nano code to the Arduino Nano
Upload the NodeMCU code to the NodeMCU Board   (includes new code)
Upload the TFT Code to the TFT MEGA Shield
Upload the ESP32_Rover Code to the ESP32 Board (GPS)
Upload the BMP Files to the TFT SD Card


Features of 8.71
---------------

- Includes the Motor Amp Sensor Code and Menu options in the TFT menu
- Reduced / Eliminated "ghost" double turns at the wire
- Fixed TFT clock transfer for none PCB boards
- Included a PCB ON/OFF option (EEPROM) in the TFT Menu Other Settings
- Fixed void Exit_Dock text in specials tab
- Stopping of the mower improved when going home 
- TFT Display functions improved
- BETA version of GPS navigation (lots to improve)


Known Issues of 8.71
--------------------
- Mower can sometimes stop due the miss-communication between MEGA mower and TFT.
- TFT screnn can go back to the main menu when mowing (working on that now)


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


 
