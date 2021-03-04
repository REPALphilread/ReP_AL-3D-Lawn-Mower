// Motion SETTINGS MENU

#if defined(LCD_KEYPAD)

// Test to displyed on the LCD screen when using the membrane key menus
void Print_LCD_Menu_Motion(byte LCD_Menu_Motion) {
  if (LCD_Menu_Motion == 1) lcd.print(F("Wheel Speed"));
  if (LCD_Menu_Motion == 2) lcd.print(F("Blade Speed"));  //+need to add ON/OFF
  if (LCD_Menu_Motion == 3) lcd.print(F("Blades ON/OFF"));
  if (LCD_Menu_Motion == 4) lcd.print(F("Turn Angles"));
  if (LCD_Menu_Motion == 5) lcd.print(F("Reverse Dist"));
  if (LCD_Menu_Motion == 6) lcd.print(F("Max Length"));
  if (LCD_Menu_Motion == 7) lcd.print(F("Pattern Mow"));
  if (LCD_Menu_Motion == 8) lcd.print(F("-SPARE-"));

  
  Max_Options_Motion = 8;
  }


void Print_Membrane_Switch_Input_Motion() {
     Read_Membrane_Keys();
     Menu_Complete_Motion = 1;
     Menu_Mode_Selection = 0;
     Menu_View = 0;

      Serial.println();
      Serial.println(F("Motion Menu Activated"));
      Menu_Complete_Motion = false;                                // Menu complete will return to the normal loop
      lcd.clear();
      delay(5);
      
      while (Menu_Complete_Motion == false) {                      // holds the program in a loop until a selection has been made in the membrane button menu
        if (Menu_View == 0) {
          lcd.setCursor(1,0);
          Print_LCD_Menu_Motion(1);
          lcd.setCursor(1,1);
          Print_LCD_Menu_Motion(2);
          }
        // Gets the values again from the keys
        Read_Membrane_Keys();
        delay(100);
             
        if(!Start_Key_X){
          Menu_Complete_Motion = true;
          Serial.println(F("Start key is pressed"));
          Activate_Menu_Option_Motion();
          lcd.clear();
          
          }
        if(!Plus_Key_X) {
          Serial.println(F("+ key is pressed"));
          Menu_View = Menu_View - 1;
          Run_Menu_Order_Motion();
          }
        if(!Minus_Key_X) {
          Menu_View = Menu_View + 1;
          Run_Menu_Order_Motion();
        }
        if(!Stop_Key_X){
          Serial.println(F("Stop key is pressed"));
          Menu_Complete_Motion = true;
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Exit Motion");
          delay(1000);
          lcd.clear();          
          Menu_Mode_Selection = 0;
          }
      }
    }

    


