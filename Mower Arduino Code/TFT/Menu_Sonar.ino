void Print_Sonar_Menu() {  
    tft.fillScreen(BLACK);
    if (Draw_Pictures == 1) bmpDraw("Sensors.bmp", 0, 80);      //Draw the mower picture
    delay(100); 
    
    // Framework for the + - buttons - setting the start position of the + button wil automatically then space the - button

    int Start_X = 20;
    int Start_Y = 60;
    int Menu_Btn_Space = 80;          // Space between the text and the -ve button
    int Button_W = 70;                // width of the button
    int Button_H = 40;                // height of the button
    int Button_Spacing = 5;           // Space between the -ve and +ve buttons
    int Txt_Size_Label = 1;           // Test size iof the label above the value
    Txt_Size_Value = 2;               // Text size of the value that is changing
    int Menu_Spacing = 65;            // Distance between the Menu Items (bottom of the last button to the label of the next item)
    int Offset_Btn = 25;
    int Txt_Size_Main_Menu = 2;
    int Column_Spacing = 50;         // Distance between the Left Hand and Right Hand Columns


    // Main Menu Title
    tft.setTextSize(Txt_Size_Main_Menu); 
    tft.setTextColor(GREEN, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(10, 10);            // Text Coordinates X, Y
    tft.print(F("Sonar Settings Menu"));  
    
    
    
    //Sonar ON/OFF 2 Buttons
    //------------------------------------------------------------
    
    int Label_X = Start_X;                           // Starting X Point.
    int Label_Y = Start_Y;                           // Starting Y Point
    Value_1     = Sonar_2_Activate;                                 // 1 is on and 0 is off

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("Sonar 2 ON/OFF"));  
    
    int Button_X = Label_X + (0.5 * Button_W);
    int Button_Y = Label_Y + Offset_Btn + (0.2 * Button_H);
    
    if (Value_1 == 1) ONOFF1_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
    if (Value_1 == 0) ONOFF1_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
    ONOFF1_btn.drawButton(false);


    //Sonar ON/OFF 1 Buttons
    //------------------------------------------------------------
    
    Label_X   = Label_X + Button_W + Column_Spacing;
    Label_Y   = Start_Y;
    Value_2   = Sonar_1_Activate;                            // Value to be modified in the menu

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);            // Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("Sonar 1 ON/OFF"));  

    
    Button_X = Label_X + (0.5 * Button_W);
    Button_Y = Label_Y + Offset_Btn + (0.2 * Button_H);
   
    if (Value_2 == 1) ONOFF2_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
    if (Value_2 == 0) ONOFF2_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
    
    ONOFF2_btn.drawButton(false);



    //SONAR ON/OFF 3 Butons
    //------------------------------------------------------------
    
    Label_X   = Label_X + Button_W + Column_Spacing;
    Label_Y   = Start_Y;
    Value_3   = Sonar_3_Activate;                            // Value to be modified in the menu

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("Sonar 3 ON/OFF"));  
    
    Button_X = Label_X + (0.5 * Button_W);
    Button_Y = Label_Y + Offset_Btn + (0.2 * Button_H);
   
 
    if (Value_3 == 1) ONOFF3_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
    if (Value_3 == 0) ONOFF3_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
    
    ONOFF3_btn.drawButton(false);

   
    
    //Button Row 4
    //------------------------------------------------------------
    
    Label_X   = 270;
    Label_Y   = 125;
    Value_X4  = Label_X;                       // X Position of the item
    Value_Y4  = Label_Y + Offset_Btn;          // Y Position of the item
    Value_4   = maxdistancesonar;                            // Value to be modified in the menu

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("Sonar Distance / cm"));  

    
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


    //Button Row 5 (Column 2)
    //------------------------------------------------------------
    
    Label_X   = Label_X;
    Label_Y   = Label_Y + Menu_Spacing;
    Value_X5  = Label_X;                       // X Position of the item
    Value_Y5  = Label_Y + Offset_Btn;          // Y Position of the item
    Value_5   = Max_Sonar_Hit;                            // Value to be modified in the menu

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("Sonar Sensitivity / hits"));  

    
    Button_X = Value_X5 + Menu_Btn_Space;
    Button_Y = Value_Y5 + (0.2 * Button_H);
   
    tft.setTextSize(Txt_Size_Value); 
    tft.setTextColor(RED, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Value_X5, Value_Y5);            // Text Coordinates X, Y
    tft.print(Value_5);    

 
    up5_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    down5_btn.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);

    up5_btn.drawButton(false);
    down5_btn.drawButton(false);  



