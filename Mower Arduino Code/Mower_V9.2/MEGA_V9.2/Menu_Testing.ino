// BUTTONS TEST MENU


#if defined(LCD_KEYPAD)

// Test to displyed on the LCD screen when using the membrane key menus
void Print_LCD_Menu_Tests(byte LCD_Menu_Tests) {
  if (LCD_Menu_Tests == 1)  lcd.print(F("Wire Test"));
  if (LCD_Menu_Tests == 2)  lcd.print(F("Relay Test"));
  if (LCD_Menu_Tests == 3)  lcd.print(F("Wheel Test"));
  if (LCD_Menu_Tests == 4)  lcd.print(F("Blade Test"));
  if (LCD_Menu_Tests == 5)  lcd.print(F("Sonar Test"));
  if (LCD_Menu_Tests == 6)  lcd.print(F("Turn Test"));
  if (LCD_Menu_Tests == 7)  lcd.print(F("Volt Amp Test"));
  if (LCD_Menu_Tests == 8)  lcd.print(F("Compass Test"));
  if (LCD_Menu_Tests == 9)  lcd.print(F("Go Home Test"));
  if (LCD_Menu_Tests == 10) lcd.print(F("Bumper Test"));
  if (LCD_Menu_Tests == 11) lcd.print(F("Spare 11"));  
  if (LCD_Menu_Tests == 12) lcd.print(F("Spare 12"));  
  if (LCD_Menu_Tests == 13) lcd.print(F("Spare 13"));  
  if (LCD_Menu_Tests == 14) lcd.print(F("BETA"));  
  if (LCD_Menu_Tests == 15) lcd.print(F("Spare 15")); 
  if (LCD_Menu_Tests == 16) lcd.print(F(""));   // Leave Blank
  Max_Options_Test = 16;
  }


void Print_Membrane_Switch_Input_Tests() {

  //Menu Options if the Mower is Tests.
     Read_Membrane_Keys();
     Menu_Complete = 1;
     Menu_Mode_Selection = 0;
     Menu_View = 0;

    
      Serial.println();
      Serial.println(F("Test Menu Activated"));
      Menu_Complete = false;                                // Menu complete will return to the normal loop
      lcd.clear();
      delay(5);
 

      while (Menu_Complete == false) {                      // holds the program in a loop until a selection has been made in the membrane button menu
        if (Menu_View == 0) {
          lcd.setCursor(1,0);
          Print_LCD_Menu_Tests(1);
          lcd.setCursor(1,1);
          Print_LCD_Menu_Tests(2);
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
          Run_Menu_Order_Testing();
          }
        if(!Minus_Key_X) {
          Menu_View = Menu_View + 1;
          Run_Menu_Order_Testing();
        }
        if(!Stop_Key_X){
          Serial.println(F("Stop key is pressed"));
          Menu_Complete = true;
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print(F("Exit Test"));
          lcd.setCursor(0,1);
          lcd.print(F("Menu"));
          delay(1000);
          lcd.clear();          
          Menu_Mode_Selection = 0;
          }
      }
    Activate_Menu_Option_Testing();
    }


 void Run_Menu_Order_Testing() {
     if (Menu_View > Max_Options_Test) Menu_View = Menu_View -1;
     if (Menu_View < 0) Menu_View = Menu_View + 1;
     Serial.print(F("- key is pressed "));
     lcd.clear();
     lcd.setCursor(1,0);
     Print_LCD_Menu_Tests(Menu_View);
     lcd.setCursor(1,1);
     Print_LCD_Menu_Tests( Menu_View + 1);
     lcd.setCursor(0,0);
     lcd.print(F(">"));
     Menu_Mode_Selection = Menu_View;
     Serial.print(F("Menu View : "));
     Serial.print(Menu_View);
     Serial.print(F("| Menu Selection"));
     Serial.println(Menu_Mode_Selection);
     delay(100);
     }


