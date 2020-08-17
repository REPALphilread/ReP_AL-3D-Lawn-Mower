// Manouvers are a set of motion functions or motor actions that are regulary called
// e.g. Turn the mower around






// Moves the Mower Forwards in the garden and activates compass features if enabled
void Manouver_Mow_The_Grass() {

    Motor_Action_Spin_Blades();
    SetPins_ToGoForwards();

    Loop_Cycle_Mowing = (Loop_Cycle_Mowing + 1);
    Serial.print(F("Loop:"));
    Serial.print(Loop_Cycle_Mowing);
    Serial.print(F("|"));
    lcd.setCursor(13, 1);
    lcd.print(Loop_Cycle_Mowing);
    delay(1);
  
  if (Loop_Cycle_Mowing < 5  )  {                       

    // If the GYRO is activated the compass will be ignored and the mower uses the GYRO instead.
    if ((Compass_Activate == 1) && (Compass_Heading_Hold_Enabled == 1) && (GYRO_Enabled == 0) ) {
        Serial.print(F("C-Lock:OFF"));
        Serial.print(F("|"));
        if (LCD_Screen_Keypad_Menu == 1)  Print_LCD_Mowing();
        Get_Compass_Reading();
        Motor_Action_Go_Mowing_Speed();
        Compass_Heading_Locked = 0;                           // Turn off the compass heading lock for the new cycles
        Compass_Steering_Status = 0;
        }

    if (GYRO_Enabled == 1);
        Serial.print(F("G-Lock:OFF"));
        Serial.print(F("|"));
        if (LCD_Screen_Keypad_Menu == 1)  Print_LCD_Mowing();
        Get_GYRO_Reading();
        Motor_Action_Go_Mowing_Speed();
        GYRO_Heading_Locked = 0;                           // Turn off the compass heading lock for the new cycles
        GYRO_Steering_Status = 0;
        }   

  // On the 5th Mowing cycle options are chosen how to Mow based on the settings of pattern mow
  // Compass assistance etc.
  
  if (Loop_Cycle_Mowing == 5)   {

    // Normal Random Mowing
    if (Pattern_Mow == 0) {
        
        // Normal Random Mowing no compass Assistance
        if ((Compass_Heading_Hold_Enabled == 0) && (GYRO_Enabled == 0)) {
          Serial.print(F("C-Lock:OFF"));
          Serial.print(F("|"));
          if (LCD_Screen_Keypad_Menu == 1) Print_LCD_Compass_Mowing();
          Motor_Action_Go_Mowing_Speed();
          Compass_Heading_Locked = 0;
          }

        // Normal Random Mowing no GYRO Assistance
        if (GYRO_Enabled == 0) {
          Serial.print(F("GYRO:OFF"));
          Serial.print(F("|"));
          Motor_Action_Go_Mowing_Speed();
          GYRO_Heading_Locked = 0;
          }          

        // Normal Random Mowing with Compass Assitnace turned on.
        // If the GYRO is turned on then the compass will be ignored and the angle will come from the GYRO
        if ((Compass_Heading_Hold_Enabled == 1) && (Compass_Activate == 1) && (GYRO_Enabled == 0) )  {
           Get_Compass_Reading();                                                      // Gets the latest compass reading
           Heading_Lock = Compass_Heading_Degrees;                                     // saves this compass reading to the heading lock
           Compass_Heading_Locked = 1;                                                 // Turns on the heading lock feature
           Motor_Action_Go_Mowing_Speed();
           }
        if (GYRO_Enabled == 1) {
           Get_GYRO_Reading();                                                      // Gets the latest compass reading
           GYRO_Heading_Locked = 1;                                                 // Turns on the heading lock feature
           Motor_Action_Go_Mowing_Speed();    
           }
        else {
          Motor_Action_Go_Mowing_Speed();
          }
      }

    if (Pattern_Mow == 1)  {                                  
        Motor_Action_Go_Mowing_Speed();
        if (LCD_Screen_Keypad_Menu == 1) Print_LCD_Parallel();
        Serial.print("Parallel:ON");
        Serial.print(F("|"));

        if ((Compass_Heading_Hold_Enabled == 1) && (Compass_Activate == 1))  {         // use the heading hold funtion for Parallel Mowing
           Get_Compass_Reading();                                                      // Gets the latest compass reading
           Heading_Lock = Compass_Heading_Degrees;                                     // saves this compass reading to the heading lock
           Compass_Heading_Locked = 1;                                                 // Turns on the heading lock feature
           Motor_Action_Go_Mowing_Speed();
           }
        else {
          Motor_Action_Go_Mowing_Speed();                                                // if the compass is not activated
          Serial.println("Compass not activated in the settings");
          }
        
        }

    // Sets up the variables so that a spiral mow pattern is activated.
    if (Pattern_Mow == 2)  {                                  
        Compass_Heading_Locked = 0;                   // Compass Lock is switched off                 
        if (LCD_Screen_Keypad_Menu == 1) Print_LCD_Spiral();
        Serial.print("Spiral:ON");
        Serial.print(F("|"));
        Motor_Action_Go_Mowing_Speed();
        }

  }  // end of statements for == 5



  // Based on the settings above the Mower will continue to mow with the following actions
  if (Loop_Cycle_Mowing > 5) {
      
      // Normal Random Mowing
      if (Pattern_Mow == 0) {
         if ((Compass_Heading_Locked == 0) && (GYRO_Enabled == 0)) {
           lcd.setCursor(0, 1);  
           Serial.print(F("C-Lock:OFF"));
           Serial.print(F("|"));
           if (LCD_Screen_Keypad_Menu == 1) lcd.print("Mowing          ");
           Motor_Action_Go_Mowing_Speed();
           Compass_Steering_Status = 0;                                             // TFT Information
           }
        if ((GYRO_Heading_Locked == 0) && (GYRO_Enabled == 0)) {
           lcd.setCursor(0, 1);  
           Serial.print(F("G-Lock:OFF"));
           Serial.print(F("|"));
           if (LCD_Screen_Keypad_Menu == 1) lcd.print("Mowing          ");
           Motor_Action_Go_Mowing_Speed();
           Compass_Steering_Status = 0;
           }
           
        if ((Compass_Heading_Hold_Enabled == 1) && (Compass_Activate == 1) && (GYRO_Enabled == 0)) {            // if the Mower is tracking using the compass steer here
          if ( (Loop_Cycle_Mowing % 2) == 0 ) {
          Get_Compass_Reading(); 
          Compass_Steering_Status = 1;        
          Calculate_Compass_Wheel_Compensation();
          Motor_Action_Dynamic_PWM_Steering();              // Removes the full speed function if the mower is trying to hold to the compass heading.
          if (LCD_Screen_Keypad_Menu == 1) Print_LCD_Compass_Mowing();
          Serial.print(F("C-Lock:ON_"));
          Serial.print("|");
          }
        }

        if (GYRO_Enabled == 1) {            // if the Mower is tracking using the compass steer here
          if ( (Loop_Cycle_Mowing % 2) == 0 ) {
          Get_GYRO_Reading(); 
          GYRO_Steering_Status = 1;        
          Calculate_GYRO_Wheel_Compensation();
          Motor_Action_Dynamic_PWM_Steering();              // Removes the full speed function if the mower is trying to hold to the compass heading.
          if (LCD_Screen_Keypad_Menu == 1) Print_LCD_Compass_Mowing();
          Serial.print(F("G-Lock:ON_"));
          Serial.print("|");
          }
        }
      
      }
        
        
       if (Pattern_Mow == 1) {
           Pattern_Mow_Parallel();
           }
           
       if (Pattern_Mow == 2) {
          Pattern_Mow_Spirals();                                // For pattern mow = 2 i.e. circular motion.
          }

    
      }

  // Max Cycles logic decides how far the Mower should run before turning around
  // This is useful is the mower gets hooked on soemthing and the wire and sonar sensors dont react.
  // The logic is now dependant on the type of mowing selected.  For Spiral mowing the max cycles are increased as the spiral mowing requires
  // more cycles to complete a decent sized spiral pattern, followed by a straight line connection leg to the next spiral
  
  int Max_Cycles_Active;                                                                        // define a veriable to hold the max cycles
  if (Pattern_Mow != 2 ) Max_Cycles_Active                        = Max_Cycles_Straight;        // if normal straight line mowing is slected
  if ((Pattern_Mow == 2 ) && (Spiral_Mow == 3)) Max_Cycles_Active = Max_Cycles_Straight;        // if spiral is selected but its a straight line leg 
  if ((Pattern_Mow == 2 ) && (Spiral_Mow < 3)) Max_Cycles_Active  = Max_Cycles_Spirals;         // if spiral is selected and its a LH or RH spiral
  
  if (Loop_Cycle_Mowing > Max_Cycles_Active) {                    // 150 the max length (Max_Cycles) for my garden. Adjust accordingly in the setup
     Serial.println("");
     Serial.println("Loop Cycle at Max");
     Serial.println("");
     Motor_Action_Stop_Spin_Blades();                    // Stop the blades from spinning
     Manouver_Turn_Around();                             // Turn around the mower
     Loop_Cycle_Mowing = 0;                              // Restes the loop cycle to start again.
     lcd.clear();
     }
 }
 
 





