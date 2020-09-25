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
    tft.print(F("WIFI APP"));  
    
    Button_X1 = Label_X + (0.5 * Button_W);
    Button_Y1 = Label_Y + Offset_Btn + (0.2 * Button_H);
    
    if (GPS_WIFI_Enabled == 0) OPTION1_BTN.initButton(&tft, Button_X1, Button_Y1, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
    if (GPS_WIFI_Enabled == 1) OPTION1_BTN.initButton(&tft, Button_X1, Button_Y1, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
    
    OPTION1_BTN.drawButton(false);

    
    //Simulation ON/OFF Mode Button
    //------------------------------------------------------------
    
    Label_X = Start_X;                           // Starting X Point.
    Label_Y = Label_Y + Menu_Spacing;            // Starting Y Point

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("SIMULATE FENCE IN APP"));  
    
    Button_X2 = Label_X + (0.5 * Button_W);
    Button_Y2 = Label_Y + Offset_Btn + (0.2 * Button_H);
    
    if (Simulation_Mode == 0) OPTION2_BTN.initButton(&tft, Button_X2, Button_Y2, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
    if (Simulation_Mode == 1) OPTION2_BTN.initButton(&tft, Button_X2, Button_Y2, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
    
    OPTION2_BTN.drawButton(false);


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
    tft.print(F("GPS Fence Activated"));  

    
    int Button_X = Value_X2 + Menu_Btn_Space;
    int Button_Y = Value_Y2 + (0.2 * Button_H);
   
    tft.setTextSize(Txt_Size_Value); 
    tft.setTextColor(RED, BLACK);                 //Text Colour/ Background Colour
    tft.setCursor(Value_X2, Value_Y2);            // Text Coordinates X, Y
    tft.print(Value_2);    

 
    UP2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    DOWN2_BTN.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);

    UP2_BTN.drawButton(false);
    DOWN2_BTN.drawButton(false);




// Create Fence

    Create_Fence_btn.initButton(&tft, 330, 90, 250, 50, WHITE, CYAN, BLACK, "New Fence", 2);
    Create_Fence_btn.drawButton(false);

// Save Button

    SAVE_BTN.initButton(&tft, 425, 278, 80, 40, WHITE, CYAN, BLACK, "Save", 2);
    SAVE_BTN.drawButton(false);


}


void React_to_Button_Press_GPS_Settings() {

    // Action if GPS ONOFF is pressed
    if (OPTION4_BTN.justPressed()) {
        
        bool Changed = 0;
        int Button_W = 160;
        int Button_H = 60;
        int Menu_Spacing = 20; 
        int Column_Spacing = 200; 
     
        int Button_X = Pos_X2;
        int Button_Y = Pos_Y2;  
      
        if ((GPS_Enabled == 1) && (Changed == 0))  {
          GPS_Enabled  = 0;
          Changed = 1;
          OPTION4_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "GPS OFF", 2);
          OPTION4_BTN.drawButton(false);
          }
        
        if ((GPS_Enabled  == 0) && (Changed == 0)) {
          GPS_Enabled  = 1;
          Changed = 1;
          OPTION4_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, BLACK, GREEN, BLACK, "GPS ON", 2);
          OPTION4_BTN.drawButton(false);
        }          

    }


 // If the WIFI APP ON/OFF Button is pressed
 if (OPTION1_BTN.justPressed() ) {

        int Button_W = 150;                // width of the button
        int Button_H = 40;                // height of the button
        int Offset_Btn = 25;
        int Column_Spacing = 200;         // Distance between the Left Hand and Right Hand Columns
        bool Changed = 0;

        if (( GPS_WIFI_Enabled  == 1) && (Changed ==0 )) {
          GPS_WIFI_Enabled = 0;
          Changed = 1;
          OPTION1_BTN.initButton(&tft, Button_X1, Button_Y1, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
          OPTION1_BTN.drawButton(false);
        }
        if (( GPS_WIFI_Enabled == 0) && (Changed ==0 ))  {
          GPS_WIFI_Enabled  = 1;
          Changed = 1;
          OPTION1_BTN.initButton(&tft, Button_X1, Button_Y1, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
          OPTION1_BTN.drawButton(false);
          }
        
  delay(200);
 }


 // If the Simulation ON/OFF Button is pressed
 if (OPTION2_BTN.justPressed() ) {

        int Button_W = 150;                // width of the button
        int Button_H = 40;                // height of the button
        int Offset_Btn = 25;
        int Column_Spacing = 200;         // Distance between the Left Hand and Right Hand Columns
        bool Changed = 0;

        if (( Simulation_Mode == 1) && (Changed ==0 )) {
          Simulation_Mode = 0;
          Changed = 1;
          OPTION2_BTN.initButton(&tft, Button_X2, Button_Y2, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
          OPTION2_BTN.drawButton(false);
        }
        if (( Simulation_Mode == 0) && (Changed ==0 ))  {
          Simulation_Mode  = 1;
          Changed = 1;
          OPTION2_BTN.initButton(&tft, Button_X2, Button_Y2, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
          OPTION2_BTN.drawButton(false);
          }
        
  delay(200);
 }


//If the Button 2 is pressed (up or down)
 if ((UP2_BTN.justPressed() )  || (DOWN2_BTN.justPressed())) {
        
        Value_All = Fence;
        Value_X_All = Value_X2;
        Value_Y_All = Value_Y2;
    
    // Actions if UP is pressed
    if (UP2_BTN.justPressed()) {
        Clear_Old_Value_GPS();       
        UP2_BTN.drawButton(true);
        Fence = Fence + 1;
        Value_All = Fence;
        Int_Float = 0;
        Print_New_Value_GPS();
        }


    // Action if down is pressed
    if (DOWN2_BTN.justPressed()) {
        Clear_Old_Value_GPS();
        DOWN2_BTN.drawButton(true);
        Fence = Fence - 1;
        if (Fence < 1) Fence = 1;
        Value_All = Fence;
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
 if (SAVE_BTN.justPressed()) {
         Menu_Complete_GPS_Settings = true;
         tft.fillScreen(BLACK);
         Serial.println(F("GPS Data Saved and TX"));
         Menu_Active = 95;                                  // Cancel the GPS menu hold on the NodeMCU
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
    OPTION1_BTN.press (down && OPTION1_BTN.contains(pixel_x, pixel_y));
    OPTION2_BTN.press (down && OPTION2_BTN.contains(pixel_x, pixel_y));
    UP2_BTN.press    (down && UP2_BTN.contains(pixel_x, pixel_y));
    DOWN2_BTN.press  (down && DOWN2_BTN.contains(pixel_x, pixel_y));
    UP3_BTN.press    (down && UP3_BTN.contains(pixel_x, pixel_y));
    DOWN3_BTN.press  (down && DOWN3_BTN.contains(pixel_x, pixel_y));
    UP4_BTN.press    (down && UP4_BTN.contains(pixel_x, pixel_y));
    DOWN4_BTN.press  (down && DOWN4_BTN.contains(pixel_x, pixel_y));
    Create_Fence_btn.press  (down && Create_Fence_btn.contains(pixel_x, pixel_y));
    SAVE_BTN.press   (down && SAVE_BTN.contains(pixel_x, pixel_y));

    if (OPTION1_BTN.justReleased())  OPTION1_BTN.drawButton();
    if (OPTION2_BTN.justReleased())  OPTION2_BTN.drawButton();
    if (UP2_BTN.justReleased())     UP2_BTN.drawButton();
    if (DOWN2_BTN.justReleased())   DOWN2_BTN.drawButton();
    if (UP3_BTN.justReleased())     UP3_BTN.drawButton();
    if (DOWN3_BTN.justReleased())   DOWN3_BTN.drawButton();
    if (UP4_BTN.justReleased())     UP4_BTN.drawButton();
    if (DOWN4_BTN.justReleased())   DOWN4_BTN.drawButton();
    if (Create_Fence_btn.justReleased())   Create_Fence_btn.drawButton();
    if (SAVE_BTN.justReleased())    SAVE_BTN.drawButton();
}
