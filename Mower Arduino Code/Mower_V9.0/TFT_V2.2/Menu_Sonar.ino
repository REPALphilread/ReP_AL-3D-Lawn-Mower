void Print_Sonar_Menu() {  
    tft.fillScreen(BLACK);

    Serial.println("RX Sonar");
    Menu_Active = 10;                           // Code to tell the Mower MEGA which data to transmit.
    Send_Menu_Selected_To_Mower_MEGA();         // Send the code to the Mower MEGA which data should be transfered
    delay(RX_Delay + 1200);                            // Wait time for the Mower MEGA to transmit the data.
    Receive_7_Data_Sets();                      // Recieve data sets from the Mower MEGA
    Sonar_1_Activate = Data1;                   // Fill the variable values with the data sets
    Sonar_2_Activate = Data2;
    Sonar_3_Activate = Data3;
    maxdistancesonar = Data4;
    Max_Sonar_Hit    = Data5;
    Data6            = 0;
    Data7            = 0;
    Clear_Data_Streams();

    if (Debug_RX_Transfer == 1) {              // Display the received values on the TFT Screen if required.        
      Set_TFT_Screen_Pos();
      tft.print(F("S1_ON = "));
      tft.println(Sonar_1_Activate);
      tft.print(F("S2_ON = "));
      tft.println(Sonar_2_Activate);
      tft.print(F("S3_ON = "));
      tft.println(Sonar_3_Activate);
      tft.print(F("Max_Dist = "));
      tft.println(maxdistancesonar);
      tft.print(F("Sensitivity = "));
      tft.println(Max_Sonar_Hit);
      tft.println(F(" ")); 
      delay(TFT_Check);
      tft.fillScreen(BLACK);     
      }

    
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
    
    if (Value_1 == 1) OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
    if (Value_1 == 0) OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
    OPTION1_BTN.drawButton(false);


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
   
    if (Value_2 == 1) OPTION2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
    if (Value_2 == 0) OPTION2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
    
    OPTION2_BTN.drawButton(false);



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
   
 
    if (Value_3 == 1) OPTION3_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
    if (Value_3 == 0) OPTION3_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
    
    OPTION3_BTN.drawButton(false);

   
    
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

 
    UP4_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    DOWN4_BTN.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);

    UP4_BTN.drawButton(false);
    DOWN4_BTN.drawButton(false);


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

 
    UP5_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    DOWN5_BTN.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);

    UP5_BTN.drawButton(false);
    DOWN5_BTN.drawButton(false);  



// Save Button

    SAVE_BTN.initButton(&tft, 425, 278, 80, 40, WHITE, CYAN, BLACK, "Save", 2);
    SAVE_BTN.drawButton(false);



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
 if (OPTION1_BTN.justPressed() ) {

        bool Changed = 0;

        if ((Sonar_2_Activate == 1) && (Changed ==0))  {
          Sonar_2_Activate = 0;
          Changed = 1;
          OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
          OPTION1_BTN.drawButton(false);
          }
        
        if ((Sonar_2_Activate == 0) && (Changed ==0)) {
          Sonar_2_Activate = 1;
          Changed = 1;
          OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
          OPTION1_BTN.drawButton(false);
        }
  delay(200);
 }


//If the ON/OFF Sonar 1 is pressed (up or down)
 if (OPTION2_BTN.justPressed() ) {

        bool Changed = 0;

        Button_X = Start_X + Button_W + Column_Spacing + (0.5 * Button_W);
        Button_Y = Start_Y + Offset_Btn + (0.2 * Button_H);

        if ((Sonar_1_Activate == 1) && (Changed ==0))  {
          Sonar_1_Activate = 0;
          Changed = 1;
          OPTION2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
          OPTION2_BTN.drawButton(false);
          }
        
        if ((Sonar_1_Activate == 0) && (Changed ==0)) {
          Sonar_1_Activate = 1;
          Changed = 1;
          OPTION2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
          OPTION2_BTN.drawButton(false);
        }
 delay(200);
 }


