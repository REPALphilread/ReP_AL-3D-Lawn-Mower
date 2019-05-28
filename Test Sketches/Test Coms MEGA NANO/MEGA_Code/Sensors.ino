/* Main Battery Voltage Test
************************************************************************************/

/* ADCMan function (needed for Perimeter Wire readings) doesnt allow direct reading of Analog pins which makes this simple operation a little complicated*/
void TestforBatteryVoltage()   {
  //ADCMan.run();
  //ADCMan.setCapture(pinVoltSensor, 1, 0);                           // A3 for Volt Sensor **test to see i the volt is now read**
  
  
  if ( ((MowerMotionStatus % 2) == 0 ) || (MowerMotionStatus == 0) ) {
    Check_Serial_Communications();          // Receive data from the Arduino Nano for Volt and Amp sensors.
    delay(50);
    Serial.println(" ");
    Serial.print("Voltage Now Reading : ");
    Serial.println(Voltnow);

   if (Voltnow <= 0) {                         // if a Zero Value is reecieved from the Serial Communication then use the previous value
      Serial.println("Battery Test skipped - Voltage Comm Fail");
      Voltnow = BatteryVoltage_Last;
      Serial.print("Using Battery_Last Value of : ");
      Serial.println(BatteryVoltage_Last);
    }
    else  {     

    // if the Volt value is not zero than use this new Voltnow value.
    BatteryVoltage = Voltnow;
    BatteryVoltage_Last = BatteryVoltage;
    Serial.print("Battery Voltage: ");
    Serial.println(BatteryVoltage);
    delay(1);;          
    
           
    lcd.setCursor(10, 0);
    lcd.print("V:");
    lcd.setCursor(12, 0);    
    lcd.print(BatteryVoltage);   
    }

//  Logic for how the battery readings should be handled

    // Checks if the battery is not connected by a voltage under 6V
    if (Voltnow < 10) {
      Battery_NoBattery_Found = (Battery_NoBattery_Found + 1);
      Serial.print("####### No Battery Found Reading ###### : ");
      Serial.println(Battery_NoBattery_Found);
      }
    
    if (Voltnow < BatteryMin) {
      Battery_To_Charge_Station_Count = (Battery_To_Charge_Station_Count + 1);
      Serial.print("####### Battery needs charging reading ######## : ");
      Serial.println(Battery_To_Charge_Station_Count);
      }

      if (Voltnow >= BatteryMin) {
      Serial.print("Battery >");
      Serial.println(BatteryMin);
      Battery_To_Charge_Station_Count = 0;
      Battery_NoBattery_Found = 0;
      }
  }

// Handles how the voltage is printed to the LCD display and what the mower does.
    if ( (BatteryVoltage > 10 ) && (BatteryVoltage <= BatteryMin) && (Battery_To_Charge_Station_Count > 10) ){
       //MowerMotionStatus = 1;
       lcd.setCursor(0, 1);
       lcd.print("Battery < :  ");
       lcd.print(BatteryMin);
       Serial.print("Battery below : ");
       Serial.println(BatteryMin);
       }
  


    // Checks if a series of low voltage signals have been detected i.e. the mower wont be sent to the charger due to just 1 bad signal
    if (Battery_To_Charge_Station_Count > 20) {
      Motion_StopMotors();
      StopSpinBlades();
      MowerMotionStatus = 1;
      Error = 7;
      Serial.print("Batt Sensor - Battery Empty < ");
      Serial.println(BatteryMin);                               //sets Mower Motion to 1 which is all stop
      lcd.setCursor(0, 1);
      lcd.print("Mower -> Charger");
      delay(5000);
      }

    if ((BatteryVoltage <= 10) && (Battery_NoBattery_Found >= 5)){
       lcd.setCursor(10, 0);
       lcd.print("V:");
       lcd.setCursor(12, 0);    
       lcd.print("OFF ");     
       }
  
   
  Serial.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}




