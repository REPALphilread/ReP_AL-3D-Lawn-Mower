void Print_Track_Find_Wire_Menu() {  

    tft.fillScreen(BLACK);
    if (Draw_Pictures == 1)   bmpDraw("FindWire.bmp", 200, 80);      //Draw the mower picture
    delay(100); 

   
    // Framework for the + - buttons - setting the start position of the + button wil automatically then space the - button

    int Menu_Btn_Space = 75;          // Space between the text and the +ve button
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
    tft.print(F("Find Wire Settings"));  
    
    //Track Forward Cycles
    //------------------------------------------------------------
    
    Button_W   = 50;
    Pos_X2     = 30;
    Pos_Y2     = 100;
    Value_Y2  = Pos_Y2 + Offset_Btn;           // Y Position of the item
    Value_2   = Max_Cycle_Wire_Find;       // Value to be modified in the menu

    // Label
    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);            // Text Colour/ Background Colour
    tft.setCursor(Pos_X2, Pos_Y2);            // Text Coordinates X, Y
    tft.print(F("2) Find Wire Forward Track / Cycles"));  

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



    //Reverse Back Cycles
    //------------------------------------------------------------
    
    Button_W  = 50;
    Pos_X3     = 240;
    Pos_Y3     = 40;
    Value_3   = Max_Cycle_Wire_Find_Back;       // Value to be modified in the menu

    // Label
    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);            // Text Colour/ Background Colour
    tft.setCursor(Pos_X3, Pos_Y3);            // Text Coordinates X, Y
    tft.print(F("3) Reverse Back Onto Wire / Cycles"));  

    // Value Number
    Pos_Y3  = Pos_Y3 + Offset_Btn;           // Y Position of the item
    tft.setTextSize(Txt_Size_Value); 
    tft.setTextColor(RED, BLACK);                 //Text Colour/ Background Colour
    tft.setCursor(Pos_X3, Pos_Y3);            // Text Coordinates X, Y
    tft.print(Value_3);    

    // Buttons
    Button_X = Pos_X3 + Menu_Btn_Space;
    Button_Y = Pos_Y3 + (0.2 * Button_H);
    up3_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    down3_btn.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);
    up3_btn.drawButton(false);
    down3_btn.drawButton(false);


    //Compass Home Direction
    //------------------------------------------------------------
    
    Button_W  = 50;
    Pos_X4     = 75;
    Pos_Y4     = 200;
    Value_4   = Home_Wire_Compass_Heading;       // Value to be modified in the menu

    // Label
    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);            // Text Colour/ Background Colour
    tft.setCursor(Pos_X4, Pos_Y4);            // Text Coordinates X, Y
    tft.print(F("1) Home Compass Heading Degrees"));  

    // Value Number
    Pos_Y4  = Pos_Y4 + Offset_Btn;           // Y Position of the item
    tft.setTextSize(Txt_Size_Value); 
    tft.setTextColor(RED, BLACK);                 //Text Colour/ Background Colour
    tft.setCursor(Pos_X4, Pos_Y4);            // Text Coordinates X, Y
    tft.print(Value_4);    

    // Buttons
    Button_X = Pos_X4 + Menu_Btn_Space;
    Button_Y = Pos_Y4 + (0.2 * Button_H);
    up4_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    down4_btn.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);
    up4_btn.drawButton(false);
    down4_btn.drawButton(false);
    
    

// Save Button

    Save_Track_Find_Wire_btn.initButton(&tft, 400, 282, 80, 40, WHITE, CYAN, BLACK, "Save", 2);
    Save_Track_Find_Wire_btn.drawButton(false);


}


