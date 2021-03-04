
// Menu Sensors
//*********************************



void Print_Sensors_Menu() {
    tft.fillScreen(BLACK);


    Serial.println(F("RX Sensor 1 Menu"));
    Menu_Active = 6;                            // Code to tell the Mower MEGA which data to transmit.
    Send_Menu_Selected_To_Mower_MEGA();         // Send the code to the Mower MEGA which data should be transfered
    delay(RX_Delay);                            // Wait time for the Mower MEGA to transmit the data.
    Receive_7_Data_Sets();                      // Recieve data sets from the Mower MEGA
    Perimeter_Wire_Enabled = Data1;                   // Fill the variable values with the data sets
    WIFI_Enabled           = Data2;
    Bumper_Activate_Frnt   = Data3;
    Data4 = 0;
    Data5 = 0;
    Data6 = 0;
    Data7 = 0;
    Clear_Data_Streams();

    if (Debug_RX_Transfer == 1) {              // Display the received values on the TFT Screen if required.        
      Set_TFT_Screen_Pos();
      tft.print(F("WIRE_ON = "));
      tft.println(Perimeter_Wire_Enabled);
      tft.print(F("WIFI_ON = "));
      tft.println(WIFI_Enabled );
      tft.print(F("Bumper_ON = "));
      tft.println(Bumper_Activate_Frnt);
      tft.println(F(" ")); 
      delay(TFT_Check);
      tft.fillScreen(BLACK);     
      }

   
    if (Draw_Pictures == 1)   bmpDraw("Sensors.bmp", 70, 20);      //Draw the mower picture
    delay(100); 

      // Framework for the buttons - setting the start position of the Quick start button wil automatically then space the other buttons

    int Start_X = 70;
    int Start_Y = 80;
    int Menu_Btn_Space = 100;          // Space between the adjacent buttons
    int Button_W = 130;                // width of the button
    int Button_H = 60;                // height of the button

    int Menu_Spacing = 20;            // Distance between the Menu Items (bottom of the last button to the label of the next item)
    int Txt_Size_Main_Menu = 2;
    int Column_Spacing = 200; 



    // Main Menu Title
    tft.setTextSize(Txt_Size_Main_Menu); 
    tft.setTextColor(GREEN, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(20, 10);            // Text Coordinates X, Y
    tft.print(F("Sensors 1/2 Menu"));  
    
    
    
    //Menu Sensors
    //------------------------------------------------------------
    
    // Sonar
    int Button_X = Start_X;
    int Button_Y = Start_Y;
   
    OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, YELLOW, YELLOW, BLACK, "Sonar >", 2);
    OPTION1_BTN.drawButton(false);
    
    //Battery
    
    Button_X = Start_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    OPTION2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, WHITE, BLACK, "Battery >", 2);
    OPTION2_BTN.drawButton(false);

    //Wire
    
    Button_X = Start_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    if (Perimeter_Wire_Enabled == 1) OPTION3_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "WIRE ON", 2);
    if (Perimeter_Wire_Enabled == 0) OPTION3_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "WIRE OFF", 2);
    
    OPTION3_BTN.drawButton(false);

    //Rain
    
    Button_X = Start_X + (Button_W + Column_Spacing) ;
    Button_Y = Start_Y;    
    
    OPTION4_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, RED, RED, WHITE, "Rain >", 2);
    OPTION4_BTN.drawButton(false);

    //WIFI
    
    Button_X = Button_X;
    Button_Y = Start_Y + (Button_H + Menu_Spacing);    
    
    if (WIFI_Enabled == 1) OPTION5_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, RED, GREEN, BLACK, "WIFI ON", 2);
    if (WIFI_Enabled == 0) OPTION5_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "WIFI OFF", 2);
    OPTION5_BTN.drawButton(false);

    //More Options
    
    Button_X = Button_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    Next_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, BLUE, BLUE, WHITE, "Next >", 2);
    Next_btn.drawButton(false);

// Done2 Button

    DONE2_BTN.initButton(&tft, 240, 270, 80, 40, WHITE, CYAN, BLACK, "Done", 2);
    DONE2_BTN.drawButton(false);
  
}


