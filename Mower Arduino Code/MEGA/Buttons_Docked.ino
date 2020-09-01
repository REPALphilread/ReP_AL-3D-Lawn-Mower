// Reads each of the membrane keys and detects if a key is pressed.
void Read_Membrane_Keys(){
  Start_Key_X   = digitalRead(Start_Key);    
  Plus_Key_X    = digitalRead(Plus_Key);   
  Minus_Key_X   = digitalRead(Minus_Key);
  Stop_Key_X    = digitalRead(Stop_Key);  
  }


// Test to displyed on the LCD screen when using the membrane key menus
void Print_LCD_Menu_Docked(byte LCD_Menu_Docked) {
  if (LCD_Menu_Docked == 1) lcd.print("Exit Dock Z-1");
  if (LCD_Menu_Docked == 2) lcd.print("Exit Dock Z-2");
  if (LCD_Menu_Docked == 3) lcd.print("Quick Start");
  if (LCD_Menu_Docked == 4) lcd.print("Trampoline Cut");
  if (LCD_Menu_Docked == 5) lcd.print("Mow the Line");
  if (LCD_Menu_Docked == 6) lcd.print("Test Menu");
  if (LCD_Menu_Docked == 7) lcd.print("-- Spare 7 --");
  if (LCD_Menu_Docked == 8) lcd.print("-- Spare 8 --");
  if (LCD_Menu_Docked == 9) lcd.print("-- Spare 9 --");
  if (LCD_Menu_Docked == 10) lcd.print("-- Spare 10 --");
  if (LCD_Menu_Docked == 11) lcd.print("-- Spare 11 --");
  if (LCD_Menu_Docked == 12) lcd.print("-- Spare 12 --");
  }


void Check_Membrane_Switch_Input_Docked() {
  //Menu Options if the Mower is Docked
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
        Serial.println(F("Docked Menu Activated"));
        delay(500);
        lcd.clear();
        delay(5);
 

      while (Menu_Complete == false) {                      // holds the program in a loop until a selection has been made in the membrane button menu
        if (Menu_View == 0) {
          lcd.setCursor(2,0);
          Print_LCD_Menu_Docked(1);
          lcd.setCursor(2,1);
          Print_LCD_Menu_Docked(2);
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
          Run_Menu_Order_Docked();
          }
        if(!Minus_Key_X) {
          Menu_View = Menu_View + 1;
          Run_Menu_Order_Docked();
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
    Activate_Menu_Option_Docked();
    }
}
    


// Code to scroll the menu and print the menu options in the LCD
 void Run_Menu_Order_Docked() {
          if (Menu_View == 1) {
             Serial.print(F("- key is pressed "));
             lcd.clear();
             lcd.setCursor(2,0);
             Print_LCD_Menu_Docked(1);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Docked(2);
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
             Print_LCD_Menu_Docked(2);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Docked(3);
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
             Print_LCD_Menu_Docked(3);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Docked(4);
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
             Print_LCD_Menu_Docked(4);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Docked(5);
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
             Print_LCD_Menu_Docked(5);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Docked(6);
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
             Print_LCD_Menu_Docked(6);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Docked(7);
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
             Print_LCD_Menu_Docked(7);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Docked(8);
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
             Print_LCD_Menu_Docked(8);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Docked(9);
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
             Print_LCD_Menu_Docked(9);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Docked(10);
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
             Print_LCD_Menu_Docked(10);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Docked(11);
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
             Print_LCD_Menu_Docked(11);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Docked(12);
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
void Activate_Menu_Option_Docked() {

     if (Menu_Mode_Selection == 1) {
       // Exit the mower from the Garage and go to Zone 1;
       lcd.clear();
       lcd.print("Manuel Start");
       lcd.setCursor(0,1);
       lcd.print("Exit Dock Z1");
       Serial.println(F("Exit to Zone 1 - Free Mow"));
       delay(1000);
       lcd.clear();
       Set_Mower_Time();
       Menu_Mode_Selection = 0;
       delay(1000);
       lcd.clear();
       if (Mow_Time_Set == 1) {
          //Enter here the code to go to zone 1 from dock
          Exit_Zone = 1;
          Track_Wire_Itterations = Track_Wire_Zone_1_Cycles;
          Manouver_Exit_To_Zone_X();
          }
     }
 
     
     if (Menu_Mode_Selection == 2) {
       // Exit the mower from the Garage and go to Zone 2;
       Menu_Mode_Selection = 0;
       lcd.clear();
       lcd.print("Manuel Start");
       lcd.setCursor(0,1);
       lcd.print("Exit Dock Z2");
       delay(1000);
       lcd.clear();
       Set_Mower_Time();
       Menu_Mode_Selection = 0;
       delay(1000);
       lcd.clear();
       if (Mow_Time_Set == 1) {
          Exit_Zone = 2;
          Track_Wire_Itterations = Track_Wire_Zone_2_Cycles;
          Manouver_Exit_To_Zone_X();
          }
     }

     if (Menu_Mode_Selection == 3) {
        // Quick Start the Mower in the middle of the Garden;
        Serial.println("Quick Start Selected");
        Manouver_Start_Mower();
        Set_Mower_Time();
        delay(1000);
        if (Mow_Time_Set == 1) Manouver_Start_Mower();
        lcd.clear();     
        }
        
   
     if (Menu_Mode_Selection == 4) {
        lcd.clear();
        lcd.print("Trampoline Cut!");
        Serial.println(F("Mower Set to Cut under Trampoline"));
        Menu_Mode_Selection = 0;
        delay(3000);
        lcd.clear();
        Special_Cut_Under_Trampoline_Function();
        }
          
      if (Menu_Mode_Selection == 5) {
       lcd.clear();
       lcd.print("Blade will spin");
       lcd.setCursor(0,1);
       lcd.print("Mow the Line");
       delay(1000);
       lcd.clear();
       Set_Mower_Time();
       if (Mow_Time_Set == 1) {
         Serial.println(F("Cutting the grass on the boundary wire"));
         Blade_Override = 1;
         Track_Wire_Itterations = 6000;
         Exit_Zone = 3;    
         Manouver_Exit_To_Zone_X();
         Manouver_Start_Mower();                                  // Sets up the mower to go.
         }
        }

      if (Menu_Mode_Selection == 6) {
        lcd.clear();
        lcd.print("Test Mower Menu");
        Serial.println(F("Test Menu Selected"));
        Menu_Mode_Selection = 0;
        delay(1000);
        lcd.clear();
        Print_Membrane_Switch_Input_Tests();
        }
  
  }
