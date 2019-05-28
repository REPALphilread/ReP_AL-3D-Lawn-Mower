    SONAR TESTING SKETCH
    ==========================================

    -------------------------------------------------------
    Make sure that the I2C address of th LCD is updated!!!
    -------------------------------------------------------
    
    This test sketch will check the installation of the Sonar Array.  
    Load this to the MEGA in the mower with the sonar array wired up.
    
    It is very important that the Sonar array works correctly.  1. to avoid stuff and 2. if the sonar is not working
    correctly it will increase the loop time of the software considerably.

    The software will wait for the sonar to ping.  If there is no return signal the software will wait around looking for it.
    This is not good for the performance of the mower.  It needs to detect wires etc immediatley.

    In the setup you can turn on or off the individual sonars.
    
    1 = ON    0 = OFF
    bool Sonar_1_Activat            = 1;                        
    bool Sonar_2_Activate           = 1;                         
    bool Sonar_3_Activate           = 1; 
    

    LCD Displays following
    Sonar 2       Sonar 1         Sonar  3
    distance 2    distance 1      distance 3
    
    All OK
    ======
    If you place your hand in front of each sonar the distance decraeses on the correspoding LCD display
    this happens for all 3 sonars and the position of the sonar reading on the LCD corresponds to the sonar module
    being tested.

    Sonar registers but the LCD display changes in the wrong place.
    ===============================================================
    Your wiring is switched.  Pleaese check the Tri and Echo pins for each sonar are connected to the right PIN
    on the MEGA.  If you run like this the mower will turn into the obsticle its trying to avoid

    SONAR Reads 999
    ===============
    The sonar signal is not being read by the software.  
      Check wiring  (refernec diagram on the website)
      Check 5V is present at that sonar
      Check continuity on all the wires from the MEGA pin to the pin on the Sonar module
      Check there is not wiggle contact (pin is not sitting correctly in the plug)
      Check that Trig and Echo pins are not mixed up.
      Check...check...check....