//If the ON/OFF Sonar 3 is pressed (up or down)
 if (OPTION3_BTN.justPressed() ) {

        bool Changed = 0;

        Button_X = Start_X + Button_W + Column_Spacing + (0.5 * Button_W)+ Button_W + Column_Spacing;
        Button_Y = Start_Y + Offset_Btn + (0.2 * Button_H);

        if ((Sonar_3_Activate == 1) && (Changed ==0))  {
          Sonar_3_Activate  = 0;
          Changed = 1;
          OPTION3_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
          OPTION3_BTN.drawButton(false);
          }
        
        if ((Sonar_3_Activate  == 0) && (Changed ==0)) {
          Sonar_3_Activate  = 1;
          Changed = 1;
          OPTION3_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
          OPTION3_BTN.drawButton(false);
        }
 delay(200);
 }


//If the Button 4 is pressed (up or down)
 if ((UP4_BTN.justPressed() )  || (DOWN4_BTN.justPressed())) {
        
        Value_All = maxdistancesonar;
        Value_X_All = Value_X4;
        Value_Y_All = Value_Y4;
    
    // Actions if UP is pressed
    if (UP4_BTN.justPressed()) {
        Clear_Old_Value_Sonar();       
        UP4_BTN.drawButton(true);
        maxdistancesonar = maxdistancesonar + 1;
        Value_All = maxdistancesonar;
        Print_New_Value_Sonar();
        }


    // Action if down is pressed
    if (DOWN4_BTN.justPressed()) {
        Clear_Old_Value_Sonar();
        DOWN4_BTN.drawButton(true);
        maxdistancesonar = maxdistancesonar - 1;
        if (maxdistancesonar < 10) maxdistancesonar = 10;
        Value_All = maxdistancesonar;
        Print_New_Value_Sonar();
        }
    }


//If the Button 5 is pressed (up or down)
 if ((UP5_BTN.justPressed() )  || (DOWN5_BTN.justPressed())) {
        
        Value_All = Max_Sonar_Hit;
        Value_X_All = Value_X5;
        Value_Y_All = Value_Y5;
    
    // Actions if UP is pressed
    if (UP5_BTN.justPressed()) {
        Clear_Old_Value_Sonar();       
        UP5_BTN.drawButton(true);
        Max_Sonar_Hit = Max_Sonar_Hit + 1;
        Value_All = Max_Sonar_Hit;
        Print_New_Value_Sonar();
        }


    // Action if down is pressed
    if (DOWN5_BTN.justPressed()) {
        Clear_Old_Value_Sonar();
        DOWN5_BTN.drawButton(true);
        Max_Sonar_Hit = Max_Sonar_Hit - 1;
        if (Max_Sonar_Hit < 1) Max_Sonar_Hit = 1;
        Value_All = Max_Sonar_Hit;
        Print_New_Value_Sonar();
        }
    }




 // Action if Sonar Save is pressed
 if (SAVE_BTN.justPressed()) {
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
    OPTION1_BTN.press    (down && OPTION1_BTN.contains(pixel_x, pixel_y));
    OPTION2_BTN.press    (down && OPTION2_BTN.contains(pixel_x, pixel_y));
    OPTION3_BTN.press    (down && OPTION3_BTN.contains(pixel_x, pixel_y));

    UP4_BTN.press    (down && UP4_BTN.contains(pixel_x, pixel_y));
    DOWN4_BTN.press  (down && DOWN4_BTN.contains(pixel_x, pixel_y));
    UP5_BTN.press    (down && UP5_BTN.contains(pixel_x, pixel_y));
    DOWN5_BTN.press  (down && DOWN5_BTN.contains(pixel_x, pixel_y));
    SAVE_BTN.press   (down && SAVE_BTN.contains(pixel_x, pixel_y));

    if (OPTION1_BTN.justReleased())     OPTION1_BTN.drawButton();
    if (OPTION2_BTN.justReleased())     OPTION2_BTN.drawButton();
    if (OPTION3_BTN.justReleased())     OPTION3_BTN.drawButton();
    
    if (UP4_BTN.justReleased())     UP4_BTN.drawButton();
    if (DOWN4_BTN.justReleased())   DOWN4_BTN.drawButton();

    if (UP5_BTN.justReleased())     UP5_BTN.drawButton();
    if (DOWN5_BTN.justReleased())   DOWN5_BTN.drawButton();
    
    if (SAVE_BTN.justReleased())   SAVE_BTN.drawButton();
}
