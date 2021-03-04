
// Test Menu 2
//*********************************

void Print_Testing_2_Menu() {

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
    tft.print(F("Test Components 2/3"));  
    
    
    
    // Wire Test
    
    int Button_X = Start_X;
    int Button_Y = Start_Y;
   
    Test1_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, YELLOW, BLACK, YELLOW, "Turn >", 2);
    Test1_btn.drawButton(false);
    
    //Relay_Test
    
    Button_X = Start_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    Test2_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, BLACK, WHITE, "Volt Amp>", 2);
    Test2_btn.drawButton(false);

    //Wheel Test
    
    Button_X = Start_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    Test3_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, RED, BLACK, WHITE, "Compass >", 2);
    Test3_btn.drawButton(false);

    //Blade Test
    
    Button_X = Start_X + (Button_W + Column_Spacing) ;
    Button_Y = Start_Y;    
    
    Test4_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, MAGENTA, BLACK, WHITE, "Go Home >", 2);
    Test4_btn.drawButton(false);

    //Sonar Test
    
    Button_X = Button_X;
    Button_Y = Start_Y + (Button_H + Menu_Spacing);    
    
    Test5_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, BLUE, BLACK, WHITE, "Bumper >", 2);
    Test5_btn.drawButton(false);

    //Next Button
    
    Button_X = Button_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    Next_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, BLUE, BLUE, WHITE, "Next >", 2);
    Next_btn.drawButton(false);

  

// Done Button

    Done4_btn.initButton(&tft, 230, 278, 80, 40, WHITE, CYAN, BLACK, "< Back", 2);
    Done4_btn.drawButton(false);
  
}


void React_to_Button_Press_Testing_2() {

// Turn Test
 if (Test1_btn.justPressed()) {
    Setup_TFT_Screen_Test();
    Menu_Active = 46;
    Send_Menu_Selected_To_Mower_MEGA();
    tft.println(F("Starting Turn Test"));

    tft.fillScreen(BLACK);
    Print_Testing_2_Menu(); 
    }

// Volt Amp Test
if (Test2_btn.justPressed()) {
    Setup_TFT_Screen_Test();
    Menu_Active = 47;
    Send_Menu_Selected_To_Mower_MEGA_No_RX();
    tft.println(F("Testing Volt & Amp Sensors"));
    tft.setTextSize(2); 
    tft.setCursor(30,80);
    tft.print("Volts");
    tft.setCursor(270,80);
    tft.print("Amps");
    int Volt_Amp_Sensor_Count = 0;
    Menu_Complete_Volt_Amp_Test = false;
    while (Menu_Complete_Volt_Amp_Test == false) {
          tft.setTextColor(BLACK, BLACK); 
          Print_Volt_Text();    
          Print_Amp_Text();     
          Receive_Volt_Amp_Sensor_Data();               
          tft.setTextColor(RED, BLACK);  
          Print_Volt_Text();
          tft.setTextColor(YELLOW, BLACK);  
          Print_Amp_Text();
          delay(500);
          Volt_Amp_Sensor_Count = Volt_Amp_Sensor_Count + 1;
          if (Volt_Amp_Sensor_Count < 3)   Menu_Complete_Volt_Amp_Test = false;   // Stops any first problems with the TXRX cancelling the test
          if (Volt_Amp_Sensor_Count > 60)  Menu_Complete_Volt_Amp_Test = true;    // Backup Exit Clause
          }

    tft.fillScreen(BLACK);
    Print_Testing_2_Menu(); 
    }
    

// Compass Test
 if (Test3_btn.justPressed()) {
    Setup_TFT_Screen_Test();
    Menu_Active = 48;
    Send_Menu_Selected_To_Mower_MEGA_No_RX();
    tft.println(F("Testing Compass Sensor"));
    tft.setTextSize(2); 
    tft.setCursor(50,80);
    tft.print("Heading");
    tft.setCursor(250,80);
    tft.print("Degrees");
    int Compass_Sensor_Count = 0;
    Menu_Complete_Compass_Test = false;
    while (Menu_Complete_Compass_Test == false) {
          tft.setTextColor(BLACK, BLACK); 
          Print_Degrees_Text();         
          Print_Heading_Text();    
          Receive_Compass_Sensor_Data();               
          tft.setTextColor(YELLOW, BLACK);  
          Print_Degrees_Text();         
          tft.setTextColor(RED, BLACK);  
          Print_Heading_Text();  
          delay(500);
          Compass_Sensor_Count = Compass_Sensor_Count + 1;
          if (Compass_Sensor_Count < 3)   Menu_Complete_Compass_Test = false;   // Stops any first problems with the TXRX cancelling the test
          if (Compass_Sensor_Count > 60)  Menu_Complete_Compass_Test = true;    // Backup Exit Clause
          }

    tft.fillScreen(BLACK);
    Print_Testing_2_Menu(); 
    }



// Go Home Test
 if (Test4_btn.justPressed()) {
    Setup_TFT_Screen_Test();
    Menu_Active = 49;
    Send_Menu_Selected_To_Mower_MEGA();
    tft.println(F("Starting Go Home Test"));

    tft.fillScreen(BLACK);
    Print_Testing_2_Menu(); 
    }

// Bumper Bar Test
 if (Test5_btn.justPressed()) {
    Setup_TFT_Screen_Test();
    Menu_Active = 50;
    Send_Menu_Selected_To_Mower_MEGA_No_RX();
    tft.println(F("Testing Bumper Bar"));
    tft.setTextSize(2); 
    tft.setCursor(50,80);
    tft.print("LEFT");
    tft.setCursor(250,80);
    tft.print("RIGHT");
    int Bumper_Sensor_Count = 0;
    Menu_Complete_Bumper_Test = false;
    while (Menu_Complete_Bumper_Test == false) {
          tft.setTextColor(BLACK, BLACK); 
          Print_Bumper_LH_Text();         
          Print_Bumper_RH_Text();    
          Receive_Bumper_Sensor_Data();               
          tft.setTextColor(BLUE, BLACK);  
          Print_Bumper_LH_Text();         
          tft.setTextColor(BLUE, BLACK);  
          Print_Bumper_RH_Text();  
          delay(500);
          Bumper_Sensor_Count = Bumper_Sensor_Count + 1;
          if (Bumper_Sensor_Count < 3)   Menu_Complete_Bumper_Test = false;   // Stops any first problems with the TXRX cancelling the test
          if (Bumper_Sensor_Count > 60)  Menu_Complete_Bumper_Test = true;    // Backup Exit Clause
          }

    tft.fillScreen(BLACK);
    Print_Testing_2_Menu(); 
    }

 // Action if Done is pressed
 if (Done4_btn.justPressed()) {
         Menu_Complete_Testing_2 = true;
         tft.fillScreen(BLACK);
         Serial.println(F("Test Screen 1/3 Selected"));
         Print_Tests_Menu();
         } 

// Action if More is pressed
if (Next_btn.justPressed()) {
          Menu_Complete_Testing_3 = false;
          tft.fillScreen(BLACK);
          Serial.println(F("TFT Options Screen Selected"));
          Print_Testing_3_Menu();
          
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Testing_3 == false) {
            Sense_Button_Press_Testing_3();
            React_to_Button_Press_Testing_3();
            }
    }

 
}
    
