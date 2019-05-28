void Setup_Compass() {
  if (Compass_Mode == 1) {
  /*Setup Compass
  *************************************************************************/
  lcd.clear();
  lcd.print("Calibrateing  ");
  lcd.setCursor(0, 1);
  lcd.print("Compass");
  while (!compass.begin())
  {
    Serial.println("Could not find a valid QMC5883 sensor, check wiring!");
    delay(500);
  }

  if (compass.isHMC()) {
    Serial.println("Initialize HMC5883");
    compass.setRange(HMC5883L_RANGE_1_3GA);
    compass.setMeasurementMode(HMC5883L_CONTINOUS);
    compass.setDataRate(HMC5883L_DATARATE_15HZ);
    compass.setSamples(HMC5883L_SAMPLES_8);
  }
  else if (compass.isQMC()) {
    Serial.println("Initialize QMC5883");
    compass.setRange(QMC5883_RANGE_2GA);
    compass.setMeasurementMode(QMC5883_CONTINOUS);
    compass.setDataRate(QMC5883_DATARATE_50HZ);
    compass.setSamples(QMC5883_SAMPLES_8);
  }
  lcd.clear();
  lcd.print("Compass Setup ");
  lcd.setCursor(0, 1);
  lcd.print("Done!             ");
  delay(1000);
  lcd.clear();
}

if (Compass_Mode == 0) {
  Serial.println("Compass Switched off - Select 1 in setup to switch on."); 
  }
}


void Setup_Relays() {
  pinMode(Relay_Motors, OUTPUT);
  delay(5);
  digitalWrite(Relay_Motors, HIGH);
  delay(5);
}


void Setup_Perimeter_Wire() {

  /* Perimeter Wire Setup - Perimeter Wire should ideally be switched off for this to calibrate the sensors
     to the zero level background noise.
   ***********************************************************************************************/

  Motion_StopMotors();
  //Wire.begin();           //**homework
  pinMode(pinLED, OUTPUT);
  digitalWrite(Relay_Motors, HIGH);
  Serial.println("Main Power Off for Calibration");
  delay(1500);
  lcd.clear();
  lcd.print("Calibrateing  ");
  lcd.setCursor(0, 1);
  lcd.print("Perimeter Wire");

  /*Calibrates the Wire detectors according to the local noise level.*/
  ADCMan.init();
  perimeter.setPins(pinPerimeterLeft, pinPerimeterRight);
  perimeter.useDifferentialPerimeterSignal = true;
  perimeter.speedTest();


  /*Setup capture of Voltage sensor.*/
  ADCMan.setCapture(pinVoltSensor, 1, 0);                                 // A3 for Volt Sensor  **needed??**
  
  /*Prints message to the LCD display*/
  lcd.clear();
  lcd.print("Wire Calibration ");
  lcd.setCursor(0, 1);
  lcd.print("Done!             ");
  delay(2000);
  lcd.clear();
  digitalWrite(Relay_Motors, LOW);                                       // Restores main motor power by activating the relay.
  delay(1500);
  Serial.println("Main Power Restored - Motors Ready");
  }



/*Docking Station Functions*/
void Power_Down_Mower() {
  Serial.println("Mower All Off");
  Motion_StopMotors();
  delay(20);
  StopSpinBlades();
  delay(20);
  Test_Docking_Procedure = 0;     // Stops the re-starting of the test cycle.
  Docked_Button_Pressed = 1;
  Alarm_3_ON = 0;                               // Turns off the Test Alarm
  Create_Alarms();
  ObjectRegistered = 0;
  digitalWrite(Relay_Motors, HIGH);            // Turn of the relay for the main battery power
  Serial.println("Main Power Off....");
  Serial.println("Mower is in the Docking Station");
  lcd.clear();
  lcd.print("Power Off");
  Mower_Docked              = 1;                          // Starts mower in parked position waiting for alarm 0 = normal
  MowerMotionStatus         = 1;
  MowerMotionStatus         = 2;                          // Sets the motion control 2 = Slow speed first loop
  ObjectRegistered          = 0;                          // Sets the sonar object registered count to 0. If 2 objects are consecutiveley detected by Sonar the mower will turn.
  Battery_NoBattery_Found   = 0;                          // Sets the low battery monitor to 0. if 10 instances are detected then the low battery is a low battery.
  delay(5000);
  lcd.clear();
  delay(200);
  }



void Setup_Run_LCD_Intro () {
  /* LCD INTRO SCREEN:
    Displays the project name and clears the screen.
    Useful to keep up with what version is currently loaded on the Mower */
  lcd.begin(16, 2);
  //lcd.begin(20, 4);
  lcd.clear();
  lcd.print("ReP_AL Robot");
  delay(1200);
  lcd.clear();
}


