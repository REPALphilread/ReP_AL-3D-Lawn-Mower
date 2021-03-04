void Print_Track_Find_Wire_Menu() {  

    tft.fillScreen(BLACK);
    Menu_Active = 18;                           // Code to tell the Mower MEGA which data to transmit.
    Send_Menu_Selected_To_Mower_MEGA();         // Send the code to the Mower MEGA which data should be transfered
    delay(RX_Delay);                            // Wait time for the Mower MEGA to transmit the data.
    Receive_7_Data_Sets();                      // Recieve data sets from the Mower MEGA
    Max_Cycle_Wire_Find       = Data1 * 100;    // Return this value back to a float.
    Max_Cycle_Wire_Find_Back  = Data2 * 10; 
    Home_Wire_Compass_Heading = Data3;
    Data3 = 0;
    Data4 = 0;
    Data5 = 0;
    Data6 = 0;
    Data7 = 0;
    Clear_Data_Streams();
    if (Debug_RX_Transfer == 1) {                             // Display the received values on the TFT Screen if required.        
      Set_TFT_Screen_Pos();
          tft.print(F("Wire Find Forwards Cycles = "));
          tft.println(Max_Cycle_Wire_Find);
          tft.print(F("Wire Find Forwards Cycles = "));
          tft.println(Max_Cycle_Wire_Find_Back);
          tft.print(F("Home Compass degrees "));
          tft.println(Home_Wire_Compass_Heading);
          tft.println(F(" "));
          delay(TFT_Check);                                   // Time the TFT displays the numbers
          tft.fillScreen(BLACK);     
          }
    

    
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
    UP2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    DOWN2_BTN.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);
    UP2_BTN.drawButton(false);
    DOWN2_BTN.drawButton(false);



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
    UP3_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    DOWN3_BTN.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);
    UP3_BTN.drawButton(false);
    DOWN3_BTN.drawButton(false);


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
    UP4_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    DOWN4_BTN.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);
    UP4_BTN.drawButton(false);
    DOWN4_BTN.drawButton(false);
    
    

// Save Button

    Save_Track_Find_Wire_btn.initButton(&tft, 400, 282, 80, 40, WHITE, CYAN, BLACK, "Save", 2);
    Save_Track_Find_Wire_btn.drawButton(false);


}


void React_to_Button_Press_Track_Find_Wire() {



//If the Button 2 is pressed (up or down)
 if ((UP2_BTN.justPressed() )  || (DOWN2_BTN.justPressed())) {
        
        Value_All = Max_Cycle_Wire_Find;
        Value_X_All = Pos_X2;
        Value_Y_All = Pos_Y2;
    
    // Actions if UP is pressed
    if (UP2_BTN.justPressed()) {
        Clear_Old_Value_Track_Find_Wire();       
        UP2_BTN.drawButton(true);
        Value_All = Value_All + 100;
        Max_Cycle_Wire_Find = Value_All;
        Print_New_Value_Track_Find_Wire();
        }


    // Action if down is pressed
    if (DOWN2_BTN.justPressed()) {
        Clear_Old_Value_Track_Find_Wire();
        DOWN2_BTN.drawButton(true);
        Value_All = Value_All - 100;
        if (Value_All < 0) Value_All = 100;
        Max_Cycle_Wire_Find = Value_All;
        Print_New_Value_Track_Find_Wire();
        }
    }


//If the Button 3 is pressed (up or down)
 if ((UP3_BTN.justPressed() )  || (DOWN3_BTN.justPressed())) {
        
        Value_All = Max_Cycle_Wire_Find_Back;
        Value_X_All = Pos_X3;
        Value_Y_All = Pos_Y3;
    
    // Actions if UP is pressed
    if (UP3_BTN.justPressed()) {
        Clear_Old_Value_Track_Find_Wire();       
        UP3_BTN.drawButton(true);
        Value_All = Value_All + 10;
        Max_Cycle_Wire_Find_Back = Value_All;
        Print_New_Value_Track_Find_Wire();
        }


    // Action if down is pressed
    if (DOWN3_BTN.justPressed()) {
        Clear_Old_Value_Track_Find_Wire();
        DOWN3_BTN.drawButton(true);
        Value_All = Value_All - 10;
        if (Value_All < 1) Value_All = 1;
        Max_Cycle_Wire_Find_Back = Value_All;
        Print_New_Value_Track_Find_Wire();
        }
    }


//If the Button 4 is pressed (up or down)
 if ((UP4_BTN.justPressed() )  || (DOWN4_BTN.justPressed())) {
        
        Value_All = Home_Wire_Compass_Heading;
        Value_X_All = Pos_X4;
        Value_Y_All = Pos_Y4;
    
    // Actions if UP is pressed
    if (UP4_BTN.justPressed()) {
        Clear_Old_Value_Track_Find_Wire();       
        UP4_BTN.drawButton(true);
        Value_All = Value_All + 1;
        if (Value_All > 360) Value_All = 0;
        Home_Wire_Compass_Heading = Value_All;
        Print_New_Value_Track_Find_Wire();
        }


    // Action if down is pressed
    if (DOWN4_BTN.justPressed()) {
        Clear_Old_Value_Track_Find_Wire();
        DOWN4_BTN.drawButton(true);
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
    UP2_BTN.press                   (down && UP2_BTN.contains(pixel_x, pixel_y));
    DOWN2_BTN.press                 (down && DOWN2_BTN.contains(pixel_x, pixel_y));
    UP3_BTN.press                   (down && UP3_BTN.contains(pixel_x, pixel_y));
    DOWN3_BTN.press                 (down && DOWN3_BTN.contains(pixel_x, pixel_y));
    UP4_BTN.press                   (down && UP4_BTN.contains(pixel_x, pixel_y));
    DOWN4_BTN.press                 (down && DOWN4_BTN.contains(pixel_x, pixel_y));
    Save_Track_Find_Wire_btn.press  (down && Save_Track_Find_Wire_btn.contains(pixel_x, pixel_y));

    if (UP2_BTN.justReleased())                   UP2_BTN.drawButton();
    if (DOWN2_BTN.justReleased())                 DOWN2_BTN.drawButton();
    if (UP3_BTN.justReleased())                   UP3_BTN.drawButton();
    if (DOWN3_BTN.justReleased())                 DOWN3_BTN.drawButton();
    if (UP4_BTN.justReleased())                   UP4_BTN.drawButton();
    if (DOWN4_BTN.justReleased())                 DOWN4_BTN.drawButton();
    if (Save_Track_Find_Wire_btn.justReleased())  Save_Track_Find_Wire_btn.drawButton();
}
