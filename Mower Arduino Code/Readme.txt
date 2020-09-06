ReP_AL 3D Printed Robot Lawn Mower
----------------------------------

Code V8.3  26.06.2020
------------------------------

Upload the MEGA code to the Arduino MEGA
Upload the Nano code to the Arduino Nano
Upload the NodeMCU code to the NodeMCU Board   (includes new code)
Upload the TFT Code to the TFT MEGA Shield
Upload the ESP32_Rover Code to the ESP32 Board (GPS)
Upload the BMP Files to the TFT SD Card


Features of 8.3
---------------

- Fixed the CW CCW exit from dock and enter into garden.  The mower now turns in the right orientation for each.
- TFT Display functions improved - Many small errors removed when transfereing between screens
- Fixed the pattern mow selection and parallel options in the TFT display
- BETA version of GPS navigation (lots to improve)


Known Issues of 8.3
-------------------
- Mower can sometimes stop due the miss-communication between MEGA mower and TFT.
- GPS communication between ESP32 and TFT is unstable
- Missing funtions for ESP32 communication (select fence etc.) - to be updated in the next release.




NodeMCU Board URL:
------------------
Use this URL to add the NodeMCU board 1.0 to the boards menu.

http://arduino.esp8266.com/stable/package_esp8266com_index.json

ESP32 Board URL:
------------------
Use this URL to add the ESP32 DOITDev1.0 board to the boards menu.
https://dl.espressif.com/dl/package_esp32_index.json, http://arduino.esp8266.com/stable/package_esp8266com_index.json


 
