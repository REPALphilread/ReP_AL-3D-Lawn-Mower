void Check_if_Raining_From_Nano () {

  if (Rain_Sensor_Installed == 1) {
      
      if ((Rain_Detected == 1) || (Rain_Detected == 0)){                            // If the value recieved is equal to 1 or 0 as expected then print the value to the serial monitor
        Serial.print(F("Rain:"));
        Serial.print(Rain_Detected);
        Serial.print("|");
        Print_Raining_LCD();
        if (Rain_Detected == 1) Rain_Hit_Detected = Rain_Hit_Detected + 1;
        if (Rain_Detected == 0) Rain_Hit_Detected = Rain_Hit_Detected - 1;
        if (Rain_Hit_Detected < 0) Rain_Hit_Detected = 0;
        }
      if ((Rain_Detected != 1) && (Rain_Detected !=0)) {
        Serial.print(F("Rain:"));
        Serial.print(Rain_Detected);
        Serial.print("|");
        Print_Raining_LCD();
        Rain_Detected = 0;
        Rain_Hit_Detected = Rain_Hit_Detected + 1; 
        }
      
    
  else {
    Serial.print(F("Rain:"));
    Serial.print("_|");  
    Print_Raining_LCD();
    Rain_Detected = 0;
    }
  
  Serial.print("RHit:");
  Serial.print(Rain_Hit_Detected);
  Serial.print("|");
  }

if ( (Mower_Running == 1) && (Rain_Hit_Detected == Rain_Total_Hits_Go_Home) ) {
  Motor_Action_Stop_Motors();
  Serial.println("");
  Serial.println("Rain detected");
  Serial.println("");
  Print_Raining_LCD();
  delay(2000);
  Manouver_Go_To_Charging_Station();            // If the Mower is running then go to the charge station. 
  }

}
