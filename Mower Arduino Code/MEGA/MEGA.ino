
/************************************************************************************
        ReP_AL Mower Project V5.3
     ==========================================

WIFI Started
Compass Tracking Testing

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
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Mower 1 Test
//LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);    //Mower 2

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
#define pinPerimeterLeft A5        // perimeter pin normally A5
#define pinPerimeterRight A4       // leave open
#define pinLED LED_BUILTIN


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
#define Relay_Motors 24         // be careful that you really use PIN24.  The order is sometimes labelled
                                // so it looks like 24 is actually 22.
                                





/***********************************************************************************
                       Global Variables
************************************************************************************/

/*Perimeter Variables*/
Perimeter perimeter;
unsigned long nextTime = 0;
int counter = 0;
boolean inside = true;
int senderOff;                      // Value sent to detrmine if the wire is on or off before motors are activated.

/*Sonar Variables*/
long duration1 = 0;               // Time required for the sonar ping to be recieved by the echo pin.
long duration2 = 0;
long duration3 = 0;

int distance1 = 999;                    // Distance caculated  by the Sonar
int distance2 = 999;
int distance3 = 999;


int distance_blockage;            // Registeration of blockages while finsing wire.
byte Blockage_Registered;
bool Mower_Stopped ;

/*Motor Variables*/
bool Motors_ON;

/*Blade Variables*/
bool Blade_Override;

/*Voltage Variables*/
float BatteryVoltage = 0.0;
byte Battery_To_Charge_Station_Count;

int I;                            // Define variable for IF-LOOP counter to get average battery value.
float BatteryVoltage_Last;
float Amps_Last;

/*Error Handling*/
byte Error;

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

byte Tracking_Turn_Left;
byte Tracking_Turn_Right;

int PWM_Right;
int PWM_Left;
int MAG_Goal;
int MAG_Error;
int MAG_Start;
byte PWM_Blade_Speed_Min;
byte PWM_Blade_Speed_Max;

/* Wire Track Printer */
int PrintInMax;
int PrintInMid;
int PrintInMin;
int PrintOutMin;
int PrintOutMid;
int PrintOutMax;
int PrintMAG_Now;

/*Docking Variables*/
bool Docked_Button_Pressed;

/*Mow Calendar Variables*/
byte Alarm_Hour_Now;
byte Time_Hour;
byte Time_Minute;
byte Time_Second;
byte Time_Day;
byte Time_Month;
byte Time_Year;
byte Time_Date;

String dayAsString(const Time::Day day) {
  switch (day) {
    case Time::kSunday: return "Sunday";
    case Time::kMonday: return "Monday";
    case Time::kTuesday: return "Tuesday";
    case Time::kWednesday: return "Wednesday";
    case Time::kThursday: return "Thursday";
    case Time::kFriday: return "Friday";
    case Time::kSaturday: return "Saturday";
  }
  return "(unknown day)";
}

/*Compass Variables*/
float Compass_Heading_Degrees;
float Heading;
bool  Compass_Heading_Locked = 0;
float Heading_Lock;
int   Heading_Upper_Limit_Compass;
int   Heading_Lower_Limit_Compass;

//Membrane KEy Variables
byte Start_Key_X;
byte Plus_Key_X;
byte Minus_Key_X; 
byte Stop_Key_X;
bool Menu_Complete;
byte Menu_Mode_Selection;
int Mow_Time_Set;

//Serial Communication
float VoltsTX;
int AmpsTX;
byte Nano_Data_Volt_Received;
byte Nano_Data_Amp_Received;
byte Amp_Hits = 0;

// Blynk Commands
float val_WIFI;

// Mower Setups
byte Mower_Setup;