// Save Button

    Save_btn.initButton(&tft, 425, 278, 80, 40, WHITE, CYAN, BLACK, "Save", 2);
    Save_btn.drawButton(false);



}

void React_to_Button_Press_Sonar() {

    int Start_X = 20;
    int Start_Y = 60;
    int Button_W = 70;                // width of the button
    int Button_H = 40;                // height of the button
    int Offset_Btn = 25;
    int Column_Spacing = 50;         // Distance between the Left Hand and Right Hand Columns
    int Button_X = Start_X + (0.5 * Button_W);
    int Button_Y = Start_Y + Offset_Btn + (0.2 * Button_H);
    


//If the ON/OFF Sonar 2 is pressed (up or down)
 if (ONOFF1_btn.justPressed() ) {

        bool Changed = 0;

        if ((Sonar_2_Activate == 1) && (Changed ==0))  {
          Sonar_2_Activate = 0;
          Changed = 1;
          ONOFF1_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
          ONOFF1_btn.drawButton(false);
          }
        
        if ((Sonar_2_Activate == 0) && (Changed ==0)) {
          Sonar_2_Activate = 1;
          Changed = 1;
          ONOFF1_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
          ONOFF1_btn.drawButton(false);
        }
  delay(200);
 }


//If the ON/OFF Sonar 1 is pressed (up or down)
 if (ONOFF2_btn.justPressed() ) {

        bool Changed = 0;

        Button_X = Start_X + Button_W + Column_Spacing + (0.5 * Button_W);
        Button_Y = Start_Y + Offset_Btn + (0.2 * Button_H);

        if ((Sonar_1_Activate == 1) && (Changed ==0))  {
          Sonar_1_Activate = 0;
          Changed = 1;
          ONOFF2_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
          ONOFF2_btn.drawButton(false);
          }
        
        if ((Sonar_1_Activate == 0) && (Changed ==0)) {
          Sonar_1_Activate = 1;
          Changed = 1;
          ONOFF2_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
          ONOFF2_btn.drawButton(false);
        }
 delay(200);
 }


//If the ON/OFF Sonar 3 is pressed (up or down)
 if (ONOFF3_btn.justPressed() ) {

        bool Changed = 0;

        Button_X = Start_X + Button_W + Column_Spacing + (0.5 * Button_W)+ Button_W + Column_Spacing;
        Button_Y = Start_Y + Offset_Btn + (0.2 * Button_H);

        if ((Sonar_3_Activate == 1) && (Changed ==0))  {
          Sonar_3_Activate  = 0;
          Changed = 1;
          ONOFF3_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
          ONOFF3_btn.drawButton(false);
          }
        
        if ((Sonar_3_Activate  == 0) && (Changed ==0)) {
          Sonar_3_Activate  = 1;
          Changed = 1;
          ONOFF3_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
          ONOFF3_btn.drawButton(false);
        }
 delay(200);
 }


//If the Button 4 is pressed (up or down)
 if ((up4_btn.justPressed() )  || (down4_btn.justPressed())) {
        
        Value_All = maxdistancesonar;
        Value_X_All = Value_X4;
        Value_Y_All = Value_Y4;
    
    // Actions if UP is pressed
    if (up4_btn.justPressed()) {
        Clear_Old_Value_Sonar();       
        up4_btn.drawButton(true);
        maxdistancesonar = maxdistancesonar + 1;
        Value_All = maxdistancesonar;
        Print_New_Value_Sonar();
        }


    // Action if down is pressed
    if (down4_btn.justPressed()) {
        Clear_Old_Value_Sonar();
        down4_btn.drawButton(true);
        maxdistancesonar = maxdistancesonar - 1;
        if (maxdistancesonar < 10) maxdistancesonar = 10;
        Value_All = maxdistancesonar;
        Print_New_Value_Sonar();
        }
    }


//If the Button 5 is pressed (up or down)
 if ((up5_btn.justPressed() )  || (down5_btn.justPressed())) {
        
        Value_All = Max_Sonar_Hit;
        Value_X_All = Value_X5;
        Value_Y_All = Value_Y5;
    
    // Actions if UP is pressed
    if (up5_btn.justPressed()) {
        Clear_Old_Value_Sonar();       
        up5_btn.drawButton(true);
        Max_Sonar_Hit = Max_Sonar_Hit + 1;
        Value_All = Max_Sonar_Hit;
        Print_New_Value_Sonar();
        }


    // Action if down is pressed
    if (down5_btn.justPressed()) {
        Clear_Old_Value_Sonar();
        down5_btn.drawButton(true);
        Max_Sonar_Hit = Max_Sonar_Hit - 1;
        if (Max_Sonar_Hit < 1) Max_Sonar_Hit = 1;
        Value_All = Max_Sonar_Hit;
        Print_New_Value_Sonar();
        }
    }




 // Action if Sonar Save is pressed
 if (Save_btn.justPressed()) {
         Menu_Complete_Sonar = true;
         tft.fillScreen(BLACK);
         Serial.println(F("Sonar Data Saved and TX"));
         Menu_Active = 910;
         Send_Menu_Selected_To_Mower_MEGA();
         Transmit_Save_Sonar_Values();
         Print_Sensors_Menu();
         }  

        
}



