// Function to follow the wire for a specific amount of time set by the itterations 'I'
// Robot tracks the wire until the itterations are exhausted.
void Track_Wire_From_Dock_to_Zone_X() {
  delay(100);
  ADCMan.run();
  if (Blade_Override == 1) {
    SpinBlades();
  }
  lcd.setCursor(0, 0);
  lcd.print("Exit Docking to");                                             // into the garden at a good position to start Mowing
  lcd.setCursor(0, 1);
  if (Exit_Zone == 1) lcd.print("Zone 1");
  if (Exit_Zone == 2) lcd.print("Zone 2");
  delay(1000);                                           // Prints info to LCD display

  //uses the PID settings in the setup
  Serial.print("P = ");
  Serial.print(P);
  Serial.print(" / D = ");
  Serial.print(D);
  Serial.println("");

  MAG_Now = 0;                                                              // Reset Values
  MAG_Start = 0;
  MAG_Error = 0;
  MAG_Goal = 0;
  delay(500);
  for (I = 0; I < Track_Wire_Itterations; I++) {                                              // Iterations 'I' before mower leaves the wire.
      delay(5);
      ADCMan.run();
      MAG_Start = perimeter.getMagnitude(0);                                // Gets the signal strength of the sensor
      MAG_Now = MAG_Start;
      delay(5);
      MAG_Error = (MAG_Goal - MAG_Start);                                   // Calculates the Error to the center of the wire which is normally zero magnitude
      PrintWirePosition();                                                  // Prints the overview to the Serial Monitor.
      //Check_Wire_Blockage();                                              // homework idea is to avoid anything in the way

      // Tracks the wire from the docking station in a Counter-Clockwise direction to the start position
      // Currently no code written to track in CCW direction.  (My mower always tracks in that diretion) Add here if needed.
      if (Track_Wire_Start_pos_CCW == 1) {
      if (MAG_Error > 0) {                                                  // If the MAG_Error > 0 then turn right for CCW Tracking. PWM_left is set to max to turn right.
        // TURN RIGHT
        PWM_Left = 255;                                                     // sets the PWM to the max possible for the wheel
        PWM_Right = PWM_MaxSpeed_RH - (MAG_Error * P);                      // Mag_Error * P is the value reduced from the max value set PWM and sent to the PWM
        if (PWM_Right > 255)  PWM_Right = 255;                              // PWM_Right capped to Max PWM of 255.
        if (PWM_Right >= 0) {
          SetPins_ToGoForwards();
          lcd.setCursor(15, 0);
          lcd.print(" ");
          }


        if (PWM_Right < 0) {                                                // sets the mower to sharp turn to the right (wheels spin opposite) if the Error to the wire is large enough.
          PWM_Right = (-1 * PWM_Right) + 220 ;
          if (PWM_Right > 255) PWM_Right = 255;
          if (PWM_Right >= 0) SetPins_ToTurnRight();
          delay(5);
          lcd.setCursor(15, 0);
          lcd.print("*");
          }
        
        Motion_Dynamic_PWM_Steering();                                      // Carries out the wheel PWM changes for steering on the wire
        Serial.print(" Turn Right ");
        Tracking_Turn_Left = 0;                                             // Failsafe if the mower looses the wire.  If the mower is commanded to turn left or right
        Tracking_Turn_Right = Tracking_Turn_Right + 1;                      // too many times it is assumed that the mower is spinning and cant get back on the wire.
        if (Tracking_Turn_Right > Max_Tracking_Turn_Right) {                // if this is detected then a function is ran to find the wire again.
          Tracking_Restart_Blocked_Path();
        }

      }
      if (MAG_Error <= 0) {                                                 // If the MAG_Error < 0 then turn left for CCW Tracking
        // TURN LEFT
        PWM_Right = 255;                                                    // PWM_Right set to max to rotate the mower to the left.
        PWM_Left = PWM_MaxSpeed_LH + (MAG_Error * P);                       // + as mag_error is negative to adjust PWM
        if (PWM_Left > 255) PWM_Left = 255;                                 // PWM_Left capped to mex PWM of 255
        if (PWM_Left >= 0) {
          SetPins_ToGoForwards();   
          lcd.setCursor(15, 0);
          lcd.print(" "); 
          }


        if (PWM_Left < 0) {                                                 // sets the mower to sharp turn to the left (wheels spin opposite) if the Error to the wire is large enough.
          PWM_Left = (-1 * PWM_Left) + 220 ;
          if (PWM_Left > 255) PWM_Left = 255;
          SetPins_ToTurnLeft();
          delay(5);
          lcd.setCursor(15, 0);
          lcd.print("*");
          }
        
        Motion_Dynamic_PWM_Steering();
        Serial.print(" Turn Left ");
        Tracking_Turn_Right = 0;
        Tracking_Turn_Left = Tracking_Turn_Left + 1;
        if (Tracking_Turn_Left > Max_Tracking_Turn_Left) {
          Tracking_Restart_Blocked_Path();
        }
      }
      Serial.print(" : MAG_Error=");
      Serial.println(MAG_Error);
    }

  if (Track_Wire_Start_pos_CW == 1) {
      // Add Code here for CW tracking to the exit zone.
      // Use the code below for CW tracking to the docking station
      // as a template.
    
    }
  }
    Blade_Override = 0;
}



