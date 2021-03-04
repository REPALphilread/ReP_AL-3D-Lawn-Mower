
// Test Menu 1
//*********************************

void Print_Tests_Menu() {
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
    tft.print(F("Test Components 1/3"));  
    
    
    
    // Wire Test
    
    int Button_X = Start_X;
    int Button_Y = Start_Y;
   
    Test1_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, YELLOW, BLACK, YELLOW, "Wire >", 2);
    Test1_btn.drawButton(false);
    
    //Relay_Test
    
    Button_X = Start_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    Test2_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, BLACK, WHITE, "Relay >", 2);
    Test2_btn.drawButton(false);

    //Wheel Test
    
    Button_X = Start_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    Test3_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, RED, BLACK, WHITE, "Wheels >", 2);
    Test3_btn.drawButton(false);

    //Blade Test
    
    Button_X = Start_X + (Button_W + Column_Spacing) ;
    Button_Y = Start_Y;    
    
    Test4_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, MAGENTA, BLACK, WHITE, "Blade >", 2);
    Test4_btn.drawButton(false);

    //Sonar Test
    
    Button_X = Button_X;
    Button_Y = Start_Y + (Button_H + Menu_Spacing);    
    
    Test5_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, BLUE, BLACK, WHITE, "Sonar >", 2);
    Test5_btn.drawButton(false);

    //Next Button
    
    Button_X = Button_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    Next_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, BLUE, BLUE, WHITE, "Next >", 2);
    Next_btn.drawButton(false);

  

// Done Button

    DONE3_BTN.initButton(&tft, 230, 278, 80, 40, WHITE, CYAN, BLACK, "Done", 2);
    DONE3_BTN.drawButton(false);
  
}


void React_to_Button_Press_Tests() {

// Wire Test
 if (Test1_btn.justPressed()) {
    Menu_Complete_Wire_Test = false;
    Setup_TFT_Screen_Test();
    Menu_Active = 41;
    Send_Menu_Selected_To_Mower_MEGA_No_RX();
    tft.println(F("Testing Wire Sensor Signal"));
    tft.setTextSize(2); 
    tft.setCursor(50,80);
    tft.print("POSITION");
    tft.setCursor(200,80);
    tft.print("WIRE SIGNAL");
    Wire_Sensor_Count = 0;
    while (Menu_Complete_Wire_Test == false) {
          
          tft.setTextColor(BLACK, BLACK); 
          Print_Wire_Text();         
          Receive_Wire_Sensor_Data();               
          //delay(Receive_Values_Delay);
          tft.setTextColor(RED, BLACK);  
          Print_Wire_Text();
          delay(500);
          Wire_Sensor_Count = Wire_Sensor_Count + 1;
          if (Wire_Sensor_Count < 3)   Menu_Complete_Wire_Test = false;   // Stops any first problems with the TXRX cancelling the test
          if (Wire_Sensor_Count > 60) Menu_Complete_Wire_Test = true;    // Backup Exit Clause
          }
    tft.fillScreen(BLACK);
    Print_Tests_Menu(); 
    }

// Relay Test
 if (Test2_btn.justPressed()) {
    Setup_TFT_Screen_Test();
    Menu_Active = 42;
    Send_Menu_Selected_To_Mower_MEGA_No_RX();
    tft.println(F("Testing Relay Function ON/OFF"));
    tft.println(F("Relay OFF"));
    delay(1000);
    tft.println(F("Relay ON"));
    delay(1000);
    tft.println(F("Test Complete"));
    delay(1000);
    tft.fillScreen(BLACK);
    Print_Tests_Menu(); 
    }

// Wheel Test
 if (Test3_btn.justPressed()) {
    Setup_TFT_Screen_Test();
    Menu_Active = 43;
    Send_Menu_Selected_To_Mower_MEGA_No_RX();
    tft.println(F("Starting Wheel Test"));
    tft.println(F("WHEELS WILL SPIN"));
    tft.println(F("MIND YOUR FINGERS!!")); 
    tft.println(F("Relay ON"));
    delay(2200);
    tft.println(F("<-- Turn Left"));
    delay(3000);
    tft.println(F("Turn Right -->"));
    delay(3000);
    tft.println(F("Go Forwards"));
    delay(3000);
    tft.println(F("Go Backwards"));
    delay(3000);
    tft.println(F("Dynamic: PWM Left 150, PWM Right 150"));
    delay(2000);
    tft.println(F("Dynamic: PWM Left 255, PWM Right 0"));
    delay(2000);
    tft.println(F("Dynamic: PWM Left 155, PWM Right 0"));
    delay(2000);
    tft.println(F("Dynamic: PWM Left 255, PWM Right 0"));
    delay(2000);
    tft.println(F("Dynamic: PWM Left 150, PWM Right 150"));
    delay(2000);
    tft.println(F("Dynamic: PWM Left 0, PWM Right 255"));
    delay(2000);
    tft.println(F("Dynamic: PWM Left 0, PWM Right 155"));
    delay(2000);
    tft.println(F("Dynamic: PWM Left 0, PWM Right 255"));
    delay(2000);
    tft.println(F("Motors Stop"));
    delay(2000);
    tft.println(F("Test Complete"));
    delay(1000);
    tft.fillScreen(BLACK);
    Print_Tests_Menu(); 
    }

// Blade Motor Test
 if (Test4_btn.justPressed()) {
    Setup_TFT_Screen_Test();
    Menu_Active = 44;
    Send_Menu_Selected_To_Mower_MEGA_No_RX();
    tft.println(F("Starting Blade Test"));
    tft.println(F("Relay ON"));
    tft.println(F("BLADE DISC WILL SPIN"));
    tft.println(F("MIND YOUR FINGERS!!"));
    delay(7000);
    tft.println(F("Blade Motor ON"));
    delay(7000);
    tft.println(F("Blade Motor OFF"));
    delay(2500);
    tft.println(F("Relay OFF"));
    tft.println(F("Test Complete"));
    delay(1000);
    tft.fillScreen(BLACK);
    Print_Tests_Menu(); 
    }


// Sonar Test
 if (Test5_btn.justPressed()) {
    Menu_Complete_Sonar_Test = false;
    Setup_TFT_Screen_Test();
    Menu_Active = 45;
    Send_Menu_Selected_To_Mower_MEGA_No_RX();
    tft.setTextSize(2); 
    tft.println(F("Testing Sonar Array"));
    tft.setCursor(30,170);
    tft.print("SONAR 2 /cm");
    tft.setCursor(180,60);
    tft.print("SONAR 1 /cm");  
    tft.setCursor(300,170);  
    tft.print("SONAR 3 /cm");  
    Sonar_Test_Cycles = 0;   
    while (Menu_Complete_Sonar_Test == false) {
          if (Sonar_Test_Cycles > 1) {
              tft.setTextColor(BLACK, BLACK);      // Removes the last value by printing black over it
              Print_Sonar_Text();                
              }
                         
          Receive_Sonar_Test_Data();                
          tft.setTextColor(RED, BLACK);  
          Print_Sonar_Text();                     // Prints the new value to the TFT
          delay(500);
              
          Sonar_Test_Cycles = Sonar_Test_Cycles + 1;
          if (Sonar_Test_Cycles < 3)   Menu_Complete_Sonar_Test = false;    // Stops any first problems with the TXRX cancelling the test
          if (Sonar_Test_Cycles > 60)  Menu_Complete_Sonar_Test = true;     // Back-up Exit incase the TXRX fails    
          }
    tft.fillScreen(BLACK);
    Print_Tests_Menu(); 
    }




// Action if More is pressed
if (Next_btn.justPressed()) {
          Menu_Complete_Testing_2 = false;
          tft.fillScreen(BLACK);
          Serial.println(F("TFT Options Screen Selected"));
          Print_Testing_2_Menu();
          
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Testing_2 == false) {
            Sense_Button_Press_Testing_2();
            React_to_Button_Press_Testing_2();
            }
    }

 // Action if Done is pressed
 if (DONE3_BTN.justPressed()) {
         Menu_Complete_Tests = true;
         tft.fillScreen(BLACK);
         Serial.println(F("Settings 1 Screen Selected"));
         Print_Settings_2_Menu();
         } 
 
 
}
    

