// Tracking SETTINGS MENU

#if defined(LCD_KEYPAD)


// Test to displyed on the LCD screen when using the membrane key menus
void Print_LCD_Menu_Tracking(byte LCD_Menu_Tracking) {
  if (LCD_Menu_Tracking == 1) lcd.print(F("Set PID"));
  if (LCD_Menu_Tracking == 2) lcd.print(F("Docking ON/OFF"));
  if (LCD_Menu_Tracking == 3) lcd.print(F("Tracking Dir"));
  if (LCD_Menu_Tracking == 4) lcd.print(F("Exit Point 1&2"));
  if (LCD_Menu_Tracking == 5) lcd.print(F("WireFind FwdBck")); 
  if (LCD_Menu_Tracking == 6) lcd.print(F("Wheel Counter"));    
  if (LCD_Menu_Tracking == 7) lcd.print(F(""));
  Max_Options_Tracking = 7;
  }


void Print_Membrane_Switch_Input_Tracking() {
     Read_Membrane_Keys();
     Menu_Complete_Tracking = 1;
     Menu_Mode_Selection = 0;
     Menu_View = 0;

      Serial.println();
      Serial.println(F("Tracking Menu Activated"));
      Menu_Complete_Tracking = false;                                // Menu complete will return to the normal loop
      lcd.clear();
      delay(5);
      
      while (Menu_Complete_Tracking == false) {                      // holds the program in a loop until a selection has been made in the membrane button menu
        if (Menu_View == 0) {
          lcd.setCursor(1,0);
          Print_LCD_Menu_Tracking(1);
          lcd.setCursor(1,1);
          Print_LCD_Menu_Tracking(2);
          }
        // Gets the values again from the keys
        Read_Membrane_Keys();
        delay(100);
             
        if(!Start_Key_X){
          Menu_Complete_Tracking = true;
          Serial.println(F("Start key is pressed"));
          Activate_Menu_Option_Tracking();
          lcd.clear();
          
          }
        if(!Plus_Key_X) {
          Serial.println(F("+ key is pressed"));
          Menu_View = Menu_View - 1;
          Run_Menu_Order_Tracking();
          }
        if(!Minus_Key_X) {
          Menu_View = Menu_View + 1;
          Run_Menu_Order_Tracking();
        }
        if(!Stop_Key_X){
          Serial.println(F("Stop key is pressed"));
          Menu_Complete_Tracking = true;
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Exit Tracking");
          delay(1000);
          lcd.clear();          
          Menu_Mode_Selection = 0;
          }
      }
    //Activate_Menu_Option_Tracking();
    }

    


