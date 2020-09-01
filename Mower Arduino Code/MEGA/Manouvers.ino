// Manouvers are a set of motion functions or motor actions that are regulary called
// e.g. Turn the mower around






// Moves the Mower Forwards in the garden and activates compass features if enabled
void Manouver_Mow_The_Grass() {

    Motor_Action_Spin_Blades();
    SetPins_ToGoForwards();

    Loop_Cycle_Mowing = (Loop_Cycle_Mowing + 1);
    Serial.print(F("Loop:"));
    Serial.print(Loop_Cycle_Mowing);
    Serial.print("|");
    lcd.setCursor(13, 1);
    lcd.print(Loop_Cycle_Mowing);
    delay(1);
  
  if (Loop_Cycle_Mowing < 5  )  {                       
    Serial.print(F("C-Lock:OFF"));
    Serial.print("|");
    Print_LCD_Mowing();
    Get_Compass_Reading();
    Motor_Action_Go_Full_Speed();
    Compass_Heading_Locked = 0;                           // Turn off the compass heading lock for the new cycles
    }

  if (Loop_Cycle_Mowing == 5)   {
    if (Compass_Heading_Hold_Enabled == 0) {
        Serial.print(F("C-Lock:OFF"));
        Serial.print("|");
        Print_LCD_Compass_Mowing();
        Motor_Action_Go_Full_Speed();
        Compass_Heading_Locked = 0;
        }
    if (Compass_Heading_Hold_Enabled == 1)  {
        Get_Compass_Reading();                            // Gets the latest compass reading
        Heading_Lock = Heading;                           // The compass heading is locked in
        Compass_Heading_Locked = 1;                       // One more cycle of normal movement
        }
    }

  if (Loop_Cycle_Mowing > 5) {
      if (Compass_Heading_Locked == 0) {
        lcd.setCursor(0, 1);
        lcd.print("Mowing..        ");
        Serial.print(F("C-Lock:OFF"));
        Serial.print("|");
        Motor_Action_Go_Full_Speed();
        }
      if (Compass_Heading_Locked == 1) {            // if the Mower is tracking using the compass steer here
        Get_Compass_Reading(); 
        Calculate_Compass_Wheel_Compensation();
        Motor_Action_Dynamic_PWM_Steering();              // Removes the full speed function if the mower is trying to hold to the compass heading.
        Print_LCD_Compass_Mowing();
        Serial.print(F("C-Lock:ON_"));
        Serial.print("|");
        }
      }

 if (Loop_Cycle_Mowing > Max_Cycles) {                    // 150 the max length for my garden. Adjust accordingly
      Serial.println("");
      Serial.println("Loop Cycle at Max");
      Serial.println("");
      Motor_Action_Stop_Spin_Blades();                    // Stop the blades from spinning
      Manouver_Turn_Around();                             // Turn around the mower
      Loop_Cycle_Mowing = 0;                              // Restes the loop cycle to start again.
      lcd.clear();
      }

}




void Manouver_Exit_From_Docking_Station() {
    lcd.clear();
    lcd.print("Exiting Garage");
    delay(2000);
    SetPins_ToGoBackwards();                    // Prepare motors to go Backwards
    Motor_Action_GoFullSpeed_Out_Garage();            // Move Backwards
    delay (7000);                               // Backwards time
    Motor_Action_Stop_Motors;                          // Stop
    SetPins_ToTurnLeft();                       // Prepare motors to turn left
    Motor_Action_Turn_Speed();                         // Turn
    delay(1000);                                 // Turn time
    Motor_Action_Stop_Motors;                          // Stop
    SetPins_ToGoBackwards();                    // Set again to go backwards
    Motor_Action_Go_Full_Speed();                       // Move Backwards
    delay (500);                               // Backwards Time
    SetPins_ToTurnLeft();                       // Set to go left             
    Motor_Action_Turn_Speed();                         // Turn
    delay(200);                                 // Turning time
    Motor_Action_Stop_Motors();                          // Stop
    SetPins_ToGoForwards();                     // Set to go forwards
    Motor_Action_Stop_Motors(); 
    lcd.clear();                                // Clears the LCD display
    lcd.print("Garage Clear");                  // Prints to the LCD screen
    Motor_Action_Stop_Motors; 
    delay(500);
    lcd.clear();
}