void Manouver_Find_Wire_Track()  {

  
  Serial.println(F("Find Wire Track Function Activated"));
  lcd.clear();
  lcd.print("Finding Wire...  ");
  Motor_Action_Stop_Spin_Blades();
  delay(5);
  Abort_Wire_Find = 0;
  No_Wire_Found_Fwd = 0;
  No_Wire_Found_Bck = 0;
  Mower_Running = 0;
  TestforBoundaryWire();                                                                    // Check to see that the wire is on.
  Loop_Cycle_Mowing = 0;
  int cycle = 0; 

  
  for (int i = 0; i <= 1; i++) {
    if (Mower_Parked == 0) {
      if (WIFI_Enabled == 1) Get_WIFI_Commands();
      Serial.print(F("Position Try = "));  
      Serial.println(i);
      ADCMan.run();
      UpdateWireSensor();
      delay(20);
      ADCMan.run();
      UpdateWireSensor();
      delay(20);
      Serial.println(F("before if loops start"));
      PrintBoundaryWireStatus();

    // First go backwards if the mower is outside the wire
    if (( inside == false) && (Abort_Wire_Find == 0) ) {                                    // If the mower is outside the wire then run the following code.
      ADCMan.run();
      UpdateWireSensor();
      PrintBoundaryWireStatus();
      Motor_Action_Stop_Motors();                                                           // Stop all wheel motion
      delay(1000);
      SetPins_ToGoBackwards();                                                                // Set the mower to back up
      delay(100);
      lcd.clear();
      lcd.print("Backwards Try...  ");
      lcd.setCursor(0,1);
      lcd.print("Finding Wire  ");
      delay(100);
      cycle = 0; 

      // Run the mower backwards until the wire is detetced and the mower is inside the wire
      while (( inside != true) && (Abort_Wire_Find == 0) && (No_Wire_Found_Bck == 0)  ){          // While the mower is still outside the fence run this code
        Loop_Cycle_Mowing = 222;                                                                  // Display this number "222" in the APP under loop cycles.
        cycle = cycle + 1;                                                                        // adds one to the cycle count
        Motor_Action_Go_Full_Speed();                                                             // Go full speed (in this case backwards)
        UpdateWireSensor();                                                                       // Read the wire sensor and see of the mower is now  or outside the wire
        ADCMan.run();
        PrintBoundaryWireStatus();                                                                // Prints of the status of the wire sensor readings.
        Serial.println("");
        if ((WIFI_Enabled == 1) && (Manuel_Mode == 0)) Get_WIFI_Commands(); 
        if (Mower_Parked == 1) {
          Serial.println("Abort Wire Find");
          Abort_Wire_Find = 1;
          }
        if (cycle > Max_Cycle_Wire_Find_Back) {                                                   // Track forwards for Max_Cycle_Wire_Find_Back cycles
            No_Wire_Found_Bck = 1;                                                                // if mower is still tracking after Max_Cycle_Wire_Find_Back cycles then cancel the find.
            Serial.println("Max Backward Cycles reached");
          }
        }
      
      Motor_Action_Stop_Motors();
      delay(5);
      }

    // Code to go forwards until the mower is outside/ON the wire
    if (( inside == true) && (Abort_Wire_Find == 0) && (No_Wire_Found_Fwd == 0) ) {             // If the Mower is situated  the wire then run the following code.
        ADCMan.run();
        UpdateWireSensor();
        Serial.println(F("CODE POSITION - MOTOR FORWARDS LOOP:  If statements"));
        PrintBoundaryWireStatus();
        Motor_Action_Stop_Motors();
        delay(1000);  
        SetPins_ToGoForwards();                                                                 // Set the motors to move the mower forwards
        delay(100);
        lcd.clear();
        lcd.print("Forward Try...  ");
        lcd.setCursor(0,1);
        lcd.print("Finding Wire  ");
        delay(100);
        cycle = 0;                                                                              // resets the cycles
        
        // Move the mower forwards until the wire is detected and the mower is then outside the wire
        while (( inside != false) && (No_Wire_Found_Fwd == 0) && (Mower_Parked ==0) ) {             // Move the mower forward until mower is outisde/ON the wire fence or 500 cycles have passed
          Loop_Cycle_Mowing = 111;                                                              // Displays 111 in the APP
          cycle = cycle + 1;
          lcd.setCursor(0,1);
          lcd.print("Track -> Charge"); 
          Motor_Action_Go_Full_Speed();                                                         // Go full speed (in this case forwards)
          Check_Bumper();                                                                       // Check if the bumper is hit
          UpdateWireSensor();                                                                   // Read the wire sensor and see of the mower is now  or outside the wire
          ADCMan.run();
          PrintBoundaryWireStatus();                                                            // Prints of the status of the wire sensor readings.
          Serial.println("");
          if ((WIFI_Enabled == 1) && (Manuel_Mode == 0)) Get_WIFI_Commands(); 
          if (Mower_Parked == 1) {
            Serial.println("Abort Wire Find");
            Abort_Wire_Find = 1;
            }
          if (Bumper == true) {
            Motor_Action_Stop_Motors();
            SetPins_ToGoBackwards();
            Motor_Action_Go_Full_Speed();
            delay(Mower_Reverse_Delay);
            Motor_Action_Stop_Motors();
            Bumper = false; 
            delay(4000);
            cycle = Max_Cycle_Wire_Find;
            }
          
          if (cycle > Max_Cycle_Wire_Find) {                                                    // Track forwards for Max_Cycle_Wire_Find_Fwd cycles
            No_Wire_Found_Fwd = 1;                                                              // if mower is still tracking after Max_Cycle_Wire_Find_Fwd cycles then cancel the find.
            Serial.println("Max Forward Cycles reached");
          }
        }
      Motor_Action_Stop_Motors();
      delay(5);
    }
  Motor_Action_Stop_Motors();
  delay(1000);
  }
  }

  // Position the mower further over the wire so it has space to turn 90° onto the wire.
  if ( (Abort_Wire_Find == 0) && (No_Wire_Found_Fwd == 0) && (Mower_Parked == 0) ) {
    SetPins_ToGoForwards();                                           
    delay(100);
    Motor_Action_Go_Full_Speed();
    delay(500);
    Motor_Action_Stop_Motors();
    }

  // Sets the firection of spin depensing on if the mower is eciting or tracking home

  // Set pins to track home to charge.
  if ((Mower_Track_To_Charge == 1) && (Mower_Parked == 0)) {
    lcd.setCursor(0,1);
    lcd.print("Track -> Charge"); 
    delay(1000);
       if (CW_Tracking_To_Charge == 1) {
          SetPins_ToTurnRight();                                                                // Track perimeter wire in a Clockwise Direction to the charging station
          Serial.println(F("CW Tracking to Charger"));
       }
       if (CCW_Tracking_To_Charge == 1) {
          SetPins_ToTurnLeft(); 
          Serial.println(F("CCW Tracking toCharger")); 
       }
    }

  // Set pins to track to exit.
  if ((Mower_Track_To_Exit == 1) && (Mower_Parked == 0)) {
    lcd.setCursor(0,1);
    lcd.print("Track -> Exit"); 
    delay(1000);
       if (CW_Tracking_To_Start == 1) {
          SetPins_ToTurnRight();                                                                // Track perimeter wire in a Clockwise Direction to the charging station
          Serial.println(F("CW Tracking to Exit"));
       }
       if (CCW_Tracking_To_Start == 1) {
          SetPins_ToTurnLeft(); 
          Serial.println(F("CCW Tracking to Exit")); 
       }
    }
  
  
  delay(20);
  // Pins are now set to turn from the above logic which way to turn onto the wire
  
  // Update the mowers position to the wire.
  ADCMan.run();
  UpdateWireSensor();
  ADCMan.run();
  PrintBoundaryWireStatus();                                                                  // Prints of the status of the wire sensor readings
  delay(20);

  int Max_Spin_Attempts = 150;
  int Spin_Attempts = 0;
  int WIFI_Check_Up;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Spin To Wire");
  // Spins the mower over the wire in the driection of tracking
  while (( inside == false)  && (Abort_Wire_Find == 0) && (No_Wire_Found_Fwd == 0) && (Mower_Parked ==0) && (Spin_Attempts < Max_Spin_Attempts )) {
        while (( inside != true) && (Spin_Attempts < Max_Spin_Attempts )) {                                                             // Do this loop until mower is back  the wire fence
        Serial.print(F("Spin Attempts"));
        Serial.print(Spin_Attempts);
        lcd.setCursor(0,1);
        lcd.print(Spin_Attempts);
        Motor_Action_Go_Full_Speed();                                                         // Go full speed (in the case turning as set by the previous logic)
        UpdateWireSensor();                                                                   // Read the wire sensor and see of the mower is now  or outside the wire
        ADCMan.run();
        PrintBoundaryWireStatus();                                                            // Prints of the status of the wire sensor readings.
        Spin_Attempts = Spin_Attempts + 1;                                            // checks that the mower is not blocked trying to spin on the wire and gets stuck in this loop
        WIFI_Check_Up = WIFI_Check_Up + 1;
        if (WIFI_Check_Up = 20) {
          if ((WIFI_Enabled == 1) && (Manuel_Mode == 0)) Get_WIFI_Commands(); 
          WIFI_Check_Up = 0;
          }
        }
    Motor_Action_Stop_Motors();                                                                 // Stop the mower on the wire facing the correct direction.
    }
  
  Motor_Action_Stop_Motors();
  if ((Abort_Wire_Find == 0) && (Spin_Attempts < Max_Spin_Attempts )) {
    Serial.println(F("Track Wire Function Complete - ON WIRE??"));
    lcd.clear();
    lcd.print("Wire Found...");
    delay(2000);                                                                                // 2 second pause to check result
    SetPins_ToGoForwards();                                           
    delay(100);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Track -> Charge"); 
    }

  // if an abort has been received or the mower is not spinning to the right diection on the the wire then park it.
  if ((Abort_Wire_Find == 1) || (Spin_Attempts >= Max_Spin_Attempts))  {
    Serial.println("Wire Find Aborted");
    lcd.clear();
    lcd.print("Wire Find ABORT!!");
    delay(2000);       
    Abort_Wire_Find = 0;
    SetPins_ToGoForwards();
    Manouver_Park_The_Mower();
    }

  if (No_Wire_Found_Fwd == 1) {
    Serial.println("Re-starting wire find");
    SetPins_ToGoForwards();
    }
  
  }



    

