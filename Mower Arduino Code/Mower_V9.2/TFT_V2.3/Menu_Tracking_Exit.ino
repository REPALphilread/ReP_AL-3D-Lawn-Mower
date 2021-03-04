void Print_Tracking_Exit_Menu() {  

    tft.fillScreen(BLACK);
 
    Serial.println(F("RX Exits"));
    Menu_Active = 17;                           // Code to tell the Mower MEGA which data to transmit.
    Send_Menu_Selected_To_Mower_MEGA();         // Send the code to the Mower MEGA which data should be transfered
    delay(RX_Delay);                            // Wait time for the Mower MEGA to transmit the data.
    Receive_7_Data_Sets();                      // Recieve data sets from the Mower MEGA
    Track_Wire_Zone_1_Cycles = Data1 * 100;                   // Fill the variable values with the data sets
    Track_Wire_Zone_2_Cycles = Data2 * 100;
    CCW_Tracking_To_Start = Data3;
    Data4 = 0;
    Data5 = 0;
    Data6 = 0;
    Data7 = 0;
    Clear_Data_Streams();

    if (Debug_RX_Transfer == 1) {              // Display the received values on the TFT Screen if required.        
      Set_TFT_Screen_Pos();
      tft.print(F("Track Wire Zone 1 = "));
      tft.println(Track_Wire_Zone_1_Cycles);     
      tft.print(F("Track Wire Zone 2 = "));
      tft.println(Track_Wire_Zone_2_Cycles);      
      if (CCW_Tracking_To_Start == 0) {
        CW_Tracking_To_Start = 1;
        CCW_Tracking_To_Charge = 1;
        CW_Tracking_To_Charge = 0;
        tft.println(F("Tracking to Charge = CCW"));
        tft.println(F("Tracking to Start = CW"));
        }        
      if (CCW_Tracking_To_Start == 1) {
        CW_Tracking_To_Start = 0;
        CCW_Tracking_To_Charge = 0;
        CW_Tracking_To_Charge = 1;      
        tft.println(F("Tracking to Charge = CW"));
        tft.println(F("Tracking to Start = CCW"));
        tft.println(F(" "));  
        }
      tft.println(F(" ")); 
      delay(TFT_Check);
      tft.fillScreen(BLACK);     
      }    
    
    
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
    UP2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    DOWN2_BTN.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);
    UP2_BTN.drawButton(false);
    DOWN2_BTN.drawButton(false);



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
    UP3_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    DOWN3_BTN.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);
    UP3_BTN.drawButton(false);
    DOWN3_BTN.drawButton(false);



    
    
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
    
    if (CCW_Tracking_To_Start == 0) OPTION1_BTN.initButton(&tft, Button_X1, Button_Y1, Button_W, Button_H, WHITE, BLUE, WHITE, "CW", 2);
    if (CCW_Tracking_To_Start == 1)  OPTION1_BTN.initButton(&tft, Button_X1, Button_Y1, Button_W, Button_H, WHITE, MAGENTA, BLACK, "CCW", 2);
    OPTION1_BTN.drawButton(false);


// Save Button

    SAVE4_BTN.initButton(&tft, 400, 282, 80, 40, WHITE, CYAN, BLACK, "Save", 2);
    SAVE4_BTN.drawButton(false);


}


