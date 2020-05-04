void Print_TFT_Menu() {  

    //if (Draw_Pictures == 1)   bmpDraw("Rain.bmp", 270, 60);      //Draw the mower picture
    delay(100);    
   
    // Framework for the + - buttons - setting the start position of the + button wil automatically then space the - button

    int Start_X = 10;
    int Start_Y = 50;
    int Menu_Btn_Space = 100;          // Space between the text and the -ve button
    int Button_W = 120;                // width of the button
    int Button_H = 60;                // height of the button
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
    tft.print(F("TFT Screen Options"));  
    
    
    
    // Full Pictures ON/OFF
    //------------------------------------------------------------
    
    int Label_X = Start_X;                           // Starting X Point.
    int Label_Y = Start_Y;                           // Starting Y Point

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("TFT Pictures ON/OFF"));  
    
    int Button_X = Label_X + (0.5 * Button_W);
    int Button_Y = Label_Y + Offset_Btn + (0.3 * Button_H);

    Value_X1 = Button_X;
    Value_Y1 = Button_Y;
    
    if (Draw_Pictures == 1) ONOFF1_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
    if (Draw_Pictures == 0) ONOFF1_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
    ONOFF1_btn.drawButton(false);


    //Turn Over sensor

    Label_X = Start_X;                           // Starting X Point.
    Label_Y = Button_Y + Menu_Spacing;                           // Starting Y Point

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("SPARE"));  
    
    Button_X = Label_X + (0.5 * Button_W);
    Button_Y = Label_Y + Offset_Btn + (0.3 * Button_H);   

    Value_X2 = Button_X;
    Value_Y2 = Button_Y;
    
    if (SPARE == 1) ONOFF2_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
    if (SPARE == 0) ONOFF2_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
    ONOFF2_btn.drawButton(false);



// Save Button

    Save_btn.initButton(&tft, 425, 278, 80, 40, WHITE, CYAN, BLACK, "Save", 2);
    Save_btn.drawButton(false);


}


void React_to_Button_Press_TFT_Setup() {

 // If the Angle Sensor Button is pressed
 if (ONOFF1_btn.justPressed() ) {

        int Button_W = 120;                // width of the button
        int Button_H = 60;                // height of the button
        
        int Button_X = Value_X1;
        int Button_Y = Value_Y1;
        bool Changed = 0;

        if ((Draw_Pictures == 1) && (Changed ==0))  {
          Draw_Pictures = 0;
          Changed = 1;
          ONOFF1_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
          ONOFF1_btn.drawButton(false);
          }
        
        if ((Draw_Pictures == 0) && (Changed ==0)) {
          Draw_Pictures = 1;
          Changed = 1;
          ONOFF1_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
          ONOFF1_btn.drawButton(false);
        }
  delay(200);
 }


 // If the Tip Over Sensor Button is pressed
 if (ONOFF2_btn.justPressed() ) {

        int Button_W = 120;                // width of the button
        int Button_H = 60;                // height of the button
        
        int Button_X = Value_X2;
        int Button_Y = Value_Y2;
        bool Changed = 0;

        if ((SPARE == 1) && (Changed ==0))  {
          SPARE = 0;
          Changed = 1;
          ONOFF2_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
          ONOFF2_btn.drawButton(false);
          }
        
        if ((SPARE == 0) && (Changed ==0)) {
          SPARE = 1;
          Changed = 1;
          ONOFF2_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
          ONOFF2_btn.drawButton(false);
        }
  delay(200);
 }

 
 // Action if Tip ensor Save is pressed
 if (Save_btn.justPressed()) {
         Menu_Complete_TFT_Setup = true;
         tft.fillScreen(BLACK);
         Serial.println(F("Tip Sensor Data Saved and TX"));
         EEPROM.write(2, 1);
         EEPROM.write(3, Draw_Pictures); 
         Print_Settings_2_Menu();
         }  


        
}


void Sense_Button_Press_TFT_Setup() {
    down = Touch_getXY();
    ONOFF1_btn.press (down && ONOFF1_btn.contains(pixel_x, pixel_y));
    ONOFF2_btn.press (down && ONOFF2_btn.contains(pixel_x, pixel_y));
    Save_btn.press   (down && Save_btn.contains(pixel_x, pixel_y));

    if (ONOFF1_btn.justReleased())  ONOFF1_btn.drawButton();
    if (ONOFF2_btn.justReleased())  ONOFF2_btn.drawButton();
    if (Save_btn.justReleased())    Save_btn.drawButton();
}
