void Print_Set_Time_Menu() {  

     // Framework for the buttons - setting the start position of the Quick start button wil automatically then space the other buttons
    tft.fillScreen(BLACK);
    int Label_Time_Spacing = 30;          // Space between the text and the -ve button
    int Button_W = 50;                // width of the button
    int Button_H = 40;                // height of the button
    int Button_Spacing = 5;           // Space between the -ve and +ve buttons
    int Time_Spacing = 150;            // Distance between the Hours and Minutes Number
    Offset_Btn = 25;
    int Time_Button_Spacing = 100;

    // Main Menu Title
    tft.setTextSize(2); 
    tft.setTextColor(GREEN, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(10, 10);            // Text Coordinates X, Y
    tft.print(F("Set Clock Menu"));  
    
    // Framework for the + - buttons - setting the start position of the + button wil automatically then space the - button

    // Top left position of the first menu item.    
    Pos_X1   = 60;
    Pos_Y1   = 80;

    
    // Size of the Time Label
    tft.setTextSize(2); 
    tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Pos_X1, Pos_Y1);            // Text Coordinates X, Y
    tft.print(F("Mower Clock Time"));  

    // Size of the Time Numbers
    tft.setTextSize(9); 
    tft.setTextColor(RED, BLACK);      //Text Colour/ Background Colour

    // Hours X 10 
    Pos_X1 = Pos_X1;
    Pos_Y1 = Pos_Y1 + Label_Time_Spacing;  
    tft.setCursor(Pos_X1, Pos_Y1);            // Text Coordinates X, Y
        if (Time_Hour > 9) tft.print(Time_Hour);
        if (Time_Hour < 10) {
          tft.print("0");
          tft.print(Time_Hour);
        }

    Pos_X3 = Pos_X1 + 100;
    Pos_Y3 = Pos_Y1;  
    tft.setCursor(Pos_X3, Pos_Y3);            // Text Coordinates X, Y
    tft.print(":");     


    // Minutes X 10 
    Pos_X2 = Pos_X1 + Time_Spacing;
    Pos_Y2 = Pos_Y1;  
    tft.setCursor(Pos_X2, Pos_Y2);            // Text Coordinates X, Y
        if (Time_Minute > 9) tft.print(Time_Minute);
        if (Time_Minute < 10) {
          tft.print("0");
          tft.print(Time_Minute);
        }
    
    // + - Hour Value
    int Button_X = Pos_X1 + (0.5 * Button_W);
    int Button_Y = Pos_Y1 + Time_Button_Spacing;
 
    up1_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    down1_btn.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);

    up1_btn.drawButton(false);
    down1_btn.drawButton(false);

    // + - Minute Value
    Button_X = Pos_X2 + (0.5 * Button_W);
    Button_Y = Pos_Y2 + Time_Button_Spacing;
 
    up2_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    down2_btn.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);

    up2_btn.drawButton(false);
    down2_btn.drawButton(false);



// Done Button

    Save_Set_Time_btn.initButton(&tft, 410, 275, 80, 40, WHITE, CYAN, BLACK, "Save", 2);
    Save_Set_Time_btn.drawButton(false);


}



void React_to_Button_Set_Time() {

  //If the Button 1 Turn Angle Max is pressed (up or down)
   if ((up1_btn.justPressed() )  || (down1_btn.justPressed())) {
        Value_All = Time_Hour;
        Label_X = Pos_X1;
        Label_Y = Pos_Y1;
    
    // Actions if UP is pressed
    if (up1_btn.justPressed()) {
        Clear_Old_Value_Set_Time();       
        up1_btn.drawButton(true);
        Value_All = Value_All + 1;
        if (Value_All > 24) Value_All = 0;
        Time_Hour = Value_All;
        Print_New_Value_Set_Time();
        }


    // Action if down is pressed
    if (down1_btn.justPressed()) {
        Clear_Old_Value_Set_Time();
        down1_btn.drawButton(true);
        Value_All = Value_All - 1;
        if (Value_All < 0) Value_All = 23;
        Time_Hour = Value_All;
        Print_New_Value_Set_Time();
        }
    
    }

  //If the Reverse Button 2 is pressed (up or down)
   if ((up2_btn.justPressed() )  || (down2_btn.justPressed())) {
        Value_All = Time_Minute;
        Label_X   = Pos_X2;
        Label_Y   = Pos_Y2;
    
    // Actions if UP is pressed
    if (up2_btn.justPressed()) {
        Clear_Old_Value_Set_Time();       
        up2_btn.drawButton(true);
        Value_All = Value_All + 1;
        if (Value_All > 59) Value_All = 0;
        Time_Minute = Value_All;
        Print_New_Value_Set_Time();
        }


    // Action if down is pressed
    if (down2_btn.justPressed()) {
        Clear_Old_Value_Set_Time();
        down2_btn.drawButton(true);
        Value_All = Value_All - 1;
        if (Value_All < 0) Value_All = 59;
        Time_Minute = Value_All;
        Print_New_Value_Set_Time();
        }
    
    }



 // Action if Sonar Save is pressed
 if (Save_Set_Time_btn.justPressed()) {
         Menu_Complete_Set_Time = true;
         tft.fillScreen(BLACK);
         Serial.println(F("Time Saved and TX"));
         Menu_Active = 923;
         Send_Menu_Selected_To_Mower_MEGA();
         Transmit_Save_Set_Time_Values();              
         Print_Time_Menu();
         }

}


void Clear_Old_Value_Set_Time() {
        // Draws over the previous Value in Black text to clear it.... !?
        tft.setTextSize(9); 
        tft.setTextColor(BLACK, BLACK);      //Text Colour/ Background Colour
        tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
        if (Value_All > 9) tft.print(Value_All);
        if (Value_All < 10) {
          tft.print("0");
          tft.print(Value_All);
        }
        }


void Print_New_Value_Set_Time() {        

        tft.setTextSize(9); 
        tft.setTextColor(RED, BLACK);      //Text Colour/ Background Colour
        tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
        if (Value_All > 9) tft.print(Value_All);
        if (Value_All < 10) {
          tft.print("0");
          tft.print(Value_All);
        }
        }




void Sense_Button_Set_Time() {
    down = Touch_getXY();
    up1_btn.press             (down && up1_btn.contains(pixel_x, pixel_y));
    down1_btn.press           (down && down1_btn.contains(pixel_x, pixel_y));
    up2_btn.press             (down && up2_btn.contains(pixel_x, pixel_y));
    down2_btn.press           (down && down2_btn.contains(pixel_x, pixel_y));
    Save_Set_Time_btn.press     (down && Save_Set_Time_btn.contains(pixel_x, pixel_y));


    if (up1_btn.justReleased())             up1_btn.drawButton();
    if (down1_btn.justReleased())           down1_btn.drawButton();
    if (up2_btn.justReleased())             up2_btn.drawButton();  
    if (down2_btn.justReleased())           down2_btn.drawButton();
    if (Save_Set_Time_btn.justReleased())     Save_Set_Time_btn.drawButton();
    }
