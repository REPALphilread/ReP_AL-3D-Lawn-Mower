void Print_Blade_Motor_Menu() {  

    tft.fillScreen(BLACK);

    Serial.println(F("RX Blade"));
    Menu_Active = 15;                           // Code to tell the Mower MEGA which data to transmit.
    Send_Menu_Selected_To_Mower_MEGA();         // Send the code to the Mower MEGA which data should be transfered
    delay(RX_Delay);                            // Wait time for the Mower MEGA to transmit the data.
    Receive_7_Data_Sets();                      // Recieve data sets from the Mower MEGA
    PWM_Blade_Speed         = Data1;            // Fill the variable values with the data sets
    Cutting_Blades_Activate = Data2;
    Data3 = 0;
    Data4 = 0;
    Data5 = 0;
    Data6 = 0;
    Data7 = 0;
    Clear_Data_Streams();

    if (Debug_RX_Transfer == 1) {              // Display the received values on the TFT Screen if required.        
      Set_TFT_Screen_Pos();
      tft.print(F("PWM Blade = "));
      tft.println(PWM_Blade_Speed);
      tft.print(F("Blade ON = "));
      tft.println(Cutting_Blades_Activate);
      tft.println(F(" ")); 
      delay(TFT_Check);
      tft.fillScreen(BLACK);     
      }
    
    if (Draw_Pictures == 1)   bmpDraw("Motors.bmp", 70, 20);      //Draw the mower picture
    delay(100); 

// Create Bars for the Motor Values

  // Global Variable = Battery                  // Battery % remaining
  Bar_Width = 50;                               // Width of the battery bar
  Bar_Height = 120;                             // Height of the battery bar
  int Bar_To_Button_Y = 25;                      // Distance between the bar and the button
  Button_W = 50;
  int Button_H = 40;
  int Button_Spacing = 5;
  int Txt_Size_Main_Menu = 2;
  LH_RH_Spacing = 340;
  
  Bar_Pos_X = 50;                               // X Coordinate of the Battery Symbol
  Bar_Pos_Y = 110;                               // Y Coordinate of the Battery Symbol
  int Txt_Size_Label = 2;                       // Text size of the battery % text

    // Main Menu Title
    tft.setTextSize(Txt_Size_Main_Menu); 
    tft.setTextColor(GREEN, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(20, 10);            // Text Coordinates X, Y
    tft.print(F("Blade Motor Settings"));  
    

  // Mower Motor Bar Graphic  
  tft.fillRect((Bar_Pos_X - 1), (Bar_Pos_Y - 1) , (Bar_Width + 2 ), (Bar_Height + 2) , WHITE);    // Create a white Box (Border)
  tft.fillRect(Bar_Pos_X, (Bar_Pos_Y), (Bar_Width), (Bar_Height) , GREY);      // Create a grey background
 
  Calculate_Gauge_Level_Blade();  // Calulate the position of the red bar line
  if (PWM_Blade_Speed >= 250) tft.fillRect( (Bar_Pos_X + 2), (Bar_Pos_Y + Bar_Height), (Bar_Width - 4), (-1 * Gauge_Level_Blade) , RED);  // draws a new red bar
  if (PWM_Blade_Speed < 250) tft.fillRect( (Bar_Pos_X + 2), (Bar_Pos_Y + Bar_Height), (Bar_Width - 4), (-1 * Gauge_Level_Blade) , GREEN);  // draws a new red bar

  int Button_X_Pos = Bar_Pos_X + (0.5 * Button_W);

  UP1_BTN.initButton  (&tft, Button_X_Pos, (Bar_Pos_Y - Bar_To_Button_Y)  , Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
  DOWN1_BTN.initButton(&tft, Button_X_Pos, (Bar_Pos_Y + Bar_Height + Bar_To_Button_Y), Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);
  UP1_BTN.drawButton(false);
  DOWN1_BTN.drawButton(false);

  tft.setTextSize(2); 
  tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
  tft.setCursor(Button_X_Pos - Button_W  + 10, (Bar_Pos_Y + Bar_Height + Bar_To_Button_Y + Button_H - 10) );            // Text Coordinates X, Y
  tft.print(F("Blade"));
  tft.setCursor(Button_X_Pos - 20, (Bar_Pos_Y - Button_H - 30) );            // Text Coordinates X, Y
  tft.print(F("PWM"));

  Print_RPM_Blade_Value();  

  
  //Blade ON/OFF Button  
  if (Cutting_Blades_Activate == 1) OPTION1_BTN.initButton(&tft, 235, 278, 150, 40, WHITE, GREEN, BLACK, "BLADE ON", 2);
  if (Cutting_Blades_Activate == 0) OPTION1_BTN.initButton(&tft, 235, 278, 150, 40, WHITE, RED, WHITE, "BLADE OFF", 2);
    
  OPTION1_BTN.drawButton(false);  
 
  
// Save Button

    Save_Blade_btn.initButton(&tft, 425, 278, 80, 40, WHITE, CYAN, BLACK, "Save", 2);
    Save_Blade_btn.drawButton(false);
  
  } 


void Calculate_Gauge_Level_Blade() {
  // Draw RPM Line
  Gauge_Level_Blade = (Bar_Height / 255) * PWM_Blade_Speed;
  //Serial.print("RPM Level = ");
  //Serial.println(Gauge_Level);
  }


void React_to_Button_Press_Blade_Motor() {

//If the + or . Button is pressed (up or down)
 if ((UP1_BTN.justPressed() )  || (DOWN1_BTN.justPressed())) {
        
    
    
    // Actions if UP is pressed
    if (UP1_BTN.justPressed()) {
        Clear_Old_Bar_Blade_Motor(); 
        Clear_Old_RPM_Blade_Value();       
        UP1_BTN.drawButton(true);
        PWM_Blade_Speed = PWM_Blade_Speed + 1;
        if (PWM_Blade_Speed > 255) PWM_Blade_Speed = 255;
        Calculate_Gauge_Level_Blade();
        Print_RPM_Blade_Value();
        Print_New_Bar_Blade_Motor();
        }


    // Action if down is pressed
    if (DOWN1_BTN.justPressed()) {
        Clear_Old_Bar_Blade_Motor();
        Clear_Old_RPM_Blade_Value(); 
        DOWN1_BTN.drawButton(true);
        PWM_Blade_Speed = PWM_Blade_Speed - 1;
        if (PWM_Blade_Speed < 0) PWM_Blade_Speed = 0;
        Calculate_Gauge_Level_Blade();
        Print_RPM_Blade_Value();
        Print_New_Bar_Blade_Motor();
        }
    }

if (OPTION1_BTN.justPressed() )  {

        bool Changed = 0;
        
        if ((Cutting_Blades_Activate == 1) && (Changed == 0))  {
          Cutting_Blades_Activate  = 0;
          Changed = 1;
          OPTION1_BTN.initButton(&tft, 235, 278, 150, 40,  WHITE, RED, WHITE, "BLADE OFF", 2);
          OPTION1_BTN.drawButton(false);
          }
        
        if ((Cutting_Blades_Activate  == 0) && (Changed == 0)) {
          Cutting_Blades_Activate  = 1;
          Changed = 1;
          OPTION1_BTN.initButton(&tft, 235, 278, 150, 40,  RED, GREEN, BLACK, "BLADE ON", 2);
          OPTION1_BTN.drawButton(false);
        }    
   }

 // Action if Blade Motor Saved is pressed
 if (Save_Blade_btn.justPressed()) {
         Menu_Complete_Blade = true;
         tft.fillScreen(BLACK);
         Serial.println(F("Blade Motor Data Saved and TX"));
         Menu_Active = 915;
         Send_Menu_Selected_To_Mower_MEGA();
         Transmit_Blade_Motor_Values();
         Print_Motion_Menu();     
         }  
 
}


void Clear_Old_RPM_Blade_Value() {

  int Button_X_Pos = Bar_Pos_X + (0.5 * Button_W);
  
  // PWM Value
  tft.setTextSize(2); 
  tft.setTextColor(BLACK, BLACK);      //Text Colour/ Background Colour
  tft.setCursor(Button_X_Pos - Button_W - 15, (Bar_Pos_Y + Bar_Height - Gauge_Level_Blade) );            // Text Coordinates X, Y
  tft.print(PWM_Blade_Speed); 
  }  

void Print_RPM_Blade_Value() {

  int Button_X_Pos = Bar_Pos_X + (0.5 * Button_W);
  
  // PWM Value
  tft.setTextSize(2); 
  tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
  tft.setCursor(Button_X_Pos - Button_W - 15, (Bar_Pos_Y + Bar_Height - Gauge_Level_Blade) );            // Text Coordinates X, Y
  tft.print(PWM_Blade_Speed);  
  }

void Clear_Old_Bar_Blade_Motor() {
  tft.fillRect(Bar_Pos_X, (Bar_Pos_Y), (Bar_Width), (Bar_Height) , GREY);                         // Draws over the red bar diagram with grey
}

void Print_New_Bar_Blade_Motor() {
  if (PWM_Blade_Speed >= 250) tft.fillRect( (Bar_Pos_X + 2), (Bar_Pos_Y + Bar_Height), (Bar_Width - 4), (-1 * Gauge_Level_Blade) , RED);  // draws a new red bar
  if (PWM_Blade_Speed < 250)  tft.fillRect( (Bar_Pos_X + 2), (Bar_Pos_Y + Bar_Height), (Bar_Width - 4), (-1 * Gauge_Level_Blade) , GREEN);  // draws a new red bar
  }


void Sense_Button_Press_Blade_Motor() {
    down = Touch_getXY();
    
    UP1_BTN.press            (down && UP1_BTN.contains(pixel_x, pixel_y));
    DOWN1_BTN.press          (down && DOWN1_BTN.contains(pixel_x, pixel_y));
    OPTION1_BTN.press    (down && OPTION1_BTN.contains(pixel_x, pixel_y));   // Blade ON/OFF
    Save_Blade_btn.press           (down && Save_Blade_btn.contains(pixel_x, pixel_y));

    if (UP1_BTN.justReleased())         UP1_BTN.drawButton();
    if (DOWN1_BTN.justReleased())       DOWN1_BTN.drawButton();
    if (OPTION1_BTN.justReleased()) OPTION1_BTN.drawButton();
    if (Save_Blade_btn.justReleased())        Save_Blade_btn.drawButton();
}
