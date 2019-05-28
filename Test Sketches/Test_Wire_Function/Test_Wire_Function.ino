 
/************************************************************************************
     ReP_AL Mower Test wire Function
     ==========================================

     You can use a Laptop and the Serial mointor to do this check but its better with the Mower and the LCD screen
     The LCD screen needs to be working (i.e. you knpow your I2C address)
     Add this I2C address to the sketch below to activate the LCD screen

     This sketch is desgined to detect the boundary wire in your garden.
     Holding the mower in your hands (no motors on/no blades spinning!!) move around the garden and over the boundary wire.
     IN/OUT :  Displays if you are inside or outside of the wire loop
     MAG : Shows the magnitude of the wire signal   -ve is inside the loop  /   +ve outside the loop

     All OK
     ======
     You are inside the mowing area and the display shows IN & You have a -ve MAG reading in the 1000's
     You are outisde the mowing area and the LCD display shows OUT & you have a +ve MAG reading
     You are directly over the wire and you have an IN/OUT flicker and the MAG reading is low or around 0.
     

     Inside Outside Flipped
     ======================
     If you are reading IN when you hold the mower outside the loop and OUT when you are inside the loop then 
     it means your sensor and boundayr wire are working only the signal is flipped :)
     Solution: switch the boundary wires on your sender station terminals or switch the 11P ferrite sensor on the amplifier
     so the legs from the 11P ferite sensor are the other way around.

     Low MAG Readings
     ================
     The MAG reading is only in the 100's.  The adjust the amplifier screw so that the signal is strengthend and you now
     get readings in the 1000's Inside and Outside the Wire



************************************************************************************/



/* Libraries Used
************************************************************************************/

/*Libraries for Perimeter Wire Receiver*/
#include <Arduino.h>
#include <Wire.h>
#include <EEPROM.h>
#include "drivers.h"
#include "adcman.h"
#include "perimeter.h"


/*Libraries for ic2 Liquid Crystal*/
#include <LiquidCrystal_I2C.h>

//I2C Address of your LCD screem
//==============================
//LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);    //LCD on test mower stand



/* Pin setup for Arduino MEGA
************************************************************************************/

/*Perimeter Wire Pins*/
#define pinPerimeterLeft A5        // perimeter pin
#define pinPerimeterRight A4       // leave open
#define pinLED LED_BUILTIN


#define LED_PIN LED_BUILTIN

/*Relay Switches*/
#define Relay_Motors 24





/***********************************************************************************
                       Global Variables
************************************************************************************/

/*Perimeter Variables*/
Perimeter perimeter;
unsigned long nextTime = 0;
int counter = 0;
boolean inside = true;
int senderOff;                      // Value sent to detrmine if the wire is on or off before motors are activated.

/*Perimeter Wire Tracking*/
int Track_Wire_Itterations;
byte Exit_Zone;
int MAG_Now;
int MAG_OUT_Stop;
int MAG_IN_Stop;
int MAG_TURN;
int MAG_Average_Start;
int MAG_Last;
byte Outside_Wire_Count;

/* Wire Track Printer */
int PrintInMax;
int PrintInMid;
int PrintInMin;
int PrintOutMin;
int PrintOutMid;
int PrintOutMax;
int PrintMAG_Now;





