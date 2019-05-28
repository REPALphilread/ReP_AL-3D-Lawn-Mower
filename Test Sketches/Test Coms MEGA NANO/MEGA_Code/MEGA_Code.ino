 
/************************************************************************************
Test the MEGA Communications with the Arduino Nano

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

/*Libraries for Real Time Clock*/
#include <stdio.h>
#include <DS1302.h>

/*Libraries for ic2 Liquid Crystal*/
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
//LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);    //LCD on test mower stand

/*Libraries for the Mowing Calendar Function*/
#include <TimeLib.h>
#include <TimeAlarms.h>
AlarmId id;

/*Compass Setup*/
#include <DFRobot_QMC5883.h>
DFRobot_QMC5883 compass;


/* Pin setup for Arduino MEGA
************************************************************************************/

/*Perimeter Wire Pins*/
#define pinPerimeterLeft A5        // perimeter pin
#define pinPerimeterRight A4       // leave open
#define pinLED LED_BUILTIN

/*Voltage Sensor Pin for ADCMan*/
#define pinVoltSensor A3

/*Real Time Clock Pins*/
const int kCePin   = 29;  // RST
const int kIoPin   = 30;  // DAT
const int kSclkPin = 31;  // CLK

DS1302 rtc(kCePin, kIoPin, kSclkPin);

/*Sonar Setup for Front Sonars 1-5*/
#define echoPin1 34   //S1               
#define trigPin1 35
#define echoPin2 36   //S2 
#define trigPin2 37
#define echoPin3 38   //S3
#define trigPin3 39



//Membrane Switch
#define Start_Key 50 //connect wire 1 to pin 2
#define Plus_Key 51 //connect wire 2 to pin 3
#define Minus_Key 52 //connect wire 3 to pin 4
#define Stop_Key 53 //connect wire 4 to pin 5

/*Pin Setup for the wheel Motion L298N Dual H Bridge Motor Controller.*/
/*Motor A*/
#define ENAPin 7                // EN Pins need a digital pin with PWM
#define IN1Pin 6                // IN Pins dont need digital PWM 
#define IN2Pin 5
/*Motor B*/
#define ENBPin 2                // EN Pins need a digital pin with PWM
#define IN3Pin 4                // IN Pins dont need digital PWM
#define IN4Pin 3

/*Motor Blades*/
#define RPWM 8
#define L_EN 9
#define R_EN 10

/*Docking Station*/
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
int mode = 0;
int senderOff;                      // Value sent to detrmine if the wire is on or off before motors are activated.
bool Perimeter_Wire_Mode;
bool Test_Docking_Procedure;

/*Sonar Variables*/
long duration1 = 0;               // Time required for the sonar ping to be recieved by the echo pin.
long duration2 = 0;
long duration3 = 0;

int  Sonar_1_Activate;
int  Sonar_2_Activate;
int  Sonar_3_Activate;


int distance1 = 999;                    // Distance caculated  by the Sonar
int distance2 = 999;
int distance3 = 999;

int distance_blockage;            // Registeration of blockages while finsing wire.
int Blockage_Registered;
int Max_Number_Blockage_Registered;


long maxdistancesonar;             // used to set the max distance before sonar is triggered to X
int MowerMotionStatus;             // lets the loop know which motion path the mower shall use.

/*Motor Variables*/
int Motors_ON;
int FullSpeed;
//int HalfSpeed;
//int SlowSpeed;

/*Blade Variables*/
bool Blades_ON;
bool Blade_Override;


/*Voltage Variables*/
//Voltage Sensor Vqariables
//float vout = 0.0;
//float R1 = 30000;   
//float R2 = 7100;      // 7500
//int RawValueVolt;     // Sensor value from serial communications
float BatteryVoltage = 0.0;
float BatteryMax;
float BatteryMin;
int BatSensorValue;
float Voltnow;
int Battery_To_Charge_Station_Count;


int I;                            // Define variable for IF-LOOP counter to get average battery value.
int Battery_NoBattery_Found;
int Good_Batt_Value;
int Show_Batt_Voltage;
int Show_Batt_Percent;
int Battery_Dynamic_Value;
int Battery_Dynamic_Motion;
int BatteryVoltage_Last;

/*Error Handling*/
int Error;
bool Mower_Docked;
int ObjectRegistered;


/*General Setup*/
bool   WIFI_On;

/*Perimeter Wire Tracking*/
bool Track_Wire_CCW_Charge;
bool Track_Wire_CW_Charge;
bool Track_Wire_Start_pos_CW;
bool Track_Wire_Start_pos_CCW;
int Track_Wire_Zone_1_Cycles;
int Track_Wire_Zone_2_Cycles;
int Track_Wire_Itterations;
int Exit_Zone;
int MAG_Now;
int MAG_OUT_Stop;
int MAG_IN_Stop;
int MAG_TURN;
int MAG_Average_Start;
int MAG_Last;
int Outside_Wire_Count;
int Outside_Wire_Count_Max;

