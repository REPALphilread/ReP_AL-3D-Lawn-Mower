void Print_Pattern_Menu() {  

    tft.fillScreen(BLACK);
    Serial.println(F("RX Pattern"));
    Menu_Active = 25;                           // Code to tell the Mower MEGA which data to transmit.
    Send_Menu_Selected_To_Mower_MEGA();         // Send the code to the Mower MEGA which data should be transfered
    delay(RX_Delay);                            // Wait time for the Mower MEGA to transmit the data.
    Receive_7_Data_Sets();                      // Recieve data sets from the Mower MEGA
    Pattern_Mow             = Data1;            // Fill the variable values with the data sets
    Turn_90_Delay_LH        = Data2 * 10;
    Turn_90_Delay_RH        = Data3 * 10;
    Move_to_next_line_delay = Data4 * 10;
    Line_Length_Cycles      = Data5;
    Data6 = 0;
    Data7 = 0;
    Clear_Data_Streams();

    if (Debug_RX_Transfer == 1) {              // Display the received values on the TFT Screen if required.        
      Set_TFT_Screen_Pos();
      if (Pattern_Mow == 0) tft.println("OFF");
      if (Pattern_Mow == 1) tft.println("Parallel");  
      if (Pattern_Mow == 3) tft.println("Spiral"); 
      tft.print(F("Turn 90 LH= "));
      tft.println(Turn_90_Delay_LH);  
      tft.print(F("Turn 90 RH= "));
      tft.println(Turn_90_Delay_RH);      
      tft.print(F("Distance to next row= "));
      tft.println(Move_to_next_line_delay);      
      tft.print(F("Row Length = "));
      tft.println(Line_Length_Cycles);  
      tft.println(" "); 
      tft.println(F(" ")); 
      delay(TFT_Check);
      tft.fillScreen(BLACK);     
      }


    
    //if (Draw_Pictures == 1)   bmpDraw("Rain.bmp", 270, 60);      //Draw the mower picture
    delay(100);    
   
    // Framework for the + - buttons - setting the start position of the + button wil automatically then space the - button

    int Start_X = 10;
    int Start_Y = 50;
    int Menu_Btn_Space = 100;          // Space between the text and the -ve button
    int Button_W = 150;                // width of the button
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
    tft.print(F("Pattern Mow Settings Menu"));  
    
    
    
    //Pattern Setting
    //------------------------------------------------------------
    
    int Label_X = Start_X;                           // Starting X Point.
    int Label_Y = Start_Y;                           // Starting Y Point

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("Pattern Mow Setting"));  
    
    int Button_X = Label_X + (0.5 * Button_W);
    int Button_Y = Label_Y + Offset_Btn + (0.2 * Button_H);
    
    if (Pattern_Mow == 0) OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, BLACK, "OFF", 2);
    if (Pattern_Mow == 1) OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, YELLOW, BLACK, "Parallel", 2);
    if (Pattern_Mow == 2) OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, BLUE, WHITE, "SPIRAL", 2);
    
    OPTION1_BTN.drawButton(false);


    //Parallel Turn Delay LH
    //------------------------------------------------------------
    
    Button_W  = 50;
    Label_X   = Label_X;
    Label_Y   = Label_Y + Menu_Spacing;
    Value_X2  = Label_X;                        // X Position of the item
    Value_Y2  = Label_Y + Offset_Btn;           // Y Position of the item
    Value_2   = Turn_90_Delay_LH;                           // Value to be modified in the menu

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);            // Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("Parallel: Turn Delay LH"));  

    
    Button_X = Value_X2 + Menu_Btn_Space;
    Button_Y = Value_Y2 + (0.2 * Button_H);
   
    tft.setTextSize(Txt_Size_Value); 
    tft.setTextColor(RED, BLACK);                 //Text Colour/ Background Colour
    tft.setCursor(Value_X2, Value_Y2);            // Text Coordinates X, Y
    tft.print(Value_2);    

 
    UP2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    DOWN2_BTN.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);

    UP2_BTN.drawButton(false);
    DOWN2_BTN.drawButton(false);



    //Parellel Turn Delay RH
    //------------------------------------------------------------

    Label_X   = Label_X;
    Label_Y   = Label_Y + Menu_Spacing;
    Value_X3  = Label_X;                        // X Position of the item
    Value_Y3  = Label_Y + Offset_Btn;           // Y Position of the item
    Value_3   = Turn_90_Delay_RH;                           // Value to be modified in the menu

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);            // Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("Parallel: Turn Delay RH"));  

    
    Button_X = Value_X3 + Menu_Btn_Space;
    Button_Y = Value_Y3 + (0.2 * Button_H);
   
    tft.setTextSize(Txt_Size_Value); 
    tft.setTextColor(RED, BLACK);                 //Text Colour/ Background Colour
    tft.setCursor(Value_X3, Value_Y3);            // Text Coordinates X, Y
    tft.print(Value_3);    

 
    UP3_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    DOWN3_BTN.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);

    UP3_BTN.drawButton(false);
    DOWN3_BTN.drawButton(false);


    //Distance to next row
    //------------------------------------------------------------

    Label_X   = Start_X + Column_Spacing + 50;                                // next Column
    Label_Y   = Start_Y + Menu_Spacing;
    Value_X4  = Label_X;                                                      // X Position of the item
    Value_Y4  = Label_Y  + Offset_Btn;                                         // Y Position of the item
    Value_4   = Move_to_next_line_delay;                                      // Value to be modified in the menu

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);            // Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("Parallel: Distance Between Lines"));  

    
    Button_X = Value_X4 + Menu_Btn_Space;
    Button_Y = Value_Y4 + (0.2 * Button_H);
   
    tft.setTextSize(Txt_Size_Value); 
    tft.setTextColor(RED, BLACK);                 //Text Colour/ Background Colour
    tft.setCursor(Value_X4, Value_Y4);            // Text Coordinates X, Y
    tft.print(Value_4);    

 
    UP4_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    DOWN4_BTN.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);

    UP4_BTN.drawButton(false);
    DOWN4_BTN.drawButton(false);


    //Row Length
    //------------------------------------------------------------

    Label_X   = Label_X; 
    Label_Y   = Label_Y  + Menu_Spacing;
    Value_X5  = Label_X;                        // X Position of the item
    Value_Y5  = Label_Y + Offset_Btn;           // Y Position of the item
    Value_5   = Line_Length_Cycles;                           // Value to be modified in the menu

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);            // Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("Parallel: Line Length / Cycles"));  

    
    Button_X = Value_X5 + Menu_Btn_Space;
    Button_Y = Value_Y5 + (0.2 * Button_H);
   
    tft.setTextSize(Txt_Size_Value); 
    tft.setTextColor(RED, BLACK);                 //Text Colour/ Background Colour
    tft.setCursor(Value_X5, Value_Y5);            // Text Coordinates X, Y
    tft.print(Value_5);    

 
    UP5_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    DOWN5_BTN.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);

    UP5_BTN.drawButton(false);
    DOWN5_BTN.drawButton(false);


