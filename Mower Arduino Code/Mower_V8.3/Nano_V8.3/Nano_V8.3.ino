#include <SoftwareSerial.h>
//#define DEBUG    //uncomment to activate
//#define TEST     //uncomment to activate

SoftwareSerial Nano(10, 11);  // RX, TX

//Amp Sensor Variables.
int RawValueAmp= 0;
int RawValueVolt = 0;
int Raining = 0;

void setup(){ 
  #ifdef DEBUG
    Serial.begin(9600);
    Serial.println();
    Serial.println("debug mode on");
  #endif
  Nano.begin(1200);

  pinMode(A3, INPUT);

  #ifdef TEST
    RawValueAmp = 510;
    RawValueVolt = 500;
  #endif
}

void loop(){

  //Read Amp and Volt Raw Number Sensor Values 

  #ifdef TEST
    RawValueAmp = RawValueAmp + 1;
    if (RawValueAmp > 550) RawValueAmp = 500;
    RawValueVolt = RawValueVolt + 1;
    if (RawValueVolt > 550) RawValueVolt = 500;
  #else
    RawValueAmp = analogRead(A1);
    RawValueVolt = analogRead(A2);
    Raining = analogRead(A3);
  #endif
  
  #ifdef DEBUG
    Serial.print("VoltsTX Raw = ");
    Serial.print(RawValueVolt);
    Serial.print("|");
    Serial.print("AmpsTX Raw = ");
    Serial.print (RawValueAmp);
    Serial.print("|");
    Serial.print("Rain Sensor Raw = ");
    Serial.print (Raining);
    Serial.print("|");
  #endif

  if (Raining < 100) Raining = 0;
  else Raining = 1;

  #ifdef DEBUG
    Serial.print( "Raining = ");
    Serial.print(Raining);
    Serial.print("|");
    Serial.println();
  #endif
 
  Nano.print(RawValueAmp);       // TX Raw Value Charge
  Nano.println("\q");
  delay(5); 
  Nano.print(RawValueVolt);      // TX Raw Value Volts
  Nano.println("\j"); 
  delay(5); 
  Nano.print(Raining);           // TX Raining
  Nano.println("\w");
  
} 