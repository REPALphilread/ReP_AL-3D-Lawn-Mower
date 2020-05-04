void Print_Wheel_Motors_Menu() {  


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
    tft.print(F("Wheel Motor Speeds"));  
    tft.setTextColor(RED, BLACK);      //Text Colour/ Background Colour
    tft.print(F("  FULL"));  
    tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
    tft.print(F("  SLOW"));  

  // LH Motor Bar Graphic  
  tft.fillRect((Bar_Pos_X - 1), (Bar_Pos_Y - 1) , (Bar_Width + 2 ), (Bar_Height + 2) , WHITE);    // Create a white Box (Border)
  tft.fillRect(Bar_Pos_X, (Bar_Pos_Y), (Bar_Width), (Bar_Height) , GREY);      // Create a grey background
 
  Calculate_Gauge_Level_LH_Wheel_Full();  // Calulate the position of the red bar line
  tft.fillRect( (Bar_Pos_X + 2), (Bar_Pos_Y + Bar_Height - Gauge_Level_LH_Full + 5), (Bar_Width - 4), 5 , RED);      // Draw Gauge Bar
  Calculate_Gauge_Level_LH_Wheel_Slow();  // Calulate the position of the red bar line
  tft.fillRect( (Bar_Pos_X + 2), (Bar_Pos_Y + Bar_Height - Gauge_Level_LH_Slow + 5), (Bar_Width - 4), 5 , YELLOW);      // Draw Gauge Bar
  
  int Button_X_Pos = Bar_Pos_X;

  //+ - Buttons Full Speed
  up1_btn.initButton  (&tft, Button_X_Pos, (Bar_Pos_Y - Bar_To_Button_Y)  , Button_W, Button_H, WHITE, RED, WHITE, "+", 2);
  down1_btn.initButton(&tft, Button_X_Pos, (Bar_Pos_Y + Bar_Height + Bar_To_Button_Y), Button_W, Button_H, WHITE, RED, WHITE, "-", 2);
  up1_btn.drawButton(false);
  down1_btn.drawButton(false);

  // + - Buttons Slow Speed LH
  up3_btn.initButton  (&tft, Button_X_Pos + (Button_Spacing + (1.0 * Button_W)), (Bar_Pos_Y - Bar_To_Button_Y)  , Button_W, Button_H, WHITE, YELLOW, BLACK, "+", 2);
  down3_btn.initButton(&tft, Button_X_Pos + (Button_Spacing + (1.0 * Button_W)), (Bar_Pos_Y + Bar_Height + Bar_To_Button_Y), Button_W, Button_H, WHITE, YELLOW, BLACK, "-", 2);
  up3_btn.drawButton(false);
  down3_btn.drawButton(false);

  tft.setTextSize(2); 
  tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
  tft.setCursor(Button_X_Pos -18 , (Bar_Pos_Y + Bar_Height + Bar_To_Button_Y + Button_H) );            // Text Coordinates X, Y
  tft.print("LH Wheel");
  tft.setCursor(Button_X_Pos, (Bar_Pos_Y - Button_H - 30) );            // Text Coordinates X, Y
  tft.print("PWM");

  Print_RPM_LH_Wheel_Value_Full();  
  Print_RPM_LH_Wheel_Value_Slow(); 
  
  
  // RH Motor Bar Graphic  
 
  tft.fillRect((Bar_Pos_X + LH_RH_Spacing - 1), (Bar_Pos_Y - 1) , (Bar_Width + 2 ), (Bar_Height + 2) , WHITE);    // Create a white Box (Border)
  tft.fillRect(Bar_Pos_X  + LH_RH_Spacing, (Bar_Pos_Y), (Bar_Width), (Bar_Height) , GREY);      // Create a grey background
 
  Calculate_Gauge_Level_RH_Wheel_Full();  // Calulate the position of the red bar line
  tft.fillRect( (Bar_Pos_X + LH_RH_Spacing + 2), (Bar_Pos_Y + Bar_Height - Gauge_Level_RH_Full + 5), (Bar_Width - 4), 5 , RED);      // Draw Gauge Bar
  Calculate_Gauge_Level_RH_Wheel_Slow();  // Calulate the position of the red bar line
  tft.fillRect( (Bar_Pos_X + LH_RH_Spacing + 2), (Bar_Pos_Y + Bar_Height - Gauge_Level_RH_Slow + 5), (Bar_Width - 4), 5 , YELLOW);      // Draw Gauge Bar
  
  Button_X_Pos = Bar_Pos_X + LH_RH_Spacing;

  up2_btn.initButton  (&tft, Button_X_Pos , (Bar_Pos_Y - Bar_To_Button_Y)  , Button_W, Button_H, WHITE, RED, WHITE, "+", 2);
  down2_btn.initButton(&tft, Button_X_Pos , (Bar_Pos_Y + Bar_Height + Bar_To_Button_Y), Button_W, Button_H, WHITE, RED, WHITE, "-", 2);
  up2_btn.drawButton(false);
  down2_btn.drawButton(false);

  // + - Buttons Slow Speed RH
  up4_btn.initButton  (&tft, Button_X_Pos + (Button_Spacing + (1.0 * Button_W)), (Bar_Pos_Y - Bar_To_Button_Y)  , Button_W, Button_H, WHITE, YELLOW, BLACK, "+", 2);
  down4_btn.initButton(&tft, Button_X_Pos + (Button_Spacing + (1.0 * Button_W)), (Bar_Pos_Y + Bar_Height + Bar_To_Button_Y), Button_W, Button_H, WHITE, YELLOW, BLACK, "-", 2);
  up4_btn.drawButton(false);
  down4_btn.drawButton(false);

  tft.setTextSize(2); 
  tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
  tft.setCursor(Button_X_Pos - 18, (Bar_Pos_Y + Bar_Height + Bar_To_Button_Y + Button_H) );            // Text Coordinates X, Y
  tft.print("RH Wheel");
  tft.setCursor(Button_X_Pos, (Bar_Pos_Y - Button_H - 30) );            // Text Coordinates X, Y
  tft.print("PWM");

  Print_RPM_RH_Wheel_Value_Full();  
  Print_RPM_RH_Wheel_Value_Slow(); 


// MAG Value
//------------------------------------------------------------
    
    Button_W  = 50;
    Label_X   = 150;
    Label_Y   = 100;
    Value_X2  = Label_X;                        // X Position of the item
    Value_Y2  = Label_Y + 25;           // Y Position of the item
    Value_2   = Slow_Speed_MAG;                 // Value to be modified in the menu

    tft.setTextSize(2); 
    tft.setTextColor(YELLOW, BLACK);            // Text Colour/ Background Colour
    tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
    tft.print(F("MAG Slow"));  

    
    int Button_X = Value_X2 + 80;
    int Button_Y = Value_Y2 + (0.3 * Button_H);
   
    tft.setTextSize(2); 
    tft.setTextColor(RED, BLACK);                 //Text Colour/ Background Colour
    tft.setCursor(Value_X2, Value_Y2);            // Text Coordinates X, Y
    tft.print(Value_2);    

 
    up5_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    down5_btn.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);

    up5_btn.drawButton(false);
    down5_btn.drawButton(false);



  
