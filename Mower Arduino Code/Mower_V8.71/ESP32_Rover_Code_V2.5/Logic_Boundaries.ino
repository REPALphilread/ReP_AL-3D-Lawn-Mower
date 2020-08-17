void Calculate_Y_Limited() {


for (int i = 0; i <= (GPSMAX-1); i++) {

   if ( (GPS_Equation[i] == 1) ||  (GPS_Equation[i] == 4)) {
    YL[i] = Y_GPS;
    if (Y_GPS < GPSY[i])   YL[i] = GPSY[i];
    if (Y_GPS > GPSY[i+1]) YL[i] = GPSY[i+1];
    }

   if ( (GPS_Equation[i] == 2) ||  (GPS_Equation[i] == 3)) {
    YL[i] = Y_GPS;
    if (Y_GPS > GPSY[i])   YL[i] = GPSY[i];
    if (Y_GPS < GPSY[i+1]) YL[i] = GPSY[i+1];
    
    }
  }

  if ( (GPS_Equation[GPSMAX] == 1) ||  (GPS_Equation[GPSMAX] == 4)) {
    YL[GPSMAX] = Y_GPS;
    if (Y_GPS < GPSY[GPSMAX])   YL[GPSMAX] = GPSY[GPSMAX];
    if (Y_GPS > GPSY[0]) YL[GPSMAX] = GPSY[0];
    }

  if ( (GPS_Equation[GPSMAX] == 2) ||  (GPS_Equation[GPSMAX] == 3)) {
    YL[GPSMAX] = Y_GPS;
    if (Y_GPS > GPSY[GPSMAX])   YL[GPSMAX] = GPSY[GPSMAX];
    if (Y_GPS < GPSY[0]) YL[GPSMAX] = GPSY[0];
    }
}



void Calculate_X_Limited() {

// Logic Boundary 0 --> 1

for (int i = 0; i <= (GPSMAX-1); i++) {

  if ( (GPS_Equation[i] == 1) || (GPS_Equation[i] == 2)) {
  
    XL[i] = XP[i];
    if (XP[i] < GPSX[i])   XL[i] = GPSX[i];
    if (XP[i] > GPSX[i+1]) XL[i] = GPSX[i+1];
    }

  if ( (GPS_Equation[i] == 3) || (GPS_Equation[i] == 4)) {
    XL[i] = XP[i];
    if (XP[i] > GPSX[i])   XL[i] = GPSX[i];
    if (XP[i] < GPSX[i+1]) XL[i] = GPSX[i+1];
    }
  }
  
   // If the last array point has been reached then we need to calculate based on the [0] array point and not [i+1] point

if ( (GPS_Equation[GPSMAX] == 1) || (GPS_Equation[GPSMAX] == 2)) {
    XL[GPSMAX] = XP[GPSMAX];
    if (XP[GPSMAX] < GPSX[GPSMAX]) XL[GPSMAX] = GPSX[GPSMAX];
    if (XP[GPSMAX] > GPSX[0]) XL[GPSMAX] = GPSX[0];
    }

if ( (GPS_Equation[GPSMAX] == 3) || (GPS_Equation[GPSMAX] == 4)) {
    XL[GPSMAX] = XP[GPSMAX];
    if (XP[GPSMAX] > GPSX[GPSMAX]) XL[GPSMAX] = GPSX[GPSMAX];
    if (XP[GPSMAX] < GPSX[0]) XL[GPSMAX] = GPSX[0];
    }
    
  }



