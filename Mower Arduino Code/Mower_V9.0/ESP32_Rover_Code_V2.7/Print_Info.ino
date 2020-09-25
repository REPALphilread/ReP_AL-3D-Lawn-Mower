void Print_Initial_Information() {

 Serial.print(F("Y_GPS = "));
 Serial.print(Y_GPS, 8);
 Serial.print(F("  X_GPS = "));
 Serial.println(X_GPS, 8);
 Serial.println(F(" "));

  //GPS Data Line 1
  Serial.print(F("  g  "));
  Serial.print(F(" |  Y Coord    "));
  Serial.print(F(" |  X  Coord "));
  Serial.print(F(" | Delta X   "));
  Serial.print(F(" | Delta Y   "));
  Serial.print(F(" | DeltaY/d "));
  Serial.print(F(" |  Ym - Yg   "));
  Serial.print(F(" |(Xg+1-Xg)/d"));
  Serial.print(F(" |   Yg+1-Yg  "));
  Serial.print(F(" |   n      "));
  Serial.print(F(" | X Projected"));
  Serial.print(F(" | Y Limited "));
  Serial.print(F(" | X Limited "));
  Serial.print(F("| IN/OUT "));
  Serial.print(F("| Line Type"));
  Serial.println(F("| Boundary"));
  Serial.println(F("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "));

  for (int i = 0; i <=GPSMAX; i++) {
  
    print_g       = i;
    print_GPSY    = GPSY[i];
    print_GPSX    = GPSX[i];
    print_deltaX  = deltaX[i];
    print_deltaY  = deltaY[i];
    print_deltaYd = deltaY_d[i];
    print_YMYG    = YMYG[i];
    print_XG      = XG[i];
    print_YG      = YG[i];
    print_n       = n[i];
    print_XP      = XP[i];
    print_YL      = YL[i];
    print_XL      = XL[i];
    print_IN_OUT  = IN_OUT[i];
    print_Line_Type = GPS_Equation[i];
    print_boundary = Boundary[i];
  
    Print_GPS_Information();    
  }
  Serial.println(" ");
  Serial.print("Mower In/Out = ");
  Serial.println(Mower_In_Out);
}


  void Print_GPS_Information() {
   
  //GPS X Info
  Serial.print(F("  "));
  if (print_g < 10) Serial.print(F(" "));
  Serial.print(print_g);
  Serial.print(F("  |  "));
  Serial.print(print_GPSY, 8);
  Serial.print(F(" | "));
  Serial.print(print_GPSX, 8);
  Serial.print(F(" |"));
  if (print_deltaX >= 0 ) Serial.print(F(" "));
  Serial.print(print_deltaX, 8);
  Serial.print(F(" |"));
  if (print_deltaY >= 0 ) Serial.print(F(" "));
  Serial.print(print_deltaY, 8);
  Serial.print(F(" | "));
  if (print_deltaYd >= 0 ) Serial.print(F(" "));
  if ((print_deltaYd < 10)    && (print_deltaYd >-10))     Serial.print(F(" "));   
  if ((print_deltaYd < 100)   && (print_deltaYd > -100))   Serial.print(F(" ")); 
  if ((print_deltaYd < 1000)  && (print_deltaYd > -1000))  Serial.print(F(" "));
  if ((print_deltaYd < 10000) && (print_deltaYd > -10000)) Serial.print(F(" "));
  Serial.print(print_deltaYd);
  Serial.print(F(" |"));
  if (print_YMYG >= 0 ) Serial.print(F(" "));
  Serial.print(print_YMYG,8);
  Serial.print(F(" |   "));
  if (print_XG >= 0 ) Serial.print(F(" "));
  if ((print_XG < 10)    && (print_XG >-10))     Serial.print(F(" "));   
  if ((print_XG < 100)   && (print_XG > -100))   Serial.print(F(" ")); 
  if ((print_XG < 1000)  && (print_XG > -1000))  Serial.print(F(" "));
  if ((print_XG < 10000) && (print_XG > -10000)) Serial.print(F(" "));
  Serial.print(print_XG);
  Serial.print(F("| "));
  if (print_YG >= 0 ) Serial.print(F(" "));
  Serial.print(print_YG, 8);
  Serial.print(F(" | "));
  if (print_n >= 0 )                         Serial.print(F(" "));
  if ((print_n < 10)   && (print_n >-10))    Serial.print(F(" "));   
  if ((print_n < 100)  && (print_n > -100))  Serial.print(F(" ")); 
  if ((print_n < 1000) && (print_n > -1000)) Serial.print(F(" ")); 
  Serial.print(print_n, 0);
  Serial.print(F(" | "));
  if (print_XP >= 0 ) Serial.print(F(" "));
  Serial.print(print_XP,7);
  Serial.print(F(" | "));
  if (print_YL >= 0 ) Serial.print(F(" "));
  Serial.print(print_YL,7);
  if (print_YL == 0 ) Serial.print(F(" "));
  Serial.print(F(" | "));
  if (print_XL >= 0 ) Serial.print(F(" "));
  Serial.print(print_XL,7);
  Serial.print(F(" |    "));
  Serial.print(print_IN_OUT);
  Serial.print(F("   |  "));
  Serial.print(print_Line_Type);
  Serial.print(F("   |  "));
  Serial.print(print_boundary);
  Serial.println(F(" "));
  }


