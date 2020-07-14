void Print_Mower_Status() {
  //Serial.print("Mower Stat....");
  if (Mower_Docked == 1) Serial.print(F("Docked:1|"));
  if (Mower_Parked == 1) Serial.print(F("Parked:1|"));
  if (Mower_Running == 1) Serial.print(F("Running:1|"));
  if (Manuel_Mode == 1) Serial.print(F("Manuel Mode:1|"));
  if (Mower_Parked_Low_Batt == 1) Serial.print(F("Park_Low_Batt:1|"));
  if (Mower_Error == 1) Serial.print(F("Mower Error:1|"));
  
}


void Setup_Tilt_Tip_Safety() {
  if (Angle_Sensor_Enabled == 1)     pinMode(Tilt_Angle, INPUT);//define Data input pin input pin
  if (Tip_Over_Sensor_Enabled == 1)  pinMode(Tilt_Orientation, INPUT);//define Data input pin input
  }

void Prepare_Mower_from_Settings() {

  if (Use_Charging_Station == 1) {
     Mower_Docked  = 1;
     Mower_Parked  = 0;
     Mower_Running = 0;
     }


if (Use_Charging_Station == 0) {
    Mower_Docked  = 0;
    Mower_Parked  = 1;
    Mower_Running = 0;
    }
 }


void Setup_Compass() {
 
  if (Compass_Activate == 1) {

    
  /*Setup Compass
  *************************************************************************/
  lcd.clear();
  lcd.print(F("Compass  "));
  lcd.setCursor(0, 1);
  lcd.print(F("Setup"));

  int Compass_Attempt = 0;
  int Compass_Found = 0;

      if (Compass_Type == 1) {
        //HMC5883 Compass
        while ((!compass.begin()) && (Compass_Attempt <= 5)){
          Serial.println(F("No HMC or QMC5883 sensor found, check wiring!"));
          delay(500);
          Compass_Attempt = Compass_Attempt + 1;
          }
        if (compass.isHMC()) {
          Serial.println(F("Initialize DF Robot HMC5883 Compass"));
          Compass_Detected = 1;                        // HMC5883
          if (LCD_Screen_Keypad_Menu == 1) {
            lcd.setCursor(6,0);
            lcd.print(F(": HMC5883"));
            delay(500);
            }

                  //compass.setRange(HMC5883L_RANGE_1_3GA);
                  //compass.setMeasurementMode(HMC5883L_CONTINOUS);
                  //compass.setDataRate(HMC5883L_DATARATE_15HZ);
                  //compass.setSamples(HMC5883L_SAMPLES_8);
                  //Compass_Found = 1;
          }
      
       //QMC5883 Compass
        else if (compass.isQMC()) {
          Serial.println(F("Initialising DF Robot QMC5883 Compass"));
          Compass_Detected = 2;                        // HMC5883
          if (LCD_Screen_Keypad_Menu == 1) {
            lcd.setCursor(6,0);
            lcd.print(F(": QMC5883"));
            delay(500);
            }
                  //compass.setRange(QMC5883_RANGE_2GA);
                  //compass.setMeasurementMode(QMC5883_CONTINOUS); 
                  //compass.setDataRate(QMC5883_DATARATE_50HZ);
                  //compass.setSamples(QMC5883_SAMPLES_8);
                  //Compass_Found = 1;
         }
      
    
      // Escape the loop if no compass is found but compass is activated in the settings
      if ((Compass_Attempt > 5) && (Compass_Found == 0)) {
        Serial.println("No Valid Compass Found");
        Compass_Activate = 0;
        Serial.println("Compass Deactivated");
        delay(3000);
      }
      if (LCD_Screen_Keypad_Menu == 1) {
            lcd.setCursor(0,1); 
            lcd.print(F("Done!             "));
            delay(500);
            lcd.clear();
            }
    }
  
  if (Compass_Type == 2) {
        Serial.println("Compass Selected GY-521");
        Wire.begin();
        Wire.beginTransmission(MPU_addr);
        Wire.write(0x6B);
        Wire.write(0);
        Wire.endTransmission(true);  
  }

  if (Compass_Activate == 0) {
      Serial.println(F("Compass Switched off - Select 1 in setup to switch on.")); 
      }
 }
}


void Setup_Relays() {
  Serial.println(F("Setup Relays"));
  pinMode(Relay_Motors, OUTPUT);
  delay(5);
  Turn_Off_Relay();
  delay(5);
  }

void Setup_Motor_Pins() {
  Serial.println(F("Setup Motor Pins"));
  pinMode(L_EN, OUTPUT);
  pinMode(R_EN, OUTPUT);
  pinMode(RPWM, OUTPUT);
  }


void  Turn_On_Relay() {
   Serial.print(F("Relay:ON|"));
   if (PCB == 0) digitalWrite(Relay_Motors, LOW);                         // Turn of the relay for the main battery power
   if (PCB == 1) digitalWrite(Relay_Motors, HIGH); 
   }

void  Turn_Off_Relay() {
   Serial.print(F("Relay:Off|"));
   if (PCB == 0) (digitalWrite(Relay_Motors, HIGH));                         // Turn of the relay for the main battery power
   if (PCB == 1) (digitalWrite(Relay_Motors, LOW));    
   }

void Setup_Membrane_Buttons() {
  Serial.println(F("Setup Membrane Keys"));
  pinMode(Start_Key, INPUT_PULLUP);            // set pin as input
  pinMode(Plus_Key, INPUT_PULLUP);            // set pin as input
  pinMode(Minus_Key, INPUT_PULLUP);            // set pin as input
  pinMode(Stop_Key, INPUT_PULLUP);            // set pin as input  
  }


void Setup_Bumper_Bar() {
  pinMode(Bumper_Switch_Frnt_RH, INPUT_PULLUP); 
  pinMode(Bumper_Switch_Frnt_LH, INPUT_PULLUP); 
}

void Setup_ADCMan() {
  Serial.println(F("Setting up ADCMAN"));

  if (Perimeter_Wire_Enabled == 1) {
      // Wire Sensor
      Serial.println(F("Setting up Wire Sensor"));
      ADCMan.init();
      ADCMan.setCapture(pinPerimeterLeft, 1, 0);
      perimeter.setPins(pinPerimeterLeft, pinPerimeterRight);
      perimeter.useDifferentialPerimeterSignal = true; 
      perimeter.speedTest(); 
      }

  if (GPS_Enabled == 1) {
      // GPS Fence Sensor 
      Serial.println(F("Setting up GPS Fence Sensor"));
      pinMode(GPS_Fence_Signal_Pin, INPUT);
      pinMode(GPS_Lock_Pin, INPUT);
      ADCMan.init();
      ADCMan.setCapture(GPS_Fence_Signal_Pin, 1, 1);
      ADCMan.setCapture(GPS_Lock_Pin, 1, 1);
      }

  ADCMan.run();
}


void Setup_Check_Pattern_Mow() {
  if (Pattern_Mow == 1) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Pattern Mow");
    lcd.setCursor(0,1);
    lcd.print("Parallel");
    delay(1000);
    lcd.clear();
    }
  if (Pattern_Mow == 2) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Pattern");
    lcd.setCursor(0,1);
    lcd.print("Spirals");
    delay(1000);
    lcd.clear();
    }
}
    
  
