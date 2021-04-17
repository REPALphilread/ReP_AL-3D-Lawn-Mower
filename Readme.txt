ReP_AL-3D-Lawn-Mower
Code and Files for the ReP_AL 3D Printed Lawn Mower
---------------------------------------------------

All build instructions and the latest STL files are found at

www.repalmakershop.com


Arduino Code
------------
The mower software is in the folder Mower Arduino Code:  
PLEASE ALWAYS USE THE LATEST VERSION OF THE CODE

Upload the MEGA code to the Arduino MEGA
Upload the Nano code to the Arduino Nano
Upload the NodeMCU code to the NodeMCU Board   (includes new code)
Upload the TFT Code to the TFT MEGA Shield
Upload the ESP32_Rover Code to the ESP32 Board (GPS)
Upload the BMP Files to the TFT SD Card


(I needed to use the "old bootloader" option in the Arduino IDE to get the sketch to upload to the NANO)
Perimeter Wire - Sender_station_V1 needs to be uploaded to the Arduino in the perimeter wire transmitter.


Perimeter Wire Transmitter
--------------------------

Upload the code from this folder to the wire transmitter


Libraries
---------
All the libraries I used for the Arduino Code can be found in this folder.
Ensure these are installed in the Arduino libraries folder otherwise the main code wont compile


Test sketches folder
--------------------
They are designed to test the indiviual components in your build to see if they are working. 
Ihe idea is to debug the components indicudually so you are faster in completing the project.




----------------------------------------------
All my work falls under the GNU Public License
----------------------------------------------
