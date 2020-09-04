void Print_GPS_New_Fence() {  

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
    tft.print(F("Create New GPS Fence"));  
    



// Save a GPS Fence Point to the NodeMCU

    Save_GPS_Point_btn.initButton(&tft, 200, 150, 300, 100, WHITE, CYAN, BLACK, "Save GPS Point", 2);
    Save_GPS_Point_btn.drawButton(false);

// End the Fence Input

    Save_Fence_btn.initButton(&tft, 425, 278, 80, 40, WHITE, CYAN, BLACK, "End", 2);
    Save_Fence_btn.drawButton(false);


}


void React_to_Button_Press_GPS_New_Fence() {

 // Action if Add GPS Point button is pressed
 if (Save_GPS_Point_btn.justPressed()) {
          Serial.println(F("Fence Point Save to NodeMCU"));
          Menu_Active = 17;
          Send_Menu_Selected_To_GPS_NodeMCU();         // Tell the Mower MEGA which menu on the TFT is selected
          Serial.println("RX GPS Values");       
          Print_GPS_New_Fence();
          }
 
 
 // Action if GPS Save is pressed
 if (Save_Fence_btn.justPressed()) {
         Menu_Active = 18;
         Send_Menu_Selected_To_GPS_NodeMCU();         // Tell the Mower MEGA which menu on the TFT is selected
         delay(3000);
         Menu_Complete_GPS_New_Fence = true;
         tft.fillScreen(BLACK);
         Serial.println(F("Exit Create Fence Menu"));
         Menu_Active = 15;                                  // Cancel the GPS menu hold on the NodeMCU
         Send_Menu_Selected_To_GPS_NodeMCU();
         Print_GPS_Menu_Settings();
         }  

       
}


void Sense_Button_Press_GPS_New_Fence() {
    down = Touch_getXY();
    Save_GPS_Point_btn.press                (down && Save_GPS_Point_btn.contains(pixel_x, pixel_y));
    Save_Fence_btn.press                    (down && Save_Fence_btn.contains(pixel_x, pixel_y));

    if (Save_GPS_Point_btn.justReleased())   Save_GPS_Point_btn.drawButton();
    if (Save_Fence_btn.justReleased())       Save_Fence_btn.drawButton();
    }