// Save Button

    Save_Wheels_btn.initButton(&tft, 240, 278, 80, 40, WHITE, CYAN, BLACK, "Save", 2);
    Save_Wheels_btn.drawButton(false);
  
  }
  
  


void Calculate_Gauge_Level_LH_Wheel_Full() {
  // Draw RPM Line
  Gauge_Level_LH_Full = (Bar_Height / 255) * PWM_MaxSpeed_LH;
  }

void Calculate_Gauge_Level_RH_Wheel_Full() {
  // Draw RPM Line
  Gauge_Level_RH_Full = (Bar_Height / 255) * PWM_MaxSpeed_RH;
  }

void Calculate_Gauge_Level_LH_Wheel_Slow() {
  // Draw RPM Line
  Gauge_Level_LH_Slow = (Bar_Height / 255) * PWM_Slow_Speed_LH;
  }

void Calculate_Gauge_Level_RH_Wheel_Slow() {
  // Draw RPM Line
  Gauge_Level_RH_Slow = (Bar_Height / 255) * PWM_Slow_Speed_RH;
  }

  

void React_to_Button_Press_Wheel_Motor() {

//If the LH + or . Button is pressed (up or down)
 if ((up1_btn.justPressed() )  || (down1_btn.justPressed())) {
        
    
    
    // Actions if UP is pressed
    if (up1_btn.justPressed()) {
        Clear_Old_Bar_LH_Wheel_Motor_Full(); 
        Clear_Old_RPM_LH_Wheel_Value_Full();       
        up1_btn.drawButton(true);
        PWM_MaxSpeed_LH = PWM_MaxSpeed_LH + 1;
        if (PWM_MaxSpeed_LH > 255) PWM_MaxSpeed_LH = 255;
        Calculate_Gauge_Level_LH_Wheel_Full();
        Print_RPM_LH_Wheel_Value_Full();
        Print_New_Bar_LH_Wheel_Motor_Full();
        }


    // Action if down is pressed
    if (down1_btn.justPressed()) {
        Clear_Old_Bar_LH_Wheel_Motor_Full();
        Clear_Old_RPM_LH_Wheel_Value_Full(); 
        down1_btn.drawButton(true);
        PWM_MaxSpeed_LH = PWM_MaxSpeed_LH - 1;
        if (PWM_MaxSpeed_LH < (PWM_Slow_Speed_LH + 30)) PWM_MaxSpeed_LH = PWM_Slow_Speed_LH + 30;
        Calculate_Gauge_Level_LH_Wheel_Full();
        Print_RPM_LH_Wheel_Value_Full();
        Print_New_Bar_LH_Wheel_Motor_Full();
        }
    }


//If the RH + or . Button is pressed (up or down)
 if ((up2_btn.justPressed() )  || (down2_btn.justPressed())) {
        
   
    // Actions if UP is pressed
    if (up2_btn.justPressed()) {
        Clear_Old_Bar_RH_Wheel_Motor_Full(); 
        Clear_Old_RPM_RH_Wheel_Value_Full();       
        up2_btn.drawButton(true);
        PWM_MaxSpeed_RH = PWM_MaxSpeed_RH + 1;
        if (PWM_MaxSpeed_RH > 255) PWM_MaxSpeed_RH = 255;
        Calculate_Gauge_Level_RH_Wheel_Full();
        Print_RPM_RH_Wheel_Value_Full();
        Print_New_Bar_RH_Wheel_Motor_Full();
        }


    // Action if down is pressed
    if (down2_btn.justPressed()) {
        Clear_Old_Bar_RH_Wheel_Motor_Full();
        Clear_Old_RPM_RH_Wheel_Value_Full(); 
        down2_btn.drawButton(true);
        PWM_MaxSpeed_RH = PWM_MaxSpeed_RH - 1;
        if (PWM_MaxSpeed_RH < (PWM_Slow_Speed_RH + 30)) PWM_MaxSpeed_RH = PWM_Slow_Speed_RH + 30;
        Calculate_Gauge_Level_RH_Wheel_Full();
        Print_RPM_RH_Wheel_Value_Full();
        Print_New_Bar_RH_Wheel_Motor_Full();
        }
    }


//If the LH + or - Slow Button is pressed (up or down)
 if ((up3_btn.justPressed() )  || (down3_btn.justPressed())) {  
    
    // Actions if UP is pressed
    if (up3_btn.justPressed()) {
        Clear_Old_Bar_LH_Wheel_Motor_Slow(); 
        Clear_Old_RPM_LH_Wheel_Value_Slow();       
        up3_btn.drawButton(true);
        PWM_Slow_Speed_LH = PWM_Slow_Speed_LH + 1;
        if (PWM_Slow_Speed_LH > (PWM_MaxSpeed_LH -30)) PWM_Slow_Speed_LH = PWM_MaxSpeed_LH - 30;
        Calculate_Gauge_Level_LH_Wheel_Slow();
        Print_RPM_LH_Wheel_Value_Slow();
        Print_New_Bar_LH_Wheel_Motor_Slow();
        }


    // Action if down is pressed
    if (down3_btn.justPressed()) {
        Clear_Old_Bar_LH_Wheel_Motor_Slow();
        Clear_Old_RPM_LH_Wheel_Value_Slow(); 
        down3_btn.drawButton(true);
        PWM_Slow_Speed_LH = PWM_Slow_Speed_LH - 1;
        if (PWM_Slow_Speed_LH < 100) PWM_Slow_Speed_LH = 100;
        Calculate_Gauge_Level_LH_Wheel_Slow();
        Print_RPM_LH_Wheel_Value_Slow();
        Print_New_Bar_LH_Wheel_Motor_Slow();
        }
    }


//If the RH + or - Slow Button is pressed (up or down)
 if ((up4_btn.justPressed() )  || (down4_btn.justPressed())) {  
    
    // Actions if UP is pressed
    if (up4_btn.justPressed()) {
        Clear_Old_Bar_RH_Wheel_Motor_Slow(); 
        Clear_Old_RPM_RH_Wheel_Value_Slow();       
        up4_btn.drawButton(true);
        PWM_Slow_Speed_RH = PWM_Slow_Speed_RH + 1;
        if (PWM_Slow_Speed_RH > (PWM_MaxSpeed_RH - 30)) PWM_Slow_Speed_RH = PWM_MaxSpeed_RH - 30;
        Calculate_Gauge_Level_RH_Wheel_Slow();
        Print_RPM_RH_Wheel_Value_Slow();
        Print_New_Bar_RH_Wheel_Motor_Slow();
        }


    // Action if down is pressed
    if (down4_btn.justPressed()) {
        Clear_Old_Bar_RH_Wheel_Motor_Slow();
        Clear_Old_RPM_RH_Wheel_Value_Slow(); 
        down4_btn.drawButton(true);
        PWM_Slow_Speed_RH = PWM_Slow_Speed_RH - 1;
        if (PWM_Slow_Speed_RH < 100) PWM_Slow_Speed_RH = 100;
        Calculate_Gauge_Level_RH_Wheel_Slow();
        Print_RPM_RH_Wheel_Value_Slow();
        Print_New_Bar_RH_Wheel_Motor_Slow();
        }
    }


//If the MAG Slow Button is pressed
 if ((up5_btn.justPressed() )  || (down5_btn.justPressed())) {
        
        Value_All = Slow_Speed_MAG;
        Value_X_All = Value_X2;
        Value_Y_All = Value_Y2;
    
    // Actions if UP is pressed
    if (up5_btn.justPressed()) {
        Clear_Old_Value_MAG();       
        up5_btn.drawButton(true);
        Slow_Speed_MAG = Slow_Speed_MAG + 10;
        if (Slow_Speed_MAG > -200) Slow_Speed_MAG = -200;
        Value_All = Slow_Speed_MAG;
        Int_Float = 0;
        Print_New_Value_MAG();
        }


    // Action if down is pressed
    if (down5_btn.justPressed()) {
        Clear_Old_Value_MAG();
        down2_btn.drawButton(true);
        Slow_Speed_MAG = Slow_Speed_MAG - 10;
        if (Slow_Speed_MAG < -2000) Slow_Speed_MAG = -2000;
        Value_All = Slow_Speed_MAG;
        Int_Float = 0;
        Print_New_Value_MAG();
        }
    }


 // Action if Wheel Motor Saved is pressed
 if (Save_Wheels_btn.justPressed()) {
         Menu_Complete_Wheels = true;
         tft.fillScreen(BLACK);
         Serial.println(F("Wheel Motor Data Saved and TX"));
         Menu_Active = 914;
         Send_Menu_Selected_To_Mower_MEGA();
         Transmit_Wheel_Motor_Values();
         Print_Motion_Menu();
         }  
  
}