void Manouver_Find_Wire_Track()  {

  Serial.println(F("Find Wire Track Function Activated"));
  lcd.clear();
  lcd.print("Finding Wire...");
  Motor_Action_Stop_Spin_Blades();
  delay(5);
  TestforBoundaryWire();                            // Check to see that the wire is on.

  for (int i = 0; i <= 1; i++) {
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

    if ( inside == false) {                                              // If the mower is outside the wire then run the following code.
      ADCMan.run();
      UpdateWireSensor();
      PrintBoundaryWireStatus();
      Motor_Action_Stop_Motors();                                              // Stop all wheel motion
      delay(1000);
      SetPins_ToGoBackwards();                                          // Set the mower to back up
      delay(100);
      lcd.clear();
      lcd.print("Backwards Try...");
      lcd.setCursor(0,1);
      lcd.print("Finding Wire");
      delay(100);
      while ( inside != true) {                                          // While the mower is still outside the fence run this code
        Motor_Action_Go_Full_Speed();                                           // Go full speed (in this case backwards)
        UpdateWireSensor();                                             // Read the wire sensor and see of the mower is now  or outside the wire
        ADCMan.run();
        PrintBoundaryWireStatus();                                      // Prints of the status of the wire sensor readings.
        Serial.println("");
      }
      Motor_Action_Stop_Motors();
      delay(5);
    }


    if ( inside == true)  {                                            // If the Mower is situated  the wire then run the following code.
      ADCMan.run();
      UpdateWireSensor();
      Serial.println(F("CODE POSITION - MOTOR FORWARDS LOOP:  If statements"));
      PrintBoundaryWireStatus();
      Motor_Action_Stop_Motors();
      delay(1000);
      SetPins_ToGoForwards();                                           // Set the motors to move the mower forwards
      delay(100);
      lcd.clear();
      lcd.print("Forward Try...");
      lcd.setCursor(0,1);
      lcd.print("Finding Wire");
      delay(100);
      while ( inside != false) {                                         // Do this loop until mower is back  the wire fence
        Motor_Action_Go_Full_Speed();                                           // Go full speed (in this case forwards)
        UpdateWireSensor();                                             // Read the wire sensor and see of the mower is now  or outside the wire
        ADCMan.run();
        PrintBoundaryWireStatus();                                      // Prints of the status of the wire sensor readings.
        Serial.println("");
      }
      Motor_Action_Stop_Motors();
      delay(5);
    }
  Motor_Action_Stop_Motors();
  //if (WIFI_Enabled == 1) Get_Blynk_Commands();
  delay(1000);
  }

  // position the mower further over the wire so it has space to turn 90° onto the wire.
  SetPins_ToGoForwards();                                           
  delay(100);
  Motor_Action_Go_Full_Speed();
  delay(500);
  Motor_Action_Stop_Motors();


  if (Mower_Track_To_Charge == 1) {
  lcd.setCursor(0,1);
  lcd.print("Track -> Charge"); 
  delay(1000);
     if (CW_Tracking_To_Charge == 1) {
        SetPins_ToTurnRight();                          // Track perimeter wire in a Clockwise Direction to the charging station
        Serial.println(F("CW Tracking to Charger"));
     }
     if (CCW_Tracking_To_Charge == 1) {
        SetPins_ToTurnLeft(); 
        Serial.println(F("CCW Tracking toCharger")); 
     }
  }

  if (Mower_Track_To_Exit == 1) {
  lcd.setCursor(0,1);
  lcd.print("Track -> Exit"); 
  delay(1000);
     if (CW_Tracking_To_Start == 1) {
        SetPins_ToTurnRight();                          // Track perimeter wire in a Clockwise Direction to the charging station
        Serial.println(F("CW Tracking to Exit"));
     }
     if (CCW_Tracking_To_Start == 1) {
        SetPins_ToTurnLeft(); 
        Serial.println(F("CCW Tracking to Exit")); 
     }
  }
  
  
  delay(20);
  // Pins are now set to turn from the above logic.
  
  // Check again that the mower is outside the wire.
  ADCMan.run();
  UpdateWireSensor();
  ADCMan.run();
  PrintBoundaryWireStatus();                                      // Prints of the status of the wire sensor readings
  delay(20);

  while ( inside == false) {
        while ( inside != true) {                                         // Do this loop until mower is back  the wire fence
        Motor_Action_Go_Full_Speed();                                           // Go full speed (in the case turning as set by the previous logic)
        UpdateWireSensor();                                             // Read the wire sensor and see of the mower is now  or outside the wire
        ADCMan.run();
        PrintBoundaryWireStatus();                                      // Prints of the status of the wire sensor readings.
      }
  Motor_Action_Stop_Motors();                                                // Stop the mower on the wire facing the correct direction.
  }
  
  Motor_Action_Stop_Motors();
  Serial.println(F("Track Wire Function Complete - ON WIRE??"));
  lcd.clear();
  lcd.print("Wire Found...");
  delay(2000);                                                         // 2 second pause to check result
  SetPins_ToGoForwards();                                           
  delay(100);
  }


