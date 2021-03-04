// NAVI SETTINGS MENU

#if defined(LCD_KEYPAD)

// Test to displyed on the LCD screen when using the membrane key menus
void Print_LCD_Menu_NAVI(byte LCD_Menu_NAVI) {
  if (LCD_Menu_NAVI == 1) lcd.print(F("Compass ON/OFF"));
  if (LCD_Menu_NAVI == 2) lcd.print(F("Compass Home Dir"));
  if (LCD_Menu_NAVI == 3) lcd.print(F("H-Hold ON/OFF"));         
  if (LCD_Menu_NAVI == 4) lcd.print(F("Compass PID")); 
  if (LCD_Menu_NAVI == 5) lcd.print(F("")); 
  if (LCD_Menu_NAVI == 6) lcd.print(F("")); 
  if (LCD_Menu_NAVI == 7) lcd.print(F("")); 
  if (LCD_Menu_NAVI == 8) lcd.print(F("")); 
  if (LCD_Menu_NAVI == 9) lcd.print(F("")); 
  if (LCD_Menu_NAVI == 10) lcd.print(F("")); 
  Max_Options_NAVI = 10;
  }


void Print_Membrane_Switch_Input_NAVI() {
     Read_Membrane_Keys();
     Menu_Complete_NAVI = 1;
     Menu_Mode_Selection = 0;
     Menu_View = 0;

      Serial.println();
      Serial.println(F("NAVI Menu Activated"));
      Menu_Complete_NAVI = false;                                // Menu complete will return to the normal loop
      lcd.clear();
      delay(5);
      
      while (Menu_Complete_NAVI == false) {                      // holds the program in a loop until a selection has been made in the membrane button menu
        if (Menu_View == 0) {
          lcd.setCursor(1,0);
          Print_LCD_Menu_NAVI(1);
          lcd.setCursor(1,1);
          Print_LCD_Menu_NAVI(2);
          }
        // Gets the values again from the keys
        Read_Membrane_Keys();
        delay(100);
             
        if(!Start_Key_X){
          Menu_Complete_NAVI = true;
          Serial.println(F("Start key is pressed"));
          Activate_Menu_Option_NAVI();
          lcd.clear();
          
          }
        if(!Plus_Key_X) {
          Serial.println(F("+ key is pressed"));
          Menu_View = Menu_View - 1;
          Run_Menu_Order_NAVI();
          }
        if(!Minus_Key_X) {
          Menu_View = Menu_View + 1;
          Run_Menu_Order_NAVI();
        }
        if(!Stop_Key_X){
          Serial.println(F("Stop key is pressed"));
          Menu_Complete_NAVI = true;
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Exit NAVI");
          delay(1000);
          lcd.clear();          
          Menu_Mode_Selection = 0;
          }
      }
    }

    


