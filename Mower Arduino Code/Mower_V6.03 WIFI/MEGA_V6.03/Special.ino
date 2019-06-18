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
    delay(700);                                                     // Turn left for 0.7seconds
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