void Clear_Old_RPM_LH_Wheel_Value_Full() {

  int Button_X_Pos = Bar_Pos_X + (0.5 * Button_W);
  
  // PWM Value
  tft.setTextSize(2); 
  tft.setTextColor(BLACK, BLACK);      //Text Colour/ Background Colour
  tft.setCursor(Button_X_Pos - Button_W - 15, (Bar_Pos_Y + Bar_Height - Gauge_Level_LH_Full) );            // Text Coordinates X, Y
  tft.print(PWM_MaxSpeed_LH); 
  }  

void Print_RPM_LH_Wheel_Value_Full() {

  int Button_X_Pos = Bar_Pos_X + (0.5 * Button_W);
  
  // PWM Value
  tft.setTextSize(2); 
  tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
  tft.setCursor(Button_X_Pos - Button_W - 15, (Bar_Pos_Y + Bar_Height - Gauge_Level_LH_Full) );            // Text Coordinates X, Y
  tft.print(PWM_MaxSpeed_LH);  
  }

void Clear_Old_Bar_LH_Wheel_Motor_Full() {
  tft.fillRect( (Bar_Pos_X + 2), (Bar_Pos_Y + Bar_Height - Gauge_Level_LH_Full + 5), (Bar_Width - 4), 5 , GREY);
}

