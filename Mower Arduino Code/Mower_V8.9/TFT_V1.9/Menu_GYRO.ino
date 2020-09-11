
// Menu GYRO
//*********************************



void Print_GYRO_Menu() {

    tft.fillScreen(BLACK);
    //if (Draw_Pictures == 1)   bmpDraw("Compass.bmp", 250, 150);      //Draw the mower picture
    delay(100); 

    
    // Framework for the buttons - setting the start position of the Quick start button wil automatically then space the other buttons

    Pos_X1 = 100;
    Pos_Y1 = 80;
    int Menu_Btn_Space = 100;          // Space between the adjacent buttons
    int Button_W = 160;                // width of the button
    int Button_H = 60;                // height of the button
    int Button_Spacing = 5;

    int Menu_Spacing = 10;            // Distance between the Menu Items (bottom of the last button to the label of the next item)
    int Txt_Size_Main_Menu = 2;
    int Column_Spacing = 200; 
    int Offset_Btn = 25;



    // Main Menu Title
    tft.setTextSize(Txt_Size_Main_Menu); 
    tft.setTextColor(GREEN, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(20, 10);            // Text Coordinates X, Y
    tft.print(F("GYRO Menu"));  
    
    
    
    //Menu GYRO
    //------------------------------------------------------------
    
    // GPS Settings
    int Button_X = Pos_X1;
    int Button_Y = Pos_Y1;
   
    //GYRO ONOFF
    
    if (GYRO_Enabled == 1) GYRO_Enabled_btn.initButton(&tft, Pos_X1, Pos_Y1, Button_W, Button_H, RED, GREEN, BLACK, "GYRO ON", 2);
    if (GYRO_Enabled == 0) GYRO_Enabled_btn.initButton(&tft, Pos_X1, Pos_Y1, Button_W, Button_H, WHITE, RED, WHITE, "GYRO OFF", 2);
    GYRO_Enabled_btn.drawButton(false);


     //GYRO PID Value
    //------------------------------------------------------------
    
    Pos_X5     = 250;
    Pos_Y5     = 55;
    Button_W = 60;                // width of the button
    Button_H = 40;                // height of the button
    Button_Spacing = 5;           // Space between the -ve and +ve buttons

    // Label
    tft.setTextSize(1); 
    tft.setTextColor(YELLOW, BLACK);            // Text Colour/ Background Colour
    tft.setCursor(Pos_X5, Pos_Y5);            // Text Coordinates X, Y
    tft.print(F("GYRO Power | P = "));  

    // Value Number
    Pos_Y5  = Pos_Y5 + Offset_Btn;           // Y Position of the item
    tft.setTextSize(2); 
    tft.setTextColor(RED, BLACK);                 //Text Colour/ Background Colour
    tft.setCursor(Pos_X5, Pos_Y5);            // Text Coordinates X, Y
    tft.print(GPower);    

    // Buttons
    Button_X = Pos_X5 + Menu_Btn_Space;
    Button_Y = Pos_Y5 + (0.2 * Button_H);
    up4_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    down4_btn.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);
    up4_btn.drawButton(false);
    down4_btn.drawButton(false);





// Done GYRO Button

    Done_GYRO_btn.initButton(&tft, 425, 278, 80, 40, WHITE, CYAN, BLACK, "Save", 2);
    Done_GYRO_btn.drawButton(false);
  
}


void React_to_Button_Press_GYRO() {



    // Action if GYRO ONOFF is pressed
    if (GYRO_Enabled_btn.justPressed()) {
        
        bool Changed = 0;
        int Button_W = 160;
        int Button_H = 60;
        int Menu_Spacing = 20; 
        int Column_Spacing = 200; 
     
        int Button_X = Pos_X1;
        int Button_Y = Pos_Y1;  
      
        if ((GYRO_Enabled == 1) && (Changed == 0))  {
          GYRO_Enabled  = 0;
          Changed = 1;
          GYRO_Enabled_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "GYRO OFF", 2);
          GYRO_Enabled_btn.drawButton(false);
          }
        
        if ((GYRO_Enabled  == 0) && (Changed == 0)) {
          GYRO_Enabled  = 1;
          Changed = 1;
          GYRO_Enabled_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, BLACK, GREEN, BLACK, "GYRO ON", 2);
          GYRO_Enabled_btn.drawButton(false);
        }          

    }
        
    
          

    
//If the GYRO P is pressed (up or down)
 if ((up4_btn.justPressed() )  || (down4_btn.justPressed())) {
        
        Value_All_Float = GPower;
        Value_X_All = Pos_X5;
        Value_Y_All = Pos_Y5;
    
    // Actions if UP is pressed
    if (up4_btn.justPressed()) {
        Clear_Old_Value_GYRO();       
        up4_btn.drawButton(true);
        Value_All_Float = Value_All_Float + 0.1;
        if (Value_All_Float > 8) Value_All_Float = 8;
        GPower = Value_All_Float;
        Int_Float = 1;
        Print_New_Value_GYRO();
        Int_Float = 0;
        }


    // Action if down is pressed
    if (down4_btn.justPressed()) {
        Clear_Old_Value_GYRO();
        down4_btn.drawButton(true);
        Value_All_Float = Value_All_Float - 0.1;
        if (Value_All_Float < 1) Value_All_Float = 1;
        GPower = Value_All_Float;
        Int_Float = 1;
        Print_New_Value_GYRO();
        Int_Float = 0;
        }
    }

    

 // Action if Done is pressed
 if (Done_GYRO_btn.justPressed()) {
         Menu_Complete_GYRO = true;
         Menu_Active = 928;
         Send_Menu_Selected_To_Mower_MEGA();
         Transmit_GYRO_Menu_Values();         
         tft.fillScreen(BLACK);
         Print_Navigation_Menu();
         delay(200);
         }
}
    


void Clear_Old_Value_GYRO() {
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

void Print_New_Value_GYRO() {        

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



void Sense_Button_Press_GYRO() {
    down = Touch_getXY();
    up4_btn.press                 (down && up4_btn.contains(pixel_x, pixel_y));
    down4_btn.press               (down && down4_btn.contains(pixel_x, pixel_y));
    GYRO_Enabled_btn.press        (down && GYRO_Enabled_btn.contains(pixel_x, pixel_y));
    Done_GYRO_btn.press           (down && Done_GYRO_btn.contains(pixel_x, pixel_y));

    if (up4_btn.justReleased())               up4_btn.drawButton();
    if (down4_btn.justReleased())             down4_btn.drawButton(); 
    if (GYRO_Enabled_btn.justReleased())      GYRO_Enabled_btn.drawButton();  
    if (Done_GYRO_btn.justReleased())         Done_GYRO_btn.drawButton();

}
