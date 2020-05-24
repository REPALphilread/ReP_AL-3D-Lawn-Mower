//  Prints a visual display of the wire tracking in the Serial Monitor
//  to see how well the wire is being followed.  Adjusting the P value in the settings
//  can improve the wire tracking ability of the mower.

#ifdef DEBUG
  void PrintWirePosition() {
    int PrintMAG_Now = MAG_Now / Scale;
    int PrintInMax = InMax / Scale;
    int PrintInMid = InMid / Scale;
    int PrintInMin = InMin / Scale;
    int PrintOutMin = OutMin / Scale;
    int PrintOutMid = OutMid / Scale;
    int PrintOutMax = OutMax / Scale;


    for (int i = PrintInMax; i <= PrintOutMax; i++) {
      if (i == PrintInMax) Serial.print(F("|"));
      if (i == PrintInMid) Serial.print(F("|"));
      if (i == PrintInMin) Serial.print(F("|"));
      if (i == PrintOutMin) Serial.print(F("|"));
      if (i == PrintOutMid) Serial.print(F("|"));
      if (i == PrintOutMax) Serial.print(F("|"));
      if (i == PrintMAG_Now) Serial.print(F("X"));     //maybe change to MAG_Lasr...
      if (i == 0) Serial.print(F("0"));

      else Serial.print(F("."));

    }
    Serial.print(F("|MAG_Now:"));  Serial.print(MAG_Now); Serial.print(F("|"));
  }
#endif


// Function to follow the wire for a specific amount of time set by the itterations 'I'
// Robot tracks the wire until the itterations are exhausted.
void Track_Wire_From_Dock_to_Zone_X() {
  delay(100);
  ADCMan.run();
  if (Blade_Override == 1) {
    Motor_Action_Spin_Blades();
  }
  
  Tracking_Turn_Right = 0;                                // resets the tracking errors for LH and RH.
  Tracking_Turn_Left = 0;
  
  #ifdef DEBUG
    //uses the PID settings in the setup
    Serial.print(F("P = "));
    Serial.print(P);
    Serial.print(F(" / D = "));
    Serial.print(D);
    Serial.println(F(""));
  #endif
  Tracking_Wire = 1;
  Mower_Running = 0;
  MAG_Now = 0;                                                              // Reset Values
  MAG_Start = 0;
  MAG_Error = 0;
  MAG_Goal = 0;
  int Dock_Cycles = 0;
  delay(500);
  if (WIFI_Enabled == 1) Get_WIFI_Commands();
  delay(5);
  for (I = 0; I < Track_Wire_Itterations; I++) {                                              // Iterations 'I' before mower leaves the wire.
      if (Mower_Parked == 0) {
      delay(5);
      ADCMan.run();
      MAG_Start = perimeter.getMagnitude(0);                                // Gets the signal strength of the sensor
      MAG_Now = MAG_Start;
      delay(5);
      MAG_Error = (MAG_Goal - MAG_Start); 
      #ifdef DEBUG                                  // Calculates the Error to the center of the wire which is normally zero magnitude
        PrintWirePosition();
      #endif                                                  // Prints the overview to the Serial Monitor.
      //Check_Wire_Blockage();                                              // homework idea is to avoid anything in the way

      // Tracks the wire from the docking station in a Counter-Clockwise direction to the start position

      if (CCW_Tracking_To_Start == 1) {
      if (MAG_Error > 0) {                                                  // If the MAG_Error > 0 then turn right for CCW Tracking. PWM_left is set to max to turn right.
        // TURN RIGHT
        PWM_Left = PWM_MaxSpeed_LH;                                                     // sets the PWM to the max possible for the wheel
        PWM_Right = 255 - (MAG_Error * P);                      // Mag_Error * P is the value reduced from the max value set PWM and sent to the PWM
        if (PWM_Right > 255)  PWM_Right = 255;                              // PWM_Right capped to Max PWM of 255.
        if (PWM_Right >= 0) {
          SetPins_ToGoForwards();
          }


        if (PWM_Right < 0) {                                                // sets the mower to sharp turn to the right (wheels spin opposite) if the Error to the wire is large enough.
          PWM_Right = (-1 * PWM_Right) + 220 ;
          if (PWM_Right > 255) PWM_Right = 255;
          if (PWM_Right >= 0) SetPins_ToTurnRight();
          delay(5);
          }
        
        Motor_Action_Dynamic_PWM_Steering();                                      // Carries out the wheel PWM changes for steering on the wire
        #ifdef DEBUG
          Serial.print(F(" Turn Right "));
        #endif
        Tracking_Turn_Left = 0;                                             // Failsafe if the mower looses the wire.  If the mower is commanded to turn left or right
        Tracking_Turn_Right = Tracking_Turn_Right + 1;                      // too many times it is assumed that the mower is spinning and cant get back on the wire.
        if (Tracking_Turn_Right > Max_Tracking_Turn_Right) {                // if this is detected then a function is ran to find the wire again.
          Motor_Action_Stop_Motors();
          Tracking_Restart_Blocked_Path();
        }

      }
      if (MAG_Error <= 0) {                                                 // If the MAG_Error < 0 then turn left for CCW Tracking
        // TURN LEFT
        PWM_Right = 255;                                                    // PWM_Right set to max to rotate the mower to the left.
        PWM_Left = 255 + (MAG_Error * P);                       // + as mag_error is negative to adjust PWM
        if (PWM_Left > 255) PWM_Left = 255;                                 // PWM_Left capped to mex PWM of 255
        if (PWM_Left >= 0) {
          SetPins_ToGoForwards();   
          }


        if (PWM_Left < 0) {                                                 // sets the mower to sharp turn to the left (wheels spin opposite) if the Error to the wire is large enough.
          PWM_Left = (-1 * PWM_Left) + 220 ;
          if (PWM_Left > 255) PWM_Left = 255;
          SetPins_ToTurnLeft();
          delay(5);                               
          }
        
        Motor_Action_Dynamic_PWM_Steering();
        #ifdef DEBUG
          Serial.print(F(" Turn Left "));
        #endif
        Tracking_Turn_Right = 0;
        Tracking_Turn_Left = Tracking_Turn_Left + 1;
        if (Tracking_Turn_Left > Max_Tracking_Turn_Left) {
          Motor_Action_Stop_Motors();
          Tracking_Restart_Blocked_Path();
        }
      }
      #ifdef DEBUG
        Serial.print(F(" : MAG_Error="));
        Serial.println(MAG_Error);
      #endif
      Dock_Cycles = Dock_Cycles + 1;
      Loop_Cycle_Mowing = I;
      if (Dock_Cycles > 10) {
        Tracking_Wire = Tracking_Wire + 1;                            // Makes the wire tracking LED in the app blink.
        if (Tracking_Wire > 1) Tracking_Wire = 0;
        if (WIFI_Enabled == 1) Get_WIFI_Commands();
        Dock_Cycles = 0;
        
        }
      }
    }
  

  if (CW_Tracking_To_Start == 1) {
      // Add Code here for CW tracking to the exit zone.
      // Use the code above for CCW tracking to the docking station
      // as a template.
    
    }
  }  
Tracking_Wire = 0;
Loop_Cycle_Mowing = 0;

delay(5);


}