// Turn Around defines how the mower should react when a wire or sonar sensor is activated.
// Now with the spiral pattern mowing is also decides the logic of which Spiral shape will be next

void Manouver_Turn_Around() {
    Motor_Action_Stop_Motors(); 
    Serial.println(F(""));
    if (Outside_Wire == 1)     Serial.println(F("Mower is Outside the Wire"));
    if (GPS_Inside_Fence == 0) Serial.println(F("Mower is Outside the GPS Fence"));
    if (Wheel_Blocked == 1)    Serial.println(F("Mower Wheels are jammed"));
    Serial.println(F("Mower is Turning"));
    if (TFT_Screen_Menu == 1) Send_Mower_Running_Data();          // Update TFT Screen
    Serial.println(F(""));
    delay(80);

    // Back up the mower
    SetPins_ToGoBackwards();
    Motor_Action_Go_Full_Speed();
    delay(Mower_Reverse_Delay);
    Motor_Action_Stop_Motors(); 

    // Randomly decide if the mower should turn left or right depending on if the loop cycle is odd or even
    if ( (Loop_Cycle_Mowing % 2) == 0 ) {
     SetPins_ToTurnRight(); 
    }
    else SetPins_ToTurnLeft();

    // Randomly turns the mower to a new heading depending on the delay Min or Delay Max from the settings
    Motor_Action_Turn_Speed();
    delay (random(Mower_Turn_Delay_Min, Mower_Turn_Delay_Max));

    // If Spiral Mode is activated
    // Advances the type of movement in Pattern Spiral Mode from : 1 RH Spiral | 2 LH Spiral | 3 Straight line.
    if (Pattern_Mow == 2) {
    Spiral_Mow = (Spiral_Mow + 1);
    if (Spiral_Mow > 3) Spiral_Mow = 1;
    }
    //Spiral (random(1,3));  Activate this to make a true random pattern.

    Motor_Action_Stop_Motors();
    
    // If the perimeter wire is enabled
    // Check that the mower has turned and moved back inside the boundary wire.
    if (Perimeter_Wire_Enabled == 1) {
        Check_Wire_In_Out();
    
        if (Outside_Wire == 1) { 
          Serial.println(F("Outside Wire 1"));
          TestforBoundaryWire();  
          delay(100);
          UpdateWireSensor();
          Check_Wire_In_Out();
              if (Outside_Wire == 1) { 
                Serial.println(F("Outside Wire 2"));
                //SetPins_ToGoBackwards();
                //Motor_Action_Go_Full_Speed();
                //delay(300);
                Motor_Action_Stop_Motors();
                delay(20);
                TestforBoundaryWire();  
                delay(80);
                UpdateWireSensor();
                Check_Wire_In_Out();
                if (Outside_Wire == 1) { 
                      Serial.println(F("Outside Wire = 3 - Must be really outside...."));
                      //SetPins_ToGoForwards();
                      //Motor_Action_Go_Full_Speed();
                      //delay(300);
                      Motor_Action_Stop_Motors();
                      delay(20);
                      TestforBoundaryWire();  
                      delay(80);
                      UpdateWireSensor();
                      Check_Wire_In_Out();
                      }
                }
    
         }
        }

    // If the GPS Fencing is enabled
    // Check that the mower has turned and moved back inside the GPS Fence.
    if (GPS_Enabled == 1) {
        Check_GPS_In_Out();       
    
        if (GPS_Inside_Fence == 0) {                                  // Mower is still outside the fence
          Serial.println(F("Outside GPS Fence 1"));
          delay(100);
          Check_GPS_In_Out();                                         // Check the GPS signal again
              if (GPS_Inside_Fence == 0) { 
                Serial.println(F("Outside GPS Fence 2"));
                delay(1000);
                Check_GPS_In_Out(); 
                if (GPS_Inside_Fence == 0) { 
                      Serial.println(F("Outside GPS Fence = 3 - Must be really outside...."));
                      }
                }
    
         }
        }

    
    Bumper = 0;                                                           // Reset Bumper
    Loop_Cycle_Mowing = 1;                                                // Rest Loop Cycle
    Sonar_Hit = 0;                                                        // Reset Sonar
    distance1 = 999;
    distance2 = 999;
    distance3 = 999;
    Sonar_Status = 0;
    Sonar_Hit_1_Total = 0;
    Sonar_Hit_2_Total = 0;
    Sonar_Hit_3_Total = 0;
    Compass_Heading_Locked = 0;                                           // Reset Compass Heading Lock
    if (LCD_Screen_Keypad_Menu == 1) lcd.clear();
    if (TFT_Screen_Menu == 1)        Send_Mower_Running_Data();           // Update TFT Screen
    Serial.println(F(""));
    Serial.println(F("Mower Turned Around"));
    Serial.println(F(""));
}

  

