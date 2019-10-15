

void Update_Blynk_App_With_Status() {

         if (Mower_Docked_Filter == 2)   {
           //App Buttons
           Blynk.virtualWrite(V10,LOW);       // Exit Dock Button 
           Blynk.virtualWrite(V0, LOW);       // Quick Start Button
           Blynk.virtualWrite(V2, LOW);       // Pause/Stop Button
           Blynk.virtualWrite(V1, LOW);       // Go To Dock Button
           }
        
        if (Mower_Running_Filter == 2)   {
           //App Buttons
           Blynk.virtualWrite(V10,LOW);       // Exit Dock Button 
           Blynk.virtualWrite(V0, LOW);       // Quick Start Button
           Blynk.virtualWrite(V2, LOW);       // Pause/Stop Button
           Blynk.virtualWrite(V1, LOW);       // Go To Dock Button
           }

        if (Manuel_Mode == 1)   {
           //App Buttons
           Blynk.virtualWrite(V10,LOW);       // Exit Dock Button 
           Blynk.virtualWrite(V0, LOW);       // Quick Start Button
           Blynk.virtualWrite(V2, LOW);       // Pause/Stop Button
           Blynk.virtualWrite(V1, LOW);       // Go To Dock Button
           
           Blynk.virtualWrite(V6, 0);
           Blynk.virtualWrite(V7, 0);
           Blynk.virtualWrite(V9, 0);     
           Blynk.virtualWrite(V8, 0);
           }

        if (Mower_Parked == 1)   {
           //App Buttons
           Blynk.virtualWrite(V10,LOW);       // Exit Dock Button 
           Blynk.virtualWrite(V0, LOW);       // Quick Start Button
           Blynk.virtualWrite(V2, LOW);       // Pause/Stop Button
           Blynk.virtualWrite(V1, LOW);       // Go To Dock Button
           }
      
      if (Charge_Detected == 4)   Blynk.virtualWrite(V12, 1023);        // Charging LED ON
      if (Charge_Detected == 0)   Blynk.virtualWrite(V12, 0);           // Charging LED OFF
      if (Tracking_Wire == 1)     Blynk.virtualWrite(V9, 1023);         // Tracking LED ON
      if (Tracking_Wire == 0)     Blynk.virtualWrite(V9, 0);            // Tracking LED OFF
      if (Mower_Parked == 1)      Blynk.virtualWrite(V6, 1023);         // Parked LED
      if (Mower_Parked == 0)      Blynk.virtualWrite(V6, 0);            // Parked LED
      if (Mower_Running_Filter == 2)     Blynk.virtualWrite(V7, 1023);            // Mowing LED
      if (Mower_Running_Filter != 2)     Blynk.virtualWrite(V7, 0);            // Mowing LED
      if (Mower_Docked_Filter == 2)      Blynk.virtualWrite(V8, 1023);         // Docked LED
      if (Mower_Docked_Filter != 2)      Blynk.virtualWrite(V8, 0);         // Docked LED
    }



BLYNK_WRITE(V0)       // Quick Start Mowing Function
{
  Clear_APP(); 
  
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (pinValue == 1) StartMower();       
  //Clear_APP();      
  lcd.clear();
  lcd.print(0, 0, "Starting . . ");      // Print to APP LCD
  delay(100);
  Blynk.virtualWrite(V0, HIGH);   // Start Mowing Buton ON

}


BLYNK_WRITE(V1)      // Go to Docking Station
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (pinValue == 1) Going_Home();
  //Clear_APP();
  lcd.clear();
  lcd.print(0, 0, "Docking . . ");        // Print to APP LCD
  delay(100);
  Blynk.virtualWrite(V1, HIGH);           // Docking Button ON

}



BLYNK_WRITE(V2)      // Pause Mower Function
{
  int pinValue = param.asInt(); // assigning incoming value from pin V2 to a variable
  if (pinValue == 1)  Pause_Mower();
  //Clear_APP();
  lcd.clear();
  lcd.print(0, 0, "Stopping . . ");       // Print to APP LCD
  delay(100);
  Blynk.virtualWrite(V2, HIGH);           // Pause Button ON
   }





