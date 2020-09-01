// Reads each of the membrane keys and detects if a key is pressed.
void Read_Membrane_Keys(){
  Start_Key_X   = digitalRead(Start_Key);    
  Plus_Key_X    = digitalRead(Plus_Key);   
  Minus_Key_X   = digitalRead(Minus_Key);
  Stop_Key_X    = digitalRead(Stop_Key);  
}


// Test to displyed on the LCD screen when using the membrane key menus
void Print_LCD_Menu_1(byte LCD_Menu_1) {
  if (LCD_Menu_1 == 1) lcd.print("Exit Dock Z-1");
  if (LCD_Menu_1 == 2) lcd.print("Exit Dock Z-2");
  if (LCD_Menu_1 == 3) lcd.print("Quick Start");
  if (LCD_Menu_1 == 4) lcd.print("Trampoline Cut");
  if (LCD_Menu_1 == 5) lcd.print("Mow the Line");
  if (LCD_Menu_1 == 6) lcd.print("-- SPARE 6 ---");
}


// Test to displyed on the LCD screen when using the membrane key menus
// when the mower is active
void Print_LCD_Menu_2(byte LCD_Menu_2) {
  if (LCD_Menu_2 == 1) lcd.print("Continue Mow");
  if (LCD_Menu_2 == 2) lcd.print("Go Home");
  if (LCD_Menu_2 == 3) lcd.print("Trampoline Cut");
  if (LCD_Menu_2 == 4) lcd.print("-- SPARE 4 ---");
  if (LCD_Menu_2 == 5) lcd.print("-- SPARE 5 ---");
  if (LCD_Menu_2 == 6) lcd.print("-- SPARE 6 ---");
  }

//************************************************************************

