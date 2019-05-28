Wheel Motor Test
----------------

Remove all cutting blades before testing!!
Update your LCD I2C address.

This sketch tests the function of the rear wheel drive motors.
If the mower turns opposite to the direction shown change the setting

bool Reverse_Steering           = 1;   

to either 1 or 0.


Not Working
-----------
- Check the correct wiring of the motors to the motor driver.
- Check there are no loose wires or connections at the Arduino Pins
- Ensure the wheel motors are not jammed by too long screws attaching it to the wheel arch.
- Check jumpers are removed/installed on the motor bridge
- Check the pins are correctly plugged into the Arduino
- Check you have a 12V supply to the motor driver (relay working? switch off?)
- Check the 12V circuit diagram and test for a 12V supply voltage on the motor driver.
- Check 12V +ve and -ve wires are correct.



