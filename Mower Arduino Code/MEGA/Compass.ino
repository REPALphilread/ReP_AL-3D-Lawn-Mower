// COMPASS FUNCTIONS
//*****************************************************************************


/* Calculates the compass heading as heading & degrees of the onboard compass */
void Get_Compass_Reading() {

  // If the Compass is activated
  if (Compass_Activate == 1) {
  
          // displays a star on the LCD to show compass is being used.
          if (LCD_Screen_Keypad_Menu == 1) lcd.setCursor(7, 0);
          if (LCD_Screen_Keypad_Menu == 1) lcd.print("*");

          // Gets the compass data depending on which method is selected    
          if (Compass_Detected == 1) Get_DFRobot_HMC5883L_Reading();
          if (Compass_Detected == 2) Get_DFRobot_QMC5883_Reading(); 
          if (Compass_Detected == 3) Get_Manuel_QMC5883_Reading();                                               
          if (Compass_Detected == 4) Get_QMC5883L_Reading();
          
          if (LCD_Screen_Keypad_Menu == 1) lcd.setCursor(7, 0);
          if (LCD_Screen_Keypad_Menu == 1) lcd.print("/");

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

          Serial.print(F("Comp°:"));
          Serial.print(Compass_Heading_Degrees);
          Serial.print("|");
          delay(5);
          if (LCD_Screen_Keypad_Menu == 1) lcd.setCursor(7, 0);
          if (LCD_Screen_Keypad_Menu == 1) lcd.print(" ");
          delay(100);
          }
}


void Get_DFRobot_HMC5883L_Reading() {
   //long x = micros();
   Vector norm = compass.readNormalize();
   delay(30);
   Heading = atan2(norm.YAxis, norm.XAxis);                            // Calculate heading
   }

void Get_DFRobot_QMC5883_Reading() {
   //long x = micros();
   Vector norm = compass.readNormalize();
   delay(30);
   Heading = atan2(norm.YAxis, norm.XAxis);                            // Calculate heading
   }


void Get_Manuel_QMC5883_Reading() {
  
  Serial.println(F("Use DF Robot and GY282"));

}


void Get_QMC5883L_Reading() {
    int x, y, z;
    Heading = compass2.readHeading();
    Heading = atan2(y, x);                          //Calculate Heading in Radians.
    }




// Turns the Mower to the correct orientation for the optimum home wire track
// Avoiding tracking around the whole wire to get back to the docking station
void Compass_Turn_Mower_To_Home_Direction() {
    //Stop the motors.
    Motor_Action_Stop_Motors;
    delay(2000);
    Print_LCD_Compass_Home();
    delay(1000);
    Compass_Target = Home_Wire_Compass_Heading;
    lcd.clear();
    // Reverse the mower a little
    SetPins_ToGoBackwards();
    Motor_Action_Go_Full_Speed();
    delay(800);
    Motor_Action_Stop_Motors;  
    Get_Compass_Reading();
    SetPins_ToTurnLeft(); 
    // This spins the mower a little to ensure a true compass reading is being read (calibration).
    SetPins_ToTurnLeft();                                     // Calls the motor function turn Left
    Motor_Action_Turn_Speed();                                       // Sets the speed of the turning motion
    delay(500);    
    Motor_Action_Stop_Motors();
    Get_Compass_Reading();
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
    Get_Compass_Reading();
    delay(2000);
    Turn_To_Compass_Heading();
}


