// Blynk TX and RX functions to communicate with the MEGA and NODEMCU
// Each transmission has a label n or p or q or 

// USE V5 Blynk  12th Feb 2019

void Get_Blynk_Commands() {
  Serial.println(F("----------------------------------------------------"));
  Receive_Data_From_NODEMCU(); 
  delay(5);
  Transmit_All_To_NODEMCU();
  Serial.println(F("----------------------------------------------------"));
  
  }

void Receive_Data_From_NODEMCU() {
  Serial.println("Looking for NODEMCU data");
  while(Serial2.available()>0){
      val_WIFI = Serial2.parseInt();
      if(Serial2.read()== '\p'){
        Serial.print("RX Value from NodeMCU : ");
        Serial.println(val_WIFI);
        //Convert the string value to a useful number to use..
        Serial.println(F(""));
        Serial.println(F("- - - - - - - - - - - - - - - - - - - - - - - - - "));
        Serial.println(F(""));
        Serial.print("Recieved WIFI Command - Order Value : ");
        Serial.println(val_WIFI);
        Serial.println(F(""));
        Serial.println(F("- - - - - - - - - - - - - - - - - - - - - - - - - "));
        Serial.println(F(""));
        delay(1000);
        Execute_Blynk_Command_To_Mower();
        }
  }
}

void Transmit_All_To_NODEMCU() {
  Serial2.print(VoltsTX);
  Serial2.println("\z");
  Serial2.print(Mower_Docked);
  Serial2.println("\a");
  Serial2.print(Error);
  Serial2.println("\b");
  Serial2.print(MowerMotionStatus);
  Serial2.println("\c");
  Serial2.print(Mower_Stopped);
  Serial2.println("\d");
  delay(30);
  Serial.print("Information sent to NODEMCU: ");
  Serial.print("Volts : ");
  Serial.print(VoltsTX);
  Serial.print(" / ");
  Serial.print("Docked : ");
  Serial.print(Mower_Docked);
  Serial.print(" / ");
  Serial.print("Error : ");
  Serial.print(Error);
  Serial.print(" / ");
  Serial.print("Motion Status : ");
  Serial.print(MowerMotionStatus);
  Serial.print(" / ");
  Serial.print("Mower Stopped : ");
  Serial.print(Mower_Stopped);
  Serial.println(F(" / "));
  
  delay(20);   
}


void Execute_Blynk_Command_To_Mower() {

// Updates the Serial Monitor with the latest Blynk Commands and can be used to start
// functions on the mower when the command is recieved.
delay(30);


// Exit Dock to Zone 1
 if (val_WIFI == 14) {
   if (Mower_Docked == 1)   {   
   Serial.print(" WIFI Command : "); 
   Serial.print(val_WIFI);
   Serial.println(F("  WIFI --> Exiting Dock "));
   lcd.clear();
   lcd.print("WIFI Start");
   lcd.setCursor(0,1);
   lcd.print("Exit Dock Z1");
   Serial.println(F("Exit to Zone 1 - Free Mow"));
   delay(1000);
   lcd.clear();
   Mower_Docked = 0;
   Get_Blynk_Commands();
   delay(5);
   Get_Blynk_Commands();
   Menu_Mode_Selection = 0;
   delay(3000);
   lcd.clear();
   Manuel_Start_Mower_Exit_Zone1();
}
   }

 // Quick Start Button in Blynk App
 if (val_WIFI == 13) {
   Serial.print(" WIFI Command : "); 
   Serial.print(val_WIFI);
   Serial.println(F("   *** Mowing ***")); 
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("WIFI Start");
   Mower_Docked = 0;
   Mower_Stopped = 0;
   MowerMotionStatus = 1;
   Get_Blynk_Commands(); 
   delay(5);
   Get_Blynk_Commands(); 
   Quick_Start();
   Prepare_To_Mow();
   }

// Go To Dock Button in Blynk App
 if (val_WIFI == 12) {
   Serial.print(" BLYNK Command : "); 
   Serial.print(val_WIFI);
   Serial.println(F("      Going Home -->"));
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("WIFI Go To Dock");
   StopSpinBlades();
   Error = 7;
   Mower_Docked = 0;
   Mower_Stopped = 0;
   MowerMotionStatus = 0;
   Get_Blynk_Commands();
   delay(5);
   Get_Blynk_Commands();
   Serial.println(F("Tracking to Charging Station"));
   delay(5);
   Get_Blynk_Commands();
   delay(1000);
   if (Compass_Mode == 1) Turn_Mower_To_Home_Direction();  
   Get_Blynk_Commands();
   FindWireTrack();
   Get_Blynk_Commands();
   Track_Perimeter_Wire_To_Dock();
   Get_Blynk_Commands();
   }

// STOP Button in Blynk App
 if (val_WIFI == 11)  {    
   Serial.print(" BLYNK Command : "); 
   Serial.print(val_WIFI);
   Serial.println(F("   !! Mower Stopped !!")); 
   Motion_StopMotors();
   delay(100);
   StopSpinBlades();
   delay(2000);
   MowerMotionStatus = 1;
   Error = 0;
   Mower_Stopped = 1;
   Get_Blynk_Commands();
   delay(5);
   Get_Blynk_Commands();
   val_WIFI = 0;   // restes val2 to zero so the command is only executed once

}
}
