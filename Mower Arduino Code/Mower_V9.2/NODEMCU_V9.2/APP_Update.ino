

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

        if (Compass_Activate == 1) Blynk.virtualWrite(V20, 1);  
        if (Compass_Activate == 0) Blynk.virtualWrite(V20, 2);
          
        if (Compass_Heading_Hold_Enabled == 1) Blynk.virtualWrite(V21, 1);  
        if (Compass_Heading_Hold_Enabled == 0) Blynk.virtualWrite(V21, 2);
          
        if (GYRO_Enabled == 1) Blynk.virtualWrite(V22, 1);  
        if (GYRO_Enabled == 0) Blynk.virtualWrite(V22, 2);

        if (Sonar_1_Activate == 1) Blynk.virtualWrite(V24, 1);  
        if (Sonar_1_Activate == 0) Blynk.virtualWrite(V24, 2);
        if (Sonar_2_Activate == 1) Blynk.virtualWrite(V25, 1);  
        if (Sonar_2_Activate == 0) Blynk.virtualWrite(V25, 2);
        if (Sonar_3_Activate == 1) Blynk.virtualWrite(V26, 1);  
        if (Sonar_3_Activate == 0) Blynk.virtualWrite(V26, 2); 
        
        if (Bumper_Activate_Frnt == 1) Blynk.virtualWrite(V29, 1);  
        if (Bumper_Activate_Frnt == 0) Blynk.virtualWrite(V29, 2); 

      
        if (Charge_Detected == 4)          Blynk.virtualWrite(V12, 1023);     // Charging LED ON
        if (Charge_Detected == 0)          Blynk.virtualWrite(V12, 0);        // Charging LED OFF
        if (Tracking_Wire == 1)            Blynk.virtualWrite(V9, 1023);      // Tracking LED ON
        if (Tracking_Wire == 0)            Blynk.virtualWrite(V9, 0);         // Tracking LED OFF
        if (Mower_Parked == 1)             Blynk.virtualWrite(V6, 1023);      // Parked LED
        if (Mower_Parked == 0)             Blynk.virtualWrite(V6, 0);         // Parked LED
        if (Mower_Running_Filter == 2)     Blynk.virtualWrite(V7, 1023);      // Mowing LED
        if (Mower_Running_Filter != 2)     Blynk.virtualWrite(V7, 0);         // Mowing LED
        if (Mower_Docked_Filter == 2)      Blynk.virtualWrite(V8, 1023);      // Docked LED
        if (Mower_Docked_Filter != 2)      Blynk.virtualWrite(V8, 0);         // Docked LED
        }



BLYNK_WRITE(V0)        // Quick Start Mowing Function
{
  Clear_APP(); 
  
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (pinValue == 1) StartMower();       
  //Clear_APP();      
  lcd.clear();
  lcd.print(0, 0, "Starting . . ");      // Print to APP LCD
  delay(100);
  Blynk.virtualWrite(V0, HIGH);   // Start Mowing Buton ON
  Blynk.virtualWrite(V11, 0);

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
  Blynk.virtualWrite(V11, 0);

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
  Blynk.virtualWrite(V11, 0);
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
  Blynk.virtualWrite(V11, 0);
  

}


BLYNK_WRITE(V13)                        // Manuel Forward Motion
{
  if (Manuel_Mode = 1) {
  int pinValue = param.asInt(); // assigning incoming value from pin V10 to a variable
  if (pinValue == 1)
  transmit_blynk_code = 7;  //+10 added to the code TX
  Transmit_Blynk_Data_to_Mega();
  Blynk.virtualWrite(V13, LOW);   // Start Mowing Buton ON
  }
  

}

BLYNK_WRITE(V14)                        // Manuel Reverse Motion
{
  if (Manuel_Mode = 1) {
  int pinValue = param.asInt(); // assigning incoming value from pin V10 to a variable
  if (pinValue == 1)
  transmit_blynk_code = 8;   //+10 added to the code TX
  Transmit_Blynk_Data_to_Mega();
  }
}

BLYNK_WRITE(V15)                        // Manuel Left Turn
{
  if (Manuel_Mode = 1) {
  int pinValue = param.asInt(); // assigning incoming value from pin V10 to a variable
  if (pinValue == 1)
  transmit_blynk_code = 9;    //+10 added to the code TX
  Transmit_Blynk_Data_to_Mega();
  }
}

BLYNK_WRITE(V16)                        // Manuel Right Turn
{
  if (Manuel_Mode = 1) {
  int pinValue = param.asInt(); // assigning incoming value from pin V10 to a variable
  if (pinValue == 1)
  transmit_blynk_code = 10;  //+10 added to the code TX
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
        Blynk.virtualWrite(V11, 0);
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
        Blynk.virtualWrite(V11, 0);
        Update_Blynk_App_With_Status();        
        break;
      }

    }
}


// Relay Switch for NODEMCU
BLYNK_WRITE(V17) {
  switch (param.asInt())
  {
    case 1: { // Relay ON
        Serial.println("RELAY ON / CAM ON");
        digitalWrite(D6, HIGH);
        break;
      }
    case 2: { // Relay OFF
        Serial.println("RELAY OFF / CAM OFF");
        digitalWrite(D6, LOW);
        break;
      }
    

    }
}

