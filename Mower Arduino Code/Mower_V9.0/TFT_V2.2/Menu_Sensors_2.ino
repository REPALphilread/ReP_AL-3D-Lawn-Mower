
// Menu Sensors
//*********************************



void Print_Sensors_Menu_2() {
    tft.fillScreen(BLACK);
    if (Draw_Pictures == 1)   bmpDraw("Sensors.bmp", 70, 20);      //Draw the mower picture
    delay(100); 

      // Framework for the buttons - setting the start position of the Quick start button wil automatically then space the other buttons

    int Start_X = 70;
    int Start_Y = 80;
    int Menu_Btn_Space = 100;          // Space between the adjacent buttons
    int Button_W = 130;                // width of the button
    int Button_H = 60;                // height of the button

    int Menu_Spacing = 20;            // Distance between the Menu Items (bottom of the last button to the label of the next item)
    int Txt_Size_Main_Menu = 2;
    int Column_Spacing = 200; 



    // Main Menu Title
    tft.setTextSize(Txt_Size_Main_Menu); 
    tft.setTextColor(GREEN, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(20, 10);            // Text Coordinates X, Y
    tft.print(F("Sensors 2/2 Menu"));  
    
    
    
    //Menu Sensors
    //------------------------------------------------------------
    
    // Tip
    int Button_X = Start_X;
    int Button_Y = Start_Y;
   
    OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, YELLOW, BLACK, YELLOW, "Tip>", 2);
    OPTION1_BTN.drawButton(false);

    //Bumper
    
    Button_X = Start_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    if (Bumper_Activate_Frnt == 1) OPTION2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, RED, GREEN, BLACK, "Bumper ON", 2);
    if (Bumper_Activate_Frnt == 0) OPTION2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "BumperOFF", 2);
    OPTION2_BTN.drawButton(false);    

// Done5 Button

    Done5_btn.initButton(&tft, 240, 270, 80, 40, WHITE, CYAN, BLACK, "< Back", 2);
    Done5_btn.drawButton(false);
  
}


void React_to_Button_Press_Sensors_2() {

    if (OPTION1_BTN.justPressed()) {
          Menu_Complete_Tip_Setup = false;
          tft.fillScreen(BLACK);
          Print_Tip_Setup_Menu();
           
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Tip_Setup == false) {
            Sense_Button_Press_Tip_Setup();
            React_to_Button_Press_Tip_Setup();

            }
        } 
    


    
    // Action if Bumper is pressed
    if (OPTION2_BTN.justPressed()) {

        bool Changed = 0;
        int Start_X = 70;
        int Start_Y = 80;
        int Button_W = 130;
        int Button_H = 60;
        int Menu_Spacing = 20; 
        int Column_Spacing = 200; 
        
        int Button_X = Start_X;
        int Button_Y = Start_Y + (Button_H + Menu_Spacing); 
      
        if ((Bumper_Activate_Frnt == 1) && (Changed == 0))  {
          Bumper_Activate_Frnt  = 0;
          Changed = 1;
          OPTION2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "BumperOFF", 2);
          OPTION2_BTN.drawButton(false);
          }
        
        if ((Bumper_Activate_Frnt  == 0) && (Changed == 0)) {
          Bumper_Activate_Frnt  = 1;
          Changed = 1;
          OPTION2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, RED, GREEN, BLACK, "Bumper ON", 2);
          OPTION2_BTN.drawButton(false);
        }          
          Menu_Active = 96;
          Send_Menu_Selected_To_Mower_MEGA();
          Transmit_Sensor_Menu1_Values();
          Print_Sensors_Menu_2();
          
    }

 // Action if Done is pressed
 if (Done5_btn.justPressed()) {
         Menu_Complete_Sensors_2 = true;
         tft.fillScreen(BLACK);
         Serial.println(F("Sensors 1/1 Screen Selected"));
         Print_Sensors_Menu();
         delay(200);
         }
}
    


void Sense_Button_Press_Sensors_2() {
    down = Touch_getXY();
    OPTION1_BTN.press             (down && OPTION1_BTN.contains(pixel_x, pixel_y));         // Tip
    OPTION2_BTN.press          (down && OPTION2_BTN.contains(pixel_x, pixel_y));   // Bumper
    Done5_btn.press           (down && Done5_btn.contains(pixel_x, pixel_y));

    if (OPTION1_BTN.justReleased())         OPTION1_BTN.drawButton();
    if (OPTION2_BTN.justReleased())      OPTION2_BTN.drawButton();  
    if (Done5_btn.justReleased())       Done5_btn.drawButton();

}
