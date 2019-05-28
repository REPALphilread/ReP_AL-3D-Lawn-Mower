#include <SoftwareSerial.h>


SoftwareSerial mySerial(10, 11);  // RX, TX

//Pin11 Nano to Pin RX1 MEGA (19)
//Pin10 Nano to Pin TX1 MEGA (18)

//Amp Sensor Variables.
int RawValueAmp= 0;
int RawValueVolt = 0;


// Transmission of the raw sensor values to the Arduino MEGA
char str[4];
int AmpsTX = 150; 
int VoltsTX = 140;


void setup(){ 
 Serial.begin(9600);
 mySerial.begin(9600);
}

void loop(){

 //Read Amp and Volt Raw Number Sensor Values 
 // False Amp and Volt Readings sent from the Nanao
 //AmpsTX = analogRead(A1);
 //VoltsTX = analogRead(A2);

 AmpsTX = AmpsTX + 1;
 VoltsTX = VoltsTX + 1;

// Transmit Values of AmpsTX and VoltsTX 
 if (mySerial.read() == '*')
  { 
    mySerial.write(highByte(AmpsTX));
    mySerial.write(lowByte(AmpsTX));
  }
    delay(20);
    
 if (mySerial.read() == '~')
  { 
    mySerial.write(highByte(VoltsTX));
    mySerial.write(lowByte(VoltsTX));
  }
    delay(20);

Serial.print("AmpsTX = ");
Serial.print(AmpsTX);
Serial.print(" / ");
Serial.print("VoltsTX = ");
Serial.println(VoltsTX);

if (AmpsTX > 250) (AmpsTX = 150);
if (VoltsTX > 250) (VoltsTX = 150);
    
} 
