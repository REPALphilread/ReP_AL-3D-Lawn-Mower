void Special_Cut_Under_Trampoline_Function() {
  //Enter Code Here
}



// after wire tracking the code to bering the mower to a sensible position away from the wire
// This poart of the code should eb modified to fit your garden needs
void Special_Move_Into_Garden_Zone_X() {
    Serial.println("start mower code here");
    Motor_Action_Stop_Motors();                                     // Stop the wheel motors
    SetPins_ToTurnLeft();                                           // Turn left
    Motor_Action_Go_Full_Speed();                                       
    delay(1400);                                                     // Turn left for 0.7seconds
    Motor_Action_Stop_Motors();                                     // Stop the wheel motors.
    SetPins_ToGoForwards();                                         // Get ready to move off
    }

void Special_Exit_From_Docking_Station() {
    lcd.clear();
    lcd.print("Exiting Garage");
    delay(2000);
    SetPins_ToGoBackwards();                                        // Prepare motors pins to go Backwards
    Motor_Action_GoFullSpeed_Out_Garage();                          // Turn the wheels
    delay (7000);                                                   // Backwards time
    Motor_Action_Stop_Motors;                                       // Stop
    SetPins_ToTurnLeft();                                           // Prepare motors to turn left
    Motor_Action_Turn_Speed();                                      // Turn the wheels
    delay(1000);                                                    // Turn time
    Motor_Action_Stop_Motors;                                       // Stop
    SetPins_ToGoBackwards();                                        // Set again to go backwards
    Motor_Action_Go_Full_Speed();                                   // Turn the wheels
    delay (500);                                                    // Backwards Time
    SetPins_ToTurnLeft();                                           // Set to go left             
    Motor_Action_Turn_Speed();                                      // Turn the wheels
    delay(200);                                                     // Turning time
    Motor_Action_Stop_Motors();                                     // Stop
    SetPins_ToGoForwards();                                         // Set to go wheel motor pins to go forwards
    Motor_Action_Stop_Motors();                                     // Stop / Park the mower here
    lcd.clear();                                                    // Clears the LCD display
    lcd.print("Garage Clear");                                      // Prints to the LCD screen       
    delay(500);
    lcd.clear();
    }



void Specials_Find_Wire_Track()  {

  Serial.println(F("Lost Mower - find wire Track"));
  lcd.clear();
  lcd.print("Finding Wire...  ");
  Motor_Action_Stop_Spin_Blades();
  delay(5);
  Abort_Wire_Find = 0;
  No_Wire_Found = 0;
  TestforBoundaryWire();                                                                    // Check to see that the wire is on.

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

    // First go backwards if the mower is outside the wire
    if ( inside == false) {                                    // If the mower is outside the wire then run the following code.
      ADCMan.run();
      UpdateWireSensor();
      PrintBoundaryWireStatus();
      Motor_Action_Stop_Motors();                                                           // Stop all wheel motion
      delay(1000);
      SetPins_ToGoBackwards();                                                              // Set the mower to back up
      delay(100);
      lcd.clear();
      lcd.print("Backwards Try...  ");
      lcd.setCursor(0,1);
      lcd.print("Finding Wire  ");
      delay(100);
      while (( inside != true) && (Abort_Wire_Find == 0) ){                                 // While the mower is still outside the fence run this code
        Motor_Action_Go_Full_Speed();                                                       // Go full speed (in this case backwards)
        UpdateWireSensor();                                                                 // Read the wire sensor and see of the mower is now  or outside the wire
        ADCMan.run();
        PrintBoundaryWireStatus();                                                          // Prints of the status of the wire sensor readings.
        Serial.println("");
        }
      }
      
      Motor_Action_Stop_Motors();
      delay(5);
      }

    // Code to go forwards until the mower is outside/ON the wire
    if ( inside == true) {             // If the Mower is situated  the wire then run the following code.
        ADCMan.run();
        UpdateWireSensor();
        Serial.println(F("CODE POSITION - MOTOR FORWARDS LOOP:  If statements"));
        PrintBoundaryWireStatus();
        Motor_Action_Stop_Motors();
        delay(1000);  
        SetPins_ToGoForwards();                                                             // Set the motors to move the mower forwards
        delay(100);
        lcd.clear();
        lcd.print("Forward Try...  ");
        lcd.setCursor(0,1);
        lcd.print("Finding Wire  ");
        delay(100);
        int cycle = 0;                                                                      // resets the cycles
        while ( inside != false) {                               // Move the mower forward until mower is outisde/ON the wire fence or 500 cycles have passed
          cycle = cycle + 1;
          Motor_Action_Go_Full_Speed();                                                     // Go full speed (in this case forwards)
          UpdateWireSensor();                                                               // Read the wire sensor and see of the mower is now  or outside the wire
          ADCMan.run();
          PrintBoundaryWireStatus();                                                        // Prints of the status of the wire sensor readings.
          }
          if (cycle > Max_Cycle_Wire_Find) {                                                                // Track forwards for 500 cycles
            No_Wire_Found = 1;                                                              // if mower is still tracking after 500 cycles then cancel the find.
            Serial.println("Max Forward Cycles reached");
          }
        }
      Motor_Action_Stop_Motors();
      delay(5);
    }
  
