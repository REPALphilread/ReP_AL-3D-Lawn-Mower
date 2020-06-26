void Print_AlarmX_Menu() {  

     // Framework for the buttons - setting the start position of the Quick start button wil automatically then space the other buttons
    tft.fillScreen(BLACK);
    int Label_Time_Spacing = 30;          // Space between the text and the -ve button
    int Button_W = 50;                // width of the button
    int Button_H = 40;                // height of the button
    int Button_Spacing = 5;           // Space between the -ve and +ve buttons
    int Time_Spacing = 150;            // Distance between the Hours and Minutes Number
    Offset_Btn = 25;
    int Time_Button_Spacing = 100;

    // Main Menu Title

    tft.setTextSize(2); 
    tft.setTextColor(GREEN, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(10, 10);            // Text Coordinates X, Y
    if (Alarm_X_Selected == 1) tft.print(F("Alarm 1 Settings"));  
    if (Alarm_X_Selected == 2) tft.print(F("Alarm 2 Settings"));  
    if (Alarm_X_Selected == 3) tft.print(F("Alarm 3 Settings"));  
    
    // Framework for the + - buttons - setting the start position of the + button wil automatically then space the - button

    // Top left position of the first menu item.    
    Pos_X1   = 35;
    Pos_Y1   = 50;

    
    // Size of the Alarm Time Label
    tft.setTextSize(2); 
    tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Pos_X1, Pos_Y1);            // Text Coordinates X, Y
    tft.print(F("Start Time"));  

    // Size of the Alarm Time Numbers
    tft.setTextSize(9); 
    tft.setTextColor(RED, BLACK);      //Text Colour/ Background Colour

    // Hours X 10 
    Pos_X1 = Pos_X1;
    Pos_Y1 = Pos_Y1 + Label_Time_Spacing;  
    tft.setCursor(Pos_X1, Pos_Y1);            // Text Coordinates X, Y
        if (Alarm_X_Hour > 9) tft.print(Alarm_X_Hour);
        if (Alarm_X_Hour < 10) {
          tft.print("0");
          tft.print(Alarm_X_Hour);
        }

    Pos_X3 = Pos_X1 + 100;
    Pos_Y3 = Pos_Y1;  
    tft.setCursor(Pos_X3, Pos_Y3);            // Text Coordinates X, Y
    tft.print(":");     


    // Minutes X 10 
    Pos_X2 = Pos_X1 + Time_Spacing;
    Pos_Y2 = Pos_Y1;  
    tft.setCursor(Pos_X2, Pos_Y2);            // Text Coordinates X, Y
        if (Alarm_X_Minute > 9) tft.print(Alarm_X_Minute);
        if (Alarm_X_Minute < 10) {
          tft.print("0");
          tft.print(Alarm_X_Minute);
        }
    
    // + - Hour Value
    int Button_X = Pos_X1 + (0.5 * Button_W);
    int Button_Y = Pos_Y1 + Time_Button_Spacing;
 
    up1_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    down1_btn.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);

    up1_btn.drawButton(false);
    down1_btn.drawButton(false);

    // + - Minute Value
    Button_X = Pos_X2 + (0.5 * Button_W);
    Button_Y = Pos_Y2 + Time_Button_Spacing;
 
    up2_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    down2_btn.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);

    up2_btn.drawButton(false);
    down2_btn.drawButton(false);


    // Position Action Label
    tft.setTextSize(2); 
    tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Pos_X1, Pos_Y1 + 150);            // Text Coordinates X, Y
    tft.print(F("Action")); 

    // Action

    Button_W = 260;
    Button_X = Pos_X1 + (0.5 * Button_W);
    Button_Y = Pos_Y1 + Time_Button_Spacing + 100;
 
    if (Alarm_X_Action == 1) up3_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, BLUE, WHITE, "Exit Z1", 2);
    if (Alarm_X_Action == 2) up3_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, MAGENTA, WHITE, "Exit Z2", 2);
    if (Alarm_X_Action == 3) up3_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, YELLOW, BLACK, "Mow Line", 2);
    if (Alarm_X_Action == 4) up3_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, WHITE, BLACK, "Quick Go", 2);
    if (Alarm_X_Action == 5) up3_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREY, BLACK, "Custom", 2);
    up3_btn.drawButton(false);


    // ALARM ON/OFF

    Button_W = 100;
    Button_H = 120;
    Pos_X4 = 380;
    Pos_Y4 = Pos_Y1 + (0.5* Button_H);
    Button_X = Pos_X4;
    Button_Y = Pos_Y4;
 
    if (Alarm_X_ON == 0) up4_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
    if (Alarm_X_ON == 1) up4_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
    up4_btn.drawButton(false);