void Print_New_Bar_LH_Wheel_Motor_Full() {
  tft.fillRect( (Bar_Pos_X + 2), (Bar_Pos_Y + Bar_Height - Gauge_Level_LH_Full + 5), (Bar_Width - 4), 5 , RED);
  }


void Clear_Old_RPM_RH_Wheel_Value_Full() {

  int Button_X_Pos = Bar_Pos_X + LH_RH_Spacing + (0.5 * Button_W);
  
  // PWM Value
  tft.setTextSize(2); 
  tft.setTextColor(BLACK, BLACK);      //Text Colour/ Background Colour
  tft.setCursor(Button_X_Pos  - Button_W - 15, (Bar_Pos_Y + Bar_Height - Gauge_Level_RH_Full) );            // Text Coordinates X, Y
  tft.print(PWM_MaxSpeed_RH); 
  }  

void Print_RPM_RH_Wheel_Value_Full() {

  int Button_X_Pos = Bar_Pos_X + LH_RH_Spacing + (0.5 * Button_W);
  
  // PWM Value
  tft.setTextSize(2); 
  tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
  tft.setCursor(Button_X_Pos - Button_W - 15, (Bar_Pos_Y + Bar_Height - Gauge_Level_RH_Full) );            // Text Coordinates X, Y
  tft.print(PWM_MaxSpeed_RH);  
  }