void React_to_Button_Press_Track_Find_Wire() {



//If the Button 2 is pressed (up or down)
 if ((up2_btn.justPressed() )  || (down2_btn.justPressed())) {
        
        Value_All = Max_Cycle_Wire_Find;
        Value_X_All = Pos_X2;
        Value_Y_All = Pos_Y2;
    
    // Actions if UP is pressed
    if (up2_btn.justPressed()) {
        Clear_Old_Value_Track_Find_Wire();       
        up2_btn.drawButton(true);
        Value_All = Value_All + 100;
        Max_Cycle_Wire_Find = Value_All;
        Print_New_Value_Track_Find_Wire();
        }


    // Action if down is pressed
    if (down2_btn.justPressed()) {
        Clear_Old_Value_Track_Find_Wire();
        down2_btn.drawButton(true);
        Value_All = Value_All - 100;
        if (Value_All < 0) Value_All = 100;
        Max_Cycle_Wire_Find = Value_All;
        Print_New_Value_Track_Find_Wire();
        }
    }


//If the Button 3 is pressed (up or down)
 if ((up3_btn.justPressed() )  || (down3_btn.justPressed())) {
        
        Value_All = Max_Cycle_Wire_Find_Back;
        Value_X_All = Pos_X3;
        Value_Y_All = Pos_Y3;
    
    // Actions if UP is pressed
    if (up3_btn.justPressed()) {
        Clear_Old_Value_Track_Find_Wire();       
        up3_btn.drawButton(true);
        Value_All = Value_All + 10;
        Max_Cycle_Wire_Find_Back = Value_All;
        Print_New_Value_Track_Find_Wire();
        }


    // Action if down is pressed
    if (down3_btn.justPressed()) {
        Clear_Old_Value_Track_Find_Wire();
        down3_btn.drawButton(true);
        Value_All = Value_All - 10;
        if (Value_All < 1) Value_All = 1;
        Max_Cycle_Wire_Find_Back = Value_All;
        Print_New_Value_Track_Find_Wire();
        }
    }


//If the Button 4 is pressed (up or down)
 if ((up4_btn.justPressed() )  || (down4_btn.justPressed())) {
        
        Value_All = Home_Wire_Compass_Heading;
        Value_X_All = Pos_X4;
        Value_Y_All = Pos_Y4;
    
    // Actions if UP is pressed
    if (up4_btn.justPressed()) {
        Clear_Old_Value_Track_Find_Wire();       
        up4_btn.drawButton(true);
        Value_All = Value_All + 1;
        if (Value_All > 360) Value_All = 0;
        Home_Wire_Compass_Heading = Value_All;
        Print_New_Value_Track_Find_Wire();
        }


    // Action if down is pressed
    if (down4_btn.justPressed()) {
        Clear_Old_Value_Track_Find_Wire();
        down4_btn.drawButton(true);
        Value_All = Value_All - 1;
        if (Value_All < 0) Value_All = 359;
        Home_Wire_Compass_Heading = Value_All;
        Print_New_Value_Track_Find_Wire();
        }
    }

 
 // Action if Tracking Save is pressed
 if (Save_Track_Find_Wire_btn.justPressed()) {
         Menu_Complete_Find_Wire = true;
         tft.fillScreen(BLACK);
         Serial.println(F("Tracking Data Saved and TX"));
         Menu_Active = 918;
         Send_Menu_Selected_To_Mower_MEGA();
         Transmit_Saved_Tracking_Find_Wire_Values();
         Print_Tracking_Menu();
         }  


        
}

void Clear_Old_Value_Track_Find_Wire() {
        // Draws over the previous Value in Black text to clear it.... !?
        tft.setTextSize(Txt_Size_Value); 
        tft.setTextColor(BLACK, BLACK);      //Text Colour/ Background Colour
        tft.setCursor(Value_X_All, Value_Y_All);            // Text Coordinates X, Y
        tft.print(Value_All);
        }

void Print_New_Value_Track_Find_Wire() {        

        tft.setTextSize(Txt_Size_Value); 
        tft.setTextColor(RED, BLACK);      //Text Colour/ Background Colour
        tft.setCursor(Value_X_All, Value_Y_All);            // Text Coordinates X, Y     
        tft.print(Value_All);
        }




void Sense_Button_Press_Track_Find_Wire() {
    down = Touch_getXY();
    up2_btn.press                   (down && up2_btn.contains(pixel_x, pixel_y));
    down2_btn.press                 (down && down2_btn.contains(pixel_x, pixel_y));
    up3_btn.press                   (down && up3_btn.contains(pixel_x, pixel_y));
    down3_btn.press                 (down && down3_btn.contains(pixel_x, pixel_y));
    up4_btn.press                   (down && up4_btn.contains(pixel_x, pixel_y));
    down4_btn.press                 (down && down4_btn.contains(pixel_x, pixel_y));
    Save_Track_Find_Wire_btn.press  (down && Save_Track_Find_Wire_btn.contains(pixel_x, pixel_y));

    if (up2_btn.justReleased())                   up2_btn.drawButton();
    if (down2_btn.justReleased())                 down2_btn.drawButton();
    if (up3_btn.justReleased())                   up3_btn.drawButton();
    if (down3_btn.justReleased())                 down3_btn.drawButton();
    if (up4_btn.justReleased())                   up4_btn.drawButton();
    if (down4_btn.justReleased())                 down4_btn.drawButton();
    if (Save_Track_Find_Wire_btn.justReleased())  Save_Track_Find_Wire_btn.drawButton();
}
