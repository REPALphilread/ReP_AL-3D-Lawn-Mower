// Test to displyed on the LCD screen when using the membrane key menus
void Print_LCD_Menu_Tests(byte LCD_Menu_Tests) {
  if (LCD_Menu_Tests == 1) lcd.print("Wire Test");
  if (LCD_Menu_Tests == 2) lcd.print("Relay Test");
  if (LCD_Menu_Tests == 3) lcd.print("Wheel Test");
  if (LCD_Menu_Tests == 4) lcd.print("Blade Test");
  if (LCD_Menu_Tests == 5) lcd.print("Sonar Test");
  if (LCD_Menu_Tests == 6) lcd.print("-- SPARE --");
  }





void Print_Membrane_Switch_Input_Tests() {

  //Menu Options if the Mower is Tests.
     Read_Membrane_Keys();
     Menu_Complete = 1;
     Menu_Mode_Selection = 0;
     int Menu_View = 0;

    
      Serial.println();
      Serial.println(F("Test Menu Activated"));
      Menu_Complete = false;                                // Menu complete will return to the normal loop
      lcd.clear();
      delay(5);
      //Serial.print(F("Menu Complete = "));
      //Serial.println(Menu_Complete);
      delay(500);
      
      while (Menu_Complete == false) {                      // holds the program in a loop until a selection has been made in the membrane button menu
        if (Menu_View <= 1) {
          lcd.setCursor(2,0);
          Print_LCD_Menu_Tests(1);
          lcd.setCursor(2,1);
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
          Menu_Mode_Selection = 1;
          if (Menu_View > 1) {
             lcd.clear();
             lcd.setCursor(2,0);
             Print_LCD_Menu_Tests(1);
             lcd.setCursor(2,1);
             Print_LCD_Menu_Tests(2);
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
              Print_LCD_Menu_Tests(2);
              lcd.setCursor(2,1);
              Print_LCD_Menu_Tests(3);
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
              Print_LCD_Menu_Tests(3);
               lcd.setCursor(2,1);
              Print_LCD_Menu_Tests(4);
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
              Print_LCD_Menu_Tests(4);
              lcd.setCursor(2,1);
              Print_LCD_Menu_Tests(5);
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
              Print_LCD_Menu_Tests(5);
              lcd.setCursor(2,1);
              Print_LCD_Menu_Tests(6);
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
      delay(100);

     if (Menu_Mode_Selection == 1) {
       // Perimeter Wire Test
       lcd.clear();
       lcd.print("Wire Test");
       lcd.setCursor(0,1);
       lcd.print("Activated");
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
             lcd.print("Test Stopped");
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
       lcd.print("Relay Test");
       lcd.setCursor(0,1);
       lcd.print("Activated");
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
             lcd.print("Test Stopped");
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
       lcd.print("Wheel Motor Test");
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
        lcd.print("Slot 5 - Empty");
        Serial.println(F("Slot 6 Selected"));
        Menu_Mode_Selection = 0;
        delay(3000);
        lcd.clear();
        // Insert Function Here();
        }
  
  }
