
// Menu Sensors
//*********************************



void Print_Sensors_Menu() {
    tft.fillScreen(BLACK);
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
   
    Sonar_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, YELLOW, YELLOW, BLACK, "Sonar >", 2);
    Sonar_btn.drawButton(false);
    
    //Battery
    
    Button_X = Start_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    Battery_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, WHITE, BLACK, "Battery >", 2);
    Battery_btn.drawButton(false);

    //Wire
    
    Button_X = Start_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    if (Perimeter_Wire_Enabled == 1) Wire_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "WIRE ON", 2);
    if (Perimeter_Wire_Enabled == 0) Wire_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "WIRE OFF", 2);
    
    Wire_btn.drawButton(false);

    //Rain
    
    Button_X = Start_X + (Button_W + Column_Spacing) ;
    Button_Y = Start_Y;    
    
    Rain_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, RED, RED, WHITE, "Rain >", 2);
    Rain_btn.drawButton(false);

    //WIFI
    
    Button_X = Button_X;
    Button_Y = Start_Y + (Button_H + Menu_Spacing);    
    
    if (WIFI_Enabled == 1) WIFI_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, RED, GREEN, BLACK, "WIFI ON", 2);
    if (WIFI_Enabled == 0) WIFI_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "WIFI OFF", 2);
    WIFI_btn.drawButton(false);

    //More Options
    
    Button_X = Button_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    Next_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, BLUE, BLUE, WHITE, "Next >", 2);
    Next_btn.drawButton(false);

// Done2 Button

    Done2_btn.initButton(&tft, 240, 270, 80, 40, WHITE, CYAN, BLACK, "Done", 2);
    Done2_btn.drawButton(false);
  
}


void React_to_Button_Press_Sensors() {

    // Action if Sonar is pressed
    if (Sonar_btn.justPressed()) {
          Menu_Complete_Sonar = false;
          tft.fillScreen(BLACK);
          Serial.println(F("Sonar Screen Selected"));
          Menu_Active = 10;
          Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
          Serial.println("RX Sonar Values");
          delay(Receive_Values_Delay + 600);
          Receive_Sonar_Data();        
          Print_Sonar_Menu();
          
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Sonar == false) {
            Sense_Button_Press_Sonar();
            React_to_Button_Press_Sonar();
            }
    }
          
    // Action if Battery is pressed
    if (Battery_btn.justPressed()) {
          Menu_Complete_Battery = false;
          tft.fillScreen(BLACK);
          Serial.println(F("Battery Screen Selected"));
          Menu_Active = 26;
          Send_Menu_Selected_To_Mower_MEGA();
          Serial.println("RX Battery Values");        
          delay(Receive_Values_Delay + 300);
          Receive_Battery_Data();
          Print_Battery_Menu();
          
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Battery == false) {
            Sense_Button_Press_Battery();
            React_to_Button_Press_Battery();
            }
    }
          

    // Action if Wire is pressed
    if (Wire_btn.justPressed()) {
        
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
          Wire_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "Wire OFF", 2);
          Wire_btn.drawButton(false);
          }
        
        if ((Perimeter_Wire_Enabled  == 0) && (Changed == 0)) {
          Perimeter_Wire_Enabled  = 1;
          Changed = 1;
          Wire_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, RED, GREEN, BLACK, "Wire ON", 2);
          Wire_btn.drawButton(false);
        }          
          Menu_Active = 96;
          Send_Menu_Selected_To_Mower_MEGA();
          Transmit_Sensor_Menu1_Values();
          Print_Sensors_Menu();
    }


    // Action if Rain is pressed
    if (Rain_btn.justPressed()) {
          Menu_Complete_Rain = false;
          tft.fillScreen(BLACK);
          Serial.println(F("Rain Sensor Screen Selected"));
          Menu_Active = 12;
          Send_Menu_Selected_To_Mower_MEGA();
          Serial.println("RX Rain Sensor Values");        
          delay(Receive_Values_Delay + 400);
          Receive_Rain_Sensor_Data();
          Print_Rain_Sensor_Menu();
          
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Rain == false) {
            Sense_Button_Press_Rain();
            React_to_Button_Press_Rain();
            }
    }


    // Action if WIFIis pressed
    if (WIFI_btn.justPressed()) {
        
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
          WIFI_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "WIFI OFF", 2);
          WIFI_btn.drawButton(false);
          }
        
        if ((WIFI_Enabled  == 0) && (Changed == 0)) {
          WIFI_Enabled  = 1;
          Changed = 1;
          WIFI_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, RED, GREEN, BLACK, "WIFI ON", 2);
          WIFI_btn.drawButton(false);
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
 if (Done2_btn.justPressed()) {
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
    Sonar_btn.press           (down && Sonar_btn.contains(pixel_x, pixel_y));
    Battery_btn.press         (down && Battery_btn.contains(pixel_x, pixel_y));
    Wire_btn.press            (down && Wire_btn.contains(pixel_x, pixel_y));
    Rain_btn.press            (down && Rain_btn.contains(pixel_x, pixel_y));
    WIFI_btn.press            (down && WIFI_btn.contains(pixel_x, pixel_y));
    Next_btn.press            (down && Next_btn.contains(pixel_x, pixel_y));
    Done2_btn.press           (down && Done2_btn.contains(pixel_x, pixel_y));

    if (Sonar_btn.justReleased())       Sonar_btn.drawButton();
    if (Battery_btn.justReleased())     Battery_btn.drawButton();
    if (Wire_btn.justReleased())        Wire_btn.drawButton();
    if (Rain_btn.justReleased())        Rain_btn.drawButton();
    if (WIFI_btn.justReleased())        WIFI_btn.drawButton();
    if (Next_btn.justReleased())        Next_btn.drawButton();  
    if (Done2_btn.justReleased())       Done2_btn.drawButton();

}
