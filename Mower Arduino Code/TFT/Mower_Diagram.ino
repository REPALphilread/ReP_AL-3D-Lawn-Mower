void Draw_Mower_Diagram() {

    int Mower_Pic_X = 250;
    int Mower_Pic_Y = 170;
    int Wheel_X     = Mower_Pic_X;
    int Wheel_Y     = Mower_Pic_Y + 20;
    int Mower_Width = 100;
    int Mower_Height = 60;
    int Wheel_Width  = Mower_Width / 5;

 
 tft.fillRect  (  Mower_Pic_X, Mower_Pic_Y, Mower_Width,  Mower_Height, GREEN);                        // Main Body
 tft.fillCircle(  Mower_Pic_X + (Mower_Width / 2) , Mower_Pic_Y, ((Mower_Width / 2) -1) , GREEN);      // Round Front
 tft.fillRect  (  Wheel_X, Wheel_Y , Wheel_Width,  40, GREY);                                          // Wheel LH
 tft.fillRect  (  Wheel_X + 82, Wheel_Y , (Wheel_Width - 2),  40, GREY);                               // Wheel RH  

 }

 void Draw_Sonar() {

    int Mower_Pic_X = 250;
    int Mower_Pic_Y = 170;
    int Wheel_X     = Mower_Pic_X;
    int Wheel_Y     = Mower_Pic_Y + 20;
    int Mower_Width = 100;
    int Mower_Height = 60;
    int Wheel_Width  = Mower_Width / 5;

 
 // Sonar 1
 tft.fillCircle(  (Mower_Pic_X - 6) + (Mower_Width / 2), (Mower_Pic_Y - 40), 5, BLACK); // Left Dot Outline
 tft.fillCircle(  (Mower_Pic_X + 6) + (Mower_Width / 2), (Mower_Pic_Y - 40), 5, BLACK);  // Right Dot Outline

 // Sonar 1 sensor Dots 
 if (Sonar_1_Activate != 1) {
   tft.fillCircle(  (Mower_Pic_X - 6) + (Mower_Width / 2), (Mower_Pic_Y - 40), 3, GREY);
   tft.fillCircle(  (Mower_Pic_X + 6) + (Mower_Width / 2), (Mower_Pic_Y - 40), 3, GREY);
   }
 if (Sonar_1_Activate == 1) {
   tft.fillCircle(  (Mower_Pic_X - 6) + (Mower_Width / 2), (Mower_Pic_Y - 40), 3, RED);
   tft.fillCircle(  (Mower_Pic_X + 6) + (Mower_Width / 2), (Mower_Pic_Y - 40), 3, RED);
   }


 // Sonar 2 
 tft.fillCircle(  (Mower_Pic_X - 30) + (Mower_Width / 2), (Mower_Pic_Y - 30), 5, BLACK);
 tft.fillCircle(  (Mower_Pic_X - 37) + (Mower_Width / 2), (Mower_Pic_Y - 20), 5, BLACK);

 // Sonar 2 sensor Dots 
 if (Sonar_2_Activate != 1) {
   tft.fillCircle(  (Mower_Pic_X - 30) + (Mower_Width / 2), (Mower_Pic_Y - 30), 3, GREY); 
   tft.fillCircle(  (Mower_Pic_X - 37) + (Mower_Width / 2), (Mower_Pic_Y - 20), 3, GREY);
   }
 if (Sonar_2_Activate == 1) {
   tft.fillCircle(  (Mower_Pic_X - 30) + (Mower_Width / 2), (Mower_Pic_Y - 30), 3, RED); 
   tft.fillCircle(  (Mower_Pic_X - 37) + (Mower_Width / 2), (Mower_Pic_Y - 20), 3, RED);
   }



 // Sonar 3 
 // Top Dot
 tft.fillCircle(  (Mower_Pic_X + 30) + (Mower_Width / 2), (Mower_Pic_Y - 30), 5, BLACK);
 tft.fillCircle(  (Mower_Pic_X + 37) + (Mower_Width / 2), (Mower_Pic_Y - 20), 5, BLACK);

if (Sonar_3_Activate != 1) {
   tft.fillCircle(  (Mower_Pic_X + 30) + (Mower_Width / 2), (Mower_Pic_Y - 30), 3, GREY); 
   tft.fillCircle(  (Mower_Pic_X + 37) + (Mower_Width / 2), (Mower_Pic_Y - 20), 3, GREY);
   }

if (Sonar_3_Activate == 1) {
   tft.fillCircle(  (Mower_Pic_X + 30) + (Mower_Width / 2), (Mower_Pic_Y - 30), 3, RED); 
   tft.fillCircle(  (Mower_Pic_X + 37) + (Mower_Width / 2), (Mower_Pic_Y - 20), 3, RED);
   }
}
