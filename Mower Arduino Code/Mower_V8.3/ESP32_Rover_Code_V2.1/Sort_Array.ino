void Copy_Array_For_MinMax() {
  
     for (int i = 0; i <= GPSMAX; i++)  {
        GPSY_Plot[i] = GPSY[i];
        GPSX_Plot[i] = GPSX[i];
        }

}


void Sort_Y_Array() {
      float hold_Y; 
      for (int r = 0; r <= 500; r++) {

        for (int i = 0; i <= (GPSMAX-1); i++) {
          hold_Y = GPSY_Plot[i+1];
          if (GPSY_Plot[i] > GPSY_Plot[i+1]) {
            GPSY_Plot[i+1] = GPSY_Plot[i];
            GPSY_Plot[i] = hold_Y;
            }
        if (GPSY_Plot[GPSMAX] < GPSY_Plot[GPSMAX-1]) {
          hold_Y = GPSY_Plot[GPSMAX];
          GPSY_Plot[GPSMAX] = GPSY_Plot[GPSMAX-1];
          GPSY_Plot[GPSMAX-1] = hold_Y;
          }
        }
      }

      Min_Y_GPS_Point = GPSY_Plot[0];
      Max_Y_GPS_Point = GPSY_Plot[GPSMAX];

     
   }


void Print_Y_Array()  {
  for (int i = 0; i <= GPSMAX; i++) {
    Serial.print(i);
    Serial.print("=");
    Serial.println(GPSY_Plot[i],6 );
  }
}

void Sort_X_Array() {
      float hold_X;
      for (int r = 0; r <= 1000; r++) {

        for (int i = 0; i <= (GPSMAX-1); i++) {
          hold_X = GPSX_Plot[i+1];
          if (GPSX_Plot[i] > GPSX_Plot[i+1]) {
            GPSX_Plot[i+1] = GPSX_Plot[i];
            GPSX_Plot[i]   = hold_X;
            }
        if (GPSX_Plot[GPSMAX] < GPSX_Plot[GPSMAX-1]) {
          hold_X = GPSX_Plot[GPSMAX];
          GPSX_Plot[GPSMAX] = GPSX_Plot[GPSMAX-1];
          GPSX_Plot[GPSMAX-1] = hold_X;
          }
        }
      }
      
    
      Min_X_GPS_Point = GPSX_Plot[GPSMAX];
      Max_X_GPS_Point = GPSX_Plot[0];

      //Print_X_Array();
 
}

void Print_X_Array()  {
  for (int i = 0; i <= GPSMAX; i++) {
    Serial.print(i);
    Serial.print(F("="));
    Serial.println(GPSX_Plot[i],6 );
  }
}
