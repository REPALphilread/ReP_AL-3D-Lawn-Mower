void Print_Movement_Menu() {  

     // Framework for the buttons - setting the start position of the Quick start button wil automatically then space the other buttons
    tft.fillScreen(BLACK);
    
    Serial.println(F("RX Turns"));
    Menu_Active = 16;                           // Code to tell the Mower MEGA which data to transmit.
    Send_Menu_Selected_To_Mower_MEGA();         // Send the code to the Mower MEGA which data should be transfered
    delay(RX_Delay);                            // Wait time for the Mower MEGA to transmit the data.
    Receive_7_Data_Sets();                      // Recieve data sets from the Mower MEGA
    Max_Cycles_Straight  = Data1 * 10;          // Fill the variable values with the data sets
    Mower_Turn_Delay_Min = Data2 * 100;
    Mower_Turn_Delay_Max = Data3 * 100;
    Mower_Reverse_Delay  = Data4 * 100;
    Data5 = 0;
    Data6 = 0;
    Data7 = 0;
    Clear_Data_Streams();

    if (Debug_RX_Transfer == 1) {              // Display the received values on the TFT Screen if required.        
      Set_TFT_Screen_Pos();
      tft.print(F("Cycles Straight = "));
      tft.println(Max_Cycles_Straight);
      tft.print(F("Turn Delay Min = "));
      tft.println(Mower_Turn_Delay_Min);
      tft.print(F("Turn Delay Max= "));
      tft.println(Mower_Turn_Delay_Max);
      tft.print(F("Reverse Delay = "));
      tft.println(Mower_Reverse_Delay);
      tft.println(F(" ")); 
      delay(TFT_Check);
      tft.fillScreen(BLACK);     
      }    
    
    
    
    
    
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

 
    UP1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    DOWN1_BTN.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);

    UP1_BTN.drawButton(false);
    DOWN1_BTN.drawButton(false);
   
    
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

 
    UP4_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    DOWN4_BTN.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);

    UP4_BTN.drawButton(false);
    DOWN4_BTN.drawButton(false);

    
    
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

 
    UP2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    DOWN2_BTN.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);

    UP2_BTN.drawButton(false);
    DOWN2_BTN.drawButton(false);



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

 
    UP3_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    DOWN3_BTN.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);

    UP3_BTN.drawButton(false);
    DOWN3_BTN.drawButton(false);
    
    

// Save Button

    Save_Movement_btn.initButton(&tft, 425, 40, 80, 40, WHITE, CYAN, BLACK, "Save", 2);
    Save_Movement_btn.drawButton(false);
    
    }