void Manouver_Move_Into_Garden_Zone_X() {
    Serial.println("start mower code here");
    // after wire tracking the code to bering the mower to a sensible position away from the wire
  }





void Manouver_Turn_Around() {
  Motor_Action_Stop_Motors(); 
  delay(500);
  SetPins_ToGoBackwards();
  Motor_Action_Go_Full_Speed();
  delay(Mower_Reverse_Delay);
  Motor_Action_Stop_Motors(); 
  
  if ( (Loop_Cycle_Mowing % 2) == 0 ) {
   SetPins_ToTurnRight(); 
  }
  else SetPins_ToTurnLeft();
  
  Motor_Action_Turn_Speed();
  delay (random(Mower_Turn_Delay_Min, Mower_Turn_Delay_Max));
  Motor_Action_Stop_Motors();
  TestforBoundaryWire();                                                   
  Check_Wire_In_Out();
  Loop_Cycle_Mowing = 1;
  Sonar_Hit = 0;
  Compass_Heading_Locked = 0;
  lcd.clear();
  }

void Manouver_Turn_Around_Sonar() {
  Motor_Action_Stop_Motors(); 
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
  
}


void Manouver_Manuel_Mode() {
  Mower_Docked          = 0;
  Mower_Parked          = 0;
  Mower_Running         = 0;
  Mower_Parked_Low_Batt = 0;
  Mower_Track_To_Exit   = 0;
  Mower_Track_To_Charge = 0;
  Mower_Lost            = 0;
  Manuel_Mode           = 1;
  Loop_Cycle_Mowing     = 0;
  Motor_Action_Stop_Motors();
  Motor_Action_Stop_Spin_Blades();
  
}


void Manouver_Start_Mower() {
  Mower_Docked          = 0;
  Mower_Parked          = 0;
  Mower_Running         = 1;
  Mower_Parked_Low_Batt = 0;
  Mower_Track_To_Charge = 0;
  Rain_Hit_Detected     = 0;
  Mower_Lost            = 0;
  Loop_Cycle_Mowing     = 0;
  Manuel_Mode           = 0;
  Turn_On_Relay();

  }

void Manouver_Mower_Exit_Dock() {

  Mower_Docked          = 0;
  Mower_Parked          = 0;
  Mower_Running         = 0;
  Mower_Parked_Low_Batt = 0;
  Rain_Hit_Detected     = 0;
  Mower_Lost            = 0;
  Manuel_Mode           = 0;
  Tracking_Wire         = 0;  
  if (WIFI_Enabled == 1) Get_WIFI_Commands();
  }

void Manouver_Dock_The_Mower() {
  Mower_Docked          = 1;
  Mower_Parked          = 0;
  Mower_Running         = 0;
  Mower_Parked_Low_Batt = 0;
  Mower_Track_To_Exit   = 0;
  Mower_Track_To_Charge = 0;
  Mower_Lost            = 0;
  Loop_Cycle_Mowing     = 0;
  Manuel_Mode           = 0;
  Motor_Action_Stop_Motors();
  Motor_Action_Stop_Spin_Blades();
  Turn_Off_Relay();
  Print_LCD_Info_Docked();
  Charge_Detected_MEGA = 0;
  
  
  //reset alarms...
  Alarm_3_ON = 0;                                           // Turns off the 1 hr Alarm
  Create_Alarms();
 
}

