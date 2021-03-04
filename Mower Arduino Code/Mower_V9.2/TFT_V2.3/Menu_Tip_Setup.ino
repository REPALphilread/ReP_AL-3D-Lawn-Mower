void Print_Tip_Setup_Menu() {  

    tft.fillScreen(BLACK);

    Serial.println(F("RX Tip"));
    Menu_Active = 24;                           // Code to tell the Mower MEGA which data to transmit.
    Send_Menu_Selected_To_Mower_MEGA();         // Send the code to the Mower MEGA which data should be transfered
    delay(RX_Delay);                            // Wait time for the Mower MEGA to transmit the data.
    Receive_7_Data_Sets();                      // Recieve data sets from the Mower MEGA
    
    Angle_Sensor_Enabled = Data1;                   // Fill the variable values with the data sets
    Tip_Over_Sensor_Enabled = Data2;
    Data3 = 0;
    Data4 = 0;
    Data5 = 0;
    Data6 = 0;
    Data7 = 0;
    Clear_Data_Streams();

    if (Debug_RX_Transfer == 1) {              // Display the received values on the TFT Screen if required.        
      Set_TFT_Screen_Pos();
      tft.print(F("Tip ON = "));
      tft.println(Angle_Sensor_Enabled);
      tft.print(F("Flip ON = "));
      tft.println(Tip_Over_Sensor_Enabled);
      delay(TFT_Check);
      tft.fillScreen(BLACK);     
      }

    
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
    tft.print(F("Tip Sensor Settings Menu"));  
    
    
    
    //Angle Sensor ON/OFF Button
    //------------------------------------------------------------
    
    int Label_X = Start_X;                           // Starting X Point.
    int Label_Y = Start_Y;                           // Starting Y Point

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("Angle Sensor ON/OFF"));  
    
    int Button_X = Label_X + (0.5 * Button_W);
    int Button_Y = Label_Y + Offset_Btn + (0.3 * Button_H);

    Value_X1 = Button_X;
    Value_Y1 = Button_Y;
    
    if (Angle_Sensor_Enabled == 1) OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
    if (Angle_Sensor_Enabled == 0) OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
    OPTION1_BTN.drawButton(false);


    //Turn Over sensor

    Label_X = Start_X;                           // Starting X Point.
    Label_Y = Button_Y + Menu_Spacing;                           // Starting Y Point

    tft.setTextSize(Txt_Size_Label); 
    tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("Turn Over Sensor ON/OFF"));  
    
    Button_X = Label_X + (0.5 * Button_W);
    Button_Y = Label_Y + Offset_Btn + (0.3 * Button_H);   

    Value_X2 = Button_X;
    Value_Y2 = Button_Y;
    
    if (Tip_Over_Sensor_Enabled == 1) OPTION2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
    if (Tip_Over_Sensor_Enabled == 0) OPTION2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
    OPTION2_BTN.drawButton(false);



// Save Button

    SAVE_BTN.initButton(&tft, 425, 278, 80, 40, WHITE, CYAN, BLACK, "Save", 2);
    SAVE_BTN.drawButton(false);


}


void React_to_Button_Press_Tip_Setup() {

 // If the Angle Sensor Button is pressed
 if (OPTION1_BTN.justPressed() ) {

        int Button_W = 120;                // width of the button
        int Button_H = 60;                // height of the button
        
        int Button_X = Value_X1;
        int Button_Y = Value_Y1;
        bool Changed = 0;

        if ((Angle_Sensor_Enabled == 1) && (Changed ==0))  {
          Angle_Sensor_Enabled = 0;
          Changed = 1;
          OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
          OPTION1_BTN.drawButton(false);
          }
        
        if ((Angle_Sensor_Enabled == 0) && (Changed ==0)) {
          Angle_Sensor_Enabled = 1;
          Changed = 1;
          OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
          OPTION1_BTN.drawButton(false);
        }
  delay(200);
 }


 // If the Tip Over Sensor Button is pressed
 if (OPTION2_BTN.justPressed() ) {

        int Button_W = 120;                // width of the button
        int Button_H = 60;                // height of the button
        
        int Button_X = Value_X2;
        int Button_Y = Value_Y2;
        bool Changed = 0;

        if ((Tip_Over_Sensor_Enabled == 1) && (Changed ==0))  {
          Tip_Over_Sensor_Enabled = 0;
          Changed = 1;
          OPTION2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
          OPTION2_BTN.drawButton(false);
          }
        
        if ((Tip_Over_Sensor_Enabled == 0) && (Changed ==0)) {
          Tip_Over_Sensor_Enabled = 1;
          Changed = 1;
          OPTION2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
          OPTION2_BTN.drawButton(false);
        }
  delay(200);
 }

 
 // Action if Tip ensor Save is pressed
 if (SAVE_BTN.justPressed()) {
         Menu_Complete_Tip_Setup = true;
         tft.fillScreen(BLACK);
         Serial.println(F("Tip Sensor Data Saved and TX"));
         Menu_Active = 924;
         Send_Menu_Selected_To_Mower_MEGA();
         Transmit_Saved_Tip_Sensor_Values();
         Print_Sensors_Menu_2();
         }  


        
}


void Sense_Button_Press_Tip_Setup() {
    down = Touch_getXY();
    OPTION1_BTN.press (down && OPTION1_BTN.contains(pixel_x, pixel_y));
    OPTION2_BTN.press (down && OPTION2_BTN.contains(pixel_x, pixel_y));
    SAVE_BTN.press   (down && SAVE_BTN.contains(pixel_x, pixel_y));

    if (OPTION1_BTN.justReleased())  OPTION1_BTN.drawButton();
    if (OPTION2_BTN.justReleased())  OPTION2_BTN.drawButton();
    if (SAVE_BTN.justReleased())    SAVE_BTN.drawButton();
}
