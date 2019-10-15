ReP_AL 3D Printed Robot Lawn Mower
----------------------------------

Code V6.7
------------------------------

Upload the MEGA code to the Arduino MEGA
Upload the Nano code to the Arduino Nano
Upload the NodeMCU code to the NodeMCU Board   (includes new code)


Features of 6.7
---------------

- PLEASE UPDATE YOUR WIFI APP BY FOLLOWING THE WIFI INSTRUCTIONS ON THE WEBSITE11
- CHANGES ARE IN THE SEGMENTED SWITCH AT THE BOTTOM OF THE APP SCREEN
https://repalmakershop.com/pages/3d-printed-lawn-mower-wifi-app

- Allows the control of the pattern mow via the APP. 
- Parallel mow is still under development but you can trial it.


Pattern Mow Settings
--------------------

To adjust the spirals and parallel parameters please change the values in the pattern mow tab.
The variables are declared at the start of the subroutine.  I will change this and add it to the main menu and EEPROM
when its more developed.


   For Spiral     void Pattern_Mow_Spirals()  
   -----------------------------------------
   End_Linking       is the distance between spirals


   For Parallel    (under development)   void Pattern_Mow_Parallel() 
   ------------------------------------------------------------------
   See the notation on the code.  Please note this is still under development
   so dont expect miracles ! :)
   You will need to adjust the Left anf Right turning times to get a rough 90° angle for your mower.



NodeMCU Board URL:
http://arduino.esp8266.com/stable/package_esp8266com_index.json


 