/***********************************************************************************************

                   SETUP OF MOWER
                   ====================================

 ***********************************************************************************************/

 
  /* User defined parameters to switch on or off parts of the code depending on the Setup of the Mower
     Useful for testing e.g. to switch the blades off if testing indoors.
  ****************************************************************************************************/

  /*  1 = Turned ON      0 = Turned OFF       Value = Value set for variable.*/

  //Main settings for the Mower Operation

  bool Blades_ON                     = 1;                      // Blades spinning or not set to 0 (zero) for OFF!  CAREFUL FINGERS!!
  bool Perimeter_Wire_Mode           = 1;                      // activates deactivates the perimiter wire detetcion.
  bool WIFI_On                       = 0;                      // Activates WIFI Communication
  bool Exit_Dock_To_Garden_Procedure = 1;                      // Tracks the wire around the garden to the Mower start position away from the docking station 
  bool Compass_Mode                  = 1;                      // Mowing directions set by the compass + docking direction - EXPERIMENTAL        
  bool Compass_Heading_Hold          = 1;                      // activates the compass heading hold function
  bool Compass_Turn_Activated        = 0;

  //Detailed Setup
  float BatteryMax                = 12.6;                       // Max battery reading read by ADCMan in Volts  12.8 LiPo   12.6 LiIon 8650 to 4.2V Charge 3S
  float BatteryMin                = 11.8;                       // Lower Limit of battery before motors are switched off in  Volt LIPO = 11.3    LIIon = 10.8 8650 Batteries
  bool  Show_Batt_Voltage         = 1;                          // Select 1 to show battery voltage in the LCD display
  bool  Battery_Dynamic_Motion    = 1;                          // Adjusts the timing of the mower movments depending on the battery level
  int   Battery_Dynamic_Value     = 12;                         // Voltage below which the movements are magnified to have the same turning and reversing power at low voltage.

  bool Sonar_1_Activate           = 1;                          // Activate the Sonar #1 - More sonars = a slower loop time and slugish reactions but better obsticle avoidance.
  bool Sonar_2_Activate           = 1;                          // Activate the Sonar #2
  bool Sonar_3_Activate           = 1;                          // Activate the Sonar #3
  long maxdistancesonar           = 55;                         // distance in cm from the mower that the sonar will activate at.
  
  bool Track_Wire_CW_Charge       = 1;                          // Track perimeter wire in a Clockwise Direction to the charging station
  bool Track_Wire_CCW_Charge      = 0;                          // Track perimeter wire in a Counter Clockwise Direction to the charging station
  bool Track_Wire_Start_pos_CW    = 0;                          // Track the wire CW to the start position
  bool Track_Wire_Start_pos_CCW   = 1;                          // Track the wire CCW to the start position
  byte Outside_Wire_Count_Max     = 3;                          // Counts the number of times the mower is outside the wire consecutively.  i.e. Mower is lost

  byte Max_Number_Blockage_Registered = 40;                    // Max number of blockages registered by sonar before turn is made.
  
  int Mower_Turn_Delay_Left       = 1500;                       // Turn time of the Mower after it reverses at the wire.
  int Mower_Turn_Delay_Right      = 2000;                       //     a higher number increases the angle of turn.
  int Mower_Reverse_Delay         = 1800;                       // Reverseing time when at the wire. 

  int Track_Wire_Zone_1_Cycles    = 2000;                       // Number of Itterations the PID function does before the mower exits the wire track
  int Track_Wire_Zone_2_Cycles    = 4200;                       //    Therefore how long the mower is tracking the wire can be set = distance tracked.
  
  byte Max_Tracking_Turn_Right    = 250;                        // The maximum number of turn right commands during wire tracking before a renewed wire find function is called
  byte Max_Tracking_Turn_Left     = 250;                        // This helps to re-find the wire should the mower loose the wire for any reason.

  bool Reverse_Steering           = 0;                          // Swap Left and Right Motor inputs (instead of reversing wiring on the motor bridge)
  byte PWM_MaxSpeed_LH            = 248;                        // Straight line speed LH Wheel (Looking from back of mower)
  byte PWM_MaxSpeed_RH            = 255;                        // Straight line speed RH Wheel - adjust to keep mower tracking straight.
  byte PWM_Blade_Speed            = 245;                        // PWM signal sent to the blade motor (speed of blade) new motor works well at 245.

  bool Set_Time                   = 0;                          // Turn to 1 to set time on RTC (Set time in Time tab Set_Time_On_RTC)  After setting time turn to 0 and reload sketch.
  bool Alarm_1_ON                 = 0;                          // Activate Alarm 1  (1 = ON 0 = OFF)
  byte Alarm_Hour1                = 9;                          // Mowing Hour Number 1
  byte Alarm_Minute1              = 30;                         // Alarm Minute 1

  bool Alarm_2_ON                 = 0;                          // Activate Alarm 2 (1 = ON 0 = OFF)
  byte Alarm_Hour2                = 18;                         // Mowing Hour Number 2
  byte Alarm_Minute2              = 23;                         // Alarm minute 2

  // Go Home Alarm
  bool Alarm_3_ON                 = 0;                          // Activate Alarm 3 (1 = ON 0 = OFF)
  byte Alarm_Hour3                = 16;                         // Mowing Hour Number 3
  byte Alarm_Minute3              = 6 ;                         // Alarm minute 3
  
  byte Alarm_Second               = 5;                          // Seconds
  byte Alarm_Day_of_Week          = 4;                          // Day of next alarm

  //Compass to find home for wire tracking
  int Home_Wire_Compass_Heading   = 140;                        // Heading the Mower will search for the wire once the mowing is completed.
  int CPower                      = 70;                         // Magnification of heading to PWM - How strong the mower corrects itself in Compass Mowing


  /*General Setup of Mower */
  bool Mower_Docked               = 1;                          // Defines if the mower is in the docking station or not.
  byte MowerMotionStatus          = 2;                          // Sets the motion control 2 = Slow speed first loop
  byte ObjectRegistered           = 0;                          // Sets the sonar object registered count to 0. If 2 objects are consecutiveley detected by Sonar the mower will turn.
  byte Battery_NoBattery_Found    = 0;                          // Sets the low battery monitor to 0. if 10 instances are detected then the low battery is a low battery.
  byte Amp_Filter_Hits            = 1;



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
    float P               = 0.12;                                 // Multiplication factor to the error measured to the wire center.  if jerky movement when tracking reduce number
    float D               = 10;                                   // Dampening value to avoid the mower snaking on the wire.  
    byte Scale            = 36;                                   // Serial Monitor Line Tracking Print Scale
  
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
  Serial1.begin(9600);
  if (WIFI_On == 1 ) Serial2.begin(9600);
  Serial.println("");
  Serial.println("          SETTING UP THE MOWER..... Please Wait ........");
  Serial.println("************************************************************");
  Serial.println(" ");

  Setup_Run_LCD_Intro();
  
  /*Sets and displays the Time     */
  if (Set_Time == 1) Set_Time_On_RTC();            // uncomment to set the time. Go to the funtion to set the times and dates
  Setup_Get_RTC1302_Time();     // Gets the time from the RTC
  delay(5);
  while (!Serial) ;
  SetTime();
  DisplayTime();

  //Membrane Switch Setup
  pinMode(Start_Key, INPUT_PULLUP);            // set pin as input
  pinMode(Plus_Key, INPUT_PULLUP);            // set pin as input
  pinMode(Minus_Key, INPUT_PULLUP);            // set pin as input
  pinMode(Stop_Key, INPUT_PULLUP);            // set pin as input   


  /*Create Alarms         */
  Create_Alarms();

  /*Setup others*/
  Setup_Relays();                             // Sets the output and turns the relay to off.
  Setup_Compass();


  /* PIN SETUP for Sensors
  **************************************************************************/

  //Sets up the SONAR Sensors
  //Sonar 1
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  //Sonar 2
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  //Sonar 3
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);



  /*Sets up the wheel motor Pins*/
  pinMode(ENAPin, OUTPUT);
  pinMode(ENBPin, OUTPUT);
  pinMode(IN1Pin, OUTPUT);
  pinMode(IN2Pin, OUTPUT);
  pinMode(IN3Pin, OUTPUT);
  pinMode(IN4Pin, OUTPUT);

  /*Sets up the Blade Motor Pins  */
  pinMode(RPWM, OUTPUT);
  pinMode(L_EN, OUTPUT);
  pinMode(R_EN, OUTPUT);


  /*Docking Station*/
  pinMode(LED_PIN, OUTPUT);
  delay(5);
  digitalWrite(LED_PIN, LOW);
  Docked_Button_Pressed = 0;



  //Wire Setup

  if (millis() >= nextTime)  {
    nextTime = millis() + 50;
    if (perimeter.isInside(0) != inside) {
      inside = perimeter.isInside(0);
      counter++;
    }
  }

  ADCMan.init();
  perimeter.setPins(pinPerimeterLeft, pinPerimeterRight);
  perimeter.useDifferentialPerimeterSignal = true;
  perimeter.speedTest();

  //Somehow this is required to get the voltage to read in the first dock stage **homework
  
  ADCMan.run();
  //Setup_Perimeter_Wire();
  delay(2000);
  //lcd.noBacklight(); // turn off backlight

}

