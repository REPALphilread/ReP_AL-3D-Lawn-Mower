// Test to displyed on the LCD screen when using the membrane key menus
void Print_LCD_Menu_Parked(byte LCD_Menu_Parked) {
  if (LCD_Menu_Parked == 1)   lcd.print("Mow Grass     ");
  if (LCD_Menu_Parked == 2)   {
    if (Use_Charging_Station == 1)  lcd.print("Go To Dock");
    if (Use_Charging_Station == 0)  lcd.print("-- SPARE 2 --");
    }
  if (LCD_Menu_Parked == 3)   lcd.print("Trampoline Cut");
  if (LCD_Menu_Parked == 4)   lcd.print("-- SPARE 4 ---");
  if (LCD_Menu_Parked == 5)   lcd.print("-- SPARE 5 ---");
  if (LCD_Menu_Parked == 6)   lcd.print("Tests");
  }
  

void Check_Membrane_Switch_Input_Parked() {

  //Menu Options if the Mower is Parked.
     Read_Membrane_Keys();
     Menu_Complete = 1;
     Menu_Mode_Selection = 0;
     int Menu_View = 0;

    
     if ((!Start_Key_X) || (!Stop_Key_X) )  {                 // If the stop or start key is pressed
      Serial.print(F("Stop Key Pressed"));
      Manouver_Park_The_Mower(); 
      Menu_Complete = false;                                // Menu complete will return to the normal loop
      lcd.clear();
      delay(5);
      Serial.print(F("Menu Complete = "));
      Serial.println(Menu_Complete);
      delay(500);
      while (Menu_Complete == false) {                      // holds the program in a loop until a selection has been made in the membrane button menu
        if (Menu_View <= 1) {
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
          Menu_Mode_Selection = 1;
          if (Menu_View > 1) {
             lcd.clear();
             lcd.setCursor(2,0);
             Print_LCD_Menu_Parked(1);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Parked(2);
             Serial.print(F("Menu View : "));
             Serial.println(Menu_View);
             Menu_View = 0;
             }
          lcd.setCursor(0,0);
          lcd.print(">");
          lcd.setCursor(0,1);
          lcd.print(" ");
          }
        if(!Minus_Key_X){
          if (Menu_View <= 1) {
             Serial.println(F("- key is pressed"));
             lcd.setCursor(0,0);
             lcd.print(" ");
             lcd.setCursor(0,1);
             lcd.print(">");
             Menu_Mode_Selection = 2;
             Menu_View = Menu_View + 1;
             Serial.print(F("Menu View Added 2 : "));
             Serial.println(Menu_View);
             delay(100);
             }
          if ((Menu_View >= 2) && (Menu_View <= 3)){
              lcd.clear();
              lcd.setCursor(2,0);
              Print_LCD_Menu_Parked(2);
              lcd.setCursor(2,1);
              Print_LCD_Menu_Parked(3);
              lcd.setCursor(0,1);
              lcd.print(">");
              Menu_Mode_Selection = 3;
              Menu_View = Menu_View + 1;;
              Serial.print(F("Menu View Added 3: "));
              Serial.println(Menu_View);
              delay(100);
              }
          if ((Menu_View >= 4) && (Menu_View <= 5)) {
              lcd.clear();
              lcd.setCursor(2,0);
              Print_LCD_Menu_Parked(3);
              //lcd.print(Menu_Item_3);
              lcd.setCursor(2,1);
              Print_LCD_Menu_Parked(4);
              //lcd.print(Menu_Item_4);
              lcd.setCursor(0,1);
              lcd.print(">");
              Menu_Mode_Selection = 4;
              Menu_View = Menu_View + 1;
              Serial.print(F("Menu View Added 4: "));
              Serial.println(Menu_View);
              delay(100);
              }
           if ( (Menu_View >= 6) && (Menu_View <= 7) ) {
              lcd.clear();
              lcd.setCursor(2,0);
              Print_LCD_Menu_Parked(4);
              lcd.setCursor(2,1);
              Print_LCD_Menu_Parked(5);
              lcd.setCursor(0,1);
              lcd.print(">");
              Menu_Mode_Selection = 5;
              Menu_View = Menu_View + 1;
              Serial.print(F("Menu View Added 5: "));
              Serial.println(Menu_View);
              delay(100);
              }
           if (Menu_View >= 8) {
              lcd.clear();
              lcd.setCursor(2,0);
              Print_LCD_Menu_Parked(5);
              lcd.setCursor(2,1);
              Print_LCD_Menu_Parked(6);
              lcd.setCursor(0,1);
              lcd.print(">");
              Menu_Mode_Selection = 6;
              Menu_View = 8;
              Serial.print(F("Menu View Added 6: "));
              Serial.println(Menu_View);
              delay(100);
              }
        }
        if(!Stop_Key_X){
          Serial.println(F("Stop key is pressed"));
          Menu_Complete = true;
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Menu Cancelled");
          delay(2000);
          lcd.clear();          
          Menu_Mode_Selection = 0;
          }
 
        } // end while loop 
      }
     delay(100);
     if (Menu_Mode_Selection == 1) {
      Menu_Mode_Selection = 0;
      lcd.clear();
      lcd.print("Mow Re-Starting");
      Serial.println(F("Mower Starting"));
      delay(2000);
      Manouver_Start_Mower();                                             // Restarts the mower again from standing position
      lcd.clear();     
     }

     if (Menu_Mode_Selection == 2) {
      if (Use_Charging_Station == 1) {
          lcd.clear();
          lcd.print("Returning Home");
          Serial.println(F("Sending Mower Home"));
          delay(100);
          delay(100);
          Menu_Mode_Selection = 0;                                      // Releases the loop in the membrane button section.
          delay(3000);
          lcd.clear();
          Manouver_Go_To_Charging_Station();        
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
        lcd.print("Slot 4 - Empty");
        Serial.println(F("Slot 4 Selected"));
        Menu_Mode_Selection = 0;
        delay(3000);
        lcd.clear();
        // Insert Function Here();
        }

      if (Menu_Mode_Selection == 5) {
        lcd.clear();
        lcd.print("Slot 5 - Empty");
        Serial.println(F("Slot 5 Selected"));
        Menu_Mode_Selection = 0;
        delay(3000);
        lcd.clear();
        // Insert Function Here();
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
     
  