/*Print off Boundary Wire Status and Values of the Perimeter Function*/
void PrintBoundaryWireStatus() {
  Serial.println(".............................................");
  //perimeter.isInside(0);
  //inside = perimeter.isInside(0);
  Serial.print("Inside (1) or Outside (0) Fence:  ");
  Serial.println((perimeter.isInside(0)));
  Serial.print("mag: ");
  Serial.print((int)perimeter.getMagnitude(0));
  Serial.print("    smag: ");
  Serial.print((int)perimeter.getSmoothMagnitude(0));
  Serial.print("     qaulity: ");
  Serial.println((perimeter.getFilterQuality(0)));
  Serial.print("Inside Variable: ");
  Serial.println(inside);
  Serial.println(".............................................");
}


/* Find the Boundary Wire and park the mower close to it for further instructions e.g. wire tracking
******************************************************************************************************/

void FindWireTrack()  {

  Serial.println("Find Wire Track Function Activated");
  lcd.clear();
  lcd.print("Finding Wire...");
  StopSpinBlades();
  delay(5);
  TestforBoundaryWire();                            // Check to see that the wire is on.

  for (int i = 0; i <= 1; i++) {
    Serial.print("Position Try = ");
    Serial.println(i);
    ADCMan.run();
    UpdateWireSensor();
    delay(20);
    ADCMan.run();
    UpdateWireSensor();
    delay(20);
    Serial.println("before if loops start");
    PrintBoundaryWireStatus();

    if (inside == false) {                                              // If the mower is outside the wire then run the following code.
      ADCMan.run();
      UpdateWireSensor();
      Serial.println("Mower is situated outside the perimeter wire fence");
      PrintBoundaryWireStatus();
      Motion_StopMotors();                                              // Stop all wheel motion
      delay(1000);
      SetPins_ToGoBackwards();                                          // Set the mower to back up
      delay(100);
      lcd.clear();
      lcd.print("Backwards Try...");
      lcd.setCursor(0,1);
      lcd.print("Finding Wire");
      delay(100);
      while (inside != true) {                                          // While the mower is still outside the fence run this code
        Motion_GoFullSpeed();                                           // Go full speed (in this case backwards)
        UpdateWireSensor();                                             // Read the wire sensor and see of the mower is now inside or outside the wire
        ADCMan.run();
        PrintBoundaryWireStatus();                                      // Prints of the status of the wire sensor readings.
      }
      Motion_StopMotors();
      delay(5);
    }


    if (inside == true)  {                                            // If the Mower is situated inside the wire then run the following code.
      ADCMan.run();
      UpdateWireSensor();
      Serial.println("CODE POSITION - MOTOR FORWARDS LOOP: inside If statements");
      PrintBoundaryWireStatus();
      Motion_StopMotors();
      delay(1000);
      SetPins_ToGoForwards();                                           // Set the motors to move the mower forwards
      delay(100);
      lcd.clear();
      lcd.print("Forward Try...");
      lcd.setCursor(0,1);
      lcd.print("Finding Wire");
      delay(100);
      while (inside != false) {                                         // Do this loop until mower is back inside the wire fence
        Motion_GoFullSpeed();                                           // Go full speed (in this case forwards)
        UpdateWireSensor();                                             // Read the wire sensor and see of the mower is now inside or outside the wire
        ADCMan.run();
        PrintBoundaryWireStatus();                                      // Prints of the status of the wire sensor readings.
      }
      Motion_StopMotors();
      delay(5);
    }
  Motion_StopMotors();
  delay(1000);
  }

  // position the mower further over the wire so it has space to turn 90° onto the wire.
  SetPins_ToGoForwards();                                           
  delay(100);
  Motion_GoFullSpeed();
  delay(500);
  Motion_StopMotors();

  
  lcd.setCursor(0,1);
  lcd.print("Turn to Wire depending on Setup for CW or CCW tracking."); 
  if ((Error == 7) && (Mower_Docked == 0)) {
     if (Track_Wire_CW_Charge == 1) {
        SetPins_ToTurnRight();                          // Track perimeter wire in a Clockwise Direction to the charging station
        Serial.println("CW Tracking Selected");
     }
     if (Track_Wire_CCW_Charge == 1) {
        SetPins_ToTurnLeft(); 
        Serial.println("CCW Tracking Selected"); 
     }
  }
  else {
    Serial.println("LEFT INPUT HERE............");
    SetPins_ToTurnLeft();
    }
    
  delay(20);
  // Pins are now set to turn from the above logic.
  
  // Check again that the mower is outside the wire.
  ADCMan.run();
  UpdateWireSensor();
  ADCMan.run();
  PrintBoundaryWireStatus();                                      // Prints of the status of the wire sensor readings
  delay(20);

  while (inside == false) {
        while (inside != true) {                                         // Do this loop until mower is back inside the wire fence
        Motion_GoFullSpeed();                                           // Go full speed (in the case turning as set by the previous logic)
        UpdateWireSensor();                                             // Read the wire sensor and see of the mower is now inside or outside the wire
        ADCMan.run();
        PrintBoundaryWireStatus();                                      // Prints of the status of the wire sensor readings.
      }
  Motion_StopMotors();                                                // Stop the mower on the wire facing the correct direction.
  }
  
  Motion_StopMotors();
  Serial.println("Track Wire Function Complete - ON WIRE??");
  lcd.clear();
  lcd.print("Wire Found...");
  delay(2000);                                                         // 2 second pause to check result
  SetPins_ToGoForwards();                                           
  delay(100);
  }


