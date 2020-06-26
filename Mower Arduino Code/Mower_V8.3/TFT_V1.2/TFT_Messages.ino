

void Print_Battery_Graphic() {


if (Battery_Display == 1) {
  // Global Variable = Battery                              // Battery % remaining
  int Battery_Bar_Width = 60;                               // Width of the battery bar
  int Battery_Bar_Height = 20;                              // Height of the battery bar
  int Battery_Value = ( (60*10) / 100 ) * (Battery / 10);   // Calculates the width of the bar depending on the % remaining
  int Battery_Pos_X = 360;                                  // X Coordinate of the Battery Symbol
  int Battery_Pos_Y = 10;                                   // Y Coordinate of the Battery Symbol
  int Txt_Size_Label = 2;                                   // Text size of the battery % text
  
  //Serial.print("Battery Value");
  //Serial.println(Battery_Value);

  // Create a white Box (Border) as background to the Battery
  tft.fillRect((Battery_Pos_X - 1), (Battery_Pos_Y - 1), (Battery_Bar_Width + 2), (Battery_Bar_Height + 2) , WHITE); 
  // Create a grey background
  tft.fillRect((Battery_Pos_X), (Battery_Pos_Y), (Battery_Bar_Width), (Battery_Bar_Height) , GREY); 
  
   // X_Coord,  Y_Coord, W, H, Colour
  if (Battery_Value < 10)  tft.fillRect(Battery_Pos_X, Battery_Pos_Y, Battery_Value, Battery_Bar_Height, RED);  
  if (Battery_Value >= 10)  tft.fillRect(Battery_Pos_X, Battery_Pos_Y, Battery_Value, Battery_Bar_Height, YELLOW);       
  if (Battery_Value >= 20)  tft.fillRect(Battery_Pos_X, Battery_Pos_Y, Battery_Value, Battery_Bar_Height, GREEN);  

  tft.setTextSize(Txt_Size_Label); 
  tft.setTextColor(YELLOW, BLACK);      //Text Colour/ Background Colour
  tft.setCursor( (Battery_Pos_X + Battery_Bar_Width + 5), (Battery_Pos_Y + 4) );            // Text Coordinates X, Y
  tft.print(Battery); 
  tft.print(F("% "));
}

if (Battery_Display == 2) {
       tft.setTextSize(3); 
       tft.setCursor(362,10); 
       tft.setTextColor(BLACK, BLACK);     
       tft.print(Battery_Last);
       tft.setCursor(362,10); 
       Battery = Battery;
       if (Battery < 14.00)        tft.setTextColor(GREEN, BLACK); 
       if (Battery < 12.20)        tft.setTextColor(YELLOW, BLACK); 
       if (Battery < 11.80)        tft.setTextColor(RED, BLACK); 
       tft.print(Battery);
       tft.setCursor(455,10);
       tft.print("V");
       Battery_Last = Battery;
       
      }  
   
  
  }








// Print the eecived time to the TFT Menu.
void Print_Time_TFT() {
      tft.setTextSize(3); 
      tft.setTextColor(GREEN, BLACK);      //Text Colour/ Background Colour
      tft.setCursor(385, 290);            // Text Coordinates X, Y
      tft.print(Time_Hour);
      tft.print(":");
      if (Time_Minute < 10) tft.print ("0");
      tft.println(Time_Minute);  
      }

void Run_Loop_Count() {
    Loop = Loop + 1;
    if (Loop > 59) Loop = 0;
    }

void Clear_TFT_Loop_Info_Mowing() {
    // Loops Info
    tft.setTextColor(BLACK, BLACK);      // Text Colour/ Background Colour
    tft.setTextSize(2); 
    tft.setCursor(20, 250);            // Text Coordinates X, Y
    tft.print(F("Loops: "));
    tft.setCursor(100, 250);            // Text Coordinates X, Y
    tft.print(Loops);  
    }

void Update_TFT_Loop_Info_Mowing() {

    // Loops Info
    tft.setTextColor(GREEN, BLACK);      // Text Colour/ Background Colour
    tft.setTextSize(2); 
    tft.setCursor(20, 250);            // Text Coordinates X, Y
    tft.print(F("Loops: "));
    tft.setCursor(100, 250);            // Text Coordinates X, Y
    tft.print(Loops);  

}


