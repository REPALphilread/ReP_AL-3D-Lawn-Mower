
// Menu Navigation
//*********************************



void Print_Navigation_Menu() {

    tft.fillScreen(BLACK);
    //if (Draw_Pictures == 1)   bmpDraw("Compass.bmp", 250, 150);      //Draw the mower picture
    delay(100); 

    
    // Framework for the buttons - setting the start position of the Quick start button wil automatically then space the other buttons

    Pos_X1 = 100;
    Pos_Y1 = 80;
    int Menu_Btn_Space = 100;          // Space between the adjacent buttons
    int Button_W = 160;                // width of the button
    int Button_H = 60;                // height of the button
    int Button_Spacing = 5;

    int Menu_Spacing = 15;            // Distance between the Menu Items (bottom of the last button to the label of the next item)
    int Txt_Size_Main_Menu = 2;
    int Column_Spacing = 200; 
    int Offset_Btn = 25;



    // Main Menu Title
    tft.setTextSize(Txt_Size_Main_Menu); 
    tft.setTextColor(GREEN, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(20, 10);            // Text Coordinates X, Y
    tft.print(F("Navigation / Guidance Menu"));  
    
    
    
    //Menu Navigation
    //------------------------------------------------------------
    
    // GPS Settings
    int Button_X = Pos_X1;
    int Button_Y = Pos_Y1;
   
    GPS_btn.initButton(&tft, Pos_X1, Pos_Y1, Button_W, Button_H, YELLOW, YELLOW, BLACK, "GPS >", 2);
    GPS_btn.drawButton(false);


    //Compass Settings
    
    Pos_X2 = Pos_X1;
    Pos_Y2 = Pos_Y1 + (Button_H + Menu_Spacing) + 15;    
    
    Compass_btn.initButton(&tft, Pos_X2, Pos_Y2, Button_W, Button_H, YELLOW, BLUE, WHITE, "Compass >", 2);
    Compass_btn.drawButton(false);
    
    Compass_btn.drawButton(false);


    //GYRO Settings
    
    Pos_X3 = Pos_X1;
    Pos_Y3 = Pos_Y2 + (Button_H + Menu_Spacing) + 15;    
    
    GYRO_btn.initButton(&tft, Pos_X3, Pos_Y3, Button_W, Button_H, YELLOW, WHITE, BLACK, "GYRO >", 2);
    GYRO_btn.drawButton(false);
    
    Compass_btn.drawButton(false);


    //GPS ON OFF
    
    Pos_X4 = Pos_X1 + Column_Spacing + 40;
    Pos_Y4 = Pos_Y1;   
    
    if (GPS_Enabled == 1) GPS_Enabled_ONOFF_btn.initButton(&tft, Pos_X4, Pos_Y4, Button_W, Button_H, WHITE, GREEN, BLACK, "GPS ON", 2);
    if (GPS_Enabled == 0) GPS_Enabled_ONOFF_btn.initButton(&tft, Pos_X4, Pos_Y4, Button_W, Button_H, WHITE, RED, WHITE, "GPS OFF", 2);
    
    GPS_Enabled_ONOFF_btn.drawButton(false);


// Done_Navigation Button

    Done_Navigation_btn.initButton(&tft, 425, 278, 80, 40, WHITE, CYAN, BLACK, "Back", 2);
    Done_Navigation_btn.drawButton(false);
  
}


void React_to_Button_Press_Navigation() {

    // Action if GPS is pressed
    if (GPS_btn.justPressed()) {
          Menu_Complete_GPS_Settings = false;
          tft.fillScreen(BLACK);
          Serial.println(F("GPS Screen Selected"));
          Menu_Active = 15;
          Send_Menu_Selected_To_GPS_NodeMCU();         // Tell the Mower MEGA which menu on the TFT is selected
          Serial.println("RX GPS Values");
          delay(100);
          Serial.println("");
          Receive_GPS_Data();        
          Print_GPS_Menu_Settings();
          
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_GPS_Settings == false) {
            Sense_Button_Press_GPS_Settings();
            React_to_Button_Press_GPS_Settings();
            }
    }


    // Action if Compass is pressed
    if (Compass_btn.justPressed()) {
          Menu_Complete_Compass = false;
          tft.fillScreen(BLACK);
          Serial.println(F("Compass Screen Selected"));
          Menu_Active = 27;
          Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
          delay(Receive_Values_Delay + 900);
          Receive_Compass_Data(); 
          Print_Compass_Menu();
          
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Compass == false) {
            Sense_Button_Press_Compass();
            React_to_Button_Press_Compass();
            }
    }

    // Action if GYRO is pressed
    if (GYRO_btn.justPressed()) {
          Menu_Complete_GYRO = false;
          tft.fillScreen(BLACK);
          Serial.println(F("GYRO Screen Selected"));
          Menu_Active = 28;
          Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
          Serial.println("GYRO Data");
          delay(Receive_Values_Delay + 600);
          Receive_GYRO_Data(); 
          Print_GYRO_Menu();
          
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_GYRO == false) {
            Sense_Button_Press_GYRO();
            React_to_Button_Press_GYRO();
            }
    }


    // Action if GPS is pressed
    if (GPS_btn.justPressed()) {
          Menu_Complete_GPS_Settings = false;
          tft.fillScreen(BLACK);
          Serial.println(F("GPS Screen Selected"));
          Menu_Active = 15;
          Send_Menu_Selected_To_GPS_NodeMCU();         // Tell the Mower MEGA which menu on the TFT is selected
          Serial.println("RX GPS Values");
          delay(100);
          Serial.println("");
          Receive_GPS_Data();        
          Print_GPS_Menu_Settings();
          
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_GPS_Settings == false) {
            Sense_Button_Press_GPS_Settings();
            React_to_Button_Press_GPS_Settings();
            }
    }


    // Action if GPS ONOFF is pressed
    if (GPS_Enabled_ONOFF_btn.justPressed()) {
        
        bool Changed = 0;
        int Button_W = 160;
        int Button_H = 60;
        int Menu_Spacing = 20; 
        int Column_Spacing = 200; 
     
        int Button_X = Pos_X4;
        int Button_Y = Pos_Y4;  
      
        if ((GPS_Enabled == 1) && (Changed == 0))  {
          GPS_Enabled  = 0;
          Changed = 1;
          GPS_Enabled_ONOFF_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "GPS OFF", 2);
          GPS_Enabled_ONOFF_btn.drawButton(false);
          }
        
        if ((GPS_Enabled  == 0) && (Changed == 0)) {
          GPS_Enabled  = 1;
          Changed = 1;
          GPS_Enabled_ONOFF_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, BLACK, GREEN, BLACK, "GPS ON", 2);
          GPS_Enabled_ONOFF_btn.drawButton(false);
        }          
         Menu_Active = 299;
         Send_Menu_Selected_To_Mower_MEGA();
         Transmit_Navigation_Menu_Values();  
         Print_Navigation_Menu();  
         Serial.println("GPS ON/OFF Saved");
    }
   

 // Action if Done is pressed
 if (Done_Navigation_btn.justPressed()) {
         Menu_Complete_Navigation = true;
         Menu_Active = 99;
         Send_Menu_Selected_To_Mower_MEGA();   
         tft.fillScreen(BLACK);
         Print_Settings_Menu();
         delay(200);
         }
}
    




void Sense_Button_Press_Navigation() {
    down = Touch_getXY();
    GPS_btn.press                         (down && GPS_btn.contains(pixel_x, pixel_y));
    Compass_btn.press                     (down && Compass_btn.contains(pixel_x, pixel_y));
    GYRO_btn.press                        (down && GYRO_btn.contains(pixel_x, pixel_y));
    GPS_Enabled_ONOFF_btn.press           (down && GPS_Enabled_ONOFF_btn.contains(pixel_x, pixel_y));
    Done_Navigation_btn.press             (down && Done_Navigation_btn.contains(pixel_x, pixel_y));

    if (GPS_btn.justReleased())               GPS_btn.drawButton();
    if (Compass_btn.justReleased())           Compass_btn.drawButton();
    if (GYRO_btn.justReleased())              GYRO_btn.drawButton();
    if (GPS_Enabled_ONOFF_btn.justReleased()) GPS_Enabled_ONOFF_btn.drawButton();    
    if (Done_Navigation_btn.justReleased())   Done_Navigation_btn.drawButton();

}