void Activate_Menu_Option_Testing() {
     
     if (Menu_Mode_Selection == 1) {
       // Perimeter Wire Test
       lcd.clear();
       lcd.print(F("Wire Test"));
       lcd.setCursor(0,1);
       lcd.print(F("Activated"));
       Serial.println(F("Perimeter Wire Test Started"));
       delay(5000);
       lcd.clear();
       Menu_Mode_Selection = 0;
       lcd.clear();
       Menu_Complete = false;
       while (Menu_Complete == false) {
          Test_Mower_Check_Wire();
          Read_Membrane_Keys();
             if(!Stop_Key_X){
             Serial.println(F("Stop key is pressed"));
             Menu_Complete = true;
             lcd.clear();
             lcd.setCursor(0,0);
             lcd.print(F("Test Stopped"));
             delay(2000);
             lcd.clear();          
             Menu_Mode_Selection = 0;
             }
     }
     }
 
     
     if (Menu_Mode_Selection == 2) {
       // Relay Test
       Menu_Mode_Selection = 0;
       lcd.clear();
       lcd.print(F("Relay Test"));
       lcd.setCursor(0,1);
       lcd.print(F("Activated"));
       delay(1000);
       lcd.clear();
       Menu_Mode_Selection = 0;
       lcd.clear();
       Menu_Complete = false;
       while (Menu_Complete == false) {
          Test_Relay();
          Read_Membrane_Keys();
             if(!Stop_Key_X){
             Serial.println(F("Stop key is pressed"));
             Menu_Complete = true;
             lcd.clear();
             lcd.setCursor(0,0);
             lcd.print(F("Test Stopped"));
             delay(2000);
             lcd.clear();          
             Menu_Mode_Selection = 0;
             }
     }
    }

     if (Menu_Mode_Selection == 3) {
       // Mower Motor Test
       Menu_Mode_Selection = 0;
       lcd.clear();
       lcd.print(F("Wheel Motor Test"));
       lcd.setCursor(0,1);
       lcd.print("Activated");
       delay(1000);
       lcd.clear();
       Menu_Mode_Selection = 0;
       lcd.clear();
       I = 1;                       // sets the itteration for the motor test
       Test_Wheel_Motors();         // starts the mowe motor test 1x
       }
        
   
     if (Menu_Mode_Selection == 4) {
       // Blade Motor Test
       Menu_Mode_Selection = 0;
       lcd.clear();
       lcd.print("Blade Motor Test");
       lcd.setCursor(0,1);
       lcd.print("Activated");
       delay(1000);
       lcd.clear();
       Menu_Mode_Selection = 0;
       lcd.clear();
       Test_Mower_Blade_Motor();
        }
          
      if (Menu_Mode_Selection == 5) {
       Menu_Mode_Selection = 0;
       lcd.clear();
       lcd.print("Sonar Test");
       lcd.setCursor(0,1);
       lcd.print("Activated");
       delay(1000);
       lcd.clear();
       Menu_Complete = false;
       while (Menu_Complete == false) {
          Test_Sonar_Array();
          Read_Membrane_Keys();
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

      if (Menu_Mode_Selection == 6) {
        lcd.clear();
        lcd.print("Pattern Mow");
        Serial.println(F("Slot 6 Selected"));
        Menu_Mode_Selection = 0;
        delay(3000);
        lcd.clear();
        Test_Compass_Turn_Function();
        }
      if (Menu_Mode_Selection == 7) {
        lcd.clear();
        lcd.print("Volt Amps Test");
        Serial.println(F("Volts and Amps Test"));
        Menu_Mode_Selection = 0;
        delay(1000);
        lcd.clear();
        Menu_Complete = false;
        while (Menu_Complete == false) {
          Read_Membrane_Keys();
          Read_Serial1_Nano();
          delay(100);
          Serial.print(F("  Charging:"));
          Serial.print(Charging);
          lcd.setCursor(0,0);
          lcd.print(F("Volt:"));
          lcd.print(Volts);
          lcd.setCursor(0,1);
          lcd.print(F("Amps:"));
          lcd.print(Amps);
          lcd.setCursor(13,1);
          lcd.print(F("C:"));
          lcd.print(Charging);
;          Serial.println(F(""));
        
             if(!Stop_Key_X){
             Serial.println(F("Stop key is pressed"));
             Menu_Complete = true;
             lcd.clear();
             lcd.setCursor(0,0);
             lcd.print(F("Test Stopped"));
             delay(2000);
             lcd.clear();          
             Menu_Mode_Selection = 0;
             }
         }   
        }
      if (Menu_Mode_Selection == 8) {
        lcd.clear();
        lcd.print("Compass Test");
        Serial.println(F("Compass Test Selected"));
        Menu_Mode_Selection = 0;
        delay(3000);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Heading:");
        lcd.setCursor(0,1);
        lcd.print("Degrees:");
        Menu_Complete = false;
        while (Menu_Complete == false) {
          // insert Test Code Here
          Read_Membrane_Keys();
          Get_Compass_Reading();
          delay(100);
          Serial.print(F("Heading:"));
          Serial.print(Heading);
          Serial.print(F("|"));
          Serial.println(F(""));
          lcd.setCursor(9,0);
          lcd.print(Heading);
          lcd.setCursor(9,1);
          lcd.print(Compass_Heading_Degrees);
          delay(500);
        
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
        


      // Tests the compass direction finding of the mower when finding the wire.  
      if (Menu_Mode_Selection == 9) {
        lcd.clear();
        lcd.print("Go Home Test");
        Serial.println(F("Test Compass Turn to Home Test and Follow Wire"));
        Menu_Mode_Selection = 0;
        delay(3000);
        lcd.clear();
        Manouver_Go_To_Charging_Station();
        }


      // Tests the bumper bar is functioning correctly.  
      if (Menu_Mode_Selection == 10) {
        lcd.clear();
        lcd.print("Bumper Bar");
        lcd.setCursor(0,1);
        lcd.print("Test");
        Serial.println(F("Test Compass Turn to Home Test and Follow Wire"));
        Menu_Mode_Selection = 0;
        delay(3000);
        lcd.clear();
        Start_Bumper_Bar_Test();
        }


      if (Menu_Mode_Selection == 14) {
        lcd.clear();
        lcd.print("BETA Commands");
        Serial.println(F("BETA Section"));
        Menu_Mode_Selection = 0;
        delay(1000);
        lcd.clear();
        Print_Membrane_Switch_Input_BETA();
        //Menu_Mode_Selection = -1;      // skips the re-writing of the menu
        } 
  
  }


#endif
