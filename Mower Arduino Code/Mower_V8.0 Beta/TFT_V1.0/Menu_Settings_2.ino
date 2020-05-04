
// Settings Menu
//*********************************

void Print_Settings_2_Menu() {

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
    tft.print(F("Setup Menu 2/2"));  
    
    
    
    //Time Options Menu
    //------------------------------------------------------------
    
   
    int Button_X = Start_X;
    int Button_Y = Start_Y;
   
    TFT_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, RED, YELLOW, BLACK, "TFT >", 2);
    TFT_btn.drawButton(false);
    
    //Tests Options
    
    Button_X = Start_X ;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    Tests_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, BLACK, WHITE, "Tests >", 2);
    Tests_btn.drawButton(false);


    //More Options
    
    Button_X = Button_X + (Button_W + Column_Spacing);
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    Done2_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, BLUE, BLUE, WHITE, "< Back", 2);
    Done2_btn.drawButton(false);
  
}


void React_to_Button_Press_Settings_2() {

    // Action if TFT is pressed
    if (TFT_btn.justPressed()) {
          Menu_Complete_TFT_Setup = false;
          tft.fillScreen(BLACK);
          Serial.println(F("TFT Options Screen Selected"));
          Print_TFT_Menu();
          
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_TFT_Setup == false) {
            Sense_Button_Press_TFT_Setup();
            React_to_Button_Press_TFT_Setup();
            }
    }
          
    // Action if Tests is pressed
    if (Tests_btn.justPressed()) {
          Menu_Complete_Tests = false;
          tft.fillScreen(BLACK);
          Serial.println(F("Test Screen 2/2 Selected"));
          Print_Tests_Menu();
          
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Tests == false) {
            Sense_Button_Press_Tests();
            React_to_Button_Press_Tests();
            }
    }


 // Action if Done is pressed
 if (Done2_btn.justPressed()) {
         Menu_Complete_Settings_2 = true;
         tft.fillScreen(BLACK);
         Serial.println(F("Settings 1 Screen Selected"));
         Print_Settings_Menu();
         }
        
}
    


void Sense_Button_Press_Settings_2() {
    down = Touch_getXY();
    TFT_btn.press         (down && TFT_btn.contains(pixel_x, pixel_y));
    Tests_btn.press       (down && Tests_btn.contains(pixel_x, pixel_y));
    Done2_btn.press       (down && Done2_btn.contains(pixel_x, pixel_y));

    if (TFT_btn.justReleased())        TFT_btn.drawButton();
    if (Tests_btn.justReleased())      Tests_btn.drawButton();
    if (Done2_btn.justReleased())      Done2_btn.drawButton();

}