// Mower is a parked position and needs manual charging
void Manouver_Park_The_Mower_Low_Batt() {
  
  Mower_Docked          = 0;
  Mower_Parked          = 0;
  Mower_Running         = 0;
  Mower_Parked_Low_Batt = 1;
  Mower_Track_To_Charge = 0;
  Mower_Lost            = 0;
  Loop_Cycle_Mowing     = 0;
  Manuel_Mode           = 0;
  Motor_Action_Stop_Motors();
  Motor_Action_Stop_Spin_Blades();
}


// Mower is in a parked or paused potion ready to restart
void Manouver_Park_The_Mower() {

  Mower_Docked          = 0;
  Mower_Parked          = 1;
  Mower_Running         = 0;
  Mower_Parked_Low_Batt = 0;
  Mower_Track_To_Charge = 0;
  Tracking_Wire         = 0;
  Mower_Track_To_Exit   = 0;
  Mower_Lost            = 0;
  Loop_Cycle_Mowing     = 0;
  Manuel_Mode           = 0;
  Motor_Action_Stop_Motors();
  Motor_Action_Stop_Spin_Blades();
  Turn_Off_Relay();
  }

void Manouver_Hibernate_Mower() {

  Mower_Docked          = 0;
  Mower_Parked          = 0;
  Mower_Running         = 0;
  Mower_Parked_Low_Batt = 0;
  Mower_Track_To_Charge = 0;
  Tracking_Wire         = 0;
  Mower_Track_To_Exit   = 0;
  Mower_Lost            = 1;
  Loop_Cycle_Mowing     = 0;
  Manuel_Mode           = 0;
  Motor_Action_Stop_Motors();
  Motor_Action_Stop_Spin_Blades();
  Turn_Off_Relay();
  }

// Mower is sent to the charging station after low volts are detected or mebrane key input.
void Manouver_Go_To_Charging_Station() {
  Mower_Docked          = 0;
  Mower_Parked          = 0;
  Mower_Running         = 0;
  Mower_Parked_Low_Batt = 0;
  Mower_Track_To_Charge = 1;
  Tracking_Wire         = 1;
  Mower_Track_To_Exit   = 0;
  Mower_Lost            = 0;
  Loop_Cycle_Mowing     = 0;
  Manuel_Mode           = 0;
  if (WIFI_Enabled == 1) Get_WIFI_Commands();
  delay(5);
  Motor_Action_Stop_Spin_Blades();
  Motor_Action_Stop_Motors();
  delay(2000);
  Turn_On_Relay();
  delay(500);
  Compass_Turn_Mower_To_Home_Direction();
  Manouver_Find_Wire_Track();
  Track_Perimeter_Wire_To_Dock();
  }

void Manouver_Exit_To_Zone_X() {
   // Zone 1 or Zone 2 and the Wire itterations are set on the Membrane Buttons.
   // These values are then crried into the following functions.  
   Turn_On_Relay();
   delay(1000);
   Manouver_Mower_Exit_Dock();
   Manouver_Exit_From_Docking_Station();                         // Move the Mower into position backing out of the docking station
   if (Perimeter_Wire_Enabled == 1) {
     Mower_Track_To_Exit = 1;
     TestforBoundaryWire();
     delay(50);
     if (Wire_Detected == 1) {
       Manouver_Find_Wire_Track();                                   // Located the boundary wire
       Track_Wire_From_Dock_to_Zone_X();
       Manouver_Move_Into_Garden_Zone_X();
       Manouver_Start_Mower();
     }
    if (Wire_Detected == 0) {
        Serial.println("");
        Serial.println("Perimeter Wire not detected");
        Manouver_Park_The_Mower();
      }
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
     delay(500);
     distance_blockage = PingSonarX(trigPin1, echoPin1, 1, 1, 1, 4, 0);
     delay(500);
     Serial.print("Distance measured from sonar :");
     Serial.println(distance_blockage);
     
     // if the sonar is measuring an opening as the distance is greater than 300cm then move forward in that direction.
     if (distance_blockage > 300) {
      while ( (inside == false) && (distance_blockage > 300) ){
        SetPins_ToGoForwards();
        Motor_Action_Go_Full_Speed();
        delay(500);
        ADCMan.run();
        UpdateWireSensor();
        PrintBoundaryWireStatus();
        distance_blockage = PingSonarX(trigPin1, echoPin1, 1, 1, 1, 4, 0); 
        delay(10);
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