void Print_Degrees_Text() {
      tft.setTextSize(6); 
      tft.setCursor(250,110);
      tft.println(Compass_Heading_Degrees); 
      }
      
void Print_Heading_Text() {
      tft.setTextSize(6); 
      tft.setCursor(50,110);
      tft.print(Heading);
      }

void Print_Bumper_RH_Text() {
      tft.setTextSize(6); 
      tft.setCursor(250,110);
      if (Bump_RH == 0) tft.print("_");
      if (Bump_RH == 1) tft.print("X");
      }
      
void Print_Bumper_LH_Text() {
      tft.setTextSize(6); 
      tft.setCursor(50,110);
      if (Bump_LH == 0) tft.print("_");
      if (Bump_LH == 1) tft.print("X");
      }


void Print_Volt_Text() {
      tft.setTextSize(6); 
      tft.setCursor(30,110);
      tft.print(Volts);
      }

void Print_Amp_Text() {
      tft.setTextSize(6); 
      tft.setCursor(270,110);
      tft.println(Amps); 
      }

void Sense_Button_Press_Testing_2() {
    down = Touch_getXY();
    Test1_btn.press          (down && Test1_btn.contains(pixel_x, pixel_y));
    Test2_btn.press          (down && Test2_btn.contains(pixel_x, pixel_y));
    Test3_btn.press          (down && Test3_btn.contains(pixel_x, pixel_y));
    Test4_btn.press          (down && Test4_btn.contains(pixel_x, pixel_y));
    Test5_btn.press          (down && Test5_btn.contains(pixel_x, pixel_y));
    Next_btn.press           (down && Next_btn.contains(pixel_x, pixel_y));
    Done4_btn.press          (down && Done4_btn.contains(pixel_x, pixel_y));

    if (Test1_btn.justReleased())       Test1_btn.drawButton();
    if (Test2_btn.justReleased())       Test2_btn.drawButton();
    if (Test3_btn.justReleased())       Test3_btn.drawButton();
    if (Test4_btn.justReleased())       Test4_btn.drawButton();
    if (Test5_btn.justReleased())       Test5_btn.drawButton();
    if (Next_btn.justReleased())        Next_btn.drawButton();
    if (Done4_btn.justReleased())       Done4_btn.drawButton();

}