// Code to scroll the menu and print the menu options in the LCD
 void Run_Menu_Order_Tracking() {
     if (Menu_View > Max_Options_Tracking) Menu_View = Menu_View -1;
     if (Menu_View < 0) Menu_View = Menu_View + 1;      
     Serial.print(F("- key is pressed "));
     lcd.clear();
     lcd.setCursor(1,0);
     Print_LCD_Menu_Tracking(Menu_View);
     lcd.setCursor(1,1);
     Print_LCD_Menu_Tracking( Menu_View + 1);
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
void Activate_Menu_Option_Tracking() {


     if (Menu_Mode_Selection == 1) {
       // Tracking PID Settings
       Menu_Mode_Selection = 0;
       lcd.clear();
       delay(500);
       lcd.setCursor(0,0);
       lcd.print(F("Tracking PID:"));
       lcd.setCursor(0,1);
       lcd.print(F("P = "));
       lcd.print(P);
       Serial.print(F("Tracking PID P = :"));
       Serial.println(P);
       Menu_Complete_Tracking = false;
       while (Menu_Complete_Tracking == false) {
             Read_Membrane_Keys();
             delay(100);
             //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
             Serial.println(F("Settings Saved"));
             Menu_Complete_Tracking = true;
             lcd.clear();
             lcd.setCursor(0,0);
             lcd.print("P : ");
             lcd.print(P);
             lcd.setCursor(0,1);
             lcd.print(F("SAVED"));
             delay(2000);
             lcd.clear();          
             EEPROM.write(21, 1);
             EEPROM.write(22, (P*100));   
             Menu_Mode_Selection = 0;
             }
             if (!Plus_Key_X) {
               P = P + 0.01;
               if (P > 10) P = 10;
               lcd.setCursor(0,1);
               lcd.print(F("      "));    // Fully clear the number to stop reminants of a previous number from being left behind
               lcd.setCursor(0,1);
               lcd.print(F("P : "));
               lcd.print(P);
               Serial.print(F("Tracking PID P = :"));
               Serial.println(P);
               }
             if (!Minus_Key_X) {
               P = P - 0.01;
               if (P < 0) P = 0;
               lcd.setCursor(0,1);
               lcd.print(F("      "));   // Fully clear the number to stop reminants of a previous number from being left behind
               lcd.setCursor(0,1);
               lcd.print(F("P : "));
               lcd.print(P);
               Serial.print(F("Tracking PID P = :"));
               Serial.println(P);
               }
             
             }
     }


if (Menu_Mode_Selection == 2) {
       // Charging Station activated
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print(F("Charging Dock"));
       lcd.setCursor(0,1);
       lcd.print(F("ON/OFF"));
       delay(1000);
       lcd.clear();
       Menu_Mode_Selection = 0;
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print(F("Dock ON/OFF"));
       lcd.setCursor(0,1);
       lcd.print(F("Status : "));
       if (Use_Charging_Station == 1) lcd.print(F("ON "));
       if (Use_Charging_Station == 0) lcd.print(F("OFF"));
       
       Menu_Complete_Tracking = false;
       while (Menu_Complete_Tracking == false) {
          Read_Membrane_Keys();
          delay(100);
          //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
               Serial.println(F("Charging Station Settings Saved"));
               Menu_Complete_Tracking = true;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print(F("Dock Saved"));
               Serial.print(F("Dock:"));
               Serial.println(Use_Charging_Station);
               delay(2000);
               lcd.clear();          
               EEPROM.write(47 , 1);
               EEPROM.write(48 , Use_Charging_Station);
               Menu_Mode_Selection = 0;
               
               }
             if (!Plus_Key_X) {
               lcd.setCursor(0,1);
               lcd.print(F("Status : "));
               Use_Charging_Station = 1;
               lcd.print(F("ON "));
               Serial.print(F("DOCK:"));
               Serial.println("Use_Charging_Station");
               delay(100);
               }
             if (!Minus_Key_X) {
               lcd.setCursor(0,1);
               lcd.print(F("Status : "));
               Use_Charging_Station = 0;
               lcd.print(F("OFF"));
               Serial.print(F("DOCK:"));
               Serial.println(Use_Charging_Station);
               delay(100);
               }
     }
     }