void Manouver_Turn_Around_Sonar() {
  Sonar_Status = 1;
  Serial.println(F("Mower is Turning - Sonar"));
  Motor_Action_Stop_Motors(); 
  
  if (TFT_Screen_Menu == 1) Send_Mower_Running_Data();          // Update TFT Screen
  delay(500);
  SetPins_ToGoBackwards();
  Motor_Action_Go_Full_Speed();
  delay(Mower_Reverse_Delay);
  Motor_Action_Stop_Motors(); 

  if ( distance1 < maxdistancesonar ||  distance2 < maxdistancesonar ) {
      lcd.setCursor(0, 8);
      lcd.print("Go Right -->       ");
      SetPins_ToTurnRight();
      Motor_Action_Turn_Speed();
      delay(Mower_Turn_Delay_Max);
      }

  if (distance3 < maxdistancesonar) {
      lcd.setCursor(0, 8);
      lcd.print("<-- Go Left      ");
      SetPins_ToTurnLeft();
      Motor_Action_Turn_Speed();
      delay(Mower_Turn_Delay_Max);
      }
  
  Motor_Action_Stop_Motors();
  Compass_Heading_Locked = 0;
  Sonar_Hit = 0;
  Loop_Cycle_Mowing = 0;
  Sonar_Status = 0;
  if (TFT_Screen_Menu == 1) Send_Mower_Running_Data();          // Update TFT Screen 
  Serial.println(F("Mower Turned Around"));
  Serial.println(F(""));
  }