void Print_Sonar_Text() {
      tft.setCursor(0,20);
      tft.setTextSize(2); 
      tft.print(Sonar_Test_Cycles);
      tft.setTextSize(6); 
      tft.setCursor(30,200);
      if (distance2 == 999) tft.print("OFF");
      if (distance2 != 999) tft.print(distance2);
      tft.setCursor(180,90);
      if (distance1 == 999) tft.print("OFF");
      if (distance1 != 999) tft.print(distance1);
      tft.setCursor(300,200);
      if (distance3 == 999) tft.print("OFF");
      if (distance3 != 999) tft.print(distance3); 
      }

void Print_Wire_Text() {
      tft.setTextSize(6); 
      tft.setCursor(50,110);
      if (INOUT == 0) tft.print("OUT");
      if (INOUT == 1) tft.print("IN");
      tft.setCursor(200,110);
      tft.println(MAG); 
      }


void Setup_TFT_Screen_Test() {
    tft.fillScreen(BLACK);
    tft.setTextSize(2); 
    tft.setTextColor(GREEN, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(0, 0);            // Text Coordinates X, Y
    }

void Sense_Button_Press_Tests() {
    down = Touch_getXY();
    Test1_btn.press          (down && Test1_btn.contains(pixel_x, pixel_y));
    Test2_btn.press          (down && Test2_btn.contains(pixel_x, pixel_y));
    Test3_btn.press          (down && Test3_btn.contains(pixel_x, pixel_y));
    Test4_btn.press          (down && Test4_btn.contains(pixel_x, pixel_y));
    Test5_btn.press          (down && Test5_btn.contains(pixel_x, pixel_y));
    Next_btn.press           (down && Next_btn.contains(pixel_x, pixel_y));
    DONE3_BTN.press          (down && DONE3_BTN.contains(pixel_x, pixel_y));

    if (Test1_btn.justReleased())       Test1_btn.drawButton();
    if (Test2_btn.justReleased())       Test2_btn.drawButton();
    if (Test3_btn.justReleased())       Test3_btn.drawButton();
    if (Test4_btn.justReleased())       Test4_btn.drawButton();
    if (Test5_btn.justReleased())       Test5_btn.drawButton();
    if (Next_btn.justReleased())        Next_btn.drawButton();
    if (DONE3_BTN.justReleased())       DONE3_BTN.drawButton();

}
