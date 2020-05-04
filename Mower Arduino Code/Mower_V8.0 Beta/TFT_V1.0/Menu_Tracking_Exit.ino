void Print_Tracking_Exit_Menu() {  

    if (Draw_Pictures == 1)   bmpDraw("Exit12CCW.bmp", 60, 50);      //Draw the mower picture
    delay(100); 

   
    // Framework for the + - buttons - setting the start position of the + button wil automatically then space the - button

    int Menu_Btn_Space = 80;          // Space between the text and the +ve button
    int Button_W = 100;                // width of the button
    int Button_H = 40;                // height of the button
    int Button_Spacing = 5;           // Space between the -ve and +ve buttons
    int Txt_Size_Label = 1;           // Test size iof the label above the value
    Txt_Size_Value = 2;               // Text size of the value that is changing
    int Menu_Spacing = 65;            // Distance between the Menu Items (bottom of the last button to the label of the next item)
    int Offset_Btn = 25;
    int Txt_Size_Main_Menu = 2;
    int Column_Spacing = 200;         // Distance between the Left Hand and Right Hand Columns


    // Main Menu Title
    tft.setTextSize(Txt_Size_Main_Menu); 
    tft.setTextColor(GREEN, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(10, 10);            // Text Coordinates X, Y
    tft.print(F("Exit and Tracking Direction Settings"));  
    
    //Exit Zone 1
    //------------------------------------------------------------
    
    Button_W   = 50;
    Pos_X2     = 220;
    Pos_Y2     = 130;
    Value_Y2  = Pos_Y2 + Offset_Btn;           // Y Position of the item
    Value_2   = Track_Wire_Zone_1_Cycles;       // Value to be modified in the menu

    // Label
    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);            // Text Colour/ Background Colour
    tft.setCursor(Pos_X2, Pos_Y2);            // Text Coordinates X, Y
    tft.print(F("Exit Zone 1 / Cycles"));  

    // Value Number
    Pos_Y2 = Pos_Y2 + Offset_Btn;
    tft.setTextSize(Txt_Size_Value); 
    tft.setTextColor(RED, BLACK);                 //Text Colour/ Background Colour
    tft.setCursor(Pos_X2, Pos_Y2);            // Text Coordinates X, Y
    tft.print(Value_2);

    // Buttons
    int Button_X = Pos_X2 + Menu_Btn_Space;
    int Button_Y = Pos_Y2 + (0.2 * Button_H);    
    up2_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    down2_btn.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);
    up2_btn.drawButton(false);
    down2_btn.drawButton(false);



    //Exit Zone 2
    //------------------------------------------------------------
    
    Button_W  = 50;
    Pos_X3     = 20;
    Pos_Y3     = 130;
    Value_3   = Track_Wire_Zone_2_Cycles;       // Value to be modified in the menu

    // Label
    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);            // Text Colour/ Background Colour
    tft.setCursor(Pos_X3, Pos_Y3);            // Text Coordinates X, Y
    tft.print(F("Exit Zone 2 / Cycles"));  

    // Value Number
    Pos_Y3  = Pos_Y3 + Offset_Btn;           // Y Position of the item
    tft.setTextSize(Txt_Size_Value); 
    tft.setTextColor(RED, BLACK);                 //Text Colour/ Background Colour
    tft.setCursor(Pos_X3, Pos_Y3);            // Text Coordinates X, Y
    tft.print(Value_3);    

    // Buttons
    Button_X = Pos_X3 + Menu_Btn_Space;
    Button_Y = Value_Y2 + (0.2 * Button_H);
    up3_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    down3_btn.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);
    up3_btn.drawButton(false);
    down3_btn.drawButton(false);



    
    
    //Tracking Direction
    //------------------------------------------------------------
    
    Pos_X1 = 40;                           // Starting X Point.
    Pos_Y1 = 220;                           // Starting Y Point
    Button_W = 130;

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Pos_X1, Pos_Y1);            // Text Coordinates X, Y
    tft.print(F("Track Wire to Start Point"));  

    Button_X1 = Pos_X1 + ( 0.5 * Button_W);
    Button_Y1 = Pos_Y1 + Offset_Btn + (0.2 * Button_H);
    
    if (CCW_Tracking_To_Start == 0) Tracking_Rotation_btn.initButton(&tft, Button_X1, Button_Y1, Button_W, Button_H, WHITE, BLUE, WHITE, "CW", 2);
    if (CCW_Tracking_To_Start == 1)  Tracking_Rotation_btn.initButton(&tft, Button_X1, Button_Y1, Button_W, Button_H, WHITE, MAGENTA, BLACK, "CCW", 2);
    Tracking_Rotation_btn.drawButton(false);


// Save Button

    Save_Tracking_Exit_btn.initButton(&tft, 400, 282, 80, 40, WHITE, CYAN, BLACK, "Save", 2);
    Save_Tracking_Exit_btn.drawButton(false);


}