void Clear_Old_Bar_RH_Wheel_Motor_Full() {
  tft.fillRect( (Bar_Pos_X + LH_RH_Spacing + 2), (Bar_Pos_Y + Bar_Height - Gauge_Level_RH_Full + 5), (Bar_Width - 4), 5 , GREY);
}

void Print_New_Bar_RH_Wheel_Motor_Full() {
  tft.fillRect( (Bar_Pos_X + LH_RH_Spacing + 2), (Bar_Pos_Y + Bar_Height - Gauge_Level_RH_Full + 5), (Bar_Width - 4), 5 , RED);
  }



void Clear_Old_RPM_LH_Wheel_Value_Slow() {

  int Button_X_Pos = Bar_Pos_X + (0.5 * Button_W);
  
  // PWM Value
  tft.setTextSize(2); 
  tft.setTextColor(BLACK, BLACK);      //Text Colour/ Background Colour
  tft.setCursor(Button_X_Pos - Button_W - 15, (Bar_Pos_Y + Bar_Height - Gauge_Level_LH_Slow) );            // Text Coordinates X, Y
  tft.print(PWM_Slow_Speed_LH); 
  }  

void Print_RPM_LH_Wheel_Value_Slow() {

  int Button_X_Pos = Bar_Pos_X + (0.5 * Button_W);
  
  // PWM Value
  tft.setTextSize(2); 
  tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
  tft.setCursor(Button_X_Pos - Button_W - 15, (Bar_Pos_Y + Bar_Height - Gauge_Level_LH_Slow) );            // Text Coordinates X, Y
  tft.print(PWM_Slow_Speed_LH);  
  }

void Clear_Old_Bar_LH_Wheel_Motor_Slow() {
  tft.fillRect( (Bar_Pos_X + 2), (Bar_Pos_Y + Bar_Height - Gauge_Level_LH_Slow + 5), (Bar_Width - 4), 5 , GREY);
}

void Print_New_Bar_LH_Wheel_Motor_Slow() {
  tft.fillRect( (Bar_Pos_X + 2), (Bar_Pos_Y + Bar_Height - Gauge_Level_LH_Slow + 5), (Bar_Width - 4), 5 , YELLOW);
  }