// Done Button

    Save_AlarmX_btn.initButton(&tft, 410, 275, 80, 40, WHITE, CYAN, BLACK, "Save", 2);
    Save_AlarmX_btn.drawButton(false);


}



void React_to_Button_AlarmX() {

  //If the Button 1 Turn Angle Max is pressed (up or down)
   if ((up1_btn.justPressed() )  || (down1_btn.justPressed())) {
        Value_All = Alarm_X_Hour;
        Label_X = Pos_X1;
        Label_Y = Pos_Y1;
    
    // Actions if UP is pressed
    if (up1_btn.justPressed()) {
        Clear_Old_Value_Time();       
        up1_btn.drawButton(true);
        Value_All = Value_All + 1;
        if (Value_All > 24) Value_All = 0;
        Alarm_X_Hour = Value_All;
        Print_New_Value_Time();
        }


    // Action if down is pressed
    if (down1_btn.justPressed()) {
        Clear_Old_Value_Time();
        down1_btn.drawButton(true);
        Value_All = Value_All - 1;
        if (Value_All < 0) Value_All = 23;
        Alarm_X_Hour = Value_All;
        Print_New_Value_Time();
        }
    
    }

  //If the Reverse Button 2 is pressed (up or down)
   if ((up2_btn.justPressed() )  || (down2_btn.justPressed())) {
        Value_All = Alarm_X_Minute;
        Label_X   = Pos_X2;
        Label_Y   = Pos_Y2;
    
    // Actions if UP is pressed
    if (up2_btn.justPressed()) {
        Clear_Old_Value_Time();       
        up2_btn.drawButton(true);
        Value_All = Value_All + 1;
        if (Value_All > 59) Value_All = 0;
        Alarm_X_Minute = Value_All;
        Print_New_Value_Time();
        }


    // Action if down is pressed
    if (down2_btn.justPressed()) {
        Clear_Old_Value_Time();
        down2_btn.drawButton(true);
        Value_All = Value_All - 1;
        if (Value_All < 0) Value_All = 59;
        Alarm_X_Minute = Value_All;
        Print_New_Value_Time();
        }
    
    }



  //Action Selection
   if (up3_btn.justPressed() ) {

        Alarm_X_Action = Alarm_X_Action + 1;
        if (Alarm_X_Action > 5) Alarm_X_Action = 1;
        int Button_W = 260;
        int Button_X = Pos_X1 + (0.5 * Button_W);
        int Button_Y = Pos_Y1 + 200;
        int Button_H = 40; 

 
    if (Alarm_X_Action == 1) up3_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, BLUE, WHITE, "Exit Z1", 2);
    if (Alarm_X_Action == 2) up3_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, MAGENTA, WHITE, "Exit Z2", 2);
    if (Alarm_X_Action == 3) up3_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, YELLOW, BLACK, "Mow Line", 2);
    if (Alarm_X_Action == 4) up3_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, WHITE, BLACK, "Quick Go", 2);
    if (Alarm_X_Action == 5) up3_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREY, BLACK, "Custom", 2);
       up3_btn.drawButton(false);
        
 delay(200);
    
   }

  //Alarm ON/OFF
   if (up4_btn.justPressed() ) {

        int Button_W = 100;
        int Button_H = 120;
        Pos_X4 = 380;
        Pos_Y4 = Pos_Y1 + (0.5* Button_H);
        int Button_X = Pos_X4;
        int Button_Y = Pos_Y4;
        bool Changed = 0;

        if ((Alarm_X_ON == 1) && (Changed ==0))  {
          Alarm_X_ON = 0;
          Changed = 1;
          up4_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "OFF", 2);
          up4_btn.drawButton(false);
          }
        
        if ((Alarm_X_ON == 0) && (Changed ==0)) {
          Alarm_X_ON = 1;
          Changed = 1;            
          up4_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, GREEN, BLACK, "ON", 2);
          up4_btn.drawButton(false);
        }

  delay(200);

    
   }


 // Action if Sonar Save is pressed
 if (Save_AlarmX_btn.justPressed()) {
         Menu_Complete_AlarmX = true;
         tft.fillScreen(BLACK);
         Serial.println(F("Alarm Data Saved and TX"));
         if (Alarm_X_Selected == 1) {
           Alarm_1_ON =     Alarm_X_ON;                 
           Alarm_1_Hour =   Alarm_X_Hour;               
           Alarm_1_Minute = Alarm_X_Minute;             
           Alarm_1_Repeat = Alarm_X_Repeat;                
           Alarm_1_Action = Alarm_X_Action;
           Menu_Active = 920;
           Send_Menu_Selected_To_Mower_MEGA();
           Transmit_Save_Alarm1_Values();
           }
         if (Alarm_X_Selected == 2) {
           Alarm_2_ON =     Alarm_X_ON;                 
           Alarm_2_Hour =   Alarm_X_Hour;               
           Alarm_2_Minute = Alarm_X_Minute;             
           Alarm_2_Repeat = Alarm_X_Repeat;                
           Alarm_2_Action = Alarm_X_Action;
           Menu_Active = 921;
           Send_Menu_Selected_To_Mower_MEGA();
           Transmit_Save_Alarm2_Values();
           }
         if (Alarm_X_Selected == 3) {
           Alarm_3_ON =     Alarm_X_ON;                 
           Alarm_3_Hour =   Alarm_X_Hour;               
           Alarm_3_Minute = Alarm_X_Minute;             
           Alarm_3_Repeat = Alarm_X_Repeat;                
           Alarm_3_Action = Alarm_X_Action;
           Menu_Active = 922;
           Send_Menu_Selected_To_Mower_MEGA();
           Transmit_Save_Alarm3_Values();
           }         
         
         Print_Time_Menu();
         
         }

}


