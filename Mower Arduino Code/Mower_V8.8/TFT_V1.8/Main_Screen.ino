
// MAIN SCREEN
//*********************************

void Print_Main_Menu_Graphic() {

    // Framework for the buttons - setting the start position of the Quick start button wil automatically then space the other buttons

    int Start_X = 90;
    int Start_Y = 80;
    int Menu_Btn_Space = 100;          // Space between the adjacent buttons
    int Button_W = 130;                // width of the button
    int Button_H = 60;                // height of the button

    int Menu_Spacing = 20;            // Distance between the Menu Items (bottom of the last button to the label of the next item)
    int Txt_Size_Main_Menu = 2;



    // Main Menu Title
    tft.setTextSize(Txt_Size_Main_Menu); 
    tft.setTextColor(GREEN, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(20, 10);            // Text Coordinates X, Y
    tft.print(F("ReP_AL Lawn Mower V8.8"));  
    
    
    
    //Button Quick Start and Exit Dock
    //------------------------------------------------------------
    
   
    int Button_X = Start_X;
    int Button_Y = Start_Y;
   
    Quick_S_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, YELLOW, YELLOW, BLACK, "Quick Go", 2);
    Quick_S_btn.drawButton(false);
    
    //Exit Dock Button and Position
    
    Button_X = Start_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    Exit_Dock_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, WHITE, BLACK, "Exit Dock", 2);
    Exit_Dock_btn.drawButton(false);

    //Options Button and Position
    
    Button_X = Start_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    Options_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, RED, RED, WHITE, "Setup", 2);
    Options_btn.drawButton(false);
  
}


void React_to_Button_Press_Main() {

    // Actions if Quick Go is pressed
    if (Quick_S_btn.justPressed()) {
          Menu_Complete_Quick_Start = false;
          tft.fillScreen(BLACK);
          Serial.println(F("Quick Go Screen Selected"));
          Menu_Active = 2;
          Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected               
          Print_Quick_Go_Menu();
          //Print_Battery_Graphic();          
          
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Quick_Start == false) {
            Sense_Button_Press_Quick_Go();
            React_to_Button_Press_Quick_Go();
            }
        }


    // Action if Exit Dock is pressed
    if (Exit_Dock_btn.justPressed()) {
          Menu_Complete_Exit_Dock = false;
          tft.fillScreen(BLACK);
          Serial.println(F("Exit Dock Screen Selected"));
          Menu_Active = 3;
          Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected               
          Print_Exit_Dock_Menu();
          //Print_Battery_Graphic();          
          
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Exit_Dock == false) {
            Sense_Button_Press_Exit_Dock();
            React_to_Button_Press_Exit_Dock();
            }       
        }

    // Action if Options is pressed
    if (Options_btn.justPressed()) {
          Menu_Complete_Settings = false;
          tft.fillScreen(BLACK);
          Serial.println(F("Options Screen Selected"));
          Menu_Active = 4;
          Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected     
          Print_Settings_Menu();
          
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Settings == false) {
            Sense_Button_Press_Options();
            React_to_Button_Press_Options();
            }
          
          
        }
}
    


void Sense_Button_Press_Main() {
    down = Touch_getXY();
    Quick_S_btn.press    (down && Quick_S_btn.contains(pixel_x, pixel_y));
    Exit_Dock_btn.press  (down && Exit_Dock_btn.contains(pixel_x, pixel_y));
    Options_btn.press    (down && Options_btn.contains(pixel_x, pixel_y));

    if (Quick_S_btn.justReleased())     Quick_S_btn.drawButton();
    if (Exit_Dock_btn.justReleased())   Exit_Dock_btn.drawButton();
    if (Options_btn.justReleased())     Options_btn.drawButton();


}
