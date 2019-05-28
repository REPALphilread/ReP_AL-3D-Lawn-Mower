// COMPASS FUNCTIONS
//*****************************************************************************

/* Calculates the compass heading as heading & degrees of the onboard compass */
void Get_Compass_Reading() {
  Vector norm = compass.readNormalize();
  delay(5);
  Heading = atan2(norm.YAxis, norm.XAxis);                    // Calculate heading

  // Set declination angle. Find your location declination on: http://magnetic-declination.com/
  // (+) Positive or (-) for negative,
  Declination_Angle = (2.0 + (19.0 / 60.0)) / (180 / PI);    // Bad Krozingen is 2° 19'
  Heading += Declination_Angle;

  if (Heading < 0) {                                              // Correct for heading < 0deg and heading > 360deg
    Heading += 2 * PI;
  }
  if (Heading > 2 * PI) {
    Heading -= 2 * PI;
  }

  Compass_Heading_Degrees = Heading * 180 / M_PI;  // Convert to degrees

  Serial.print("Heading = ");
  Serial.print(Heading);
  Serial.print("  /  Degress = ");
  Serial.print(Compass_Heading_Degrees);
  Serial.println();
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
    int Home_Wire_Lower_Compass = Home_Wire_Compass_Heading - 8;
    int Home_Wire_Upper_Compass = Home_Wire_Compass_Heading + 8;
    Serial.println("********************************");
    Serial.print("Home Compass Heading Target : ");
    Serial.println(Home_Wire_Compass_Heading);
    Serial.print("Tolerance : ");
    Serial.print(Home_Wire_Lower_Compass);
    Serial.print("  :  ");
    Serial.println(Home_Wire_Upper_Compass);
    Serial.println("********************************");
    delay(2000);
    lcd.clear();
    Get_Compass_Reading();
    SetPins_ToTurnLeft(); 
    Serial.print("Compass Heading Now : ");
    Serial.println(Compass_Heading_Degrees);
    Serial.println("********************************");
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
    SetPins_ToTurnLeft();    // Calls the motor function turn Left
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
    
    SetPins_ToTurnLeft(); 
    // Step turns the mower to the left while the heading is outside the home tolerance
    // Once the heading is found. the mower stops and can then activate the find wire function
    while ((Compass_Heading_Degrees < Home_Wire_Lower_Compass) || (Compass_Heading_Degrees > Home_Wire_Upper_Compass)) {    
        Serial.println("Turning to Home");
        Get_Compass_Reading();
        delay(500);
        lcd.print(Compass_Heading_Degrees);
        Serial.print("Compass Heading Now : ");
        Serial.println(Compass_Heading_Degrees);
        Serial.println("********************************");
        SetPins_ToTurnLeft();
        delay(10);
        Motion_TurnSpeed();                                       // Sets the speed of the turning motion
        delay(300);    
        Motion_StopMotors();
        delay(500);
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