int Tracking_Turn_Left;
int Tracking_Turn_Right;
int Max_Tracking_Turn_Right;
int Max_Tracking_Turn_Left;

int Mower_Turn_Delay_Left;
int Mower_Turn_Delay_Right;
int Mower_Reverse_Delay;

int InMin;
int InMid;
int InMax;
int OutMin;
int OutMid;
int OutMax;

int PWM_Right;
int PWM_Left;
int MAG_Goal;
int MAG_Error;
int MAG_Start;
float P;
float D;
int PWM_MaxSpeed_LH;
int PWM_MaxSpeed_RH;
int PWM_Blade_Speed;
int PWM_Blade_Speed_Min;
int PWM_Blade_Speed_Max;

/* Wire Track Printer */
int Scale;
//int PrintInMax;
//int PrintInMid;
//int PrintInMin;
//int PrintOutMin;
//int PrintOutMid;
//int PrintOutMax;
//int PrintMAG_Now;

/*Docking Variables*/
bool Docked_Button_Pressed;
bool Exit_Dock_To_Garden_Procedure;

/*Mow Calendar Variables*/
bool Alarm_1_ON;
int Alarm_Hour;
int Alarm_Hour1;
int Alarm_Minute1;

bool Alarm_2_ON;
int Alarm_Hour2;
int Alarm_Minute2;

bool Alarm_3_ON;
int Alarm_Hour3;
int Alarm_Minute3;
int Alarm_Hour_Now;
int Alarm_Second;
int Alarm_Day_of_Week;
int Time_Hour;
int Time_Minute;
int Time_Second;
int Time_Day;
int Time_Month;
int Time_Year;
int Time_Date;

/*Compass Variables*/
float Heading;
float Declination_Angle;
float Compass_Heading_Degrees;
bool Test_Compass_Mode;
bool Compass_Mode;
int Home_Wire_Compass_Heading;

//Membrane KEy Variables
int Start_Key_X;
int Plus_Key_X;
int Minus_Key_X;
int Stop_Key_X;
bool Menu_Complete;
int Menu_Mode_Selection;
int Mow_Time_Set;

//Serial Communication
byte val;
byte low, high;
float AmpsReal;


/***********************************************************************************************

                   SETUP OF MOWER
                   ====================================

 ***********************************************************************************************/

