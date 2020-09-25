void Sense_Button_Press_Errors() {
    down = Touch_getXY();
    Clear_Error_btn.press                     (down && Clear_Error_btn.contains(pixel_x, pixel_y));
    if (Clear_Error_btn.justReleased())        Clear_Error_btn.drawButton();
    }


void React_to_Button_Press_Errors() {

    // Action if Time is pressed
    if (Clear_Error_btn.justPressed()) {
          tft.fillScreen(BLACK);
          Mower_Status_Value = 1;
          Menu_Active = 1;
          Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
          if (Mower_Status_Value == 1) {              // 1 = Docked
            if (Draw_Pictures == 1) bmpDraw("mower1.bmp", 150, 90);      //Draw the mower picture
            delay(100);
            Print_Main_Menu_Graphic();
            Check_For_Active_Alarms();
            }
          // send information to mower to exit error sequence
          }
    }
