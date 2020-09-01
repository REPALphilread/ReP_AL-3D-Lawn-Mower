// BETA SETTINGS MENU


// Test to displyed on the LCD screen when using the membrane key menus
void Print_LCD_Menu_BETA(byte LCD_Menu_BETA) {
  if (LCD_Menu_BETA == 1) lcd.print(F("BETA Tip Sensor"));
  if (LCD_Menu_BETA == 2) lcd.print(F("BETA Test Tip"));
  if (LCD_Menu_BETA == 3) lcd.print(F("BETA 3"));          // needs writing
  Max_Options_BETA = 3;
  }


void Print_Membrane_Switch_Input_BETA() {
     Read_Membrane_Keys();
     Menu_Complete = 1;
     Menu_Mode_Selection = 0;
     Menu_View = 0;

      Serial.println();
      Serial.println(F("BETA Menu Activated"));
      Menu_Complete = false;                                // Menu complete will return to the normal loop
      lcd.clear();
      delay(5);
      
      while (Menu_Complete == false) {                      // holds the program in a loop until a selection has been made in the membrane button menu
        if (Menu_View == 0) {
          lcd.setCursor(1,0);
          Print_LCD_Menu_BETA(1);
          lcd.setCursor(1,1);
          Print_LCD_Menu_BETA(2);
          }
        // Gets the values again from the keys
        Read_Membrane_Keys();
        delay(100);
             
        if(!Start_Key_X){
          Menu_Complete = true;
          Serial.println(F("Start key is pressed"));
          Activate_Menu_Option_BETA();
          lcd.clear();
          
          }
        if(!Plus_Key_X) {
          Serial.println(F("+ key is pressed"));
          Menu_View = Menu_View - 1;
          Run_Menu_Order_BETA();
          }
        if(!Minus_Key_X) {
          Menu_View = Menu_View + 1;
          Run_Menu_Order_BETA();
        }
        if(!Stop_Key_X){
          Serial.println(F("Stop key is pressed"));
          Menu_Complete = true;
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Exit BETA");
          delay(1000);
          lcd.clear();          
          Menu_Mode_Selection = 0;
          Print_Membrane_Switch_Input_Settings();
          }
      }
    //Activate_Menu_Option_BETA();
    }

    


// Code to scroll the menu and print the menu options in the LCD
 void Run_Menu_Order_BETA() {
     if (Menu_View > Max_Options_BETA) Menu_View = Menu_View -1;
     if (Menu_View < 0) Menu_View = Menu_View + 1;      
     Serial.print(F("- key is pressed "));
     lcd.clear();
     lcd.setCursor(1,0);
     Print_LCD_Menu_BETA(Menu_View);
     lcd.setCursor(1,1);
     Print_LCD_Menu_BETA( Menu_View + 1);
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
void Activate_Menu_Option_BETA() {

  if (Menu_Mode_Selection == 1) {
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

      if (Menu_Mode_Selection == 2) {
        lcd.clear();
        lcd.print("Tilt Test");
        Serial.println(F("Tilt Test Selected"));
        Menu_Mode_Selection = 0;
        delay(2000);
        lcd.clear();
        Calibrate_Compass_Angle();
        Menu_Complete = false;
          delay(100);
          while (Menu_Complete == false) {
          // insert Test Code Here
          Read_Membrane_Keys();
          Test_Compass_Check_Tip_Angle();
          
             if(!Stop_Key_X){
             Serial.println(F("Stop key is pressed"));
             Menu_Complete = true;
             lcd.clear();
             lcd.setCursor(0,0);
             lcd.print("Test Stopped");
             delay(2000);
             lcd.clear();          
             Menu_Mode_Selection = 0;
             }
         }
      }
     
Print_Membrane_Switch_Input_BETA();
}
