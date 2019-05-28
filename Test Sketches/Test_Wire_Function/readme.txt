     
     -------------------------------------------------------
     Make sure that the I2C address of th LCD is updated!!!
     -------------------------------------------------------
     
     
     You can use a Laptop and the Serial mointor to do this check but its better with the Mower and the LCD screen
     The LCD screen needs to be working (i.e. you know your I2C address)
     Add this I2C address to the sketch to activate the LCD screen
     This sketch is desgined to detect the boundary wire in your garden.
     Holding the mower in your hands (no motors on/no blades spinning!!) move around the garden and over the boundary wire.
     IN/OUT :  Displays if you are inside or outside of the wire loop
     MAG : Shows the magnitude of the wire signal   -ve is inside the loop  /   +ve outside the loop
     
     All OK
     ======
     You are inside the mowing area and the display shows IN & You have a -ve MAG reading in the 1000's
     You are outisde the mowing area and the LCD display shows OUT & you have a +ve MAG reading
     You are directly over the wire and you have an IN/OUT flicker and the MAG reading is low or around 0.
     
     Inside Outside Flipped
     ======================
     If you are reading IN when you hold the mower outside the loop and OUT when you are inside the loop then 
     it means your sensor and boundary wire are working (good news!), only the signal is flipped :)
     Solution: switch the boundary wires on your sender station terminals or switch the 11P ferrite sensor on the amplifier
     so the legs from the 11P ferite sensor are the other way around.
     
     Low MAG Readings
     ================
     The MAG reading is only in the 100's.  The adjust the amplifier screw so that the signal is strengthend and you now
     get readings in the 1000's Inside and Outside the Wire
     
     
     Nothing Happens
     ===============
     Check the wiring diagram again and all is connected as in the diagram.
     Check the correct pin is being used on the MEGA for the amplifier.
     Check the Amplifier has 5V power
     Check the sketch is uploaded to the perimeter wire transmitter
     Check your Garden wire loop is closed and has no breaks in it.
     Check you have enough power to the perimeter wire transmitter
     Check the continuity of all wires on the perimeter sensor
     There is a problem somehere.......    :)