// Code to scroll the menu and print the menu options in the LCD
 void Run_Menu_Order_Motion() {
     if (Menu_View > Max_Options_Motion) Menu_View = Menu_View -1;
     if (Menu_View < 0) Menu_View = Menu_View + 1;      
     Serial.print(F("- key is pressed "));
     lcd.clear();
     lcd.setCursor(1,0);
     Print_LCD_Menu_Motion(Menu_View);
     lcd.setCursor(1,1);
     Print_LCD_Menu_Motion( Menu_View + 1);
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
void Activate_Menu_Option_Motion() {


   if (Menu_Mode_Selection == 1) {
       // LH and RH wheel SPEED PWM settings
     
       int Set = 1;
       Menu_Mode_Selection = 0;
       lcd.clear();
       delay(100);
       lcd.setCursor(0,0);
       lcd.print(F("Set Wheel PWM"));
       lcd.setCursor(0,1);
       lcd.print(F("LH & RH Wheels"));
       delay(1000);
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print(F("> LH_PWM: "));
       lcd.print(PWM_MaxSpeed_LH);
       lcd.setCursor(0,1);
       lcd.print(F("  RH_PWM: "));
       lcd.print(PWM_MaxSpeed_RH);
       Menu_Complete_Motion = false;
       while (Menu_Complete_Motion == false) {
             Read_Membrane_Keys();
             delay(100);
             //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
             
             if (Set == 2) { 
               Serial.println(F("Settings Saved"));
               Menu_Complete_Motion = true;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print(F("Wheel PWM"));
               lcd.setCursor(0,1);
               lcd.print(F("SAVED"));
               delay(2000);
               lcd.clear();          
               EEPROM.write(13, 1);
               EEPROM.write(14, PWM_MaxSpeed_LH);
               EEPROM.write(15, 1);
               EEPROM.write(16, PWM_MaxSpeed_RH);
               Menu_Mode_Selection = 0;
               }
              
             if (Set == 1) {
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print(F("  LH_PWM: "));
                lcd.print(PWM_MaxSpeed_LH);
                lcd.setCursor(0,1);
                lcd.print(F("> RH_PWM: "));
                lcd.print(PWM_MaxSpeed_RH);   
                Set = Set + 1;          
                }


             }
             if (!Plus_Key_X) {
               if (Set == 1) {
                 PWM_MaxSpeed_LH = PWM_MaxSpeed_LH + 1;
                 if (PWM_MaxSpeed_LH > 255) PWM_MaxSpeed_LH = 255;
                 lcd.clear();
                 lcd.setCursor(0,0);
                 lcd.print(F("> LH_PWM: "));
                 lcd.print(PWM_MaxSpeed_LH);
                 lcd.setCursor(0,1);
                 lcd.print(F("  RH_PWM: "));
                 lcd.print(PWM_MaxSpeed_RH);
                 }
               if (Set == 2) {
                 PWM_MaxSpeed_RH = PWM_MaxSpeed_RH + 1;
                 if (PWM_MaxSpeed_RH > 255) PWM_MaxSpeed_RH = 255;
                 lcd.clear();
                 lcd.setCursor(0,0);
                 lcd.print(F("  LH_PWM: "));
                 lcd.print(PWM_MaxSpeed_LH);
                 lcd.setCursor(0,1);
                 lcd.print(F("> RH_PWM: "));
                 lcd.print(PWM_MaxSpeed_RH);       
                 }
               }
             if (!Minus_Key_X) {
               if (Set == 1) {
                 PWM_MaxSpeed_LH = PWM_MaxSpeed_LH - 1;
                 if (PWM_MaxSpeed_LH < 0) PWM_MaxSpeed_LH = 0;
                 lcd.setCursor(0,0);
                 lcd.setCursor(0,0);
                 lcd.print(F("> LH_PWM: "));
                 lcd.print(PWM_MaxSpeed_LH);
                 lcd.setCursor(0,1);
                 lcd.print(F("  RH_PWM: "));
                 lcd.print(PWM_MaxSpeed_RH);
                 }
               if (Set == 2) {
                 PWM_MaxSpeed_RH = PWM_MaxSpeed_RH - 1;
                 if (PWM_MaxSpeed_RH < 0) PWM_MaxSpeed_RH = 0;
                 lcd.setCursor(0,0);
                 lcd.setCursor(0,0);
                 lcd.print(F("  LH_PWM: "));
                 lcd.print(PWM_MaxSpeed_LH);
                 lcd.setCursor(0,1);
                 lcd.print(F("> RH_PWM: "));
                 lcd.print(PWM_MaxSpeed_RH);       
                 }
               }
     
             
     }
     }




     if (Menu_Mode_Selection == 2) {
       // Blade SPEED PWM Settings
       Menu_Mode_Selection = 0;
       lcd.clear();
       delay(500);
       lcd.setCursor(0,0);
       lcd.print(F("Blade Speed:"));
       lcd.setCursor(0,1);
       lcd.print(PWM_Blade_Speed);
       Serial.print(F("Blade PWM:"));
       Serial.println(PWM_Blade_Speed);
       Menu_Complete_Motion = false;
       while (Menu_Complete_Motion == false) {
             Read_Membrane_Keys();
             delay(100);
             //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
             Serial.println(F("Settings Saved"));
             Menu_Complete_Motion = true;
             lcd.clear();
             lcd.setCursor(0,0);
             lcd.print(F("Blade PWM:"));
             lcd.print(PWM_Blade_Speed);
             lcd.setCursor(0,1);
             lcd.print("SAVED");
             delay(2000);
             lcd.clear();          
             EEPROM.write(17, 1);
             EEPROM.write(18, PWM_Blade_Speed);   
             Menu_Mode_Selection = 0;
             }
             if (!Plus_Key_X) {
               PWM_Blade_Speed = PWM_Blade_Speed + 1;
               if (PWM_Blade_Speed > 255) PWM_Blade_Speed = 255;
               lcd.setCursor(0,1);
               lcd.print(F("      "));    // Fully clear the number to stop reminants of a previous number from being left behind
               lcd.setCursor(0,1);
               lcd.print(PWM_Blade_Speed);
               Serial.print(F("Blade PWM:"));
               Serial.println(PWM_Blade_Speed);
               }
             if (!Minus_Key_X) {
               PWM_Blade_Speed = PWM_Blade_Speed - 1;
               if (PWM_Blade_Speed < 0) PWM_Blade_Speed = 0;
               lcd.setCursor(0,1);
               lcd.print(F("      "));   // Fully clear the number to stop reminants of a previous number from being left behind
               lcd.setCursor(0,1);
               lcd.print(PWM_Blade_Speed);
               Serial.print(F("Blade PWM:"));
               Serial.println(PWM_Blade_Speed);
               }
             
             }
     }
        

   if (Menu_Mode_Selection == 3) {
       // Cutting Blades ON/OFF
       lcd.clear();
       lcd.print(F("Cutting Blades"));
       lcd.setCursor(0,1);
       lcd.print(F("ON/OFF "));       
       delay(1000);
       lcd.clear();
       Menu_Mode_Selection = 0;
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print(F("Cutting Blades"));
       lcd.setCursor(0,1);
       lcd.print(F("Status: "));
       if (Cutting_Blades_Activate == 1) lcd.print(F("ON "));
       if (Cutting_Blades_Activate == 0) lcd.print(F("OFF"));
       
       Menu_Complete_Motion = false;
       while (Menu_Complete_Motion == false) {
          Read_Membrane_Keys();
          delay(100);
          //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
               Serial.println(F("Cutting Blades ON/OFF Settings Saved"));
               Menu_Complete_Motion = true;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print(F("Cutting Blades"));
               lcd.setCursor(0,1);
               lcd.print(F("Saved: "));
               if (Cutting_Blades_Activate == 1) lcd.print(F("ON "));
               if (Cutting_Blades_Activate == 0) lcd.print(F("OFF"));
               Serial.print(F("Status:"));
               Serial.println(Cutting_Blades_Activate);
               delay(2000);
               lcd.clear();          
               EEPROM.write(83 , 1);
               EEPROM.write(84 , Cutting_Blades_Activate);
               Menu_Mode_Selection = 0;
               
               }
             if (!Plus_Key_X) {
               lcd.setCursor(0,1);
               lcd.print(F("Status: "));
               Cutting_Blades_Activate = 1;
               lcd.print(F("ON "));
               Serial.print(F("Status:"));
               Serial.println(Cutting_Blades_Activate);
               delay(100);
               }
             if (!Minus_Key_X) {
               lcd.setCursor(0,1);
               lcd.print(F("Status: "));
               Cutting_Blades_Activate = 0;
               lcd.print(F("OFF"));
               Serial.print(F("Status:"));
               Serial.println(Cutting_Blades_Activate);
               delay(100);
               }
     }
     }

     if (Menu_Mode_Selection == 4) {
       // Turn Time / Angles at Wire: Sets the turning time when the mower changes direction
     
       int Set = 1;
       Menu_Mode_Selection = 0;
       lcd.clear();
       delay(100);
       lcd.setCursor(0,0);
       lcd.print(F("Set Turn time"));
       lcd.setCursor(0,1);
       lcd.print(F("Min/Max ms"));
       delay(1000);
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print(F("> Min/ms:"));
       lcd.print(Mower_Turn_Delay_Min);
       lcd.setCursor(0,1);
       lcd.print(F("  Max/ms:"));
       lcd.print(Mower_Turn_Delay_Max);
       Menu_Complete_Motion = false;
       while (Menu_Complete_Motion == false) {
             Read_Membrane_Keys();
             delay(100);
             //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
             
             if (Set == 2) { 
               Serial.println(F("Settings Saved"));
               Menu_Complete_Motion = true;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print(F("Min Max Turn"));
               lcd.setCursor(0,1);
               lcd.print(F("SAVED"));
               delay(2000);
               lcd.clear();          
               EEPROM.write(31, 1);
               EEPROM.write(32, (Mower_Turn_Delay_Min/100));
               EEPROM.write(33, 1);
               EEPROM.write(34, (Mower_Turn_Delay_Max/100));
               Menu_Mode_Selection = 0;
               }
              
             if (Set == 1) {
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print(F("  Min/ms:"));
                lcd.print(Mower_Turn_Delay_Min);
                lcd.setCursor(0,1);
                lcd.print(F("> Max/ms:"));
                lcd.print(Mower_Turn_Delay_Max);   
                Set = Set + 1;          
                }


             }
             if (!Plus_Key_X) {
               if (Set == 1) {
                 Mower_Turn_Delay_Min = Mower_Turn_Delay_Min + 100;
                 if (Mower_Turn_Delay_Min >= Mower_Turn_Delay_Max) {
                  lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print("Min must be");
                  lcd.setCursor(0,1);
                  lcd.print("lower than max");
                  Mower_Turn_Delay_Min = Mower_Turn_Delay_Max - 100;
                  delay(1000);
                  lcd.clear();
                  }
                 lcd.setCursor(0,0);
                 lcd.setCursor(0,0);
                 lcd.print(F("> Min/ms:"));
                 lcd.print(Mower_Turn_Delay_Min);
                 lcd.setCursor(0,1);
                 lcd.print(F("  Max/ms:"));
                 lcd.print(Mower_Turn_Delay_Max);
                 }
               if (Set == 2) {
                 Mower_Turn_Delay_Max = Mower_Turn_Delay_Max + 100;
                 lcd.setCursor(0,0);
                 lcd.setCursor(0,0);
                 lcd.print(F("  Min/ms:"));
                 lcd.print(Mower_Turn_Delay_Min);
                 lcd.setCursor(0,1);
                 lcd.print(F("> Max/ms:"));
                 lcd.print(Mower_Turn_Delay_Max);          
                 }
               }
             if (!Minus_Key_X) {
               if (Set == 1) {
                 Mower_Turn_Delay_Min = Mower_Turn_Delay_Min - 100;
                   if (Mower_Turn_Delay_Min < 1000) lcd.clear();     
                   if (Mower_Turn_Delay_Min <= 0) {
                     lcd.clear();
                     Mower_Turn_Delay_Min = 100;      // cant be less than zero.
                     }
                 lcd.setCursor(0,0);
                 lcd.print(F("> Min/ms:"));
                 lcd.print(Mower_Turn_Delay_Min);
                 lcd.setCursor(0,1);
                 lcd.print(F("  Max/ms:"));
                 lcd.print(Mower_Turn_Delay_Max);
                 }
               if (Set == 2) {
                 Mower_Turn_Delay_Max = Mower_Turn_Delay_Max - 100;
                 if (Mower_Turn_Delay_Max < 1000) lcd.clear();
                 if (Mower_Turn_Delay_Max <= Mower_Turn_Delay_Min) {     // Max vant be less than min Value
                  lcd.clear();
                  lcd.setCursor(0,0);
                  lcd.print("Max must be");
                  lcd.setCursor(0,1);
                  lcd.print("Higher than Min");
                  Mower_Turn_Delay_Max = Mower_Turn_Delay_Min + 100;
                  delay(1000);
                  lcd.clear();
                 }
                 lcd.setCursor(0,0);
                 lcd.print(F("  Min/ms:"));
                 lcd.print(Mower_Turn_Delay_Min);
                 lcd.setCursor(0,1);
                 lcd.print(F("> Max/ms:"));
                 lcd.print(Mower_Turn_Delay_Max);          
                 }
               }
     
             
     }
     }


     if (Menu_Mode_Selection == 5) {
       // Mower Reverse Time
       Menu_Mode_Selection = 0;
       lcd.clear();
       delay(100);
       lcd.setCursor(0,0);
       lcd.print(F("Reverse Time/ms:"));
       lcd.setCursor(0,1);
       lcd.print(Mower_Reverse_Delay);
       Serial.print(F("Mower Reverse Time /ms:"));
       Serial.println(Mower_Reverse_Delay);
       Menu_Complete_Motion = false;
       while (Menu_Complete_Motion == false) {
             Read_Membrane_Keys();
             delay(100);
             //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
             Serial.println(F("Settings Saved"));
             Menu_Complete_Motion = true;
             lcd.clear();
             lcd.setCursor(0,0);
             lcd.print(F("Reverse Time/ms:"));
             lcd.print(Mower_Reverse_Delay);
             lcd.setCursor(0,1);
             lcd.print(F("SAVED"));
             delay(2000);
             lcd.clear();          
             EEPROM.write(35, 1);
             EEPROM.write(36, (Mower_Reverse_Delay/100));
             Menu_Mode_Selection = 0;
             }
             if (!Plus_Key_X) {
               Mower_Reverse_Delay = Mower_Reverse_Delay + 100;
               lcd.setCursor(0,0);
               lcd.print(F("Reverse Time/ms:"));
               lcd.setCursor(0,1);
               lcd.print(Mower_Reverse_Delay);
               }
             if (!Minus_Key_X) {
               Mower_Reverse_Delay = Mower_Reverse_Delay - 100;
               if (Mower_Reverse_Delay <= 1000) lcd.clear(); 
               if (Mower_Reverse_Delay <= 0) Mower_Reverse_Delay = 100;
               lcd.setCursor(0,0);
               lcd.print(F("Reverse Time/ms:"));
               lcd.setCursor(0,1);
               lcd.print(Mower_Reverse_Delay);
               }
             
             }
     }


      if (Menu_Mode_Selection == 6) {
       // Straight Line Distance before Automatic Turn
       // Counts the number of loops ran.  If the max number of loops are ran the mower
       // stops and turns around anyway.
       Menu_Mode_Selection = 0;
       lcd.clear();
       delay(100);
       lcd.setCursor(0,0);
       lcd.print(F("Distance Max:"));
       lcd.setCursor(0,1);
       lcd.print("Before Turn");
       delay(1000);
       lcd.clear();
       lcd.setCursor(0,1);
       lcd.print(F("Max Loops: "));
       lcd.print(Max_Cycles_Straight);
       Menu_Complete_Motion = false;
       while (Menu_Complete_Motion == false) {
             Read_Membrane_Keys();
             delay(100);
           //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
               Serial.println(F("Settings Saved"));
               Menu_Complete_Motion = true;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print(F("SAVED"));
               lcd.setCursor(0,1);
               lcd.print(F("Max Loops: "));
               lcd.print(Max_Cycles_Straight);
               delay(2000);
               lcd.clear();          
               EEPROM.write(57, 1);
               EEPROM.write(58, (Max_Cycles_Straight / 10));
  
             Menu_Mode_Selection = 0;
             }
             if (!Plus_Key_X) {
               Max_Cycles_Straight = Max_Cycles_Straight + 10;
               lcd.clear();
               lcd.setCursor(0,1);
               lcd.print(F("Max Loops: "));
               lcd.print(Max_Cycles_Straight);
               }
             if (!Minus_Key_X) {
               Max_Cycles_Straight = Max_Cycles_Straight - 10;
               if (Max_Cycles_Straight < 10) Max_Cycles_Straight = 10;
               lcd.clear();
               lcd.setCursor(0,1);
               lcd.print(F("Max Loops: "));
               lcd.print(Max_Cycles_Straight);
               }
             
             }
     }



     
      if (Menu_Mode_Selection == 7) {
       // Pattern Mow Setup
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print(F("Pattern Mow"));
       lcd.setCursor(0,1);
       lcd.print(F("Setting"));
       delay(1000);
       lcd.clear();
       Menu_Mode_Selection = 0;
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print(F("Pattern ON/OFF"));
       lcd.setCursor(0,1);
       lcd.print("Status : ");
       if (Pattern_Mow == 1) lcd.print(F("Parallel"));
       if (Pattern_Mow == 2) lcd.print(F("Spiral  "));
       if (Pattern_Mow == 0) lcd.print(F("OFF"));
       
       Menu_Complete_Motion = false;
       while (Menu_Complete_Motion == false) {
          Read_Membrane_Keys();
          delay(100);
          //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
               Serial.println(F("Compass Settings Saved"));
               Menu_Complete_Motion = true;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print("Pattern Saved");
               lcd.setCursor(0,1);
               if (Pattern_Mow == 0) {
                Pattern_Mow = 0;
                lcd.print(F("OFF"));
               }
               if (Pattern_Mow == 1) {
                lcd.print(F("Parallel"));
                Pattern_Mow = 1;
               }
               if (Pattern_Mow == 2) {
                lcd.print(F("Spiral  "));
                Pattern_Mow = 2;
                Spiral_Mow == 1;
               }
               Serial.print(F("Pattern Mow:"));
               Serial.println(Pattern_Mow);
               delay(2000);
               lcd.clear();          
               EEPROM.write(23 , 1);
               EEPROM.write(24 , Pattern_Mow);
               Menu_Mode_Selection = 0;
               
               }
             if (!Plus_Key_X) {
               lcd.setCursor(0,1);
               lcd.print("Status:");
               Pattern_Mow = Pattern_Mow + 1;
               if (Pattern_Mow > 2) Pattern_Mow = 2;
               if (Pattern_Mow == 1) lcd.print("Parallel");
               if (Pattern_Mow == 2) lcd.print("Spiral  ");  
               Serial.print(F("Pattern Mow:"));
               Serial.println(Pattern_Mow);
               delay(100);
               }
             if (!Minus_Key_X) {
               lcd.setCursor(0,1);
               lcd.print("Status : ");
               Pattern_Mow = 0;
               lcd.print("OFF       ");
               Serial.print(F("Pattern Mow:"));
               Serial.println(Pattern_Mow);
               delay(100);
               }
     }
     }



if (Menu_Complete_Motion = true) Print_Membrane_Switch_Input_Motion();  

}

#endif
