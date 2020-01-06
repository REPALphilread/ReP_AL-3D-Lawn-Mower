// BUTTONS SETTINGS MENU


// Test to displyed on the LCD screen when using the membrane key menus
void Print_LCD_Menu_Settings(byte LCD_Menu_Settings) {
  if (LCD_Menu_Settings == 1) lcd.print(F("Alarm 1"));
  if (LCD_Menu_Settings == 2) lcd.print(F("Alarm 2"));
  if (LCD_Menu_Settings == 3) lcd.print(F("Alarm 3"));  
  if (LCD_Menu_Settings == 4) lcd.print(F("Wheel Speed LH"));
  if (LCD_Menu_Settings == 5) lcd.print(F("Wheel Speed RH"));
  if (LCD_Menu_Settings == 6) lcd.print(F("Blade Speed"));
  if (LCD_Menu_Settings == 7) lcd.print(F("Compass ON/OFF"));
  if (LCD_Menu_Settings == 8) lcd.print(F("Compass Home deg"));
  if (LCD_Menu_Settings == 9) lcd.print(F("Set Clock"));
  if (LCD_Menu_Settings == 10) lcd.print(F("Pattern Mow"));
  if (LCD_Menu_Settings == 11) lcd.print(F("Battery Min"));  
  if (LCD_Menu_Settings == 12) lcd.print(F("Tracking PID"));   
  if (LCD_Menu_Settings == 13) lcd.print(F("Tip Safety"));   
  if (LCD_Menu_Settings == 14) lcd.print(F("SPARE"));  
  if (LCD_Menu_Settings == 15) lcd.print(F("SPARE"));   
  if (LCD_Menu_Settings == 16) lcd.print(F("SPARE"));   
  if (LCD_Menu_Settings == 17) lcd.print(F("SPARE"));   
  if (LCD_Menu_Settings == 18) lcd.print(F("CLEAR EEPROM"));   // Leave Blank
  if (LCD_Menu_Settings == 19) lcd.print("");   // Leave Blank
  }







