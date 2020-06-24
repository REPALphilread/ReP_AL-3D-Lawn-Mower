//Transmits Data to the TFT e.g. sensor data from EEPROM

void Send_Data_To_TFT() {
    // Depending on the code received the following data set is sent through the Serial 3 port.

    // GPS Data Short
    if (TFT_Menu_Command == 15) {
            
      TFT_Serial.print(Fence);
      TFT_Serial.println("\h");
      delay(1000);
      TFT_Serial.flush();
            
      TFT_Serial.print(Min_Sats);
      TFT_Serial.println("\k");
      delay(1000); 
      TFT_Serial.flush();
    
      Serial.println("");
      Serial.print("Confirmstion Code Sent : ");
      Serial.println(RXCode); 
      Serial.print("Fence : ");
      Serial.println(Fence); 
      Serial.print("Min_Sats : ");
      Serial.println(Min_Sats); 
      delay(20);
      TFT_Serial.flush();
      
      }

    
    // Save a new Fence Point to the NODEMCU Serial monitor.
    if (TFT_Menu_Command == 16) {
      Serial.println(F("GPS Point Saved"));
      Fence_Type_Create = 1;
      Fence_Point = 1;
      Create_GPS_Fence();

      // Location of the points just for information to the user.
      Serial.println(F("Location : - - -Enter Location Here - - -"));


    }

    // Save a new Fence Point to the NODEMCU Serial monitor.
    if (TFT_Menu_Command == 17) {
       Capture_Fence_Coordinates();
       Fence_Point = Fence_Point + 1;


    }

    if (TFT_Menu_Command == 18) {
       Serial.println("");
       Serial.println("");
       Serial.println("");
       Serial.println("");
       Serial.println("Fence Input Completed");     

    }


}




void Set_Output_Pins() {

  // Sets the pin to 3.3V or 0V depending if the mower is inside or outside the 
  // boundary fence.
  if ( Mower_In_Out == 0 ) digitalWrite(GPS_Signal_Pin, LOW);       // OUTSIDE FENCE = 0V on Pin 14
  if ( Mower_In_Out == 1 ) digitalWrite(GPS_Signal_Pin, HIGH);      // INSIDE FENCE = 3.3V on Pin 14


  // Sets the pin to 3.3V or 0V depending if the GPS lock signal achieved
  if ( FIXED < 4 )  digitalWrite(GPS_Lock_Pin, LOW);       // OUTSIDE FENCE = 0V on Pin 14
  if ( FIXED >= 4 ) digitalWrite(GPS_Lock_Pin, HIGH);      // INSIDE FENCE = 3.3V on Pin 14

}