// Code to scroll the menu and print the menu options in the LCD
 void Run_Menu_Order_NAVI() {
     if (Menu_View > Max_Options_NAVI) Menu_View = Menu_View -1;
     if (Menu_View < 0) Menu_View = Menu_View + 1;      
     Serial.print(F("- key is pressed "));
     lcd.clear();
     lcd.setCursor(1,0);
     Print_LCD_Menu_NAVI(Menu_View);
     lcd.setCursor(1,1);
     Print_LCD_Menu_NAVI( Menu_View + 1);
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
void Activate_Menu_Option_NAVI() {


   if (Menu_Mode_Selection == 1) {
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
       
       Menu_Complete_NAVI = false;
       while (Menu_Complete_NAVI == false) {
          Read_Membrane_Keys();
          delay(100);
          //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
               Serial.println(F("Compass Settings Saved"));
               Menu_Complete_NAVI = true;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print(F("Compass Saved"));
               Serial.print(F("Compass:"));
               Serial.println(Compass_Activate);
               delay(2000);
               lcd.clear();          
               EEPROM.write(19 , 1);
               EEPROM.write(20 , Compass_Activate);
               if (Compass_Activate == 1)   {
                   if (Compass_Setup_Mode == 1) Setup_DFRobot_QMC5883_HMC5883L_Compass();   // USes the DFRobot Library
                   if (Compass_Setup_Mode == 2) Setup_DFRobot_QMC5883_HMC5883L_Compass();   // Uses manual i2C address
                   if (Compass_Setup_Mode == 3) Setup_DFRobot_QMC5883_HMC5883L_Compass();   // Uses QMC5883L Library               
                   Menu_Mode_Selection = 0;
                   }
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


     if (Menu_Mode_Selection == 2) {
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
       Menu_Complete_NAVI = false;
       while (Menu_Complete_NAVI == false) {
             Read_Membrane_Keys();
             delay(100);
             //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
             Serial.println(F("Settings Saved"));
             Menu_Complete_NAVI = true;
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



   if (Menu_Mode_Selection == 3) {
       // Heading Hold ON/OFF
       lcd.clear();
       lcd.print(F("Heading Hold Setup"));
       delay(1000);
       lcd.clear();
       Menu_Mode_Selection = 0;
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print(F("H-Hold ON/OFF"));
       lcd.setCursor(0,1);
       lcd.print(F("Status : "));
       if (Compass_Heading_Hold_Enabled == 1) lcd.print(F("ON "));
       if (Compass_Heading_Hold_Enabled == 0) lcd.print(F("OFF"));
       
       Menu_Complete_NAVI = false;
       while (Menu_Complete_NAVI == false) {
          Read_Membrane_Keys();
          delay(100);
          //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
               Serial.println(F("Heading Hold Settings Saved"));
               Menu_Complete_NAVI = true;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print(F("H-Hold Saved"));
               Serial.print(F("Heading Hold:"));
               Serial.println(Compass_Heading_Hold_Enabled);
               delay(2000);
               lcd.clear();          
               EEPROM.write(59 , 1);
               EEPROM.write(60 , Compass_Heading_Hold_Enabled);
               Menu_Mode_Selection = 0;
               
               }
             if (!Plus_Key_X) {
               lcd.setCursor(0,1);
               lcd.print(F("Status : "));
               Compass_Heading_Hold_Enabled = 1;
               lcd.print(F("ON "));
               Serial.print(F("H-Hold:"));
               Serial.println(Compass_Heading_Hold_Enabled);
               delay(100);
               }
             if (!Minus_Key_X) {
               lcd.setCursor(0,1);
               lcd.print(F("Status : "));
               Compass_Heading_Hold_Enabled = 0;
               lcd.print(F("OFF"));
               Serial.print(F("H-Hold:"));
               Serial.println(Compass_Heading_Hold_Enabled);
               delay(100);
               }
     }
     }



     if (Menu_Mode_Selection == 4) {
       // Compass PID Settings
       Menu_Mode_Selection = 0;
       lcd.clear();
       delay(500);
       lcd.setCursor(0,0);
       lcd.print(F("Compass PID:"));
       lcd.setCursor(0,1);
       lcd.print(F("P = "));
       lcd.print(CPower);
       Serial.print(F("Compass PID P = :"));
       Serial.println(CPower);
       Menu_Complete_NAVI = false;
       while (Menu_Complete_NAVI == false) {
             Read_Membrane_Keys();
             delay(100);
             //Enter Code Here to Cycle until stop key is pressed.
             if(!Start_Key_X){
             Serial.println(F("Settings Saved"));
             Menu_Complete_NAVI = true;
             lcd.clear();
             lcd.setCursor(0,0);
             lcd.print("Compass P : ");
             lcd.print(CPower);
             lcd.setCursor(0,1);
             lcd.print(F("SAVED"));
             delay(2000);
             lcd.clear();          
             EEPROM.write(61, 1);
             EEPROM.write(62, (CPower*100));   
             Menu_Mode_Selection = 0;
             }
             if (!Plus_Key_X) {
               CPower = CPower + 0.01;
               if (CPower > 10) CPower = 10;
               lcd.clear();
               lcd.print(F("Compass PID:"));
               lcd.setCursor(0,1);
               lcd.print(F("P = "));
               lcd.print(CPower);
               Serial.print(F("Compass PID P = :"));
               Serial.println(CPower);
               }
             if (!Minus_Key_X) {
               CPower = CPower - 0.01;
               if (CPower < 0) CPower = 0.1;
               lcd.clear();
               lcd.print(F("Compass PID:"));
               lcd.setCursor(0,1);
               lcd.print(F("P = "));
               lcd.print(CPower);
               Serial.print(F("Compass PID P = :"));
               Serial.println(CPower);
               }
             
             }
     }
if (Menu_Complete_NAVI = true) Print_Membrane_Switch_Input_NAVI();   
}

#endif
