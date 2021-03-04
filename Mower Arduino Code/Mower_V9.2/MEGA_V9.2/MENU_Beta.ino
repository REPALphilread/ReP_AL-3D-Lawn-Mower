// BETA SETTINGS MENU


// Test to displyed on the LCD screen when using the membrane key menus
void Print_LCD_Menu_BETA(byte LCD_Menu_BETA) {
  #if defined(LCD_KEYPAD)
  if (LCD_Menu_BETA == 1) lcd.print(F("Tilt Test"));
  if (LCD_Menu_BETA == 2) lcd.print(F("Test"));
  if (LCD_Menu_BETA == 3) lcd.print(F("Test"));          // needs writing
  Max_Options_BETA = 3;
  #endif
  }
  


void Print_Membrane_Switch_Input_BETA() {
     #if defined(LCD_KEYPAD)
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
    #endif
    }

    


// Code to scroll the menu and print the menu options in the LCD
 void Run_Menu_Order_BETA() {
     #if defined(LCD_KEYPAD)
     
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
     #endif
     }

     
// Defines the actions when that option is selected with the keypad.
void Activate_Menu_Option_BETA() {

      #if defined(LCD_KEYPAD)
      if (Menu_Mode_Selection == 3) {
        
        lcd.clear();
        lcd.print("Tilt Test");
        
        Serial.println(F("Tilt Test Selected"));
        Menu_Mode_Selection = 0;
        delay(2000);
        lcd.clear();
        
        //Calibrate_Compass_Angle();
        Menu_Complete = false;
          delay(100);
          while (Menu_Complete == false) {
          // insert Test Code Here
          Read_Membrane_Keys();
          Check_Tilt_Tip_Angle();
          
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

#endif
}
