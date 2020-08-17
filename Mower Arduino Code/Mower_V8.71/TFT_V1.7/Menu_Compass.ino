
// Menu Navigation
//*********************************



void Print_Compass_Menu() {

    tft.fillScreen(BLACK);
    if (Draw_Pictures == 1)   bmpDraw("Compass.bmp", 300, 120);      //Draw the mower picture
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
    tft.print(F("Compass Settings Menu"));  
    
    
    
    //Menu Compass
    //------------------------------------------------------------

    //Compass ON OFF
    
    int Button_X = Pos_X1;
    int Button_Y = Pos_Y1;
    
    if (Compass_Activate == 1) Compass_ONOFF_btn.initButton(&tft, Pos_X1, Pos_Y1, Button_W, Button_H, WHITE, GREEN, BLACK, "Comp ON", 2);
    if (Compass_Activate == 0) Compass_ONOFF_btn.initButton(&tft, Pos_X1, Pos_Y1, Button_W, Button_H, WHITE, RED, WHITE, "Comp OFF", 2);
    
    Compass_ONOFF_btn.drawButton(false);

    //HEading Hold ONOFF
    
    Pos_X2 = Pos_X1;
    Pos_Y2 = Pos_Y1 + (Button_H + Menu_Spacing);    
    
    if (Compass_Heading_Hold_Enabled == 1) HeadHold_btn.initButton(&tft, Pos_X2, Pos_Y2, Button_W, Button_H, RED, GREEN, BLACK, "HHold ON", 2);
    if (Compass_Heading_Hold_Enabled == 0) HeadHold_btn.initButton(&tft, Pos_X2, Pos_Y2, Button_W, Button_H, WHITE, RED, WHITE, "HHold OFF", 2);
    HeadHold_btn.drawButton(false);



    //Pattern Setting
    //------------------------------------------------------------
    
    Pos_X3 = 30;
    Pos_Y3 = Pos_Y2 + (Button_H + Menu_Spacing);  

    tft.setTextSize(Txt_Size_Main_Menu); 
    tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(Pos_X3, Pos_Y3);            // Text Coordinates X, Y
    tft.print(F("Compass Setup Type"));  
    
    Pos_X4 = Pos_X1; 
    Pos_Y4 = Pos_Y3 + Offset_Btn + (0.5 * Button_H);
    
    if (Compass_Setup_Mode == 1) Comp_Mode_btn.initButton(&tft, Pos_X4, Pos_Y4, Button_W, Button_H, WHITE, RED, WHITE, "DFRobot", 2);
    if (Compass_Setup_Mode == 2) Comp_Mode_btn.initButton(&tft, Pos_X4, Pos_Y4, Button_W, Button_H, WHITE, YELLOW, BLACK, "Manuel", 2);
    if (Compass_Setup_Mode == 3) Comp_Mode_btn.initButton(&tft, Pos_X4, Pos_Y4, Button_W, Button_H, WHITE, BLUE, WHITE, "HMC5883L", 2);
    
    Comp_Mode_btn.drawButton(false);


     //Compass PID Value
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
    tft.print(F("Compass Power | P = "));  

    // Value Number
    Pos_Y5  = Pos_Y5 + Offset_Btn;           // Y Position of the item
    tft.setTextSize(2); 
    tft.setTextColor(RED, BLACK);                 //Text Colour/ Background Colour
    tft.setCursor(Pos_X5, Pos_Y5);            // Text Coordinates X, Y
    tft.print(CPower);    

    // Buttons
    Button_X = Pos_X5 + Menu_Btn_Space;
    Button_Y = Pos_Y5 + (0.2 * Button_H);
    up4_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "+", 2);
    down4_btn.initButton(&tft, (Button_X + (Button_W + Button_Spacing)), Button_Y, Button_W, Button_H, WHITE, CYAN, BLACK, "-", 2);
    up4_btn.drawButton(false);
    down4_btn.drawButton(false);





// Done_Compass Button

    Done_Compass_btn.initButton(&tft, 425, 278, 80, 40, WHITE, CYAN, BLACK, "Save", 2);
    Done_Compass_btn.drawButton(false);
  
}


void React_to_Button_Press_Compass() {

          
    // Action if Compass ONOFF is pressed
    if (Compass_ONOFF_btn.justPressed()) {
        
        bool Changed = 0;
        int Button_W = 160;
        int Button_H = 60;
        int Menu_Spacing = 20; 
        int Column_Spacing = 200; 
     
        int Button_X = Pos_X1;
        int Button_Y = Pos_Y1;  
      
        if ((Compass_Activate == 1) && (Changed == 0))  {
          Compass_Activate  = 0;
          Changed = 1;
          Compass_ONOFF_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "Comp OFF", 2);
          Compass_ONOFF_btn.drawButton(false);
          }
        
        if ((Compass_Activate  == 0) && (Changed == 0)) {
          Compass_Activate  = 1;
          Changed = 1;
          Compass_ONOFF_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, BLACK, GREEN, BLACK, "Comp ON", 2);
          Compass_ONOFF_btn.drawButton(false);
        }          

    }
            
    
          

    // Action if Compass ONOFF is pressed
    if (HeadHold_btn.justPressed()) {
        
        bool Changed = 0;
        int Button_W = 160;
        int Button_H = 60;
        int Menu_Spacing = 20; 
        int Column_Spacing = 200; 
        
        int Button_X = Pos_X2;
        int Button_Y = Pos_Y2;  
      
        if ((Compass_Heading_Hold_Enabled == 1) && (Changed == 0))  {
          Compass_Heading_Hold_Enabled  = 0;
          Changed = 1;
          HeadHold_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "HHold OFF", 2);
          HeadHold_btn.drawButton(false);
          }
        
        if ((Compass_Heading_Hold_Enabled  == 0) && (Changed == 0)) {
          Compass_Heading_Hold_Enabled  = 1;
          Changed = 1;
          HeadHold_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, BLACK, GREEN, BLACK, "HHold ON", 2);
          HeadHold_btn.drawButton(false);
        }          
    }



    