/* Check that boundary wire is turned on
************************************************************************************/
void TestforBoundaryWire()  {
  if (millis() >= nextTime)  {
    nextTime = millis() + 50;
    if (perimeter.isInside(0) != inside) {
      inside = perimeter.isInside(0);
      counter++;
    }
  }

  if (Perimeter_Wire_Mode == 1) {                                               // Perimeter use is ON - Perimter_USE can be turned on or off in the setup.

    /*Checks to see if the boundary wire is turned OFF.
      uses the mag field calculated. Between -50 and 50 normally the field is off.     */

    MAG_Now = perimeter.getMagnitude(0);
    if ( (MAG_Now > -20 ) && (MAG_Now < 20 )  ) {
      Serial.print("Sender Turned OFF!! ");
      senderOff = 1;
      Error = 6;
      MowerMotionStatus = 1;
    }

    /* Checks to see that the boundary fence is turned ON.
      uses the mag field. under -50 or above 50 means the field is on.*/
    if (   (MAG_Now < -50 ) || (MAG_Now > 50 )  ) {
      Serial.print("Sender ON ");
      senderOff = 0;
    }

    Serial.print(" - Sender Status: ");
    Serial.print(senderOff);
    Serial.print("  = ");
    if (senderOff == 0) Serial.println("ON");
    if (senderOff == 1) Serial.println("OFF");
    Serial.print("Mag Reading = ");
    Serial.println(MAG_Now);
    Serial.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  }

  if (Perimeter_Wire_Mode == 0) {                                               // Perimeter use is OFF - Perimter_USE can be turned on or off in the setup.
    Serial.println("TEST MODE : Perimeter Wire Sensor on Mower not in use ");
    senderOff = 0;

  }
}

/* Read Boundary Wire
************************************************************************************/
void UpdateWireSensor()   {
  if (millis() >= nextTime)  {
    nextTime = millis() + 50;
    if (perimeter.isInside(0) != inside) {
      inside = perimeter.isInside(0);
      counter++;
    }
  }
}

// Serial Communications to Arduino Nano
void Check_Serial_Communications() {

int AmpsTX;
int VoltsTX;

// Receive AmpsTX from Arduino Nano

Serial1.write('*');
delay(5);
while(Serial1.available()>0) {
delay(5);
byte h = Serial1.read();
byte l = Serial1.read();
AmpsTX = word(h , l);}

delay(5);

// Receive VoltsTX from Arduino Nano
Serial1.write('~');
delay(5);
while(Serial1.available()>0) {
delay(5);                              // delay important to receive correct info
byte h2 = Serial1.read();
byte l2 = Serial1.read();
VoltsTX = word(h2 , l2);}

delay(5);

Serial.print("AmpsTX : ");
Serial.print(AmpsTX);
Serial.print(" / ");
Serial.print("VoltsTX : ");
Serial.println(VoltsTX);

// Calculate Amp Value from Charging Pins
int mVperAmp = 185;
int ACSoffset = 2500; 
double VoltageAmp = 0;
double Amps = 0;

VoltageAmp = (AmpsTX / 1024.0) * 5000; // Gets you mV
AmpsReal =  ((VoltageAmp - ACSoffset) / mVperAmp);


// Calculate Voltage Sensor Value from Battery
 
 float vout = 0.0;
 float R1 = 30000;   
 float R2 = 7500;      // 7500

 
 int RawValueVolt = VoltsTX;                      // Takes the sensor raw value to calculate the voltage
 vout = (RawValueVolt * 5.0) / 1024.0; // see text
 Voltnow = vout / (R2/(R1+R2)); 

 }



void Check_if_Charging() {
    
    if ((AmpsReal > 0.1) && (AmpsReal < 4) ) {
      lcd.setCursor(0,0);            // Spaces to the right & down
      lcd.print("++");
      lcd.print(AmpsReal);
      }
    if (AmpsReal < 0.01) {
      lcd.setCursor(0,0);            // Spaces to the right & down
      lcd.print("        ");
      }

  }