void Print_Membrane_Switch_Input_Settings() {

  //Menu Options if the Mower is Settings.
     Read_Membrane_Keys();
     Menu_Complete = 1;
     Menu_Mode_Selection = 0;
     Menu_View = 0;

    
      Serial.println();
      Serial.println(F("Settings Menu Activated"));
      Menu_Complete = false;                                // Menu complete will return to the normal loop
      lcd.clear();
      delay(5);
 

      while (Menu_Complete == false) {                      // holds the program in a loop until a selection has been made in the membrane button menu
        if (Menu_View == 0) {
          lcd.setCursor(2,0);
          Print_LCD_Menu_Settings(1);
          lcd.setCursor(2,1);
          Print_LCD_Menu_Settings(2);
          }
        // Gets the values again from the keys
        Read_Membrane_Keys();
        delay(100);
             
        if(!Start_Key_X){
          Menu_Complete = true;
          Serial.println(F("Start key is pressed"));
          lcd.clear();
          Activate_Menu_Option_Settings();
          }
        if(!Plus_Key_X) {
          Serial.println(F("+ key is pressed"));
          Menu_View = Menu_View - 1;
          Run_Menu_Order_Settings();
          }
        if(!Minus_Key_X) {
          Menu_View = Menu_View + 1;
          Run_Menu_Order_Settings();
        }
        if(!Stop_Key_X){
          Serial.println(F("Stop key is pressed"));
          Menu_Complete = true;
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Menu Cancelled");
          delay(1000);
          lcd.clear();          
          Menu_Mode_Selection = 0;
          }
      }
    }

 void Run_Menu_Order_Settings() {
          if (Menu_View == 1) {
             Serial.print(F("- key is pressed "));
             lcd.clear();
             lcd.setCursor(2,0);
             Print_LCD_Menu_Settings(1);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Settings(2);
             lcd.setCursor(0,0);
             lcd.print(">");
             Menu_Mode_Selection = 1;
             Serial.print(F("Menu View : "));
             Serial.print(Menu_View);
             Serial.print(F("| Menu Selection"));
             Serial.println(Menu_Mode_Selection);
             delay(100);
             }
          if (Menu_View == 2) {
             Serial.print(F("- key is pressed "));
             lcd.clear();
             lcd.setCursor(2,0);
             Print_LCD_Menu_Settings(2);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Settings(3);
             lcd.setCursor(0,0);
             lcd.print(">");
             Menu_Mode_Selection = 2;
             Serial.print(F("Menu View : "));
             Serial.print(Menu_View);
             Serial.print(F("| Menu Selection"));
             Serial.println(Menu_Mode_Selection);
             delay(100);
             }
          if (Menu_View == 3) {
             Serial.print(F("- key is pressed "));
             lcd.clear();
             lcd.setCursor(2,0);
             Print_LCD_Menu_Settings(3);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Settings(4);
             lcd.setCursor(0,0);
             lcd.print(">");
             Menu_Mode_Selection = 3;
             Serial.print(F("Menu View : "));
             Serial.print(Menu_View);
             Serial.print(F("| Menu Selection"));
             Serial.println(Menu_Mode_Selection);
             delay(100);
             }
          if (Menu_View == 4) {
             Serial.print(F("- key is pressed "));
             lcd.clear();
             lcd.setCursor(2,0);
             Print_LCD_Menu_Settings(4);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Settings(5);
             lcd.setCursor(0,0);
             lcd.print(">");
             Menu_Mode_Selection = 4;
             Serial.print(F("Menu View : "));
             Serial.print(Menu_View);
             Serial.print(F("| Menu Selection"));
             Serial.println(Menu_Mode_Selection);
             delay(100);
             }
          if (Menu_View == 5) {
             Serial.print(F("- key is pressed "));
             lcd.clear();
             lcd.setCursor(2,0);
             Print_LCD_Menu_Settings(5);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Settings(6);
             lcd.setCursor(0,0);
             lcd.print(">");
             Menu_Mode_Selection = 5;
             Serial.print(F("Menu View : "));
             Serial.print(Menu_View);
             Serial.print(F("| Menu Selection"));
             Serial.println(Menu_Mode_Selection);
             delay(100);
             }
          if (Menu_View == 6) {
             Serial.print(F("- key is pressed "));
             lcd.clear();
             lcd.setCursor(2,0);
             Print_LCD_Menu_Settings(6);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Settings(7);
             lcd.setCursor(0,0);
             lcd.print(">");
             Menu_Mode_Selection = 6;
             Serial.print(F("Menu View : "));
             Serial.print(Menu_View);
             Serial.print(F("| Menu Selection"));
             Serial.println(Menu_Mode_Selection);
             delay(100);
             }
          if (Menu_View == 7) {
             Serial.print(F("- key is pressed "));
             lcd.clear();
             lcd.setCursor(2,0);
             Print_LCD_Menu_Settings(7);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Settings(8);
             lcd.setCursor(0,0);
             lcd.print(">");
             Menu_Mode_Selection = 7;
             Serial.print(F("Menu View : "));
             Serial.print(Menu_View);
             Serial.print(F("| Menu Selection"));
             Serial.println(Menu_Mode_Selection);
             delay(100);
             }
          if (Menu_View == 8) {
             Serial.print(F("- key is pressed "));
             lcd.clear();
             lcd.setCursor(2,0);
             Print_LCD_Menu_Settings(8);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Settings(9);
             lcd.setCursor(0,0);
             lcd.print(">");
             Menu_Mode_Selection = 8;
             Serial.print(F("Menu View : "));
             Serial.print(Menu_View);
             Serial.print(F("| Menu Selection"));
             Serial.println(Menu_Mode_Selection);
             delay(100);
             }
          if (Menu_View == 9) {
             Serial.print(F("- key is pressed "));
             lcd.clear();
             lcd.setCursor(2,0);
             Print_LCD_Menu_Settings(9);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Settings(10);
             lcd.setCursor(0,0);
             lcd.print(">");
             Menu_Mode_Selection = 9;
             Serial.print(F("Menu View : "));
             Serial.print(Menu_View);
             Serial.print(F("| Menu Selection"));
             Serial.println(Menu_Mode_Selection);
             delay(100);
             }
          if (Menu_View == 10) {
             Serial.print(F("- key is pressed "));
             lcd.clear();
             lcd.setCursor(2,0);
             Print_LCD_Menu_Settings(10);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Settings(11);
             lcd.setCursor(0,0);
             lcd.print(">");
             Menu_Mode_Selection = 10;
             Serial.print(F("Menu View : "));
             Serial.print(Menu_View);
             Serial.print(F("| Menu Selection"));
             Serial.println(Menu_Mode_Selection);
             delay(100);
             }
          if (Menu_View == 11) {
             Serial.print(F("- key is pressed "));
             lcd.clear();
             lcd.setCursor(2,0);
             Print_LCD_Menu_Settings(11);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Settings(12);
             lcd.setCursor(0,0);
             lcd.print(">");
             Menu_Mode_Selection = 11;
             Serial.print(F("Menu View : "));
             Serial.print(Menu_View);
             Serial.print(F("| Menu Selection"));
             Serial.println(Menu_Mode_Selection);
             delay(100);
             }
        
          if (Menu_View == 12) {
             Serial.print(F("- key is pressed "));
             lcd.clear();
             lcd.setCursor(2,0);
             Print_LCD_Menu_Settings(12);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Settings(13);
             lcd.setCursor(0,0);
             lcd.print(">");
             Menu_Mode_Selection = 12;
             Serial.print(F("Menu View : "));
             Serial.print(Menu_View);
             Serial.print(F("| Menu Selection"));
             Serial.println(Menu_Mode_Selection);
             delay(100);
             }

           if (Menu_View == 13) {
             Serial.print(F("- key is pressed "));
             lcd.clear();
             lcd.setCursor(2,0);
             Print_LCD_Menu_Settings(13);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Settings(14);
             lcd.setCursor(0,0);
             lcd.print(">");
             Menu_Mode_Selection = 13;
             Serial.print(F("Menu View : "));
             Serial.print(Menu_View);
             Serial.print(F("| Menu Selection"));
             Serial.println(Menu_Mode_Selection);
             delay(100);
             }

           if (Menu_View == 14) {
             Serial.print(F("- key is pressed "));
             lcd.clear();
             lcd.setCursor(2,0);
             Print_LCD_Menu_Settings(14);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Settings(15);
             lcd.setCursor(0,0);
             lcd.print(">");
             Menu_Mode_Selection = 14;
             Serial.print(F("Menu View : "));
             Serial.print(Menu_View);
             Serial.print(F("| Menu Selection"));
             Serial.println(Menu_Mode_Selection);
             delay(100);
             }

           if (Menu_View == 15) {
             Serial.print(F("- key is pressed "));
             lcd.clear();
             lcd.setCursor(2,0);
             Print_LCD_Menu_Settings(15);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Settings(16);
             lcd.setCursor(0,0);
             lcd.print(">");
             Menu_Mode_Selection = 15;
             Serial.print(F("Menu View : "));
             Serial.print(Menu_View);
             Serial.print(F("| Menu Selection"));
             Serial.println(Menu_Mode_Selection);
             delay(100);
             }

           if (Menu_View == 16) {
             Serial.print(F("- key is pressed "));
             lcd.clear();
             lcd.setCursor(2,0);
             Print_LCD_Menu_Settings(16);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Settings(17);
             lcd.setCursor(0,0);
             lcd.print(">");
             Menu_Mode_Selection = 16;
             Serial.print(F("Menu View : "));
             Serial.print(Menu_View);
             Serial.print(F("| Menu Selection"));
             Serial.println(Menu_Mode_Selection);
             delay(100);
             }

           if (Menu_View == 17) {
             Serial.print(F("- key is pressed "));
             lcd.clear();
             lcd.setCursor(2,0);
             Print_LCD_Menu_Settings(17);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Settings(18);
             lcd.setCursor(0,0);
             lcd.print(">");
             Menu_Mode_Selection = 17;
             Serial.print(F("Menu View : "));
             Serial.print(Menu_View);
             Serial.print(F("| Menu Selection"));
             Serial.println(Menu_Mode_Selection);
             delay(100);
             } 

           if (Menu_View == 18) {
             Serial.print(F("- key is pressed "));
             lcd.clear();
             lcd.setCursor(2,0);
             Print_LCD_Menu_Settings(18);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Settings(19);
             lcd.setCursor(0,0);
             lcd.print(">");
             Menu_Mode_Selection = 18;
             Serial.print(F("Menu View : "));
             Serial.print(Menu_View);
             Serial.print(F("| Menu Selection"));
             Serial.println(Menu_Mode_Selection);
             delay(100);
             }                             
      delay(100);
      }