// Function to re-find the wire if the mower looses the wire while mowing
// 3 outside the wires ativates this function. Sonar and wire function is then used to re-find the wire.
void Outside_Wire_ReFind_Function(){
  StopSpinBlades(); 
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
        Motion_GoFullSpeed();
        delay(500);
        ADCMan.run();
        UpdateWireSensor();
        PrintBoundaryWireStatus();
        distance_blockage = PingSonarX(trigPin1, echoPin1, 1, 1, 1, 4, 0); 
        delay(10);
      }
     Motion_StopMotors;
     ADCMan.run();
     UpdateWireSensor();
     PrintBoundaryWireStatus();
     }

     // if the sonar is measuring something less than 300cm then turn to the left and measure again
     // keep turning 'while function' until a path is open.
     while (distance_blockage < 300) {
       SetPins_ToTurnLeft();
       delay(200);
       Motion_TurnSpeed();                                                             
       delay(100); 
       distance_blockage = PingSonarX(trigPin1, echoPin1, 1, 1, 1, 4, 0); 
       delay(10);
     }
     Motion_StopMotors;
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


void Check_Wire_Blockage() {
    distance_blockage = PingSonarX(trigPin1, echoPin1, 1, 1, 1, 4, 0);          //use SONAR1 to check if a blockage is in fron of the mower.
    delay(2);
    if (distance_blockage < maxdistancesonar) {
      Blockage_Registered = Blockage_Registered + 1;
      Serial.println("**** Find Wire Blockage Registered ******");
    }   

    else  {
    Blockage_Registered = 0;
    }


  if (Blockage_Registered >= Max_Number_Blockage_Registered) {
      Serial.println("Blockage Detected while finding wire....");
      Motion_StopMotors();
      delay(2000);
      lcd.setCursor(0, 8);
      lcd.print("Reversing Block");
      SetPins_ToGoBackwards();
      Motion_GoFullSpeed();
      delay (3000);                                                                               // Time given to Reverse  the Mower
      Motion_StopMotors();
      SetPins_ToTurnRight();
      delay(100);
      Motion_GoFullSpeed();
      delay (2000); 
      }

}


