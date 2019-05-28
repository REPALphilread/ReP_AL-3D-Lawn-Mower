
Description of the test sketches and what they do.
==================================================

I2C_Address_Finder
You will need to run this on the Mower Arduino MEGA to find the address of the LCD screen.  The Adress found then needs to be
inputed into the Mower code so that the MEGA can talk to the LCD screen.

Relay_Test:
If the relay is correctly wired to the MEGA the sketch turns the relay on and off at 1 second intervals.
If the relay is not working check that pin24 is really being used.  The pins are labeled so that its easily done to use the wrong pin.


Test Coms MEGA NANO:
Checks that the serial communication between the MEGA and the NANO is working.
Open the sketch in 2 seperate ARDUINO IDE editors.  then run the serial mointor of the MEGA (Baud 115200) and the NANO (Baud 9600)
If all is working well you should see the same Amps and Volts reading on each serial monitor.

Test Sonar Arrays
Checks the functionality of the SONAR array.  see the readme.txt in the folder for more details

Test Wire Function
Checks that the perimeter wire is working and setup correctly.
Upload the sketch to the Arduino MEGA.  You will need to have the perimeter wire transmitter station running and a minimum 10-20m length of wire running from it.  The amplifier and 11P ferrite sensor will also need to be installed in the mower and connected to the Arduino MEGA as shown in the wiring diagrams (A5).

Mower Blade Test Only
Checks the function of the Mower Blade Motor and motor controller
REMOVE ALL BLADES from the mower disc when running this test!

Wheel Motor Test
Checks correct operation of the rear drive wheels
