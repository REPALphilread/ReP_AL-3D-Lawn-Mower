// SENSORS SETTINGS MENU

#if defined(LCD_KEYPAD)


// Test to displyed on the LCD screen when using the membrane key menus
void Print_LCD_Menu_Sensors(byte LCD_Menu_Sensors) {
  if (LCD_Menu_Sensors == 1)  lcd.print(F("SONAR ON/OFF"));
  if (LCD_Menu_Sensors == 2)  lcd.print(F("SONAR Distance"));
  if (LCD_Menu_Sensors == 3)  lcd.print(F("SONAR Sensitivity"));   
  if (LCD_Menu_Sensors == 4)  lcd.print(F("Battery Min/Max"));      // add max
  if (LCD_Menu_Sensors == 5)  lcd.print(F("Batt Sensitivity"));
  if (LCD_Menu_Sensors == 6)  lcd.print(F("WIRE ON/OFF"));   
  if (LCD_Menu_Sensors == 7)  lcd.print(F("RAIN ON/OFF"));
  if (LCD_Menu_Sensors == 8)  lcd.print(F("Rain Sensitivity"));
  if (LCD_Menu_Sensors == 9)  lcd.print(F("WIFI ON/OFF"));
  if (LCD_Menu_Sensors == 10)  lcd.print(F("Bumper ON/OFF"));
  if (LCD_Menu_Sensors == 11) lcd.print(F("ANGLE ON/OFF"));
  if (LCD_Menu_Sensors == 12)  lcd.print(F("TIP ON/OFF"));
  if (LCD_Menu_Sensors == 13) lcd.print(F(""));
  
  Max_Options_Sensors = 13;
  }


void Print_Membrane_Switch_Input_Sensors() {
     Read_Membrane_Keys();
     Menu_Complete = 1;
     Menu_Mode_Selection = 0;
     Menu_View = 0;

      Serial.println();
      Serial.println(F("Sensors Menu Activated"));
      Menu_Complete_Sensors = false;                                // Menu complete will return to the normal loop
      lcd.clear();
      delay(5);
      
      while (Menu_Complete_Sensors == false) {                      // holds the program in a loop until a selection has been made in the membrane button menu
        if (Menu_View == 0) {
          lcd.setCursor(1,0);
          Print_LCD_Menu_Sensors(1);
          lcd.setCursor(1,1);
          Print_LCD_Menu_Sensors(2);
          }
        // Gets the values again from the keys
        Read_Membrane_Keys();
        delay(100);
             
        if(!Start_Key_X){
          Menu_Complete_Sensors = true;
          Serial.println(F("Start key is pressed"));
          Activate_Menu_Option_Sensors();
          lcd.clear();
          
          }
        if(!Plus_Key_X) {
          Serial.println(F("+ key is pressed"));
          Menu_View = Menu_View - 1;
          Run_Menu_Order_Sensors();
          }
        if(!Minus_Key_X) {
          Menu_View = Menu_View + 1;
          Run_Menu_Order_Sensors();
        }
        if(!Stop_Key_X){
          Serial.println(F("Stop key is pressed"));
          Menu_Complete_Sensors = true;
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Exit Sensors");
          delay(1000);
          lcd.clear();          
          Menu_Mode_Selection = 0;
          }
      }
    }

    


// Code to scroll the menu and print the menu options in the LCD
 void Run_Menu_Order_Sensors() {
     if (Menu_View > Max_Options_Sensors) Menu_View = Menu_View -1;
     if (Menu_View < 0) Menu_View = Menu_View + 1;      
     Serial.print(F("- key is pressed "));
     lcd.clear();
     lcd.setCursor(1,0);
     Print_LCD_Menu_Sensors(Menu_View);
     lcd.setCursor(1,1);
     Print_LCD_Menu_Sensors(Menu_View + 1);
     lcd.setCursor(0,0);
     lcd.print(">");
     Menu_Mode_Selection = Menu_View;
     Serial.print(F("Menu View : "));
     Serial.print(Menu_View);
     Serial.print(F("| Menu Selection"));
     Serial.println(Menu_Mode_Selection);
     delay(100);
     }

     
