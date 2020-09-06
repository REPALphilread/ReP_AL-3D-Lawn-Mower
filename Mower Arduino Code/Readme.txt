ReP_AL 3D Printed Robot Lawn Mower
----------------------------------

Code V8.6  30.07.2020
------------------------------

Upload the MEGA code to the Arduino MEGA
Upload the Nano code to the Arduino Nano
Upload the NodeMCU code to the NodeMCU Board   (includes new code)
Upload the TFT Code to the TFT MEGA Shield
Upload the ESP32_Rover Code to the ESP32 Board (GPS)
Upload the BMP Files to the TFT SD Card

PLEASE UPDATE THE LIBRARY FILES WITH THIS RELEASE


Features of 8.6
---------------

- PCB support as the onboard clock and relay are setup differently
- Added various QMC libraries (please use DF Robot for now)
- Added GY521 GYRO support. (GYRO will alway override compass if enabled)
- BETA version of GPS navigation (lots to improve)


Known Issues of 8.6
-------------------
- Mower can sometimes stop due the miss-communication between MEGA mower and TFT.
- GPS communication between ESP32 and TFT is unstable
- Missing funtions for ESP32 communication (select fence etc.) - to be updated in the next release.
- Normal RTC clock not tested with this version yet.




NodeMCU Board URL:
------------------
Use this URL to add the NodeMCU board 1.0 to the boards menu.

http://arduino.esp8266.com/stable/package_esp8266com_index.json

ESP32 Board URL:
------------------
Use this URL to add the ESP32 DOITDev1.0 board to the boards menu.
https://dl.espressif.com/dl/package_esp32_index.json, http://arduino.esp8266.com/stable/package_esp8266com_index.json


 