void Print_Confirmation_Text_ERROR() {
      
      bool Error_Found = 0;
      Menu_Complete_Mowing = true;
      Menu_Complete_Main = true;
      tft.fillScreen(BLACK);
      Print_Battery_Graphic();                      // Shows the battery value
      delay(200);
      
      // Draw Red Circle with !
      tft.fillCircle(70, 150, 70, RED);             // X, Y, Radius
      tft.fillRect(60, 105, 20, 60 , WHITE);        // X, Y, Width, Height
      tft.fillRect(60, 175, 20, 20 , WHITE);        // X, Y, Width, Height     


      if (Mower_Error_Value == 1) {
            tft.setTextSize(6); 
            tft.setTextColor(GREEN, BLACK);               //Text Colour/ Background Colour
            tft.setCursor(160, 100);                      // Text Coordinates X, Y
            tft.print(F("ERROR"));  
            tft.setTextColor(YELLOW, BLACK); 
            tft.setCursor(160, 160);              // Text Coordinates X, Y
            tft.print(F("WIRE OFF")); 
            delay(4000);
            Error_Found = 1;
            }
      if (Mower_Error_Value == 2) {
            tft.setTextSize(6); 
            tft.setTextColor(WHITE, BLACK);               //Text Colour/ Background Colour
            tft.setCursor(160, 100);                      // Text Coordinates X, Y
            tft.print(F("PARKED"));  
            tft.setTextColor(YELLOW, BLACK); 
            tft.setCursor(160, 160);              // Text Coordinates X, Y
            tft.print(F("LOW BATT")); 
            delay(4000);
            Error_Found = 1;
            }
      if (Mower_Error_Value == 3) {
            tft.setTextSize(6); 
            tft.setTextColor(WHITE, BLACK);               //Text Colour/ Background Colour
            tft.setCursor(160, 100);                      // Text Coordinates X, Y
            tft.print(F("PARKED"));  
            tft.setTextColor(YELLOW, BLACK); 
            tft.setCursor(160, 160);              // Text Coordinates X, Y
            tft.print(F("TIP OVER")); 
            delay(4000);
            Error_Found = 1;
            }
      
      if (Error_Found == 0) {
            tft.setTextSize(6); 
            tft.setTextColor(YELLOW, BLACK);               //Text Colour/ Background Colour
            tft.setCursor(160, 100);                      // Text Coordinates X, Y
            tft.print(F("ERROR"));  
            tft.setTextColor(YELLOW, BLACK); 
            tft.setCursor(160, 160);              // Text Coordinates X, Y
            tft.print(F("UNKNOWN")); 
            delay(4000);
            Error_Found = 1;
            }
      }


