

void Calculate_Equation_Type() {

  Serial.print("GPSMAX = ");
  Serial.println(GPSMAX);

for (int i = 0; i <= GPSMAX; i++) {

if (i < GPSMAX) {
    deltaX[i] = GPSX[i+1] - GPSX[i];
    deltaY[i] = GPSY[i+1] - GPSY[i];
    }
  
  // If the last array point has been reached then we need to calculate based on the [0] array point and not [i+1] point
  if (i == GPSMAX) {
    deltaX[i] = GPSX[0] - GPSX[GPSMAX];
    deltaY[i] = GPSY[0] - GPSY[GPSMAX];
    }

  if ((deltaX[i] > 0) && (deltaY[i] > 0))  GPS_Equation[i] = 1;     // Diagonal BL to TR (Bottom Left to Top Right)
  if ((deltaX[i] > 0) && (deltaY[i] < 0))  GPS_Equation[i] = 2;     // Diagonal TL to BR
  if ((deltaX[i] < 0) && (deltaY[i] < 0))  GPS_Equation[i] = 3;     // Diagonal TR to BL
  if ((deltaX[i] < 0) && (deltaY[i] > 0))  GPS_Equation[i] = 4;     // Diagonal BR to TL
  if ((deltaX[i] == 0) && (deltaY[i] > 0)) GPS_Equation[i] = 5;     // Straight Line UP
  if ((deltaX[i] == 0) && (deltaY[i] < 0)) GPS_Equation[i] = 6;     // Straight Line Down
  
  if ((deltaX[i] > 0) && ( ( (deltaY[i] <= 0.000003) && (deltaY[i] >= -0.000003) ) ) ) GPS_Equation[i] = 7;     // More or less Straight Line Left to Right
  if ((deltaX[i] < 0) && ( ( (deltaY[i] <= 0.000003) && (deltaY[i] >= -0.000003) ) ) ) GPS_Equation[i] = 8;     // More or less Straight Line Right to Left
  }
}





void Calculate_GPS_Data() {
  
  for (int i = 0; i <= (GPSMAX); i++) {
    if (i < GPSMAX) {
      deltaY_d[i] = deltaY[i] / d;                   // Calculate (Delta Y / d )
      YMYG[i] = Y_GPS - GPSY[i];                   // Calculate (YMower - Yg)
      XG[i] = (GPSX[i+1] - GPSX[i]) / d;             // Calculate ((XG+1) - XG) / d
      YG[i] = GPSY[i+1] - GPSY[i];                   // Calculate (YG+1) -YG
      if (YG[i] != 0) n[i] = 1 + ( YMYG[i] / ( YG[i] / XG[i] ) );    // Calculate n as long as YG1 is not 0
      }
  
  // If the last array point has been reached then we need to calculate based on the [0] array point and not [i+1] point
  if (i == GPSMAX) {
      deltaY_d[i] = deltaY[i] / d;                   // Calculate (Delta Y / d )
      YMYG[i] = Y_GPS - GPSY[i];                   // Calculate (YMower - Yg)
      XG[i] = (GPSX[0] - GPSX[i]) / d;             // Calculate ((XG+1) - XG) / d
      YG[i] = GPSY[0] - GPSY[i];                   // Calculate (YG+1) -YG
      if (YG[i] != 0) n[i] = 1 + ( YMYG[i] / ( YG[i] / XG[i] ) );    // Calculate n
      }
    

    }
}



void Calculate_X_Projected () {
    for (int i = 0; i <=GPSMAX; i++) {
    XP[i] = GPSX[i] + ( d * n[i] );  
    }
}
