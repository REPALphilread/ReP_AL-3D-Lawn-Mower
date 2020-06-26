
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
   
    Tilt_Test_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, YELLOW, BLACK, YELLOW, "Tilt >", 2);
    Tilt_Test_btn.drawButton(false);
    
    //Test 2
    
    Button_X = Start_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    Test2_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, BLACK, WHITE, "SPARE", 2);
    Test2_btn.drawButton(false);

    //Spare Test
    
    Button_X = Start_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    Test3_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, RED, BLACK, WHITE, "SPARE", 2);
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
 if (Tilt_Test_btn.justPressed()) {
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
    }
    
// Test 3
 if (Test3_btn.justPressed()) {
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
    Tilt_Test_btn.press      (down && Tilt_Test_btn.contains(pixel_x, pixel_y));
    Test2_btn.press          (down && Test2_btn.contains(pixel_x, pixel_y));
    Test3_btn.press          (down && Test3_btn.contains(pixel_x, pixel_y));
    Test4_btn.press          (down && Test4_btn.contains(pixel_x, pixel_y));
    Test5_btn.press          (down && Test5_btn.contains(pixel_x, pixel_y));
    Next_btn.press           (down && Next_btn.contains(pixel_x, pixel_y));
    Done6_btn.press          (down && Done6_btn.contains(pixel_x, pixel_y));

    if (Tilt_Test_btn.justReleased())   Tilt_Test_btn.drawButton();
    if (Test2_btn.justReleased())       Test2_btn.drawButton();
    if (Test3_btn.justReleased())       Test3_btn.drawButton();
    if (Test4_btn.justReleased())       Test4_btn.drawButton();
    if (Test5_btn.justReleased())       Test5_btn.drawButton();
    if (Next_btn.justReleased())        Next_btn.drawButton();
    if (Done6_btn.justReleased())       Done6_btn.drawButton();

}
