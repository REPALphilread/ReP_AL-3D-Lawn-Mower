
// Settings Menu
//*********************************

void Print_Tracking_Menu() {

      // Framework for the buttons - setting the start position of the Quick start button wil automatically then space the other buttons

    tft.fillScreen(BLACK);
    int Start_X = 100;
    int Start_Y = 80;
    int Menu_Btn_Space = 100;          // Space between the adjacent buttons
    int Button_W = 150;                // width of the button
    int Button_H = 60;                // height of the button

    int Menu_Spacing = 20;            // Distance between the Menu Items (bottom of the last button to the label of the next item)
    int Txt_Size_Main_Menu = 2;
    int Column_Spacing = 100; 



    // Main Menu Title
    tft.setTextSize(Txt_Size_Main_Menu); 
    tft.setTextColor(GREEN, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(20, 10);            // Text Coordinates X, Y
    tft.print(F("Tracking Settinsgs"));  
    
    
    
    //Exit 1&2 Options Menu
    //------------------------------------------------------------
    
   
    int Button_X = Start_X;
    int Button_Y = Start_Y;
   
    OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, RED, YELLOW, BLACK, "Exit1&2>", 2);
    OPTION1_BTN.drawButton(false);
    
    //Find Wire
    
    Button_X = Start_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    OPTION2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, BLUE, WHITE, BLACK, "FindWire>", 2);
    OPTION2_BTN.drawButton(false);

    //PID
    
    Button_X = Start_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    OPTION3_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, RED, MAGENTA, WHITE, "PID >", 2);
    OPTION3_BTN.drawButton(false);

    //Spare Button
    
    Button_X = Start_X + (Button_W + Column_Spacing) ;
    Button_Y = Start_Y;    
    
    Spare_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, MAGENTA, BLACK, WHITE, "Spare >", 2);
    Spare_btn.drawButton(false);
    
    
    //Dock ON/OFF
    
    Button_X = Start_X + (Button_W + Column_Spacing);
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    Pos_X1 = Button_X;
    Pos_Y1 = Button_Y;

    
    if (Use_Charging_Station == 1) OPTION4_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "Dock ON", 2);
    if (Use_Charging_Station == 0) OPTION4_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "Dock OFF", 2);
    
    OPTION4_BTN.drawButton(false);

// Done Button

    Done6_btn.initButton(&tft, 425, 278, 80, 40, WHITE, CYAN, BLACK, "Done", 2);
    Done6_btn.drawButton(false);
  
}


void React_to_Button_Press_Tracking() {


    // Action if Exit Point is pressed
    if (OPTION1_BTN.justPressed()) {
          Menu_Complete_Tracking_Exit = false;
          tft.fillScreen(BLACK);
          Print_Tracking_Exit_Menu();

          while (Menu_Complete_Tracking_Exit == false) {
            Sense_Button_Tracking_Exit();
            React_to_Button_Tracking_Exit();
            }
    }
          
    // Action if Find Wire is pressed
    if (OPTION2_BTN.justPressed()) {
          Menu_Complete_Find_Wire = false;
          tft.fillScreen(BLACK);
          Print_Track_Find_Wire_Menu();
          
          while (Menu_Complete_Find_Wire == false) {
            Sense_Button_Press_Track_Find_Wire();
            React_to_Button_Press_Track_Find_Wire();
            }
    }
          

    // Action if Track PID is pressed
    if (OPTION3_BTN.justPressed()) {
          Menu_Complete_Track_PID = false;
          tft.fillScreen(BLACK);
          Serial.println(F("Tracking PID Menu Selected"));
          Menu_Active = 19;
          Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
          Serial.println("RX Tracking PID");
          delay(Receive_Values_Delay + 200);
          Receive_Track_PID_Data();           
          
          Print_Track_PID_Menu();
         
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Track_PID == false) {
            Sense_Button_Press_Track_PID();
            React_to_Button_Press_Track_PID();
            }
    }



    // Action if Dock ON OFF pressed
    if (OPTION4_BTN.justPressed()) {
        
        bool Changed = 0;
        
        int Button_X = Pos_X1;
        int Button_Y = Pos_Y1;  
        int Button_W = 150;                // width of the button
        int Button_H = 60;                // height of the button    
          
        if ((Use_Charging_Station == 1) && (Changed == 0))  {
          Use_Charging_Station  = 0;
          Changed = 1;
          OPTION4_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "Dock OFF", 2);
          OPTION4_BTN.drawButton(false);
          }
        
        if ((Use_Charging_Station  == 0) && (Changed == 0)) {
          Use_Charging_Station  = 1;
          Changed = 1;
          OPTION4_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, RED, GREEN, BLACK, "Dock ON", 2);
          OPTION4_BTN.drawButton(false);
        }          
          Menu_Active = 98;
          Send_Menu_Selected_To_Mower_MEGA();
          Transmit_Tracking_Menu_Values();
          Print_Tracking_Menu();
    }  


 // Action if Done is pressed
 if (Done6_btn.justPressed()) {
         Menu_Complete_Tracking = true;
         tft.fillScreen(BLACK);
         Serial.println(F("Tracking Data Saved and TX"));
         Menu_Active = 98;
         Send_Menu_Selected_To_Mower_MEGA();
         Print_Settings_Menu();
         }  

}
    


void Sense_Button_Press_Tracking() {
    down = Touch_getXY();
    OPTION1_BTN.press                (down && OPTION1_BTN.contains(pixel_x, pixel_y));   // Exit Point
    OPTION2_BTN.press                 (down && OPTION2_BTN.contains(pixel_x, pixel_y));   // Find Wire
    OPTION3_BTN.press                 (down && OPTION3_BTN.contains(pixel_x, pixel_y));
    Spare_btn.press                     (down && Spare_btn.contains(pixel_x, pixel_y));
    OPTION4_BTN.press                (down && OPTION4_BTN.contains(pixel_x, pixel_y));
    Done6_btn.press             (down && Done6_btn.contains(pixel_x, pixel_y));

    if (OPTION1_BTN.justReleased())        OPTION1_BTN.drawButton();
    if (OPTION2_BTN.justReleased())         OPTION2_BTN.drawButton();
    if (OPTION3_BTN.justReleased())         OPTION3_BTN.drawButton();
    if (Spare_btn.justReleased())             Spare_btn.drawButton();
    if (OPTION4_BTN.justReleased())        OPTION4_BTN.drawButton();
    if (Done6_btn.justReleased())     Done6_btn.drawButton();

}
