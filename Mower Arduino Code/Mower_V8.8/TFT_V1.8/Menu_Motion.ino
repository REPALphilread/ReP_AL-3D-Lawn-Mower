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
   
    Wheels_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, BLUE, YELLOW, BLACK, "Wheel >", 2);
    Wheels_btn.drawButton(false);
    
    // Blade Motor
    
    Button_X = Start_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    Blade_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, RED, WHITE, BLACK, "Blade >", 2);
    Blade_btn.drawButton(false);

    //Pattern
    
    Button_X = Start_X;
    Button_Y = Button_Y + (Button_H + Menu_Spacing);    
    
    Pattern_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, MAGENTA, WHITE, "Pattern >", 2);
    Pattern_btn.drawButton(false);
   
    
    //Turns
    
    Button_X = Start_X + (Button_W + Column_Spacing) ;
    Button_Y = Start_Y;    
    
    Movement_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, RED, BLUE, WHITE, "Turns >", 2);
    Movement_btn.drawButton(false);


    //Block
    
    Button_X = Start_X + (Button_W + Column_Spacing) ;
    Button_Y = Start_Y + (Button_H + Menu_Spacing); ;    
    
    Wheel_Amp_Block_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "Amp Wheel>", 2);
    Wheel_Amp_Block_btn.drawButton(false);



// Save Button

    Save_btn.initButton(&tft, 425, 278, 80, 40, WHITE, CYAN, BLACK, "Done", 2);
    Save_btn.drawButton(false);


}






void React_to_Button_Press_Motion() {


//If the Button 1 is pressed (up or down)
 if (Wheels_btn.justPressed() ) {
          Menu_Complete_Wheels = false;
          tft.fillScreen(BLACK);
          Serial.println(F("Wheel Motor Screen Selected"));
          Menu_Active = 14;
          Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected 
          Serial.println("RX Motor Values");
          delay(Receive_Values_Delay +1000);
          Receive_Wheel_Motor_Data(); 
          Print_Wheel_Motors_Menu();
           
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Wheels == false) {
            Sense_Button_Press_Wheel_Motor();
            React_to_Button_Press_Wheel_Motor();

            }
   }
        

 if (Blade_btn.justPressed() ) {
          Menu_Complete_Blade = false;
          tft.fillScreen(BLACK);
          Serial.println(F("Blade Motor Screen Selected"));
          Menu_Active = 15;
          Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected 
          Serial.println("RX Blade Motor Values");
          delay(Receive_Values_Delay);
          Receive_Blade_Motor_Data(); 
          Print_Blade_Motor_Menu();
           
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Blade == false) {
            Sense_Button_Press_Blade_Motor();
            React_to_Button_Press_Blade_Motor();

            }
        }


 if (Pattern_btn.justPressed() ) {
          Menu_Complete_Pattern = false;
          tft.fillScreen(BLACK);
          Serial.println(F("Pattern Screen Selected"));
          Menu_Active = 25;
          Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected 
          Serial.println("RX Pattern Values");
          delay(Receive_Values_Delay + 1400);
          Receive_Pattern_Data(); 
          Print_Pattern_Menu();
           
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Pattern == false) {
            Sense_Button_Press_Pattern();
            React_to_Button_Press_Pattern();

            }
        }


 if (Movement_btn.justPressed() ) {
          Menu_Complete_Movement = false;
          tft.fillScreen(BLACK);
          Serial.println(F("Movement Screen Selected"));
          Menu_Active = 16;
          Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected 
          Serial.println("RX Movement Values");
          delay(Receive_Values_Delay + 400);
          Receive_Movement_Menu_Data(); 
          Print_Movement_Menu();
           
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Movement == false) {
            Sense_Button_Press_Movement();
            React_to_Button_Press_Movement();
           }
     }


 if (Wheel_Amp_Block_btn.justPressed() ) {
          Menu_Complete_Wheel_Amp_Block = false;
          tft.fillScreen(BLACK);
          Serial.println(F("Wheel Amp Block Selected"));
          Menu_Active = 29;
          Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected 
          Serial.println("RX Wheel Amp Block Values");
          delay(Receive_Values_Delay + 400);
          Receive_Wheel_Amp_Block_Menu_Data(); 
          Print_Wheel_Amp_Block_Menu();
           
          // Sense for the settings buttons until the saved button is pressed.
          while (Menu_Complete_Wheel_Amp_Block == false) {
            Sense_Button_Wheel_Amp_Block();
            React_to_Button_Wheel_Amp_Block();
           }
     }
     


 // Action if Save is pressed
 if (Save_btn.justPressed()) {
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
    Wheels_btn.press    (down && Wheels_btn.contains(pixel_x, pixel_y));
    Blade_btn.press     (down && Blade_btn.contains(pixel_x, pixel_y));
    Pattern_btn.press   (down && Pattern_btn.contains(pixel_x, pixel_y));
    Movement_btn.press  (down && Movement_btn.contains(pixel_x, pixel_y));
    Wheel_Amp_Block_btn.press  (down && Wheel_Amp_Block_btn.contains(pixel_x, pixel_y));
    Save_btn.press      (down && Save_btn.contains(pixel_x, pixel_y));

    if (Wheels_btn.justReleased())    Wheels_btn.drawButton();
    if (Blade_btn.justReleased())     Blade_btn.drawButton();  
    if (Pattern_btn.justReleased())   Pattern_btn.drawButton();
    if (Movement_btn.justReleased())  Movement_btn.drawButton();
    if (Wheel_Amp_Block_btn.justReleased())  Wheel_Amp_Block_btn.drawButton();
    if (Save_btn.justReleased())   Save_btn.drawButton();
    }
