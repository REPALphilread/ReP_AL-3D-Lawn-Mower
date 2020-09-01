ReP_AL 3D Printed Robot Lawn Mower
----------------------------------

Code V6.31   
------------------------------

Upload the MEGA code to the Arduino MEGA
Upload the Nano code to the Arduino Nano
Upload the NodeMCU code to the NodeMCU Board


Features of 6.31
---------------

- EEPROM has been added.  Settings will be saved to EEPROM and reloaded when the mower is powered on.
- EEPROM can also be cleared in the settings menu.
- Please dont save the Compass to ON in EEPROM unless you have a compass fitted.  This could hang the program at the beginning.  If you do this by mistake you will need to adjust the code in the EEPROM tab so the compass setting is not loaded.
- Clock can now be set in Settings (Time only not date).
- Added PWM test to the wheel test routine.
- Compass turn to home has been improved.  There is now a max amount of cycles before tehe headign is locked.  This prevents the mower dancing around looking for the correct heading.
- Improved the cancellation of tracking and wire finding using the cancel button on the APP.  Now the mower goes into a parked mode as it should, before it got trapped in some loops in the code and the mower became locked.


NodeMCU Board URL:
http://arduino.esp8266.com/stable/package_esp8266com_index.json


 
