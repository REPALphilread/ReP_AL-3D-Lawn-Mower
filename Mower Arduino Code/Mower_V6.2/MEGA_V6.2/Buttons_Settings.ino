// BUTTONS SETTINGS MENU


// Test to displyed on the LCD screen when using the membrane key menus
void Print_LCD_Menu_Settings(byte LCD_Menu_Settings) {
  if (LCD_Menu_Settings == 1) lcd.print("Wheel PWM_L");
  if (LCD_Menu_Settings == 2) lcd.print("Wheel PWM_R");
  if (LCD_Menu_Settings == 3) lcd.print("Blade PWM");
  if (LCD_Menu_Settings == 4) lcd.print("-----");
  if (LCD_Menu_Settings == 5) lcd.print("-----");
  if (LCD_Menu_Settings == 6) lcd.print("-----");
  if (LCD_Menu_Settings == 7) lcd.print("-----");
  if (LCD_Menu_Settings == 8) lcd.print("-----");
  if (LCD_Menu_Settings == 9) lcd.print("-----");
  if (LCD_Menu_Settings == 10) lcd.print("-----");
  if (LCD_Menu_Settings == 11) lcd.print("-----");  
  if (LCD_Menu_Settings == 12) lcd.print("");   // Leave Blank
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
    Activate_Menu_Option_Settings();
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
             Menu_Mode_Selection = 10;
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
       // Wheel PWM Settings
       Menu_Mode_Selection = 0;
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("Wheel PWM_L:");
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
             lcd.print("PWM_L:");
             lcd.print(PWM_MaxSpeed_LH);
             lcd.setCursor(0,1);
             lcd.print("SAVED");
             delay(2000);
             lcd.clear();          
             Menu_Mode_Selection = 0;
             }
             if (!Plus_Key_X) {
               PWM_MaxSpeed_LH = PWM_MaxSpeed_LH + 1;
               lcd.setCursor(0,1);
               lcd.print("      ");    // Fully clear the number to stop reminants of a previous number from being left behind
               lcd.setCursor(0,1);
               lcd.print(PWM_MaxSpeed_LH);
               Serial.print(F("PWM_L:"));
               Serial.println(PWM_MaxSpeed_LH);
               }
             if (!Minus_Key_X) {
               PWM_MaxSpeed_LH = PWM_MaxSpeed_LH - 1;
               lcd.setCursor(0,1);
               lcd.print("      ");   // Fully clear the number to stop reminants of a previous number from being left behind
               lcd.setCursor(0,1);
               lcd.print(PWM_MaxSpeed_LH);
               Serial.print(F("PWM_L:"));
               Serial.println(PWM_MaxSpeed_LH);
               }
             
             }
     }
     
 
     
     if (Menu_Mode_Selection == 2) {
       // Wheel RH PWM Settings
       Menu_Mode_Selection = 0;
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("Wheel PWM_R:");
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
             lcd.print("PWM_R:");
             lcd.print(PWM_MaxSpeed_RH);
             lcd.setCursor(0,1);
             lcd.print("SAVED");
             delay(2000);
             lcd.clear();          
             Menu_Mode_Selection = 0;
             }
             if (!Plus_Key_X) {
               PWM_MaxSpeed_RH = PWM_MaxSpeed_RH + 1;
               lcd.setCursor(0,1);
               lcd.print("      ");    // Fully clear the number to stop reminants of a previous number from being left behind
               lcd.setCursor(0,1);
               lcd.print(PWM_MaxSpeed_RH);
               Serial.print(F("PWM_R:"));
               Serial.println(PWM_MaxSpeed_RH);
               }
             if (!Minus_Key_X) {
               PWM_MaxSpeed_RH = PWM_MaxSpeed_RH - 1;
               lcd.setCursor(0,1);
               lcd.print("      ");   // Fully clear the number to stop reminants of a previous number from being left behind
               lcd.setCursor(0,1);
               lcd.print(PWM_MaxSpeed_RH);
               Serial.print(F("PWM_R:"));
               Serial.println(PWM_MaxSpeed_RH);
               }
             
             }
     }

     if (Menu_Mode_Selection == 3) {
       // Blade PWM Settings
       Menu_Mode_Selection = 0;
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("Blade PWM:");
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
             lcd.print("Blade PWM:");
             lcd.print(PWM_Blade_Speed);
             lcd.setCursor(0,1);
             lcd.print("SAVED");
             delay(2000);
             lcd.clear();          
             Menu_Mode_Selection = 0;
             }
             if (!Plus_Key_X) {
               PWM_Blade_Speed = PWM_Blade_Speed + 1;
               lcd.setCursor(0,1);
               lcd.print("      ");    // Fully clear the number to stop reminants of a previous number from being left behind
               lcd.setCursor(0,1);
               lcd.print(PWM_Blade_Speed);
               Serial.print(F("Blade PWM:"));
               Serial.println(PWM_Blade_Speed);
               }
             if (!Minus_Key_X) {
               PWM_Blade_Speed = PWM_Blade_Speed - 1;
               lcd.setCursor(0,1);
               lcd.print("      ");   // Fully clear the number to stop reminants of a previous number from being left behind
               lcd.setCursor(0,1);
               lcd.print(PWM_Blade_Speed);
               Serial.print(F("Blade PWM:"));
               Serial.println(PWM_Blade_Speed);
               }
             
             }
     }
        
   
     if (Menu_Mode_Selection == 4) {
       // Enter Settings Here
       lcd.clear();
       lcd.print("..........");
       lcd.setCursor(0,1);
       lcd.print("Activated");
       Serial.println(F("...................."));
       delay(5000);
       lcd.clear();
       Menu_Mode_Selection = 0;
       lcd.clear();
       Menu_Complete = false;
       while (Menu_Complete == false) {
          //Enter Code Here to Cycle until stop key is pressed.
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
          
      if (Menu_Mode_Selection == 5) {
       // Enter Settings Here
       lcd.clear();
       lcd.print("..........");
       lcd.setCursor(0,1);
       lcd.print("Activated");
       Serial.println(F("...................."));
       delay(5000);
       lcd.clear();
       Menu_Mode_Selection = 0;
       lcd.clear();
       Menu_Complete = false;
       while (Menu_Complete == false) {
          //Enter Code Here to Cycle until stop key is pressed.
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
       // Enter Settings Here
       lcd.clear();
       lcd.print("..........");
       lcd.setCursor(0,1);
       lcd.print("Activated");
       Serial.println(F("...................."));
       delay(5000);
       lcd.clear();
       Menu_Mode_Selection = 0;
       lcd.clear();
       Menu_Complete = false;
       while (Menu_Complete == false) {
          //Enter Code Here to Cycle until stop key is pressed.
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


      if (Menu_Mode_Selection == 7) {
       // Enter Settings Here
       lcd.clear();
       lcd.print("..........");
       lcd.setCursor(0,1);
       lcd.print("Activated");
       Serial.println(F("...................."));
       delay(5000);
       lcd.clear();
       Menu_Mode_Selection = 0;
       lcd.clear();
       Menu_Complete = false;
       while (Menu_Complete == false) {
          //Enter Code Here to Cycle until stop key is pressed.
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
      if (Menu_Mode_Selection == 8) {
       // Enter Settings Here
       lcd.clear();
       lcd.print("..........");
       lcd.setCursor(0,1);
       lcd.print("Activated");
       Serial.println(F("...................."));
       delay(5000);
       lcd.clear();
       Menu_Mode_Selection = 0;
       lcd.clear();
       Menu_Complete = false;
       while (Menu_Complete == false) {
          //Enter Code Here to Cycle until stop key is pressed.
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
        
      if (Menu_Mode_Selection == 9) {
       // Enter Settings Here
       lcd.clear();
       lcd.print("..........");
       lcd.setCursor(0,1);
       lcd.print("Activated");
       Serial.println(F("...................."));
       delay(5000);
       lcd.clear();
       Menu_Mode_Selection = 0;
       lcd.clear();
       Menu_Complete = false;
       while (Menu_Complete == false) {
          //Enter Code Here to Cycle until stop key is pressed.
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
      if (Menu_Mode_Selection == 10) {
       // Enter Settings Here
       lcd.clear();
       lcd.print("..........");
       lcd.setCursor(0,1);
       lcd.print("Activated");
       Serial.println(F("...................."));
       delay(5000);
       lcd.clear();
       Menu_Mode_Selection = 0;
       lcd.clear();
       Menu_Complete = false;
       while (Menu_Complete == false) {
          //Enter Code Here to Cycle until stop key is pressed.
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
  
  }
