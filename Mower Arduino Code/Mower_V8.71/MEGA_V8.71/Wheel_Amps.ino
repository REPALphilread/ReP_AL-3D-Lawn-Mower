void Calculate_Wheel_Amps() {
  // Calculate Amp Value from Wheel Amp sensor
 int mVperAmp = 185;
 int ACSoffset = 2500; 
 double VoltageAmp = 0;
 double Amps = 0;
 VoltageAmp = (RawWheelAmp / 1024.0) * 5000; // Gets you mV
 WheelAmps =  ((VoltageAmp - ACSoffset) / mVperAmp);
 }


void Check_Wheel_Amps() {
  Calculate_Wheel_Amps();
  if (Wheel_Amp_Sensor_ON == 1) {
        if (WheelAmps >= Max_Wheel_Amps) {
        Serial.println("");
        Serial.println("!! Wheel_Blocked !!");
        Serial.print(F("|")); 
        Wheel_Blocked = 4;
        }
        else 
        Wheel_Blocked = 0;
   
  }
}



void Test_Check_Wheel_Amps() {

        if (WheelAmps > Max_Wheel_Amps) {
        Serial.println("");
        Serial.println("!! Wheel_Blocked !!");
        Serial.print(F("|")); 
        Wheel_Blocked = 4;
        }
        else 
        Wheel_Blocked = 0;
}