void Manouver_Manuel_Mode() {
  Mower_Docked          = 0;
  Mower_Parked          = 0;
  Mower_Running         = 0;
  Mower_Parked_Low_Batt = 0;
  Mower_Track_To_Exit   = 0;
  Mower_Track_To_Charge = 0;
  Exiting_Dock          = 0;
  Mower_Error           = 0;
  Manuel_Mode           = 1;
  Loop_Cycle_Mowing     = 0;
  Motor_Action_Stop_Motors();
  Motor_Action_Stop_Spin_Blades();
  
}


void Manouver_Start_Mower() {
  
  if ((Mower_Track_To_Exit == 1) && (TFT_Screen_Menu == 1)) {
    Mower_Track_To_Exit   = 0;
    Exiting_Dock          = 0;
    Mower_Running         = 1;
    Calculate_TFT_Mower_Status_Value(); 
    Send_Mower_Tracking_Data();
    }

 
  Mower_Docked          = 0;
  Mower_Parked          = 0;
  Mower_Running         = 1;
  Mower_Parked_Low_Batt = 0;
  Mower_Track_To_Charge = 0;
  Rain_Hit_Detected     = 0;
  Mower_Error           = 0;
  Exiting_Dock          = 0;
  Loop_Cycle_Mowing     = 0;
  Manuel_Mode           = 0;
  Wire_Refind_Tries     = 0;
  Calculate_TFT_Mower_Status_Value(); 
  Turn_On_Relay();
  Y_Tilt = 0;

  }

