// BUTTONS PARKED MENU


// Test to displyed on the LCD screen when using the membrane key menus
void Print_LCD_Menu_Parked(byte LCD_Menu_Parked) {
  if (LCD_Menu_Parked == 1)   lcd.print("Mow Grass     ");
  if (LCD_Menu_Parked == 2)   {
    if (Use_Charging_Station == 1)  lcd.print("Go To Dock");
    if (Use_Charging_Station == 0)  lcd.print("Dock Removed");
    }
  if (LCD_Menu_Parked == 3)   lcd.print(F("Trampoline Cut"));
  if (LCD_Menu_Parked == 4)   lcd.print(F("Test Menu"));
  if (LCD_Menu_Parked == 5)   lcd.print(F("Setup Mower"));
  if (LCD_Menu_Parked == 6)   lcd.print(F("-- SPARE 6 ---"));
  if (LCD_Menu_Parked == 7)   lcd.print(F("-- SPARE 7 ---"));
  if (LCD_Menu_Parked == 8)   lcd.print(F("-- SPARE 8 ---"));
  if (LCD_Menu_Parked == 9)   lcd.print(F("-- SPARE 9 ---"));
  if (LCD_Menu_Parked == 10)   lcd.print(F("-- SPARE 10 ---"));
  if (LCD_Menu_Parked == 11)   lcd.print(F("-- SPARE 11 ---"));
  if (LCD_Menu_Parked == 12)   lcd.print("");    // Leave Blank
  }
  

 void Check_Membrane_Switch_Input_Parked() {

  //Menu Options if the Mower is Parked.
     Read_Membrane_Keys();
     Menu_Complete = 1;
     Menu_Mode_Selection = 0;
     Menu_View = 0;

     if(!Start_Key_X)  {                                    // If the start key is pressed
        Serial.println();
        Serial.println(F("Start Key Pressed"));
        Menu_Complete = false;                                // Menu complete will return to the normal loop
        lcd.clear();
        delay(5);
        Serial.println();
        Serial.println(F("Parked Menu Activated"));
        delay(500);

 

      while (Menu_Complete == false) {                      // holds the program in a loop until a selection has been made in the membrane button menu
        if (Menu_View == 0) {
          lcd.setCursor(2,0);
          Print_LCD_Menu_Parked(1);
          lcd.setCursor(2,1);
          Print_LCD_Menu_Parked(2);
          }
        // Gets the values again from the keys
        Read_Membrane_Keys();
        delay(100);
             
        if(!Start_Key_X){
          Menu_Complete = true;
          Serial.println(F("Start key is pressed"));
          lcd.clear();
          }
        if(!Plus_Key_X) {
          Serial.println(F("+ key is pressed"));
          Menu_View = Menu_View - 1;
          Run_Menu_Order_Parked();
          }
        if(!Minus_Key_X) {
          Menu_View = Menu_View + 1;
          Run_Menu_Order_Parked();
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
    Activate_Menu_Option_Parked();
    }
 }

 void Run_Menu_Order_Parked() {
          if (Menu_View == 1) {
             Serial.print(F("- key is pressed "));
             lcd.clear();
             lcd.setCursor(2,0);
             Print_LCD_Menu_Parked(1);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Parked(2);
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
             Print_LCD_Menu_Parked(2);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Parked(3);
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
             Print_LCD_Menu_Parked(3);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Parked(4);
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
             Print_LCD_Menu_Parked(4);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Parked(5);
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
             Print_LCD_Menu_Parked(5);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Parked(6);
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
             Print_LCD_Menu_Parked(6);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Parked(7);
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
             Print_LCD_Menu_Parked(7);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Parked(8);
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
             Print_LCD_Menu_Parked(8);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Parked(9);
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
             Print_LCD_Menu_Parked(9);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Parked(10);
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
             Print_LCD_Menu_Parked(10);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Parked(11);
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
             Print_LCD_Menu_Parked(11);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Parked(12);
             lcd.setCursor(0,0);
             lcd.print(">");
             Menu_Mode_Selection = 10;
             Serial.print(F("Menu View : "));
             Serial.print(Menu_View);
             Serial.print(F("| Menu Selection"));
             Serial.println(Menu_Mode_Selection);
             delay(100);
             }
        
        
      delay(100);
      }



// Defines the actions when that option is selected with the keypad.
void Activate_Menu_Option_Parked() {
     
     if (Menu_Mode_Selection == 1) {
      Menu_Mode_Selection = 0;
      lcd.clear();
      Print_Membrane_Switch_Input_Timing();
      lcd.clear();
      lcd.print(F("Mow Re-Starting"));
      Serial.println(F("Mower Starting"));
      delay(2000);
      Manouver_Start_Mower();                                             // Restarts the mower again from standing position
      lcd.clear();     
     }

     if (Menu_Mode_Selection == 2) {
      if (Use_Charging_Station == 1) {
          lcd.clear();
          lcd.print(F("Returning Home"));
          Serial.println(F("Sending Mower Home"));
          delay(100);
          Menu_Mode_Selection = 0;                                      // Releases the loop in the membrane button section.
          delay(1000);
          lcd.clear();
          Manouver_Go_To_Charging_Station();        
          }
      if (Use_Charging_Station == 0) {
          lcd.clear();
          lcd.print(F("No Dock Active"));
          Serial.println(F("Activate Docking Station in Settings"));
          delay(100);
          Menu_Mode_Selection = 0;                                      // Releases the loop in the membrane button section.
          delay(1000);
          lcd.clear();
          }

     }
      
      if (Menu_Mode_Selection == 3) {
        lcd.clear();
        lcd.print("Trampoline Cut!");
        Serial.println(F("Mower Set to Cut under Trampoline"));
        Menu_Mode_Selection = 0;
        delay(3000);
        lcd.clear();
        Special_Cut_Under_Trampoline_Function();
        }

      if (Menu_Mode_Selection == 4) {
        lcd.clear();
        lcd.print("Test Mower Menu");
        Serial.println(F("Test Menu Selected"));
        Menu_Mode_Selection = 0;
        delay(3000);
        lcd.clear();
        Print_Membrane_Switch_Input_Tests();
        }

      if (Menu_Mode_Selection == 5) {
        lcd.clear();
        lcd.print("Setup Mower");
        Serial.println(F("Mower Setup Selected"));
        Menu_Mode_Selection = 0;
        delay(3000);
        lcd.clear();
        Print_Membrane_Switch_Input_Settings();
        }

      if (Menu_Mode_Selection == 6) {
        lcd.clear();
        lcd.print("Slot 6 - Empty");
        Serial.println(F("Slot 6 Selected"));
        Menu_Mode_Selection = 0;
        delay(3000);
        lcd.clear();
        // Insert Function Here();
        }
  }


void Check_Membrane_Keys_Running() {

     Read_Membrane_Keys();
     if(!Stop_Key_X){
        Manouver_Park_The_Mower();
        Check_Membrane_Switch_Input_Parked();   
        Menu_Mode_Selection = 0;
        }
}
     
  
