
/* Perimieter Wire Collision Motion
  ************************************************************************************/
  void Check_Wire()  {
  
  ADCMan.run();
  if (millis() >= nextTime)  {
    nextTime = millis() + 50;
    if (perimeter.isInside(0) != inside) {
      inside = perimeter.isInside(0);
      counter++;
    }
  }

  /* Prints Values to the Serial Monitor of mag, smag and signal quality.  */
  Serial.print(F("IN/OUT:"));
  //Serial.print((perimeter.isInside(0)));
  if ((perimeter.isInside(0)) == 0)  Serial.print(F("OUT|"));
  if ((perimeter.isInside(0)) == 1)  Serial.print(F("IN_|"));
  //Serial.print(F("Mag: "));
  ((int)perimeter.getMagnitude(0));
  //Serial.print(F("Smag: "));
  ((int)perimeter.getSmoothMagnitude(0));
  //Serial.print(F("     qaulity: "));
  ((perimeter.getFilterQuality(0)));

  }

  void Manage_Wire()  {
  /*If the mower is inside the perimeter fence then carry on.*/
  if ( ((perimeter.isInside(0)) == 1) && (senderOff == 0) && (Error == 0) && (Mower_Docked == 0) && (Mower_Stopped == 0))  {
    //Serial.println(F("Moving Inside the perimeter fence."));
    lcd.setCursor(7, 0);
    lcd.print("IN");
    delay(1);
    if (millis() >= nextTime)  {
      nextTime = millis() + 50;
      if (perimeter.isInside(0) != inside) {            // Check this is funny operation is found!!!!!
        inside = perimeter.isInside(0);
        counter++;
      }
    }
  Outside_Wire_Count = 0;
  }

  /*If the mower is outside the perimeter fence then turn around.  (Sender is ON, No Errors present and Perimiter is being used then...) */
  if ( ((perimeter.isInside(0)) == 0) && (senderOff == 0)  &&  (Error == 0) && (Perimeter_Wire_Mode == 1) && (Mower_Docked == 0) && (Mower_Stopped == 0) )  {
    
    ObjectRegistered = 0;                                 // Resets the Sonar count so a double backwards movement is not caused.
    Motion_StopMotors();
    delay(100);
    lcd.setCursor(7, 0);
    lcd.print("**");
    lcd.setCursor(0, 1);
    lcd.print("Outside Wire.");
    Outside_Wire_Count = Outside_Wire_Count + 1;          // Tallies the number of times the mower is outside the wire consecutivley.
    Serial.print(F("Wire#:"));             // Prints the status to the serial monitor
    Serial.print(Outside_Wire_Count);
    Serial.print(F("|"));  
    delay(2);

    // if the Mower is still in a safe condition and it doesnt seem like its backed off the wire into the flower beds for whatever reason then...
    if (Outside_Wire_Count < Outside_Wire_Count_Max) {
      lcd.setCursor(0, 8);
      lcd.print("Reversing Wire..");

      // 1. Mower Stops
      // 2. Mower Reverses.
      // 3. Mower Turns.
      // 4. Mower sets off in the new direction.
    
      // 1. Mower Stops 
      Motion_StopMotors();                                      // Motors stop wheels
      SetPins_ToGoBackwards();                                    
      delay(700);                                               // distance the mower moves backwards
      Motion_GoFullSpeed();                                     // mower reverses

    
      // 2. Reversing
      // If the battery dynamic function is switched to 0 then this delay is used all the time  
      if (Battery_Dynamic_Motion == 0) {  
        delay(3500);                                            // Standard reversing time if no dynamic battery function is used.
        lcd.setCursor(0, 8);
        lcd.print("Reversing       ");                          // indicates low voltage turn on the lcd.
        }
  
      // Dynamic Reversing depending on the voltage - High voltage can make the mower reverse too much.
      // USes the Dynamic function to give more time to turn the motors at a lower battery voltage.
      if (Battery_Dynamic_Motion == 1) {                        //checks if dynamic voltage motion is on or off
            if (BatteryVoltage >= Battery_Dynamic_Value) {
              lcd.setCursor(0, 8);
              lcd.print("Reversing V+    ");                    // indicates high voltage turn on the lcd.
              delay (Mower_Reverse_Delay);                                     // Reversing Time in seconds for higher voltage.
              }
            else {
              lcd.setCursor(0, 8);
              lcd.print("Reversing V-    ");                    // indicates low voltage turn on the lcd.
              delay(Mower_Reverse_Delay + 1000);                                      // Reversing time in seconds for lower voltage
              }
      }

      //Mower Stops reversing
      Motion_StopMotors();

      // 3. Turning
      // Standard turn if the dynamic battery motion feature is switched to 0 then this function is called.
      Serial.print(F("Turning |"));
      if ((Battery_Dynamic_Motion == 0) && (Compass_Turn_Activated == 0) ) {
        if ( (MowerMotionStatus % 2) == 0 ) {                       // Checks if the number can be evenly divided
          SetPins_ToTurnLeft();                                     // Calls the motor function turn Left
          delay(100);
          lcd.print("Turning around       ");
          Motion_TurnSpeed();                                       // Sets the speed of the turning motion
          delay(Mower_Turn_Delay_Left);                                              // delay sets how many seconds the mower turns.
          }               
  
        else {
          SetPins_ToTurnRight();                                    // if the number cant be evenly divided the it turns right.
          delay(100);
          Motion_TurnSpeed();                                       // Sets the speed of the turning motion
          delay(Mower_Turn_Delay_Right);                                              // delay sets how many seconds the mower turns
          }
      }

      if (Compass_Turn_Activated == 1) {
        Serial.println(F("-------------------------"));
        Serial.println(F("MAKING A COMPASS TURN"));
        Serial.println(F("-------------------------"));
        Motion_StopMotors();
        
        Get_Compass_Reading();
        delay(50);
        Get_Compass_Reading();
        delay(50);
        
        Heading_Lower_Limit_Compass = (Heading + 2) - 2 ;
            if (Heading_Lower_Limit_Compass > 360 ) (Heading_Lower_Limit_Compass = Heading_Lower_Limit_Compass - 360);
        Heading_Upper_Limit_Compass = (Heading + 2) + 2 ;
            if (Heading_Upper_Limit_Compass > 360 ) (Heading_Upper_Limit_Compass = Heading_Upper_Limit_Compass - 360);
        Serial.print(F("New Heading - Lower Limit :"));
        Serial.print(Heading_Lower_Limit_Compass);
        Serial.print(F("   Upper Limit : "));
        Serial.println(Heading_Upper_Limit_Compass);
        Turn_To_Compass_Heading();
        
        Motion_GoFullSpeed(); 
        delay(1000);
        Motion_StopMotors();
        
        Get_Compass_Reading();
        delay(50);
        Get_Compass_Reading();
        delay(50);
      
        Heading_Lower_Limit_Compass = (Heading + 2) - 2 ;
            if (Heading_Lower_Limit_Compass > 360 ) (Heading_Lower_Limit_Compass = Heading_Lower_Limit_Compass - 360);
        Heading_Upper_Limit_Compass = (Heading + 2) + 2 ;
            if (Heading_Upper_Limit_Compass > 360 ) (Heading_Upper_Limit_Compass = Heading_Upper_Limit_Compass - 360);
        Serial.print(F("New Heading - Lower Limit :"));
        Serial.print(Heading_Lower_Limit_Compass);
        Serial.print(F("   Upper Limit : "));
        Serial.println(Heading_Upper_Limit_Compass);
        Turn_To_Compass_Heading();
        
        
      }

      // Uses the Dynamic function to give more time to turn the motors at a lower battery voltage.
      if (Battery_Dynamic_Motion == 1) {
        if ( (MowerMotionStatus % 2) == 0 ) {                                         // Checks if the number can be evenly divided
          SetPins_ToTurnLeft();                                                       // Calls the motor funstion turn Left
          delay(200);
          Motion_TurnSpeed();                                                         // Sets the speed of the turning motion
          if (BatteryVoltage >= Battery_Dynamic_Value) delay(Mower_Turn_Delay_Left);  // checks the battery voltage and sets delay time to lower for higher battery power
          else delay(Mower_Turn_Delay_Left + 1000);                                   // if battery voltage is lower the delay time is increased. 
          }
        else {
          SetPins_ToTurnRight();                                                      // Calls the motor funstion turn right
          delay(200);
          Motion_TurnSpeed();                                                         // Sets the speed of the turning motion                                                  
          if (BatteryVoltage >= Battery_Dynamic_Value) delay(Mower_Turn_Delay_Right); // checks the battery voltage and sets delay time to lower for higher battery power
          else delay(Mower_Turn_Delay_Right + 1000);                                  // if battery voltage is lower the delay time is increased.                                   
          }
      }

      //Stops the turning
      Motion_StopMotors();
      delay(50);
      

      //4. Mower sets off in the new direction.
      SetPins_ToGoForwards();
      delay(100);
    
      MowerMotionStatus = 3;
      ADCMan.run();
      
      if (millis() >= nextTime)  {
        nextTime = millis() + 50;
        if (perimeter.isInside(0) != inside) {
        inside = perimeter.isInside(0);
        counter++;
      }

    }
   }
 }

   // As the Outside wire count has exceeded the max level it seems like the mower cant get back inside the wire and has backed itself into the plants
  // Starts a range of moves to try and get the mower back inside the wire and not damage the plants outside.
  if (Outside_Wire_Count >= Outside_Wire_Count_Max) {
      lcd.clear();
      lcd.print("OUT OF WIRE!");
      Motion_StopMotors();                        // Stop the wheel drive motors.
      StopSpinBlades();                           // Stop the cutting blade spinning.
      delay(10000);                               // give time for the blades to stop
      Outside_Wire_ReFind_Function();             // Start the Algorythm to get the mower back inside the wire
      lcd.clear();
  }
}

