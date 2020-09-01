void Check_For_Errors() {

  Serial.print(F("|MMS:"));
  Serial.print(MowerMotionStatus);                    // Prints the current status to the Serial Printer for debugging
  Serial.print(F("|Error:"));                         // Prints the Error Number to the Serial Monitor
  Serial.print(Error);
  Serial.print(F("|"));

  if (MowerMotionStatus == 1) {                         // MotionMowerStatus of 1 is set by the above sensor checks indicating an error.
    //Serial.println(F("Inside Error Functions"));
    
    lcd.setCursor(0, 1);
    if (Error == 2) {                                   // Open Error Check
    }
    if (Error == 5) {                                   //Errors 5 and above will result in total disabalisation of the Mower.
      Serial.println(F(" No Battery"));
      lcd.setCursor(0, 1);
      lcd.print("Battery Out!!");
    }
    if (Error == 6) {  //Errors 5 and above will result in total disabalisation of the Mower.
      lcd.setCursor(0,1);
      lcd.print("WIRE NO SIGNAL");
      Serial.print("WIRE OFF!");
    }
    if ((Error == 7) && (Mower_Docked == 0)) {
      Serial.print(F("HOME"));
      StopSpinBlades();
      delay(1000);
      if (Compass_Mode == 1) Turn_Mower_To_Home_Direction();  
      FindWireTrack();
      Track_Perimeter_Wire_To_Dock();
      }
    Motion_StopMotors();
    StopSpinBlades();
    MowerMotionStatus = 0;                           //set to 0. At the end of the cosde Motionmowertstaus + 1 to bring back to 1
  }



  if ((Mower_Docked == 1)  ||  (Mower_Stopped == 1)) {                                //Overrides all other functions this Error check must come last in the Loop
    
    if (Mower_Docked == 1) {
        lcd.setCursor(0,1);
        lcd.print("Docked");
        }
    if (Mower_Stopped == 1) {
       lcd.clear();
       lcd.setCursor(0,1);
       lcd.print("WIFI Stop");
       Serial.println(F(""));
       Serial.print(F("Mower Stopped = "));
       Serial.println(Mower_Stopped);
       }
    
    lcd.setCursor(11,1);            // Spaces to the right & down
    if ((hour()) < 10) {                //moves the cursor to the right otherwise the first hour number from before is left behind on the LCD.
      lcd.print("0");
      lcd.setCursor(12,1);
      }
    lcd.print(hour());
    lcd.print(":");

    if ((minute()) < 10) {
      lcd.print("0");
      }
    lcd.print(minute());
    //Check_if_Charging();
    
    ADCMan.run();
    UpdateWireSensor();
    //TestforBatteryVoltage();  
 
    delay(100);
    TestforBoundaryWire();        
    ADCMan.run(); // Keep ADCMan running
    delay(5);
    Serial.print(F("Parked:"));
    Serial.print(Mower_Stopped);
    Serial.print(F("|"));
    Motion_StopMotors();
    StopSpinBlades();
    digitalWrite(Relay_Motors, HIGH);
    MowerMotionStatus = 0;
    Battery_NoBattery_Found = 0;
  }
}
