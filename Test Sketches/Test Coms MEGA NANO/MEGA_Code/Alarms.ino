void StartMower() {

  Serial.println("************************************************************");
  Serial.println("*****   ALARM - START MOWING from Docking Station   ********");
  Serial.println("************************************************************");

  lcd.backlight();                               // turn on backlight.
  delay(100);
  Mower_Docked = 0;
  lcd.clear();
  delay(1000);
  lcd.print("Mow Time!!");
  delay(2000);
  lcd.clear();
  lcd.print("PreChecks");
  ADCMan.run();
  delay(1000);

  // Either start mowing immediatley or use the exit procedure from the docking station
  if (Exit_Dock_To_Garden_Procedure == 1){                  // if this is selected then the extra function below are called.
    Exit_From_Docking_Station();                            // Set up the mower to exit the docking station 
    delay(200);
    Exit_From_Garage();                                     // Back the mower out of the docking station into the optimal Garden position.
    delay(500);
    FindWireTrack();      
    delay(300); 
    Track_Wire_Itterations = Track_Wire_Zone_2_Cycles;      // On the Alram function the mower always tracks to Zone 2
    Exit_Zone = 2;
    Track_Wire_From_Dock_to_Zone_X();                       // Tracks the boundary wire around the garden to  a specific point set by the itterations
    delay(500);
    Move_Into_Garden_Zone_X();                              // Move the mower into the correct position after the wire track.
    delay(200);
    Prepare_To_Mow();                                       // sets up the mower to start mowing.
    }
  else Prepare_To_Mow();                                    // just sets up the mower to mow right away.
     
}