void Activate_Menu_Option_Settings() {

     if (Menu_Mode_Selection == 1) {
       // Alarm 1 Settings
       Menu_Mode_Selection = 0;
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("Alarm_1 : ");
       lcd.print(Alarm_1_Hour);
       lcd.print(F(":"));
       if (Alarm_1_Minute < 10) lcd.print ("0");
       lcd.print(Alarm_1_Minute);
       Serial.print("Alarm 1 Status : ");
       Serial.println(Alarm_1_ON);
       lcd.setCursor(0,1);
       if (Alarm_1_ON == 1) lcd.print("Active");
       if (Alarm_1_ON == 0) lcd.print("OFF");
       Menu_Complete = false;
       delay(500);
       while (Menu_Complete == false) {
             Read_Membrane_Keys();
             delay(100);
             //Enter Code Here to Cycle until stop key is pressed.
               if(!Start_Key_X){
               Serial.println(F("Settings Saved"));
               Menu_Complete = true;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print(F("Alarm_1 :"));
               lcd.print(Alarm_1_Hour);
               lcd.print(F(":"));
               if (Alarm_1_Minute < 10) lcd.print ("0");
               lcd.print(Alarm_1_Minute);
               lcd.setCursor(0,1);
               lcd.print(F("ON  SAVED"));
               Alarm_1_ON = 1;
               delay(2000);
               lcd.clear();          
               Menu_Mode_Selection = 0;
               EEPROM.write(1, 1);
               EEPROM.write(2, Alarm_1_Hour);
               EEPROM.write(3, Alarm_1_Minute);
               EEPROM.write(4, Alarm_1_ON);
               }
             if (!Plus_Key_X) {
               Alarm_1_Minute = Alarm_1_Minute + 1;
               if (Alarm_1_Minute > 59) {
                Alarm_1_Minute = 0;
                Alarm_1_Hour = Alarm_1_Hour + 1;
                }
               if (Alarm_1_Hour > 23) Alarm_1_Hour = 0;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print(F("Alarm_1 : "));
               lcd.print(Alarm_1_Hour);
               lcd.print(F(":"));
               if (Alarm_1_Minute < 10) lcd.print ("0");
               lcd.print(Alarm_1_Minute);
               }
             if (!Minus_Key_X) {
               Alarm_1_Minute = Alarm_1_Minute - 1;
               if (Alarm_1_Minute < 0) {
                Alarm_1_Minute = 59;
                Alarm_1_Hour = Alarm_1_Hour - 1;
                if (Alarm_1_Hour < 0) Alarm_1_Hour = 23;
                }
               
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print(F("Alarm_1 : "));
               lcd.print(Alarm_1_Hour);
               lcd.print(F(":"));
               if (Alarm_1_Minute < 10) lcd.print ("0");
               lcd.print(Alarm_1_Minute);
               }
             if(!Stop_Key_X){
               Serial.println(F("Alarm Cancelled"));
               Menu_Complete = true;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print(F("Alarm_1 :"));
               lcd.print(Alarm_1_Hour);
               lcd.print(F(":"));
               if (Alarm_1_Minute < 10) lcd.print ("0");
               lcd.print(Alarm_1_Minute);
               lcd.setCursor(0,1);
               lcd.print(F("Alarm OFF"));
               Alarm_1_ON = 0;
               delay(2000);
               lcd.clear();          
               Menu_Mode_Selection = 0;
               EEPROM.write(1, 1);                                // Show the Alarm has been saved to the EEPROM
               EEPROM.write(4, Alarm_1_ON);                       // Saves that the alarm has been cancelled.
               }
             }
       Serial.print(F("Alarm 1 Status : "));
       Serial.println(Alarm_1_ON);
       delay(1000);
     }

  if (Menu_Mode_Selection == 2) {
       // Alarm 2 Settings
       Menu_Mode_Selection = 0;
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print(F("Alarm_2 : "));
       lcd.print(Alarm_2_Hour);
       lcd.print(F(":"));
       if (Alarm_2_Minute < 10) lcd.print ("0");
       lcd.print(Alarm_2_Minute);
       Serial.print(F("Alarm 2 Status : "));
       Serial.println(Alarm_2_ON);
       lcd.setCursor(0,1);
       if (Alarm_2_ON == 1) lcd.print(F("Active"));
       if (Alarm_2_ON == 0) lcd.print(F("OFF"));
       Menu_Complete = false;
       delay(500);
       while (Menu_Complete == false) {
             Read_Membrane_Keys();
             delay(100);
             //Enter Code Here to Cycle until stop key is pressed.
               if(!Start_Key_X){
               Serial.println(F("Settings Saved"));
               Menu_Complete = true;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print(F("Alarm_2 :"));
               lcd.print(Alarm_2_Hour);
               lcd.print(F(":"));
               if (Alarm_2_Minute < 10) lcd.print ("0");
               lcd.print(Alarm_2_Minute);
               lcd.setCursor(0,1);
               lcd.print(F("ON  SAVED"));
               Alarm_2_ON = 1;
               delay(2000);
               lcd.clear();          
               Menu_Mode_Selection = 0;
               EEPROM.write(5, 1);
               EEPROM.write(6, Alarm_2_Hour);
               EEPROM.write(7, Alarm_2_Minute);
               EEPROM.write(8, Alarm_2_ON);
               }
             if (!Plus_Key_X) {
               Alarm_2_Minute = Alarm_2_Minute + 1;
               if (Alarm_2_Minute > 59) {
                Alarm_2_Minute = 0;
                Alarm_2_Hour = Alarm_2_Hour + 1;
                }
               if (Alarm_2_Hour > 23) Alarm_2_Hour = 0;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print(F("Alarm_2 : "));
               lcd.print(Alarm_2_Hour);
               lcd.print(F(":"));
               if (Alarm_2_Minute < 10) lcd.print ("0");
               lcd.print(Alarm_2_Minute);
               }
             if (!Minus_Key_X) {
               Alarm_2_Minute = Alarm_2_Minute - 1;
               if (Alarm_2_Minute < 0) {
                Alarm_2_Minute = 59;
                Alarm_2_Hour = Alarm_2_Hour - 1;
                if (Alarm_2_Hour < 0) Alarm_2_Hour = 23;
                }
               
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print(F("Alarm_2 : "));
               lcd.print(Alarm_2_Hour);
               lcd.print(F(":"));
               if (Alarm_2_Minute < 10) lcd.print ("0");
               lcd.print(Alarm_2_Minute);
               }
             if(!Stop_Key_X){
               Serial.println(F("Alarm Cancelled"));
               Menu_Complete = true;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print(F("Alarm_2 :"));
               lcd.print(Alarm_2_Hour);
               lcd.print(F(":"));
               if (Alarm_2_Minute < 10) lcd.print ("0");
               lcd.print(Alarm_2_Minute);
               lcd.setCursor(0,1);
               lcd.print(F("Alarm OFF"));
               Alarm_2_ON = 0;
               delay(2000);
               lcd.clear();          
               Menu_Mode_Selection = 0;
               EEPROM.write(5, 1);
               EEPROM.write(8, Alarm_2_ON);
               }
             }
       Serial.print(F("Alarm 2 Status : "));
       Serial.println(Alarm_2_ON);
       delay(1000);
     }

if (Menu_Mode_Selection == 3) {
       // Alarm 3 Settings
       Menu_Mode_Selection = 0;
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print(F("Alarm_3 : "));
       lcd.print(Alarm_3_Hour);
       lcd.print(F(":"));
       if (Alarm_3_Minute < 10) lcd.print ("0");
       lcd.print(Alarm_3_Minute);
       Serial.print(F("Alarm 3 Status : "));
       Serial.println(Alarm_3_ON);
       lcd.setCursor(0,1);
       if (Alarm_3_ON == 1) lcd.print(F("Active"));
       if (Alarm_3_ON == 0) lcd.print(F("OFF"));
       Menu_Complete = false;
       delay(500);
       while (Menu_Complete == false) {
             Read_Membrane_Keys();
             delay(100);
             //Enter Code Here to Cycle until stop key is pressed.
               if(!Start_Key_X){
               Serial.println(F("Settings Saved"));
               Menu_Complete = true;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print(F("Alarm_3 :"));
               lcd.print(Alarm_3_Hour);
               lcd.print(F(":"));
               if (Alarm_3_Minute < 10) lcd.print ("0");
               lcd.print(Alarm_3_Minute);
               lcd.setCursor(0,1);
               lcd.print(F("ON  SAVED"));
               Alarm_3_ON = 1;
               delay(2000);
               lcd.clear();          
               Menu_Mode_Selection = 0;
               EEPROM.write(9, 1);
               EEPROM.write(10, Alarm_3_Hour);
               EEPROM.write(11, Alarm_3_Minute);
               EEPROM.write(12, Alarm_3_ON);
               }
             if (!Plus_Key_X) {
               Alarm_3_Minute = Alarm_3_Minute + 1;
               if (Alarm_3_Minute > 59) {
                Alarm_3_Minute = 0;
                Alarm_3_Hour = Alarm_3_Hour + 1;
                }
               if (Alarm_3_Hour > 23) Alarm_3_Hour = 0;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print(F("Alarm_3 : "));
               lcd.print(Alarm_3_Hour);
               lcd.print(F(":"));
               if (Alarm_3_Minute < 10) lcd.print ("0");
               lcd.print(Alarm_3_Minute);
               }
             if (!Minus_Key_X) {
               Alarm_3_Minute = Alarm_3_Minute - 1;
               if (Alarm_3_Minute < 0) {
                Alarm_3_Minute = 59;
                Alarm_3_Hour = Alarm_3_Hour - 1;
                if (Alarm_3_Hour < 0) Alarm_3_Hour = 23;
                }

              
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print(F("Alarm_3 : "));
               lcd.print(Alarm_3_Hour);
               lcd.print(F(":"));
               if (Alarm_3_Minute < 10) lcd.print ("0");
               lcd.print(Alarm_3_Minute);
               }
            
             if(!Stop_Key_X){
               Serial.println(F("Alarm Cancelled"));
               Menu_Complete = true;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print(F("Alarm_3 :"));
               lcd.print(Alarm_3_Hour);
               lcd.print(F(":"));
               if (Alarm_3_Minute < 10) lcd.print ("0");
               lcd.print(Alarm_3_Minute);
               lcd.setCursor(0,1);
               lcd.print(F("Alarm OFF"));
               Alarm_3_ON = 0;
               delay(2000);
               lcd.clear();          
               Menu_Mode_Selection = 0;
               EEPROM.write(9, 1);
               EEPROM.write(12, Alarm_3_ON);
               }
             }
       Serial.print(F("Alarm 3 Status : "));
       Serial.println(Alarm_3_ON);
       delay(1000);
     }


     
     if (Menu_Mode_Selection == 4) {
       // Wheel PWM Settings
       Menu_Mode_Selection = 0;
       lcd.clear();
       delay(100);
       lcd.setCursor(0,0);
       lcd.print(F("Wheel Speed LH:"));
       lcd.setCursor(0,1);
       lcd.print(PWM_MaxSpeed_LH);
       Serial.print(F("PWM_L:"));
       Serial.println(PWM_MaxSpeed_LH);
       Menu_Complete = false;
       while (Menu_Complete == false) {
             Read_Membrane_Keys();
             delay(100);
             //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
             Serial.println(F("Settings Saved"));
             Menu_Complete = true;
             lcd.clear();
             lcd.setCursor(0,0);
             lcd.print(F("PWM_L:"));
             lcd.print(PWM_MaxSpeed_LH);
             lcd.setCursor(0,1);
             lcd.print(F("SAVED"));
             delay(2000);
             lcd.clear();          
             EEPROM.write(13, 1);
             EEPROM.write(14, PWM_MaxSpeed_LH);
  
             Menu_Mode_Selection = 0;
             }
             if (!Plus_Key_X) {
               PWM_MaxSpeed_LH = PWM_MaxSpeed_LH + 1;
               if (PWM_MaxSpeed_LH > 255) PWM_MaxSpeed_LH = 255;
               lcd.setCursor(0,1);
               lcd.print(F("      "));    // Fully clear the number to stop reminants of a previous number from being left behind
               lcd.setCursor(0,1);
               lcd.print(PWM_MaxSpeed_LH);
               Serial.print(F("PWM_L:"));
               Serial.println(PWM_MaxSpeed_LH);
               }
             if (!Minus_Key_X) {
               PWM_MaxSpeed_LH = PWM_MaxSpeed_LH - 1;
               if (PWM_MaxSpeed_LH < 0) PWM_MaxSpeed_LH = 0;
               lcd.setCursor(0,1);
               lcd.print(F("      "));   // Fully clear the number to stop reminants of a previous number from being left behind
               lcd.setCursor(0,1);
               lcd.print(PWM_MaxSpeed_LH);
               Serial.print(F("PWM_L:"));
               Serial.println(PWM_MaxSpeed_LH);
               }
             
             }
     }
     
 
     
     if (Menu_Mode_Selection == 5) {
       // Wheel RH PWM Settings
       Menu_Mode_Selection = 0;
       lcd.clear();
       delay(100);
       lcd.setCursor(0,0);
       lcd.print(F("Wheel Speed RH:"));
       lcd.setCursor(0,1);
       lcd.print(PWM_MaxSpeed_RH);
       Serial.print(F("PWM_R:"));
       Serial.println(PWM_MaxSpeed_RH);
       Menu_Complete = false;
       while (Menu_Complete == false) {
             Read_Membrane_Keys();
             delay(100);
             //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
             Serial.println(F("Settings Saved"));
             Menu_Complete = true;
             lcd.clear();
             lcd.setCursor(0,0);
             lcd.print(F("PWM_R:"));
             lcd.print(PWM_MaxSpeed_RH);
             lcd.setCursor(0,1);
             lcd.print(F("SAVED"));
             delay(2000);
             lcd.clear();       
             EEPROM.write(15, 1);
             EEPROM.write(16, PWM_MaxSpeed_RH);   
             Menu_Mode_Selection = 0;
             }
             if (!Plus_Key_X) {
               PWM_MaxSpeed_RH = PWM_MaxSpeed_RH + 1;
               if (PWM_MaxSpeed_RH > 255) PWM_MaxSpeed_RH = 255;
               lcd.setCursor(0,1);
               lcd.print(F("      "));    // Fully clear the number to stop reminants of a previous number from being left behind
               lcd.setCursor(0,1);
               lcd.print(PWM_MaxSpeed_RH);
               Serial.print(F("PWM_R:"));
               Serial.println(PWM_MaxSpeed_RH);
               }
             if (!Minus_Key_X) {
               PWM_MaxSpeed_RH = PWM_MaxSpeed_RH - 1;
               if (PWM_MaxSpeed_RH < 0) PWM_MaxSpeed_RH = 0;
               lcd.setCursor(0,1);
               lcd.print(F("      "));   // Fully clear the number to stop reminants of a previous number from being left behind
               lcd.setCursor(0,1);
               lcd.print(PWM_MaxSpeed_RH);
               Serial.print(F("PWM_R:"));
               Serial.println(PWM_MaxSpeed_RH);
               }
             
             }
     }

     if (Menu_Mode_Selection == 6) {
       // Blade PWM Settings
       Menu_Mode_Selection = 0;
       lcd.clear();
       delay(500);
       lcd.setCursor(0,0);
       lcd.print(F("Blade Speed:"));
       lcd.setCursor(0,1);
       lcd.print(PWM_Blade_Speed);
       Serial.print(F("Blade PWM:"));
       Serial.println(PWM_Blade_Speed);
       Menu_Complete = false;
       while (Menu_Complete == false) {
             Read_Membrane_Keys();
             delay(100);
             //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
             Serial.println(F("Settings Saved"));
             Menu_Complete = true;
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
        
   

          
 
      if (Menu_Mode_Selection == 7) {
       // Compass setup
       lcd.clear();
       lcd.print(F("Compass Setup"));
       delay(1000);
       lcd.clear();
       Menu_Mode_Selection = 0;
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print(F("Compass ON/OFF"));
       lcd.setCursor(0,1);
       lcd.print(F("Status : "));
       if (Compass_Activate == 1) lcd.print(F("ON "));
       if (Compass_Activate == 0) lcd.print(F("OFF"));
       
       Menu_Complete = false;
       while (Menu_Complete == false) {
          Read_Membrane_Keys();
          delay(100);
          //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
               Serial.println(F("Compass Settings Saved"));
               Menu_Complete = true;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print(F("Compass Saved"));
               Serial.print(F("Compass:"));
               Serial.println(Compass_Activate);
               delay(2000);
               lcd.clear();          
               EEPROM.write(19 , 1);
               EEPROM.write(20 , Compass_Activate);
               if (Compass_Activate == 1) Setup_Compass();
               Menu_Mode_Selection = 0;
               
               }
             if (!Plus_Key_X) {
               lcd.setCursor(0,1);
               lcd.print(F("Status : "));
               Compass_Activate = 1;
               lcd.print(F("ON "));
               Serial.print(F("Compass:"));
               Serial.println(Compass_Activate);
               delay(100);
               }
             if (!Minus_Key_X) {
               lcd.setCursor(0,1);
               lcd.print(F("Status : "));
               Compass_Activate = 0;
               lcd.print(F("OFF"));
               Serial.print(F("Compass:"));
               Serial.println(Compass_Activate);
               delay(100);
               }
     }
     }




     if (Menu_Mode_Selection == 8) {
       // Compass Home Degrees
       Menu_Mode_Selection = 0;
       lcd.clear();
       delay(500);
       lcd.setCursor(0,0);
       lcd.print(F("Compass Home Degrees:"));
       lcd.setCursor(0,1);
       lcd.print(Home_Wire_Compass_Heading);
       Serial.print(F("Compass Home Degrees:"));
       Serial.println(Home_Wire_Compass_Heading);
       Menu_Complete = false;
       while (Menu_Complete == false) {
             Read_Membrane_Keys();
             delay(100);
             //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
             Serial.println(F("Settings Saved"));
             Menu_Complete = true;
             lcd.clear();
             lcd.setCursor(0,0);
             lcd.print(F("Compass Home Degrees:"));
             lcd.print(Home_Wire_Compass_Heading);
             lcd.setCursor(0,1);
             lcd.print(F("SAVED"));
             delay(2000);
             lcd.clear();          
             EEPROM.write(27, 1);
             EEPROM.write(28, (Home_Wire_Compass_Heading/10));   
             Menu_Mode_Selection = 0;
             }
             if (!Plus_Key_X) {
               Home_Wire_Compass_Heading = Home_Wire_Compass_Heading + 10;
               if (Home_Wire_Compass_Heading > 360) Home_Wire_Compass_Heading = 0;
               lcd.setCursor(0,1);
               lcd.print("      ");    // Fully clear the number to stop reminants of a previous number from being left behind
               lcd.setCursor(0,1);
               lcd.print(Home_Wire_Compass_Heading);
               Serial.print(F("Compass Home Degrees:"));
               Serial.println(Home_Wire_Compass_Heading);
               }
             if (!Minus_Key_X) {
               Home_Wire_Compass_Heading = Home_Wire_Compass_Heading - 10;
               if (Home_Wire_Compass_Heading < 0) Home_Wire_Compass_Heading = 360;
               lcd.setCursor(0,1);
               lcd.print("      ");   // Fully clear the number to stop reminants of a previous number from being left behind
               lcd.setCursor(0,1);
               lcd.print(Home_Wire_Compass_Heading);
               Serial.print(F("Compass Home Degrees : "));
               Serial.println(Home_Wire_Compass_Heading);
               }
             
             }
     }


     if (Menu_Mode_Selection == 12) {
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
       Menu_Complete = false;
       while (Menu_Complete == false) {
             Read_Membrane_Keys();
             delay(100);
             //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
             Serial.println(F("Settings Saved"));
             Menu_Complete = true;
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
        


// Set Mower CLock
      
if (Menu_Mode_Selection == 9) {
       // Set Mower Clock
       Menu_Mode_Selection = 0;
       lcd.clear();
       lcd.setCursor(0,0);            // Spaces to the right & down
       Time t = rtc.time();
       int set_hour = t.hr;
       int set_min = t.min;      
       lcd.print(F("Time : "));
       lcd.print(set_hour);
       lcd.print(F(":"));
       if (set_min < 10) lcd.print ("0");
       lcd.print(set_min);
       Serial.print(F("Time : "));
       Serial.print(set_hour);
       Serial.print(F(":"));
       if (set_min < 10) Serial.print ("0");
       Serial.println(set_min);

       Menu_Complete = false;
       delay(500);
       while (Menu_Complete == false) {
             Read_Membrane_Keys();
             delay(100);
             //Enter Code Here to Cycle until stop key is pressed.
               if(!Start_Key_X){
               Serial.println(F("Settings Saved"));
               Menu_Complete = true;
               lcd.clear();
               lcd.print(F("Time : "));
               lcd.print(set_hour);
               lcd.print(":");
               if (set_min < 10) lcd.print ("0");
               lcd.print(set_min);
               lcd.setCursor(0,1);
               rtc.writeProtect(false);
               rtc.halt(false);
               Serial.print(F("Clock : "));
               Serial.print(set_hour);
               Serial.print(":");
               if (set_min < 10) Serial.print("0");
               Serial.println(set_min);
               Time t(2019, 07, 19, set_hour, set_min, 00, Time::kFriday);            // Year XXXX, Month XX, Day XX, Hour XX, Minute XX, Second, kXYZday
               rtc.time(t);    
               delay(200);
               rtc.writeProtect(true);
               rtc.halt(true);
               rtc.time(t); 
               lcd.print(F("TIME SAVED"));
               delay(2000);
               lcd.clear();          
               Menu_Mode_Selection = 0;
               }
             if (!Plus_Key_X) {
               set_min = set_min + 1;
               if (set_min > 59) {
                set_min = 0;
                set_hour = set_hour + 1;
                }
               if (set_hour > 23) set_hour = 0;
               lcd.clear();
               lcd.print(F("Time : "));
               lcd.print(set_hour);
               lcd.print(":");
               if (set_min < 10) lcd.print ("0");
               lcd.print(set_min);
               }
             if (!Minus_Key_X) {
               set_min = set_min - 1;
               if (set_min < 0) {
                set_min = 59;
                set_hour = set_hour - 1;
                }
               if (set_hour < 0) set_hour = 23;
               lcd.clear();
               lcd.print(F("Time : "));
               lcd.print(set_hour);
               lcd.print(":");
               if (set_min < 10) lcd.print ("0");
               lcd.print(set_min);
                }
             if(!Stop_Key_X){
               Serial.println(F("Time Set Cancelled"));
               Menu_Complete = true;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print(F("Time Set"));
               lcd.setCursor(0,1);
               lcd.print(F("Cancelled"));    
               delay(2000);
               lcd.clear();          
               Menu_Mode_Selection = 0;
               }
             }
       Serial.print(F("Time : "));
       delay(1000);
       }
     




     
      if (Menu_Mode_Selection == 10) {
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
       
       Menu_Complete = false;
       while (Menu_Complete == false) {
          Read_Membrane_Keys();
          delay(100);
          //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
               Serial.println(F("Compass Settings Saved"));
               Menu_Complete = true;
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


     if (Menu_Mode_Selection == 11) {
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
       Menu_Complete = false;
       while (Menu_Complete == false) {
             Read_Membrane_Keys();
             delay(100);
             //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
             Serial.println(F("Settings Saved"));
             Menu_Complete = true;
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

       if (Menu_Mode_Selection == 13) {
       // Tip Safety ** Experimental**
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print(F("Tip Safety"));
       lcd.setCursor(0,1);
       lcd.print(F("Mode"));
       delay(1000);
       lcd.clear();
       Menu_Mode_Selection = 0;
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print(F("Tip ON/OFF"));
       lcd.setCursor(0,1);
       lcd.print("Status : ");
       if (Tip_Safety == 1) lcd.print(F("ON "));
       if (Tip_Safety == 0) lcd.print(F("OFF"));
       
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
               lcd.print("Tip Set Saved");
               Serial.print(F("Tip Safety:"));
               Serial.println(Tip_Safety);
               delay(2000);
               lcd.clear();          
               EEPROM.write(29 , 1);
               EEPROM.write(30 , Tip_Safety);
               Menu_Mode_Selection = 0;
               
               }
             if (!Plus_Key_X) {
               lcd.setCursor(0,1);
               lcd.print("Status : ");
               Tip_Safety = 1;
               lcd.print("ON ");
               Serial.print(F("Tip Safety:"));
               Serial.println(Tip_Safety);
               delay(100);
               }
             if (!Minus_Key_X) {
               lcd.setCursor(0,1);
               lcd.print("Status : ");
               Tip_Safety = 0;
               lcd.print("OFF");
               Serial.print(F("Tip Safety:"));
               Serial.println(Tip_Safety);
               delay(100);
               }
     }
     }




// Menu Option to CLEAR EEPROM
//-----------------------------
     
      if (Menu_Mode_Selection == 18) {
       // EEPORM Clear MENU
       lcd.clear();
       lcd.print("EEPROM Clear ?");
       lcd.setCursor(0,1);
       lcd.print("Yes/No");
       Serial.println(F("Clear EEPROM Yes/No   - Press Up for Yes and Down for No.  Start to Confirm"));
       Menu_Mode_Selection = 0;
       Menu_Complete = false;
       int Answer = 0;
       while (Menu_Complete == false) {
          //Enter Code Here to Cycle until stop key is pressed.
          Read_Membrane_Keys();
          delay(100);
           if(!Start_Key_X){
             Serial.println(F("Stop key is pressed"));
             Menu_Complete = true;
             lcd.clear();
             lcd.setCursor(0,0);
             if (Answer == 1) {
              Clear_EERPOM();
              lcd.clear();
              lcd.print("EEPROM Cleared");
              lcd.setCursor(0,1);
              lcd.print("Power OFF Mower");
              }
             if (Answer == 0) {
              lcd.clear();
              lcd.print("Cancelled");
              lcd.setCursor(0,1);
              }
             delay(2000);
             lcd.clear();          
             Menu_Mode_Selection = 0;
             }
            if (!Plus_Key_X) {
               Answer = 1;
               lcd.setCursor(0,1);
               lcd.print("Yes    ");
               Serial.println(F("Clear EEPROM = YES....  Press Start to Confirm"));
               delay(100);
               }
             if (!Minus_Key_X) {
               Answer = 0;
               lcd.setCursor(0,1);
               lcd.print("No     ");               
               Serial.println(F("Clear EEPROM = No....Press Start to Confirm"));
               delay(100);
               }
       }
     }
  Print_Membrane_Switch_Input_Settings();
  }
