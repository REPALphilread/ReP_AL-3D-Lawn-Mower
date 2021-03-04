
// Test Menu 3
//*********************************

void Print_Testing_3_Menu() {

    tft.fillScreen(BLACK);
      // Framework for the buttons - setting the start position of the Quick start button wil automatically then space the other buttons

    int Start_X = 90;
    int Start_Y = 80;
    int Menu_Btn_Space = 100;          // Space between the adjacent buttons
    int Button_W = 130;                // width of the button
    int Button_H = 60;                // height of the button

    int Menu_Spacing = 20;            // Distance between the Menu Items (bottom of the last button to the label of the next item)
    int Txt_Size_Main_Menu = 2;
    int Column_Spacing = 160; 



    // Main Menu Title
    tft.setTextSize(Txt_Size_Main_Menu); 
    tft.setTextColor(GREEN, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(20, 10);            // Text Coordinates X, Y
    tft.print(F("Test Components 3/3"));  
    
    
    
    // Tilt
    
    int Button_X = Start_X;
    int Button_Y = Start_Y;
   
    Test1_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, YELLOW, BLACK, YELLOW, "Tilt >", 2);
    Test1_btn.drawButton(false);
    
    //Test 2
    
    Button_X = Start_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    Test2_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, BLACK, WHITE, "GYRO >", 2);
    Test2_btn.drawButton(false);

    //Spare Test
    
    Button_X = Start_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    Test3_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, RED, BLACK, WHITE, "Wheel Amp", 2);
    Test3_btn.drawButton(false);

    //Spare Test
    
    Button_X = Start_X + (Button_W + Column_Spacing) ;
    Button_Y = Start_Y;    
    
    Test4_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, MAGENTA, BLACK, WHITE, "SPARE", 2);
    Test4_btn.drawButton(false);

    //Spare Test
    
    Button_X = Button_X;
    Button_Y = Start_Y + (Button_H + Menu_Spacing);    
    
    Test5_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, BLUE, BLACK, WHITE, "SPARE", 2);
    Test5_btn.drawButton(false);

    //Next Button
    
    Button_X = Button_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    Next_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, BLUE, BLUE, WHITE, "Next >", 2);
    Next_btn.drawButton(false);

  

// Done Button

    Done6_btn.initButton(&tft, 230, 278, 80, 40, WHITE, CYAN, BLACK, "< Back", 2);
    Done6_btn.drawButton(false);
  
}