void Turn_To_Compass_Heading() {

    Serial.println("");
    Serial.println("- - - - - - - - -");
    Serial.println(F("Compass Home 2 Activated"));
    delay(1000); 
    
    // Print info to LCD
    lcd.setCursor(0,0);
    lcd.print("Target: ");
    lcd.print(Compass_Target);

    // Print to Serial Monitor
    Serial.print("Compass Target : ");
    Serial.println(Compass_Target);   

    // Sets the boundaries for the error of compass accurcy required.
    Heading_Lower_Limit_Compass = Compass_Target - 5;
    Heading_Upper_Limit_Compass = Compass_Target + 5;

    int Attemps_Compass_Turn = 0;
    float Compass_Last = 0;
    int Bad_Reading = 0;

    if (Compass_Target < 180) {
    
    Serial.println("Compass Target < 180 logic used");
    float Limit = Compass_Target + 180;
    Serial.print("Left Turn Limit : ");
    Serial.print(Compass_Target);
    Serial.print(" to ");
    Serial.println(Limit);

    Serial.print("Right Turn Limit : ");
    Serial.print(Limit);
    Serial.print(" to 360° & 0 to ");
    Serial.println(Compass_Target);

    Get_Compass_Reading();
    delay(500);
    Get_Compass_Reading();
    delay(500);
    
    while ((Compass_Heading_Degrees < Heading_Lower_Limit_Compass) || (Compass_Heading_Degrees > Heading_Upper_Limit_Compass) && (Attemps_Compass_Turn < 40) && (Bad_Reading < 5))  { 

      delay(200);
      Get_Compass_Reading();
      
      // Double check if the compass reading retunred is plausable.
      if (Attemps_Compass_Turn > 5) {
        if (Compass_Heading_Degrees - Compass_Last > 50) {
          Serial.print("Bad Compass Reading ");
          Serial.print("Compass Heading Degrees = ");
          Serial.print(Compass_Heading_Degrees);
          Serial.print("  Compass Last = ");
          Serial.print(Compass_Last);
          Serial.print("  Degrees - Last = ");
          Serial.println(Compass_Heading_Degrees - Compass_Last);
          
          Bad_Reading = Bad_Reading + 1;
          lcd.setCursor(15,1);
          lcd.print("x");
          Get_Compass_Reading;
          delay(100);
          }
        else {
          lcd.setCursor(15,1);
          lcd.print("o");  
        }
        
      }
      Compass_Last = Compass_Heading_Degrees;    // sotres the last good compass reading


      
      delay(100);
      Serial.print("Compass Heading : ");
      Serial.print(Compass_Heading_Degrees);
      Serial.print("|");
      
      if ( (Compass_Heading_Degrees  > Compass_Target) && (Compass_Heading_Degrees < Limit) )  {
          SetPins_ToTurnLeft(); 
          Serial.print(F("Spin Left"));
          Serial.print(F("|"));  
          delay(100);
          }
      if ( ((Compass_Heading_Degrees > Limit) && (Compass_Heading_Degrees < 360)) || ( (Compass_Heading_Degrees > 0) && (Compass_Heading_Degrees < Compass_Target)) ) {
          SetPins_ToTurnRight(); 
          Serial.print(F("Spin Right"));
          Serial.print(F("|")); 
          delay(100); 
          }

      
      // Turn the mower and get the compass reading
      Motor_Action_Turn_Speed();                                       // Sets the speed of the turning motion
      delay(100);
      Get_Compass_Reading;
      Motor_Action_Turn_Speed();                                       // Sets the speed of the turning motion
      delay(100);
      Get_Compass_Reading;
      Motor_Action_Stop_Motors();
      lcd.setCursor(0,1);
      lcd.print(Compass_Heading_Degrees);
    
      
      Attemps_Compass_Turn = Attemps_Compass_Turn + 1;
      Serial.print("Atempts:");
      Serial.print(Attemps_Compass_Turn);
      Serial.print("|");
      Serial.println("");
    }
    }

if (Compass_Target >= 180) {
    
    Serial.println("Compass Target > 180 logic used");
    
    float Limit = Compass_Target - 180;

    Serial.print("Left Turn Limit : ");
    Serial.print(Compass_Target);
    Serial.print(" to 360° & 0 to ");
    Serial.println(Limit);
    
    Serial.print("Right Turn Limit : ");
    Serial.print(Compass_Target);
    Serial.print(" to ");
    Serial.println(Limit);

    while ((Compass_Heading_Degrees < Heading_Lower_Limit_Compass) || (Compass_Heading_Degrees > Heading_Upper_Limit_Compass) && (Attemps_Compass_Turn < 40) && (Bad_Reading < 5))  { 

      delay(200);
      Get_Compass_Reading();
      
      // Double check if the compass reading returned is plausable.
      if (Attemps_Compass_Turn > 5) {
        if (Compass_Heading_Degrees - Compass_Last > 50){
          Serial.println("Bad Compass Reading");
          Bad_Reading = Bad_Reading + 1;
          lcd.setCursor(15,1);
          lcd.print("x");
          Get_Compass_Reading;
          delay(100);
          }
        else {
          lcd.setCursor(15,1);
          lcd.print("o");  
        }
        
      }
      Compass_Last = Compass_Heading_Degrees;    // sotres the last good compass reading


      
      delay(100);
      Serial.print("Compass Heading : ");
      Serial.print(Compass_Heading_Degrees);
      Serial.print("|");

      if ( ((Compass_Heading_Degrees > Compass_Target) && (Compass_Heading_Degrees < 360)) || ( (Compass_Heading_Degrees > 0) && (Compass_Heading_Degrees < Limit)) ) {
          SetPins_ToTurnLeft(); 
          Serial.print(F("Spin Left"));
          Serial.print(F("|")); 
          delay(100); 
          }
      if ( (Compass_Heading_Degrees  > Limit) && (Compass_Heading_Degrees < Compass_Target) )  {
          SetPins_ToTurnRight(); 
          Serial.print(F("Spin Right"));
          Serial.print(F("|"));  
          delay(100);
          }

      Motor_Action_Turn_Speed();                                       // Sets the speed of the turning motion
      delay(100);
      Get_Compass_Reading;
      delay(100);
      Motor_Action_Turn_Speed();                                       // Sets the speed of the turning motion
      delay(100);
      Get_Compass_Reading;
      Motor_Action_Stop_Motors();

      Attemps_Compass_Turn = Attemps_Compass_Turn + 1;
      Serial.print("Atempts:");
      Serial.print(Attemps_Compass_Turn);
      Serial.print("|");
      Serial.println("");
     }
    }   

 if (Bad_Reading > 5)  {
    lcd.clear();
    lcd.print("Bad Compass Readings");
    lcd.setCursor(0,1);
    lcd.print("Restarting");
    delay(1000);
    SetPins_ToTurnLeft();                                     // Calls the motor function turn Left
    Motor_Action_Turn_Speed();                                       // Sets the speed of the turning motion
    delay(100);  
    Get_Compass_Reading;   
    SetPins_ToTurnLeft();                                     // Calls the motor function turn Left
    Motor_Action_Turn_Speed();                                       // Sets the speed of the turning motion
    delay(100);  
    Get_Compass_Reading;   
    SetPins_ToTurnLeft();                                     // Calls the motor function turn Left
    Motor_Action_Turn_Speed();                                       // Sets the speed of the turning motion
    delay(100);  
    Get_Compass_Reading;   
    Turn_To_Compass_Heading();
}

}


