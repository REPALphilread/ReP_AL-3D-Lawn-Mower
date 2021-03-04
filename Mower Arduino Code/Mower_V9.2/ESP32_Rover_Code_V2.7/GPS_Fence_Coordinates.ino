// GPS Coordinates of the Fence. Please use the "Create fence" option in the software menu.
// Google maps can be used to get the coordinates, but these are less accurate.

// 1st coordinate should be taken on the left hand of the screen. If the point is an outside boundary, set the boundar condition to 1
// To understand the difference between an outside and an inside boundary see repalmakershop.com
// If more GPS coordinates are required add a new line with the next [number] in the series.
// If less coordinates are required delete the additonal lines not required.  Do NOT have empty array values with no coordinates.
// Remember to modify the GPSMAX[ ] and GPS_Array[ ] values above to fit the new amount of coordinates.


void Load_GPS_Fence_Data() {

if (Fence == 1) {

      GPSMAX  = 28;                       // GPSMAX is the last value in the array  e.g. GPSY[20] GPSMAX = 20
      
      Serial.println(F("Arduino Based ReP_AL GPS Fence Test Platform"));
      Serial.print(F("GPS Points Selected = 0 to "));
      Serial.println(GPSMAX);
      
      // Location of the points just for information to the user.
      Serial.println(F("Location : ReP_AL Garden Bad Krozingen"));
      delay(1000);
      
      GPSY[0]  = 47.92372110;   GPSX[0]  = 7.68654540;   Boundary[0]  = 1;
      GPSY[1]  = 47.92375795;   GPSX[1]  = 7.68648773;   Boundary[1]  = 1;
      GPSY[2]  = 47.92376155;   GPSX[2]  = 7.68649444;   Boundary[2]  = 1;
      GPSY[3]  = 47.92376155;   GPSX[3]  = 7.68650785;   Boundary[3]  = 2;
      GPSY[4]  = 47.92374627;   GPSX[4]  = 7.68654003;   Boundary[4]  = 2;
      GPSY[5]  = 47.92375885;   GPSX[5]  = 7.68655881;   Boundary[5]  = 2;
      GPSY[6]  = 47.92375525;   GPSX[6]  = 7.68658295;   Boundary[6]  = 2;
      GPSY[7]  = 47.92376424;   GPSX[7]  = 7.68662050;   Boundary[7]  = 1;
      GPSY[8]  = 47.92378042;   GPSX[8]  = 7.68664732;   Boundary[8]  = 1;
      GPSY[9]  = 47.92378761;   GPSX[9]  = 7.68666878;   Boundary[9]  = 2;
      GPSY[10] = 47.92378222;   GPSX[10] = 7.68668219;   Boundary[10] = 2;
      GPSY[11] = 47.92378042;   GPSX[11] = 7.68670365;   Boundary[11] = 2;
      GPSY[12] = 47.92378222;   GPSX[12] = 7.68671974;   Boundary[12] = 2;
      GPSY[13] = 47.92379300;   GPSX[13] = 7.68673315;   Boundary[13] = 2;
      GPSY[14] = 47.92380558;   GPSX[14] = 7.68673852;   Boundary[14] = 2;
      GPSY[15] = 47.92381996;   GPSX[15] = 7.68672511;   Boundary[15] = 1;
      GPSY[16] = 47.92387388;   GPSX[16] = 7.68680557;   Boundary[16] = 1;
      GPSY[17] = 47.92385052;   GPSX[17] = 7.68684312;   Boundary[17] = 1;
      GPSY[18] = 47.92383973;   GPSX[18] = 7.68682971;   Boundary[18] = 1;
      GPSY[19] = 47.92383075;   GPSX[19] = 7.68682166;   Boundary[19] = 1;
      GPSY[20] = 47.92381097;   GPSX[20] = 7.68682971;   Boundary[20] = 1;
      GPSY[21] = 47.92375705;   GPSX[21] = 7.68673047;   Boundary[21] = 2;
      GPSY[22] = 47.92376244;   GPSX[22] = 7.68671169;   Boundary[22] = 2;
      GPSY[23] = 47.92375525;   GPSX[23] = 7.68669024;   Boundary[23] = 2;
      GPSY[24] = 47.92375166;   GPSX[24] = 7.68665269;   Boundary[24] = 2;
      GPSY[25] = 47.92375166;   GPSX[25] = 7.68663123;   Boundary[25] = 2;
      GPSY[26] = 47.92374627;   GPSX[26] = 7.68660441;   Boundary[26] = 2;
      GPSY[27] = 47.92374088;   GPSX[27] = 7.68659099;   Boundary[27] = 1;
      GPSY[28] = 47.92373548;   GPSX[28] = 7.68658027;   Boundary[28] = 1;
      
      // Starting coordinates of the mower in Simulation Mode.
      if (Simulation_Mode == 1){  Y_GPS = 47.92381700;    X_GPS = 7.68676300;  }
            


      }


if (Fence == 2) {

      GPSMAX  = 85;                       // GPSMAX is the last value in the array  e.g. GPSY[20] GPSMAX = 20
      
      Serial.println(F("Arduino Based ReP_AL GPS Fence Test Platform"));
      Serial.print(F("GPS Points Selected = 0 to "));
      Serial.println(GPSMAX);
      Serial.println("Location : Ross Bridge Golf Course Birmingham AL");
      
      GPSY[0]  = 33.387944;   GPSX[0]  = -86.876217;  Boundary[0]   = 1;  
      GPSY[1]  = 33.388006;   GPSX[1]  = -86.876302;  Boundary[1]   = 1;
      GPSY[2]  = 33.388057;   GPSX[2]  = -86.876352;  Boundary[2]   = 1;
      GPSY[3]  = 33.388128;   GPSX[3]  = -86.876389;  Boundary[3]   = 1;
      GPSY[4]  = 33.388171;   GPSX[4]  = -86.876391;  Boundary[4]   = 1;
      GPSY[5]  = 33.388239;   GPSX[5]  = -86.876365;  Boundary[5]   = 2;
      GPSY[6]  = 33.388304;   GPSX[6]  = -86.876353;  Boundary[6]   = 1;
      GPSY[7]  = 33.388376;   GPSX[7]  = -86.876364;  Boundary[7]   = 1;
      GPSY[8]  = 33.388448;   GPSX[8]  = -86.876393;  Boundary[8]   = 1;
      GPSY[9]  = 33.388551;   GPSX[9]  = -86.876455;  Boundary[9]   = 2;
      GPSY[10] = 33.388629;   GPSX[10] = -86.876495;  Boundary[10]  = 2;
      GPSY[11] = 33.388685;   GPSX[11] = -86.876510;  Boundary[11]  = 2;
      GPSY[12] = 33.388725;   GPSX[12] = -86.876509;  Boundary[12]  = 2;
      GPSY[13] = 33.388790;   GPSX[13] = -86.876483;  Boundary[13]  = 1;
      GPSY[14] = 33.388850;   GPSX[14] = -86.876455;  Boundary[14]  = 1;
      GPSY[15] = 33.388906;   GPSX[15] = -86.876441;  Boundary[15]  = 1;
      GPSY[16] = 33.388965;   GPSX[16] = -86.876451;  Boundary[16]  = 1;
      GPSY[17] = 33.389017;   GPSX[17] = -86.876476;  Boundary[17]  = 1;
      GPSY[18] = 33.389049;   GPSX[18] = -86.876493;  Boundary[18]  = 1;
      GPSY[19] = 33.389072;   GPSX[19] = -86.876536;  Boundary[19]  = 1;
      GPSY[20] = 33.389096;   GPSX[20] = -86.876617;  Boundary[20]  = 1;
      GPSY[21] = 33.389114;   GPSX[21] = -86.876662;  Boundary[21]  = 2;
      GPSY[22] = 33.389155;   GPSX[22] = -86.876695;  Boundary[22]  = 2;
      GPSY[23] = 33.389285;   GPSX[23] = -86.876828;  Boundary[23]  = 2;
      GPSY[24] = 33.389349;   GPSX[24] = -86.876883;  Boundary[24]  = 1;
      GPSY[25] = 33.389398;   GPSX[25] = -86.876912;  Boundary[25]  = 1;
      GPSY[26] = 33.389461;   GPSX[26] = -86.876927;  Boundary[26]  = 1;
      GPSY[27] = 33.389507;   GPSX[27] = -86.876930;  Boundary[27]  = 1;
      GPSY[28] = 33.389580;   GPSX[28] = -86.876907;  Boundary[28]  = 1;
      GPSY[29] = 33.389641;   GPSX[29] = -86.876887;  Boundary[29]  = 1;
      GPSY[30] = 33.389719;   GPSX[30] = -86.876888;  Boundary[30]  = 1;
      GPSY[31] = 33.389790;   GPSX[31] = -86.876870;  Boundary[31]  = 1;
      GPSY[32] = 33.389833;   GPSX[32] = -86.876848;  Boundary[32]  = 1;
      GPSY[33] = 33.389860;   GPSX[33] = -86.876818;  Boundary[33]  = 1;
      GPSY[34] = 33.389882;   GPSX[34] = -86.876778;  Boundary[34]  = 1;
      GPSY[35] = 33.389889;   GPSX[35] = -86.876743;  Boundary[35]  = 1;
      GPSY[36] = 33.389876;   GPSX[36] = -86.876698;  Boundary[36]  = 1;
      GPSY[37] = 33.389854;   GPSX[37] = -86.876656;  Boundary[37]  = 1;
      GPSY[38] = 33.389810;   GPSX[38] = -86.876613;  Boundary[38]  = 1;
      GPSY[39] = 33.389768;   GPSX[39] = -86.876582;  Boundary[39]  = 1;
      GPSY[40] = 33.389753;   GPSX[40] = -86.876579;  Boundary[40]  = 1;
      GPSY[41] = 33.389703;   GPSX[41] = -86.876585;  Boundary[41]  = 1;
      GPSY[42] = 33.389634;   GPSX[42] = -86.876620;  Boundary[42]  = 1;
      GPSY[43] = 33.389586;   GPSX[43] = -86.876643;  Boundary[43]  = 1;
      GPSY[44] = 33.389538;   GPSX[44] = -86.876650;  Boundary[44]  = 1;
      GPSY[45] = 33.389491;   GPSX[45] = -86.876649;  Boundary[45]  = 1;
      GPSY[46] = 33.389437;   GPSX[46] = -86.876628;  Boundary[46]  = 1;
      GPSY[47] = 33.389392;   GPSX[47] = -86.876605;  Boundary[47]  = 1;
      GPSY[48] = 33.389328;   GPSX[48] = -86.876548;  Boundary[48]  = 1;
      GPSY[49] = 33.389249;   GPSX[49] = -86.876466;  Boundary[49]  = 1;
      GPSY[50] = 33.389184;   GPSX[50] = -86.876383;  Boundary[50]  = 1;
      GPSY[51] = 33.389099;   GPSX[51] = -86.876278;  Boundary[51]  = 1;
      GPSY[52] = 33.389061;   GPSX[52] = -86.876235;  Boundary[52]  = 1;
      GPSY[53] = 33.389033;   GPSX[53] = -86.876209;  Boundary[53]  = 1;
      GPSY[54] = 33.389003;   GPSX[54] = -86.876189;  Boundary[54]  = 1;
      GPSY[55] = 33.388971;   GPSX[55] = -86.876174;  Boundary[55]  = 1;
      GPSY[56] = 33.388931;   GPSX[56] = -86.876168;  Boundary[56]  = 1;
      GPSY[57] = 33.388885;   GPSX[57] = -86.876173;  Boundary[57]  = 1;
      GPSY[58] = 33.388872;   GPSX[58] = -86.876174;  Boundary[58]  = 1;
      GPSY[59] = 33.388825;   GPSX[59] = -86.876156;  Boundary[59]  = 1;
      GPSY[60] = 33.388768;   GPSX[60] = -86.876122;  Boundary[60]  = 1;
      GPSY[61] = 33.388729;   GPSX[61] = -86.876094;  Boundary[61]  = 1;
      GPSY[62] = 33.388695;   GPSX[62] = -86.876056;  Boundary[62]  = 1;
      GPSY[63] = 33.388673;   GPSX[63] = -86.876017;  Boundary[63]  = 1;
      GPSY[64] = 33.388650;   GPSX[64] = -86.875911;  Boundary[64]  = 1;
      GPSY[65] = 33.388635;   GPSX[65] = -86.875865;  Boundary[65]  = 1;
      GPSY[66] = 33.388612;   GPSX[66] = -86.875822;  Boundary[66]  = 1;
      GPSY[67] = 33.388583;   GPSX[67] = -86.875791;  Boundary[67]  = 1;
      GPSY[68] = 33.388538;   GPSX[68] = -86.875766;  Boundary[68]  = 1;
      GPSY[69] = 33.388496;   GPSX[69] = -86.875750;  Boundary[69]  = 1;
      GPSY[70] = 33.388468;   GPSX[70] = -86.875748;  Boundary[70]  = 1;
      GPSY[71] = 33.388434;   GPSX[71] = -86.875756;  Boundary[71]  = 1;
      GPSY[72] = 33.388389;   GPSX[72] = -86.875792;  Boundary[72]  = 1;
      GPSY[73] = 33.388329;   GPSX[73] = -86.875857;  Boundary[73]  = 1;
      GPSY[74] = 33.388265;   GPSX[74] = -86.875911;  Boundary[74]  = 1;
      GPSY[75] = 33.388218;   GPSX[75] = -86.875941;  Boundary[75]  = 1;
      GPSY[76] = 33.388165;   GPSX[76] = -86.875962;  Boundary[76]  = 1;
      GPSY[77] = 33.388133;   GPSX[77] = -86.875971;  Boundary[77]  = 1;
      GPSY[78] = 33.388067;   GPSX[78] = -86.875971;  Boundary[78]  = 1;
      GPSY[79] = 33.388015;   GPSX[79] = -86.875965;  Boundary[79]  = 1;
      GPSY[80] = 33.387969;   GPSX[80] = -86.875979;  Boundary[80]  = 1;
      GPSY[81] = 33.387927;   GPSX[81] = -86.876004;  Boundary[81]  = 1;
      GPSY[82] = 33.387893;   GPSX[82] = -86.876046;  Boundary[82]  = 1;
      GPSY[83] = 33.387889;   GPSX[83] = -86.876095;  Boundary[83]  = 1;
      GPSY[84] = 33.387907;   GPSX[84] = -86.876150;  Boundary[84]  = 1;
      GPSY[85] = 33.387930;   GPSX[85] = -86.876193;  Boundary[85]  = 1;
      
      // Starting coordinates of the mower in Simulation Mode.
         if (Simulation_Mode == 1){  Y_GPS = 33.388733;  X_GPS = -86.876297; }
            
      
      }



if (Fence == 3) {

      GPSMAX  = 3;                       // GPSMAX is the last value in the array  e.g. GPSY[20] GPSMAX = 20
      
      Serial.println(F("Arduino Based ReP_AL GPS Fence Test Platform"));
      Serial.print(F("GPS Points Selected = 0 to "));
      Serial.println(GPSMAX);
      Serial.println("Location : Test Square Garden");
      GPSY[0] = 47.92377533;  GPSX[0] = 7.68663450;  Boundary [0] = 1;      //  Sattelites:12  FIX Type:3/5
      GPSY[1] = 47.92379367;  GPSX[1] = 7.68667467;  Boundary [1] = 1;      //  Sattelites:12  FIX Type:3/5
      GPSY[2] = 47.92377700;  GPSX[2] = 7.68670400;  Boundary [2] = 1;      //  Sattelites:12  FIX Type:4/5
      GPSY[3] = 47.92375800;  GPSX[3] = 7.68667200;  Boundary [3] = 1;      //  Sattelites:12  FIX Type:4/5
      
      
      // Starting coordinates of the mower in Simulation Mode.
         if (Simulation_Mode == 1) {  Y_GPS = 47.92377250; X_GPS = 7.68667633; }
            
      
      }




if (Fence == 4) {

// Location : Home Test Field 2



GPSY[0] = 47.92378250;  GPSX[0] = 7.68662491;  Boundary [0] = 1;      //  Sattelites:12  FIX Type:4/5
GPSY[1] = 47.92378619;  GPSX[1] = 7.68666927;  Boundary [1] = 1;      //  Sattelites:12  FIX Type:4/5
GPSY[2] = 47.92376823;  GPSX[2] = 7.68666938;  Boundary [2] = 1;      //  Sattelites:12  FIX Type:4/5
GPSY[3] = 47.92376323;  GPSX[3] = 7.68662071;  Boundary [3] = 1;      //  Sattelites:12  FIX Type:4/5


    GPSMAX = 3;
    // Starting coordinates of the mower in Simulation Mode.
    if (Simulation_Mode == 1) {  Y_GPS = 47.92378255; X_GPS = 7.68662421; }
}




}





  
