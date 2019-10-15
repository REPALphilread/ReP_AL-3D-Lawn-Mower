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

To adjust the spirals and parallel parameters please change the values in the pattern mow tab.
The variables are declared at the start of the subroutine.

For Spiral    

int End_Linking       is the distance between spirals


For Parallel    (under development)

1. Adjust the Turn_90_Delay so that the mower turns roughly 90° when turning Left & Right

Line_Length_Cycles  = the distance the mower travels in a "straight" line 

Turning_Compass_Assist = 0   (this tries to use the compass to ensure the mower turns 90° but currently it doesnt work well=


NodeMCU Board URL:
http://arduino.esp8266.com/stable/package_esp8266com_index.json


 