void React_to_Button_Press_Sensors() {

    // Action if Sonar is pressed
    if (OPTION1_BTN.justPressed()) {
          Menu_Complete_Sonar = false;
          tft.fillScreen(BLACK);  
          Print_Sonar_Menu();
          
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Sonar == false) {
            Sense_Button_Press_Sonar();
            React_to_Button_Press_Sonar();
            }
    }
          
    // Action if Battery is pressed
    if (OPTION2_BTN.justPressed()) {
          Menu_Complete_Battery = false;
          tft.fillScreen(BLACK);
          Print_Battery_Menu();
          
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Battery == false) {
            Sense_Button_Press_Battery();
            React_to_Button_Press_Battery();
            }
    }
          

    // Action if Wire is pressed
    if (OPTION3_BTN.justPressed()) {
        
        bool Changed = 0;
        int Start_X = 70;
        int Start_Y = 80;
        int Button_W = 130;
        int Button_H = 60;
        int Menu_Spacing = 20; 
        int Column_Spacing = 200; 
     
        int Button_X = Start_X;
        int Button_Y = Start_Y + (Button_H + Menu_Spacing) + (Button_H + Menu_Spacing);  
      
        if ((Perimeter_Wire_Enabled == 1) && (Changed == 0))  {
          Perimeter_Wire_Enabled  = 0;
          Changed = 1;
          OPTION3_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "Wire OFF", 2);
          OPTION3_BTN.drawButton(false);
          }
        
        if ((Perimeter_Wire_Enabled  == 0) && (Changed == 0)) {
          Perimeter_Wire_Enabled  = 1;
          Changed = 1;
          OPTION3_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, RED, GREEN, BLACK, "Wire ON", 2);
          OPTION3_BTN.drawButton(false);
        }          
          Menu_Active = 96;
          Send_Menu_Selected_To_Mower_MEGA();
          Transmit_Sensor_Menu1_Values();
          Print_Sensors_Menu();
    }


    // Action if Rain is pressed
    if (OPTION4_BTN.justPressed()) {
          Menu_Complete_Rain = false;
          tft.fillScreen(BLACK);
          Print_Rain_Sensor_Menu();
          
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Rain == false) {
            Sense_Button_Press_Rain();
            React_to_Button_Press_Rain();
            }
    }


    // Action if WIFIis pressed
    if (OPTION5_BTN.justPressed()) {
        
        bool Changed = 0;
        int Start_X = 70;
        int Start_Y = 80;
        int Button_W = 130;
        int Button_H = 60;
        int Menu_Spacing = 20; 
        int Column_Spacing = 200; 
        
        int Button_X = Start_X + (Button_W + Column_Spacing);
        int Button_Y = Start_Y + (Button_H + Menu_Spacing);  
      
        if ((WIFI_Enabled == 1) && (Changed == 0))  {
          WIFI_Enabled  = 0;
          Changed = 1;
          OPTION5_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "WIFI OFF", 2);
          OPTION5_BTN.drawButton(false);
          }
        
        if ((WIFI_Enabled  == 0) && (Changed == 0)) {
          WIFI_Enabled  = 1;
          Changed = 1;
          OPTION5_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, RED, GREEN, BLACK, "WIFI ON", 2);
          OPTION5_BTN.drawButton(false);
        }          
          Menu_Active = 96;
          Send_Menu_Selected_To_Mower_MEGA();
          Transmit_Sensor_Menu1_Values();
          Print_Sensors_Menu();
    }  

    
    // Action if More is pressed
    if (Next_btn.justPressed()) {
          Menu_Complete_Sensors_2 = false;
          tft.fillScreen(BLACK);
          Serial.println(F("TFT Sensors 2/2 Screen Selected"));
          Print_Sensors_Menu_2();
          
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Sensors_2 == false) {
            Sense_Button_Press_Sensors_2();
            React_to_Button_Press_Sensors_2();
            }
    }


 // Action if Done is pressed
 if (DONE2_BTN.justPressed()) {
         Menu_Complete_Sensors = true;
         tft.fillScreen(BLACK);
         Serial.println(F("Options Screen Selected"));
         Menu_Active = 4;
         Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
         Print_Settings_Menu();
         delay(200);
         }
}
    


void Sense_Button_Press_Sensors() {
    down = Touch_getXY();
    OPTION1_BTN.press            (down && OPTION1_BTN.contains(pixel_x, pixel_y));   // SONAR
    OPTION2_BTN.press            (down && OPTION2_BTN.contains(pixel_x, pixel_y));
    OPTION3_BTN.press            (down && OPTION3_BTN.contains(pixel_x, pixel_y));
    OPTION4_BTN.press            (down && OPTION4_BTN.contains(pixel_x, pixel_y));
    OPTION5_BTN.press            (down && OPTION5_BTN.contains(pixel_x, pixel_y));
    Next_btn.press               (down && Next_btn.contains(pixel_x, pixel_y));
    DONE2_BTN.press              (down && DONE2_BTN.contains(pixel_x, pixel_y));

    if (OPTION1_BTN.justReleased())        OPTION1_BTN.drawButton();
    if (OPTION2_BTN.justReleased())        OPTION2_BTN.drawButton();
    if (OPTION3_BTN.justReleased())        OPTION3_BTN.drawButton();
    if (OPTION4_BTN.justReleased())        OPTION4_BTN.drawButton();
    if (OPTION5_BTN.justReleased())        OPTION5_BTN.drawButton();
    if (Next_btn.justReleased())        Next_btn.drawButton();  
    if (DONE2_BTN.justReleased())       DONE2_BTN.drawButton();

}
