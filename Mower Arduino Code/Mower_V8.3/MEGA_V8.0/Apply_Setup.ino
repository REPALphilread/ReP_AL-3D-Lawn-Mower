#ifdef DEBUG
  void Print_Mower_Status() {
    //Serial.print("Mower Stat....");
    if (Mower_Docked == 1) Serial.print(F("Docked:1|"));
    if (Mower_Parked == 1) Serial.print(F("Parked:1|"));
    if (Mower_Running == 1) Serial.print(F("Running:1|"));
    if (Manuel_Mode == 1) Serial.print(F("Manuel Mode:1|"));
    if (Mower_Parked_Low_Batt == 1) Serial.print(F("Park_Low_Batt:1|"));
    if (Mower_Error == 1) Serial.print(F("Mower Error:1|"));
    
  }
#endif

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
  int Compass_Attempt = 0;
  int Compass_Found = 0;

      if (Compass_Type == 1) {
        //HMC5883 Compass
        while ((!compass.begin()) && (Compass_Attempt <= 5)){
          #ifdef DEBUG
            Serial.println(F("No HMC or QMC5883 sensor found, check wiring!"));
          #endif
          delay(500);
          Compass_Attempt = Compass_Attempt + 1;
          }
        if (compass.isHMC()) {
          #ifdef DEBUG
            Serial.println(F("Initialize DF Robot HMC5883 Compass"));
          #endif
                  //compass.setRange(HMC5883L_RANGE_1_3GA);
                  //compass.setMeasurementMode(HMC5883L_CONTINOUS);
                  //compass.setDataRate(HMC5883L_DATARATE_15HZ);
                  //compass.setSamples(HMC5883L_SAMPLES_8);
                  //Compass_Found = 1;
          }
      
       //QMC5883 Compass
        else if (compass.isQMC()) {
          #ifdef DEBUG
            Serial.println(F("Initialising DF Robot QMC5883 Compass"));
          #endif
                  //compass.setRange(QMC5883_RANGE_2GA);
                  //compass.setMeasurementMode(QMC5883_CONTINOUS); 
                  //compass.setDataRate(QMC5883_DATARATE_50HZ);
                  //compass.setSamples(QMC5883_SAMPLES_8);
                  //Compass_Found = 1;
         }
      
    
      // Escape the loop if no compass is found but compass is activated in the settings
      if ((Compass_Attempt > 5) && (Compass_Found == 0)) {
        #ifdef DEBUG
          Serial.println("No Valid Compass Found");
        #endif
        Compass_Activate = 0;
        #ifdef DEBUG
          Serial.println("Compass Deactivated");
        #endif
        delay(3000);
      }
    }
  
  if (Compass_Type == 2) {
        #ifdef DEBUG
          Serial.println("Compass Selected GY-521");
        #endif
        Wire.begin();
        Wire.beginTransmission(MPU_addr);
        Wire.write(0x6B);
        Wire.write(0);
        Wire.endTransmission(true);  
  }

  if (Compass_Activate == 0) {
      #ifdef DEBUG
        Serial.println(F("Compass Switched off - Select 1 in setup to switch on.")); 
      #endif
      }
 }
}


void Setup_Relays() {
  #ifdef DEBUG
    Serial.println(F("Setup Relays"));
  #endif
  pinMode(Relay_Motors, OUTPUT);
  delay(5);
  Turn_Off_Relay();
  delay(5);
  }

void Setup_Motor_Pins() {
  #ifdef DEBUG
    Serial.println(F("Setup Motor Pins"));
  #endif  
  pinMode(L_EN, OUTPUT);
  pinMode(R_EN, OUTPUT);
  pinMode(RPWM, OUTPUT);
  }


void  Turn_On_Relay() {
  #ifdef DEBUG
   Serial.print(F("Relay:ON|"));
  #endif
   digitalWrite(Relay_Motors, LOW);                         // Turn of the relay for the main battery power
   }

void  Turn_Off_Relay() {
  #ifdef DEBUG
    Serial.print(F("Relay:Off|"));
  #endif
  digitalWrite(Relay_Motors, HIGH);                         // Turn of the relay for the main battery power
  }

void Setup_Bumper_Bar() {
  pinMode(Bumper_Switch_Frnt_RH, INPUT_PULLUP); 
  pinMode(Bumper_Switch_Frnt_LH, INPUT_PULLUP); 
}

void Setup_ADCMan() {
  #ifdef DEBUG
    Serial.println(F("ADCMAN"));
  #endif
  ADCMan.init();
  perimeter.setPins(pinPerimeterLeft, pinPerimeterRight);
  perimeter.useDifferentialPerimeterSignal = true;
  perimeter.speedTest();
  ADCMan.run();
}

    
  
