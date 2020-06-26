
// Menu cretaed when the Quick Go button is pressed on the main menu


void Print_Quick_Go_Menu() {
    tft.fillScreen(BLACK);
      // Framework for the buttons - setting the start position of the Quick start button wil automatically then space the other buttons

    int Start_X = 70;
    int Start_Y = 80;
    int Menu_Btn_Space = 30;          // Space between the buttons
    int Button_W = 130;                // width of the button
    int Button_H = 60;                // height of the button

    int Menu_Spacing = 20;            // Distance between the Menu Items (bottom of the last button to the label of the next item)
    int Txt_Size_Main_Menu = 2;



    // Main Menu Title
    tft.setTextSize(Txt_Size_Main_Menu); 
    tft.setTextColor(GREEN, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(20, 10);            // Text Coordinates X, Y
    tft.print(F("ReP_AL Lawn Mower V8.3"));  
    
    
    
    //Re-Print Quick Go
    int Button_X = Start_X;
    int Button_Y = Start_Y;
    Quick_S_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, YELLOW, YELLOW, BLACK, "Quick Go", 2);
    Quick_S_btn.drawButton(false);

    //Draw Connecting Line
    tft.fillRect( (Button_X + (0.5 * Button_W) ) , Button_Y, 70, 5, WHITE);
    tft.fillRect( (Button_X + (Button_W + Menu_Btn_Space) ) , Button_Y, 5, 200, WHITE);

    // Reset the Height of the buttons
    Button_H = Button_H - 15;
    
    
    //Go Now Button
    Button_X = Start_X  + (Button_W + Menu_Btn_Space);
    Button_Y = Button_Y;    
    Go_Now_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, BLUE, RED, WHITE, "Just Go", 2);
    Go_Now_btn.drawButton(false);
   
    //1 hr mow Button  
    Button_X = Button_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    hr1_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, YELLOW, YELLOW, BLACK, "1hr Mow", 2);
    hr1_btn.drawButton(false);

    //2 hr mow Button  
    Button_X = Button_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);   
    hr2_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, MAGENTA, MAGENTA, YELLOW, "2hr Mow", 2);
    hr2_btn.drawButton(false);

    //Max mow Button  
    Button_X = Button_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    Max_Mow_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, RED, YELLOW, BLACK, "Max Mow", 2);
    Max_Mow_btn.drawButton(false);


    // Cancel Button
    Cancel_QG_btn.initButton(&tft, 425, 278, 80, 40, WHITE, CYAN, BLACK, "Cancel", 2);
    Cancel_QG_btn.drawButton(false);
}


void React_to_Button_Press_Quick_Go() {

    // Actions Just Go is pressed
    if (Go_Now_btn.justPressed()) {
       Menu_Complete_Quick_Start = true;
       Menu_Complete_Main = true;
       Mow_Time = 3;
       Menu_Active = 92;
       Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
       Transmit_Mower_Start_Conditions_Quick_Start();
       Print_Confirmation_Text_Quick_Start();        
        }

    // Actions 1h is pressed
    if (hr1_btn.justPressed()) {
       Menu_Complete_Quick_Start = true;
       Menu_Complete_Main = true;
       Mow_Time = 1;
       Mower_Error_Value = 0;
       Mower_Status_Value = 5;
       Menu_Active = 92;
       Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
       Transmit_Mower_Start_Conditions_Quick_Start();
       Print_Confirmation_Text_Quick_Start();       
       }


    // Action if 2 hr is pressed
    if (hr2_btn.justPressed()) {
       Menu_Complete_Quick_Start = true;
       Menu_Complete_Main = true;
       Mow_Time = 2;
       Mower_Error_Value = 0;
       Mower_Status_Value = 5;
       Menu_Active = 92;
       Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
       Transmit_Mower_Start_Conditions_Quick_Start();
       Print_Confirmation_Text_Quick_Start();       
       }

    // Action if max mow is pressed
    if (Max_Mow_btn.justPressed()) {
       Menu_Complete_Quick_Start = true;
       Menu_Complete_Main = true;
       Mow_Time = 3;
       Mower_Error_Value = 0;
       Mower_Status_Value = 5;
       Menu_Active = 92;
       Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
       Transmit_Mower_Start_Conditions_Quick_Start();
       Print_Confirmation_Text_Quick_Start();       
       }

    // Action if cancel is pressed
    if (Cancel_QG_btn.justPressed()) {
         Menu_Complete_Quick_Start = true;
         tft.fillScreen(BLACK);
         Serial.println(F("Main Screen Selected"));
         Menu_Active = 1;
         Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
         delay(200);
         if ((Mower_Status_Value == 0) ||(Mower_Status_Value == 1) || (Mower_Status_Value == 2)) {              // 1 = Docked  2 = Parked
            tft.fillScreen(BLACK);
            if (Draw_Pictures == 1) bmpDraw("mower1.bmp", 150, 90);      //Draw the mower picture
            delay(100);
            Print_Main_Menu_Graphic();
            Check_For_Active_Alarms();
            }
        }
}


void Sense_Button_Press_Quick_Go() {
    down = Touch_getXY();
    Go_Now_btn.press    (down && Go_Now_btn.contains(pixel_x, pixel_y));
    hr1_btn.press       (down && hr1_btn.contains(pixel_x, pixel_y));
    hr2_btn.press       (down && hr2_btn.contains(pixel_x, pixel_y));
    Max_Mow_btn.press   (down && Max_Mow_btn.contains(pixel_x, pixel_y));
    Cancel_QG_btn.press (down && Cancel_QG_btn.contains(pixel_x, pixel_y));

    if (Go_Now_btn.justReleased())    Go_Now_btn.drawButton();
    if (hr1_btn.justReleased())       hr1_btn.drawButton();
    if (hr2_btn.justReleased())       hr2_btn.drawButton();
    if (Max_Mow_btn.justReleased())   Max_Mow_btn.drawButton();
    if (Cancel_QG_btn.justReleased()) Cancel_QG_btn.drawButton();
    
}


void Print_Confirmation_Text_Quick_Start() {
      tft.fillScreen(BLACK);
     
      // Draw White Circle with Green Arrow Up
      tft.fillCircle(70, 150, 70, GREEN);                       // X, Y, Radius
      tft.fillTriangle(30,180 , 110,180, 70,100,  WHITE);       // Point left XY, Point right XY, Point top XY
      tft.drawTriangle(30,180 , 110,180, 70,100,  BLACK);       // Point left XY, Point right XY, Point top XY

      // Print Text Information
      tft.setTextSize(5); 
      tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
      tft.setCursor(150, 95);            // Text Coordinates X, Y
      tft.print(F("QUICK START"));  
      tft.setTextSize(3); 
      tft.setCursor(150, 150);            // Text Coordinates X, Y
      tft.print(F("Mow Time: "));  
      if (Mow_Time < 3) tft.print(Mow_Time); 
      if (Mow_Time == 3) tft.print("Max");  
      tft.print(F(" hrs"));
      delay(2000);  
      tft.fillScreen(BLACK);
      }