void Clear_Old_Value_Time() {
        // Draws over the previous Value in Black text to clear it.... !?
        tft.setTextSize(9); 
        tft.setTextColor(BLACK, BLACK);      //Text Colour/ Background Colour
        tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
        if (Value_All > 9) tft.print(Value_All);
        if (Value_All < 10) {
          tft.print("0");
          tft.print(Value_All);
        }
        }


void Print_New_Value_Time() {        

        tft.setTextSize(9); 
        tft.setTextColor(RED, BLACK);      //Text Colour/ Background Colour
        tft.setCursor(Label_X, Label_Y);            // Text Coordinates X, Y
        if (Value_All > 9) tft.print(Value_All);
        if (Value_All < 10) {
          tft.print("0");
          tft.print(Value_All);
        }
        }




void Sense_Button_AlarmX() {
    down = Touch_getXY();
    up1_btn.press             (down && up1_btn.contains(pixel_x, pixel_y));
    down1_btn.press           (down && down1_btn.contains(pixel_x, pixel_y));
    up2_btn.press             (down && up2_btn.contains(pixel_x, pixel_y));
    down2_btn.press           (down && down2_btn.contains(pixel_x, pixel_y));
    up3_btn.press             (down && up3_btn.contains(pixel_x, pixel_y));
    down3_btn.press           (down && down3_btn.contains(pixel_x, pixel_y));
    up4_btn.press             (down && up4_btn.contains(pixel_x, pixel_y));
    Save_AlarmX_btn.press     (down && Save_AlarmX_btn.contains(pixel_x, pixel_y));


    if (up1_btn.justReleased())             up1_btn.drawButton();
    if (down1_btn.justReleased())           down1_btn.drawButton();
    if (up2_btn.justReleased())             up2_btn.drawButton();  
    if (down2_btn.justReleased())           down2_btn.drawButton();
    if (up3_btn.justReleased())             up3_btn.drawButton();
    if (up4_btn.justReleased())             up4_btn.drawButton();
    if (down3_btn.justReleased())           down3_btn.drawButton();
    if (Save_AlarmX_btn.justReleased())     Save_AlarmX_btn.drawButton();
    }


void Check_For_Active_Alarms() {
    if ((Alarm_1_ON == 1) || (Alarm_2_ON == 1) || (Alarm_3_ON == 1)) {
      bmpDraw("Alarmbell.bmp", 390, 235);
      Serial.println(F("ALARM ON"));
    }
}
