// Reads each of the membrane keys and detects if a key is pressed.
void Read_Membrane_Keys(){
  Start_Key_X   = digitalRead(Start_Key);    
  Plus_Key_X    = digitalRead(Plus_Key);   
  Minus_Key_X   = digitalRead(Minus_Key);
  Stop_Key_X    = digitalRead(Stop_Key);  
}


//************************************************************************

void Check_Membrane_Switch_Input() {

  //Mower_Docked = 0;    // use to test second menu feature

  //Menu Options if the Mower is docked.
  if (Mower_Docked == 1) {
     Read_Membrane_Keys();
     Menu_Complete = 1;
     Menu_Mode_Selection = 0;
     char Menu_Item_1[16] = "Exit Dock Z-1";
     char Menu_Item_2[16] = "Exit Dock Z-2";
     char Menu_Item_3[16] = "Quick Start";
     char Menu_Item_4[16] = "Trampoline Cut";
     char Menu_Item_5[16] = "Mow the Line";
     char Menu_Item_6[16] = "-- SPARE 6 ---";
     int Menu_View = 0;

    
     if(!Start_Key_X)  {                                    // If the start key is pressed
      Serial.print("Start Key Pressed");
      Menu_Complete = false;                                // Menu complete will return to the normal loop
      lcd.clear();
      delay(5);
      Serial.print("Menu Complete = ");
      Serial.println(Menu_Complete);
      delay(500);
      while (Menu_Complete == false) {                      // holds the program in a loop until a selection has been made in the membrane button menu
        Serial.println("Start key is pressed");
        Serial.print("Menu View Currently : ");
        Serial.println(Menu_View);
        if (Menu_View <= 1) {
          lcd.setCursor(2,0);
          lcd.print(Menu_Item_1);
          lcd.setCursor(2,1);
          lcd.print(Menu_Item_2);
          }
        // Gets the values again from the keys
        Read_Membrane_Keys();
        delay(100);
             
        if(!Start_Key_X){
          Menu_Complete = true;
          Serial.println("Start key is pressed");
          lcd.clear();
          }
        if(!Plus_Key_X) {
          Serial.println("+ key is pressed");
          Menu_Mode_Selection = 1;
          if (Menu_View > 1) {
             lcd.clear();
             lcd.setCursor(2,0);
             lcd.print(Menu_Item_1);
             lcd.setCursor(2,1);
             lcd.print(Menu_Item_2);
             Serial.print("Menu View : ");
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
             Serial.println("- key is pressed");
             lcd.setCursor(0,0);
             lcd.print(" ");
             lcd.setCursor(0,1);
             lcd.print(">");
             Menu_Mode_Selection = 2;
             Menu_View = Menu_View + 1;
             Serial.print("Menu View Added 2 : ");
             Serial.println(Menu_View);
             delay(100);
             }
          if ((Menu_View >= 2) && (Menu_View <= 3)){
              lcd.clear();
              lcd.setCursor(2,0);
              lcd.print(Menu_Item_2);
              lcd.setCursor(2,1);
              lcd.print(Menu_Item_3);
              lcd.setCursor(0,1);
              lcd.print(">");
              Menu_Mode_Selection = 3;
              Menu_View = Menu_View + 1;;
              Serial.print("Menu View Added 3: ");
              Serial.println(Menu_View);
              delay(100);
              }
          if ((Menu_View >= 4) && (Menu_View <= 5)) {
              lcd.clear();
              lcd.setCursor(2,0);
              lcd.print(Menu_Item_3);
              lcd.setCursor(2,1);
              lcd.print(Menu_Item_4);
              lcd.setCursor(0,1);
              lcd.print(">");
              Menu_Mode_Selection = 4;
              Menu_View = Menu_View + 1;
              Serial.print("Menu View Added 4: ");
              Serial.println(Menu_View);
              delay(100);
              }
           if ( (Menu_View >= 6) && (Menu_View <= 7) ) {
              lcd.clear();
              lcd.setCursor(2,0);
              lcd.print(Menu_Item_4);
              lcd.setCursor(2,1);
              lcd.print(Menu_Item_5);
              lcd.setCursor(0,1);
              lcd.print(">");
              Menu_Mode_Selection = 5;
              Menu_View = Menu_View + 1;
              Serial.print("Menu View Added 5: ");
              Serial.println(Menu_View);
              delay(100);
              }
           if (Menu_View >= 8) {
              lcd.clear();
              lcd.setCursor(2,0);
              lcd.print(Menu_Item_5);
              lcd.setCursor(2,1);
              lcd.print(Menu_Item_6);
              lcd.setCursor(0,1);
              lcd.print(">");
              Menu_Mode_Selection = 6;
              Menu_View = 8;
              Serial.print("Menu View Added 6: ");
              Serial.println(Menu_View);
              delay(100);
              }
        }
        if(!Stop_Key_X){
          Serial.println("Stop key is pressed");
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
       lcd.clear();
       lcd.print("Manuel Start");
       lcd.setCursor(0,1);
       lcd.print("Exit Dock Z1");
       Serial.println("Exit to Zone 1 - Free Mow");
       delay(1000);
       lcd.clear();
       Set_Mower_Time();
       Menu_Mode_Selection = 0;
       delay(3000);
       lcd.clear();
       Exit_From_Docking_Station();                        // Set up the mower to exit the docking station 
       delay(500);
       Exit_From_Garage();                                 // Back the mower out of the Garage and into position
       delay(500);
       FindWireTrack();      
       delay(300);      
       Track_Wire_Itterations = Track_Wire_Zone_1_Cycles;
       Exit_Zone = 1;
       Track_Wire_From_Dock_to_Zone_X();
       delay(500);
       Move_Into_Garden_Zone_X();
       delay(500);
       Prepare_To_Mow();
       }
 
     
     if (Menu_Mode_Selection == 2) {
       Menu_Mode_Selection = 0;
       lcd.clear();
       lcd.print("Manuel Start");
       lcd.setCursor(0,1);
       lcd.print("Exit Dock Z2");
       delay(1000);
       lcd.clear();
       Set_Mower_Time();
       if (Mow_Time_Set == 1) {
         Serial.println("Exit to Zone 2 - Free Mow");
         digitalWrite(Relay_Motors, LOW);
         delay(2000);
         Exit_From_Docking_Station();                       // Set up the mower to exit the docking station 
         delay(500);
         Exit_From_Garage();                                // Move the Mower into position backing out of the docking station
         delay(500);  
         FindWireTrack();                                   // Located the boundary wire
         delay(300);      
         Track_Wire_Itterations = Track_Wire_Zone_2_Cycles; // Set the number of itterations of following the wire.
         Exit_Zone = 2;                                     // Zone called to exit at
         Track_Wire_From_Dock_to_Zone_X();                  // Runs the PID function and follows the wire until the itterations are completed
         delay(500);
         Move_Into_Garden_Zone_X();                         // Calls the motion function to move the mower off the wire into the garden
         delay(500);
         Prepare_To_Mow();                                  // Sets up the mower to go.
         delay(100);
         }
       }

     if (Menu_Mode_Selection == 3) {
        lcd.clear();
        lcd.print("Quick Start");
        Serial.println("Mower Quick Start Selected");
        Menu_Mode_Selection = 0;
        delay(1000);
        lcd.clear();
        Set_Mower_Time();
        delay(1000);
        if (Mow_Time_Set == 1) Prepare_To_Mow();
        }
        
   
     if (Menu_Mode_Selection == 4) {
        lcd.clear();
        lcd.print("Trampoline Cut!");
        Serial.println("Mower Set to Cut under Trampoline");
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
         Serial.println("Cutting the grass on the boundary wire");
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
        Serial.println("Slot 6 Selected");
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
     char Menu_Item_1[16] = "Continue Mow";
     char Menu_Item_2[16] = "Go Home";
     char Menu_Item_3[16] = "Trampoline Cut";
     char Menu_Item_4[16] = "-- Spare 4 --";
     char Menu_Item_5[16] = "-- Spare 5 --";
     char Menu_Item_6[16] = "-- Spare 6 --";
     int Menu_View = 0;

    
     if ((!Start_Key_X) || (!Stop_Key_X) )  {                 // If the stop or start key is pressed
      Serial.print("Stop Key Pressed");
      Motion_StopMotors();
      delay(100);
      StopSpinBlades();
      delay(100);
      Menu_Complete = false;                                // Menu complete will return to the normal loop
      lcd.clear();
      delay(5);
      Serial.print("Menu Complete = ");
      Serial.println(Menu_Complete);
      delay(500);
      while (Menu_Complete == false) {                      // holds the program in a loop until a selection has been made in the membrane button menu
        Serial.println("Start key is pressed");
        Serial.print("Menu View Currently : ");
        Serial.println(Menu_View);
        if (Menu_View <= 1) {
          lcd.setCursor(2,0);
          lcd.print(Menu_Item_1);
          lcd.setCursor(2,1);
          lcd.print(Menu_Item_2);
          }
        // Gets the values again from the keys
        Read_Membrane_Keys();
        delay(100);

             
        if(!Start_Key_X){
          Menu_Complete = true;
          Serial.println("Start key is pressed");
          lcd.clear();
          }
        if(!Plus_Key_X) {
          Serial.println("+ key is pressed");
          Menu_Mode_Selection = 1;
          if (Menu_View > 1) {
             lcd.clear();
             lcd.setCursor(2,0);
             lcd.print(Menu_Item_1);
             lcd.setCursor(2,1);
             lcd.print(Menu_Item_2);
             Serial.print("Menu View : ");
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
             Serial.println("- key is pressed");
             lcd.setCursor(0,0);
             lcd.print(" ");
             lcd.setCursor(0,1);
             lcd.print(">");
             Menu_Mode_Selection = 2;
             Menu_View = Menu_View + 1;
             Serial.print("Menu View Added 2 : ");
             Serial.println(Menu_View);
             delay(100);
             }
          if ((Menu_View >= 2) && (Menu_View <= 3)){
              lcd.clear();
              lcd.setCursor(2,0);
              lcd.print(Menu_Item_2);
              lcd.setCursor(2,1);
              lcd.print(Menu_Item_3);
              lcd.setCursor(0,1);
              lcd.print(">");
              Menu_Mode_Selection = 3;
              Menu_View = Menu_View + 1;;
              Serial.print("Menu View Added 3: ");
              Serial.println(Menu_View);
              delay(100);
              }
          if ((Menu_View >= 4) && (Menu_View <= 5)) {
              lcd.clear();
              lcd.setCursor(2,0);
              lcd.print(Menu_Item_3);
              lcd.setCursor(2,1);
              lcd.print(Menu_Item_4);
              lcd.setCursor(0,1);
              lcd.print(">");
              Menu_Mode_Selection = 4;
              Menu_View = Menu_View + 1;
              Serial.print("Menu View Added 4: ");
              Serial.println(Menu_View);
              delay(100);
              }
           if ( (Menu_View >= 6) && (Menu_View <= 7) ) {
              lcd.clear();
              lcd.setCursor(2,0);
              lcd.print(Menu_Item_4);
              lcd.setCursor(2,1);
              lcd.print(Menu_Item_5);
              lcd.setCursor(0,1);
              lcd.print(">");
              Menu_Mode_Selection = 5;
              Menu_View = Menu_View + 1;
              Serial.print("Menu View Added 5: ");
              Serial.println(Menu_View);
              delay(100);
              }
           if (Menu_View >= 8) {
              lcd.clear();
              lcd.setCursor(2,0);
              lcd.print(Menu_Item_5);
              lcd.setCursor(2,1);
              lcd.print(Menu_Item_6);
              lcd.setCursor(0,1);
              lcd.print(">");
              Menu_Mode_Selection = 6;
              Menu_View = 8;
              Serial.print("Menu View Added 6: ");
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
      Serial.println("Mower Re-starting");
      delay(2000);
      Prepare_To_Mow();                                             // Restarts the mower again from standing position
     }

     if (Menu_Mode_Selection == 2) {
      lcd.clear();
      lcd.print("Returning Home");
      Serial.println("Sending Mower Home");
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
        Serial.println("Mower Set to Cut under Trampoline");
        Menu_Mode_Selection = 0;
        delay(3000);
        lcd.clear();
        Cut_Under_Trampoline_Function();
        }

      if (Menu_Mode_Selection == 4) {
        lcd.clear();
        lcd.print("Slot 4 - Empty");
        Serial.println("Slot 4 Selected");
        Menu_Mode_Selection = 0;
        delay(3000);
        lcd.clear();
        // Insert Function Here();
        }

      if (Menu_Mode_Selection == 5) {
        lcd.clear();
        lcd.print("Slot 5 - Empty");
        Serial.println("Slot 5 Selected");
        Menu_Mode_Selection = 0;
        delay(3000);
        lcd.clear();
        // Insert Function Here();
        }

      if (Menu_Mode_Selection == 6) {
        lcd.clear();
        lcd.print("Slot 6 - Empty");
        Serial.println("Slot 6 Selected");
        Menu_Mode_Selection = 0;
        delay(3000);
        lcd.clear();
        // Insert Function Here();
        }
  } // end if mower docked =! 7  
     
}    