void Manouver_Mower_Exit_Dock() {

  Mower_Docked          = 0;
  Mower_Parked          = 0;
  Mower_Running         = 0;
  Mower_Parked_Low_Batt = 0;
  Rain_Hit_Detected     = 0;
  Mower_Error           = 0;
  Manuel_Mode           = 0;
  Tracking_Wire         = 0;
  Exiting_Dock          = 1;  
  Mower_Status_Value    = 9;
  //Calculate_TFT_Mower_Status_Value();    // Mower Status Value is already given in above line.
  
  Serial.println(F("Updating TFT with Exit Dock Information"));
  Send_Mower_Tracking_Data();         // Send docked numbers to break out of the cycle and change it to mower exiting dock mode.
  Serial.println(F(""));// Send Command to the TFT
  if (WIFI_Enabled == 1) Get_WIFI_Commands();   // Command WIFI
  }

void Manouver_Dock_The_Mower() {
  if (TFT_Screen_Menu == 1) {
    Turn_To_Home              = 0;
    Find_Wire_Track           = 0;
    Go_To_Charging_Station    = 0;
    Mower_Docked              = 1;
    Tracking_Wire             = 0;
    Mower_Track_To_Charge     = 0;
    Calculate_TFT_Mower_Status_Value();
    Send_Mower_Tracking_Data();
    }
  
  Mower_Docked          = 1;
  Mower_Parked          = 0;
  Mower_Running         = 0;
  Mower_Parked_Low_Batt = 0;
  Mower_Track_To_Exit   = 0;
  Mower_Track_To_Charge = 0;
  Mower_Error           = 0;
  Loop_Cycle_Mowing     = 0;
  Manuel_Mode           = 0;
  Exiting_Dock          = 0;
  Motor_Action_Stop_Motors();
  Motor_Action_Stop_Spin_Blades();
  Turn_Off_Relay();
  Print_LCD_Info_Docked();
  Charge_Detected_MEGA = 0;
  //Setup Alarms 
  Alarm_Timed_Mow_ON = 0;                                           // Turns off the 1 hr Alarm
 
}

// Mower is a parked position and needs manual charging
void Manouver_Park_The_Mower_Low_Batt() {

  Motor_Action_Stop_Motors();
  Motor_Action_Stop_Spin_Blades();
 
  if ((Exiting_Dock == 1) && (TFT_Screen_Menu == 1))  {
        Serial.println(F("Sending TFT Tracking Data"));
        Mower_Parked_Low_Batt = 1;
        Mower_Error           = 1;
        Exiting_Dock          = 0;
        Calculate_TFT_Mower_Status_Value();               // Updates the Mower status Value
        Send_Mower_Tracking_Data();
        }
  if ((Mower_Running == 1) &&  (TFT_Screen_Menu == 1)) {
        Serial.println(F("Sending TFT Running Data"));
        Mower_Parked_Low_Batt = 1;
        Mower_Error           = 1;
        Mower_Running         = 0;
        Calculate_TFT_Mower_Status_Value();               // Updates the Mower status Value
        Send_Mower_Running_Data();
        }
  
  Mower_Parked_Low_Batt = 1;
  Mower_Docked          = 0;
  Mower_Parked          = 0;
  Mower_Running         = 0;
  Mower_Track_To_Charge = 0;
  Mower_Error           = 0;
  Loop_Cycle_Mowing     = 0;
  Manuel_Mode           = 0;


}


// Mower is in a parked or paused potion ready to restart
void Manouver_Park_The_Mower() {

  Motor_Action_Stop_Motors();
  Motor_Action_Stop_Spin_Blades();

  if (Mower_Parked == 0 ) lcd.clear();
  if ((Mower_Running == 1) &&  (TFT_Screen_Menu == 1)) {
        Serial.println(F("Sending TFT Running Data"));
        Mower_Parked          = 1;
        Mower_Error           = 0;
        Mower_Running         = 0;
        Calculate_TFT_Mower_Status_Value();               // Updates the Mower status Value
        Send_Mower_Running_Data();
        }
  
  Mower_Docked          = 0;
  Mower_Parked          = 1;
  Mower_Running         = 0;
  Mower_Parked_Low_Batt = 0;
  Mower_Track_To_Charge = 0;
  Tracking_Wire         = 0;
  Mower_Track_To_Exit   = 0;
  Mower_Error           = 0;
  Loop_Cycle_Mowing     = 0;
  Manuel_Mode           = 0;
  Turn_Off_Relay();

  Alarm_Timed_Mow_ON = 0;                                           // Turns off the 1 hr Alarm
  //if (Alarm_1_Repeat == 0) Alarm_1_ON = 0;
  //if (Alarm_2_Repeat == 0) Alarm_2_ON = 0;
  //if (Alarm_3_Repeat == 0) Alarm_3_ON = 0;
  }


