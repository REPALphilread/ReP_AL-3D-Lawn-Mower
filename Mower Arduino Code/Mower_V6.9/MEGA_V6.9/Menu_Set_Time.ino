// BUTTONS ALARMS MENU


// Test to displyed on the LCD screen when using the membrane key menus
void Print_LCD_Menu_Alarms(byte LCD_Menu_Alarms) {
  if (LCD_Menu_Alarms == 1) lcd.print(F("Set Alarm 1"));
  if (LCD_Menu_Alarms == 2) lcd.print(F("Set Alarm 2"));
  if (LCD_Menu_Alarms == 3) lcd.print(F("Set Alarm 3"));
  if (LCD_Menu_Alarms == 4) lcd.print(F("Set Clock")); 
  Max_Options_Alarms = 4;
  }


void Print_Membrane_Switch_Input_Alarms() {
     Read_Membrane_Keys();
     Menu_Complete = 1;
     Menu_Mode_Selection = 0;
     Menu_View = 0;

      Serial.println();
      Serial.println(F("Alarms Menu Activated"));
      Menu_Complete = false;                                // Menu complete will return to the normal loop
      lcd.clear();
      delay(5);
      
      while (Menu_Complete == false) {                      // holds the program in a loop until a selection has been made in the membrane button menu
        if (Menu_View == 0) {
          lcd.setCursor(1,0);
          Print_LCD_Menu_Alarms(1);
          lcd.setCursor(1,1);
          Print_LCD_Menu_Alarms(2);
          }
        // Gets the values again from the keys
        Read_Membrane_Keys();
        delay(100);
             
        if(!Start_Key_X){
          Menu_Complete = true;
          Serial.println(F("Start key is pressed"));
          Activate_Menu_Option_Alarms();
          lcd.clear();
          
          }
        if(!Plus_Key_X) {
          Serial.println(F("+ key is pressed"));
          Menu_View = Menu_View - 1;
          Run_Menu_Order_Alarms();
          }
        if(!Minus_Key_X) {
          Menu_View = Menu_View + 1;
          Run_Menu_Order_Alarms();
        }
        if(!Stop_Key_X){
          Serial.println(F("Stop key is pressed"));
          Menu_Complete = true;
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Exit Alarms");
          delay(1000);
          lcd.clear();          
          Menu_Mode_Selection = 0;
          Print_Membrane_Switch_Input_Settings();
          }
      }
    //Activate_Menu_Option_Alarms();
    }

    


// Code to scroll the menu and print the menu options in the LCD
 void Run_Menu_Order_Alarms() {
     if (Menu_View > Max_Options_Alarms) Menu_View = Menu_View -1;
     if (Menu_View < 0) Menu_View = Menu_View + 1;      
     Serial.print(F("- key is pressed "));
     lcd.clear();
     lcd.setCursor(1,0);
     Print_LCD_Menu_Alarms(Menu_View);
     lcd.setCursor(1,1);
     Print_LCD_Menu_Alarms( Menu_View + 1);
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
void Activate_Menu_Option_Alarms() {

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


// Set Mower CLock
      
if (Menu_Mode_Selection == 4) {
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
     
Print_Membrane_Switch_Input_Alarms();
}
