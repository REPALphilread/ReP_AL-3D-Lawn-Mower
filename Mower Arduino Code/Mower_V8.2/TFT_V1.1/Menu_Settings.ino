
// Settings Menu
//*********************************

void Print_Settings_Menu() {
    tft.fillScreen(BLACK);
      // Framework for the buttons - setting the start position of the Quick start button wil automatically then space the other buttons

    int Start_X = 90;
    int Start_Y = 80;
    int Menu_Btn_Space = 100;          // Space between the adjacent buttons
    int Button_W = 130;                // width of the button
    int Button_H = 60;                // height of the button

    int Menu_Spacing = 20;            // Distance between the Menu Items (bottom of the last button to the label of the next item)
    int Txt_Size_Main_Menu = 2;
    int Column_Spacing = 160; 



    // Main Menu Title
    tft.setTextSize(Txt_Size_Main_Menu); 
    tft.setTextColor(GREEN, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(20, 10);            // Text Coordinates X, Y
    tft.print(F("Setup Menu 1/2"));  
    
    
    
    //Time Options Menu
    //------------------------------------------------------------
    
   
    int Button_X = Start_X;
    int Button_Y = Start_Y;
   
    Time_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, YELLOW, YELLOW, BLACK, "Time >", 2);
    Time_btn.drawButton(false);
    
    //Sensors Options
    
    Button_X = Start_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    Sensors_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, WHITE, BLACK, "Sensors >", 2);
    Sensors_btn.drawButton(false);

    //Motion Options
    
    Button_X = Start_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    Motion_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "Motion >", 2);
    Motion_btn.drawButton(false);

    //Tracking Options
    
    Button_X = Start_X + (Button_W + Column_Spacing) ;
    Button_Y = Start_Y;    
    
    Tracking_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, MAGENTA, WHITE, "Track >", 2);
    Tracking_btn.drawButton(false);

    //Navigation Options
    
    Button_X = Button_X;
    Button_Y = Start_Y + (Button_H + Menu_Spacing);    
    
    Navigation_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, BLUE, BLUE, WHITE, "NAVI >", 2);
    Navigation_btn.drawButton(false);

    //More Options
    
    Button_X = Button_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    Next_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, YELLOW, YELLOW, BLACK, "Next >", 2);
    Next_btn.drawButton(false);

// Done Button

    Done_btn.initButton(&tft, 230, 278, 80, 40, WHITE, CYAN, BLACK, "Done", 2);
    Done_btn.drawButton(false);
  
}


void React_to_Button_Press_Options() {

    // Action if Time is pressed
    if (Time_btn.justPressed()) {
          Menu_Complete_Time = false;
          tft.fillScreen(BLACK);
          Serial.println(F("Time Screen Selected"));
          Menu_Active = 5;
          Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
          Print_Time_Menu();
          
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Time == false) {
            Sense_Button_Press_Time();
            React_to_Button_Press_Time();
            }
    }
          
    // Action if Sensors is pressed
    if (Sensors_btn.justPressed()) {
          Menu_Complete_Sensors = false;
          tft.fillScreen(BLACK);
          Serial.println(F("Sensors Screen Selected"));
          Menu_Active = 6;
          Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
          Serial.println("RX Sonar Values");
          delay(Receive_Values_Delay);
          Receive_Sensor_Menu1_Data(); 
          Print_Sensors_Menu();
          
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Sensors == false) {
            Sense_Button_Press_Sensors();
            React_to_Button_Press_Sensors();
            }
    }
          

    // Action if Motion is pressed
    if (Motion_btn.justPressed()) {
          Menu_Complete_Motion = false;
          tft.fillScreen(BLACK);
          Serial.println(F("Motion Screen Selected"));
          Menu_Active = 7;
          Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
          Print_Motion_Menu();
         
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Motion == false) {
            Sense_Button_Press_Motion();
            React_to_Button_Press_Motion();
            }
    }


    // Action if Tracking is pressed
    if (Tracking_btn.justPressed()) {
          Menu_Complete_Tracking = false;
          tft.fillScreen(BLACK);
          Serial.println(F("Tracking Screen Selected"));
          Menu_Active = 8;
          Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
          Serial.println("RX Tracking Values");
          delay(Receive_Values_Delay);
          Receive_Tracking_Data();   
          Print_Tracking_Menu();

          
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Tracking == false) {
            Sense_Button_Press_Tracking();
            React_to_Button_Press_Tracking();
            }
    }     

    // Action if Navigation is pressed
    if (Navigation_btn.justPressed()) {
          Menu_Complete_Navigation = false;
          tft.fillScreen(BLACK);
          Serial.println(F("Navigation Screen Selected"));
          Menu_Active = 9;
          Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
          Serial.println("RX Tracking Values");
          delay(Receive_Values_Delay + 300);
          Receive_Navigation_Data();   
          Print_Navigation_Menu();
          
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Navigation == false) {
            Sense_Button_Press_Navigation();
            React_to_Button_Press_Navigation();
            }
    }

    // Action if More is pressed
    if (Next_btn.justPressed()) {
          Menu_Complete_Settings_2 = false;
          tft.fillScreen(BLACK);
          Serial.println(F("TFT Settings 2/2 Screen Selected"));
          Print_Settings_2_Menu();
          
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Settings_2 == false) {
            Sense_Button_Press_Settings_2();
            React_to_Button_Press_Settings_2();
            }
    }


 // Action if Done is pressed
 if (Done_btn.justPressed()) {
         Menu_Complete_Settings = true;
         tft.fillScreen(BLACK);
          Serial.println(F("Main Screen Selected"));
          Menu_Active = 1;
          Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
          Serial.print(F("Mower Status ="));
          Serial.println(Mower_Status_Value);
          if ((Mower_Status_Value == 0) ||(Mower_Status_Value == 1) || (Mower_Status_Value == 2)) {              // 1 = Docked  2 = Parked
            tft.fillScreen(BLACK);

            
            if (Draw_Pictures == 1) bmpDraw("mower1.bmp", 150, 90);      //Draw the mower picture
            delay(100);
            Print_Main_Menu_Graphic();
            Check_For_Active_Alarms();
            }
         if (Mower_Status_Value == 5) Print_Stop_Menu_Graphic();  // 2 = Parked
        }
}
    


void Sense_Button_Press_Options() {
    down = Touch_getXY();
    Time_btn.press          (down && Time_btn.contains(pixel_x, pixel_y));
    Sensors_btn.press       (down && Sensors_btn.contains(pixel_x, pixel_y));
    Motion_btn.press        (down && Motion_btn.contains(pixel_x, pixel_y));
    Tracking_btn.press      (down && Tracking_btn.contains(pixel_x, pixel_y));
    Navigation_btn.press    (down && Navigation_btn.contains(pixel_x, pixel_y));
    Next_btn.press          (down && Next_btn.contains(pixel_x, pixel_y));
    Done_btn.press          (down && Done_btn.contains(pixel_x, pixel_y));

    if (Time_btn.justReleased())        Time_btn.drawButton();
    if (Sensors_btn.justReleased())     Sensors_btn.drawButton();
    if (Motion_btn.justReleased())      Motion_btn.drawButton();
    if (Tracking_btn.justReleased())    Tracking_btn.drawButton();
    if (Navigation_btn.justReleased())  Navigation_btn.drawButton();
    if (Next_btn.justReleased())        Next_btn.drawButton();
    if (Done_btn.justReleased())        Done_btn.drawButton();

}
