void RX_Get_Volts_From_Nano (){
        
        OK_Nano_Data_Volt_Received = 0;                                       // Resets the OK_Volt_Recieved to zero
        VoltsTX = Serial1.parseFloat();                                       // Read the voltage data from the Nano
        if(Serial1.read()== '\j'){
          

            if ((VoltsTX > 10) && (VoltsTX < 15)) {                           // If Nano Volts received is between 10 and 15
               OK_Nano_Data_Volt_Received = 0;                                // Value is considered good
               Battery_Voltage_Last = VoltsTX;
               Serial.print(F("V:"));    
               Serial.print(VoltsTX);
               Serial.print(F(" |"));
               
               }                                                              // and is printed to the serial monitor
             
            if ((VoltsTX < 10) || (VoltsTX > 15)) {         // Values above 15 or less than 10
              OK_Nano_Data_Volt_Received = 1;                                 // The value is discounted
              VoltsTX = Battery_Voltage_Last;
              Serial.print(F("V:"));
              Serial.print(VoltsTX);        
              Serial.print(F("*"));     
              Serial.print(F("|"));
              }
        }

        else {
            Serial.print(F("V:"));
            Serial.print("__.__");        
            Serial.print(F("*"));     
            Serial.print(F("|"));
            VoltsTX = Battery_Voltage_Last;
          
        }
}


void Process_Volt_Information()   {
//  Logic for how the battery readings should be handled
    
    if (VoltsTX < Battery_Min) {
      Low_Battery_Detected = (Low_Battery_Detected + 1);
      Serial.print("VLow:");
      Serial.print(Low_Battery_Detected);
      Serial.print("|");
      if (Low_Battery_Detected > Low_Battery_Instances_Chg) {
         Serial.println("Low Battery Detected");
         if (Use_Charging_Station == 1) Manouver_Go_To_Charging_Station();                       // Stops the mowing and sends the mower back to the charging station via the permieter wire
         if (Use_Charging_Station == 0) Manouver_Park_The_Mower_Low_Batt();                      // Parks the mower with a low battery warning
         }
      }

    if (VoltsTX >= Battery_Min) {
      Serial.print("VLow:");
      Serial.print(Low_Battery_Detected);
      Serial.print("|");
      Low_Battery_Detected = 0;
      }
}


// checks to see if the mower is on the charging station
void Check_if_Charging () {

  Charge_Detected = Serial1.parseInt();
  
  if(Serial1.read()== '\q') {
      if ((Charge_Detected == 1) || (Charge_Detected == 0)){                            // If the value recieved is equal to 1 or 0 as expected then print the value to the serial monitor
        Serial.print("Charging:");
        Serial.print(Charge_Detected);
        Serial.print("|");
        Print_Charging_LCD();
        }
      if ((Charge_Detected != 1) && (Charge_Detected !=0)) {
        Serial.print("Charging:");
        Serial.print(Charge_Detected);
        Serial.print("|");
        Print_Charging_LCD();
      }
      
    }
  else {
    Serial.print("Charging:");
    Serial.print("_|");  
    }
}

void Check_if_Docked() {
  
  if ((Charge_Detected == 1)){                                                // if Amps are between this there is a charge detected.  Amps above 4 are discounted as a miscommunication
      Docked_Hits = (Docked_Hits + 1) ;                                       // Filters out the bad Amp sensor readings so no single bad sensor reading will interupt the tracking
      
      if (Docked_Hits == Docked_Filter_Hits) {
        Motor_Action_Stop_Motors();    
        Serial.println(F("Charging Current detected"));
        Serial.println(F("Mower Docked"));
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Docked in");
        lcd.setCursor(0, 1);
        lcd.print("Charging Station");                                        // Prints info to LCD display
        delay(2000);
        Mower_Docked = 1;
        Manouver_Dock_The_Mower();                                                   // Shuts down the Mower ready for charging and mowing again.
        lcd.clear();
        }
 }
 else {
  Docked_Hits = 0;
 
 }

 
}