void Calculate_IN_OUT() {

  for (int i = 0; i <=(GPSMAX-1); i++) {
     XL_Q    = XL[i];
     GPS_QX0 = GPSX[i];
     GPS_QX1 = GPSX[i+1];
     GPS_QY0 = GPSY[i];
     GPS_QY1 = GPSY[i+1];
     Boundary_Q = Boundary[i];

  
  if (GPS_Equation[i] == 1)  {
     Calculate_Logic_1_IN_OUT();
     IN_OUT[i] = IN_OUT_Q;
     }
  if (GPS_Equation[i] == 2){
     Calculate_Logic_2_IN_OUT();
     IN_OUT[i] = IN_OUT_Q;
     }
  if (GPS_Equation[i] == 3){
     Calculate_Logic_3_IN_OUT();
     IN_OUT[i] = IN_OUT_Q;
     }
  if (GPS_Equation[i] == 4){
     Calculate_Logic_4_IN_OUT();
     IN_OUT[i] = IN_OUT_Q;
     }
  if (GPS_Equation[i] == 5){
     Calculate_Logic_5_IN_OUT();
     IN_OUT[i] = IN_OUT_Q;
     }
  if (GPS_Equation[i] == 6){
     Calculate_Logic_6_IN_OUT();
     IN_OUT[i] = IN_OUT_Q;
     }
  if (GPS_Equation[i] == 7){
     Calculate_Logic_7_IN_OUT();
     IN_OUT[i] = IN_OUT_Q;
     }
  if (GPS_Equation[i] == 8){
     Calculate_Logic_8_IN_OUT();
     IN_OUT[i] = IN_OUT_Q;
     }


  }
  
  // Logic Boundary GPSMAX --> origin
     XL_Q    = XL[GPSMAX];
     GPS_QX0 = GPSX[GPSMAX];
     GPS_QX1 = GPSX[0];
     GPS_QY0 = GPSY[GPSMAX];
     GPS_QY1 = GPSY[0];
     Boundary_Q = Boundary[GPSMAX];
  
  if (GPS_Equation[GPSMAX] == 1)  {
     Calculate_Logic_1_IN_OUT();
     IN_OUT[GPSMAX] = IN_OUT_Q;
     }
  if (GPS_Equation[GPSMAX] == 2){
     Calculate_Logic_2_IN_OUT();
     IN_OUT[GPSMAX] = IN_OUT_Q;
     }
  if (GPS_Equation[GPSMAX] == 3){
     Calculate_Logic_3_IN_OUT();
     IN_OUT[GPSMAX] = IN_OUT_Q;
     }
  if (GPS_Equation[GPSMAX] == 4){
     Calculate_Logic_4_IN_OUT();
     IN_OUT[GPSMAX] = IN_OUT_Q;
     }
  if (GPS_Equation[GPSMAX] == 5){
     Calculate_Logic_5_IN_OUT();
     IN_OUT[GPSMAX] = IN_OUT_Q;
     }
  if (GPS_Equation[GPSMAX] == 6){
     Calculate_Logic_6_IN_OUT();
     IN_OUT[GPSMAX] = IN_OUT_Q;
     }
  if (GPS_Equation[GPSMAX] == 7){
     Calculate_Logic_7_IN_OUT();
     IN_OUT[GPSMAX] = IN_OUT_Q;
     }
  if (GPS_Equation[GPSMAX] == 8){
     Calculate_Logic_8_IN_OUT();
     IN_OUT[GPSMAX] = IN_OUT_Q;
     }




  // Caluclate Overall In/Out status
  Mower_In_Out = 0;
  for (int i = 0; i <= GPSMAX; i++) {
      Mower_In_Out = Mower_In_Out + IN_OUT[i];
      }
  
  if (Mower_In_Out <  (GPSMAX+1)) Mower_In_Out = 0;        // if one of the values is out the Mower_In_Out = 0 = OUT
  if (Mower_In_Out == (GPSMAX+1)) Mower_In_Out = 1;       // if one of the values is out the Mower_In_Out = 1 = IN

  // Checks if the Mower is basically outside the outer limits of the GEO fence.
  if (Y_GPS < GPSY_Plot[0]) Mower_In_Out = 0;
  if (Y_GPS > GPSY_Plot[GPSMAX]) Mower_In_Out = 0;

  }



