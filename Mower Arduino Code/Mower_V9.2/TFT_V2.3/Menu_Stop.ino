// MAIN SCREEN
//*********************************

void Print_Stop_Menu_Graphic() {
   tft.fillScreen(BLACK);
      // Framework for the buttons - setting the start position of the Quick start button wil automatically then space the other buttons

    int Start_X = 80;
    int Start_Y = 130;
    int Menu_Btn_Space = 100;          // Space between the adjacent buttons
    int Button_W = 130;                // width of the button
    int Button_H = 130;                // height of the button

    int Menu_Spacing = 20;            // Distance between the Menu Items (bottom of the last button to the label of the next item)
    int Txt_Size_Main_Menu = 2;



    // Main Menu Title
    tft.setTextSize(Txt_Size_Main_Menu); 
    tft.setTextColor(GREEN, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(20, 10);            // Text Coordinates X, Y
    tft.print(F("ReP_AL Lawn Mower V9.2"));  
    
    
    
    //Re-Print STOP Button
    int Button_X = Start_X;
    int Button_Y = Start_Y;   
    OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "STOP", 2);
    OPTION1_BTN.drawButton(false);

    //Draw Connecting Line
    tft.fillRect( (Button_X + (0.5 * Button_W) ) , Button_Y, 70, 5, WHITE);

    // Reset the Height of the buttons    
    Button_H = Button_H - 70;
    
    // Draw first button on the top row again
    Button_Y = Start_Y - 50;
    
    // Draw Vertical line from the top position again
    tft.fillRect( (Start_X + Button_W + 30) , Button_Y, 5, 150, WHITE);
    
    //Reestart button
    Button_X = Start_X  + (Button_W + (0.5 * Menu_Btn_Space) );
    OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, BLUE, BLACK, YELLOW, "Re-Start", 2);
    OPTION1_BTN.drawButton(false);
   
    //Go Home Button  
    Button_X = Button_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    OPTION2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, YELLOW, BLACK, YELLOW, "Go Home", 2);
    OPTION2_BTN.drawButton(false);

    //Park  
    Button_X = Button_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    OPTION4_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, YELLOW, BLUE, WHITE, "PARK", 2);
    OPTION4_BTN.drawButton(false);

    //Options 
    Button_X = Button_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    OPTION3_BTN.initButton(&tft, 80, 240, Button_W, Button_H, RED, BLACK, WHITE, "Options", 2);
    OPTION3_BTN.drawButton(false);

}
    
 

void React_to_Button_Press_Stop() {

    // Actions if Restart button is pressed
    if (OPTION1_BTN.justPressed()) {
      Mow_Time = 3;
      Menu_Active = 92;
      Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
      Transmit_Mower_Start_Conditions_Quick_Start();
      Menu_Complete_Stop = true;
      Mower_Status_Value = 5;
      Menu_Complete_Mowing = false;
      Print_Confirmation_Text_Mower_Restarting();     
      Print_Mowing_Menu_Graphic();      
      }
      
           


    // Actions if Go Home button is pressed
    if (OPTION2_BTN.justPressed()) {
      Menu_Active = 94;
      Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
      Menu_Complete_Stop = true;
      Menu_Complete_Mowing = true;;
      Mower_Status_Value = 7;         
      }
   
    // Actions if Park button is pressed
    if (OPTION4_BTN.justPressed()) {
         Menu_Complete_Stop = true;
         Menu_Complete_Mowing = true;
         tft.fillScreen(BLACK);
         delay(200);
         Mower_Status_Value = 1;          
        }

    // Actions if Options button is pressed
    if (OPTION3_BTN.justPressed()) {
          tft.fillScreen(BLACK);
          Print_Settings_Menu();
          Menu_Complete_Settings = false;
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Settings == false) {
            Sense_Button_Press_Options();
            React_to_Button_Press_Options();
            }        
        }

}
    
void Sense_Button_Press_Stop() {
    down = Touch_getXY();
    OPTION1_BTN.press                  (down && OPTION1_BTN.contains(pixel_x, pixel_y));    // Restart
    OPTION2_BTN.press                  (down && OPTION2_BTN.contains(pixel_x, pixel_y));   // Options
    OPTION4_BTN.press                     (down && OPTION4_BTN.contains(pixel_x, pixel_y));   // PArk
    OPTION3_BTN.press                  (down && OPTION3_BTN.contains(pixel_x, pixel_y));
    
    if (OPTION1_BTN.justReleased())     OPTION1_BTN.drawButton();
    if (OPTION2_BTN.justReleased())     OPTION2_BTN.drawButton();
    if (OPTION4_BTN.justReleased())        OPTION4_BTN.drawButton();
    if (OPTION3_BTN.justReleased())     OPTION3_BTN.drawButton();
}



void Print_Confirmation_Text_Mower_Restarting() {
      tft.fillScreen(BLACK);
      tft.setTextSize(3); 
      tft.setTextColor(GREEN, BLACK);      //Text Colour/ Background Colour
      tft.setCursor(100, 120);            // Text Coordinates X, Y
      tft.print(F("RE-STARTING MOWER"));  
      delay(1500);  
      tft.fillScreen(BLACK);
      }