void Clear_Old_RPM_RH_Wheel_Value_Slow() {

  int Button_X_Pos = Bar_Pos_X + LH_RH_Spacing + (0.5 * Button_W);
  
  // PWM Value
  tft.setTextSize(2); 
  tft.setTextColor(BLACK, BLACK);      //Text Colour/ Background Colour
  tft.setCursor(Button_X_Pos  - Button_W - 15, (Bar_Pos_Y + Bar_Height - Gauge_Level_RH_Slow) );            // Text Coordinates X, Y
  tft.print(PWM_Slow_Speed_RH); 
  }  

void Print_RPM_RH_Wheel_Value_Slow() {

  int Button_X_Pos = Bar_Pos_X + LH_RH_Spacing + (0.5 * Button_W);
  
  // PWM Value
  tft.setTextSize(2); 
  tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
  tft.setCursor(Button_X_Pos - Button_W - 15, (Bar_Pos_Y + Bar_Height - Gauge_Level_RH_Slow) );            // Text Coordinates X, Y
  tft.print(PWM_Slow_Speed_RH);  
  }

void Clear_Old_Bar_RH_Wheel_Motor_Slow() {
  tft.fillRect( (Bar_Pos_X + LH_RH_Spacing + 2), (Bar_Pos_Y + Bar_Height - Gauge_Level_RH_Slow + 5), (Bar_Width - 4), 5 , GREY);
}

void Print_New_Bar_RH_Wheel_Motor_Slow() {
  tft.fillRect( (Bar_Pos_X + LH_RH_Spacing + 2), (Bar_Pos_Y + Bar_Height - Gauge_Level_RH_Slow + 5), (Bar_Width - 4), 5 , YELLOW);
  }





void Clear_Old_Value_MAG() {
        // Draws over the previous Value in Black text to clear it.... !?
        tft.setTextSize(2); 
        tft.setTextColor(BLACK, BLACK);      //Text Colour/ Background Colour
        tft.setCursor(Value_X_All, Value_Y_All);            // Text Coordinates X, Y
        if (Int_Float == 0) {
          tft.print(Value_All);
          }
        if (Int_Float == 1) {
          tft.print(Value_All_Float);
          }  
        }

void Print_New_Value_MAG() {        

        tft.setTextSize(2); 
        tft.setTextColor(RED, BLACK);      //Text Colour/ Background Colour
        tft.setCursor(Value_X_All, Value_Y_All);            // Text Coordinates X, Y
        if (Int_Float == 0) {
          tft.print(Value_All);
          }
        if (Int_Float == 1) {
          tft.print(Value_All_Float);
          }          
        }


void Sense_Button_Press_Wheel_Motor() {
    down = Touch_getXY();
    
    up1_btn.press    (down && up1_btn.contains(pixel_x, pixel_y));
    down1_btn.press  (down && down1_btn.contains(pixel_x, pixel_y));
    up2_btn.press    (down && up2_btn.contains(pixel_x, pixel_y));
    down2_btn.press  (down && down2_btn.contains(pixel_x, pixel_y));
    up3_btn.press    (down && up3_btn.contains(pixel_x, pixel_y));
    down3_btn.press  (down && down3_btn.contains(pixel_x, pixel_y));
    up4_btn.press    (down && up4_btn.contains(pixel_x, pixel_y));
    down4_btn.press  (down && down4_btn.contains(pixel_x, pixel_y));
    up5_btn.press    (down && up5_btn.contains(pixel_x, pixel_y));
    down5_btn.press  (down && down5_btn.contains(pixel_x, pixel_y));
    Save_Wheels_btn.press   (down && Save_Wheels_btn.contains(pixel_x, pixel_y));

    if (up1_btn.justReleased())     up1_btn.drawButton();
    if (down1_btn.justReleased())   down1_btn.drawButton();
    if (up2_btn.justReleased())     up2_btn.drawButton();
    if (down2_btn.justReleased())   down2_btn.drawButton();
    if (up3_btn.justReleased())     up3_btn.drawButton();
    if (down3_btn.justReleased())   down3_btn.drawButton();  
    if (up4_btn.justReleased())     up4_btn.drawButton();
    if (down4_btn.justReleased())   down4_btn.drawButton();  
    if (up5_btn.justReleased())     up5_btn.drawButton();
    if (down5_btn.justReleased())   down5_btn.drawButton();  
    if (Save_Wheels_btn.justReleased())   Save_Wheels_btn.drawButton();
}