// Save Button

    SAVE_BTN.initButton(&tft, 425, 278, 80, 40, WHITE, CYAN, BLACK, "Save", 2);
    SAVE_BTN.drawButton(false);


}


void React_to_Button_Press_Pattern() {

 // If the SONAR Sensor ON/OFF Button is pressed
 if (OPTION1_BTN.justPressed() ) {

        int Start_X = 10;
        int Start_Y = 50;
        int Button_W = 150;                // width of the button
        int Button_H = 40;                // height of the button
        int Offset_Btn = 25;
        int Column_Spacing = 200;         // Distance between the Left Hand and Right Hand Columns
        
        int Button_X = Start_X + (0.5 * Button_W);
        int Button_Y = Start_Y + Offset_Btn + (0.2 * Button_H);
        bool Changed = 0;

        if (( Pattern_Mow == 3) && (Changed ==0 )) {
          Pattern_Mow = 0;
          Changed = 1;
          OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, BLACK, "OFF", 2);
          OPTION1_BTN.drawButton(false);
        }
        if (( Pattern_Mow == 0) && (Changed ==0 ))  {
          Pattern_Mow = 1;
          Changed = 1;
          OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, YELLOW, BLACK, "Parallel", 2);
          OPTION1_BTN.drawButton(false);
          }
        
        if (( Pattern_Mow == 1) && (Changed ==0 )) {
          Pattern_Mow = 3;
          Changed = 1;
          OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, BLUE, WHITE, "SPIRAL", 2);
          OPTION1_BTN.drawButton(false);
        }
  delay(200);
 }



