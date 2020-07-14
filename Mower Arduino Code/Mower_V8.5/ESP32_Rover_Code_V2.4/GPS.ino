void Read_GPS_Data() {
  
 
  smartDelay(GPS_Delay);

  if (millis() > 5000 && gps.charsProcessed() < 10)
    Serial.print(F("No GPS Data | "));
}


// This custom version of delay() ensures that the gps object
// is being "fed".
static void smartDelay(unsigned long ms)
  {
    unsigned long start = millis();
    do 
    {
      while (Serial2.available())
        gps.encode(Serial2.read());
    } while (millis() - start < ms);  
  }

static void printFloat(float val, bool valid, int len, int prec)
{
  if (!valid)
  {
    while (len-- > 1)
      Serial.print('*');
    Serial.print(' ');
  }
  else
  {
    Serial.print(val, prec);
    int vi = abs((int)val);
    int flen = prec + (val < 0.0 ? 2 : 1); // . and -
    flen += vi >= 1000 ? 4 : vi >= 100 ? 3 : vi >= 10 ? 2 : 1;
    for (int i=flen; i<len; ++i)
      Serial.print(' ');
  }
  smartDelay(0);
}

static void printInt(unsigned long val, bool valid, int len)
{
  char sz[32] = "*****************";
  if (valid)
    sprintf(sz, "%ld", val);
  sz[len] = 0;
  for (int i=strlen(sz); i<len; ++i)
    sz[i] = ' ';
  if (len > 0) 
    sz[len-1] = ' ';
  Serial.print(sz);
  smartDelay(0);
}

static void printDateTime(TinyGPSDate &d, TinyGPSTime &t)
{
  if (!d.isValid())
  {
    Serial.print(F("********** "));
  }
  else
  {
    char sz[32];
    sprintf(sz, "%02d/%02d/%02d ", d.month(), d.day(), d.year());
    Serial.print(sz);
  }
  
  if (!t.isValid())
  {
    Serial.print(F("******** "));
  }
  else
  {
    char sz[32];
    sprintf(sz, "%02d:%02d:%02d ", t.hour(), t.minute(), t.second());
    Serial.print(sz);
  }

  printInt(d.age(), d.isValid(), 5);
  smartDelay(0);
}

static void printStr(const char *str, int len)
{
  int slen = strlen(str);
  for (int i=0; i<len; ++i)
    Serial.print(i<slen ? str[i] : ' ');
  smartDelay(0);
}


void Run_GPS_Accuracy_Display_Menu(){
    Read_GPS_Data();
    Y_GPS = gps.location.lat();    
    X_GPS = gps.location.lng();
    Sats    = gps.satellites.value();
    Calculate_GPS_Accuracy;
    Serial.print(" | Y Accuracy: ");
    Serial.print(Y_GPS_Accuracy, 8);
    Serial.print(" X Accuracy: ");
    Serial.print(X_GPS_Accuracy, 8);
    Serial.print(" | ");  
    Serial.print("Sats:");
    Serial.println(Sats);
    
}


void Calculate_GPS_Accuracy() {

    //Fills the array with 5 GPS Coordinates
    //Serial.print(" GPS_Cycles:");
    //Serial.print(GPS_Cycles);
    //Serial.print(" | ");
    Y_GPS_Range_Values[GPS_Cycles] = Y_GPS;
    X_GPS_Range_Values[GPS_Cycles] = X_GPS;

    int Points= 5;


    // Sort Y Range Values
    if (Range_Go == 1) {
      double Range_Y; 
      for (int r = 0; r <= 100; r++) {

        for (int i = 0; i <= (Points -1); i++) {
          Range_Y = Y_GPS_Range_Values[i+1];
          if (Y_GPS_Range_Values[i] > Y_GPS_Range_Values[i+1]) {
            Y_GPS_Range_Values[i+1] = Y_GPS_Range_Values[i];
            Y_GPS_Range_Values[i] = Range_Y;
            }
        if (Y_GPS_Range_Values[Points] < Y_GPS_Range_Values[Points-1]) {
          Range_Y = Y_GPS_Range_Values[Points];
          Y_GPS_Range_Values[Points] = Y_GPS_Range_Values[Points-1];
          Y_GPS_Range_Values[Points-1] = Range_Y;
          }
        }
      }
      Y_GPS_Range_Min = Y_GPS_Range_Values[1];
      Y_GPS_Range_Max = Y_GPS_Range_Values[Points-1];
      Y_GPS_Accuracy  = Y_GPS_Range_Max - Y_GPS_Range_Min;

      double Range_X; 
      for (int n = 0; n <= 100; n++) {

        for (int d = 0; d <= (Points - 1); d++) {
          Range_X = X_GPS_Range_Values[d+1];
          if (X_GPS_Range_Values[d] > X_GPS_Range_Values[d+1]) {
            X_GPS_Range_Values[d+1] = X_GPS_Range_Values[d];
            X_GPS_Range_Values[d] = Range_X;
            }
        if (X_GPS_Range_Values[Points] < X_GPS_Range_Values[Points-1]) {
          Range_X = X_GPS_Range_Values[Points];
          X_GPS_Range_Values[Points] = X_GPS_Range_Values[Points-1];
          X_GPS_Range_Values[Points-1] = Range_X;
          }
        }
      }
      X_GPS_Range_Min = X_GPS_Range_Values[1];
      X_GPS_Range_Max = X_GPS_Range_Values[Points-1];
      X_GPS_Accuracy  = X_GPS_Range_Max - X_GPS_Range_Min;
    }
  

    // Advances the GPS Cycles and gives the signal for the range to start calculating once the array is full.
    GPS_Cycles = GPS_Cycles + 1;

    // Once the 5th GPS Coordinate has been filled the first GPS coordinate is replaced and so on... and so on...
    if (GPS_Cycles > Points) {
      Range_Go = 1;
      GPS_Cycles = 0;
    }
     

  //Conversion of the decimal GPS coordinate into cm
  //0.0000001 = 1cm therefore the number x 10000000 = cm
  Y_Rng_cm = (Y_GPS_Accuracy * 10000000);        // Turns the accuracy into cm reading
  X_Rng_cm = (X_GPS_Accuracy * 10000000);        // Turns the accuracy into cm reading
    
  }
    
void Print_Y_Range_Array()  {
  Serial.println(" ");
  for (int i = 0; i <= 19; i++) {
    Serial.print("Y");
    Serial.print(i);
    Serial.print(F("="));
    Serial.println(Y_GPS_Range_Values[i],8 );
  }
}

void Print_X_Range_Array()  {
  Serial.println(" ");
  for (int s = 0; s <= 19; s++) {
    Serial.print("X");
    Serial.print(s);
    Serial.print(F("="));
    Serial.println(X_GPS_Range_Values[s],8 );
  }
} 