void React_to_Button_Press_Movement() {

  //If the Button 1 Turn Angle Max is pressed (up or down)
   if ((UP1_BTN.justPressed() )  || (DOWN1_BTN.justPressed())) {
        Value_All = Value_1;
        Label_X = 90;
        Label_Y = 250  + Offset_Btn;
    
    // Actions if UP is pressed
    if (UP1_BTN.justPressed()) {
        Clear_Old_Value_Movement();       
        UP1_BTN.drawButton(true);
        Value_All = Value_All + 100;
        Value_1 = Value_All;
        Mower_Turn_Delay_Max = Value_1; 
        Print_New_Value_Movement();
        }


    // Action if down is pressed
    if (DOWN1_BTN.justPressed()) {
        Clear_Old_Value_Movement();
        DOWN1_BTN.drawButton(true);
        Value_All = Value_All - 100;
        if (Value_All < 500) Value_All = 500;
        if (Value_All < Mower_Turn_Delay_Min) Value_All = Mower_Turn_Delay_Min + 100;
        Value_1 = Value_All;
        Mower_Turn_Delay_Max = Value_1; 
        Print_New_Value_Movement();
        }
    
    }

  //If the Reverse Button 2 is pressed (up or down)
   if ((UP2_BTN.justPressed() )  || (DOWN2_BTN.justPressed())) {
        Value_All = Value_2;
        Label_X   = 310;
        Label_Y   = 230  + Offset_Btn;
    
    // Actions if UP is pressed
    if (UP2_BTN.justPressed()) {
        Clear_Old_Value_Movement();       
        UP2_BTN.drawButton(true);
        Value_All = Value_All + 100;
        Value_2 = Value_All;
        Mower_Reverse_Delay = Value_2;
        Print_New_Value_Movement();
        }


    // Action if down is pressed
    if (DOWN2_BTN.justPressed()) {
        Clear_Old_Value_Movement();
        DOWN2_BTN.drawButton(true);
        Value_All = Value_All - 100;
        if (Value_All < 500) Value_All = 500;
        Value_2 = Value_All;
        Mower_Reverse_Delay = Value_2;
        Print_New_Value_Movement();
        }
    
    }



  //If the Max Mow Length Button 3 is pressed (up or down)
   if ((UP3_BTN.justPressed() )  || (DOWN3_BTN.justPressed())) {
        Value_All = Value_3;
        Label_X   = 20;
        Label_Y   = 50  + Offset_Btn;
    
    // Actions if Max Mow Length UP is pressed
    if (UP3_BTN.justPressed()) {
        Clear_Old_Value_Movement();       
        UP3_BTN.drawButton(true);
        Value_All = Value_All + 5;
        Value_3 = Value_All;
        Max_Cycles_Straight = Value_3;
        Print_New_Value_Movement();
        }


    // Action if Max Mow Length down is pressed
    if (DOWN3_BTN.justPressed()) {
        Clear_Old_Value_Movement();
        DOWN3_BTN.drawButton(true);
        Value_All = Value_All - 5;
        if (Value_All < 20) Value_All = 20;
        Value_3 = Value_All;
        Max_Cycles_Straight = Value_3;
        Print_New_Value_Movement();
        }
    
    }


  //If the Turn Angle Min Button 4 is pressed (up or down)
   if ((UP4_BTN.justPressed() )  || (DOWN4_BTN.justPressed())) {
        Value_All = Value_4;
        Label_X   = 20;
        Label_Y   = 150  + Offset_Btn;
    
    // Actions if UP is pressed
    if (UP4_BTN.justPressed()) {
        Clear_Old_Value_Movement();       
        UP4_BTN.drawButton(true);
        Value_All = Value_All + 100;
        if (Value_All > Mower_Turn_Delay_Max) Value_All = Mower_Turn_Delay_Max - 100;
        Value_4 = Value_All;
        Mower_Turn_Delay_Min = Value_4; 
        Print_New_Value_Movement();
        }


    // Action if down is pressed
    if (DOWN4_BTN.justPressed()) {
        Clear_Old_Value_Movement();
        DOWN4_BTN.drawButton(true);
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
    UP1_BTN.press             (down && UP1_BTN.contains(pixel_x, pixel_y));
    DOWN1_BTN.press           (down && DOWN1_BTN.contains(pixel_x, pixel_y));
    UP2_BTN.press             (down && UP2_BTN.contains(pixel_x, pixel_y));
    DOWN2_BTN.press           (down && DOWN2_BTN.contains(pixel_x, pixel_y));
    UP3_BTN.press             (down && UP3_BTN.contains(pixel_x, pixel_y));
    DOWN3_BTN.press           (down && DOWN3_BTN.contains(pixel_x, pixel_y));
    UP4_BTN.press             (down && UP4_BTN.contains(pixel_x, pixel_y));
    DOWN4_BTN.press           (down && DOWN4_BTN.contains(pixel_x, pixel_y));
    Save_Movement_btn.press   (down && Save_Movement_btn.contains(pixel_x, pixel_y));


    if (UP1_BTN.justReleased())             UP1_BTN.drawButton();
    if (DOWN1_BTN.justReleased())           DOWN1_BTN.drawButton();
    if (UP2_BTN.justReleased())             UP2_BTN.drawButton();  
    if (DOWN2_BTN.justReleased())           DOWN2_BTN.drawButton();
    if (UP3_BTN.justReleased())             UP3_BTN.drawButton();
    if (DOWN3_BTN.justReleased())           DOWN3_BTN.drawButton();
    if (UP4_BTN.justReleased())             UP4_BTN.drawButton();
    if (DOWN4_BTN.justReleased())           DOWN4_BTN.drawButton();
    if (Save_Movement_btn.justReleased())   Save_Movement_btn.drawButton();
    }