void Clear_Old_Value_Sonar() {
        // Draws over the previous Value in Black text to clear it.... !?
        tft.setTextSize(Txt_Size_Value); 
        tft.setTextColor(BLACK, BLACK);      //Text Colour/ Background Colour
        tft.setCursor(Value_X_All, Value_Y_All);            // Text Coordinates X, Y
        tft.print(Value_All);
        }


void Print_New_Value_Sonar() {        

        tft.setTextSize(Txt_Size_Value); 
        tft.setTextColor(RED, BLACK);      //Text Colour/ Background Colour
        tft.setCursor(Value_X_All, Value_Y_All);            // Text Coordinates X, Y
        tft.print(Value_All);
        Serial.println(Value_All);
        }
        



void Sense_Button_Press_Sonar() {
    down = Touch_getXY();
    ONOFF1_btn.press    (down && ONOFF1_btn.contains(pixel_x, pixel_y));
    ONOFF2_btn.press    (down && ONOFF2_btn.contains(pixel_x, pixel_y));
    ONOFF3_btn.press    (down && ONOFF3_btn.contains(pixel_x, pixel_y));

    up4_btn.press    (down && up4_btn.contains(pixel_x, pixel_y));
    down4_btn.press  (down && down4_btn.contains(pixel_x, pixel_y));
    up5_btn.press    (down && up5_btn.contains(pixel_x, pixel_y));
    down5_btn.press  (down && down5_btn.contains(pixel_x, pixel_y));
    Save_btn.press   (down && Save_btn.contains(pixel_x, pixel_y));

    if (ONOFF1_btn.justReleased())     ONOFF1_btn.drawButton();
    if (ONOFF2_btn.justReleased())     ONOFF2_btn.drawButton();
    if (ONOFF3_btn.justReleased())     ONOFF3_btn.drawButton();
    
    if (up4_btn.justReleased())     up4_btn.drawButton();
    if (down4_btn.justReleased())   down4_btn.drawButton();

    if (up5_btn.justReleased())     up5_btn.drawButton();
    if (down5_btn.justReleased())   down5_btn.drawButton();
    
    if (Save_btn.justReleased())   Save_btn.drawButton();
}