//If the Button 2 is pressed (up or down)
 if ((UP2_BTN.justPressed() )  || (DOWN2_BTN.justPressed())) {
        
        Value_All = Turn_90_Delay_LH;
        Value_X_All = Value_X2;
        Value_Y_All = Value_Y2;
    
    // Actions if UP is pressed
    if (UP2_BTN.justPressed()) {
        Clear_Old_Value_Pattern();       
        UP2_BTN.drawButton(true);
        Turn_90_Delay_LH = Turn_90_Delay_LH + 25;
        Value_All = Turn_90_Delay_LH;
        Int_Float = 0;
        Print_New_Value_Pattern();
        }


    // Action if down is pressed
    if (DOWN2_BTN.justPressed()) {
        Clear_Old_Value_Pattern();
        DOWN2_BTN.drawButton(true);
        Turn_90_Delay_LH = Turn_90_Delay_LH - 25;
        if (Turn_90_Delay_LH < 100) Turn_90_Delay_LH = 100;
        Value_All = Turn_90_Delay_LH;
        Int_Float = 0;
        Print_New_Value_Pattern();
        }
    }


//If the Button 2 is pressed (up or down)
 if ((UP3_BTN.justPressed() )  || (DOWN3_BTN.justPressed())) {
        
        Value_All = Turn_90_Delay_RH;
        Value_X_All = Value_X3;
        Value_Y_All = Value_Y3;
    
    // Actions if UP is pressed
    if (UP3_BTN.justPressed()) {
        Clear_Old_Value_Pattern();       
        UP3_BTN.drawButton(true);
        Turn_90_Delay_RH = Turn_90_Delay_RH + 25;
        Value_All = Turn_90_Delay_RH;
        Int_Float = 0;
        Print_New_Value_Pattern();
        }


    // Action if down is pressed
    if (DOWN3_BTN.justPressed()) {
        Clear_Old_Value_Pattern();
        DOWN3_BTN.drawButton(true);
        Turn_90_Delay_RH = Turn_90_Delay_RH - 25;
        if (Turn_90_Delay_RH < 100) Turn_90_Delay_RH = 100;
        Value_All = Turn_90_Delay_RH;
        Int_Float = 0;
        Print_New_Value_Pattern();
        }
    }


//If the Button 4 is pressed (up or down)
 if ((UP4_BTN.justPressed() )  || (DOWN4_BTN.justPressed())) {
        
        Value_All = Move_to_next_line_delay;
        Value_X_All = Value_X4;
        Value_Y_All = Value_Y4;
    
    // Actions if UP is pressed
    if (UP4_BTN.justPressed()) {
        Clear_Old_Value_Pattern();       
        UP4_BTN.drawButton(true);
        Move_to_next_line_delay = Move_to_next_line_delay + 25;
        Value_All = Move_to_next_line_delay;
        Int_Float = 0;
        Print_New_Value_Pattern();
        }


    // Action if down is pressed
    if (DOWN4_BTN.justPressed()) {
        Clear_Old_Value_Pattern();
        DOWN4_BTN.drawButton(true);
        Move_to_next_line_delay = Move_to_next_line_delay - 25;
        if (Move_to_next_line_delay < 100) Move_to_next_line_delay = 100;
        Value_All = Move_to_next_line_delay;
        Int_Float = 0;
        Print_New_Value_Pattern();
        }
    }


