
void Print_Wheel_Motors_Menu() {  


  tft.fillScreen(BLACK);

    Serial.println(F("RX Wheel PWM"));
    Menu_Active = 14;                           // Code to tell the Mower MEGA which data to transmit.
    Send_Menu_Selected_To_Mower_MEGA();         // Send the code to the Mower MEGA which data should be transfered
    delay(RX_Delay);                            // Wait time for the Mower MEGA to transmit the data.
    Receive_7_Data_Sets();                      // Recieve data sets from the Mower MEGA
    PWM_MaxSpeed_LH   = Data1;                   // Fill the variable values with the data sets
    PWM_MaxSpeed_RH   = Data2;
    PWM_Slow_Speed_LH = Data3;
    PWM_Slow_Speed_RH = Data4;
    Slow_Speed_MAG    = Data5;
    Slow_Speed_MAG    = Slow_Speed_MAG * 10;
    Data6 = 0;
    Data7 = 0;
    Clear_Data_Streams();

    if (Debug_RX_Transfer == 1) {              // Display the received values on the TFT Screen if required.        
      Set_TFT_Screen_Pos();
      tft.print(F("PWM LH = "));
      tft.println(PWM_MaxSpeed_LH);
      tft.print(F("PWM RH = "));
      tft.println(PWM_MaxSpeed_RH);
      tft.print(F("PWM S LH = "));
      tft.println(PWM_Slow_Speed_LH);
      tft.print(F("PWM S RH = "));
      tft.println(PWM_Slow_Speed_RH);
      tft.print(F("Slow MAG = "));
      tft.println(Slow_Speed_MAG);
      tft.println(F(" ")); 
      delay(TFT_Check);
      tft.fillScreen(BLACK);     
      }


  
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
  UP1_BTN.initButton  (&tft, Button_X_Pos, (Bar_Pos_Y - Bar_To_Button_Y)  , Button_W, Button_H, WHITE, RED, WHITE, "+", 2);
  DOWN1_BTN.initButton(&tft, Button_X_Pos, (Bar_Pos_Y + Bar_Height + Bar_To_Button_Y), Button_W, Button_H, WHITE, RED, WHITE, "-", 2);
  UP1_BTN.drawButton(false);
  DOWN1_BTN.drawButton(false);

  // + - Buttons Slow Speed LH
  UP3_BTN.initButton  (&tft, Button_X_Pos + (Button_Spacing + (1.0 * Button_W)), (Bar_Pos_Y - Bar_To_Button_Y)  , Button_W, Button_H, WHITE, YELLOW, BLACK, "+", 2);
  DOWN3_BTN.initButton(&tft, Button_X_Pos + (Button_Spacing + (1.0 * Button_W)), (Bar_Pos_Y + Bar_Height + Bar_To_Button_Y), Button_W, Button_H, WHITE, YELLOW, BLACK, "-", 2);
  UP3_BTN.drawButton(false);
  DOWN3_BTN.drawButton(false);

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

  UP2_BTN.initButton  (&tft, Button_X_Pos , (Bar_Pos_Y - Bar_To_Button_Y)  , Button_W, Button_H, WHITE, RED, WHITE, "+", 2);
  DOWN2_BTN.initButton(&tft, Button_X_Pos , (Bar_Pos_Y + Bar_Height + Bar_To_Button_Y), Button_W, Button_H, WHITE, RED, WHITE, "-", 2);
  UP2_BTN.drawButton(false);
  DOWN2_BTN.drawButton(false);

  // + - Buttons Slow Speed RH
  UP4_BTN.initButton  (&tft, Button_X_Pos + (Button_Spacing + (1.0 * Button_W)), (Bar_Pos_Y - Bar_To_Button_Y)  , Button_W, Button_H, WHITE, YELLOW, BLACK, "+", 2);
  DOWN4_BTN.initButton(&tft, Button_X_Pos + (Button_Spacing + (1.0 * Button_W)), (Bar_Pos_Y + Bar_Height + Bar_To_Button_Y), Button_W, Button_H, WHITE, YELLOW, BLACK, "-", 2);
  UP4_BTN.drawButton(false);
  DOWN4_BTN.drawButton(false);

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

 
    UP5_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    DOWN5_BTN.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);

    UP5_BTN.drawButton(false);
    DOWN5_BTN.drawButton(false);



  
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
 if ((UP1_BTN.justPressed() )  || (DOWN1_BTN.justPressed())) {
        
    
    
    // Actions if UP is pressed
    if (UP1_BTN.justPressed()) {
        Clear_Old_Bar_LH_Wheel_Motor_Full(); 
        Clear_Old_RPM_LH_Wheel_Value_Full();       
        UP1_BTN.drawButton(true);
        PWM_MaxSpeed_LH = PWM_MaxSpeed_LH + 1;
        if (PWM_MaxSpeed_LH > 255) PWM_MaxSpeed_LH = 255;
        Calculate_Gauge_Level_LH_Wheel_Full();
        Print_RPM_LH_Wheel_Value_Full();
        Print_New_Bar_LH_Wheel_Motor_Full();
        }


    // Action if down is pressed
    if (DOWN1_BTN.justPressed()) {
        Clear_Old_Bar_LH_Wheel_Motor_Full();
        Clear_Old_RPM_LH_Wheel_Value_Full(); 
        DOWN1_BTN.drawButton(true);
        PWM_MaxSpeed_LH = PWM_MaxSpeed_LH - 1;
        if (PWM_MaxSpeed_LH < (PWM_Slow_Speed_LH + 30)) PWM_MaxSpeed_LH = PWM_Slow_Speed_LH + 30;
        Calculate_Gauge_Level_LH_Wheel_Full();
        Print_RPM_LH_Wheel_Value_Full();
        Print_New_Bar_LH_Wheel_Motor_Full();
        }
    }


