void Print_Rain_Sensor_Menu() {  

    tft.fillScreen(BLACK);
    if (Draw_Pictures == 1)   bmpDraw("Rain.bmp", 270, 60);      //Draw the mower picture
    delay(100);    
   
    // Framework for the + - buttons - setting the start position of the + button wil automatically then space the - button

    int Start_X = 10;
    int Start_Y = 50;
    int Menu_Btn_Space = 100;          // Space between the text and the -ve button
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
    tft.print(F("Rain Settings Menu"));  
    
    
    
    //Rain Sensor ON/OFF Button
    //------------------------------------------------------------
    
    int Label_X = Start_X;                           // Starting X Point.
    int Label_Y = Start_Y;                           // Starting Y Point

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("Rain Sensor ON/OFF"));  
    
    int Button_X = Label_X + (0.5 * Button_W);
    int Button_Y = Label_Y + Offset_Btn + (0.2 * Button_H);
    
    if (Rain_Sensor_Installed == 1) ONOFF1_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
    if (Rain_Sensor_Installed == 0) ONOFF1_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
    ONOFF1_btn.drawButton(false);


    //Button Row 2
    //------------------------------------------------------------
    
    Button_W  = 50;
    Label_X   = Label_X;
    Label_Y   = Label_Y + Menu_Spacing;
    Value_X2  = Label_X;                        // X Position of the item
    Value_Y2  = Label_Y + Offset_Btn;           // Y Position of the item
    Value_2   = Rain_Total_Hits_Go_Home;                           // Value to be modified in the menu

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);            // Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("Rain Sensitivity"));  

    
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



// Save Button

    Save_btn.initButton(&tft, 425, 278, 80, 40, WHITE, CYAN, BLACK, "Save", 2);
    Save_btn.drawButton(false);


}


void React_to_Button_Press_Rain() {

 // If the SONAR Sensor ON/OFF Button is pressed
 if (ONOFF1_btn.justPressed() ) {

        int Start_X = 10;
        int Start_Y = 50;
        int Button_W = 100;                // width of the button
        int Button_H = 40;                // height of the button
        int Offset_Btn = 25;
        int Column_Spacing = 200;         // Distance between the Left Hand and Right Hand Columns
        
        int Button_X = Start_X + (0.5 * Button_W);
        int Button_Y = Start_Y + Offset_Btn + (0.2 * Button_H);
        bool Changed = 0;

        if ((Rain_Sensor_Installed == 1) && (Changed ==0))  {
          Rain_Sensor_Installed = 0;
          Changed = 1;
          ONOFF1_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
          ONOFF1_btn.drawButton(false);
          }
        
        if ((Rain_Sensor_Installed == 0) && (Changed ==0)) {
          Rain_Sensor_Installed = 1;
          Changed = 1;
          ONOFF1_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
          ONOFF1_btn.drawButton(false);
        }
  delay(200);
 }



//If the Button 2 is pressed (up or down)
 if ((up2_btn.justPressed() )  || (down2_btn.justPressed())) {
        
        Value_All = Rain_Total_Hits_Go_Home;
        Value_X_All = Value_X2;
        Value_Y_All = Value_Y2;
    
    // Actions if UP is pressed
    if (up2_btn.justPressed()) {
        Clear_Old_Value_Rain();       
        up2_btn.drawButton(true);
        Rain_Total_Hits_Go_Home = Rain_Total_Hits_Go_Home + 1;
        Value_All = Rain_Total_Hits_Go_Home;
        Int_Float = 0;
        Print_New_Value_Rain();
        }


    // Action if down is pressed
    if (down2_btn.justPressed()) {
        Clear_Old_Value_Rain();
        down2_btn.drawButton(true);
        Rain_Total_Hits_Go_Home = Rain_Total_Hits_Go_Home - 1;
        if (Rain_Total_Hits_Go_Home < 1) Rain_Total_Hits_Go_Home = 1;
        Value_All = Rain_Total_Hits_Go_Home;
        Int_Float = 0;
        Print_New_Value_Rain();
        }
    }

 
 // Action if Rain Save is pressed
 if (Save_btn.justPressed()) {
         Menu_Complete_Rain = true;
         tft.fillScreen(BLACK);
         Serial.println(F("Rain Data Saved and TX"));
         Menu_Active = 912;
         Send_Menu_Selected_To_Mower_MEGA();
         Transmit_Saved_Rain_Sensor_Values();
         Print_Sensors_Menu();
         }  


        
}



void Clear_Old_Value_Rain() {
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

void Print_New_Value_Rain() {        

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




void Sense_Button_Press_Rain() {
    down = Touch_getXY();
    ONOFF1_btn.press (down && ONOFF1_btn.contains(pixel_x, pixel_y));
    up2_btn.press    (down && up2_btn.contains(pixel_x, pixel_y));
    down2_btn.press  (down && down2_btn.contains(pixel_x, pixel_y));
    Save_btn.press   (down && Save_btn.contains(pixel_x, pixel_y));

    if (ONOFF1_btn.justReleased())  ONOFF1_btn.drawButton();
    if (up2_btn.justReleased())     up2_btn.drawButton();
    if (down2_btn.justReleased())   down2_btn.drawButton();
    if (Save_btn.justReleased())    Save_btn.drawButton();
}
