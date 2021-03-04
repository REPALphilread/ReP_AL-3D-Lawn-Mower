
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
    tft.print(F("ReP_AL Lawn Mower V9.2"));  
    
    
    
    //Button Quick Start and Exit Dock
    //------------------------------------------------------------
    
   
    int Button_X = Start_X;
    int Button_Y = Start_Y;
   
    OPTION_A_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, YELLOW, YELLOW, BLACK, "Quick Go", 2);
    OPTION_A_BTN.drawButton(false);
    
    //Exit Dock Button and Position
    
    Button_X = Start_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    OPTION_B_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, WHITE, BLACK, "Exit Dock", 2);
    OPTION_B_BTN.drawButton(false);

    //Options Button and Position
    
    Button_X = Start_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    OPTION_C_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, RED, RED, WHITE, "Setup", 2);
    OPTION_C_BTN.drawButton(false);
  
}


void React_to_Button_Press_Main() {

    // Actions if Quick Start is pressed
    if (OPTION_A_BTN.justPressed()) {
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
    if (OPTION_B_BTN.justPressed()) {
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
    if (OPTION_C_BTN.justPressed()) {
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
    OPTION_A_BTN.press    (down && OPTION_A_BTN.contains(pixel_x, pixel_y));      // Quick Start
    OPTION_B_BTN.press  (down && OPTION_B_BTN.contains(pixel_x, pixel_y));        // Exit Dock
    OPTION_C_BTN.press    (down && OPTION_C_BTN.contains(pixel_x, pixel_y));      // Options/Setup Button

    if (OPTION_A_BTN.justReleased())     OPTION_A_BTN.drawButton();
    if (OPTION_B_BTN.justReleased())     OPTION_B_BTN.drawButton();
    if (OPTION_C_BTN.justReleased())     OPTION_C_BTN.drawButton();


}