// END SETUP



/************************************************************************************************

                        THE LOOP

 ************************************************************************************************/

void loop() {

  /* Setup the Errors to the right start vlaues etc. for the new Loop
  ***********************************************************************/
  if (Error <= 6) Error = 0;                                      // Reset Error Code to zero. Errors are added each time thru the loop if found.
  if (MowerMotionStatus <= 1)   MowerMotionStatus = 2;            // If the MotionMowerStatus is 0 it is reset to 2 = Slow - Errors to change Motion to 1 = Stop are added on next loop
  Serial.print("Dock:");
  Serial.print(Mower_Docked);
  Serial.print("|");
  if (Mower_Docked == 1)  {
    Battery_NoBattery_Found = 0;
    MowerMotionStatus = 1;                                        // If the Mower is parked (Mower_Docked=1) then wait until the error is cleared by an alarm.

  }

  Serial.print("L:");                              // Keeping track of the program health in the serial monitor
  Serial.print(MowerMotionStatus);                              // In Setup - first loop Motion Mower is set to 2
  Serial.print("|");
  
  
  // Checks for the membrane switch and controls the menu function
  Check_Membrane_Switch_Input();


  
  // Compass Functions - If the Compass Heading Hold function is turned on the the mower will
  // try to stay mowing in a straight line.
  if (Compass_Mode == 1) Activate_Compass_Functions();
   
       

  /* CHECK ALL SENSORS IF MOWER IS NOT DOCKED
  ************************************************************************************/
  TestforBatteryVoltage();
  
  if (Mower_Docked == 1)  {  
    Check_Serial_Communication_Amps ();
    Check_if_Charging();
    }
  delay(5);

  if ((Mower_Docked == 0) && (Mower_Stopped == 0) ) {             // Sensors are not ran if docked.
    Action_For_Battery_Voltage();                                 // Gives the mower an action depending on batterz voltage
    TestforBoundaryWire();                                        // Check if Boundary wire is switched on and active
    ADCMan.run(); // Keep ADCMan running
    delay(5);
    }
 
  /*Checks for the activation of Time Alarms which set the Mower going
   **************************************************************************/
  //DisplayTime();                                                  // Writes the Time and Date to the Serial monitor
  Display_Next_Alarm();                                           // Time for next Mowing Alarm
  Alarm.delay(10);                                                // Call the check to see if any alarms are active


  // Check for Errors
  //***********************************************************************************
  Check_For_Errors();
  
  // Adjust Mower Speed according to MotionMowerStatus
  // **********************************************************************************
  Calculate_Motion_Mower_Status();

  // Check if the Mower is inside the wire and adjust
  // **********************************************************************************
  Check_Wire();
  Manage_Wire();

  //   PING THE SONAR DETECTORS FOR OBJECTS AROUND:
  // **********************************************************************************
  if ((Mower_Docked == 0) && (Mower_Stopped == 0) )  Ping_Sonars();

  //   WIFI Commands are RX/TX if the WIFI option in setting is on
  // **********************************************************************************
  if (WIFI_On == 1) Get_Blynk_Commands();



  //Serial.print("MMS:");
  //Serial.print(MowerMotionStatus);
  MowerMotionStatus = MowerMotionStatus + 1;                                                    //Adds 1 to the Loop and back to the Top
  Serial.println("|");

          
  }     //End the Loop Bracket