//If the RH + or . Button is pressed (up or down)
 if ((UP2_BTN.justPressed() )  || (DOWN2_BTN.justPressed())) {
        
   
    // Actions if UP is pressed
    if (UP2_BTN.justPressed()) {
        Clear_Old_Bar_RH_Wheel_Motor_Full(); 
        Clear_Old_RPM_RH_Wheel_Value_Full();       
        UP2_BTN.drawButton(true);
        PWM_MaxSpeed_RH = PWM_MaxSpeed_RH + 1;
        if (PWM_MaxSpeed_RH > 255) PWM_MaxSpeed_RH = 255;
        Calculate_Gauge_Level_RH_Wheel_Full();
        Print_RPM_RH_Wheel_Value_Full();
        Print_New_Bar_RH_Wheel_Motor_Full();
        }


    // Action if down is pressed
    if (DOWN2_BTN.justPressed()) {
        Clear_Old_Bar_RH_Wheel_Motor_Full();
        Clear_Old_RPM_RH_Wheel_Value_Full(); 
        DOWN2_BTN.drawButton(true);
        PWM_MaxSpeed_RH = PWM_MaxSpeed_RH - 1;
        if (PWM_MaxSpeed_RH < (PWM_Slow_Speed_RH + 30)) PWM_MaxSpeed_RH = PWM_Slow_Speed_RH + 30;
        Calculate_Gauge_Level_RH_Wheel_Full();
        Print_RPM_RH_Wheel_Value_Full();
        Print_New_Bar_RH_Wheel_Motor_Full();
        }
    }


//If the LH + or - Slow Button is pressed (up or down)
 if ((UP3_BTN.justPressed() )  || (DOWN3_BTN.justPressed())) {  
    
    // Actions if UP is pressed
    if (UP3_BTN.justPressed()) {
        Clear_Old_Bar_LH_Wheel_Motor_Slow(); 
        Clear_Old_RPM_LH_Wheel_Value_Slow();       
        UP3_BTN.drawButton(true);
        PWM_Slow_Speed_LH = PWM_Slow_Speed_LH + 1;
        if (PWM_Slow_Speed_LH > (PWM_MaxSpeed_LH -30)) PWM_Slow_Speed_LH = PWM_MaxSpeed_LH - 30;
        Calculate_Gauge_Level_LH_Wheel_Slow();
        Print_RPM_LH_Wheel_Value_Slow();
        Print_New_Bar_LH_Wheel_Motor_Slow();
        }


    // Action if down is pressed
    if (DOWN3_BTN.justPressed()) {
        Clear_Old_Bar_LH_Wheel_Motor_Slow();
        Clear_Old_RPM_LH_Wheel_Value_Slow(); 
        DOWN3_BTN.drawButton(true);
        PWM_Slow_Speed_LH = PWM_Slow_Speed_LH - 1;
        if (PWM_Slow_Speed_LH < 100) PWM_Slow_Speed_LH = 100;
        Calculate_Gauge_Level_LH_Wheel_Slow();
        Print_RPM_LH_Wheel_Value_Slow();
        Print_New_Bar_LH_Wheel_Motor_Slow();
        }
    }


