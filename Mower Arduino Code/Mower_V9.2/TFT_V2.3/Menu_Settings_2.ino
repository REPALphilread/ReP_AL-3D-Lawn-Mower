
// Settings Menu
//*********************************

void Print_Settings_2_Menu() {
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
    tft.print(F("Setup Menu 2/2"));  
    
    
    
    //Other Options Menu
    //------------------------------------------------------------
    
   
    int Button_X = Start_X;
    int Button_Y = Start_Y;
   
    OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, RED, YELLOW, BLACK, "Other >", 2);
    OPTION1_BTN.drawButton(false);
    
    //Tests Options
    
    Button_X = Start_X ;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    OPTION2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, BLUE, WHITE, BLACK, "Tests >", 2);
    OPTION2_BTN.drawButton(false);


    //More Options
    
    Button_X = Button_X + (Button_W + Column_Spacing);
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    DONE2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, BLUE, BLUE, WHITE, "< Back", 2);
    DONE2_BTN.drawButton(false);
  
}


void React_to_Button_Press_Settings_2() {

    // Action if TFT is pressed
    if (OPTION1_BTN.justPressed()) {
          Menu_Complete_Setup_Other = false;
          tft.fillScreen(BLACK);
          Serial.println(F("Setup Other Screen Selected"));
          Menu_Active = 30;
          Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected 
          Serial.println("RX Motor Values");
          delay(Receive_Values_Delay +1000);
          Receive_Setup_Other_Data(); 
          Print_Setup_Other_Menu();
          
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Setup_Other == false) {
            Sense_Button_Press_Setup_Other();
            React_to_Button_Press_Setup_Other();
          }
    
    
    
    }
          
    // Action if Tests is pressed
    if (OPTION2_BTN.justPressed()) {
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
 if (DONE2_BTN.justPressed()) {
         Menu_Complete_Settings_2 = true;
         tft.fillScreen(BLACK);
         Serial.println(F("Settings 1 Screen Selected"));
         Print_Settings_Menu();
         }
        
}
    


void Sense_Button_Press_Settings_2() {
    down = Touch_getXY();
    OPTION1_BTN.press (down && OPTION1_BTN.contains(pixel_x, pixel_y));
    OPTION2_BTN.press       (down && OPTION2_BTN.contains(pixel_x, pixel_y));
    DONE2_BTN.press       (down && DONE2_BTN.contains(pixel_x, pixel_y));

    if (OPTION1_BTN.justReleased())   OPTION1_BTN.drawButton();
    if (OPTION2_BTN.justReleased())         OPTION2_BTN.drawButton();
    if (DONE2_BTN.justReleased())         DONE2_BTN.drawButton();

}