void Calculate_Logic_1_IN_OUT() {
  //Diagonal BL to TR (Bottom Left to Top Right)
    
    // if the X_GPS reading is smaller than the X Logic Reading the Mower is Outside
    if (X_GPS < XL_Q) IN_OUT_Q = 0;
    if (X_GPS > XL_Q) IN_OUT_Q = 1;
   
    // if the X reading of the mower is outside the X boundaries of line.  The mower is IN.
    if (Boundary_Q == 2) {
      if ((X_GPS < GPS_QX0) ||  (X_GPS > GPS_QX1)) IN_OUT_Q = 1;
      }

    // Y Extension of the boundary condition Northwards.
    if (Boundary_Q == 3) {
      if ((X_GPS > GPS_QX0) &&  (X_GPS < GPS_QX1)) {
        if (Y_GPS > GPS_QY1) IN_OUT_Q = 0; 
        }
    }    
    

    // If the mower is within the Y boundaries, its classed as an external boundary gate and 
    // the the mower is to the left of the X0 line the mower is OUT
    if (Boundary_Q == 1) {
      if ((Y_GPS > GPS_QY0) &&  (Y_GPS < GPS_QY1)) {
        if (X_GPS < GPS_QX0) IN_OUT_Q = 0; 
        }
    }        
   
    // if the Y reading of the mower is outside the Y bpoundaries of line   The mower is IN.
      if ((Y_GPS < GPS_QY0) ||  (Y_GPS > GPS_QY1)) IN_OUT_Q = 1;
    
    }
    

void Calculate_Logic_2_IN_OUT() {
  // Diagonal TL to BR (Top Left to Bottom Right)
  
    // if the X_GPS reading is smaller than the X Logic Reading the Mower is Outside
    if (X_GPS > XL_Q) IN_OUT_Q = 0;
    if (X_GPS < XL_Q) IN_OUT_Q = 1;
   
    // if the X reading of the mower is outside the X Limits of line  The mower is IN.
    if ((X_GPS < GPS_QX0) ||  (X_GPS > GPS_QX1)) IN_OUT_Q = 1;

    // If the mower is within the Y boundaries, its classed as an external boundary gate and 
    // the the mower is to the right of the X+1 line the mower is OUT
    if (Boundary_Q == 1) {
      if ((Y_GPS < GPS_QY0) &&  (Y_GPS > GPS_QY1)) {
        if (X_GPS > GPS_QX1) IN_OUT_Q = 0; 
        }
    }   

    // Y Extension of the boundary condition Northwards
    if (Boundary_Q == 3) {
      if ((X_GPS > GPS_QX0) &&  (X_GPS < GPS_QX1)) {
        if (Y_GPS > GPS_QY0) IN_OUT_Q = 0; 
        }
    }    
    
    // if the Y reading of the mower is outside the Y Limits of line  The mower is IN.
       if ((Y_GPS > GPS_QY0) ||  (Y_GPS < GPS_QY1)) IN_OUT_Q = 1;
       
    }

void Calculate_Logic_3_IN_OUT() {
     // Diagonal Top Right to Bottom Left
    
    // if the X_GPS reading is smaller than the X Logic Reading the Mower is Outside
    if (X_GPS > XL_Q) IN_OUT_Q = 0;
    if (X_GPS < XL_Q) IN_OUT_Q = 1;
   
    // if the X reading of the mower is outside the X Limits of line  The mower is IN.
    if ((X_GPS > GPS_QX0) ||  (X_GPS < GPS_QX1)) IN_OUT_Q = 1;

    // If the mower is within the Y boundaries, its classed as an external boundary gate and 
    // the the mower is to the right of the X0 line the mower is OUT
    if (Boundary_Q == 1) {
      if ((Y_GPS < GPS_QY0) &&  (Y_GPS > GPS_QY1)) {
        if (X_GPS > GPS_QX0) IN_OUT_Q = 0; 
        }
    }   
    
    // if the Y reading of the mower is outside the Y Limits of line  The mower is IN.
      if ((Y_GPS > GPS_QY0) ||  (Y_GPS < GPS_QY1)) IN_OUT_Q = 1;
      
    } 

