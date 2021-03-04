void myTimerEvent()  {

}


void Run_Blynk_Data() {

  
  if(!Blynk.connected()) {                      // if disconnected from Blynk
    digitalWrite(GPS_Signal_Pin, LOW);          // Call OUTSIDE FENCE = 0V on Pin 26
    Serial.println("------------------------");
    Serial.println("ESP32 Disconnected from Blynk");
    Serial.println("Reconnecting ... ");
    Set_Mode_ESP32_WIFI ();
    WIFI_Connect();
    Blynk.run();
    timer.run();  
    }
  else {
    Blynk.run();
    timer.run();  
    //digitalWrite(LED, LOW);         //LED is inverted on a MODEMCU...

    // Only updates the GPS Fence every 20 loops to reduce the blinking on the screen
    if ((Show_GPS_Fence == 1) && (First_Plot == 1)) {    
      Serial.println("");
      Serial.println("------------------------");
      Serial.println("Plotting the Fence to the APP");
      Plot_GPS_Fence();
      Serial.println("------------------------");
      Serial.println("");
      First_Plot = 2;
    }
    First_Plot = First_Plot + 1;              // cycles forward the counter                 
    if (First_Plot == GPS_Fence_Update) First_Plot = 1;     // if the counter = 20 then resets it to 1 to plot the data again
    
    Update_Mower_Location_and_Info_on_Map();
  }

}



void Update_Mower_Location_and_Info_on_Map() {

  int index = (GPSMAX+1);
  // Updates the Mower Location
  myMap.location(index, Y_GPS, X_GPS, "Mower");   //Pin,pointIndex, lat, lon, "value"

  Blynk.virtualWrite(V2, Sats);               // Update Satellites
  Blynk.virtualWrite(V3, Y_GPS,8);          // Update Mower Y Lattitude Position
  Blynk.virtualWrite(V4, X_GPS,8);          // Update Mower X Longitude Position
  Blynk.virtualWrite(V5, Mower_In_Out);       // Update Mower In/Out Information
  if (GPS_Locked == 1) Blynk.virtualWrite(V6, 1023); 
  if (GPS_Locked == 0) Blynk.virtualWrite(V6, 0); 
}


void Plot_GPS_Fence() {

Serial.println("Blynk Plotting GPS Fence");

// Plots the GPS Fence on the map
for (int i = 1; i <=GPSMAX ; i++) {
  int index = i;
  myMap.location(index, GPSY[i], GPSX[i], i);   //Pin,pointIndex, lat, lon, "value"


  
  Serial.print("GPSY[");
  Serial.print(i -1);
  Serial.print("] = ");
  Serial.print(GPSY[i - 1], 8);   // Print the vlaue to 8 decimal places
  
  Serial.print("  GPSX[");
  Serial.print(i -1);
  Serial.print("] = ");
  Serial.println(GPSX[i - 1], 8);   // Print the vlaue to 8 decimal places
  }

}


void Plot_GPS_Logic_Limits() {
for (int i = 0; i <=GPSMAX ; i++) {
  int index = ((GPSMAX*2)+i);
  myMap.location(index, YL[i], XL[i], i);   //Pin,pointIndex, lat, lon, "value"
  }

}


void Blynk_Map_Update() {
    Blynk.run();
    timer.run();  
    myMap.location((Fence_Point - 1), GPSY6[Fence_Point - 1], GPSX6[Fence_Point - 1], (Fence_Point - 1));   //Pin,pointIndex, lat, lon, "value"
    Blynk.virtualWrite(V18, Sats);               // Update Satellites

}