//If the RH + or - Slow Button is pressed (up or down)
 if ((UP4_BTN.justPressed() )  || (DOWN4_BTN.justPressed())) {  
    
    // Actions if UP is pressed
    if (UP4_BTN.justPressed()) {
        Clear_Old_Bar_RH_Wheel_Motor_Slow(); 
        Clear_Old_RPM_RH_Wheel_Value_Slow();       
        UP4_BTN.drawButton(true);
        PWM_Slow_Speed_RH = PWM_Slow_Speed_RH + 1;
        if (PWM_Slow_Speed_RH > (PWM_MaxSpeed_RH - 30)) PWM_Slow_Speed_RH = PWM_MaxSpeed_RH - 30;
        Calculate_Gauge_Level_RH_Wheel_Slow();
        Print_RPM_RH_Wheel_Value_Slow();
        Print_New_Bar_RH_Wheel_Motor_Slow();
        }


    // Action if down is pressed
    if (DOWN4_BTN.justPressed()) {
        Clear_Old_Bar_RH_Wheel_Motor_Slow();
        Clear_Old_RPM_RH_Wheel_Value_Slow(); 
        DOWN4_BTN.drawButton(true);
        PWM_Slow_Speed_RH = PWM_Slow_Speed_RH - 1;
        if (PWM_Slow_Speed_RH < 100) PWM_Slow_Speed_RH = 100;
        Calculate_Gauge_Level_RH_Wheel_Slow();
        Print_RPM_RH_Wheel_Value_Slow();
        Print_New_Bar_RH_Wheel_Motor_Slow();
        }
    }


//If the MAG Slow Button is pressed
 if ((UP5_BTN.justPressed() )  || (DOWN5_BTN.justPressed())) {
        
        Value_All = Slow_Speed_MAG;
        Value_X_All = Value_X2;
        Value_Y_All = Value_Y2;
    
    // Actions if UP is pressed
    if (UP5_BTN.justPressed()) {
        Clear_Old_Value_MAG();       
        UP5_BTN.drawButton(true);
        Slow_Speed_MAG = Slow_Speed_MAG + 10;
        if (Slow_Speed_MAG > -200) Slow_Speed_MAG = -200;
        Value_All = Slow_Speed_MAG;
        Int_Float = 0;
        Print_New_Value_MAG();
        }


    // Action if down is pressed
    if (DOWN5_BTN.justPressed()) {
        Clear_Old_Value_MAG();
        DOWN2_BTN.drawButton(true);
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
    
    UP1_BTN.press    (down && UP1_BTN.contains(pixel_x, pixel_y));
    DOWN1_BTN.press  (down && DOWN1_BTN.contains(pixel_x, pixel_y));
    UP2_BTN.press    (down && UP2_BTN.contains(pixel_x, pixel_y));
    DOWN2_BTN.press  (down && DOWN2_BTN.contains(pixel_x, pixel_y));
    UP3_BTN.press    (down && UP3_BTN.contains(pixel_x, pixel_y));
    DOWN3_BTN.press  (down && DOWN3_BTN.contains(pixel_x, pixel_y));
    UP4_BTN.press    (down && UP4_BTN.contains(pixel_x, pixel_y));
    DOWN4_BTN.press  (down && DOWN4_BTN.contains(pixel_x, pixel_y));
    UP5_BTN.press    (down && UP5_BTN.contains(pixel_x, pixel_y));
    DOWN5_BTN.press  (down && DOWN5_BTN.contains(pixel_x, pixel_y));
    Save_Wheels_btn.press   (down && Save_Wheels_btn.contains(pixel_x, pixel_y));

    if (UP1_BTN.justReleased())     UP1_BTN.drawButton();
    if (DOWN1_BTN.justReleased())   DOWN1_BTN.drawButton();
    if (UP2_BTN.justReleased())     UP2_BTN.drawButton();
    if (DOWN2_BTN.justReleased())   DOWN2_BTN.drawButton();
    if (UP3_BTN.justReleased())     UP3_BTN.drawButton();
    if (DOWN3_BTN.justReleased())   DOWN3_BTN.drawButton();  
    if (UP4_BTN.justReleased())     UP4_BTN.drawButton();
    if (DOWN4_BTN.justReleased())   DOWN4_BTN.drawButton();  
    if (UP5_BTN.justReleased())     UP5_BTN.drawButton();
    if (DOWN5_BTN.justReleased())   DOWN5_BTN.drawButton();  
    if (Save_Wheels_btn.justReleased())   Save_Wheels_btn.drawButton();
}
