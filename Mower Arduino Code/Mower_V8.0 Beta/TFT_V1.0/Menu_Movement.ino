void Print_Movement_Menu() {  

     // Framework for the buttons - setting the start position of the Quick start button wil automatically then space the other buttons

    if (Draw_Pictures == 1)   bmpDraw("Movement.bmp", 155, 60);      //Draw the mower picture
    delay(100); 

    int Start_X = 10;
    int Start_Y = 50;
    int Menu_Btn_Space = 80;          // Space between the text and the -ve button
    int Button_W = 50;                // width of the button
    int Button_H = 40;                // height of the button
    int Button_Spacing = 5;           // Space between the -ve and +ve buttons
    int Txt_Size_Label = 1;           // Test size iof the label above the value
    int Txt_Size_Value = 2;               // Text size of the value that is changing
    int Menu_Spacing = 65;            // Distance between the Menu Items (bottom of the last button to the label of the next item)
    Offset_Btn = 25;
    int Txt_Size_Main_Menu = 2;
    int Column_Spacing = 100;         // Distance between the Left Hand and Right Hand Columns

    // Main Menu Title
    tft.setTextSize(Txt_Size_Main_Menu); 
    tft.setTextColor(GREEN, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(10, 10);            // Text Coordinates X, Y
    tft.print(F("Mower Movement Menu"));  
    
    // Framework for the + - buttons - setting the start position of the + button wil automatically then space the - button



    //Turn Angles
    //------------------------------------------------------------
    
    Label_X   = 90;
    Label_Y   = 250;
    int Value_X1  = Label_X;                       // X Position of the item
    int Value_Y1  = Label_Y + Offset_Btn;          // Y Position of the item
    Value_1 = Mower_Turn_Delay_Max;

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("Turn Angle Max / milli sec"));  

    
    int Button_X = Value_X1 + Menu_Btn_Space;
    int Button_Y = Value_Y1 + (0.2 * Button_H);
   
    tft.setTextSize(Txt_Size_Value); 
    tft.setTextColor(RED, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Value_X1, Value_Y1);            // Text Coordinates X, Y
    tft.print(Value_1);    

 
    up1_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    down1_btn.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);

    up1_btn.drawButton(false);
    down1_btn.drawButton(false);
   
    
    //Turn Angles Min
    //------------------------------------------------------------
    
    Label_X   = 20;
    Label_Y   = 150;
    Value_X4  = Label_X;                       // X Position of the item
    Value_Y4  = Label_Y + Offset_Btn;          // Y Position of the item
    Value_4 = Mower_Turn_Delay_Min;

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("Turn Angle Min / milli sec"));  

    
    Button_X = Value_X4 + Menu_Btn_Space;
    Button_Y = Value_Y4 + (0.2 * Button_H);
   
    tft.setTextSize(Txt_Size_Value); 
    tft.setTextColor(RED, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Value_X4, Value_Y4);            // Text Coordinates X, Y
    tft.print(Value_4);    

 
    up4_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    down4_btn.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);

    up4_btn.drawButton(false);
    down4_btn.drawButton(false);

    
    
    //Reverse
    //------------------------------------------------------------
    
    Label_X   = 310;
    Label_Y   = 230;
    Value_X2  = Label_X;                       // X Position of the item
    Value_Y2  = Label_Y + Offset_Btn;          // Y Position of the item
    Value_2 = Mower_Reverse_Delay;

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("Reverse Distance / mille sec"));  

    
    Button_X = Value_X2 + Menu_Btn_Space;
    Button_Y = Value_Y2 + (0.2 * Button_H);
   
    tft.setTextSize(Txt_Size_Value); 
    tft.setTextColor(RED, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Value_X2, Value_Y2);            // Text Coordinates X, Y
    tft.print(Value_2);    

 
    up2_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    down2_btn.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);

    up2_btn.drawButton(false);
    down2_btn.drawButton(false);



    //Max Mow Length
    //------------------------------------------------------------
    
    Label_X   = 20;
    Label_Y   = 50;
    Value_X3  = Label_X;                       // X Position of the item
    Value_Y3  = Label_Y + Offset_Btn;          // Y Position of the item
    Value_3 = Max_Cycles_Straight;

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("Max Mow Length / cycles"));  

    
    Button_X = Value_X3 + Menu_Btn_Space;
    Button_Y = Value_Y3 + (0.2 * Button_H);
   
    tft.setTextSize(Txt_Size_Value); 
    tft.setTextColor(RED, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Value_X3, Value_Y3);            // Text Coordinates X, Y
    tft.print(Value_3);    

 
    up3_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    down3_btn.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);

    up3_btn.drawButton(false);
    down3_btn.drawButton(false);
    
    

// Save Button

    Save_Movement_btn.initButton(&tft, 425, 40, 80, 40, WHITE, CYAN, BLACK, "Save", 2);
    Save_Movement_btn.drawButton(false);
    
    }