void Update_TFT_Mower_Messages_Mowing() {

     bool Skip_Message = 0;
     bool Show_Update = 1;

     if (Show_Update == 1) {
         tft.setTextSize(3);
         tft.setCursor(20, 280);
         tft.print("W:");
         tft.print(Wire_Status);
         tft.print("  S:");
         tft.print(Sonar_Status);
         tft.print("  B:");
         tft.print(Bumper_Status);
         tft.print("  C:");
         tft.print(Compass_Steering_Status);
         tft.print("  T:");
         tft.print(Tilt_Angle_Sensed);

     if (GPS_Enabled == 1) {
         if (GPS_In_Out_TX == 1) {
          tft.setCursor(330, 50);
          tft.setTextColor(BLACK, BLACK);
          tft.print("GPS:OUT");
          tft.setCursor(330, 50);
          tft.setTextColor(GREEN, BLACK);
          tft.print("GPS:IN");
          }
         
         if (GPS_In_Out_TX == 0) {
          tft.setCursor(330, 50);
          tft.setTextColor(GREEN, BLACK);
          tft.print("GPS:OUT");   
          }
         
         tft.setCursor(330, 80);
         tft.setTextColor(GREEN, BLACK);
         tft.print("FIX:");
         if (GPS_Lock_OK_TX == 1) tft.print("RTK");
         if (GPS_Lock_OK_TX == 0) tft.print("FIX");
         }
     }
     
     tft.setTextSize(8);
    
     
     if ((Sonar_Status == 0) && (Skip_Message == 0)) {
       tft.setCursor(180,100); 
       tft.setTextColor(BLACK, BLACK);      //Text Colour/ Background Colour  
       tft.print("SONAR");      
       }
     if ((Sonar_Status == 1)  && (Skip_Message == 0)){
       tft.setCursor(180,100); 
       tft.setTextColor(YELLOW, BLACK); 
       tft.print("SONAR");
       Skip_Message = 1;
       }
    
     if (Perimeter_Wire_Enabled == 1) {
         if ((Wire_Status == 0) && (Skip_Message == 0)) {
           tft.setCursor(180,100); 
           tft.setTextColor(BLACK, BLACK);      //Text Colour/ Background Colour 
           tft.print("WIRE");       
           }
         if ((Wire_Status == 1)  && (Skip_Message == 0)){
           tft.setCursor(180,100); 
           tft.setTextColor(YELLOW, BLACK); 
           tft.print("WIRE");
           Skip_Message = 1;
           }
        }

     if ((Bumper_Status == 0) && (Skip_Message == 0)) {
       tft.setCursor(180,100); 
       tft.setTextColor(BLACK, BLACK);     
       tft.print("BUMP");
       }
     if ((Bumper_Status == 1)  && (Skip_Message == 0)) {
       tft.setCursor(180,100); 
       tft.setTextColor(YELLOW, BLACK); 
       tft.print("BUMP");
       Skip_Message = 1;
       }

     if ((Tilt_Angle_Sensed == 1) && (Skip_Message == 0)) {
       tft.setCursor(180,100); 
       tft.setTextColor(BLACK, BLACK);     
       tft.print("TILT");
       }
     if ((Tilt_Angle_Sensed == 0)  && (Skip_Message == 0)) {
       tft.setCursor(180,100); 
       tft.setTextColor(YELLOW, BLACK); 
       tft.print("TILT");
       Skip_Message = 1;
       }

     if (GPS_Enabled == 1) {
         if ((GPS_In_Out_TX == 1)  && (Skip_Message == 0)) {
           tft.setCursor(160,100); 
           tft.setTextColor(BLACK, BLACK); 
           tft.print("GPS");
           Skip_Message = 1;
           }
         if ((GPS_In_Out_TX == 0)  && (Skip_Message == 0)) {
           tft.setCursor(160,100); 
           tft.setTextColor(YELLOW, BLACK); 
           tft.print("GPS");
           Skip_Message = 1;
           }
         if ((GPS_Lock_OK_TX == 0)  && (Skip_Message == 0)) {
           tft.setCursor(180,100); 
           tft.setTextColor(YELLOW, BLACK); 
           tft.print("FIX");
           Skip_Message = 1;
           }
         if ((GPS_Lock_OK_TX == 1)  && (Skip_Message == 0)) {
           tft.setCursor(180,100); 
           tft.setTextColor(BLACK, BLACK); 
           tft.print("FIX");
           Skip_Message = 1;
           }
     }

    int left_arrow = 180;
    int right_arrow = 380;
    int y_level = 100;
       
     if ((Compass_Steering_Status == 0)  && (Skip_Message == 0)) {
       tft.setTextColor(BLACK, BLACK);      //Text Colour/ Background Colour     
       tft.setCursor(left_arrow,y_level);   
       tft.print("<");
       tft.setCursor(right_arrow, y_level); 
       tft.print(">");
       }
     if ((Compass_Steering_Status == 1)  && (Skip_Message == 0)){
       tft.setTextColor(YELLOW, BLACK); 
       tft.setCursor(left_arrow, y_level); 
       tft.print("<");
       tft.setCursor(right_arrow, y_level); 
       tft.print(">");

       Skip_Message = 1;
       }
     if ((Compass_Steering_Status == 2)  && (Skip_Message == 0)){
       tft.setTextColor(BLACK, BLACK);      //Text Colour/ Background Colour     
       tft.setCursor(left_arrow,y_level);   
       tft.print("<");
       tft.setCursor(right_arrow, y_level); 
       tft.print(">");
       
       tft.setCursor(right_arrow, y_level); 
       tft.setTextColor(YELLOW, BLACK); 
       tft.print(">");
       Skip_Message = 1;
       }
     if ((Compass_Steering_Status == 3)  && (Skip_Message == 0)){
       tft.setTextColor(BLACK, BLACK);      //Text Colour/ Background Colour     
       tft.setCursor(left_arrow,y_level);   
       tft.print("<");
       tft.setCursor(right_arrow, y_level); 
       tft.print(">");
       
       tft.setCursor(left_arrow, y_level); 
       tft.setTextColor(YELLOW, BLACK); 
       tft.print("<");
       Skip_Message = 1;
       }

}