if (Menu_Mode_Selection == 3) {
       // Charging Station Diretion
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print(F("Tracking "));
       lcd.setCursor(0,1);
       lcd.print(F("Directions"));
       delay(1000);
       lcd.clear();
       Menu_Mode_Selection = 0;
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print(F("Exit Dir: "));
       if (CW_Tracking_To_Start == 1)  lcd.print(F("CW"));
       if (CCW_Tracking_To_Start == 1) lcd.print(F("CCW"));
       lcd.setCursor(0,1);
       lcd.print(F("Dock Dir: "));
       if (CW_Tracking_To_Charge == 1)  lcd.print(F("CW"));
       if (CCW_Tracking_To_Charge == 1) lcd.print(F("CCW"));
       
       Menu_Complete_Tracking = false;
       while (Menu_Complete_Tracking == false) {
          Read_Membrane_Keys();
          delay(100);
          //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
               Serial.println(F("Charging Station Settings Saved"));
               Menu_Complete_Tracking = true;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print(F("Tracking"));
               lcd.setCursor(0,1);
               lcd.print(F("Direction Saved"));
               delay(2000);
               lcd.clear();          
               EEPROM.write(49 , 1);
               EEPROM.write(50 , CW_Tracking_To_Charge);                
               EEPROM.write(51 , 1);
               EEPROM.write(52 , CCW_Tracking_To_Charge);       
               EEPROM.write(53 , 1);
               EEPROM.write(54 , CW_Tracking_To_Start);                
               EEPROM.write(55 , 1);
               EEPROM.write(56 , CCW_Tracking_To_Start);   
               Menu_Mode_Selection = 0;
               }               
               
             if (!Plus_Key_X) {
               lcd.clear();
               CW_Tracking_To_Start   = 1;
               CCW_Tracking_To_Charge = 1;   
               CCW_Tracking_To_Start  = 0;
               CW_Tracking_To_Charge  = 0;  
               lcd.setCursor(0,0); 
               lcd.print(F("Exit Dir: "));               
               if (CW_Tracking_To_Start == 1)  lcd.print(F("CW"));
               if (CCW_Tracking_To_Start == 1) lcd.print(F("CCW"));
               lcd.setCursor(0,1);
               lcd.print(F("Dock Dir: "));
               if (CW_Tracking_To_Charge == 1)  lcd.print(F("CW"));
               if (CCW_Tracking_To_Charge == 1) lcd.print(F("CCW"));
               }


               
             if (!Minus_Key_X) {
               lcd.clear();
               CW_Tracking_To_Start   = 0;
               CCW_Tracking_To_Charge = 0;   
               CCW_Tracking_To_Start  = 1;
               CW_Tracking_To_Charge  = 1;  
               lcd.setCursor(0,0); 
               lcd.print(F("Exit Dir: "));               
               if (CW_Tracking_To_Start == 1)  lcd.print(F("CW"));
               if (CCW_Tracking_To_Start == 1) lcd.print(F("CCW"));
               lcd.setCursor(0,1);
               lcd.print(F("Dock Dir: "));
               if (CW_Tracking_To_Charge == 1)  lcd.print(F("CW"));
               if (CCW_Tracking_To_Charge == 1) lcd.print(F("CCW"));
               }
       }
     }

   if (Menu_Mode_Selection == 4) {
       // Sets the Exit point of Zone 1 and 2
       // Number of loop cycles when the mower is tracking the wire to Zone 1 and Zone 2

     
       int Set = 1;
       Menu_Mode_Selection = 0;
       lcd.clear();
       delay(100);
       lcd.setCursor(0,0);
       lcd.print(F("Tracking Zone"));
       lcd.setCursor(0,1);
       lcd.print(F("1&2 Cycles"));
       delay(1000);
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print(F("> Zone1:"));
       lcd.print(Track_Wire_Zone_1_Cycles);
       lcd.setCursor(0,1);
       lcd.print(F("  Zone2:"));
       lcd.print(Track_Wire_Zone_2_Cycles);
       Menu_Complete_Tracking = false;
       while (Menu_Complete_Tracking == false) {
             Read_Membrane_Keys();
             delay(100);
             //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
             
             if (Set == 2) { 
               Serial.println(F("Settings Saved"));
               Menu_Complete_Tracking = true;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print(F("Z1&Z2 Track"));
               lcd.setCursor(0,1);
               lcd.print(F("Cycles SAVED"));
               delay(2000);
               lcd.clear();          
               EEPROM.write(43, 1);
               EEPROM.write(44, (Track_Wire_Zone_1_Cycles/100));
               EEPROM.write(45, 1);
               EEPROM.write(46, (Track_Wire_Zone_2_Cycles/100));
               Menu_Mode_Selection = 0;
               }
              
             if (Set == 1) {
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print(F("  Zone1:"));
                lcd.print(Track_Wire_Zone_1_Cycles);
                lcd.setCursor(0,1);
                lcd.print(F("> Zone2:"));
                lcd.print(Track_Wire_Zone_2_Cycles);   
                Set = Set + 1;          
                }


             }
             if (!Plus_Key_X) {
               if (Set == 1) {
                 Track_Wire_Zone_1_Cycles = Track_Wire_Zone_1_Cycles + 100;
                 lcd.setCursor(0,0);
                 lcd.setCursor(0,0);
                 lcd.print(F("> Zone1:"));
                 lcd.print(Track_Wire_Zone_1_Cycles);
                 lcd.setCursor(0,1);
                 lcd.print(F("  Zone2:"));
                 lcd.print(Track_Wire_Zone_2_Cycles);
                 }
               if (Set == 2) {
                 Track_Wire_Zone_2_Cycles = Track_Wire_Zone_2_Cycles + 100;
                 lcd.setCursor(0,0);
                 lcd.setCursor(0,0);
                 lcd.print(F("  Zone1:"));
                 lcd.print(Track_Wire_Zone_1_Cycles);
                 lcd.setCursor(0,1);
                 lcd.print(F("> Zone2:"));
                 lcd.print(Track_Wire_Zone_2_Cycles);          
                 }
               }
             if (!Minus_Key_X) {
               if (Set == 1) {
                 Track_Wire_Zone_1_Cycles = Track_Wire_Zone_1_Cycles - 100;
                   if (Track_Wire_Zone_1_Cycles < 1000) lcd.clear();     
                   if (Track_Wire_Zone_1_Cycles <= 0) {
                     lcd.clear();
                     Track_Wire_Zone_1_Cycles = 100;      // cant be less than zero.
                     }
                 lcd.setCursor(0,0);
                 lcd.print(F("> Zone1:"));
                 lcd.print(Track_Wire_Zone_1_Cycles);
                 lcd.setCursor(0,1);
                 lcd.print(F("  Zone2:"));
                 lcd.print(Track_Wire_Zone_2_Cycles);
                 }
               if (Set == 2) {
                 Track_Wire_Zone_2_Cycles = Track_Wire_Zone_2_Cycles - 100;
                 if (Track_Wire_Zone_2_Cycles < 1000) lcd.clear();
                 lcd.setCursor(0,0);
                 lcd.print(F("  Zone1:"));
                 lcd.print(Track_Wire_Zone_1_Cycles);
                 lcd.setCursor(0,1);
                 lcd.print(F("> Zone2:"));
                 lcd.print(Track_Wire_Zone_2_Cycles);          
                 }
               }
     
             
     }
     }


     if (Menu_Mode_Selection == 5) {
       // Forward and Reverse Tracking Distance to find wire
     
       int Set = 1;
       Menu_Mode_Selection = 0;
       lcd.clear();
       delay(100);
       lcd.setCursor(0,0);
       lcd.print(F("Set Wire Find"));
       lcd.setCursor(0,1);
       lcd.print(F("Distance/Cycles "));
       delay(1000);
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print(F(">Track Fwd: "));
       lcd.print(Max_Cycle_Wire_Find );
       lcd.setCursor(0,1);
       lcd.print(F(" Track Bck: "));
       lcd.print(Max_Cycle_Wire_Find_Back);
       Menu_Complete_Tracking = false;
       while (Menu_Complete_Tracking == false) {
             Read_Membrane_Keys();
             delay(100);
             //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
             
             if (Set == 2) { 
               Serial.println(F("Settings Saved"));
               Menu_Complete_Tracking = true;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print(F("Fwd/Bck Track"));
               lcd.setCursor(0,1);
               lcd.print(F("Cycles SAVED"));
               delay(2000);
               lcd.clear();          
               EEPROM.write(69, 1);
               EEPROM.write(70, (Max_Cycle_Wire_Find/10));
               EEPROM.write(71, 1);
               EEPROM.write(72, (Max_Cycle_Wire_Find_Back/10));
               Menu_Mode_Selection = 0;
               }
              
             if (Set == 1) {
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print(F(" Track Fwd: "));
                lcd.print(Max_Cycle_Wire_Find);
                lcd.setCursor(0,1);
                lcd.print(F(">Track Bck: "));
                lcd.print(Max_Cycle_Wire_Find_Back);
                Set = Set + 1;  
                delay(200);        
                }


             }
             if (!Plus_Key_X) {
               if (Set == 1) {
                 Max_Cycle_Wire_Find = Max_Cycle_Wire_Find + 10;
                 lcd.setCursor(0,0);
                 lcd.print(F(">Track Fwd: "));
                 lcd.print(Max_Cycle_Wire_Find );
                 lcd.setCursor(0,1);
                 lcd.print(F(" Track Bck: "));
                 lcd.print(Max_Cycle_Wire_Find_Back);
                 }
               if (Set == 2) {
                 Max_Cycle_Wire_Find_Back = Max_Cycle_Wire_Find_Back + 10;
                 lcd.setCursor(0,0);
                 lcd.print(F(" Track Fwd: "));
                 lcd.print(Max_Cycle_Wire_Find);
                 lcd.setCursor(0,1);
                 lcd.print(F(">Track Bck: "));
                 lcd.print(Max_Cycle_Wire_Find_Back);         
                 }
               }
             if (!Minus_Key_X) {
               if (Set == 1) {
                 Max_Cycle_Wire_Find = Max_Cycle_Wire_Find - 10;
                 if (Max_Cycle_Wire_Find <= 10) Max_Cycle_Wire_Find = 10;      // cant be less than zero.
                 lcd.clear();
                 lcd.setCursor(0,0);
                 lcd.print(F(">Track Fwd: "));
                 lcd.print(Max_Cycle_Wire_Find);
                 lcd.setCursor(0,1);
                 lcd.print(F(" Track Bck: "));
                 lcd.print(Max_Cycle_Wire_Find_Back);  
                 }
               if (Set == 2) {
                 Max_Cycle_Wire_Find_Back = Max_Cycle_Wire_Find_Back - 10;
                 if (Max_Cycle_Wire_Find_Back <= 10) Max_Cycle_Wire_Find_Back = 10;      // cant be less than zero.
                 lcd.clear();
                 lcd.setCursor(0,0);
                 lcd.print(F(" Track Fwd: "));
                 lcd.print(Max_Cycle_Wire_Find);
                 lcd.setCursor(0,1);
                 lcd.print(F(">Track Bck: "));
                 lcd.print(Max_Cycle_Wire_Find_Back);       
                 }
               }
     
             
     }
     }



     if (Menu_Mode_Selection == 6) {
       //Wheel Input Counter LH and RH
     
       int Set = 1;
       Menu_Mode_Selection = 0;
       lcd.clear();
       delay(100);
       lcd.setCursor(0,0);
       lcd.print(F("Wheel Input"));
       lcd.setCursor(0,1);
       lcd.print(F("Counter/Cycles "));
       delay(1000);
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print(F(">RH Wheel: "));
       lcd.print(Max_Tracking_Turn_Right );
       lcd.setCursor(0,1);
       lcd.print(F(" LH Wheel: "));
       lcd.print(Max_Tracking_Turn_Left);
       Menu_Complete_Tracking = false;
       while (Menu_Complete_Tracking == false) {
             Read_Membrane_Keys();
             delay(100);
             //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
             
             if (Set == 2) { 
               Serial.println(F("Settings Saved"));
               Menu_Complete_Tracking = true;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print(F("Wheel Counter/"));
               lcd.setCursor(0,1);
               lcd.print(F("Cycles SAVED"));
               delay(2000);
               lcd.clear();          
               EEPROM.write(73, 1);
               EEPROM.write(74, (Max_Tracking_Turn_Right/10));
               EEPROM.write(75, 1);
               EEPROM.write(76, (Max_Tracking_Turn_Left/10));
               Menu_Mode_Selection = 0;
               }
              
             if (Set == 1) {
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print(F(" RH Wheel: "));
                lcd.print(Max_Tracking_Turn_Right);
                lcd.setCursor(0,1);
                lcd.print(F(">LH Wheel: "));
                lcd.print(Max_Tracking_Turn_Left);
                Set = Set + 1;  
                delay(200);        
                }


             }
             if (!Plus_Key_X) {
               if (Set == 1) {
                 Max_Tracking_Turn_Right = Max_Tracking_Turn_Right + 10;
                 lcd.setCursor(0,0);
                 lcd.print(F(">RH Wheel: "));
                 lcd.print(Max_Tracking_Turn_Right );
                 lcd.setCursor(0,1);
                 lcd.print(F(" LH Wheel: "));
                 lcd.print(Max_Tracking_Turn_Left);
                 }
               if (Set == 2) {
                 Max_Tracking_Turn_Left = Max_Tracking_Turn_Left + 10;
                 lcd.setCursor(0,0);
                 lcd.print(F(" RH Wheel: "));
                 lcd.print(Max_Tracking_Turn_Right);
                 lcd.setCursor(0,1);
                 lcd.print(F(">LH Wheel: "));
                 lcd.print(Max_Tracking_Turn_Left);         
                 }
               }
             if (!Minus_Key_X) {
               if (Set == 1) {
                 Max_Tracking_Turn_Right = Max_Tracking_Turn_Right - 10;
                 if (Max_Tracking_Turn_Right <= 100) Max_Tracking_Turn_Right = 100;      // cant be less than zero.
                 lcd.clear();
                 lcd.setCursor(0,0);
                 lcd.print(F(">RH Wheel: "));
                 lcd.print(Max_Tracking_Turn_Right);
                 lcd.setCursor(0,1);
                 lcd.print(F(" LH Wheel: "));
                 lcd.print(Max_Tracking_Turn_Left);  
                 }
               if (Set == 2) {
                 Max_Tracking_Turn_Left = Max_Tracking_Turn_Left - 10;
                 if (Max_Tracking_Turn_Left <= 100) Max_Tracking_Turn_Left = 100;      // cant be less than zero.
                 lcd.clear();
                 lcd.setCursor(0,0);
                 lcd.print(F(" RH Wheel: "));
                 lcd.print(Max_Tracking_Turn_Right);
                 lcd.setCursor(0,1);
                 lcd.print(F(">LH Wheel: "));
                 lcd.print(Max_Tracking_Turn_Left);       
                 }
               }
     
             
     }
     }

     
if (Menu_Complete_Tracking = true) Print_Membrane_Switch_Input_Tracking();   
}

#endif