void React_to_Button_Press_Movement() {

  //If the Button 1 Turn Angle Max is pressed (up or down)
   if ((up1_btn.justPressed() )  || (down1_btn.justPressed())) {
        Value_All = Value_1;
        Label_X = 90;
        Label_Y = 250  + Offset_Btn;
    
    // Actions if UP is pressed
    if (up1_btn.justPressed()) {
        Clear_Old_Value_Movement();       
        up1_btn.drawButton(true);
        Value_All = Value_All + 100;
        Value_1 = Value_All;
        Mower_Turn_Delay_Max = Value_1; 
        Print_New_Value_Movement();
        }


    // Action if down is pressed
    if (down1_btn.justPressed()) {
        Clear_Old_Value_Movement();
        down1_btn.drawButton(true);
        Value_All = Value_All - 100;
        if (Value_All < 500) Value_All = 500;
        if (Value_All < Mower_Turn_Delay_Min) Value_All = Mower_Turn_Delay_Min + 100;
        Value_1 = Value_All;
        Mower_Turn_Delay_Max = Value_1; 
        Print_New_Value_Movement();
        }
    
    }

  //If the Reverse Button 2 is pressed (up or down)
   if ((up2_btn.justPressed() )  || (down2_btn.justPressed())) {
        Value_All = Value_2;
        Label_X   = 310;
        Label_Y   = 230  + Offset_Btn;
    
    // Actions if UP is pressed
    if (up2_btn.justPressed()) {
        Clear_Old_Value_Movement();       
        up2_btn.drawButton(true);
        Value_All = Value_All + 100;
        Value_2 = Value_All;
        Mower_Reverse_Delay = Value_2;
        Print_New_Value_Movement();
        }


    // Action if down is pressed
    if (down2_btn.justPressed()) {
        Clear_Old_Value_Movement();
        down2_btn.drawButton(true);
        Value_All = Value_All - 100;
        if (Value_All < 500) Value_All = 500;
        Value_2 = Value_All;
        Mower_Reverse_Delay = Value_2;
        Print_New_Value_Movement();
        }
    
    }



  //If the Max Mow Length Button 3 is pressed (up or down)
   if ((up3_btn.justPressed() )  || (down3_btn.justPressed())) {
        Value_All = Value_3;
        Label_X   = 20;
        Label_Y   = 50  + Offset_Btn;
    
    // Actions if Max Mow Length UP is pressed
    if (up3_btn.justPressed()) {
        Clear_Old_Value_Movement();       
        up3_btn.drawButton(true);
        Value_All = Value_All + 5;
        Value_3 = Value_All;
        Max_Cycles_Straight = Value_3;
        Print_New_Value_Movement();
        }


    // Action if Max Mow Length down is pressed
    if (down3_btn.justPressed()) {
        Clear_Old_Value_Movement();
        down3_btn.drawButton(true);
        Value_All = Value_All - 5;
        if (Value_All < 20) Value_All = 20;
        Value_3 = Value_All;
        Max_Cycles_Straight = Value_3;
        Print_New_Value_Movement();
        }
    
    }


  //If the Turn Angle Min Button 4 is pressed (up or down)
   if ((up4_btn.justPressed() )  || (down4_btn.justPressed())) {
        Value_All = Value_4;
        Label_X   = 20;
        Label_Y   = 150  + Offset_Btn;
    
    // Actions if UP is pressed
    if (up4_btn.justPressed()) {
        Clear_Old_Value_Movement();       
        up4_btn.drawButton(true);
        Value_All = Value_All + 100;
        if (Value_All > Mower_Turn_Delay_Max) Value_All = Mower_Turn_Delay_Max - 100;
        Value_4 = Value_All;
        Mower_Turn_Delay_Min = Value_4; 
        Print_New_Value_Movement();
        }


    // Action if down is pressed
    if (down4_btn.justPressed()) {
        Clear_Old_Value_Movement();
        down4_btn.drawButton(true);
        Value_All = Value_All - 100;
        if (Value_All < 500) Value_All = 500;
        Value_4 = Value_All;
        Mower_Turn_Delay_Min = Value_4; 
        Print_New_Value_Movement();
        }
    
    }


 // Action if Sonar Save is pressed
 if (Save_Movement_btn.justPressed()) {
         Menu_Complete_Movement = true;
         tft.fillScreen(BLACK);
         Serial.println(F("Movement Data Saved and TX"));
         Menu_Active = 916;
         Send_Menu_Selected_To_Mower_MEGA();
         Transmit_Save_Movement_Values();
         Print_Motion_Menu();
         }

}

void Clear_Old_Value_Movement() {
        // Draws over the previous Value in Black text to clear it.... !?
        tft.setTextSize(2); 
        tft.setTextColor(BLACK, BLACK);      //Text Colour/ Background Colour
        tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
        tft.print(Value_All);
        }


void Print_New_Value_Movement() {        

        tft.setTextSize(2); 
        tft.setTextColor(RED, BLACK);      //Text Colour/ Background Colour
        tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
        tft.print(Value_All);
        }


void Sense_Button_Press_Movement() {
    down = Touch_getXY();
    up1_btn.press             (down && up1_btn.contains(pixel_x, pixel_y));
    down1_btn.press           (down && down1_btn.contains(pixel_x, pixel_y));
    up2_btn.press             (down && up2_btn.contains(pixel_x, pixel_y));
    down2_btn.press           (down && down2_btn.contains(pixel_x, pixel_y));
    up3_btn.press             (down && up3_btn.contains(pixel_x, pixel_y));
    down3_btn.press           (down && down3_btn.contains(pixel_x, pixel_y));
    up4_btn.press             (down && up4_btn.contains(pixel_x, pixel_y));
    down4_btn.press           (down && down4_btn.contains(pixel_x, pixel_y));
    Save_Movement_btn.press   (down && Save_Movement_btn.contains(pixel_x, pixel_y));


    if (up1_btn.justReleased())             up1_btn.drawButton();
    if (down1_btn.justReleased())           down1_btn.drawButton();
    if (up2_btn.justReleased())             up2_btn.drawButton();  
    if (down2_btn.justReleased())           down2_btn.drawButton();
    if (up3_btn.justReleased())             up3_btn.drawButton();
    if (down3_btn.justReleased())           down3_btn.drawButton();
    if (up4_btn.justReleased())             up4_btn.drawButton();
    if (down4_btn.justReleased())           down4_btn.drawButton();
    if (Save_Movement_btn.justReleased())   Save_Movement_btn.drawButton();
    }