/* Prints a visual display of the wire tracking in the Serial Monitor
    to see how well the wire is being followed.  Adjusting the P value in the settings
    can improve the wire tracking ability of the mower.
*/

void PrintWirePosition() {
  int PrintMAG_Now = MAG_Now / Scale;
  int PrintInMax = InMax / Scale;
  int PrintInMid = InMid / Scale;
  int PrintInMin = InMin / Scale;
  int PrintOutMin = OutMin / Scale;
  int PrintOutMid = OutMid / Scale;
  int PrintOutMax = OutMax / Scale;


  for (int i = PrintInMax; i <= PrintOutMax; i++) {
    if (i == PrintInMax) Serial.print("|");
    if (i == PrintInMid) Serial.print("|");
    if (i == PrintInMin) Serial.print("|");
    if (i == PrintOutMin) Serial.print("|");
    if (i == PrintOutMid) Serial.print("|");
    if (i == PrintOutMax) Serial.print("|");
    if (i == PrintMAG_Now) Serial.print("X");     //maybe change to MAG_Lasr...
    if (i == 0) Serial.print("0");

    else Serial.print(".");

  }
  Serial.print("  MAG_Now= ");  Serial.print(MAG_Now); Serial.print(" :  ");
}



/* Track the Perimeter wire using a PID type method
  This code tracks the boundary wire and by calculating the Perimeter Magnitude and calculating the distance to the center of the wire.
  This error value of (position - center of wire) is mulitplied by the P value in the setup to send a PWM change to the left or right
  wheel to bring the sensor back over the wire.*/