//  Track the Perimeter wire using a PID type method
//  This code tracks the boundary wire and by calculating the Perimeter Magnitude and calculating the distance to the center of the wire.
//  This error value of (position - center of wire) is mulitplied by the P value in the setup to send a PWM change to the left or right
//  wheel to bring the sensor back over the wire.*/


void Track_Perimeter_Wire_To_Dock()  {
  Motor_Action_Stop_Spin_Blades();
  Docked_Hits = 0;
  Check_if_Charging();                                                        // Checks if an amperage is detected on the charge wire
  Check_if_Docked();
  

  #ifdef DEBUG
    Serial.println(F(" Tracking the wire to the Garage: "));                     // Prints the PID values used.
    Serial.print(F("P = "));
    Serial.print(P);
    Serial.print(F(" / D = "));
    Serial.print(D);
    Serial.println(F(""));
  #endif

  Tracking_Wire = 1;
  Loop_Cycle_Mowing = 0;
  Mower_Running = 0;
  
  MAG_Now = 0;                                                              // Reset Values
  MAG_Start = 0;
  MAG_Error = 0;
  MAG_Goal = 0;
  int Dock_Cycles = 0;
  delay(5);
  if (CCW_Tracking_To_Charge == 1)  {  
    #ifdef DEBUG                                                 // Mower tracks the wire in a Counter Clockwise Direction
      Serial.println(F("TRACKING COUNTER-CLOCKWISE"));
    #endif
    while ((Mower_Docked == 0) && (Mower_Parked == 0)) {
      ADCMan.run();
      MAG_Start = perimeter.getMagnitude(0);                                    // Gets the signal strength of the sensor
      MAG_Now = MAG_Start;
      delay(5);
      MAG_Error = (MAG_Goal - MAG_Start);                                       // Calculates the Error to the center of the wire which is normally zero magnitude (remember - - is + )
      #ifdef DEBUG
        PrintWirePosition();                                                      // Prints the overview to the Serial Monitor.
      #endif
      Loop_Cycle_Mowing = Loop_Cycle_Mowing + 1;

      if (MAG_Error > 0) {                                                      // Trun the mower to the right if MAG_Error > 0 with a CCW track direction.
        // RIGHT TURN
        PWM_Left = 255;                                                         // Set PWM_Left to maximum
        PWM_Right = 255 - (MAG_Error * P);                                      // Mag_Error * P is the value reduced from the max value set PWM and sent to the PWM                 
        if (PWM_Right > 255) PWM_Right = 255;                                   // Caps the PWM_Right to 255
        if (PWM_Right >= 0) {
          SetPins_ToGoForwards();
          }
       
        
        if (PWM_Right < 0) {                                                    // Set the wheels to rotate around the axis if a sharp turn is required.
          PWM_Right = (-1 * PWM_Right) + 220 ;                                  // change the negative value to a positive for the PWM input to the motor bridge.
          if (PWM_Right > 255) PWM_Right = 255;                                 // cap the maximum PWM to 255
          SetPins_ToTurnRight();                                                // set the motor bridge pins to turn left 
          }
       
        Motor_Action_Dynamic_PWM_Steering();                                          // Carries out the wheel PWM changes for steering on the wire
        #ifdef DEBUG
          Serial.print(F(" Turn Right "));
        #endif
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
          }
        

        if (PWM_Left < 0) {                                                     // if the PWM calulated is below zero set the mower for a sharp turn
          PWM_Left = (-1 * PWM_Left) +220 ;                                          // make the negative value a positive one to input to the motor bridge
          if (PWM_Left > 255) PWM_Left = 255;                                   // if again the PWM is above 255 then cap it to 255
          SetPins_ToTurnLeft();                                                 // set the pins to sharp turn left  
          delay(5);
          }
          
        Motor_Action_Dynamic_PWM_Steering();
        #ifdef DEBUG
          Serial.print(F(" Turn Left "));
        #endif
        Tracking_Turn_Right = 0;
        Tracking_Turn_Left = Tracking_Turn_Left + 1;
        if (Tracking_Turn_Left > Max_Tracking_Turn_Left) {
          Tracking_Restart_Blocked_Path();
          if (Mower_Parked == 1) Mower_Docked = 1;
        }
      }
      #ifdef DEBUG
        Serial.print(F(" : MAG_Error="));
        Serial.print(MAG_Error);
      #endif
      Read_Serial1_Nano();
      Check_if_Charging();
      Check_if_Docked();
      Dock_Cycles = Dock_Cycles + 1;
      if (Dock_Cycles > 10) {
        Tracking_Wire = Tracking_Wire + 1;                            // Makes the wire tracking LED in the app blink.
        if (Tracking_Wire > 1) Tracking_Wire = 0;
        Mower_Running = 0;
        if (WIFI_Enabled == 1) Get_WIFI_Commands();
        Dock_Cycles = 0;
        }
      }
  Loop_Cycle_Mowing = 0;  
  }

  if (CW_Tracking_To_Charge == 1)  {                             // Mower tracks the wire in a Counter Clockwise Direction
    #ifdef DEBUG
      Serial.println(F("TRACKING ---  CLOCKWISE"));               // With the same functions as above
    #endif
    while ((Mower_Docked == 0) && (Mower_Parked == 0)) {
      delay(5);
      ADCMan.run();
      MAG_Start = perimeter.getMagnitude(0);
      MAG_Now = MAG_Start;
      delay(5);
      MAG_Error = (MAG_Goal - MAG_Start);
      #ifdef DEBUG
        PrintWirePosition();
      #endif
      Loop_Cycle_Mowing = Loop_Cycle_Mowing + 1;

      // Turn the Mower to the left to get back on the wire. Clock Wise Motion around the wire
      // Power down the left wheel and full power right wheel to turn left
      if (MAG_Error > 0) {                                      // if MAG_Error > 0 then Turn left in CW tracking                      
        // Turn LEFT
        PWM_Right = 255;                                        // Set the right wheel to max PWMto turn left
        PWM_Left = 255 - (MAG_Error * P);
        if (PWM_Left > 255) PWM_Left = 255;                     // 
        if (PWM_Left >= 0) {
          SetPins_ToGoForwards();                               // keep the mower moving forward
          }

        
        if (PWM_Left < 0) {
          PWM_Left = (-1 * PWM_Left) + 220;
          if (PWM_Left > 255) PWM_Left = 255;
          SetPins_ToTurnLeft();
          delay(5);
          }
        
        Motor_Action_Dynamic_PWM_Steering();                          // send the PWM values to the motor driver.
        #ifdef DEBUG
          Serial.print(F(" Turn Left "));
        #endif
        Tracking_Turn_Right = 0;
        Tracking_Turn_Left = Tracking_Turn_Left + 1;
        if (Tracking_Turn_Left > Max_Tracking_Turn_Left) {
          Tracking_Restart_Blocked_Path();
        }
      }
      if (MAG_Error <= 0) {                                     // Turn the Mower to the right to get back on the wire.
        //Turn Right
        PWM_Left = 255;
        PWM_Right = 255 + (MAG_Error * P);          // + as mag_error is negative to adjust PWM
        if (PWM_Right > 255) PWM_Right = 255;
        if (PWM_Right >= 0) {
          SetPins_ToGoForwards();
          }


        if (PWM_Right < 0) {
          PWM_Right = (-1 * PWM_Right) + 220 ;
          if (PWM_Right > 255) PWM_Right = 255;
          if (PWM_Right >= 0) SetPins_ToTurnRight();
        }

        Motor_Action_Dynamic_PWM_Steering();
        #ifdef DEBUG
          Serial.print(F(" Turn Right "));
        #endif
        Tracking_Turn_Left = 0;
        Tracking_Turn_Right = Tracking_Turn_Right + 1;
        if (Tracking_Turn_Right > Max_Tracking_Turn_Right) {
          Tracking_Restart_Blocked_Path();
          }

      }
      #ifdef DEBUG
        Serial.print(F(" : MAG_Error="));
        Serial.print(MAG_Error);
      #endif
      Read_Serial1_Nano();
      Check_if_Charging();
      Check_if_Docked();
      Dock_Cycles = Dock_Cycles + 1;
      if (Dock_Cycles > 10) {
        Tracking_Wire = Tracking_Wire + 1;                            // Makes the wire tracking LED in the app blink.
        if (Tracking_Wire > 1) Tracking_Wire = 0;
        Mower_Running = 0;
        if (WIFI_Enabled == 1) Get_WIFI_Commands();
        Dock_Cycles = 0;
        }
      }
  Loop_Cycle_Mowing = 0;  
  }
 Tracking_Wire = 0;
 Loop_Cycle_Mowing = 0;

}


