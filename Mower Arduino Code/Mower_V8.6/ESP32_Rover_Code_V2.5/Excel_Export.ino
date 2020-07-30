void Print_Excel_Sheet() {

    for (int i = 0; i <=GPSMAX; i++) {
  
    print_g       = i;
    print_GPSY    = GPSY[i];
    print_GPSX    = GPSX[i];
    //print_deltaX  = deltaX[i];
    //print_deltaY  = deltaY[i];
    //print_deltaYd = deltaY_d[i];
    //print_YMYG    = YMYG[i];
    //print_XG      = XG[i];
    //print_YG      = YG[i];
    //print_n       = n[i];
    //print_XP      = XP[i];
    //print_XL      = XL[i];
    //print_IN_OUT  = IN_OUT[i];
    //print_Line_Type = GPS_Equation[i];
  
    Print_Excel_Information();    
  }
}


void Print_Excel_Information() {
   
  //GPS Excel Output

  Serial.print(print_g);
  Serial.print(F(" "));
  Serial.print(print_GPSY, 6);
  Serial.print(F(" "));
  Serial.print(print_GPSX, 6);
  Serial.print(F(" "));  
  Serial.print(print_deltaX, 6);
  Serial.print(F(" "));
  Serial.print(print_deltaY, 6);
  Serial.print(F(" "));
  Serial.print(print_deltaYd);
  Serial.print(F(" "));
  Serial.print(print_YMYG,6);
  Serial.print(F(" "));
  Serial.print(print_XG);
  Serial.print(F(" "));
  Serial.print(print_YG, 6);
  Serial.print(F(" "));
  Serial.print(print_n, 0);
  Serial.print(F(" "));
  Serial.print(print_XP,7);
  Serial.print(F(" "));
  Serial.print(print_XL,7);
  Serial.print(F(" "));
  Serial.print(print_IN_OUT);
  Serial.print(F(" "));
  Serial.println(print_Line_Type);
  }
