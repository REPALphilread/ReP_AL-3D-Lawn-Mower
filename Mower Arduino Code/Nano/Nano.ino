#include <SoftwareSerial.h>


SoftwareSerial mySerial(10, 11);  // RX, TX

//Amp Sensor Variables.
int RawValueAmp= 0;
int RawValueVolt = 0;
bool Charging;


// Transmission of the raw sensor values to the Arduino MEGA
float AmpsTX; 
float VoltsTX;
bool Test;


void setup(){ 
 Serial.begin(9600);
 mySerial.begin(9600);
 Test = 0;

 if (Test == 1) {
  RawValueAmp = 510;
  RawValueVolt = 500;
 }
}

void Calculate_Volt_Amp() {


// Calculate Amp Value from Charging Pins
 int mVperAmp = 185;
 int ACSoffset = 2500; 
 double VoltageAmp = 0;
 double Amps = 0;
 VoltageAmp = (RawValueAmp / 1024.0) * 5000; // Gets you mV
 AmpsTX =  ((VoltageAmp - ACSoffset) / mVperAmp);



// Calculate Voltage Sensor Value from Battery
 
 float vout = 0.0;
 float R1 = 30000;      // 30000 Mower 2    Mower 1 30000
 float R2 = 7300;       // 7300 Mower 2     Mower 1 7500
 vout = (RawValueVolt * 5.0) / 1024.0; // see text
 VoltsTX = vout / (R2/(R1+R2)); 

}

 
void TX_Volts()  {  
  mySerial.print(VoltsTX);
  mySerial.println("\j");
  Serial.print("VoltsTX = ");
  Serial.print(VoltsTX);
}

void TX_Charge()  {
  mySerial.print(Charging);
  mySerial.println("\q");
}

void loop(){

 //Read Amp and Volt Raw Number Sensor Values 
 if (Test == 0) { 
 RawValueAmp = analogRead(A1);
 RawValueVolt = analogRead(A2);
 }

  if (Test == 1 )   {
 RawValueAmp = RawValueAmp + 1;
 if (RawValueAmp > 550) RawValueAmp = 500;
 RawValueVolt = RawValueVolt + 1;
 if (RawValueVolt > 550) RawValueVolt = 500;
  }


 Serial.print("VoltsTX Raw = ");
 Serial.print(RawValueVolt);
 Serial.print(" / ");
 Serial.print("AmpsTX Raw = ");
 Serial.print (RawValueAmp);
 Serial.print(" / ");


 Calculate_Volt_Amp();

 if (AmpsTX < 0.1) Charging = 0;
 if (AmpsTX > 0.1) Charging = 1;
 Serial.print(" / Charging = ");  
 Serial.print(Charging);
 Serial.print(" / ");

 Serial.print(" / ");
 Serial.print("AmpsTX = ");
 Serial.println (AmpsTX);
 
 
 TX_Volts();
 delay(5);
 TX_Charge();

    
} 