// Defines the actions when that option is selected with the keypad.
void Activate_Menu_Option_Sensors() {

     if (Menu_Mode_Selection == 1) {
       // SONAR ON/OFF
     
       int Set = 1;
       Menu_Mode_Selection = 0;
       lcd.clear();
       delay(100);
       lcd.setCursor(0,0);
       lcd.print(F("SONAR Active Y/N"));
       lcd.setCursor(0,1);
       lcd.print(F(">S2:"));
       if (Sonar_2_Activate == 1) lcd.print("Y");
       if (Sonar_2_Activate == 0) lcd.print("N");
       lcd.print(F(" S1:"));
       if (Sonar_1_Activate == 1) lcd.print("Y");
       if (Sonar_1_Activate == 0) lcd.print("N");
       lcd.print(F(" S3:"));
       if (Sonar_3_Activate == 1) lcd.print("Y");
       if (Sonar_3_Activate == 0) lcd.print("N");
       delay(2000);

       Menu_Complete_Sensors = false;
       while (Menu_Complete_Sensors == false) {
             Read_Membrane_Keys();
             delay(100);
             //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
             
             if (Set == 3) {
               lcd.clear(); 
               lcd.setCursor(0,0);
               lcd.print(F("SONAR"));
               lcd.setCursor(0,1);
               lcd.print(F("Settings Saved"));
               delay(2000);            
               EEPROM.write(37, 1);
               EEPROM.write(38, Sonar_1_Activate);
               EEPROM.write(39, 1);
               EEPROM.write(40, Sonar_2_Activate);
               EEPROM.write(41, 1);
               EEPROM.write(42, Sonar_3_Activate);
               Menu_Mode_Selection = 0;
               Menu_Complete_Sensors = true;
               }

             
             if (Set == 2) { 
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print(F("Y = Yes  N = No"));
                lcd.setCursor(0,1);
                lcd.print(F(" S2:"));
                if (Sonar_2_Activate == 1) lcd.print("Y");
                if (Sonar_2_Activate == 0) lcd.print("N");
                lcd.print(F(" S1:"));
                if (Sonar_1_Activate == 1) lcd.print("Y");
                if (Sonar_1_Activate == 0) lcd.print("N");
                lcd.print(F(">S3:"));
                if (Sonar_3_Activate == 1) lcd.print("Y");
                if (Sonar_3_Activate == 0) lcd.print("N");
                Set = Set + 1;         
               }
            
             if (Set == 1) { 
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print(F("Y = Yes  N = No"));
                lcd.setCursor(0,1);
                lcd.print(F(" S2:"));
                if (Sonar_2_Activate == 1) lcd.print("Y");
                if (Sonar_2_Activate == 0) lcd.print("N");
                lcd.print(F(">S1:"));
                if (Sonar_1_Activate == 1) lcd.print("Y");
                if (Sonar_1_Activate == 0) lcd.print("N");
                lcd.print(F(" S3:"));
                if (Sonar_3_Activate == 1) lcd.print("Y");
                if (Sonar_3_Activate == 0) lcd.print("N");
                Set = Set + 1;         
               }
             }

             if (!Plus_Key_X) {
               if (Set == 1) {
                 Sonar_2_Activate = 1;
                 if (Sonar_2_Activate > 1) Sonar_2_Activate == 1;
                 lcd.clear();
                 lcd.setCursor(0,0);
                 lcd.print(F("Y = Yes  N = No"));
                 lcd.setCursor(0,1);
                 lcd.print(F(">S2:"));
                 if (Sonar_2_Activate == 1) lcd.print("Y");
                 if (Sonar_2_Activate == 0) lcd.print("N");
                 lcd.print(F(" S1:"));
                 if (Sonar_1_Activate == 1) lcd.print("Y");
                 if (Sonar_1_Activate == 0) lcd.print("N");
                 lcd.print(F(" S3:"));
                 if (Sonar_3_Activate == 1) lcd.print("Y");
                 if (Sonar_3_Activate == 0) lcd.print("N");
                 }
               if (Set == 2) {
                 Sonar_1_Activate = 1;
                 if (Sonar_1_Activate > 1) Sonar_1_Activate == 1;
                 lcd.clear();
                 lcd.setCursor(0,0);
                 lcd.print(F("Y = Yes  N = No"));
                 lcd.setCursor(0,1);
                 lcd.print(F(" S2:"));
                 if (Sonar_2_Activate == 1) lcd.print("Y");
                 if (Sonar_2_Activate == 0) lcd.print("N");
                 lcd.print(F(">S1:"));
                 if (Sonar_1_Activate == 1) lcd.print("Y");
                 if (Sonar_1_Activate == 0) lcd.print("N");
                 lcd.print(F(" S3:"));
                 if (Sonar_3_Activate == 1) lcd.print("Y");
                 if (Sonar_3_Activate == 0) lcd.print("N");
                 }
               if (Set == 3) {
                 Sonar_3_Activate = 1;
                 if (Sonar_3_Activate > 1) Sonar_3_Activate == 1;
                 lcd.clear();
                 lcd.setCursor(0,0);
                 lcd.print(F("Y = Yes  N = No"));
                 lcd.setCursor(0,1);
                 lcd.print(F(" S2:"));
                 if (Sonar_2_Activate == 1) lcd.print("Y");
                 if (Sonar_2_Activate == 0) lcd.print("N");
                 lcd.print(F(" S1:"));
                 if (Sonar_1_Activate == 1) lcd.print("Y");
                 if (Sonar_1_Activate == 0) lcd.print("N");
                 lcd.print(F(">S3:"));
                 if (Sonar_3_Activate == 1) lcd.print("Y");
                 if (Sonar_3_Activate == 0) lcd.print("N");
                 }
             }
             
             if (!Minus_Key_X) {
               if (Set == 1) {
                 Sonar_2_Activate = 0;
                 if (Sonar_2_Activate < 0) Sonar_2_Activate == 0;
                 lcd.clear();
                 lcd.setCursor(0,0);
                 lcd.print(F("Y = Yes  N = No"));
                 lcd.setCursor(0,1);
                 lcd.print(F(">S2:"));
                 if (Sonar_2_Activate == 1) lcd.print("Y");
                 if (Sonar_2_Activate == 0) lcd.print("N");
                 lcd.print(F(" S1:"));
                 if (Sonar_1_Activate == 1) lcd.print("Y");
                 if (Sonar_1_Activate == 0) lcd.print("N");
                 lcd.print(F(" S3:"));
                 if (Sonar_3_Activate == 1) lcd.print("Y");
                 if (Sonar_3_Activate == 0) lcd.print("N");
                 }
               if (Set == 2) {
                 Sonar_1_Activate = 0;
                 if (Sonar_1_Activate < 0) Sonar_1_Activate == 0;
                 lcd.clear();
                 lcd.setCursor(0,0);
                 lcd.print(F("Y = Yes  N = No"));
                 lcd.setCursor(0,1);
                 lcd.print(F(" S2:"));
                 if (Sonar_2_Activate == 1) lcd.print("Y");
                 if (Sonar_2_Activate == 0) lcd.print("N");
                 lcd.print(F(">S1:"));
                 if (Sonar_1_Activate == 1) lcd.print("Y");
                 if (Sonar_1_Activate == 0) lcd.print("N");
                 lcd.print(F(" S3:"));
                 if (Sonar_3_Activate == 1) lcd.print("Y");
                 if (Sonar_3_Activate == 0) lcd.print("N");
                 }
               if (Set == 3) {
                 Sonar_3_Activate = 0;
                 if (Sonar_3_Activate < 0) Sonar_3_Activate == 0;
                 lcd.clear();
                 lcd.setCursor(0,0);
                 lcd.print(F("Y = Yes  N = No"));
                 lcd.setCursor(0,1);
                 lcd.print(F(" S2:"));
                 if (Sonar_2_Activate == 1) lcd.print("Y");
                 if (Sonar_2_Activate == 0) lcd.print("N");
                 lcd.print(F(" S1:"));
                 if (Sonar_1_Activate == 1) lcd.print("Y");
                 if (Sonar_1_Activate == 0) lcd.print("N");
                 lcd.print(F(">S3:"));
                 if (Sonar_3_Activate == 1) lcd.print("Y");
                 if (Sonar_3_Activate == 0) lcd.print("N");
               }         
           }
     }
     }

     if (Menu_Mode_Selection == 2) {
       // SONAR Distance
       Menu_Mode_Selection = 0;
       lcd.clear();
       delay(500);
       lcd.setCursor(0,0);
       lcd.print(F("Sonar Distance:"));
       lcd.setCursor(0,1);
       lcd.print(F("cm = "));
       lcd.print(maxdistancesonar);
       Serial.print(F("Sonar Distnace = :"));
       Serial.println(maxdistancesonar);
       Menu_Complete_Sensors = false;
       while (Menu_Complete_Sensors == false) {
             Read_Membrane_Keys();
             delay(100);
             //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
             Serial.println(F("Settings Saved"));
             Menu_Complete_Sensors = true;
             lcd.clear();
             lcd.setCursor(0,0);
             lcd.print(F("cm = "));
             lcd.print(maxdistancesonar);
             lcd.setCursor(0,1);
             lcd.print(F("SAVED"));
             delay(2000);
             lcd.clear();          
             EEPROM.write(65, 1);
             EEPROM.write(66, maxdistancesonar);   
             Menu_Mode_Selection = 0;
             }
             if (!Plus_Key_X) {
               maxdistancesonar = maxdistancesonar + 1;
               if (maxdistancesonar> 100) maxdistancesonar = 100;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print(F("Sonar Distance:"));
               lcd.setCursor(0,1);
               lcd.print(F("cm = "));
               lcd.print(maxdistancesonar);
               Serial.print(F("Sonar Distnace = :"));
               Serial.println(maxdistancesonar);
               }
             if (!Minus_Key_X) {
               maxdistancesonar = maxdistancesonar - 1;
               if (maxdistancesonar < 10) maxdistancesonar = 10;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print(F("Sonar Distance:"));
               lcd.setCursor(0,1);
               lcd.print(F("cm = "));
               lcd.print(maxdistancesonar);
               Serial.print(F("Sonar Distnace = :"));
               Serial.println(maxdistancesonar);
               }
             
             }
     }



     if (Menu_Mode_Selection == 3) {
       // SONAR Sensitivity
       Menu_Mode_Selection = 0;
       lcd.clear();
       delay(500);
       lcd.setCursor(0,0);
       lcd.print(F("Sonar Sensitivity:"));
       lcd.setCursor(0,1);
       lcd.print(F("Hits = "));
       lcd.print(Max_Sonar_Hit);
       Serial.print(F("Sonar Sensitivity = :"));
       Serial.println(Max_Sonar_Hit);
       Menu_Complete_Sensors = false;
       while (Menu_Complete_Sensors == false) {
             Read_Membrane_Keys();
             delay(100);
             //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
             Serial.println(F("Settings Saved"));
             Menu_Complete_Sensors = true;
             lcd.clear();
             lcd.setCursor(0,0);
             lcd.print("Hits : ");
             lcd.print(Max_Sonar_Hit);
             lcd.setCursor(0,1);
             lcd.print(F("SAVED"));
             delay(2000);
             lcd.clear();          
             EEPROM.write(63, 1);
             EEPROM.write(64, Max_Sonar_Hit);   
             Menu_Mode_Selection = 0;
             }
             if (!Plus_Key_X) {
               Max_Sonar_Hit = Max_Sonar_Hit + 1;
               if (Max_Sonar_Hit> 10) Max_Sonar_Hit = 10;
               lcd.clear();
               lcd.setCursor(0,0); 
               lcd.print(F("Sonar Sensitivity:"));
               lcd.setCursor(0,1);
               lcd.print(F("Hits = "));
               lcd.print(Max_Sonar_Hit);
               Serial.print(F("Sonar sensitivity = :"));
               Serial.println(Max_Sonar_Hit);
               }
             if (!Minus_Key_X) {
               Max_Sonar_Hit = Max_Sonar_Hit - 1;
               if (Max_Sonar_Hit < 1) Max_Sonar_Hit = 1;
               lcd.clear();
               lcd.setCursor(0,0); 
               lcd.print(F("Sonar Sensitivity:"));
               lcd.setCursor(0,1);
               lcd.print(F("Hits = "));
               lcd.print(Max_Sonar_Hit);
               Serial.print(F("Sonar sensitivity = :"));
               Serial.println(Max_Sonar_Hit);
               }
             
             }
     }


     if (Menu_Mode_Selection == 4) {
       // Battery Min Setting
       Menu_Mode_Selection = 0;
       lcd.clear();
       delay(500);
       lcd.setCursor(0,0);
       lcd.print("Min Battery Volt");
       lcd.setCursor(0,1);
       lcd.print("V = ");
       lcd.print(Battery_Min);
       Serial.print(F("Battery Minimum Volt = :"));
       Serial.println(Battery_Min);
       Menu_Complete_Sensors = false;
       while (Menu_Complete_Sensors == false) {
             Read_Membrane_Keys();
             delay(100);
             //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
             Serial.println(F("Settings Saved"));
             Menu_Complete_Sensors = true;
             lcd.clear();
             lcd.setCursor(0,0);
             lcd.print("V = ");
             lcd.print(Battery_Min);
             lcd.setCursor(0,1);
             lcd.print("SAVED");
             delay(2000);
             lcd.clear();          
             EEPROM.write(25, 1);
             EEPROM.write(26, (Battery_Min * 10));   
             Menu_Mode_Selection = 0;
             }
             if (!Plus_Key_X) {
               Battery_Min = Battery_Min + 0.1;
               if (Battery_Min > 12.6) Battery_Min = 12.6;
               lcd.setCursor(0,1);
               lcd.print("      ");    // Fully clear the number to stop reminants of a previous number from being left behind
               lcd.setCursor(0,1);
               lcd.print("V = ");
               lcd.print(Battery_Min);
               Serial.print(F("Minimum Battery Voltage = :"));
               Serial.println(Battery_Min);
               }
             if (!Minus_Key_X) {
               Battery_Min = Battery_Min - 0.1;
               if (Battery_Min < 10.5) Battery_Min = 10.5;
               lcd.setCursor(0,1);
               lcd.print("      ");   // Fully clear the number to stop reminants of a previous number from being left behind
               lcd.setCursor(0,1);
               lcd.print("V = ");
               lcd.print(Battery_Min);
               Serial.print(F("Minimum Battery Voltage = :"));
               Serial.println(Battery_Min);
               }
             
             }
     }


     if (Menu_Mode_Selection == 5) {
       // Battery to Charge Sensitivity
       Menu_Mode_Selection = 0;
       delay(500);
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print(F("Batt Sensitivity:"));
       lcd.setCursor(0,1);
       lcd.print(F("Hits = "));
       lcd.print(Low_Battery_Instances_Chg);
       Serial.print(F("Batt Sensitivity = :"));
       Serial.println(Low_Battery_Instances_Chg);
       Menu_Complete_Sensors = false;
       while (Menu_Complete_Sensors == false) {
             Read_Membrane_Keys();
             delay(100);
             //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
             Serial.println(F("Settings Saved"));
             Menu_Complete_Sensors = true;
             lcd.clear();
             lcd.setCursor(0,0);
             lcd.print("Hits : ");
             lcd.print(Low_Battery_Instances_Chg);
             lcd.setCursor(0,1);
             lcd.print(F("SAVED"));
             delay(2000);
             lcd.clear();          
             EEPROM.write(85, 1);
             EEPROM.write(86, Low_Battery_Instances_Chg);   
             Menu_Mode_Selection = 0;
             }
             if (!Plus_Key_X) {
               Low_Battery_Instances_Chg = Low_Battery_Instances_Chg + 1;
               if (Low_Battery_Instances_Chg> 50) Low_Battery_Instances_Chg = 50;
               lcd.clear();
               lcd.setCursor(0,0); 
               lcd.print(F("Batt Sensitivity:"));
               lcd.setCursor(0,1);
               lcd.print(F("Hits = "));
               lcd.print(Low_Battery_Instances_Chg);
               Serial.print(F("Battery sensitivity = :"));
               Serial.println(Low_Battery_Instances_Chg);
               }
             if (!Minus_Key_X) {
               Low_Battery_Instances_Chg = Low_Battery_Instances_Chg - 1;
               if (Low_Battery_Instances_Chg < 1) Low_Battery_Instances_Chg = 1;
               lcd.clear();
               lcd.setCursor(0,0); 
               lcd.print(F("Batt Sensitivity:"));
               lcd.setCursor(0,1);
               lcd.print(F("Hits = "));
               lcd.print(Low_Battery_Instances_Chg);
               Serial.print(F("Battery sensitivity = :"));
               Serial.println(Low_Battery_Instances_Chg);
               }
             
             }
     }



   if (Menu_Mode_Selection == 6) {
       // Wire Sensor ON/OFF
       lcd.clear();
       lcd.print(F("Wire Sensor"));
       delay(1000);
       lcd.clear();
       Menu_Mode_Selection = 0;
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print(F("Wire Sensor"));
       lcd.setCursor(0,1);
       lcd.print(F("Status : "));
       if (Perimeter_Wire_Enabled == 1) lcd.print(F("ON "));
       if (Perimeter_Wire_Enabled == 0) lcd.print(F("OFF"));
       
       Menu_Complete_Sensors = false;
       while (Menu_Complete_Sensors == false) {
          Read_Membrane_Keys();
          delay(100);
          //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
               Serial.println(F("Wire Sensor ON/OFF Settings Saved"));
               Menu_Complete_Sensors = true;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print(F("Wire Sensor"));
               lcd.setCursor(0,1);
               lcd.print(F("Saved: "));
               if (Perimeter_Wire_Enabled == 1) lcd.print(F("ON "));
               if (Perimeter_Wire_Enabled == 0) lcd.print(F("OFF"));
               Serial.print(F("Sensor:"));
               Serial.println(Perimeter_Wire_Enabled);
               delay(2000);
               lcd.clear();          
               EEPROM.write(67 , 1);
               EEPROM.write(68 , Perimeter_Wire_Enabled);
               Menu_Mode_Selection = 0;
               
               }
             if (!Plus_Key_X) {
               lcd.setCursor(0,1);
               lcd.print(F("Status : "));
               Perimeter_Wire_Enabled = 1;
               lcd.print(F("ON "));
               Serial.print(F("Sensor:"));
               Serial.println(Perimeter_Wire_Enabled);
               delay(100);
               }
             if (!Minus_Key_X) {
               lcd.setCursor(0,1);
               lcd.print(F("Status : "));
               Perimeter_Wire_Enabled = 0;
               lcd.print(F("OFF"));
               Serial.print(F("Sensor:"));
               Serial.println(Perimeter_Wire_Enabled);
               delay(100);
               }
     }
     }

   if (Menu_Mode_Selection == 7) {
       // Rain Sensor ON/OFF
       lcd.clear();
       lcd.print(F("Rain Sensor"));
       delay(1000);
       lcd.clear();
       Menu_Mode_Selection = 0;
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print(F("Rain Sensor"));
       lcd.setCursor(0,1);
       lcd.print(F("Status : "));
       if (Rain_Sensor_Installed == 1) lcd.print(F("ON "));
       if (Rain_Sensor_Installed == 0) lcd.print(F("OFF"));
       
       Menu_Complete_Sensors = false;
       while (Menu_Complete_Sensors == false) {
          Read_Membrane_Keys();
          delay(100);
          //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
               Serial.println(F("Rain Sensor ON/OFF Settings Saved"));
               Menu_Complete_Sensors = true;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print(F("Rain Sensor"));
               lcd.setCursor(0,1);
               lcd.print(F("Saved: "));
               if (Rain_Sensor_Installed == 1) lcd.print(F("ON "));
               if (Rain_Sensor_Installed == 0) lcd.print(F("OFF"));
               Serial.print(F("Sensor:"));
               Serial.println(Rain_Sensor_Installed);
               delay(2000);
               lcd.clear();          
               EEPROM.write(77 , 1);
               EEPROM.write(78 , Rain_Sensor_Installed);
               Menu_Mode_Selection = 0;
               
               }
             if (!Plus_Key_X) {
               lcd.setCursor(0,1);
               lcd.print(F("Status : "));
               Rain_Sensor_Installed = 1;
               lcd.print(F("ON "));
               Serial.print(F("Sensor:"));
               Serial.println(Rain_Sensor_Installed);
               delay(100);
               }
             if (!Minus_Key_X) {
               lcd.setCursor(0,1);
               lcd.print(F("Status : "));
               Rain_Sensor_Installed = 0;
               lcd.print(F("OFF"));
               Serial.print(F("Sensor:"));
               Serial.println(Rain_Sensor_Installed);
               delay(100);
               }
     }
     }

     if (Menu_Mode_Selection == 8) {
       // Rain Sensitivity
       Menu_Mode_Selection = 0;
       delay(500);
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print(F("Rain Sensitivity:"));
       lcd.setCursor(0,1);
       lcd.print(F("Hits = "));
       lcd.print(Rain_Total_Hits_Go_Home);
       Serial.print(F("Rain Sensitivity = :"));
       Serial.println(Rain_Total_Hits_Go_Home);
       Menu_Complete_Sensors = false;
       while (Menu_Complete_Sensors == false) {
             Read_Membrane_Keys();
             delay(100);
             //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
             Serial.println(F("Settings Saved"));
             Menu_Complete_Sensors = true;
             lcd.clear();
             lcd.setCursor(0,0);
             lcd.print("Hits : ");
             lcd.print(Rain_Total_Hits_Go_Home);
             lcd.setCursor(0,1);
             lcd.print(F("SAVED"));
             delay(2000);
             lcd.clear();          
             EEPROM.write(79, 1);
             EEPROM.write(80, Rain_Total_Hits_Go_Home);   
             Menu_Mode_Selection = 0;
             }
             if (!Plus_Key_X) {
               Rain_Total_Hits_Go_Home = Rain_Total_Hits_Go_Home + 1;
               if (Rain_Total_Hits_Go_Home> 50) Rain_Total_Hits_Go_Home = 50;
               lcd.clear();
               lcd.setCursor(0,0); 
               lcd.print(F("Rain Sensitivity:"));
               lcd.setCursor(0,1);
               lcd.print(F("Hits = "));
               lcd.print(Rain_Total_Hits_Go_Home);
               Serial.print(F("Rain sensitivity = :"));
               Serial.println(Rain_Total_Hits_Go_Home);
               }
             if (!Minus_Key_X) {
               Rain_Total_Hits_Go_Home = Rain_Total_Hits_Go_Home - 1;
               if (Rain_Total_Hits_Go_Home < 1) Rain_Total_Hits_Go_Home = 1;
               lcd.clear();
               lcd.setCursor(0,0); 
               lcd.print(F("Rain Sensitivity:"));
               lcd.setCursor(0,1);
               lcd.print(F("Hits = "));
               lcd.print(Rain_Total_Hits_Go_Home);
               Serial.print(F("Rain sensitivity = :"));
               Serial.println(Rain_Total_Hits_Go_Home);
               }
             
             }
     }


   if (Menu_Mode_Selection == 9) {
       // WIFI ON/OFF
       lcd.clear();
       lcd.print(F("WIFI Function"));
       delay(1000);
       lcd.clear();
       Menu_Mode_Selection = 0;
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print(F("WIFI Function"));
       lcd.setCursor(0,1);
       lcd.print(F("Status: "));
       if (WIFI_Enabled == 1) lcd.print(F("Enabled "));
       if (WIFI_Enabled == 0) lcd.print(F("Disabled"));
       
       Menu_Complete_Sensors = false;
       while (Menu_Complete_Sensors == false) {
          Read_Membrane_Keys();
          delay(100);
          //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
               Serial.println(F("Rain Sensor ON/OFF Settings Saved"));
               Menu_Complete_Sensors = true;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print(F("WIFI Function"));
               lcd.setCursor(0,1);
               lcd.print(F("Saved: "));
               if (WIFI_Enabled == 1) lcd.print(F("Enabled "));
               if (WIFI_Enabled == 0) lcd.print(F("Disabled"));
               Serial.print(F("Status:"));
               Serial.println(WIFI_Enabled);
               delay(2000);
               lcd.clear();          
               EEPROM.write(81 , 1);
               EEPROM.write(82 , WIFI_Enabled);
               Menu_Mode_Selection = 0;
               
               }
             if (!Plus_Key_X) {
               lcd.setCursor(0,1);
               lcd.print(F("Status: "));
               WIFI_Enabled = 1;
               lcd.print(F("Enabled "));
               Serial.print(F("Status:"));
               Serial.println(WIFI_Enabled);
               delay(100);
               }
             if (!Minus_Key_X) {
               lcd.setCursor(0,1);
               lcd.print(F("Status: "));
               WIFI_Enabled = 0;
               lcd.print(F("Disabled"));
               Serial.print(F("Status:"));
               Serial.println(WIFI_Enabled);
               delay(100);
               }
     }
     }

   if (Menu_Mode_Selection == 10) {
       // Bumper Bar ON/OFF
       lcd.clear();
       lcd.print(F("Bumper Bar"));
       delay(1000);
       lcd.clear();
       Menu_Mode_Selection = 0;
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print(F("Bumper Bar"));
       lcd.setCursor(0,1);
       lcd.print(F("Status : "));
       if (Bumper_Activate_Frnt == 1) lcd.print(F("ON "));
       if (Bumper_Activate_Frnt == 0) lcd.print(F("OFF"));
       
       Menu_Complete_Sensors = false;
       while (Menu_Complete_Sensors == false) {
          Read_Membrane_Keys();
          delay(100);
          //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
               Serial.println(F("Wire Sensor ON/OFF Settings Saved"));
               Menu_Complete_Sensors = true;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print(F("Bumper Bar"));
               lcd.setCursor(0,1);
               lcd.print(F("Saved: "));
               if (Bumper_Activate_Frnt == 1) {
                  lcd.print(F("ON "));
                  Setup_Bumper_Bar();
                  }
               if (Bumper_Activate_Frnt == 0) lcd.print(F("OFF"));
               Serial.print(F("Sensor:"));
               Serial.println(Bumper_Activate_Frnt);
               delay(2000);
               lcd.clear();          
               EEPROM.write(90 , 1);
               EEPROM.write(91 , Bumper_Activate_Frnt);
               Menu_Mode_Selection = 0;
               
               }
             if (!Plus_Key_X) {
               lcd.setCursor(0,1);
               lcd.print(F("Status : "));
               Bumper_Activate_Frnt = 1;
               lcd.print(F("ON "));
               Serial.print(F("Sensor:"));
               Serial.println(Bumper_Activate_Frnt);
               delay(100);
               }
             if (!Minus_Key_X) {
               lcd.setCursor(0,1);
               lcd.print(F("Status : "));
               Bumper_Activate_Frnt = 0;
               lcd.print(F("OFF"));
               Serial.print(F("Sensor:"));
               Serial.println(Bumper_Activate_Frnt);
               delay(100);
               }
     }
     }


  if (Menu_Mode_Selection == 11) {
       // Angle Safety Sensor ON/OFF
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print(F("Angle ON/OFF"));
       lcd.setCursor(0,1);
       lcd.print(F("Mode"));
       delay(1000);
       lcd.clear();
       Menu_Mode_Selection = 0;
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print(F("Angle ON/OFF"));
       lcd.setCursor(0,1);
       lcd.print("Status : ");
       if (Angle_Sensor_Enabled == 1) lcd.print(F("ON "));
       if (Angle_Sensor_Enabled == 0) lcd.print(F("OFF"));
       
       Menu_Complete = false;
       while (Menu_Complete == false) {
          Read_Membrane_Keys();
          delay(100);
          //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
               Serial.println(F("Tip Settings Saved"));
               Menu_Complete = true;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print("Angle Sensor");
               lcd.setCursor(0,1);
               if (Angle_Sensor_Enabled == 0) lcd.print("OFF");
               if (Angle_Sensor_Enabled == 1) lcd.print("ON"); 
               Serial.print(F("Angle Sensor ON/OFF: "));
               Serial.println(Angle_Sensor_Enabled);
               delay(2000);
               lcd.clear();          
               EEPROM.write(29 , 1);
               EEPROM.write(30 , Angle_Sensor_Enabled);
               Menu_Mode_Selection = 0;
               
               }
             if (!Plus_Key_X) {
               lcd.setCursor(0,1);
               lcd.print("Status : ");
               Angle_Sensor_Enabled = 1;
               lcd.print("ON ");
               Serial.print(F("Angle Enabled:"));
               Serial.println(Angle_Sensor_Enabled);
               delay(100);
               }
             if (!Minus_Key_X) {
               lcd.setCursor(0,1);
               lcd.print("Status : ");
               Angle_Sensor_Enabled = 0;
               lcd.print("OFF");
               Serial.print(F("Angle Enabled:"));
               Serial.println(Angle_Sensor_Enabled);
               delay(100);
               }
     }
     }

      
   if (Menu_Mode_Selection == 12) {
       // Tip Safety Sensor ON/OFF
       lcd.clear();
       delay(500);
       Menu_Mode_Selection = 0;
       lcd.setCursor(0,0);
       lcd.print(F("Tip Over Sensor"));
       lcd.setCursor(0,1);
       lcd.print(F("Status : "));
       if (Tip_Over_Sensor_Enabled == 1) lcd.print(F("ON "));
       if (Tip_Over_Sensor_Enabled == 0) lcd.print(F("OFF"));
       
       Menu_Complete = false;
       while (Menu_Complete == false) {
          Read_Membrane_Keys();
          delay(100);
          //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
               Serial.println(F("Tip Settings Saved"));
               Menu_Complete = true;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print("Tip Over Sensor");
               lcd.setCursor(0,1);
               if (Tip_Over_Sensor_Enabled == 0) lcd.print("OFF");
               if (Tip_Over_Sensor_Enabled == 1) lcd.print("ON"); 
               Serial.print(F("Tip Over Sensor:"));
               Serial.println(Tip_Over_Sensor_Enabled);
               delay(2000);
               lcd.clear();          
               EEPROM.write(92 , 1);
               EEPROM.write(93 , Tip_Over_Sensor_Enabled);
               Menu_Mode_Selection = 0;
               
               }
             if (!Plus_Key_X) {
               lcd.setCursor(0,1);
               lcd.print("Status : ");
               Tip_Over_Sensor_Enabled = 1;
               lcd.print("ON ");
               Serial.print(F("Tip Over Enabled:"));
               Serial.println(Tip_Over_Sensor_Enabled);
               delay(100);
               }
             if (!Minus_Key_X) {
               lcd.setCursor(0,1);
               lcd.print("Status : ");
               Tip_Over_Sensor_Enabled = 0;
               lcd.print("OFF");
               Serial.print(F("Tip Over Enabled:"));
               Serial.println(Tip_Over_Sensor_Enabled);
               delay(100);
               }
     }
     }     


if (Menu_Complete_Sensors = true) Print_Membrane_Switch_Input_Sensors();
}

#endif
