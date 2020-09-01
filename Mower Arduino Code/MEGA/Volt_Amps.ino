/* Main Battery Voltage Test
************************************************************************************/

/* ADCMan function (needed for Perimeter Wire readings) doesnt allow direct reading of Analog pins which makes this simple operation a little complicated*/
void TestforBatteryVoltage()   {
  Check_Serial_Communication_Volts();  
  // ask the Nano for Voltage and Amps reading
   
  if ((Nano_Data_Volt_Received == 1) && (VoltsTX < 15) && (VoltsTX > 7)) {
    BatteryVoltage_Last = VoltsTX;
    }


  else {
    VoltsTX = BatteryVoltage_Last;
    Serial.print(F("L"));
    //Serial.print(VoltsTX);
    Serial.print("|");
    }

           
    lcd.setCursor(10, 0);
    lcd.print("V:");
    lcd.setCursor(12, 0);    
    lcd.print(VoltsTX);  

}

void Action_For_Battery_Voltage() {

//  Logic for how the battery readings should be handled

    // Checks if the battery is not connected by a voltage under 6V
    if (VoltsTX < 10) {
      Battery_NoBattery_Found = (Battery_NoBattery_Found + 1);
      //Serial.print(F("####### No Battery Found Reading ###### : "));
      //Serial.println(Battery_NoBattery_Found);
      }
    
    if (VoltsTX < BatteryMin) {
      Battery_To_Charge_Station_Count = (Battery_To_Charge_Station_Count + 1);
      //Serial.print("Batt_Out:");
      //Serial.print(Battery_To_Charge_Station_Count);
      //Serial.print("|");
      }

      if (VoltsTX >= BatteryMin) {
      //Serial.print(F("Battery >"));
      //Serial.println(BatteryMin);
      Battery_To_Charge_Station_Count = 0;
      Battery_NoBattery_Found = 0;
      }
  

// Handles how the voltage is printed to the LCD display and what the mower does.
    if ( (BatteryVoltage > 10 ) && (BatteryVoltage <= BatteryMin) && (Battery_To_Charge_Station_Count > 10) ){
       //MowerMotionStatus = 1;
       lcd.setCursor(0, 1);
       lcd.print("Battery < :  ");
       lcd.print(BatteryMin);
       Serial.print(F("Battery below : "));
       Serial.println(BatteryMin);
       }
  


    // Checks if a series of low voltage signals have been detected i.e. the mower wont be sent to the charger due to just 1 bad signal
    if (Battery_To_Charge_Station_Count > 20)  {
      Motion_StopMotors();
      StopSpinBlades();
      MowerMotionStatus = 1;
      Error = 7;
      Serial.print(F("Batt Sensor - Battery Empty < "));
      Serial.println(BatteryMin);                               //sets Mower Motion to 1 which is all stop
      lcd.setCursor(0, 1);
      lcd.print("Mower -> Charger");
      delay(5000);
      }

    if ((BatteryVoltage <= 10) && (Battery_NoBattery_Found >= 5)){
       lcd.setCursor(10, 0);
       lcd.print("V:");
       lcd.setCursor(12, 0);    
       lcd.print("OFF ");     
       }
  
}






void Check_Serial_Communication_Volts (){
        Nano_Data_Volt_Received = 0;
        VoltsTX = Serial1.parseFloat();
        if(Serial1.read()== '\j'){
            if ((VoltsTX < 15) && (VoltsTX > 10)) {
              Serial.print(F("V:"));
              Serial.print(VoltsTX);
              Nano_Data_Volt_Received = 1;
              Serial.print(F("|"));
            }
            if ((VoltsTX > 15) || (VoltsTX < 10) ) {
              Serial.print(F("V:"));
              Serial.print("_.__"); 
              Nano_Data_Volt_Received = 1;
              }
        }
        
        if ( Nano_Data_Volt_Received == 0 ) {
            Serial.print(F("V:"));
            Serial.print("_.__");
            //Serial.print(F(" | "));
            }
      }


void Check_Serial_Communication_Amps (){
        Nano_Data_Amp_Received = 0; 
        AmpsTX = Serial1.parseInt();
        if(Serial1.read()== '\q'){
            Serial.print(F("Charge:"));
            Serial.print(AmpsTX);
            Serial.print(F("|"));  
            Nano_Data_Amp_Received = 1;
            }
        if ( Nano_Data_Amp_Received == 0 ) {
           Serial.print(F("Charge:"));
           Serial.print(F("?"));
           Serial.print(F("|"));
           }
       }



// checks to see if the mower is on the charging station
void Check_if_Docked () {

  AmpsTX = Serial1.parseInt();
  if(Serial1.read()== '\q') {
      if ((AmpsTX == 1) || (AmpsTX == 0)){                            // If the value recieved is equal to 1 or 0 as expected then print the value to the serial monitor
        Serial.print("| Charging:");
        Serial.println(AmpsTX);
        }
      if ((AmpsTX != 1) && (AmpsTX !=0)) {
        Serial.print("| Charging:");
        Serial.println(AmpsTX);       
      }
      
    }
  else {
    Serial.print("| Charging:");
    Serial.println("?");  
    }
  
  if ((AmpsTX == 1)){                              // if Amps are between this there is a charge detected.  Amps above 4 are discounted as a miscommunication
      Amp_Hits = (Amp_Hits + 1) ;                                       // Filters out the bad Amp sensor readings so no single bad sensor reading will interupt the tracking
      
      if (Amp_Hits == Amp_Filter_Hits) {
        Motion_StopMotors();    
        Serial.println(F("Charging Current detected"));
        Serial.println(F("Mower Docked"));
        lcd.print("Docked in");
        lcd.setCursor(0, 1);
        lcd.print("Charging Station");                                // Prints info to LCD display
        delay(2000);
        Power_Down_Mower();                                           // Shits down the Mower ready for charging and mowing again.
        lcd.clear();
        }
 }
 else {
  Amp_Hits = 0;
 
 }

 
}


void Check_if_Charging() {

      
    if (AmpsTX == 1) {
      lcd.setCursor(0,0);            // Spaces to the right & down
      lcd.print("Charging:");
      }
    if (AmpsTX == 0) {
      lcd.setCursor(0,0);            // Spaces to the right & down
      lcd.print("         ");
      }

  }
