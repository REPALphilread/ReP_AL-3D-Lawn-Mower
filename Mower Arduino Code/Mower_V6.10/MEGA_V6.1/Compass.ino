// COMPASS FUNCTIONS
//*****************************************************************************

/* Calculates the compass heading as heading & degrees of the onboard compass */
void Get_Compass_Reading() {
  Vector norm = compass.readNormalize();
  delay(5);
  Heading = atan2(norm.YAxis, norm.XAxis);                        // Calculate heading

  // Set declination angle. Find your location declination on: http://magnetic-declination.com/
  // (+) Positive or (-) for negative,
  float Declination_Angle = (2.0 + (19.0 / 60.0)) / (180 / PI);   // Bad Krozingen is 2° 19'
  Heading += Declination_Angle;

  if (Heading < 0) {                                              // Correct for heading < 0deg and heading > 360deg
    Heading += 2 * PI;
    }
  if (Heading > 2 * PI) {
    Heading -= 2 * PI;
    }

  Compass_Heading_Degrees = Heading * 180 / M_PI;                 // Convert to degrees
  //Serial.print(F("Comp H:"));
  //Serial.print(Heading);
  Serial.print(F("Comp°:"));
  Serial.print(Compass_Heading_Degrees);
  Serial.print("|");
  delay(5);
}


// Turns the Mower to the correct orientation for the optimum home wire track
// Avoiding tracking around the whole wire to get back to the docking station
void Compass_Turn_Mower_To_Home_Direction() {
    Motor_Action_Stop_Motors;
    delay(1000);
    Print_LCD_Compass_Home();
    delay(2000);
    Compass_Target = Home_Wire_Compass_Heading;
    Print_LCD_Heading_for_Home();
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
    Motor_Action_Turn_Speed();                                       // Sets the speed of the turning motion
    delay(500);    
    Motor_Action_Stop_Motors();
    Get_Compass_Reading();
    lcd.clear();
    lcd.print(Compass_Heading_Degrees);
    SetPins_ToTurnLeft();                                     // Calls the motor function turn Left
    delay(100);
    Motor_Action_Turn_Speed();                                       // Sets the speed of the turning motion
    delay(2000);  
    Motor_Action_Stop_Motors();
    Get_Compass_Reading();
    delay(500);
    lcd.clear();
    lcd.print("Compass Set");
    Motor_Action_Stop_Motors();
    delay(2000);
    Turn_To_Compass_Heading();
}


void Turn_To_Compass_Heading()  {
    // Step turns the mower to the left while the heading is outside the home tolerance
    // Once the heading is found. the mower stops and can then activate the find wire function
    
    lcd.setCursor(0,0);
    lcd.print("Target: ");
    lcd.print(Compass_Target);
    lcd.setCursor(0,1);
    lcd.print("Now:");
    lcd.setCursor(0,4);
    Heading_Lower_Limit_Compass = Compass_Target - 3;
    Heading_Upper_Limit_Compass = Compass_Target + 3;

    // Continue to turn the mower while the compass is measuring degrees outiside these points.
    //while ((Compass_Heading_Degrees < Heading_Lower_Limit_Compass) || (Compass_Heading_Degrees > Heading_Upper_Limit_Compass) && (Mower_Parked == 0)) {    
    for (int i = 0; i <= 1; i++) {
    while ((Compass_Heading_Degrees < Heading_Lower_Limit_Compass) || (Compass_Heading_Degrees > Heading_Upper_Limit_Compass)) {    
        Serial.print(F("Turning to Target:"));
        Serial.print(Compass_Target);
        Serial.print(F("|"));
        Get_Compass_Reading();
        delay(5);
        lcd.print("   ");
        lcd.print(Compass_Heading_Degrees);
        Serial.println("");
        float Compass_Error;
        Compass_Error = Compass_Heading_Degrees - Compass_Target;
        Serial.print("Error:");
        Serial.print(Compass_Error);
        Serial.print(F("|"));        
        if ( Compass_Error < 0) {
          SetPins_ToTurnRight(); 
          Serial.print("Spin Right");
          Serial.print(F("|"));  
          }
        if ( Compass_Error > 0) {
          SetPins_ToTurnLeft(); 
          Serial.print("Spin Left");
          Serial.print(F("|"));  
        }
        if (Compass_Error < 5)   Turn_Adjust = 100;
        if (Compass_Error < 10)  Turn_Adjust = 90;
        if (Compass_Error < 50)  Turn_Adjust = 80;
        if (Compass_Error < 180) Turn_Adjust = 20;
        
        Motor_Action_Turn_Speed();                                       // Sets the speed of the turning motion
        //if ((WIFI_Enabled == 1) && (Manuel_Mode == 0)) Get_WIFI_Commands();
        }
    Get_Compass_Reading();
    delay(5);
    Get_Compass_Reading();
    }

    
   
    // Once the while loop is satisfied (compass measures a degree between Lower and Upper, stop the mower
    Motor_Action_Stop_Motors();
    Turn_Adjust = 0;
    SetPins_ToGoForwards();
    lcd.print("Found");
    delay(1000);
    lcd.clear();
 }

void Display_Compass_Current_Heading_on_LCD() {
      lcd.setCursor(5, 1);
      lcd.print("    ");
      lcd.print(Compass_Heading_Degrees);
      delay(10);
}



void Calculate_Compass_Wheel_Compensation() {

  float Compass_Error = Compass_Heading_Degrees - Heading_Lock;        // Calculates the error in compass heading from the saved lock heading
  
  if (Compass_Error > 180) Compass_Error = Compass_Error * -1 ;
  if (Compass_Error < -180) Compass_Error = Compass_Error * -1 ;
  Serial.print(F("C_Err:"));
  Serial.print(Compass_Error);
  Serial.print("|");
 
  if (Compass_Error < 0) {                                             // Steer left
     Serial.print("Steer_Right|");
    PWM_Right = PWM_MaxSpeed_RH + (CPower * Compass_Error);            // Multiply the difference by D to increase the power then subtract from the PWM
    if (PWM_Right < 0) PWM_Right = PWM_MaxSpeed_RH - 50;
    PWM_Left = PWM_MaxSpeed_LH;                                        // Keep the Right wheel at full power calibrated to go straight
    } 
  if (Compass_Error >= 0) {  
    Serial.print("Steer_Left|");
    PWM_Right = PWM_MaxSpeed_RH;                                       // Keep the Left wheel at full power calibrated to go straight             
    PWM_Left = PWM_MaxSpeed_LH -  (CPower * Compass_Error);            // Multiply the difference by D to increase the power then subtract from the PWM
    if (PWM_Left < 0) PWM_Left = PWM_MaxSpeed_LH - 50;
    }

}