// Reset Mower MEGA
BLYNK_WRITE(V18)                        // Manuel Right Turn
{
      Serial.print("|MEGA ERROR");  
      Blynk.virtualWrite(V11, 1023);
      digitalWrite(D5, HIGH); 
      digitalWrite(D5, LOW); 
      delay(1000);
      digitalWrite(D5, HIGH); 
      delay(2000);
      Blynk.virtualWrite(V11, 0);
      Total_Error = 0;
      Error_Loop = 0;
      Error_Volt = 0;


  }


// Reset Mower MEGA
BLYNK_WRITE(V19)                        // Manuel Right Turn
{
  Serial.print("|ERROR Re-Start");  
  Clear_APP(); 
  
  StartMower();       
  lcd.clear();
  lcd.print(0, 0, "Starting . . ");      // Print to APP LCD
  delay(100);
  Blynk.virtualWrite(V0, HIGH);   // Start Mowing Buton ON
  Blynk.virtualWrite(V11, 0);
  }


// Compass ON/OFF

BLYNK_WRITE(V20) {
  switch (param.asInt())
  {
    case 1: { // Compass ON
        Serial.println("Compass ON");
        transmit_blynk_code = 30;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Compass_Activate = 1;
        break;
      }
    case 2: { // Compass OFF
        Serial.println("Compass OFF");
        transmit_blynk_code = 31;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Compass_Activate = 0;
        break;
      }  
    }
}


// Heading Hold ON/OFF
BLYNK_WRITE(V21) {
  switch (param.asInt())
  {
    case 1: { // Relay ON
        Serial.println("Heading Hold ON");
        transmit_blynk_code = 32;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Compass_Heading_Hold_Enabled = 1;
        break;
      }
    case 2: { // Relay OFF
        Serial.println("HEading Hold OFF");
        transmit_blynk_code = 33;   //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Compass_Heading_Hold_Enabled = 0;
        break;
      }  
    }
}


// GYRO ON/OFF
BLYNK_WRITE(V22) {
  switch (param.asInt())
  {
    case 1: { // GYRO ON
        Serial.println("GYRO ON");
        transmit_blynk_code = 34;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        GYRO_Enabled = 1;
        break;
      }
    case 2: { // GYRO OFF
        Serial.println("GYRO OFF");
        transmit_blynk_code = 35; //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega(); 
        GYRO_Enabled = 0;
        break;
      }  
    }
}



// Sonar 1 ON/OFF
BLYNK_WRITE(V24) {
  switch (param.asInt())
  {
    case 1: { // Sonar 1 ON
        Serial.println("SONAR 1 ON"); 
        transmit_blynk_code = 37;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Sonar_1_Activate = 1;
        break;
      }
    case 2: { // Sonar 1 OFF
        Serial.println("SONAR 1 OFF");
        transmit_blynk_code = 38;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Sonar_1_Activate = 0;
        break;
      }  
    }
}

// Sonar 2 ON/OFF
BLYNK_WRITE(V25) {
  switch (param.asInt())
  {
    case 1: { // Sonar 2 ON
        Serial.println("SONAR 2 ON");
        transmit_blynk_code = 39;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Sonar_2_Activate = 1;
        break;
      }
    case 2: { // Sonar 2 OFF
        Serial.println("SONAR 2 OFF");
        transmit_blynk_code = 40;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Sonar_2_Activate = 0;
        break;
      }  
    }
}


// Sonar 3 ON/OFF
BLYNK_WRITE(V26) {
  switch (param.asInt())
  {
    case 1: { // Sonar 3 ON
        Serial.println("SONAR 3 ON");
        transmit_blynk_code = 41; //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Sonar_3_Activate = 1;
        break;
      }
    case 2: { // Sonar 3 OFF
        Serial.println("SONAR 3 OFF");
        transmit_blynk_code = 42;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Sonar_3_Activate = 0;
        break;
      }  
    }
}


// Bumper ON/OFF
BLYNK_WRITE(V29) {
  switch (param.asInt())
  {
    case 1: { // Bumper ON
        Serial.println("Bumper ON");
        transmit_blynk_code = 43; //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Bumper_Activate_Frnt = 1;
        break;
      }
    case 2: { // Bumper OFF
        Serial.println("Bumper OFF");
        transmit_blynk_code = 44;  //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Bumper_Activate_Frnt = 0;
        break;
      }  
    }
}


// Set the WIFI APP buttons to the correct status
// Uses a 2 step transmission to set both boards into the right
// Status to receive a reliable long transfer list
BLYNK_WRITE(V23)    {                     
  switch (param.asInt())
  {
    case 1: {    // Update App 
        Blynk.virtualWrite(V23, 2);
        Serial.println(F(""));
        
        // Transmit get ready code
        Serial.println("");
        transmit_blynk_code = 36;       //+10 added to the code TX
        Transmit_Blynk_Data_to_Mega();
        Serial.println("");
        // Tell the MEGA to break the current loop of commands and 
        // be ready to send the button status update
        Serial.println("Waiting for to be MEGA Ready for TX");    
        Serial.println("");
        delay(3000);
    
        // Transmit code to tell the MEGA to now transmit the buttons status
        transmit_blynk_code = 45;
        Transmit_Blynk_Data_to_Mega();
        delay(2500);
        Recieve_App_Button_Status();
        }
    Serial.println(F(""));
    Blynk.virtualWrite(V23, 0);
    }
 }



BLYNK_WRITE(V30)    {   
  int Sonar_Sensitivity = param.asInt();
  Serial.println("");
  Serial.print("Sonar Sensitivity = ");
  Serial.println(Sonar_Sensitivity);
  Serial.println("");
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
  Blynk.virtualWrite(V12, 0);   // Charging LED OFF  
}
