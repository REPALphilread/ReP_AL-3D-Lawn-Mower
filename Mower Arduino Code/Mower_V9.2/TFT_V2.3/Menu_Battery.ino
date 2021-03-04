void Print_Battery_Menu() {  
    tft.fillScreen(BLACK);


    Serial.println(F("Battery Screen Selected"));
    Menu_Active = 26;                           // Code to tell the Mower MEGA which data to transmit.
    Send_Menu_Selected_To_Mower_MEGA();         // Send the code to the Mower MEGA which data should be transfered
    delay(RX_Delay + 1200);                     // Wait time for the Mower MEGA to transmit the data.
    Receive_7_Data_Sets();                      // Recieve data sets from the Mower MEGA
    Battery_Min               = Data1;          // Return this value back to a float.
    Battery_Min               = Battery_Min/10; 
    Low_Battery_Instances_Chg = Data2;
    Data3 = 0;
    Data4 = 0;
    Data5 = 0;
    Data6 = 0;
    Data7 = 0;
    Clear_Data_Streams();

    if (Debug_RX_Transfer == 1) {              // Display the received values on the TFT Screen if required.        
      Set_TFT_Screen_Pos();
      tft.print(F("Batt_Min = "));
      tft.println(Battery_Min);
      tft.print(F("Batt_Seny = "));
      tft.println(Low_Battery_Instances_Chg);
      delay(TFT_Check);
      tft.fillScreen(BLACK);     
      }
         
    if (Draw_Pictures == 1)   bmpDraw("batterypack.bmp", 270, 60);      //Draw the mower picture
    delay(100);    
    
    // Framework for the + - buttons - setting the start position of the + button wil automatically then space the - button

    int Start_X = 10;
    int Start_Y = 50;
    int Menu_Btn_Space = 100;          // Space between the text and the -ve button
    int Button_W = 50;                // width of the button
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
    tft.print(F("Battery Settings Menu"));  
    
    
    
    //Button Row 1
    //------------------------------------------------------------
    
    int Label_X = Start_X;                           // Starting X Point.
    int Label_Y = Start_Y;                           // Starting Y Point
    Value_X1    = Label_X;                      // X Position of the item
    Value_Y1    = Label_Y + Offset_Btn;         // Y Position of the item

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("Bsttery Min Voltage"));  

    
    int Button_X = Value_X1 + Menu_Btn_Space;
    int Button_Y = Value_Y1 + (0.2 * Button_H);
   
    tft.setTextSize(Txt_Size_Value); 
    tft.setTextColor(RED, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Value_X1, Value_Y1);            // Text Coordinates X, Y
    tft.print(Battery_Min);    

 
    UP1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    DOWN1_BTN.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);

    UP1_BTN.drawButton(false);
    DOWN1_BTN.drawButton(false);


    //Button Row 2
    //------------------------------------------------------------
    
    Label_X   = Label_X;
    Label_Y   = Label_Y + Menu_Spacing;
    Value_X2  = Label_X;                        // X Position of the item
    Value_Y2  = Label_Y + Offset_Btn;           // Y Position of the item
    Value_2   = Low_Battery_Instances_Chg;                           // Value to be modified in the menu

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);            // Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("Battery Sensitivity"));  

    
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





// Save Button

    SAVE_BTN.initButton(&tft, 425, 278, 80, 40, WHITE, CYAN, BLACK, "Save", 2);
    SAVE_BTN.drawButton(false);


}






void React_to_Button_Press_Battery() {


//If the Button 1 is pressed (up or down)
 if ((UP1_BTN.justPressed() )  || (DOWN1_BTN.justPressed())) {
        
        Value_All_Float = Battery_Min;
        Value_X_All = Value_X1;
        Value_Y_All = Value_Y1;
    
    // Actions if UP is pressed
    if (UP1_BTN.justPressed()) {
        Clear_Old_Value_Battery();       
        UP1_BTN.drawButton(true);
        Battery_Min = Battery_Min + 0.1;
        if (Battery_Min > 12.5) Battery_Min = 12.5;
        Value_All_Float = Battery_Min;
        Int_Float = 1;
        Print_New_Value_Battery();
        Int_Float = 0;
        }


    // Action if down is pressed
    if (DOWN1_BTN.justPressed()) {
        Clear_Old_Value_Battery();
        DOWN1_BTN.drawButton(true);
        Battery_Min = Battery_Min - 0.1;
        if (Battery_Min < 10.5) Battery_Min = 10.5;
        Value_All_Float = Battery_Min;
        Int_Float = 1;
        Print_New_Value_Battery();
        Int_Float = 0;
        }
    }

//If the Button 2 is pressed (up or down)
 if ((UP2_BTN.justPressed() )  || (DOWN2_BTN.justPressed())) {
        
        Value_All = Low_Battery_Instances_Chg;
        Value_X_All = Value_X2;
        Value_Y_All = Value_Y2;
    
    // Actions if UP is pressed
    if (UP2_BTN.justPressed()) {
        Clear_Old_Value_Battery();       
        UP2_BTN.drawButton(true);
        Low_Battery_Instances_Chg = Low_Battery_Instances_Chg + 1;
        Value_All = Low_Battery_Instances_Chg;
        Int_Float = 0;
        Print_New_Value_Battery();
        }


    // Action if down is pressed
    if (DOWN2_BTN.justPressed()) {
        Clear_Old_Value_Battery();
        DOWN2_BTN.drawButton(true);
        Low_Battery_Instances_Chg = Low_Battery_Instances_Chg - 1;
        if (Low_Battery_Instances_Chg < 1) Low_Battery_Instances_Chg = 1;
        Value_All = Low_Battery_Instances_Chg;
        Int_Float = 0;
        Print_New_Value_Battery();
        }
    }

 
 // Action if Save is pressed
 if (SAVE_BTN.justPressed()) {
         Menu_Complete_Battery = true;
         tft.fillScreen(BLACK);
         Serial.println(F("Battery Data Saved and TX"));
         Menu_Active = 911;
         Send_Menu_Selected_To_Mower_MEGA();
         Transmit_Saved_Battery_Values();
         Print_Sensors_Menu();
         }  


        
}



void Clear_Old_Value_Battery() {
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

void Print_New_Value_Battery() {        

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




void Sense_Button_Press_Battery() {
    down = Touch_getXY();
    UP1_BTN.press    (down && UP1_BTN.contains(pixel_x, pixel_y));
    DOWN1_BTN.press  (down && DOWN1_BTN.contains(pixel_x, pixel_y));
    UP2_BTN.press    (down && UP2_BTN.contains(pixel_x, pixel_y));
    DOWN2_BTN.press  (down && DOWN2_BTN.contains(pixel_x, pixel_y));
    SAVE_BTN.press   (down && SAVE_BTN.contains(pixel_x, pixel_y));

    if (UP1_BTN.justReleased())     UP1_BTN.drawButton();
    if (DOWN1_BTN.justReleased())   DOWN1_BTN.drawButton();
    
    if (UP2_BTN.justReleased())     UP2_BTN.drawButton();
    if (DOWN2_BTN.justReleased())   DOWN2_BTN.drawButton();



    if (SAVE_BTN.justReleased())   SAVE_BTN.drawButton();
}