void Display_Compass_Current_Heading_on_LCD() {
      lcd.setCursor(5, 1);
      lcd.print("    ");
      lcd.print(Compass_Heading_Degrees);
      delay(10);
}



void Calculate_Compass_Wheel_Compensation() {

  float Compass_Error = Compass_Heading_Degrees - Heading_Lock;        // Calculates the error in compass heading from the saved lock heading
  
  if (Compass_Error > 180) Compass_Error = Compass_Error * - 1 ;
  if (Compass_Error < -180) Compass_Error = Compass_Error * - 1 ;
  Serial.print(F("C_Err:"));
  Serial.print(Compass_Error);
  Serial.print(F("|"));
 
  if (Compass_Error < 0) {                                             // Steer left
     Serial.print(F("SR|"));
    
    
    // With no adjustment of wheel speed according to MAG Level    
    if (MAG_Speed_Adjustment == 0) {
      PWM_Left = PWM_MaxSpeed_LH;         
      PWM_Right = PWM_MaxSpeed_RH + (CPower * Compass_Error);            // Multiply the difference by D to increase the power then subtract from the PWM
      if (PWM_Right < 0) PWM_Right = PWM_MaxSpeed_RH - 50;
      }
    
    if (MAG_Speed_Adjustment == 1) {
      // MAX MAG Speed Left Hand Wheel
      if (MAG_Now >= Slow_Speed_MAG)  {
        PWM_Left = PWM_MaxSpeed_LH;
        PWM_Right = PWM_MaxSpeed_RH + (CPower * Compass_Error);            // Multiply the difference by D to increase the power then subtract from the PWM
        if (PWM_Right < 0) PWM_Right = PWM_MaxSpeed_RH - 50; 
      }
      if (MAG_Now < Slow_Speed_MAG)   {
        PWM_Left = PWM_Slow_Speed_LH;
        PWM_Right = PWM_Slow_Speed_RH + ((CPower/2) * Compass_Error);            // Multiply the difference by D to increase the power then subtract from the PWM
        if (PWM_Right < 0) PWM_Right = PWM_Slow_Speed_RH - 20; 
      }
    
      }
    Compass_Steering_Status = 2;
    } 




    
  if (Compass_Error >= 0) {  
    Serial.print(F("SL|"));

    // With no adjustment of wheel speed according to MAG Level
    if (MAG_Speed_Adjustment == 0) {
      PWM_Right = PWM_MaxSpeed_RH; 
      PWM_Left = PWM_MaxSpeed_LH -  (CPower * Compass_Error);            // Multiply the difference by D to increase the power then subtract from the PWM
      if (PWM_Left < 0) PWM_Left = PWM_MaxSpeed_LH - 50;
      }
    
    if (MAG_Speed_Adjustment == 1) {
      // MAX MAG Speed Right Hand Wheel
      if (MAG_Now >= Slow_Speed_MAG)  {
        PWM_Right = PWM_MaxSpeed_RH; 
        PWM_Left = PWM_MaxSpeed_LH -  (CPower * Compass_Error);            // Multiply the difference by D to increase the power then subtract from the PWM
        if (PWM_Left < 0) PWM_Left = PWM_MaxSpeed_LH - 50;
        }
      if (MAG_Now < Slow_Speed_MAG)   {
        PWM_Right = PWM_Slow_Speed_RH;
        PWM_Left = PWM_Slow_Speed_LH -  ((CPower/2) * Compass_Error);            // Multiply the difference by D to increase the power then subtract from the PWM
        if (PWM_Left < 0) PWM_Left = PWM_Slow_Speed_LH - 20;
      }
    
      }
    Compass_Steering_Status = 3;
    }

}
