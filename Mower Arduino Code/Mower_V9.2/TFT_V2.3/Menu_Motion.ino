void Print_Motion_Menu() {  

     // Framework for the buttons - setting the start position of the Quick start button wil automatically then space the other buttons
    tft.fillScreen(BLACK);
    int Start_X = 90;
    int Start_Y = 80;
    int Menu_Btn_Space = 60;          // Space between the adjacent buttons
    int Button_W = 150;                // width of the button
    int Button_H = 60;                // height of the button

    int Menu_Spacing = 20;            // Distance between the Menu Items (bottom of the last button to the label of the next item)
    int Txt_Size_Main_Menu = 2;
    int Column_Spacing = 100; 

    // Main Menu Title
    tft.setTextSize(Txt_Size_Main_Menu); 
    tft.setTextColor(GREEN, BLACK);      //Text Colour/ Background Colour
    tft.setCursor(10, 10);            // Text Coordinates X, Y
    tft.print(F("Motor / Motion Settings Menu"));  
    
    
    //Wheel Motors
    //------------------------------------------------------------
    
   
    int Button_X = Start_X;
    int Button_Y = Start_Y;
   
    OPTION1_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, BLUE, YELLOW, BLACK, "Wheel >", 2);
    OPTION1_BTN.drawButton(false);
    
    // Blade Motor
    
    Button_X = Start_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    OPTION2_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, RED, WHITE, BLACK, "Blade >", 2);
    OPTION2_BTN.drawButton(false);

    //Pattern
    
    Button_X = Start_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    OPTION3_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, MAGENTA, WHITE, "Pattern >", 2);
    OPTION3_BTN.drawButton(false);
   
    
    //Turns
    
    Button_X = Start_X + (Button_W + Column_Spacing) ;
    Button_Y = Start_Y;    
    
    OPTION4_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, RED, BLUE, WHITE, "Turns >", 2);
    OPTION4_BTN.drawButton(false);


    //Block
    
    Button_X = Start_X + (Button_W + Column_Spacing) ;
    Button_Y = Start_Y + (Button_H + Menu_Spacing); ;    
    
    OPTION5_BTN.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "Amp Wheel>", 2);
    OPTION5_BTN.drawButton(false);



// Save Button

    SAVE_BTN.initButton(&tft, 425, 278, 80, 40, WHITE, CYAN, BLACK, "Done", 2);
    SAVE_BTN.drawButton(false);


}






void React_to_Button_Press_Motion() {


//If the Button 1 is pressed (up or down)
 if (OPTION1_BTN.justPressed() ) {
          Menu_Complete_Wheels = false;
          tft.fillScreen(BLACK);
          Print_Wheel_Motors_Menu();
           
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Wheels == false) {
            Sense_Button_Press_Wheel_Motor();
            React_to_Button_Press_Wheel_Motor();

            }
   }
        

 if (OPTION2_BTN.justPressed() ) {
          Menu_Complete_Blade = false;
          tft.fillScreen(BLACK);
          Print_Blade_Motor_Menu();
           
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Blade == false) {
            Sense_Button_Press_Blade_Motor();
            React_to_Button_Press_Blade_Motor();

            }
        }


 if (OPTION3_BTN.justPressed() ) {
          Menu_Complete_Pattern = false;
          tft.fillScreen(BLACK);
          Print_Pattern_Menu();
           
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Pattern == false) {
            Sense_Button_Press_Pattern();
            React_to_Button_Press_Pattern();
            }
        }


 if (OPTION4_BTN.justPressed() ) {
          Menu_Complete_Movement = false;
          tft.fillScreen(BLACK);
          Print_Movement_Menu();
           
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Movement == false) {
            Sense_Button_Press_Movement();
            React_to_Button_Press_Movement();
           }
     }


 if (OPTION5_BTN.justPressed() ) {
          Menu_Complete_Wheel_Amp_Block = false;
          tft.fillScreen(BLACK);
          Print_Wheel_Amp_Block_Menu();
           
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Wheel_Amp_Block == false) {
            Sense_Button_Wheel_Amp_Block();
            React_to_Button_Wheel_Amp_Block();
           }
     }
     


 // Action if Save is pressed
 if (SAVE_BTN.justPressed()) {
         Menu_Complete_Motion = true;
         tft.fillScreen(BLACK);
         delay(200);
         Print_Settings_Menu();
         }  

        
}



void Clear_Old_Value_Motion() {
        // Draws over the previous Value in Black text to clear it.... !?
        tft.setTextSize(Txt_Size_Value); 
        tft.setTextColor(BLACK, BLACK);      //Text Colour/ Background Colour
        tft.setCursor(Value_X_All, Value_Y_All);            // Text Coordinates X, Y
        tft.print(Value_All);
        }

void Print_New_Value_Motion() {        

        tft.setTextSize(Txt_Size_Value); 
        tft.setTextColor(RED, BLACK);      //Text Colour/ Background Colour
        tft.setCursor(Value_X_All, Value_Y_All);            // Text Coordinates X, Y
        tft.print(Value_All);
        Serial.println(Value_All);
        }




void Sense_Button_Press_Motion() {
    down = Touch_getXY();
    OPTION1_BTN.press    (down && OPTION1_BTN.contains(pixel_x, pixel_y));
    OPTION2_BTN.press     (down && OPTION2_BTN.contains(pixel_x, pixel_y));
    OPTION3_BTN.press   (down && OPTION3_BTN.contains(pixel_x, pixel_y));   // Pattern
    OPTION4_BTN.press  (down && OPTION4_BTN.contains(pixel_x, pixel_y));
    OPTION5_BTN.press  (down && OPTION5_BTN.contains(pixel_x, pixel_y));
    SAVE_BTN.press      (down && SAVE_BTN.contains(pixel_x, pixel_y));

    if (OPTION1_BTN.justReleased())    OPTION1_BTN.drawButton();
    if (OPTION2_BTN.justReleased())     OPTION2_BTN.drawButton();  
    if (OPTION3_BTN.justReleased())   OPTION3_BTN.drawButton();
    if (OPTION4_BTN.justReleased())  OPTION4_BTN.drawButton();
    if (OPTION5_BTN.justReleased())  OPTION5_BTN.drawButton();
    if (SAVE_BTN.justReleased())   SAVE_BTN.drawButton();
    }