//Starts an algorithym to find the wire again after it is lost in tracking
void Tracking_Restart_Blocked_Path() {
  Motor_Action_Stop_Motors();
  #ifdef DEBUG
    Serial.println(F("Possible Blocked Path - Trying to Avoid"));
  #endif
  Mower_Running = 1;
  Tracking_Wire = 1;
  if (WIFI_Enabled == 1) Get_WIFI_Commands();                                   // TX and RX data from NodeMCU
  delay(1000);
  Mower_Running = 0;
  Tracking_Wire = 0;
  if (WIFI_Enabled == 1) Get_WIFI_Commands();                                   // TX and RX data from NodeMCU
  delay(1000);
  Mower_Running = 1;
  Tracking_Wire = 1;
  if (WIFI_Enabled == 1) Get_WIFI_Commands();                                   // TX and RX data from NodeMCU
  delay(1000);
  Mower_Running = 0;
  Tracking_Wire = 0;
  if (WIFI_Enabled == 1) Get_WIFI_Commands();                                   // TX and RX data from NodeMCU
  delay(1000);
  
  if (WIFI_Enabled == 1) Get_WIFI_Commands();                                   // TX and RX data from NodeMCU
  if (Mower_Parked != 1) {                                                                              // If Pause has been pressed dont carry on.
    SetPins_ToGoBackwards();
    delay(500);
    Motor_Action_Go_Full_Speed();
    delay (5000);                                                 //Reversing Time in seconds
    Motor_Action_Stop_Motors();
    delay(2000);
    Tracking_Turn_Left = 0;                                       // Resets the tracking error counters
    Tracking_Turn_Right = 0;                                      // Resets the tracking error counters
    delay(500);
    Mower_Running = 0;
    Tracking_Wire = 0;
    if (WIFI_Enabled == 1) Get_WIFI_Commands();                                   // TX and RX data from NodeMCU
    if (Compass_Activate == 1) Compass_Turn_Mower_To_Home_Direction();
    Manouver_Find_Wire_Track();
    //Track_Perimeter_Wire_To_Dock();
    }
  
}  
