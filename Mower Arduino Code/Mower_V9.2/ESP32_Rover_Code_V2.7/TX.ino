//Transmits Data to the TFT e.g. sensor data from EEPROM

void Send_Data_To_TFT() {
    // Depending on the code received the following data set is sent through the Serial 3 port.
    //Serial.println("");

    // GPS Data Short
    if (TFT_Menu_Command == 15) {
      Serial.println("");
      delay(1500);
      Serial.println("TX to TFT");
      delay(5);

      TFT_Serial.print(GPS_WIFI_Enabled);
      TFT_Serial.println("\a");
      delay(300);
      TFT_Serial.flush();
      
      TFT_Serial.print(Simulation_Mode);
      TFT_Serial.println("\b");
      delay(300);
      TFT_Serial.flush();

      TFT_Serial.print(Fence);
      TFT_Serial.println("\c");
      delay(300); 
      TFT_Serial.flush();

      Serial.print(F("GPS_WIFI_Enabled = "));
      if (GPS_WIFI_Enabled == 1) Serial.println("Enabled");
      if (GPS_WIFI_Enabled == 0) Serial.println("Disabled");
      Serial.print(F("Simulation Mode = "));
      if (Simulation_Mode == 1) Serial.println("Enabled");
      if (Simulation_Mode == 0) Serial.println("Disabled");
      Serial.print(F("Fence = "));
      Serial.println(Fence);
      Serial.println(F(" "));
      TFT_Serial.flush();
      
      }

    
    // Save a new Fence Point to the NODEMCU Serial monitor.
    if (TFT_Menu_Command == 16) {
      Serial.println("");
      Serial.println(F("GPS Point Saved"));
      Blynk.virtualWrite(V1, "clr");
      Fence_Type_Create = 1;
      Fence_Point = 1;
      Create_GPS_Fence();

      // Location of the points just for information to the user.
      Serial.print("if (Fence == ) {");
      Serial.println("");
      Serial.print("   GPSMAX = __ ;            // GPSMAX is the last value in the array  e.g. GPSY[20] GPSMAX = 20");
      Serial.println("");
      Serial.println(F("   // Location : - - -Enter Location Here - - -"));
      Serial.println("");
      Serial.println("");
      Serial.println("");


    }

    // Save a new Fence Point to the NODEMCU Serial monitor.
    if (TFT_Menu_Command == 17) {
       Capture_Fence_Coordinates();
       Fence_Point = Fence_Point + 1;
       }

    if (TFT_Menu_Command == 18) {
       Serial.println("");
       Serial.println("");
       Serial.print("    GPSMAX = ");
       Serial.print(Fence_Point - 2);
       Serial.print(";");
       Serial.println("");
       Serial.println("    // Starting coordinates of the mower in Simulation Mode.");
       Serial.println("    if (Simulation_Mode == 1) {  Y_GPS = _; X_GPS = _; }");
       Serial.println("}");
       Serial.println("");
       Serial.println("");
       Serial.println("********************************************************");
       Serial.println("Fence Input Completed");     

    }


}




void Set_Output_Pins() {

  // Sets the pin to 3.3V or 0V depending if the mower is inside or outside the 
  // boundary fence.
  if ( Mower_In_Out == 0 ) {
    digitalWrite(GPS_Signal_Pin, LOW);       // OUTSIDE FENCE = 0V on Pin 26
    digitalWrite(LED, LOW);
    }
  if ( Mower_In_Out == 1 ) {
    digitalWrite(GPS_Signal_Pin, HIGH);      // INSIDE FENCE = 3.3V on Pin 26
    digitalWrite(LED, HIGH);
    }


  // Sets the pin to 3.3V or 0V depending if the GPS lock signal achieved
  if (( FIXED < 4  ) || ( Sats < Min_Sats)) digitalWrite(GPS_Lock_Pin, LOW);       // OUTSIDE FENCE = 0V on Pin 27
  if (( FIXED >= 4 ) && ( Sats >= Min_Sats)) digitalWrite(GPS_Lock_Pin, HIGH);      // INSIDE FENCE  = 3.3V on Pin 27

}