//If the Button 5 is pressed (up or down)
 if ((UP5_BTN.justPressed() )  || (DOWN5_BTN.justPressed())) {
        
        Value_All = Move_to_next_line_delay;
        Value_X_All = Value_X5;
        Value_Y_All = Value_Y5;
    
    // Actions if UP is pressed
    if (UP5_BTN.justPressed()) {
        Clear_Old_Value_Pattern();       
        UP5_BTN.drawButton(true);
        Line_Length_Cycles = Line_Length_Cycles + 5;
        Value_All = Line_Length_Cycles;
        Int_Float = 0;
        Print_New_Value_Pattern();
        }


    // Action if down is pressed
    if (DOWN5_BTN.justPressed()) {
        Clear_Old_Value_Pattern();
        DOWN5_BTN.drawButton(true);
        Line_Length_Cycles = Line_Length_Cycles - 5;
        if (Line_Length_Cycles < 10) Line_Length_Cycles = 10;
        Value_All = Line_Length_Cycles;
        Int_Float = 0;
        Print_New_Value_Pattern();
        }
    }
 
 // Action if Rain Save is pressed
 if (SAVE_BTN.justPressed()) {
         Menu_Complete_Pattern = true;
         tft.fillScreen(BLACK);
         Serial.println(F("Rain Data Saved and TX"));
         Menu_Active = 925;
         Send_Menu_Selected_To_Mower_MEGA();
         Transmit_Saved_Pattern_Values();
         Print_Motion_Menu();
         }  
        
}



void Clear_Old_Value_Pattern() {
        // Draws over the previous Value in Black text to clear it.... !?
        tft.setTextSize(Txt_Size_Value); 
        tft.setTextColor(BLACK, BLACK);      //Text Colour/ Background Colour
        tft.setCursor(Value_X_All, Value_Y_All);            // Text Coordinates X, Y
        if (Int_Float == 0) {
          tft.print(Value_All);
          }
        if (Int_Float == 1) {
          tft.print(Value_All_Float);
          }  
        }

void Print_New_Value_Pattern() {        

        tft.setTextSize(Txt_Size_Value); 
        tft.setTextColor(RED, BLACK);      //Text Colour/ Background Colour
        tft.setCursor(Value_X_All, Value_Y_All);            // Text Coordinates X, Y
        if (Int_Float == 0) {
          tft.print(Value_All);
          }
        if (Int_Float == 1) {
          tft.print(Value_All_Float);
          }          
        }




void Sense_Button_Press_Pattern() {
    down = Touch_getXY();
    OPTION1_BTN.press (down && OPTION1_BTN.contains(pixel_x, pixel_y));
    UP2_BTN.press    (down && UP2_BTN.contains(pixel_x, pixel_y));
    DOWN2_BTN.press  (down && DOWN2_BTN.contains(pixel_x, pixel_y));
    UP3_BTN.press    (down && UP3_BTN.contains(pixel_x, pixel_y));
    DOWN3_BTN.press  (down && DOWN3_BTN.contains(pixel_x, pixel_y));
    UP4_BTN.press    (down && UP4_BTN.contains(pixel_x, pixel_y));
    DOWN4_BTN.press  (down && DOWN4_BTN.contains(pixel_x, pixel_y));
    UP5_BTN.press    (down && UP5_BTN.contains(pixel_x, pixel_y));
    DOWN5_BTN.press  (down && DOWN5_BTN.contains(pixel_x, pixel_y));
    SAVE_BTN.press   (down && SAVE_BTN.contains(pixel_x, pixel_y));

    if (OPTION1_BTN.justReleased())  OPTION1_BTN.drawButton();
    if (UP2_BTN.justReleased())     UP2_BTN.drawButton();
    if (DOWN2_BTN.justReleased())   DOWN2_BTN.drawButton();
    if (UP3_BTN.justReleased())     UP3_BTN.drawButton();
    if (DOWN3_BTN.justReleased())   DOWN3_BTN.drawButton();
    if (UP4_BTN.justReleased())     UP4_BTN.drawButton();
    if (DOWN4_BTN.justReleased())   DOWN4_BTN.drawButton();
    if (UP5_BTN.justReleased())     UP5_BTN.drawButton();
    if (DOWN5_BTN.justReleased())   DOWN5_BTN.drawButton();
    if (SAVE_BTN.justReleased())    SAVE_BTN.drawButton();
}