void Track_Perimeter_Wire_To_Dock()  {
  lcd.clear();
  lcd.print("Tracking to..");
  lcd.setCursor(0, 1);
  lcd.print("Charging Station");                                            // Prints info to LCD display
  StopSpinBlades();
  Check_if_Docked();                                                        // Checks if an amperage is detected on the charge wire
  

  Serial.println(" Tracking the wire to the Garage: ");                     // Prints the PID values used.
  Serial.print("P = ");
  Serial.print(P);
  Serial.print(" / D = ");
  Serial.print(D);
  Serial.println("");

  MAG_Now = 0;                                                              // Reset Values
  MAG_Start = 0;
  MAG_Error = 0;
  MAG_Goal = 0;
  delay(500);
  if (Track_Wire_CCW_Charge == 1)  {                                                   // Mower tracks the wire in a Counter Clockwise Direction
    Serial.println("TRACKING COUNTER-CLOCKWISE");
    while (Docked_Button_Pressed == 0) {
      lcd.clear();
      lcd.print("Tracking CCW to");
      lcd.setCursor(0, 1);
      lcd.print("Charging Station");                                            // Prints info to LCD display
      delay(5);
      ADCMan.run();
      MAG_Start = perimeter.getMagnitude(0);                                    // Gets the signal strength of the sensor
      MAG_Now = MAG_Start;
      delay(5);
      MAG_Error = (MAG_Goal - MAG_Start);                                       // Calculates the Error to the center of the wire which is normally zero magnitude (remember - - is + )
      PrintWirePosition();                                                      // Prints the overview to the Serial Monitor.

      if (MAG_Error > 0) {                                                      // Trun the mower to the right if MAG_Error > 0 with a CCW track direction.
        // RIGHT TURN
        PWM_Left = 255;                                                         // Set PWM_Left to maximum
        PWM_Right = 255 - (MAG_Error * P);                                      // Mag_Error * P is the value reduced from the max value set PWM and sent to the PWM                 
        if (PWM_Right > 255) PWM_Right = 255;                                   // Caps the PWM_Right to 255
        if (PWM_Right >= 0) {
          SetPins_ToGoForwards();
          lcd.setCursor(15, 0);
          lcd.print(" ");
          }
       
        
        if (PWM_Right < 0) {                                                    // Set the wheels to rotate around the axis if a sharp turn is required.
          PWM_Right = (-1 * PWM_Right) + 220 ;                                        // change the negative value to a positive for the PWM input to the motor bridge.
          if (PWM_Right > 255) PWM_Right = 255;                                 // cap the maximum PWM to 255
          SetPins_ToTurnRight();                                                // set the motor bridge pins to turn left 
          lcd.setCursor(15, 0);
          lcd.print("*");
          }
       
        Motion_Dynamic_PWM_Steering();                                          // Carries out the wheel PWM changes for steering on the wire
        Serial.print(" Turn Right ");
        Tracking_Turn_Left = 0;                                                 // Failsafe if the mower looses the wire.  If the mower is commanded to turn left or right
        Tracking_Turn_Right = Tracking_Turn_Right + 1;                          // too many times it is assumed that the mower is spinning and cant get back on the wire.
        if (Tracking_Turn_Right > Max_Tracking_Turn_Right) {                    // if this is detected then a function is ran to find the wire again.
          Tracking_Restart_Blocked_Path();
        }

      }
      if (MAG_Error <= 0) {                                                     // Turn the mower to the left if MAG_Error < 0 with a CCW track direction
        //LEFT TURN
        PWM_Right = 255;                                                        // Set the PWM_Right to maximum
        PWM_Left = 255 + (MAG_Error * P);                                       // + as mag_error is negative to adjust PWM
        if (PWM_Left > 255) PWM_Left = 255;                                     // cap PWM_Left to the maximum 
        if (PWM_Left >= 0) {
          SetPins_ToGoForwards();
          lcd.setCursor(15, 0);
          lcd.print(" ");
          }
        

        if (PWM_Left < 0) {                                                     // if the PWM calulated is below zero set the mower for a sharp turn
          PWM_Left = (-1 * PWM_Left) +220 ;                                          // make the negative value a positive one to input to the motor bridge
          if (PWM_Left > 255) PWM_Left = 255;                                   // if again the PWM is above 255 then cap it to 255
          SetPins_ToTurnLeft();                                                 // set the pins to sharp turn left  
          lcd.setCursor(15, 0);
          lcd.print("*");
          }
          
        Motion_Dynamic_PWM_Steering();
        Serial.print(" Turn Left ");
        Tracking_Turn_Right = 0;
        Tracking_Turn_Left = Tracking_Turn_Left + 1;
        if (Tracking_Turn_Left > Max_Tracking_Turn_Left) {
          Tracking_Restart_Blocked_Path();
        }
      }
      Serial.print(" : MAG_Error=");
      Serial.println(MAG_Error);
      Check_if_Docked();
    }
  }

  if (Track_Wire_CW_Charge == 1)  {                                                // Mower tracks the wire in a Counter Clockwise Direction
    Serial.println("TRACKING ---  CLOCKWISE");                              // With the same functions as above
    while (Docked_Button_Pressed == 0) {
      delay(5);
      lcd.clear();
      lcd.print("Tracking CW to");
      lcd.setCursor(0, 1);
      lcd.print("Charging Station");                                    // Prints info to LCD display
      ADCMan.run();
      MAG_Start = perimeter.getMagnitude(0);
      MAG_Now = MAG_Start;
      delay(5);
      MAG_Error = (MAG_Goal - MAG_Start);
      PrintWirePosition();

      // Turn the Mower to the left to get back on the wire. Clock Wise Motion around the wire
      // Power down the left wheel and full power right wheel to turn left
      if (MAG_Error > 0) {                                        // if MAG_Error > 0 then Turn left in CW tracking                      
        // Turn LEFT
        PWM_Right = 255;                                          // Set the right wheel to max PWMto turn left
        PWM_Left = PWM_MaxSpeed_LH - (MAG_Error * P);
        if (PWM_Left > 255) PWM_Left = 255;                       // 
        if (PWM_Left >= 0) {
          SetPins_ToGoForwards();                                   // keep the mower moving forward
          lcd.setCursor(15, 0);
          lcd.print(" ");
          }

        
        if (PWM_Left < 0) {
          PWM_Left = (-1 * PWM_Left) + 220;
          if (PWM_Left > 255) PWM_Left = 255;
          lcd.setCursor(15, 0);
          lcd.print("*");
          SetPins_ToTurnLeft();
          delay(5);
          }
        
        Motion_Dynamic_PWM_Steering();                            // send the PWM values to the motor driver.
        Serial.print(" Turn Left ");
        Tracking_Turn_Right = 0;
        Tracking_Turn_Left = Tracking_Turn_Left + 1;
        if (Tracking_Turn_Left > Max_Tracking_Turn_Left) {
          Tracking_Restart_Blocked_Path();
        }
      }
      if (MAG_Error <= 0) {                                         // Turn the Mower to the right to get back on the wire.
        //Turn Right
        PWM_Left = 255;
        PWM_Right = PWM_MaxSpeed_RH + (MAG_Error * P);              // + as mag_error is negative to adjust PWM
        if (PWM_Right > 255) PWM_Right = 255;
        if (PWM_Right >= 0) {
          SetPins_ToGoForwards();
          lcd.setCursor(15, 0);
          lcd.print(" ");
          }


        if (PWM_Right < 0) {
          PWM_Right = (-1 * PWM_Right) + 220 ;
          if (PWM_Right > 255) PWM_Right = 255;
          SetPins_ToTurnRight();
          lcd.setCursor(15, 0);
          lcd.print("*");
        }

        Motion_Dynamic_PWM_Steering();
        Serial.print(" Turn Right ");
        Tracking_Turn_Left = 0;
        Tracking_Turn_Right = Tracking_Turn_Right + 1;
        if (Tracking_Turn_Right > Max_Tracking_Turn_Right) {
          Tracking_Restart_Blocked_Path();
        }

      }
      Serial.print(" : MAG_Error=");
      Serial.println(MAG_Error);
      Check_if_Docked();
    }
  }
}



