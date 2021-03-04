void Print_Rain_Sensor_Menu() {  

    tft.fillScreen(BLACK);

    Serial.println(F("RX Rain"));
    Menu_Active = 12;                           // Code to tell the Mower MEGA which data to transmit.
    Send_Menu_Selected_To_Mower_MEGA();         // Send the code to the Mower MEGA which data should be transfered
    delay(RX_Delay);                            // Wait time for the Mower MEGA to transmit the data.
    Receive_7_Data_Sets();                      // Recieve data sets from the Mower MEGA
    Rain_Sensor_Installed = Data1;              // Fill the variable values with the data sets
    Rain_Total_Hits_Go_Home = Data2;
    Data3 = 0;
    Data4 = 0;
    Data5 = 0;
    Data6 = 0;
    Data7 = 0;
    Clear_Data_Streams();

    if (Debug_RX_Transfer == 1) {              // Display the received values on the TFT Screen if required.        
      Set_TFT_Screen_Pos();
      tft.print(F("Rain_ON = "));
      tft.println(Rain_Sensor_Installed);
      tft.print(F("Sensitivity = "));
      tft.println(Rain_Total_Hits_Go_Home);
      tft.println(F(" ")); 
      delay(TFT_Check);
      tft.fillScreen(BLACK);     
      }

    
    
    
    
    
    
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
    
    if (Rain_Sensor_Installed == 1) OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
    if (Rain_Sensor_Installed == 0) OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
    OPTION1_BTN.drawButton(false);


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

 
    UP2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    DOWN2_BTN.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);

    UP2_BTN.drawButton(false);
    DOWN2_BTN.drawButton(false);



// Save Button

    SAVE_BTN.initButton(&tft, 425, 278, 80, 40, WHITE, CYAN, BLACK, "Save", 2);
    SAVE_BTN.drawButton(false);


}


void React_to_Button_Press_Rain() {

 // If the SONAR Sensor ON/OFF Button is pressed
 if (OPTION1_BTN.justPressed() ) {

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
          OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
          OPTION1_BTN.drawButton(false);
          }
        
        if ((Rain_Sensor_Installed == 0) && (Changed ==0)) {
          Rain_Sensor_Installed = 1;
          Changed = 1;
          OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
          OPTION1_BTN.drawButton(false);
        }
  delay(200);
 }



//If the Button 2 is pressed (up or down)
 if ((UP2_BTN.justPressed() )  || (DOWN2_BTN.justPressed())) {
        
        Value_All = Rain_Total_Hits_Go_Home;
        Value_X_All = Value_X2;
        Value_Y_All = Value_Y2;
    
    // Actions if UP is pressed
    if (UP2_BTN.justPressed()) {
        Clear_Old_Value_Rain();       
        UP2_BTN.drawButton(true);
        Rain_Total_Hits_Go_Home = Rain_Total_Hits_Go_Home + 1;
        Value_All = Rain_Total_Hits_Go_Home;
        Int_Float = 0;
        Print_New_Value_Rain();
        }


    // Action if down is pressed
    if (DOWN2_BTN.justPressed()) {
        Clear_Old_Value_Rain();
        DOWN2_BTN.drawButton(true);
        Rain_Total_Hits_Go_Home = Rain_Total_Hits_Go_Home - 1;
        if (Rain_Total_Hits_Go_Home < 1) Rain_Total_Hits_Go_Home = 1;
        Value_All = Rain_Total_Hits_Go_Home;
        Int_Float = 0;
        Print_New_Value_Rain();
        }
    }

 
 // Action if Rain Save is pressed
 if (SAVE_BTN.justPressed()) {
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
    OPTION1_BTN.press (down && OPTION1_BTN.contains(pixel_x, pixel_y));
    UP2_BTN.press    (down && UP2_BTN.contains(pixel_x, pixel_y));
    DOWN2_BTN.press  (down && DOWN2_BTN.contains(pixel_x, pixel_y));
    SAVE_BTN.press   (down && SAVE_BTN.contains(pixel_x, pixel_y));

    if (OPTION1_BTN.justReleased())  OPTION1_BTN.drawButton();
    if (UP2_BTN.justReleased())     UP2_BTN.drawButton();
    if (DOWN2_BTN.justReleased())   DOWN2_BTN.drawButton();
    if (SAVE_BTN.justReleased())    SAVE_BTN.drawButton();
}
