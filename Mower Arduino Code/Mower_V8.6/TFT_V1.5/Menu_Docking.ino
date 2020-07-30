void Print_Menu_Docking_Screen() {
      tft.fillScreen(BLACK);
      tft.setTextSize(6); 
      tft.setTextColor(GREEN, BLACK);      //Text Colour/ Background Colour
      tft.setCursor(30, 100);            // Text Coordinates X, Y
      tft.print(F("MOW END")); 
      tft.setCursor(30, 180);            // Text Coordinates X, Y
      tft.setTextColor(MAGENTA, BLACK);      //Text Colour/ Background Colour
      tft.print(F("GOING HOME"));  
      delay(4000);
      tft.fillScreen(BLACK); 

    //bmpDraw("mower4.bmp", 150, 60);      //Draw the mower picture
      // Framework for the buttons - setting the start position of the Quick start button wil automatically then space the other buttons

    int Start_X = 80;
    int Start_Y = 130;
    int Menu_Btn_Space = 100;          // Space between the adjacent buttons
    int Button_W = 130;                // width of the button
    int Button_H = 130;                // height of the button

    int Menu_Spacing = 20;            // Distance between the Menu Items (bottom of the last button to the label of the next item)
    int Txt_Size_Main_Menu = 2;

    //STOP Button
    int Button_X = Start_X;
    int Button_Y = Start_Y;   
    Stop_btn.initButton(&tft, Button_X, Button_Y, Button_W, Button_H, WHITE, RED, WHITE, "STOP Dock", 2);
    Stop_btn.drawButton(false);

    //Draw_Mower_Diagram();

}


void Print_Docking_Stage() {
     if (Turn_To_Home == 1)  {
        tft.setTextSize(3); 
        tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour        
        tft.setCursor(180,100);
        tft.print(F("Turn to Home"));
     }
     if (Turn_To_Home == 0)  {
        tft.setTextSize(3); 
        tft.setTextColor(BLACK, BLACK);      //Text Colour/ Background Colour        
        tft.setCursor(180,100);
        tft.print(F("Turn to Home"));
     }
     
     if (Find_Wire_Track == 1) {
        tft.setTextSize(3); 
        tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour  
        tft.setCursor(180,130);
        tft.print(F("Finding Wire"));
     }
     if (Find_Wire_Track == 0)  {
        tft.setTextSize(3); 
        tft.setTextColor(BLACK, BLACK);      //Text Colour/ Background Colour        
        tft.setCursor(180,130);
        tft.print(F("Finding Wire"));
     }
     if (Go_To_Charging_Station == 1){   
        tft.setTextSize(3); 
        tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour  
        tft.setCursor(180,160);
        tft.print(F("Tracking to Dock"));
     }
     if (Go_To_Charging_Station == 0)  {
        tft.setTextSize(3); 
        tft.setTextColor(BLACK, BLACK);      //Text Colour/ Background Colour        
        tft.setCursor(180,160);
        tft.print(F("Tracking to Dock"));
     }
     if (Docking_Complete == 1){   
        tft.setTextSize(3); 
        tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour  
        tft.setCursor(180,200);
        tft.print(F("Docking Complete"));
        delay(4000);
        Mower_Status_Value = 1;    //1 = Docked   2 = Mowing   7 = Tracking to Dock
        
     }

}
      
      