void setup() {
    //Setup is placed in a function so the setup can be ran once the Mower is docked 
    //to reset the board as best as possible to the beginning.
  
  /* User defined parameters to switch on or off parts of the code depending on the Setup of the Mower
     Useful for testing e.g. to switch the blades off if testing indoors.
  ****************************************************************************************************/

  /*  1 = Turned ON      0 = Turned OFF       Value = Value set for variable.*/

  //Main settings for the Mower Operation

  Blades_ON                     = 1;                      // Blades spinning or not set to 0 (zero) for OFF!  CAREFUL FINGERS!!
  Perimeter_Wire_Mode           = 1;                      // activates deactivates the perimiter wire detetcion.
  WIFI_On                       = 0;                      // Activates WIFI Communication
  Exit_Dock_To_Garden_Procedure = 1;                      // Tracks the wire around the garden to the Mower start position away from the docking station 

  // Test Modes to debug certain mower procdures
  Test_Docking_Procedure    = 0;                          // Test the docking procedure
  Test_Compass_Mode         = 0;

  //Detailed Setup
  BatteryMax                = 12.6;                       // Max battery reading read by ADCMan in Volts  12.8 LiPo   12.6 LiIon 8650 to 4.2V Charge 3S
  BatteryMin                = 11.8;                       // Lower Limit of battery before motors are switched off in  Volt LIPO = 11.3    LIIon = 10.8 8650 Batteries
  Show_Batt_Voltage         = 1;                          // Select 1 to show battery voltage in the LCD display
  Battery_Dynamic_Motion    = 1;                          // Adjusts the timing of the mower movments depending on the battery level
  Battery_Dynamic_Value     = 12.0;                       // Voltage below which the movements are magnified to have the same turning and reversing power at low voltage.

  Sonar_1_Activate          = 1;                          // Activate the Sonar #1 - More sonars = a slower loop time and slugish reactions but better obsticle avoidance.
  Sonar_2_Activate          = 1;                          // Activate the Sonar #2
  Sonar_3_Activate          = 1;                          // Activate the Sonar #3
  
  Track_Wire_CW_Charge      = 1;                          // Track perimeter wire in a Clockwise Direction to the charging station
  Track_Wire_CCW_Charge     = 0;                          // Track perimeter wire in a Counter Clockwise Direction to the charging station
  Track_Wire_Start_pos_CW   = 0;                          // Track the wire CW to the start position
  Track_Wire_Start_pos_CCW  = 1;                          // Track the wire CCW to the start position
  Outside_Wire_Count_Max    = 3;                          // Counts the number of times the mower is outside the wire consecutively.  i.e. Mower is lost

  Max_Number_Blockage_Registered = 40;                    // Max number of blockages registered by sonar before turn is made.
  
  Mower_Turn_Delay_Left     = 2500;                       // Turn time of the Mower after it reverses at the wire.
  Mower_Turn_Delay_Right    = 2700;                       //     a higher number increases the angle of turn.
  Mower_Reverse_Delay       = 3000;                       // Reverseing time when at the wire. 

  Track_Wire_Zone_1_Cycles  = 2000;                       // Number of Itterations the PID function does before the mower exits the wire track
  Track_Wire_Zone_2_Cycles  = 4000;                       //    Therefore how long the mower is tracking the wire can be set = distance tracked.
  
  Max_Tracking_Turn_Right   = 250;                        // The maximum number of turn right commands during wire tracking before a renewed wire find function is called
  Max_Tracking_Turn_Left    = 250;                        // This helps to re-find the wire should the mower loose the wire for any reason.

  PWM_Blade_Speed           = 245;                        // Initial PWM signal sent to the blade motor (speed of blade) new motor works well at 240.
  
  Alarm_1_ON                = 0;                          // Activate Alarm 1  (1 = ON 0 = OFF)
  Alarm_Hour1               = 9;                          // Mowing Hour Number 1
  Alarm_Minute1             = 30;                         // Alarm Minute 1

  Alarm_2_ON                = 0;                          // Activate Alarm 2 (1 = ON 0 = OFF)
  Alarm_Hour2               = 18;                         // Mowing Hour Number 2
  Alarm_Minute2             = 23;                         // Alarm minute 2

  // Go Home Alarm
  Alarm_3_ON                = 0;                          // Activate Alarm 3 (1 = ON 0 = OFF)
  Alarm_Hour3               = 16;                         // Mowing Hour Number 3
  Alarm_Minute3             = 6 ;                         // Alarm minute 3
  
  Alarm_Second              = 00;                         // Seconds
  Alarm_Day_of_Week         = 4;                          // Day of next alarm

  //Compass to find home for wire tracking
  Compass_Mode              = 1;                          // Mowing directions set by the compass - EXPERIMENTAL               
  Home_Wire_Compass_Heading = 140;

  /*General Setup of Mower */
  Mower_Docked              = 1;                          // Starts mower in parked position waiting for alarm 0 = normal
  MowerMotionStatus         = 1;
  MowerMotionStatus         = 2;                          // Sets the motion control 2 = Slow speed first loop
  ObjectRegistered          = 0;                          // Sets the sonar object registered count to 0. If 2 objects are consecutiveley detected by Sonar the mower will turn.
  Battery_NoBattery_Found   = 0;                          // Sets the low battery monitor to 0. if 10 instances are detected then the low battery is a low battery.


  /* Description of how the below values are displayed in the Serial Monitor Print Out for the wire
     function
     (InMax)                   Wire = 0                 (OutMax)
         |      (InMid)           |           (OutMid)     |
         |--------|--------|------|------|--------|--------|
         |        |        |      |      |        |        |
                        (InMin)       (OutMin)
  */

  // OUTDOOR VALUES
    /*Negative Values for In*/                            // These values are based on the signal received by the wire sensor for my perimeter loop
    InMin = -200;
    InMid = -700;
    InMax = -1500;                                        // the maximum received signal value inside the wire
    /*General Setup*/
    P             = 0.17;                                 // Multiplication factor to the error measured to the wire center.  if jerky movement when tracking reduce number
    D             = 10;                                   // Dampening value to avoid the mower snaking on the wire.  
    Scale         = 36;                                   // Serial Monitor Line Tracking Print Scale
    PWM_MaxSpeed_LH  = 250;                               // Wheel Motor Speed Max LH Wheel (Looking from back of mower)
    PWM_MaxSpeed_RH  = 255;                               // Wheel Motor Speed Max RH Wheel
   
    /*Positive Values for Out*/
    OutMin = 150;
    OutMid = 400;
    OutMax = 1500;                                        // the maximum received signal value outside the wire
  
  
  
  /************************************************************************************************************/


  /* Starts the Communication to the Serial Monitor baud 115200. */
  Serial.begin(115200);
  Serial1.begin(9600);
  Serial.println("");
  Serial.println("SETTING UP THE MOWER..... Please Wait ........");
  Serial.println("************************************************************");
  Serial.println(" ");





  /*Sets up the Voltage sensor Pins*/
  pinMode(pinVoltSensor, INPUT);

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



  Check_Serial_Communications();
 //TestforBatteryVoltage();


} //End the Loop