/***********************************************************************************************

                   SETUP OF MOWER
                   ====================================

 ***********************************************************************************************/

 
  /* User defined parameters to switch on or off parts of the code depending on the Setup of the Mower
     Useful for testing e.g. to switch the blades off if testing indoors.
  ****************************************************************************************************/

  /*  1 = Turned ON      0 = Turned OFF       Value = Value set for variable.*/

  //Main settings for the Mower Operation

  //bool Blades_ON                     = 1;                      // Blades spinning or not set to 0 (zero) for OFF!  CAREFUL FINGERS!!
  bool Perimeter_Wire_Mode           = 1;                      // activates deactivates the perimiter wire detetcion.
  bool WIFI_On                       = 1;                      // Activates WIFI Communication
  //bool Exit_Dock_To_Garden_Procedure = 1;                      // Tracks the wire around the garden to the Mower start position away from the docking station 

  
  bool Track_Wire_CW_Charge       = 1;                          // Track perimeter wire in a Clockwise Direction to the charging station
  bool Track_Wire_CCW_Charge      = 0;                          // Track perimeter wire in a Counter Clockwise Direction to the charging station
  bool Track_Wire_Start_pos_CW    = 0;                          // Track the wire CW to the start position
  bool Track_Wire_Start_pos_CCW   = 1;                          // Track the wire CCW to the start position
  byte Outside_Wire_Count_Max     = 3;                          // Counts the number of times the mower is outside the wire consecutively.  i.e. Mower is lost

  byte Max_Number_Blockage_Registered = 40;                    // Max number of blockages registered by sonar before turn is made.
  

  /* Description of how the below values are displayed in the Serial Monitor Print Out for the wire
     function
     (InMax)                   Wire = 0                 (OutMax)
         |      (InMid)           |           (OutMid)     |
         |--------|--------|------|------|--------|--------|
         |        |        |      |      |        |        |
                        (InMin)       (OutMin)
  */

  // Wire detection Values
    /*Negative Values for In*/                            // These values are based on the signal received by the wire sensor for my perimeter loop
    int InMin = -200;
    int InMid = -700;
    int InMax = -1500;                                        // the maximum received signal value inside the wire
    /*General Setup PID numbers for wire tracking*/
    float P               = 0.17;                                 // Multiplication factor to the error measured to the wire center.  if jerky movement when tracking reduce number
    float D               = 10;                                   // Dampening value to avoid the mower snaking on the wire.  
    byte Scale            = 36;                                   // Serial Monitor Line Tracking Print Scale
    byte PWM_MaxSpeed_LH  = 240;                               // Wheel Motor Speed Max LH Wheel (Looking from back of mower)
    byte PWM_MaxSpeed_RH  = 255;                               // Wheel Motor Speed Max RH Wheel
   
    /*Positive Values for Out*/
    int OutMin = 150;
    int OutMid = 400;
    int OutMax = 1500;                                        // the maximum received signal value outside the wire
  
  
  
  /************************************************************************************************************/

void setup() {
    //Setup is placed in a function so the setup can be ran once the Mower is docked 
    //to reset the board as best as possible to the beginning.

  /* Starts the Communication to the Serial Monitor baud 115200. */
  Serial.begin(115200);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("ReP_AL Robot");
  lcd.setCursor(0,1);
  lcd.print("Wire Tester");
  delay(2000);
  lcd.clear();

  //Not sure if this is required here..........
  if (millis() >= nextTime)  {
    nextTime = millis() + 50;
    if (perimeter.isInside(0) != inside) {
      inside = perimeter.isInside(0);
      counter++;
    }
  }
  
  Setup_Wires();
  //Somehow this is required to get the voltage to read in the first dock stage **homework
  ADCMan.run();
  delay(2000);
}

// END SETUP



/************************************************************************************************
 * ************************************************************************************************
 * ************************************************************************************************
 * ************************************************************************************************
 * ************************************************************************************************


                        THE LOOP
                        ========

 **************************************************************************************************
 ************************************************************************************************
 ************************************************************************************************
 ************************************************************************************************/

void loop() {

  // Checks for the membrane switch and controls the menu function
  Check_Wire();                                                      // Check if Boundary wire is switched on and active
  ADCMan.run(); // Keep ADCMan running
  delay(5);

} //End the Loop



void Setup_Wires() {

  /* Perimeter Wire Setup - Perimeter Wire should ideally be switched off for this to calibrate the sensors
     to the zero level background noise.
   ***********************************************************************************************/

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