//If the Compass P is pressed (up or down)
 if ((up4_btn.justPressed() )  || (down4_btn.justPressed())) {
        
        Value_All_Float = CPower;
        Value_X_All = Pos_X5;
        Value_Y_All = Pos_Y5;
    
    // Actions if UP is pressed
    if (up4_btn.justPressed()) {
        Clear_Old_Value_Compass();       
        up4_btn.drawButton(true);
        Value_All_Float = Value_All_Float + 0.1;
        if (Value_All_Float > 5) Value_All_Float = 5;
        CPower = Value_All_Float;
        Int_Float = 1;
        Print_New_Value_Compass();
        Int_Float = 0;
        }


    // Action if down is pressed
    if (down4_btn.justPressed()) {
        Clear_Old_Value_Compass();
        down4_btn.drawButton(true);
        Value_All_Float = Value_All_Float - 0.1;
        if (Value_All_Float < 1) Value_All_Float = 1;
        CPower = Value_All_Float;
        Int_Float = 1;
        Print_New_Value_Compass();
        Int_Float = 0;
        }
    }


 // If Compass Mode Button is pressed
 if (Comp_Mode_btn.justPressed() ) {

        int Button_W = 160;                // width of the button
        int Button_H = 60;                // height of the button
        
        bool Changed = 0;

        if (( Compass_Setup_Mode == 3) && (Changed ==0 )) {
          Compass_Setup_Mode = 1;
          Changed = 1;
          Comp_Mode_btn.initButton(&tft, Pos_X4, Pos_Y4, Button_W, Button_H, WHITE, RED, WHITE, "DFRobot", 2);
          Comp_Mode_btn.drawButton(false);
        }
        if (( Compass_Setup_Mode == 1) && (Changed ==0 ))  {
          Compass_Setup_Mode = 2;
          Changed = 1;
          Comp_Mode_btn.initButton(&tft, Pos_X4, Pos_Y4, Button_W, Button_H, WHITE, YELLOW, BLACK, "Manuel", 2);
          Comp_Mode_btn.drawButton(false);
          }
        
        if (( Compass_Setup_Mode == 2) && (Changed ==0 )) {
          Compass_Setup_Mode = 3;
          Changed = 1;
          Comp_Mode_btn.initButton(&tft, Pos_X4, Pos_Y4, Button_W, Button_H, WHITE, BLUE, WHITE, "HMC5883L", 2);
          Comp_Mode_btn.drawButton(false);
        }
  delay(200);
 }

    

 // Action if Done is pressed
 if (Done_Compass_btn.justPressed()) {
         Menu_Complete_Compass = true;
         Menu_Active = 926;
         Send_Menu_Selected_To_Mower_MEGA();
         Transmit_Compass_Menu_Values();         
         tft.fillScreen(BLACK);
         Print_Navigation_Menu();
         delay(200);
         }
         
}
    


void Clear_Old_Value_Compass() {
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

void Print_New_Value_Compass() {        

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



void Sense_Button_Press_Compass() {
    down = Touch_getXY();
    Compass_ONOFF_btn.press       (down && Compass_ONOFF_btn.contains(pixel_x, pixel_y));
    HeadHold_btn.press            (down && HeadHold_btn.contains(pixel_x, pixel_y));
    PCompass_btn.press            (down && PCompass_btn.contains(pixel_x, pixel_y));
    up4_btn.press                 (down && up4_btn.contains(pixel_x, pixel_y));
    down4_btn.press               (down && down4_btn.contains(pixel_x, pixel_y));
    Comp_Mode_btn.press           (down && Comp_Mode_btn.contains(pixel_x, pixel_y));
    Done_Compass_btn.press        (down && Done_Compass_btn.contains(pixel_x, pixel_y));



    if (Compass_ONOFF_btn.justReleased())     Compass_ONOFF_btn.drawButton();
    if (HeadHold_btn.justReleased())          HeadHold_btn.drawButton();
    if (PCompass_btn.justReleased())          PCompass_btn.drawButton();
    if (up4_btn.justReleased())               up4_btn.drawButton();
    if (down4_btn.justReleased())             down4_btn.drawButton();
    if (Comp_Mode_btn.justReleased())         Comp_Mode_btn.drawButton();
    if (Done_Compass_btn.justReleased())      Done_Compass_btn.drawButton();

}
