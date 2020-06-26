void Print_GPS_Menu_Settings() {  

    tft.fillScreen(BLACK);
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
    tft.print(F("GPS Settings Menu"));  
    
    
    
    //GPS ON/OFF Mode Button
    //------------------------------------------------------------
    
    int Label_X = Start_X;                           // Starting X Point.
    int Label_Y = Start_Y;                           // Starting Y Point

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("GPS Setting"));  
    
    int Button_X = Label_X + (0.5 * Button_W);
    int Button_Y = Label_Y + Offset_Btn + (0.2 * Button_H);
    
    if (GPS_Mode == 0) ONOFF1_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, BLACK, "OFF", 2);
    if (GPS_Mode == 1) ONOFF1_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, YELLOW, BLACK, "ON", 2);
    if (GPS_Mode == 2) ONOFF1_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, BLUE, WHITE, "ON + APP", 2);
    
    ONOFF1_btn.drawButton(false);


    //GPS Fence Activate
    //------------------------------------------------------------
    
    Button_W  = 50;
    Label_X   = Label_X;
    Label_Y   = Label_Y + Menu_Spacing;
    Value_X2  = Label_X;                        // X Position of the item
    Value_Y2  = Label_Y + Offset_Btn;           // Y Position of the item
    Value_2   = Fence;                          // Value to be modified in the menu

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);            // Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("GPS Fence Activate"));  

    
    Button_X = Value_X2 + Menu_Btn_Space;
    Button_Y = Value_Y2 + (0.2 * Button_H);
   
    tft.setTextSize(Txt_Size_Value); 
    tft.setTextColor(RED, BLACK);                 //Text Colour/ Background Colour
    tft.setCursor(Value_X2, Value_Y2);            // Text Coordinates X, Y
    tft.print(Value_2);    

 
    up2_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    down2_btn.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);

    up2_btn.drawButton(false);
    down2_btn.drawButton(false);



    //Minimum GPS Lock
    //------------------------------------------------------------

    Label_X   = Label_X;
    Label_Y   = Label_Y + Menu_Spacing;
    Value_X3  = Label_X;                        // X Position of the item
    Value_Y3  = Label_Y + Offset_Btn;           // Y Position of the item
    Value_3   = Min_Sats;                           // Value to be modified in the menu

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);            // Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("Minimum Sat Lock"));  

    
    Button_X = Value_X3 + Menu_Btn_Space;
    Button_Y = Value_Y3 + (0.2 * Button_H);
   
    tft.setTextSize(Txt_Size_Value); 
    tft.setTextColor(RED, BLACK);                 //Text Colour/ Background Colour
    tft.setCursor(Value_X3, Value_Y3);            // Text Coordinates X, Y
    tft.print(Value_3);    

 
    up3_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    down3_btn.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);

    up3_btn.drawButton(false);
    down3_btn.drawButton(false);


    //Spare
    //------------------------------------------------------------

    Label_X   = Label_X;
    Label_Y   = Label_Y + Menu_Spacing;
    Value_X4  = Label_X;                        // X Position of the item
    Value_Y4  = Label_Y + Offset_Btn;           // Y Position of the item
    Value_4   = Spare;                           // Value to be modified in the menu

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);            // Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("Spare"));  

    
    Button_X = Value_X4 + Menu_Btn_Space;
    Button_Y = Value_Y4 + (0.2 * Button_H);
   
    tft.setTextSize(Txt_Size_Value); 
    tft.setTextColor(RED, BLACK);                 //Text Colour/ Background Colour
    tft.setCursor(Value_X4, Value_Y4);            // Text Coordinates X, Y
    tft.print(Value_4);    

 
    up4_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    down4_btn.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);

    up4_btn.drawButton(false);
    down4_btn.drawButton(false);


// Create Fence

    Create_Fence_btn.initButton(&tft, 330, 90, 250, 50, WHITE, CYAN, BLACK, "New Fence", 2);
    Create_Fence_btn.drawButton(false);

// Save Button

    Save_btn.initButton(&tft, 425, 278, 80, 40, WHITE, CYAN, BLACK, "Save", 2);
    Save_btn.drawButton(false);


}


void React_to_Button_Press_GPS_Settings() {

 // If the SONAR Sensor ON/OFF Button is pressed
 if (ONOFF1_btn.justPressed() ) {

        int Start_X = 10;
        int Start_Y = 50;
        int Button_W = 150;                // width of the button
        int Button_H = 40;                // height of the button
        int Offset_Btn = 25;
        int Column_Spacing = 200;         // Distance between the Left Hand and Right Hand Columns
        
        int Button_X = Start_X + (0.5 * Button_W);
        int Button_Y = Start_Y + Offset_Btn + (0.2 * Button_H);
        bool Changed = 0;

        if (( GPS_Mode == 3) && (Changed ==0 )) {
          GPS_Mode = 0;
          Changed = 1;
          ONOFF1_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, BLACK, "OFF", 2);
          ONOFF1_btn.drawButton(false);
        }
        if (( GPS_Mode == 0) && (Changed ==0 ))  {
          GPS_Mode = 1;
          Changed = 1;
          ONOFF1_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, YELLOW, BLACK, "ON", 2);
          ONOFF1_btn.drawButton(false);
          }
        
        if (( GPS_Mode == 1) && (Changed ==0 )) {
          GPS_Mode = 3;
          Changed = 1;
          ONOFF1_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, BLUE, WHITE, "ON + APP", 2);
          ONOFF1_btn.drawButton(false);
        }
  delay(200);
 }



