ReP_AL 3D Printed Robot Lawn Mower
----------------------------------

Code V9.2  10.01.2021
----------------------

Upload the MEGA code to the Arduino MEGA
Upload the Nano code to the Arduino Nano
Upload the NodeMCU code to the NodeMCU Board   (includes new code)
Upload the TFT Code to the TFT MEGA Shield
Upload the ESP32_Rover Code to the ESP32 Board (GPS)
Upload the BMP Files to the TFT SD Card


Features of 9.2
---------------

- Allows all LCD messages to be turned off if using a TFT screen.  This makes the program much more compact when using a TFT screen

In MEGA code line 11
set //#define LCD_KEYPAD for no LCD message
set #define LCD_KEYPAD for LCD messages on

- Major bug fix in the sensors menu.  Now SONAR and WIFI can be accessed again.


Known Issues of 9.0
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


 