// Puts the mower to sleep - normally due to an error being found 
void Manouver_Hibernate_Mower() {

  Motor_Action_Stop_Motors();
  Motor_Action_Stop_Spin_Blades();
  
  // This function requires 2 different strategies to send the correct information to the TFT based on if the mower 
  // is running or exiting the dock.  The Error function is therefore transmitted diffrently depending on the expected
  // Package of daat the TFT is waiting for.  i.e. in Exit Dock Mode the TFT expects the Exit Dock TFT Data Package
  // and will hang if it recieves the running data package.

  Serial.println(F("Hibernate Mower"));
  
  if ((Exiting_Dock == 1) && (TFT_Screen_Menu == 1))  {
        Serial.println(F("Sending TFT Tracking Data"));
        Mower_Error           = 1;
        Exiting_Dock          = 0;
        Mower_Parked          = 0;  
        Calculate_TFT_Mower_Status_Value();               // Updates the Mower status Value
        Send_Mower_Tracking_Data();
        }
  if ((Mower_Running == 1) &&  (TFT_Screen_Menu == 1)) {
        Serial.println(F("Sending TFT Running Data"));        
        Mower_Error           = 1;
        Mower_Running         = 0;
        if (Tilt_Orientation_Sensed == 1)  {
          Serial.println("Tilt Used");
          Mower_Error           = 3;
          Mower_Running         = 0;
          }
        Serial.print(F("Mower Error before calc="));
        Serial.println(Mower_Error);  
        Calculate_TFT_Mower_Status_Value();               // Updates the Mower status Value
        Serial.print(F("Mower Error after calc="));
        Serial.println(Mower_Error);  
        Send_Mower_Running_Data();
        }

  if ((Mower_Parked == 1) &&  (TFT_Screen_Menu == 1) && (Tilt_Orientation_Sensed == 0)) {
        Serial.println(F("Sending TFT Parked Data"));
        Mower_Error           = 1;
        Mower_Parked          = 1;
        Calculate_TFT_Mower_Status_Value();               // Updates the Mower status Value
        Send_Mower_Docked_Data();
        }

        Mower_Docked          = 0;  
        Mower_Parked_Low_Batt = 0;
        Mower_Track_To_Charge = 0;
        Tracking_Wire         = 0;
        Mower_Track_To_Exit   = 0;
        Loop_Cycle_Mowing     = 0;
        Manuel_Mode           = 0;
 
  // Powers down the mower motors and cuts the main power via the relay. 

  Turn_Off_Relay();
  }

// Mower is sent to the charging station after low volts are detected or mebrane key input.
void Manouver_Go_To_Charging_Station() {

  Motor_Action_Stop_Spin_Blades();
  Motor_Action_Stop_Motors();

  if ((TFT_Screen_Menu == 1) && (Mower_Parked = 1)) {
      Mower_Docked          = 0;
      Mower_Parked          = 0;
      Mower_Track_To_Charge = 1;
      Tracking_Wire         = 1;
      Serial.println(F("Updating TFT with Exit Dock Information"));
      Calculate_TFT_Mower_Status_Value();
      Send_Mower_Docked_Data();         // Send docked numbers to break out of the cycle and change it to mower exiting dock mode.
      delay(4000);  
      }  

  if ((TFT_Screen_Menu == 1) && (Mower_Running ==1)) {
      Mower_Running         = 0;
      Mower_Track_To_Charge = 1;
      Tracking_Wire         = 1;
      Serial.println(F("Updating TFT with Exit Dock Information"));
      Calculate_TFT_Mower_Status_Value();
      Send_Mower_Running_Data();         // Send docked numbers to break out of the cycle and change it to mower exiting dock mode.
      delay(4000);  
      }

  
  Mower_Docked          = 0;
  Mower_Parked          = 0;
  Mower_Running         = 0;
  Mower_Parked_Low_Batt = 0;
  Mower_Track_To_Charge = 1;
  Tracking_Wire         = 1;
  Mower_Track_To_Exit   = 0;
  Mower_Error           = 0;
  Loop_Cycle_Mowing     = 0;
  Manuel_Mode           = 0;
  No_Wire_Found_Fwd     = 0;
  No_Wire_Found_Bck     = 0;
  Manage_Alarms();                                              // Switches on or off the Alarms depending on the setup


  if (WIFI_Enabled == 1) Get_WIFI_Commands();
  delay(5);
  delay(2000);
  Turn_On_Relay();
  delay(500);
  
  
  
  // Turns the Mower in the Home Compass Direction and send the info to the TFT and WIFI
  if (WIFI_Enabled == 1) Get_WIFI_Commands();
  if (TFT_Screen_Menu == 1) {                                     // send Commands to the TFT;
    Turn_To_Home = 1;
    Find_Wire_Track = 0;
    Go_To_Charging_Station = 0;
    Send_Mower_Tracking_Data();
    }
  if ((Compass_Activate == 1) && (Mower_Parked ==0))    Compass_Turn_Mower_To_Home_Direction();
  
  
  // Find the Wire and send the info to the TFT and WIFI
  if (WIFI_Enabled == 1) Get_WIFI_Commands();
  if (TFT_Screen_Menu == 1) {
    Turn_To_Home = 0;
    Find_Wire_Track = 1;
    Go_To_Charging_Station = 0;
    Send_Mower_Tracking_Data();
    }
  if (Mower_Parked == 0)                                Manouver_Find_Wire_Track();
  
   // Track the Wire and send the info to the TFT and WIFI
  if (WIFI_Enabled == 1) Get_WIFI_Commands();
  if (TFT_Screen_Menu == 1) {
    Turn_To_Home = 0;
    Find_Wire_Track = 0;
    Go_To_Charging_Station = 1;
    Send_Mower_Tracking_Data();
    }
  if ((Mower_Parked == 0) && (No_Wire_Found_Fwd == 0))      Track_Perimeter_Wire_To_Dock();
  
  // Restarts the process if no wire is found,
  if (WIFI_Enabled == 1) Get_WIFI_Commands();
  if (TFT_Screen_Menu == 1) Send_Mower_Tracking_Data();
  if (No_Wire_Found_Fwd == 1)                               Manouver_Go_To_Charging_Station();
  
  if (WIFI_Enabled == 1) Get_WIFI_Commands();

  }

