 


void Process_Volt_Information()   {
//  Logic for how the battery readings should be handled
    
    if (Volts < Battery_Min) {
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

    if (Volts >= Battery_Min) {
      Serial.print("VLow:");
      Serial.print(Low_Battery_Detected);
      Serial.print("|");
      Low_Battery_Detected = 0;
      }
}



// checks to see if the mower is on the charging station
void Check_if_Charging() {


    if (Charging == 4)  {                            // If the value recieved is equal to 1 or 0 as expected then print the value to the serial monitor
        Serial.print("Charging:");
        Serial.print(Charging);
        Serial.print("|");
        Charge_Detected_MEGA = 1;
        Print_Charging_LCD();
        Serial.print("MEGA = 1|");
        }
    if (Charging == 0)  {                            // If the value recieved is equal to 1 or 0 as expected then print the value to the serial monitor
        Serial.print("Charging:");
        Serial.print(Charging);
        Serial.print("|");
        Charge_Detected_MEGA = 0;
        Print_Charging_LCD();
        }
      if ((Charging != 4) && (Charging !=0)) {
        Serial.print("Charging:");
        Serial.print(Charging);
        Serial.print("|");
        Charge_Detected_MEGA = 0;
        Print_Charging_LCD();
        }
      
    
  
//  else {
//    Serial.print("Charging:");
//   // Serial.print("_|");  
//   Serial.print(Charging);
//   Charge_Detected_MEGA = 0;
//   Serial.print("**|");
//    }
}



void Check_if_Docked() {
  
  if (Charge_Detected_MEGA == 1) {                                    // if Amps are between this there is a charge detected.  Amps above 4 are discounted as a miscommunication
        Motor_Action_Stop_Motors();    
        Serial.println(F("Charging Current detected"));
        Serial.println(F("Mower Docked"));
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Docked in");
        lcd.setCursor(0, 1);
        lcd.print("Charging Station");                                // Prints info to LCD display
        delay(2000);
        Mower_Docked = 1;
        Manouver_Dock_The_Mower();                                    // Shuts down the Mower ready for charging and mowing again.
        lcd.clear();
        }
   Serial.println("");
  }
        
void Calculate_Volt_Amp_Charge() {

if (Show_TX_Data == 1) {
      Serial.print("Amp:");
      Serial.print(RawValueAmp);
      Serial.print("|");
      Serial.print("Volt:");
      Serial.print(RawValueVolt);
      Serial.print("|");
      Serial.print("Rain:");
      Serial.print(Rain_Detected);
      Serial.print("|");
      }

// Calculate Amps from NANO RX Data
 int mVperAmp = 185;
 int ACSoffset = 2500; 
 double VoltageAmp = 0;
 double Amps = 0;
 VoltageAmp = (RawValueAmp / 1024.0) * 5000; // Gets you mV
 Amps =  ((VoltageAmp - ACSoffset) / mVperAmp);

 Serial.print(F("A:"));    
 Serial.print(Amps);
 Serial.print(F("|"));


// Calculate Voltage from NANO RX Data

 if (RawValueVolt > 100)  {
 float vout = 0.0;
 float R1 = 30000;      // 30000 Mower 2    Mower 1 30000
 float R2 = 7000;       // 7300 Mower 2     Mower 1 7500
 vout = (RawValueVolt * 5.0) / 1024.0; // see text
 Volts = vout / (R2/(R1+R2));
 Volts_Last = Volts;
 Zero_Volts = 0;
 }

 else {
 Volts = Volts_Last;
 Zero_Volts = Zero_Volts + 1;
 if (Zero_Volts > 5) Volts = 0;
 
 }

 Serial.print(F("V:"));    
 Serial.print(Volts);
 Serial.print(F("|"));

 if (Amps < 0.4) Charging = 0;
 if (Amps > 0.4) Charging = 4;
 //Serial.print("Charging = ");  
 //Serial.print(Charging);
 //Serial.print("|");

}