void Print_Error_Messages_Docked() {
  
  
  // Mower_Error 1 = No Wire Detected.
  if (Mower_Error_Value == 1) {
       // Draw Red Circle with !
       tft.fillCircle(300, 58, 16, RED);           // X, Y, Radius
       tft.fillRect(298, 45, 4, 15 , WHITE);       // X, Y, Width, Height
       tft.fillRect(298, 64, 4, 5 , WHITE);        // X, Y, Width, Height 
       
       tft.setTextSize(3); 
       tft.setCursor(330,48); 
       tft.setTextColor(YELLOW, BLACK); 
       tft.print("WIRE OFF");
       }
  
  // Erases over the Red circle and text with black versions of the same thing.
  if (Mower_Error_Value != 1) {
       tft.fillCircle(300, 58, 16, BLACK);        // X, Y, Radius
       tft.setTextSize(3); 
       tft.setCursor(330,48); 
       tft.setTextColor(BLACK, BLACK); 
       tft.print("WIRE OFF");
       }
  }

void Print_Mower_Status() {
       tft.setTextSize(2); 
       tft.setCursor(30,295); 
       tft.setTextColor(GREEN, BLACK); 
       if (Mower_Status_Value == 1) tft.print("Docked");
       if (Mower_Status_Value == 2) tft.print("Parked");

       if (Charging == 4) {
           tft.setTextSize(2); 
           tft.setCursor(100,295); 
           tft.setTextColor(GREEN, BLACK); 
           tft.print("   - Charging");
           }
       if ((Charging == 0) || (Charging != 4)) {
           tft.setTextSize(2); 
           tft.setCursor(100,295); 
           tft.setTextColor(BLACK, BLACK); 
           tft.print("   - Charging");
           }
       if (GPS_Enabled == 0) {
           tft.setTextSize(2); 
           tft.setCursor(170,50); 
           tft.setTextColor(BLACK, BLACK); 
           tft.print("GPS:");
           }    
       if (GPS_Enabled == 1) {
           tft.setTextSize(2); 
           tft.setCursor(170,50); 
           tft.setTextColor(GREEN, BLACK); 
           tft.print("GPS:");
           }          
       if (GPS_Enabled == 1) {
             if (GPS_Lock_OK_TX == 0) {
                 tft.print("    ");
                 }    
             if (GPS_Lock_OK_TX == 5) {
                 tft.print("RTK");
                 }     
             if (GPS_Lock_OK_TX == 2) {
                 tft.print("   ");
                 }  
             }
       }
       

void Calculate_TFT_Time() {

  time = millis();
  int Seconds_Passed = (time / 1000 ) - (60 * Minutes_Passed);
  if (Seconds_Passed > 59) {
    Minutes_Passed = Minutes_Passed + 1;
    Time_Minute = Time_Minute + 1;
    if (Time_Minute > 59) {
      Time_Minute = 0;
      Time_Hour = Time_Hour + 1;
      if (Time_Hour > 23) {
       Time_Hour = 0; 
       }    
    }
  }
  Serial.print(F("|Time:"));
  Serial.print(Time_Hour);
  Serial.print(F(":"));
  if (Time_Minute < 10) Serial.print("0");
  Serial.print(Time_Minute);   
  Serial.print(":");
  if (Seconds_Passed < 10) Serial.print("0");
  Serial.println(Seconds_Passed); //prints time since program started
  
  }