BLYNK_WRITE(V10)      // Exit Dock Function
{
  int pinValue = param.asInt(); // assigning incoming value from pin V10 to a variable
  if (pinValue == 1) Exit_Dock();
  //Clear_APP();
  lcd.clear();
  lcd.print(0, 0, "Exiting . . ");      // Print to APP LCD
  delay(100);
  Blynk.virtualWrite(V10, HIGH);        // Dock Button ON
  

}


BLYNK_WRITE(V13)                        // Manuel Forward Motion
{
  if (Manuel_Mode = 1) {
  int pinValue = param.asInt(); // assigning incoming value from pin V10 to a variable
  if (pinValue == 1)
  transmit_blynk_code = 7;
  Transmit_Blynk_Data_to_Mega();
  Blynk.virtualWrite(V13, LOW);   // Start Mowing Buton ON
  }
  

}

BLYNK_WRITE(V14)                        // Manuel Reverse Motion
{
  if (Manuel_Mode = 1) {
  int pinValue = param.asInt(); // assigning incoming value from pin V10 to a variable
  if (pinValue == 1)
  transmit_blynk_code = 8;
  Transmit_Blynk_Data_to_Mega();
  }
}

BLYNK_WRITE(V15)                        // Manuel Left Turn
{
  if (Manuel_Mode = 1) {
  int pinValue = param.asInt(); // assigning incoming value from pin V10 to a variable
  if (pinValue == 1)
  transmit_blynk_code = 9;
  Transmit_Blynk_Data_to_Mega();
  }
}

BLYNK_WRITE(V16)                        // Manuel Right Turn
{
  if (Manuel_Mode = 1) {
  int pinValue = param.asInt(); // assigning incoming value from pin V10 to a variable
  if (pinValue == 1)
  transmit_blynk_code = 10;
  Transmit_Blynk_Data_to_Mega();


  }
}

BLYNK_WRITE(V4) {
  switch (param.asInt())
  {
    case 1: { // Item 1
        Serial.println("Automatic Mode");
        Automatic_Mode = 1;
        Manuel_Mode = 0;
        Set_To_Automatic_Mode_Random();
        Update_Blynk_App_With_Status();
        break;
      }
    case 2: { // Item 2
        Serial.println("Automatic Spiral");
        Automatic_Mode = 2;
        Manuel_Mode = 0;
        Set_To_Automatic_Mode_Spiral();
        Update_Blynk_App_With_Status();
        break;
      }
    
    case 3: { // Item 3
        Serial.println("Automatic Parallel");
        Manuel_Mode = 0;
        Automatic_Mode = 1;
        Set_To_Automatic_Mode_Parallel();
        Mower_Parked = 0;
        Mower_Docked = 0;
        Mower_Running = 0;
        Update_Blynk_App_With_Status();
        break;
      }

    
    case 4: { // Item 4
        Serial.println("Manuel Mode");
        Manuel_Mode = 1;
        Automatic_Mode = 0;
        Set_To_Manuel_Mode();
        Mower_Parked = 0;
        Mower_Docked = 0;
        Mower_Running = 0;
        Update_Blynk_App_With_Status();
        break;
      }

    }
}

void Clear_APP() {
  Blynk.virtualWrite(V0, LOW);   // Start Mowing Buton OFF
  Blynk.virtualWrite(V1, LOW);  // Go-Home Button OFF
  Blynk.virtualWrite(V2, LOW);  // Stop Button OFF
  Blynk.virtualWrite(V3, 0);    // Reset Voltage
  Blynk.virtualWrite(V5, 0);    // Loops
  Blynk.virtualWrite(V7, 0);    // Mow LED
  Blynk.virtualWrite(V8, 0);    // Dock LED Off
  Blynk.virtualWrite(V9, 0);    // TrackingLED OFF
  Blynk.virtualWrite(V10, LOW); // Dock Button OFF
  Blynk.virtualWrite(V11, 0);   // Compass LED OFF  
  Blynk.virtualWrite(V12, 0);   // Charging LED OFF  
}