/*Starts an algorithym to find the wire again after it is lost in tracking*/
void Tracking_Restart_Blocked_Path() {
  Motion_StopMotors();
  Serial.println("Possible Blocked Path - Trying to Avoid");
  lcd.clear();
  lcd.print("Wire Lost.");
  lcd.setCursor(0, 1);
  lcd.print("Recovering.....");                                  // Prints info to LCD display
  SetPins_ToGoBackwards();
  delay(500);
  Motion_GoFullSpeed();
  delay (3000);                                                  //Reversing Time in seconds
  Motion_StopMotors();
  delay(2000);
//  if (Tracking_Turn_Left > Max_Tracking_Turn_Left) {             // Gives the mower a kick to the left to avaoid blockage
//    SetPins_ToTurnLeft();
//    delay(200);
//    Motion_TurnSpeed();                                         // Sets the speed of the turning motion
//    delay(1500);
//  }
//  if (Tracking_Turn_Right > Max_Tracking_Turn_Right) {           // Gives the mower a kick to the right to avaoid blockage
//    SetPins_ToTurnLeft();
//    delay(200);
//    Motion_TurnSpeed();                                         // Sets the speed of the turning motion
//    delay(1500);
//  }
  Tracking_Turn_Left = 0;                                        // Resets the tracking error counters
  Tracking_Turn_Right = 0;                                       // Resets the tracking error counters
  FindWireTrack();                                               // Refind the wire with the find wire function.
}


// checks to see if the mower is on the charging station
void Check_if_Docked () {

  Check_Serial_Communications();                                  // Reads the AMPs sensor from the Arduino Nano
  if ((AmpsReal >= 0.15) && (AmpsReal <=4) ){                     // if Amps are between this there is a charge detected.  Amps above 4 are discounted as a miscommunication
    delay(1000);
    Serial.println("Charging Current detected");
    Serial.print("Amps : ");
    Serial.println(AmpsReal);
    Motion_StopMotors();    
    Serial.println("Mower Docked");
    lcd.print("Docked in");
    lcd.setCursor(0, 1);
    lcd.print("Charging Station");                                // Prints info to LCD display
    delay(2000);
    Power_Down_Mower();                                           // Shits down the Mower ready for charging and mowing again.
    lcd.clear();
  }
  if (AmpsReal >= 4) {                                            // if Amps are above 4A then something is miscommunicating with the Nano and its discounted.
      lcd.setCursor(15, 1);                                       // displays a # briefly ón the LCD to show it happened and was discounted
      lcd.print("#");
      Serial.println();
      Serial.println("Error - Too many Amps for docking station....");
      Serial.println();
      }
  if (AmpsReal < 0.1) {
    Serial.print("Not Docked");
    lcd.setCursor(15, 1);
    lcd.print(" ");
  }

}