void React_to_Button_Tracking_Exit() {

 // If the SONAR Sensor ON/OFF Button is pressed
 if (Tracking_Rotation_btn.justPressed() ) {

        int Button_W = 130;                // width of the button
        int Button_H = 40;                // height of the button
        bool Changed = 0;

        if ((CCW_Tracking_To_Start == 1) && (Changed == 0))  {
          CW_Tracking_To_Start = 1;
          CCW_Tracking_To_Start = 0;
          CCW_Tracking_To_Charge = 1;
          CW_Tracking_To_Charge = 0;
          
          Changed = 1;
          Tracking_Rotation_btn.initButton(&tft, Button_X1, Button_Y1, Button_W, Button_H, WHITE, BLUE, WHITE, "CW", 2);
          Tracking_Rotation_btn.drawButton(false);
          }
        
        if ((CCW_Tracking_To_Start == 0) && (Changed == 0)) {
          CW_Tracking_To_Start = 0;
          CCW_Tracking_To_Start = 1;
          CCW_Tracking_To_Charge = 0;
          CW_Tracking_To_Charge = 1;
          
          Changed = 1;
          Tracking_Rotation_btn.initButton(&tft, Button_X1, Button_Y1, Button_W, Button_H, WHITE, MAGENTA, BLACK, "CCW", 2);
          Tracking_Rotation_btn.drawButton(false);
        }
  delay(200);
 }



//If the Button 2 is pressed (up or down)
 if ((up2_btn.justPressed() )  || (down2_btn.justPressed())) {
        
        Value_All = Track_Wire_Zone_1_Cycles;
        Value_X_All = Pos_X2;
        Value_Y_All = Pos_Y2;
    
    // Actions if UP is pressed
    if (up2_btn.justPressed()) {
        Clear_Old_Value_Tracking_Exit();       
        up2_btn.drawButton(true);
        Value_All = Value_All + 100;
        Track_Wire_Zone_1_Cycles = Value_All;
        Print_New_Value_Tracking_Exit();
        }


    // Action if down is pressed
    if (down2_btn.justPressed()) {
        Clear_Old_Value_Tracking_Exit();
        down2_btn.drawButton(true);
        Value_All = Value_All - 100;
        if (Value_All < 0) Value_All = 100;
        Track_Wire_Zone_1_Cycles = Value_All;
        Print_New_Value_Tracking_Exit();
        }
    }


//If the Button 3 is pressed (up or down)
 if ((up3_btn.justPressed() )  || (down3_btn.justPressed())) {
        
        Value_All = Track_Wire_Zone_2_Cycles;
        Value_X_All = Pos_X3;
        Value_Y_All = Pos_Y3;
    
    // Actions if UP is pressed
    if (up3_btn.justPressed()) {
        Clear_Old_Value_Tracking_Exit();       
        up3_btn.drawButton(true);
        Value_All = Value_All + 100;
        Track_Wire_Zone_2_Cycles = Value_All;
        Print_New_Value_Tracking_Exit();
        }


    // Action if down is pressed
    if (down3_btn.justPressed()) {
        Clear_Old_Value_Tracking_Exit();
        down3_btn.drawButton(true);
        Value_All = Value_All - 100;
        if (Value_All < 0) Value_All = 100;
        Track_Wire_Zone_2_Cycles = Value_All;
        Print_New_Value_Tracking_Exit();
        }
    }

 
 // Action if Tracking Save is pressed
 if (Save_Tracking_Exit_btn.justPressed()) {
         Menu_Complete_Tracking_Exit = true;
         tft.fillScreen(BLACK);
         Serial.println(F("Tracking Data Saved and TX"));
         Menu_Active = 917;
         Send_Menu_Selected_To_Mower_MEGA();
         Transmit_Saved_Tracking_Exit_Values();
         Print_Tracking_Menu();
         }  

        
}





void Clear_Old_Value_Tracking_Exit() {
        // Draws over the previous Value in Black text to clear it.... !?
        tft.setTextSize(Txt_Size_Value); 
        tft.setTextColor(BLACK, BLACK);      //Text Colour/ Background Colour
        tft.setCursor(Value_X_All, Value_Y_All);            // Text Coordinates X, Y
        tft.print(Value_All);
        }

void Print_New_Value_Tracking_Exit() {        

        tft.setTextSize(Txt_Size_Value); 
        tft.setTextColor(RED, BLACK);      //Text Colour/ Background Colour
        tft.setCursor(Value_X_All, Value_Y_All);            // Text Coordinates X, Y     
        tft.print(Value_All);
        }




void Sense_Button_Tracking_Exit() {
    down = Touch_getXY();
    Tracking_Rotation_btn.press   (down && Tracking_Rotation_btn.contains(pixel_x, pixel_y));
    up2_btn.press                 (down && up2_btn.contains(pixel_x, pixel_y));
    down2_btn.press               (down && down2_btn.contains(pixel_x, pixel_y));
    up3_btn.press                 (down && up3_btn.contains(pixel_x, pixel_y));
    down3_btn.press               (down && down3_btn.contains(pixel_x, pixel_y));
    Save_Tracking_Exit_btn.press  (down && Save_Tracking_Exit_btn.contains(pixel_x, pixel_y));

    if (Tracking_Rotation_btn.justReleased())   Tracking_Rotation_btn.drawButton();
    if (up2_btn.justReleased())                 up2_btn.drawButton();
    if (down2_btn.justReleased())               down2_btn.drawButton();
    if (up3_btn.justReleased())                 up3_btn.drawButton();
    if (down3_btn.justReleased())               down3_btn.drawButton();
    if (Save_Tracking_Exit_btn.justReleased())  Save_Tracking_Exit_btn.drawButton();
}
