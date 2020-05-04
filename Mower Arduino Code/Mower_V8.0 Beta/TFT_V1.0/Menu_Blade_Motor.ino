void Print_Blade_Motor_Menu() {  


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

  up1_btn.initButton  (&tft, Button_X_Pos, (Bar_Pos_Y - Bar_To_Button_Y)  , Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
  down1_btn.initButton(&tft, Button_X_Pos, (Bar_Pos_Y + Bar_Height + Bar_To_Button_Y), Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);
  up1_btn.drawButton(false);
  down1_btn.drawButton(false);

  tft.setTextSize(2); 
  tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
  tft.setCursor(Button_X_Pos - Button_W  + 10, (Bar_Pos_Y + Bar_Height + Bar_To_Button_Y + Button_H - 10) );            // Text Coordinates X, Y
  tft.print("Blade");
  tft.setCursor(Button_X_Pos - 20, (Bar_Pos_Y - Button_H - 30) );            // Text Coordinates X, Y
  tft.print("PWM");

  Print_RPM_Blade_Value();  

  
  //Blade ON/OFF Button  
  if (Cutting_Blades_Activate == 1) Blade_ONOFF_btn.initButton(&tft, 235, 278, 150, 40, WHITE, GREEN, BLACK, "BLADE ON", 2);
  if (Cutting_Blades_Activate == 0) Blade_ONOFF_btn.initButton(&tft, 235, 278, 150, 40, WHITE, RED, WHITE, "BLADE OFF", 2);
    
  Blade_ONOFF_btn.drawButton(false);  
 
  
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
 if ((up1_btn.justPressed() )  || (down1_btn.justPressed())) {
        
    
    
    // Actions if UP is pressed
    if (up1_btn.justPressed()) {
        Clear_Old_Bar_Blade_Motor(); 
        Clear_Old_RPM_Blade_Value();       
        up1_btn.drawButton(true);
        PWM_Blade_Speed = PWM_Blade_Speed + 1;
        if (PWM_Blade_Speed > 255) PWM_Blade_Speed = 255;
        Calculate_Gauge_Level_Blade();
        Print_RPM_Blade_Value();
        Print_New_Bar_Blade_Motor();
        }


    // Action if down is pressed
    if (down1_btn.justPressed()) {
        Clear_Old_Bar_Blade_Motor();
        Clear_Old_RPM_Blade_Value(); 
        down1_btn.drawButton(true);
        PWM_Blade_Speed = PWM_Blade_Speed - 1;
        if (PWM_Blade_Speed < 0) PWM_Blade_Speed = 0;
        Calculate_Gauge_Level_Blade();
        Print_RPM_Blade_Value();
        Print_New_Bar_Blade_Motor();
        }
    }

if (Blade_ONOFF_btn.justPressed() )  {

        bool Changed = 0;
        
        if ((Cutting_Blades_Activate == 1) && (Changed == 0))  {
          Cutting_Blades_Activate  = 0;
          Changed = 1;
          Blade_ONOFF_btn.initButton(&tft, 235, 278, 150, 40,  WHITE, RED, WHITE, "BLADE OFF", 2);
          Blade_ONOFF_btn.drawButton(false);
          }
        
        if ((Cutting_Blades_Activate  == 0) && (Changed == 0)) {
          Cutting_Blades_Activate  = 1;
          Changed = 1;
          Blade_ONOFF_btn.initButton(&tft, 235, 278, 150, 40,  RED, GREEN, BLACK, "BLADE ON", 2);
          Blade_ONOFF_btn.drawButton(false);
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
    
    up1_btn.press            (down && up1_btn.contains(pixel_x, pixel_y));
    down1_btn.press          (down && down1_btn.contains(pixel_x, pixel_y));
    Blade_ONOFF_btn.press    (down && Blade_ONOFF_btn.contains(pixel_x, pixel_y));
    Save_Blade_btn.press           (down && Save_Blade_btn.contains(pixel_x, pixel_y));

    if (up1_btn.justReleased())         up1_btn.drawButton();
    if (down1_btn.justReleased())       down1_btn.drawButton();
    if (Blade_ONOFF_btn.justReleased()) Blade_ONOFF_btn.drawButton();
    if (Save_Blade_btn.justReleased())        Save_Blade_btn.drawButton();
}