void Check_Membrane_Switch_Input() {

  //Mower_Docked = 0;    // use to test second menu feature

  //Menu Options if the Mower is docked.
  if (Mower_Docked == 1) {
     Read_Membrane_Keys();
     Menu_Complete = 1;
     Menu_Mode_Selection = 0;
     //char Menu_Item_1[16] = "Exit Dock Z-1";
     //char Menu_Item_2[16] = "Exit Dock Z-2";
     //char Menu_Item_3[16] = "Quick Start";
     //char Menu_Item_4[16] = "Trampoline Cut";
     //char Menu_Item_5[16] = "Mow the Line";
     //char Menu_Item_6[16] = "-- SPARE 6 ---";
     int Menu_View = 0;

    
     if(!Start_Key_X)  {                                    // If the start key is pressed
      Serial.print(F("Start Key Pressed"));
      Menu_Complete = false;                                // Menu complete will return to the normal loop
      lcd.clear();
      delay(5);
      Serial.print(F("Menu Complete = "));
      Serial.println(Menu_Complete);
      delay(500);
      while (Menu_Complete == false) {                      // holds the program in a loop until a selection has been made in the membrane button menu
        Serial.println(F("Start key is pressed"));
        Serial.print(F("Menu View Currently : "));
        Serial.println(Menu_View);
        if (Menu_View <= 1) {
          lcd.setCursor(2,0);
          Print_LCD_Menu_1(1);
          lcd.setCursor(2,1);
          Print_LCD_Menu_1(2);
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
             Print_LCD_Menu_1(1);
             lcd.setCursor(2,1);
             Print_LCD_Menu_1(2);
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
              Print_LCD_Menu_1(2);
              //lcd.print(Menu_Item_2);
              lcd.setCursor(2,1);
              Print_LCD_Menu_1(3);
              //lcd.print(Menu_Item_3);
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
              Print_LCD_Menu_1(3);
               lcd.setCursor(2,1);
              Print_LCD_Menu_1(4);
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
              Print_LCD_Menu_1(4);
              lcd.setCursor(2,1);
              Print_LCD_Menu_1(5);
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
              Print_LCD_Menu_1(5);
              lcd.setCursor(2,1);
              Print_LCD_Menu_1(6);
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
       delay(3000);
       lcd.clear();
       Manuel_Start_Mower_Exit_Zone1();
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
       if (Mow_Time_Set == 1) {
       Manuel_Start_Mower_Exit_Zone2();
       }
     }

     if (Menu_Mode_Selection == 3) {
        // Quick Start the Mower in the middle of the Garden;
        Quick_Start();
        Set_Mower_Time();
        delay(1000);
        if (Mow_Time_Set == 1) Prepare_To_Mow();
        }
        
   
     if (Menu_Mode_Selection == 4) {
        lcd.clear();
        lcd.print("Trampoline Cut!");
        Serial.println(F("Mower Set to Cut under Trampoline"));
        Menu_Mode_Selection = 0;
        delay(3000);
        lcd.clear();
        Cut_Under_Trampoline_Function();
        }
          
      if (Menu_Mode_Selection == 5) {
       lcd.clear();
       lcd.print("Blade will spin");
       lcd.setCursor(0,1);
       lcd.print("Cut the Line");
       delay(1000);
       lcd.clear();
       Set_Mower_Time();
       if (Mow_Time_Set == 1) {
         Serial.println(F("Cutting the grass on the boundary wire"));
         digitalWrite(Relay_Motors, LOW);
         delay(2000);
         Exit_From_Docking_Station();                       // Set up the mower to exit the docking station 
         delay(500);
         Exit_From_Garage();                                // Move the Mower into position backing out of the docking station
         delay(500);  
         FindWireTrack();                                   // Located the boundary wire
         delay(300);      
         Blade_Override = 1;
         Track_Wire_Itterations = 6000; // Set the number of itterations of following the wire.
         Exit_Zone = 3;                                     // Zone called to exit at
         Track_Wire_From_Dock_to_Zone_X();                  // Runs the PID function and follows the wire until the itterations are completed
         delay(500);
         Move_Into_Garden_Zone_X();                         // Calls the motion function to move the mower off the wire into the garden
         delay(500);
         Prepare_To_Mow();                                  // Sets up the mower to go.
         delay(100);
         }
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
  } // end if mower docked == 7   


 //Menu Options if the Mower is working in the garden.
  if (Mower_Docked != 1) {
     Read_Membrane_Keys();
     Menu_Complete = 1;
     Menu_Mode_Selection = 0;
     //char Menu_Item_1[16] = "Continue Mow";
     //char Menu_Item_2[16] = "Go Home";
     //char Menu_Item_3[16] = "Trampoline Cut";
     //char Menu_Item_4[16] = "-- Spare 4 --";
     //char Menu_Item_5[16] = "-- Spare 5 --";
     //char Menu_Item_6[16] = "-- Spare 6 --";
     int Menu_View = 0;

    
     if ((!Start_Key_X) || (!Stop_Key_X) )  {                 // If the stop or start key is pressed
      Serial.print(F("Stop Key Pressed"));
      Motion_StopMotors();
      delay(100);
      StopSpinBlades();
      delay(100);
      Menu_Complete = false;                                // Menu complete will return to the normal loop
      lcd.clear();
      delay(5);
      Serial.print(F("Menu Complete = "));
      Serial.println(Menu_Complete);
      delay(500);
      while (Menu_Complete == false) {                      // holds the program in a loop until a selection has been made in the membrane button menu
        Serial.println(F("Start key is pressed"));
        Serial.print(F("Menu View Currently : "));
        Serial.println(Menu_View);
        if (Menu_View <= 1) {
          lcd.setCursor(2,0);
          Print_LCD_Menu_2(1);
          //lcd.print(Menu_Item_1);
          lcd.setCursor(2,1);
          Print_LCD_Menu_2(2);
          //lcd.print(Menu_Item_2);
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
             Print_LCD_Menu_2(1);
             lcd.setCursor(2,1);
             Print_LCD_Menu_2(2);
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
              Print_LCD_Menu_2(2);
              //lcd.print(Menu_Item_2);
              lcd.setCursor(2,1);
              Print_LCD_Menu_2(3);
              //lcd.print(Menu_Item_3);
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
              Print_LCD_Menu_2(3);
              //lcd.print(Menu_Item_3);
              lcd.setCursor(2,1);
              Print_LCD_Menu_2(4);
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
              Print_LCD_Menu_2(4);
              lcd.setCursor(2,1);
              Print_LCD_Menu_2(5);
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
              Print_LCD_Menu_2(5);
              lcd.setCursor(2,1);
              Print_LCD_Menu_2(6);
              lcd.setCursor(0,1);
              lcd.print(">");
              Menu_Mode_Selection = 6;
              Menu_View = 8;
              Serial.print(F("Menu View Added 6: "));
              Serial.println(Menu_View);
              delay(100);
              }
        }
 
        } // end while loop 
      }
     delay(100);
     if (Menu_Mode_Selection == 1) {
      Menu_Mode_Selection = 0;
      lcd.clear();
      lcd.print("Mow Re-Starting");
      Serial.println(F("Mower Re-starting"));
      delay(2000);
      Prepare_To_Mow();                                             // Restarts the mower again from standing position
     }

     if (Menu_Mode_Selection == 2) {
      lcd.clear();
      lcd.print("Returning Home");
      Serial.println(F("Sending Mower Home"));
      MowerMotionStatus = 1;
      Error = 7;                                                    // Sets mower into the Error mode to find home
      delay(100);
      delay(100);
      Menu_Mode_Selection = 0;                                      // Releases the loop in the membrane button section.
      delay(3000);
      lcd.clear();
     }
      
      if (Menu_Mode_Selection == 3) {
        lcd.clear();
        lcd.print("Trampoline Cut!");
        Serial.println(F("Mower Set to Cut under Trampoline"));
        Menu_Mode_Selection = 0;
        delay(3000);
        lcd.clear();
        Cut_Under_Trampoline_Function();
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
  } // end if mower docked =! 7  
     
}    