void Manouver_Exit_To_Zone_X() {
   // Zone 1 or Zone 2 and the Wire itterations are set on the Membrane Buttons.
   // These values are then crried into the following functions.  
   Turn_On_Relay();
   delay(1000);
   Serial.println(F("Sending Tracking Data in Exit To Zone X"));
   Mower_Status_Value = 9;                                      // 9 = Exiting Dock
   Send_Mower_Tracking_Data();                                  // Send the tracking TX Data package to the mower.   
   Manouver_Mower_Exit_Dock();                                  // Carry out the Exit Dock Manouver
   
   Manouver_Exit_From_Docking_Station();                         // Move the Mower into position backing out of the docking station
   if (Perimeter_Wire_Enabled == 1) {
     Mower_Track_To_Exit = 1;
     TestforBoundaryWire();
     delay(50);

     // If the boundary wire is on then carry on
     if (Wire_Detected == 1) {
       if (WIFI_Enabled == 1) Get_WIFI_Commands();
       Manouver_Find_Wire_Track();                                   // Located the boundary wire
       if (WIFI_Enabled == 1) Get_WIFI_Commands();
       if (Mower_Parked == 0) Track_Wire_From_Dock_to_Zone_X();
       if (WIFI_Enabled == 1) Get_WIFI_Commands();
       if (Mower_Parked == 0) Special_Move_Into_Garden_Zone_X();
       if (WIFI_Enabled == 1) Get_WIFI_Commands();
       if (Mower_Parked == 0) Manouver_Start_Mower();
       if (WIFI_Enabled == 1) Get_WIFI_Commands();
       if (Mower_Parked == 1) Manouver_Park_The_Mower();
     }
    
    // If the boundary wire is turned off / not detected
    // Then the test boundary wire function will already put the mower into hibernate mode.
    
//    if (Wire_Detected == 0) {
//        TestforBoundaryWire();                                      // Test again for the boundary wire
//          if (Wire_Detected == 0) {                                 // if its still saying the wire is off then park the mower.
//          Serial.println("");
//          Serial.println("Perimeter Wire not detected");
//          Manouver_Park_The_Mower();
//          Mower_Status_Value = 4;         // Sends the mower status value to the TFT Screen 4 = Error Status.
//          Mower_Error_Value = 1;          // Describes the error 1 = No Wire, 
//          Serial.println(F("Sending Tracking Data in Wire detect = 0"));
//          Send_Mower_Tracking_Data();
//          }
//        }   
    }
    
  if (Perimeter_Wire_Enabled == 0) {
       Serial.println("");
       Serial.println("Perimeter Wire not activated in settings");
       Manouver_Park_The_Mower();
  }
}


// Function to re-find the wire if the mower looses the wire while mowing
// 3 outside the wires ativates this function. Sonar and wire function is then used to re-find the wire.
void Manouver_Outside_Wire_ReFind_Function(){
    Motor_Action_Stop_Spin_Blades(); 
    lcd.clear();
    lcd.print("Trying to find");
    lcd.setCursor(0,1);
    lcd.print("Wire Again...");
    ADCMan.run();
    UpdateWireSensor();
    delay(20);
    PrintBoundaryWireStatus();
    ADCMan.run();
    UpdateWireSensor();
    delay(20);
    PrintBoundaryWireStatus();
  while (inside == false) {                                              // If the mower is outside the wire then run the following code.
     ADCMan.run();
     UpdateWireSensor();
     PrintBoundaryWireStatus();
     //Check_Wire_In_Out();
     delay(500);
     distance_blockage = PingSonarX(trigPin1, echoPin1, 1, 1, 1, 4, 0);
     delay(500);
     Serial.print(F("Distance measured from sonar :"));
     Serial.println(distance_blockage);
     
     // if the sonar is measuring an opening as the distance is greater than 300cm then move forward in that direction.
     if (distance_blockage > 400) {
      while ( (inside == false) && (distance_blockage > 400) ){
        SetPins_ToGoForwards();
        Motor_Action_Go_Full_Speed();
        delay(500);
        ADCMan.run();
        UpdateWireSensor();
        PrintBoundaryWireStatus();
        distance_blockage = PingSonarX(trigPin1, echoPin1, 1, 1, 1, 4, 0); 
        delay(10);
        //Check_Wire_In_Out();
      }
     Motor_Action_Stop_Motors;
     ADCMan.run();
     UpdateWireSensor();
     PrintBoundaryWireStatus();
     }

     // if the sonar is measuring something less than 300cm then turn to the left and measure again
     // keep turning 'while function' until a path is open.
     while (distance_blockage < 300) {
       SetPins_ToTurnLeft();
       delay(200);
       Motor_Action_Turn_Speed();                                                             
       delay(100); 
       distance_blockage = PingSonarX(trigPin1, echoPin1, 1, 1, 1, 4, 0); 
       delay(10);
     }
     Motor_Action_Stop_Motors;
     ADCMan.run();
     UpdateWireSensor();
     PrintBoundaryWireStatus();
  }

   Serial.println("Mower is now back inside the wire......?");
   lcd.clear();
   lcd.print("Mower now");
   lcd.setCursor(0,1);
   lcd.print("Inside Wire?");
   Outside_Wire_Count = 0;
   //FindWireTrack();
}
