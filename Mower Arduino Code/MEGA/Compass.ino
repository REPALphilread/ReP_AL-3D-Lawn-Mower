// COMPASS FUNCTIONS
//*****************************************************************************

/* Calculates the compass heading as heading & degrees of the onboard compass */
void Get_Compass_Reading() {
  Vector norm = compass.readNormalize();
  delay(5);
  Heading = atan2(norm.YAxis, norm.XAxis);                    // Calculate heading

  // Set declination angle. Find your location declination on: http://magnetic-declination.com/
  // (+) Positive or (-) for negative,
  float Declination_Angle = (2.0 + (19.0 / 60.0)) / (180 / PI);    // Bad Krozingen is 2° 19'
  Heading += Declination_Angle;

  if (Heading < 0) {                                              // Correct for heading < 0deg and heading > 360deg
    Heading += 2 * PI;
  }
  if (Heading > 2 * PI) {
    Heading -= 2 * PI;
  }

  Compass_Heading_Degrees = Heading * 180 / M_PI;  // Convert to degrees

  Serial.print(F("Comp H:"));
  Serial.print(Heading);
  Serial.print(F(" D:"));
  Serial.print(Compass_Heading_Degrees);
  Serial.print("|");
  delay(5);
}


// Turns the Mower to the correct orientation for the optimum home wire track
// Avoiding tracking around the whole wire to get back to the docking station
void Turn_Mower_To_Home_Direction() {
    Motion_StopMotors;
    delay(1000);
    lcd.clear();
    lcd.print("Compass Home");
    delay(2000);
    Heading_Lower_Limit_Compass = Home_Wire_Compass_Heading - 8;
    Heading_Upper_Limit_Compass = Home_Wire_Compass_Heading + 8;
    Serial.println(F("********************************"));
    Serial.print(F("Home Compass Heading Target : "));
    Serial.println(Home_Wire_Compass_Heading);
    Serial.print(F("Tolerance : "));
    Serial.print(Heading_Lower_Limit_Compass);
    Serial.print(F("  :  "));
    Serial.println(Heading_Upper_Limit_Compass);
    Serial.println(F("********************************"));
    delay(2000);
    lcd.clear();
    Get_Compass_Reading();
    SetPins_ToTurnLeft(); 
    Serial.print(F("Compass Heading Now : "));
    Serial.println(Compass_Heading_Degrees);
    Serial.println(F("********************************"));
    delay(100);
    lcd.print(Compass_Heading_Degrees);
    // This spins the mower a little to ensure a true compass reading is being read (calibration).
    SetPins_ToTurnLeft();                                     // Calls the motor function turn Left
    Motion_TurnSpeed();                                       // Sets the speed of the turning motion
    delay(500);    
    Motion_StopMotors();
    Get_Compass_Reading();
    lcd.clear();
    lcd.print(Compass_Heading_Degrees);
    SetPins_ToTurnLeft();                                     // Calls the motor function turn Left
    delay(100);
    Motion_TurnSpeed();                                       // Sets the speed of the turning motion
    delay(2000);  
    Motion_StopMotors();
    Get_Compass_Reading();
    delay(500);
    lcd.clear();
    lcd.print("Compass Set");
    Motion_StopMotors();
    delay(2000);
    Turn_To_Compass_Heading();
}



void Turn_To_Compass_Heading()  {
    // Step turns the mower to the left while the heading is outside the home tolerance
    // Once the heading is found. the mower stops and can then activate the find wire function
    SetPins_ToTurnLeft(); 
    while ((Compass_Heading_Degrees < Heading_Lower_Limit_Compass) || (Compass_Heading_Degrees > Heading_Upper_Limit_Compass)) {    
        Serial.println(F("Turning to Home"));
        Get_Compass_Reading();
        lcd.setCursor(0,0);
        lcd.print("Target: ");
        lcd.print( ((Heading_Lower_Limit_Compass - Heading_Lower_Limit_Compass) / 2 ) + Heading_Lower_Limit_Compass);
        lcd.setCursor(0,1);
        lcd.print("Now: ");
        lcd.print(Compass_Heading_Degrees);
        Serial.print(F("Compass Heading Now : "));
        Serial.println(Compass_Heading_Degrees);
        Serial.println(F("****************************"));
        Motion_TurnSpeed();                                       // Sets the speed of the turning motion
        lcd.clear();
        }
    Motion_StopMotors();
    SetPins_ToGoForwards();
 }

void Display_Compass_Current_Heading_on_LCD() {
      lcd.setCursor(5, 1);
      lcd.print("    ");
      lcd.print(Compass_Heading_Degrees);
      delay(10);
}


void Activate_Compass_Functions() {
       //Get_Compass_Reading();                                     // Gets the compass direction of the mower
       if (Compass_Heading_Hold == 1) {                           // If Compass Hold is turned on in the settings
            if (MowerMotionStatus < 5) {
                Compass_Heading_Locked = 0;
                Get_Compass_Reading();
                }
            
            if (MowerMotionStatus == 5) {                         // 5 cycles are given to steady the compass reading
                Get_Compass_Reading();                            // Gets the latest compass reading
                Heading_Lock = Heading;                           // The compass heading is locked in
                Compass_Heading_Locked = 0;                       // One more cycle of normal movement
                }
                
            if (MowerMotionStatus > 5) {                          // on the 6th loop cycle 
                Compass_Heading_Locked = 1;
                Get_Compass_Reading(); 
                //Serial.print(F("Compass Lock On"));
                Compass_Heading_Hold_Func();                      // Calculate the deviation from the heading lock
                //Motion_Dynamic_PWM_Steering();                  // Not needed as the Calculate_Mowermotionstatus function will call this function
                }
        }
}

void Compass_Heading_Hold_Func() {

  //Serial.print(F("Comp:HLock"));
  //Serial.print(Heading_Lock);
  //Serial.print(F("|"));
  //Serial.print(F("   Heading Current: "));
  //Serial.println(Heading);
  //Serial.println(F("------------------------"));

  float diff = Heading - Heading_Lock;                        // Calculates the error in compass heading from the saved lock heading

  //Serial.print(F("Difference 1: "));
  //Serial.println(diff);
  
   if (diff > 180) {                                          // Make adjustments for the 360 degree system
      diff = -360 + diff;
      }
   else if (diff < -180) {
      diff = 360 + diff;
      }
 //Serial.print(F("Difference degree: "));
 //Serial.println(diff);
 
  if (diff < 0) {                                             // Steer left
    PWM_Right = PWM_MaxSpeed_RH + (CPower * diff);                  // Multiply the difference by D to increase the power then subtract from the PWM
    PWM_Left = PWM_MaxSpeed_LH;                              // Keep the Right wheel at full power calibrated to go straight
    //Serial.print(F("Compass - Turning Right    :"));
    //Serial.print(F("PWM Left :"));
    //Serial.print(PWM_Left);
    //Serial.print(F("  PWM Right :"));
    //Serial.println(PWM_Right);
    } 
  if (diff >= 0) {                                                      // Steer Right
    PWM_Right = PWM_MaxSpeed_RH;                               // Keep the Left wheel at full power calibrated to go straight             
    PWM_Left = PWM_MaxSpeed_LH -  (CPower * diff);                // Multiply the difference by D to increase the power then subtract from the PWM
    //Serial.print(F("Compass - Turning Left     : "));
    //Serial.print(F("PWM Left :"));
    //Serial.print(PWM_Left);
    //Serial.print(F("   PWM Right :"));
    //Serial.println(PWM_Right);
    }
    // Values are send to the motors in the next part of the sketch
}