void Print_Running_Loop_Data() {
    Serial.print("Fence Active:");
    Serial.print(Fence);
    Serial.print(" | Y:");
    Serial.print(Y_GPS,8);
    Serial.print(" X:");
    Serial.print(X_GPS,8);
    Serial.print(" | Sats:");
    Serial.print(gps.satellites.value());
    Serial.print(" | GPS FIX:");
    FIXED = strtoul( FIX.value(), NULL, 10 );   // changes the CHAR Value to an Int value
    if (FIXED == 0) Serial.print("0/5 None");
    if (FIXED == 1) Serial.print("1/5 2D/3D");
    if (FIXED == 2) Serial.print("2/5 DGNSS");
    if (FIXED == 4) Serial.print("3/5 FIXED RTK");
    if (FIXED == 5) Serial.print("4/5 FLOAT RTK");
    if (FIXED == 6) Serial.print("5/5 DEAD REK");
    Serial.print(" ");

    if (Print_GPS_Fix_cm == true) {
      
    Serial.print(" | Y Err: ");
    Serial.print(Y_GPS_Accuracy, 8);
    Serial.print(" X Err: ");
    Serial.print(X_GPS_Accuracy, 8);

      // Y Details
      //Serial.print(F("| Y Fix = "));
      //Serial.print(Y_Rng_cm);
      //Serial.print(" cm ");
      //Print_Y_Range_Array(); 
      //Serial.print(" Y Max =");
      //Serial.print(Y_GPS_Range_Max,8);
      //Serial.print(" Y Min =");
      //Serial.print(Y_GPS_Range_Min,8);
      //Serial.print(F(" | "));

      // X Details
      //Serial.print(F("| X Fix = "));
      //Serial.print(X_Rng_cm);
      
      //Serial.print(" cm ");
      //Print_X_Range_Array(); 
      //Serial.print(" X Max =");
      //Serial.print(X_GPS_Range_Max,8);
      //Serial.print(" X Min =");
      //Serial.print(X_GPS_Range_Min,8);
      //Serial.print(F(" | "));
    }

    if (Print_Summary_Fence == true) {
      for (int i = 0; i <= GPSMAX; i++) {
         Serial.print("g");
         Serial.print(i);
         Serial.print("=");
         Serial.print(IN_OUT[i] );
         Serial.print(" ");
         }
     }
    
    Serial.print("| Mower In(1)/Out(0) : ");
    if (Mower_In_Out == 1) Serial.print("IN FENCE");
    if (Mower_In_Out == 0) Serial.print("OUTSIDE FENCE");
    
    
  }

void Print_No_Lock_Data() {
    Serial.print("Fence Active:");
    Serial.print(Fence);
    Serial.print(" | Y GPS:");
    Serial.print(Y_GPS,8);
    Serial.print(" X_GPS:");
    Serial.print(X_GPS,8);
    Serial.print(" | Sats:");
    Serial.print(gps.satellites.value());
    Serial.print(" | GPS Time: ");
    printDateTime(gps.date, gps.time);
    Serial.print(" | GPS FIX:");
    FIXED = strtoul( FIX.value(), NULL, 10 );   // changes the CHAR Value to an Int value
    if (FIXED == 0) Serial.print("None");
    if (FIXED == 1) Serial.print("2D/3D");
    if (FIXED == 2) Serial.print("DGNSS");
    if (FIXED == 4) Serial.print("FIXED RTK");
    if (FIXED == 5) Serial.print("FLOAT RTK");
    if (FIXED == 6) Serial.print("DEAD REK");
  }

void Display_Waiting_Info() {
      Serial.print("No GPS Lock | Satelites : ");
    printInt(gps.satellites.value(), gps.satellites.isValid(), 5);
    printFloat(gps.hdop.hdop(), gps.hdop.isValid(), 6, 1);
    printFloat(gps.location.lat(), gps.location.isValid(), 11, 6);
    printFloat(gps.location.lng(), gps.location.isValid(), 12, 6);
    printInt(gps.location.age(), gps.location.isValid(), 5);
    printDateTime(gps.date, gps.time);
    printFloat(gps.altitude.meters(), gps.altitude.isValid(), 7, 2);
    printFloat(gps.course.deg(), gps.course.isValid(), 7, 2);
    printFloat(gps.speed.kmph(), gps.speed.isValid(), 6, 2);
    printStr(gps.course.isValid() ? TinyGPSPlus::cardinal(gps.course.deg()) : "*** ", 6);
}


void Print_X_Y_Max_Min() {

     Serial.print(F("Min Y GPS Point = "));
     Serial.print(Min_Y_GPS_Point, 8);
     Serial.print(F("   Max Y GPS Point = "));
     Serial.println(Max_Y_GPS_Point, 8); 
     Serial.print(F("Min X GPS Point = "));
     Serial.print(Min_X_GPS_Point, 8);
     Serial.print(F("   Max X GPS Point = "));
     Serial.print(Max_X_GPS_Point, 8);  
     Serial.println(F(" ")); 

     
}