void React_to_Button_Press_Testing_3() {

// TILT TEST
 if (Test1_btn.justPressed()) {
      Setup_TFT_Screen_Test();
      Menu_Active = 40;
      Send_Menu_Selected_To_Mower_MEGA_No_RX();
      tft.println(F("Testing Tilt Sensor"));
      tft.setTextSize(2); 
      tft.setCursor(50,80);
      tft.print("ANGLE!:");
      tft.setCursor(250,80);
      tft.print("UPSIDE!:");
      Menu_Complete_Tilt_Test = false;
      delay(100);
      while (Menu_Complete_Tilt_Test == false) {       
          // Erase the information
          tft.setTextColor(BLACK, BLACK); 
          Print_Tilt_Text();         
          Print_Orientation_Text();    
          // Print new values
          Receive_Tilt_Sensor_Data();                         
          tft.setTextColor(YELLOW, BLACK);  
          Print_Tilt_Text();         
          tft.setTextColor(YELLOW, BLACK);  
          Print_Orientation_Text();  
          delay(100);      
          }

    tft.fillScreen(BLACK);
    Print_Testing_3_Menu(); 
      
    }

// Test 2
if (Test2_btn.justPressed()) {
    Setup_TFT_Screen_Test();
    Menu_Active = 39;
    Send_Menu_Selected_To_Mower_MEGA_No_RX();
    tft.println(F("Testing GYRO Sensor"));
    tft.setTextSize(2); 
    tft.setCursor(50,80);
    tft.print("X Angle");
    tft.setCursor(250,80);
    tft.print("Y Angle");
    int GYRO_Sensor_Count = 0;
    Menu_Complete_GYRO_Test = false;
    while (Menu_Complete_GYRO_Test == false) {
          tft.setTextColor(BLACK, BLACK); 
          Print_X_Angle_Text();         
          Print_Y_Angle_Text();    
          Receive_GYRO_Sensor_Data();               
          tft.setTextColor(YELLOW, BLACK);  
          Print_X_Angle_Text();         
          tft.setTextColor(RED, BLACK);  
          Print_Y_Angle_Text();  
          delay(500);
          GYRO_Sensor_Count = GYRO_Sensor_Count + 1;
          if (GYRO_Sensor_Count < 3)   Menu_Complete_GYRO_Test = false;   // Stops any first problems with the TXRX cancelling the test
          if (GYRO_Sensor_Count > 100)  Menu_Complete_GYRO_Test = true;    // Backup Exit Clause
          }

    tft.fillScreen(BLACK);
    Print_Testing_3_Menu(); 
    }
    
// Test 3
if (Test3_btn.justPressed()) {
    Setup_TFT_Screen_Test();
    Menu_Active = 38;
    Send_Menu_Selected_To_Mower_MEGA_No_RX();
    tft.println(F("Testing Wheel Amp Sensor"));
    tft.setTextSize(2); 
    tft.setCursor(50,80);
    tft.print("Status");
    int Wheel_Amp_Sensor_Count = 0;
    Menu_Complete_Wheel_Amp_Test = false;
    while (Menu_Complete_Wheel_Amp_Test == false) {
          tft.setTextColor(BLACK, BLACK);   
          if (Wheel_Blocked == 0) Print_Wheel_Blocked_Text();    
          Receive_Wheel_Amp_Data();              
          tft.setTextColor(YELLOW, BLACK);  
          if (Wheel_Blocked == 4) Print_Wheel_Blocked_Text(); 
          delay(500);
          Wheel_Amp_Sensor_Count = Wheel_Amp_Sensor_Count + 1;
          if (Wheel_Amp_Sensor_Count < 3)    Menu_Complete_Wheel_Amp_Test = false;   // Stops any first problems with the TXRX cancelling the test
          if (Wheel_Amp_Sensor_Count > 70)  Menu_Complete_Wheel_Amp_Test = true;    // Backup Exit Clause
          }

    tft.fillScreen(BLACK);
    Print_Testing_3_Menu(); 
    }

// Test 4
 if (Test4_btn.justPressed()) {
    }

// Test 5
 if (Test5_btn.justPressed()) {
    }

 // Action if Done is pressed
 if (Done6_btn.justPressed()) {
         Menu_Complete_Testing_3 = true;
         tft.fillScreen(BLACK);
         Serial.println(F("Test Screen 2/3 Selected"));
         Print_Testing_2_Menu();
         } 
 
 
}


void Print_X_Angle_Text() {
      tft.setTextSize(6); 
      tft.setCursor(50,110);
      tft.println(GYRO_X_Angle); 
      }
      
void Print_Y_Angle_Text() {
      tft.setTextSize(6); 
      tft.setCursor(250,110);
      tft.print(GYRO_Y_Angle);
      }

     
void Print_Wheel_Blocked_Text() {
      tft.setTextSize(6); 
      tft.setCursor(80,110);
      tft.print("Blocked");
      }

      

void Print_Tilt_Text() {
      tft.setTextSize(6); 
      tft.setCursor(50,110);
      if (Tilt_Angle_Sensed == 0) tft.print("X");
      if (Tilt_Angle_Sensed == 1) tft.print(" ");
      }
      
void Print_Orientation_Text() {
      tft.setTextSize(6); 
      tft.setCursor(250,110);
      if (Tilt_Orientation_Sensed == 1) tft.print("X");
      if (Tilt_Orientation_Sensed == 0) tft.print(" ");
      }


void Sense_Button_Press_Testing_3() {
    down = Touch_getXY();
    Test1_btn.press      (down && Test1_btn.contains(pixel_x, pixel_y));
    Test2_btn.press      (down && Test2_btn.contains(pixel_x, pixel_y));
    Test3_btn.press          (down && Test3_btn.contains(pixel_x, pixel_y));
    Test4_btn.press          (down && Test4_btn.contains(pixel_x, pixel_y));
    Test5_btn.press          (down && Test5_btn.contains(pixel_x, pixel_y));
    Next_btn.press           (down && Next_btn.contains(pixel_x, pixel_y));
    Done6_btn.press          (down && Done6_btn.contains(pixel_x, pixel_y));

    if (Test1_btn.justReleased())   Test1_btn.drawButton();
    if (Test2_btn.justReleased())   Test2_btn.drawButton();
    if (Test3_btn.justReleased())       Test3_btn.drawButton();
    if (Test4_btn.justReleased())       Test4_btn.drawButton();
    if (Test5_btn.justReleased())       Test5_btn.drawButton();
    if (Next_btn.justReleased())        Next_btn.drawButton();
    if (Done6_btn.justReleased())       Done6_btn.drawButton();

}
