

Upload the code to the Arduino MEGA in the mower.  Ensure that the LCD is powered on and connected to the 
SCL SCA pins on the MEGA as shwon on my website.

Run the sketch and open the serial monitor.  Note down the address shown and update the MOWER code with this address

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 

The 0x27 parts needs to be updated with whatever address your LCD screen has.