/* Check that boundary wire is turned on
************************************************************************************/
void TestforBoundaryWire()  {
  if (millis() >= nextTime)  {
    nextTime = millis() + 50;
    if (perimeter.isInside(0) != inside) {
      inside = perimeter.isInside(0);
      counter++;
    }
  }

  if (Perimeter_Wire_Mode == 1) {                                               // Perimeter use is ON - Perimter_USE can be turned on or off in the setup.

    /*Checks to see if the boundary wire is turned OFF.
      uses the mag field calculated. Between -50 and 50 normally the field is off.     */

    MAG_Now = perimeter.getMagnitude(0);
    if ( (MAG_Now > -20 ) && (MAG_Now < 20 )  ) {
      senderOff = 1;
      Error = 6;
      MowerMotionStatus = 1;
      }

    /* Checks to see that the boundary fence is turned ON.
      uses the mag field. under -50 or above 50 means the field is on.*/
    if (   (MAG_Now < -50 ) || (MAG_Now > 50 )  ) {
      senderOff = 0;
      }

    Serial.print(F("Wire"));
    Serial.print(F(":"));
    if (senderOff == 0) Serial.print(F("ON|"));
    if (senderOff == 1) Serial.print(F("OFF|"));
    Serial.print(F("Mag:"));
    Serial.print(MAG_Now);
    Serial.print("|");
  }

  if (Perimeter_Wire_Mode == 0) {                                               // Perimeter use is OFF - Perimter_USE can be turned on or off in the setup.
    Serial.println(F("TEST MODE : Perimeter Wire Sensor on Mower not in use "));
    senderOff = 0;

  }
}

/* Read Boundary Wire
************************************************************************************/
void UpdateWireSensor()   {
  if (millis() >= nextTime)  {
    nextTime = millis() + 50;
    if (perimeter.isInside(0) != inside) {
      inside = perimeter.isInside(0);
      counter++;
    }
  }
}