void Calculate_Logic_4_IN_OUT() {
  // Diagonal Bottom Right to Top Left
    
    // if the X_GPS reading is smaller than the X Logic Reading the Mower is Outside
    if (X_GPS < XL_Q) IN_OUT_Q = 0;
    if (X_GPS > XL_Q) IN_OUT_Q = 1;
   
    // if the X reading of the mower is outside the X Limits of line.  The mower is IN.
    if ((X_GPS < GPS_QX1) ||  (X_GPS > GPS_QX0)) IN_OUT_Q = 1;

    // If the mower is within the Y boundaries, its classed as an external boundary gate and 
    // the the mower is to the right of the X0 line the mower is OUT
    if (Boundary_Q == 1) {
      if ((Y_GPS > GPS_QY0) &&  (Y_GPS < GPS_QY1)) {
        if (X_GPS < GPS_QX1) IN_OUT_Q = 0; 
        }
    }   
    
    // if the Y reading of the mower is outside the Y Limits of line.  The mower is IN.
      if ((Y_GPS < GPS_QY0) ||  (Y_GPS > GPS_QY1)) IN_OUT_Q = 1;
      
    }

 
void Calculate_Logic_5_IN_OUT() {

    // Vertical Line Upwards

    // if the Y reading of the mower is outside the Y Limits of line.  The mower is IN.
    if ((Y_GPS > GPS_QY1) ||  (Y_GPS < GPS_QY0)) IN_OUT_Q = 1;
    
    // if the X reading of the mower is greater than the X value.  The mower is IN.
    if (X_GPS > GPS_QX0)  IN_OUT_Q = 1;

    // if the X reading is less than than the X value. The Mower is out
    if (X_GPS < GPS_QX0)  IN_OUT_Q = 0;
    
    }    


void Calculate_Logic_6_IN_OUT() {

    // Vertical Line Downwards

    // if the Y reading of the mower is outside the Y Limits of line.  The mower is IN.
    if ((Y_GPS < GPS_QY1) ||  (Y_GPS > GPS_QY0)) IN_OUT_Q = 1;
    
    // if the X reading of the mower is less than the X value.  The mower is IN.
    if (X_GPS < GPS_QX0)  IN_OUT_Q = 1;

    // if the X reading is greater than than the X value. The Mower is out
    if (X_GPS > GPS_QX0)  IN_OUT_Q = 0;
    
    } 


void Calculate_Logic_7_IN_OUT() {

    // Straight Line Left to Right

    // if the Y reading is greater than than the Y value. The Mower is out
    if (Y_GPS > GPS_QY0)  IN_OUT_Q = 0;

    // if the X reading of the mower is outside the X Limits of line.  The mower is IN.
    if ((X_GPS > GPS_QX1) ||  (X_GPS < GPS_QX0)) IN_OUT_Q = 1;
    
    // if the Y reading of the mower is less than the Y value.  The mower is IN.
    if (Y_GPS < GPS_QY0)  IN_OUT_Q = 1;


    
    } 


void Calculate_Logic_8_IN_OUT() {

    // Straight Line Right to Left

    // if the Y reading is less than than the straight line Y value. The Mower is out
    if (Y_GPS < GPS_QY0)  IN_OUT_Q = 0;


    // if the X reading of the mower is outside the X Limits of line.  The mower is IN.
    if ((X_GPS > GPS_QX0) ||  (X_GPS < GPS_QX1)) IN_OUT_Q = 1;
    
    // if the Y reading of the mower is greater than the Y value.  The mower is IN.
    if (Y_GPS > GPS_QY0)  IN_OUT_Q = 1;

    
    
    } 
