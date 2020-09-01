
// Test sketch to sense the tip of the Mower and shut dowen the
// Mower blade.


void Read_X_Y_Values() {
  
  // Retrieve the raw values from the magnetometer (not scaled).
//  MagnetometerRaw raw = compass.ReadRawAxis();
  
  // Retrieve the scaled values from the magnetometer (scaled to the configured scale).
  //MagnetometerScaled scaled = compass.ReadScaledAxis();

  //Serial.print("Raw:\t");
  //Serial.print(raw.XAxis);
  //Serial.print("   ");   
  //Serial.print(raw.YAxis);
  //Serial.print("   ");   
  //Serial.print(raw.ZAxis);
  //Serial.print("   \tScaled:\t");

  //Serial.print(scaled.XAxis);
  Serial.print("   ");   
  //Serial.print(scaled.YAxis);
  Serial.print("   ");   
  //Serial.print(scaled.ZAxis);
}



void Compass_Check_Tilt_Angle() {
     Vector mag = compass.readRaw();
     Y_Tilt = mag.YAxis + Calb_YAxis;

    if ( ( Y_Tilt > Max_Tilt) || ( Y_Tilt < Min_Tilt) )  {
      Tilt_Y = Tilt_Y + 1;
      lcd.setCursor(6,0);
      lcd.print("!");
      }
      else {
        Tilt_Y = 0;
        lcd.setCursor(6,0);
        lcd.print(" ");
      }

    if (Tilt_Y > Max_Tilt_Hits) {
      lcd.setCursor(6,0);
      lcd.print("T");
      //Motor_Action_Stop_Spin_Blades();
      //Motor_Action_Stop_Motors();
      //Mower_Running = 0;
      //Mower_Parked = 1;
      Serial.print(F("TILT !!"));
      delay(10000);
  }
  
}



void Test_Compass_Check_Tip_Angle() {
  Vector mag = compass.readRaw();
  lcd.setCursor(15,0);
  lcd.print("*");
  delay(200);

  // Reads the angle of the compass and calculates it according to the calibration done.
  X_Tilt = mag.XAxis + Calb_XAxis;
  Y_Tilt = mag.YAxis + Calb_YAxis;
  Z_Tilt = mag.ZAxis + Calb_ZAxis;

  
  Serial.print(F("X:"));
  Serial.print(X_Tilt);
  Serial.print(F("  Y:"));
  Serial.print(Y_Tilt);
  Serial.print(F("  Z:"));
  Serial.print(Z_Tilt);
  lcd.clear();
  lcd.setCursor(0,0);

  // If Y Axis is tilted     
  if ( ( Y_Tilt > Max_Tilt) || ( Y_Tilt < Min_Tilt) )  {
    Tilt_Y = Tilt_Y + 1;
    }
  else Tilt_Y = 0;

  Serial.print(F("          Tilt X: "));
  Serial.print(Tilt_X);
  Serial.print(F(" Tilt Y: "));
  Serial.print(Tilt_Y);
  Serial.print(F("   Tilt Z: "));
  Serial.println(Tilt_Z);
  lcd.setCursor(0,1);
  lcd.print("             ");
  lcd.setCursor(0,1);
  lcd.print(Tilt_Y);
  lcd.setCursor(8,1);
  lcd.print(Y_Tilt);

  if (Tilt_Y > Max_Tilt_Hits) {
    lcd.setCursor(0,0);
    lcd.print("Tilt !!");
    Serial.print(F("TILT !!"));
  }

 if ( Tilt_Y < Max_Tilt_Hits ) {
  lcd.setCursor(0,0);
  lcd.print("Level OK");
 }
}


void Calibrate_Compass_Angle() {
 float Calb_Total_X = 0;
 float Calb_Total_Y = 0;
 float Calb_Total_Z = 0;
 int c;

 Serial.println("Calibrating compass - keep mower still");
 lcd.clear();
 lcd.print("Calibrating");
 lcd.setCursor(0,1);
 lcd.print("Compass Angle");
 for (c = 1; c <= 15; c++) {
    Vector mag = compass.readRaw();
    Calb_Total_X = (Calb_Total_X + mag.XAxis);
    Calb_Total_Y = (Calb_Total_Y + mag.YAxis);
    Calb_Total_Z = (Calb_Total_Z + mag.ZAxis);
    Serial.print(F("C:"));
    Serial.print(c);
    Serial.print(F(" X_Raw:"));
    Serial.print(mag.XAxis);
    Serial.print(F(" Y_Raw:"));
    Serial.print(mag.YAxis);
    Serial.print(F(" Z_Raw:"));
    Serial.println(mag.ZAxis);
    delay(200);
    }
    
  Calb_Total_X = Calb_Total_X / (c-1);
  Calb_Total_Y = Calb_Total_Y / (c-1);
  Calb_Total_Z = Calb_Total_Z / (c-1);

  Serial.print(F(" X_Calb:"));
  Serial.print(Calb_Total_X);
  Serial.print(F(" Y_Calb:"));
  Serial.print(Calb_Total_Y);
  Serial.print(F(" Z_Calb:"));
  Serial.println(Calb_Total_Z);

   
    Serial.println("Calibration done"); 
    lcd.clear();
    lcd.print("Done!");
    Calb_XAxis = (0 - Calb_Total_X);
    Calb_YAxis = (0 - Calb_Total_Y);
    Calb_ZAxis = (0 - Calb_Total_Z);  
    delay(500);

   Serial.println("Calibration Values");
   Serial.print(F("X_Calb:"));
   Serial.print(Calb_XAxis);
   Serial.print(F("  Y_Calb:"));
   Serial.print(Calb_YAxis);
   Serial.print(F("  Z_Calb:"));
   Serial.println(Calb_ZAxis);
   lcd.clear();
   lcd.print("XYZ Calibration");
   lcd.setCursor(0,1);
   lcd.print(Calb_YAxis);

  Serial.println("Testing Calibration");
  for (int c = 0; c <= 5; c++) {
    Vector mag = compass.readRaw();
    Serial.print(F("X axis Calibrated : "));
    Serial.print(mag.XAxis + Calb_XAxis); 
    Serial.print(F("  Y axis Calibrated : "));
    Serial.print(mag.YAxis + Calb_YAxis);
    Serial.print(F("  Z axis Calibrated : "));
    Serial.println(mag.ZAxis + Calb_ZAxis);
    delay(100); 
    }
lcd.clear();
}