void React_to_Button_Tracking_Exit() {

 // If the SONAR Sensor ON/OFF Button is pressed
 if (OPTION1_BTN.justPressed() ) {

        int Button_W = 130;                // width of the button
        int Button_H = 40;                // height of the button
        bool Changed = 0;

        if ((CCW_Tracking_To_Start == 1) && (Changed == 0))  {
          CW_Tracking_To_Start = 1;
          CCW_Tracking_To_Start = 0;
          CCW_Tracking_To_Charge = 1;
          CW_Tracking_To_Charge = 0;
          
          Changed = 1;
          OPTION1_BTN.initButton(&tft, Button_X1, Button_Y1, Button_W, Button_H, WHITE, BLUE, WHITE, "CW", 2);
          OPTION1_BTN.drawButton(false);
          }
        
        if ((CCW_Tracking_To_Start == 0) && (Changed == 0)) {
          CW_Tracking_To_Start = 0;
          CCW_Tracking_To_Start = 1;
          CCW_Tracking_To_Charge = 0;
          CW_Tracking_To_Charge = 1;
          
          Changed = 1;
          OPTION1_BTN.initButton(&tft, Button_X1, Button_Y1, Button_W, Button_H, WHITE, MAGENTA, BLACK, "CCW", 2);
          OPTION1_BTN.drawButton(false);
        }
  delay(200);
 }



//If the Button 2 is pressed (up or down)
 if ((UP2_BTN.justPressed() )  || (DOWN2_BTN.justPressed())) {
        
        Value_All = Track_Wire_Zone_1_Cycles;
        Value_X_All = Pos_X2;
        Value_Y_All = Pos_Y2;
    
    // Actions if UP is pressed
    if (UP2_BTN.justPressed()) {
        Clear_Old_Value_Tracking_Exit();       
        UP2_BTN.drawButton(true);
        Value_All = Value_All + 100;
        Track_Wire_Zone_1_Cycles = Value_All;
        Print_New_Value_Tracking_Exit();
        }


    // Action if down is pressed
    if (DOWN2_BTN.justPressed()) {
        Clear_Old_Value_Tracking_Exit();
        DOWN2_BTN.drawButton(true);
        Value_All = Value_All - 100;
        if (Value_All < 0) Value_All = 100;
        Track_Wire_Zone_1_Cycles = Value_All;
        Print_New_Value_Tracking_Exit();
        }
    }


//If the Button 3 is pressed (up or down)
 if ((UP3_BTN.justPressed() )  || (DOWN3_BTN.justPressed())) {
        
        Value_All = Track_Wire_Zone_2_Cycles;
        Value_X_All = Pos_X3;
        Value_Y_All = Pos_Y3;
    
    // Actions if UP is pressed
    if (UP3_BTN.justPressed()) {
        Clear_Old_Value_Tracking_Exit();       
        UP3_BTN.drawButton(true);
        Value_All = Value_All + 100;
        Track_Wire_Zone_2_Cycles = Value_All;
        Print_New_Value_Tracking_Exit();
        }


    // Action if down is pressed
    if (DOWN3_BTN.justPressed()) {
        Clear_Old_Value_Tracking_Exit();
        DOWN3_BTN.drawButton(true);
        Value_All = Value_All - 100;
        if (Value_All < 0) Value_All = 100;
        Track_Wire_Zone_2_Cycles = Value_All;
        Print_New_Value_Tracking_Exit();
        }
    }

 
 // Action if Tracking Save is pressed
 if (SAVE4_BTN.justPressed()) {
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
    OPTION1_BTN.press   (down && OPTION1_BTN.contains(pixel_x, pixel_y));
    UP2_BTN.press                 (down && UP2_BTN.contains(pixel_x, pixel_y));
    DOWN2_BTN.press               (down && DOWN2_BTN.contains(pixel_x, pixel_y));
    UP3_BTN.press                 (down && UP3_BTN.contains(pixel_x, pixel_y));
    DOWN3_BTN.press               (down && DOWN3_BTN.contains(pixel_x, pixel_y));
    SAVE4_BTN.press  (down && SAVE4_BTN.contains(pixel_x, pixel_y));

    if (OPTION1_BTN.justReleased())   OPTION1_BTN.drawButton();
    if (UP2_BTN.justReleased())                 UP2_BTN.drawButton();
    if (DOWN2_BTN.justReleased())               DOWN2_BTN.drawButton();
    if (UP3_BTN.justReleased())                 UP3_BTN.drawButton();
    if (DOWN3_BTN.justReleased())               DOWN3_BTN.drawButton();
    if (SAVE4_BTN.justReleased())  SAVE4_BTN.drawButton();
}