//If the Button 2 is pressed (up or down)
 if ((up2_btn.justPressed() )  || (down2_btn.justPressed())) {
        
        Value_All = Fence;
        Value_X_All = Value_X2;
        Value_Y_All = Value_Y2;
    
    // Actions if UP is pressed
    if (up2_btn.justPressed()) {
        Clear_Old_Value_GPS();       
        up2_btn.drawButton(true);
        Fence = Fence + 1;
        Value_All = Fence;
        Int_Float = 0;
        Print_New_Value_GPS();
        }


    // Action if down is pressed
    if (down2_btn.justPressed()) {
        Clear_Old_Value_GPS();
        down2_btn.drawButton(true);
        Fence = Fence - 1;
        if (Fence < 1) Fence = 1;
        Value_All = Fence;
        Int_Float = 0;
        Print_New_Value_GPS();
        }
    }


//If the Button 2 is pressed (up or down)
 if ((up3_btn.justPressed() )  || (down3_btn.justPressed())) {
        
        Value_All = Turn_90_Delay_RH;
        Value_X_All = Value_X3;
        Value_Y_All = Value_Y3;
    
    // Actions if UP is pressed
    if (up3_btn.justPressed()) {
        Clear_Old_Value_GPS();       
        up3_btn.drawButton(true);
        Min_Sats = Min_Sats + 1;
        if (Min_Sats > 15) Min_Sats = 15;       
        Value_All = Min_Sats;
        Int_Float = 0;
        Print_New_Value_GPS();
        }


    // Action if down is pressed
    if (down3_btn.justPressed()) {
        Clear_Old_Value_GPS();
        down3_btn.drawButton(true);
        Min_Sats = Min_Sats - 1;
        if (Min_Sats < 5) Min_Sats = 5;
        Value_All = Min_Sats;
        Int_Float = 0;
        Print_New_Value_GPS();
        }
    }


//If the Button 4 is pressed (up or down)
 if ((up4_btn.justPressed() )  || (down4_btn.justPressed())) {
        
        Value_All = Move_to_next_line_delay;
        Value_X_All = Value_X4;
        Value_Y_All = Value_Y4;
    
    // Actions if UP is pressed
    if (up4_btn.justPressed()) {
        Clear_Old_Value_GPS();       
        up4_btn.drawButton(true);
        Spare = Spare + 100;
        Value_All = Spare;
        Int_Float = 0;
        Print_New_Value_GPS();
        }


    // Action if down is pressed
    if (down4_btn.justPressed()) {
        Clear_Old_Value_GPS();
        down4_btn.drawButton(true);
        Spare = Spare - 100;
        if (Spare < 100) Spare = 100;
        Value_All = Spare;
        Int_Float = 0;
        Print_New_Value_GPS();
        }
    }


 // Action if Create Fence is pressed
 if (Create_Fence_btn.justPressed()) {
          Menu_Complete_GPS_New_Fence = false;
          tft.fillScreen(BLACK);
          Serial.println(F("Create New GPS Fence"));
          Menu_Active = 16;
          Send_Menu_Selected_To_GPS_NodeMCU();         // Tell the Mower MEGA which menu on the TFT is selected
          Serial.println("RX GPS Values");       
          Print_GPS_New_Fence();
          
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_GPS_New_Fence == false) {
            Sense_Button_Press_GPS_New_Fence();
            React_to_Button_Press_GPS_New_Fence();
            }
         }
 
 // Action if GPS Save is pressed
 if (Save_btn.justPressed()) {
         Menu_Complete_GPS_Settings = true;
         tft.fillScreen(BLACK);
         Serial.println(F("GPS Data Saved and TX"));
         Menu_Active = 99;                                  // Cancel the GPS menu hold on the NodeMCU
         Send_Menu_Selected_To_GPS_NodeMCU();
         Transmit_Saved_GPS_Values();
         Print_Navigation_Menu();
         }  

       
}



void Clear_Old_Value_GPS() {
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

void Print_New_Value_GPS() {        

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




void Sense_Button_Press_GPS_Settings() {
    down = Touch_getXY();
    ONOFF1_btn.press (down && ONOFF1_btn.contains(pixel_x, pixel_y));
    up2_btn.press    (down && up2_btn.contains(pixel_x, pixel_y));
    down2_btn.press  (down && down2_btn.contains(pixel_x, pixel_y));
    up3_btn.press    (down && up3_btn.contains(pixel_x, pixel_y));
    down3_btn.press  (down && down3_btn.contains(pixel_x, pixel_y));
    up4_btn.press    (down && up4_btn.contains(pixel_x, pixel_y));
    down4_btn.press  (down && down4_btn.contains(pixel_x, pixel_y));
    Create_Fence_btn.press  (down && Create_Fence_btn.contains(pixel_x, pixel_y));
    Save_btn.press   (down && Save_btn.contains(pixel_x, pixel_y));

    if (ONOFF1_btn.justReleased())  ONOFF1_btn.drawButton();
    if (up2_btn.justReleased())     up2_btn.drawButton();
    if (down2_btn.justReleased())   down2_btn.drawButton();
    if (up3_btn.justReleased())     up3_btn.drawButton();
    if (down3_btn.justReleased())   down3_btn.drawButton();
    if (up4_btn.justReleased())     up4_btn.drawButton();
    if (down4_btn.justReleased())   down4_btn.drawButton();
    if (Create_Fence_btn.justReleased())   Create_Fence_btn.drawButton();
    if (Save_btn.justReleased())    Save_btn.drawButton();
}
