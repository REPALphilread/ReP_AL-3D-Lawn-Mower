
//Libraries for Perimeter Wire Receiver
#include <Arduino.h>
#include <Wire.h>
#include <EEPROM.h>
#include "drivers.h"
#include "adcman.h"
#include "perimeter.h"

//Libraries for Real Time Clock
#include <stdio.h>
#include <DS1302.h>

//Libraries for ic2 Liquid Crystal
#include <LiquidCrystal_I2C.h>
//LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  //Mower 1 Test
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);    //Mower 2

//Libraries for the Mowing Calendar Function
#include <TimeLib.h>
#include <TimeAlarms.h>
AlarmId id;

//Compass Setup
#include <DFRobot_QMC5883.h>
DFRobot_QMC5883 compass;


//Pin setup for Arduino MEGA

//Perimeter Wire Pins
#define pinPerimeterLeft A5        // perimeter pin normally A5
#define pinPerimeterRight A4       // leave open
#define pinLED LED_BUILTIN


//Real Time Clock Pins
const int kCePin   = 29;  // RST
const int kIoPin   = 30;  // DAT
const int kSclkPin = 31;  // CLK

DS1302 rtc(kCePin, kIoPin, kSclkPin);

//Sonar Setup for Front Sonars 1-3
#define echoPin1 34   //S1               
#define trigPin1 35
#define echoPin2 36   //S2 
#define trigPin2 37
#define echoPin3 38   //S3
#define trigPin3 39



//Membrane Switch
#define Start_Key 50 //connect wire 1 to pin 2
#define Plus_Key 51  //connect wire 2 to pin 3
#define Minus_Key 52 //connect wire 3 to pin 4
#define Stop_Key 53  //connect wire 4 to pin 5


//Pin Setup for the wheel Motor Bridge Controller
//Motor A
#define ENAPin 7                // EN Pins need a digital pin with PWM
#define IN1Pin 6                // IN Pins dont need digital PWM 
#define IN2Pin 5
//Motor B
#define ENBPin 2                // EN Pins need a digital pin with PWM
#define IN3Pin 4                // IN Pins dont need digital PWM
#define IN4Pin 3

//Motor Blades
#define RPWM 8
#define L_EN 9
#define R_EN 10

//Relay Switch
#define Relay_Motors 24         // be careful that you really use PIN24.  The order is sometimes labelled
                                // so it looks like 24 is actually 22.


//Global Variables

  //Perimeter Variables
  Perimeter perimeter;
  unsigned long nextTime = 0;
  int counter = 0;
  boolean inside = true;
  int Wire_Detected;

  byte Loop_Cycle_Mowing = 0; 

  //Sonar Variables
  long duration1 = 0;                     // Time required for the sonar ping to be recieved by the echo pin.
  long duration2 = 0;
  long duration3 = 0;

  int distance1 = 999;                    // Distance caculated  by the Sonar
  int distance2 = 999;
  int distance3 = 999;

  int distance_blockage;     

  int Sonar_Hit_1_Total;
  int Sonar_Hit_2_Total;
  int Sonar_Hit_3_Total;
  bool Sonar_Hit_Any_Total;
  bool Sonar_Hit_1 = 0;
  bool Sonar_Hit_2 = 0;
  bool Sonar_Hit_3 = 0;
  bool Sonar_Hit   = 0;


  //Mower Status Variables
  bool Mower_Docked;
  bool Mower_Parked;
  bool Mower_Running;
  bool Mower_Parked_Low_Batt;
  bool Mower_Lost;
  bool Manuel_Mode;

  //Membrane Key Variables
  byte  Start_Key_X;
  byte  Plus_Key_X;
  byte  Minus_Key_X; 
  byte  Stop_Key_X;
  bool  Menu_Complete;
  byte  Menu_Mode_Selection;
  int   Mow_Time_Set;

  //Serial Communication
  float Volts;
  float Volts_Last;
  int   Zero_Volts;
  float Amps;
  float VoltageAmp;
  int   RawValueAmp;
  int   RawValueVolt;
  int   Rain_Detected;
  int   Rain_Hit_Detected = 0;
  int   Charging;
  //float Battery_Voltage_Last;
  float Amps_Last;
  int   Volts_Outside_Reading;
  byte  OK_Nano_Data_Volt_Received; 
  byte  OK_Nano_Data_Charge_Received;
  byte  Charge_Hits = 0;
  byte  Docked_Hits = 0;
  bool  Charge_Detected_MEGA = 0;
  
  //Mow Calendar Variables
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

  //Perimeter Wire Tracking
  int I; 
  int Track_Wire_Itterations;
  bool Outside_Wire;
  byte Exit_Zone;
  int MAG_Now;
  int MAG_OUT_Stop;
  int MAG_IN_Stop;
  int MAG_TURN;
  int MAG_Average_Start;
  int MAG_Last;
  byte Outside_Wire_Count = 0;
  int Tracking_Wire = 0;

  byte Tracking_Turn_Left;
  byte Tracking_Turn_Right;
  bool Mower_Track_To_Charge;
  bool Mower_Track_To_Exit;

  bool Abort_Wire_Find;
  bool No_Wire_Found;

  int PWM_Right;
  int PWM_Left;
  int MAG_Goal;
  int MAG_Error;
  int MAG_Start;
  byte PWM_Blade_Speed_Min;
  byte PWM_Blade_Speed_Max;
  bool Blade_Override = 0;

  //Compass Variables
  float Compass_Heading_Degrees;
  float Heading;
  bool  Compass_Heading_Locked = 0;
  float Heading_Lock;
  int   Heading_Upper_Limit_Compass;
  int   Heading_Lower_Limit_Compass;

  //Wire Track Printer
  int PrintInMax;
  int PrintInMid;
  int PrintInMin;
  int PrintOutMin;
  int PrintOutMid;
  int PrintOutMax;
  int PrintMAG_Now;

  //WIFI Variables
  float val_WIFI;


/***********************************************************************************************

                   SETUP OF MOWER

  The following setup parameters will setup the mower for your garden
  Turn on or off the settings to defien how you like the mower to behave.
    
  1 = Turned ON      0 = Turned OFF       Value = Value set for variable.

****************************************************************************************************/

  char Version[16] = "V6.03";

  bool Cutting_Blades_Activate    = 1;                          // Activates the cutting blades and disc in the code
  bool WIFI_Enabled               = 1;                          // Activates the WIFI Fucntions
  bool Perimeter_Wire_Enabled     = 1;                          // Activates use of the perimeter boundary wire

  //Docking Station
  bool Use_Charging_Station       = 1;                          // 1 if you are using the docking/charging station     0 if not
  bool CW_Tracking_To_Charge      = 1;                          // Clock-Wise         tracking around the boundary wire to the charging station
  bool CCW_Tracking_To_Charge     = 0;                          // Counter-Clock-Wise tracking around the boundary wire to the charging station
  bool CW_Tracking_To_Start       = 0;                          // Clock-Wise         tracking around the boundary wire when tracking to the start position
  bool CCW_Tracking_To_Start      = 1;                          // Counter-Clock-Wise tracking around the boundary wire to the charging station
  byte Docked_Filter_Hits         = 1;                          // Number of charge signals to be detected before mower powers off
  
  int Track_Wire_Zone_1_Cycles    = 1700;                       // Zone 1 - Number of Itterations the PID function does before the mower exits the wire track
  int Track_Wire_Zone_2_Cycles    = 2500;                       // Zone 2 - Therefore how long the mower is tracking the wire can be set = distance tracked.

  byte Max_Tracking_Turn_Right    = 250;                        // The maximum number of turn right commands during wire tracking before a renewed wire find function is called
  byte Max_Tracking_Turn_Left     = 250;                        // This helps to re-find the wire should the mower loose the wire for any reason.
  int  Max_Cycle_Wire_Find        = 320;                        // MAximum number of forward tracking cycles before the mower restarts a compass turn and wire find.

  //Compass Module
  bool Compass_Activate               = 1;                      // Turns on the Compass (needs to be 1 to activate further compass features)
  bool Compass_Heading_Hold_Enabled   = 1;                      // Activates the compass heading hold function to keep the mower straight
  int  Home_Wire_Compass_Heading      = 110;                    // Heading the Mower will search for the wire once the mowing is completed.
  int  CPower                         = 2;                    // Magnification of heading to PWM - How strong the mower corrects itself in Compass Mowing

  //Rain sensor 
  bool Rain_Sensor_Installed          = 1;                      // 1 for Rain sensor installed    0 for no sensor installed.
  byte Rain_Total_Hits_Go_Home        = 10;                      // This sensor only makes sense in combination with a mower docking station
                                                                // as the mower is sent there to get out of the rain.
  //Battery Settings
  float Battery_Max               = 12.6;                       // Max battery volts in Volts. 3S = 12.6V
  float Battery_Min               = 10.2;                       // Lower Limit of battery charge before re-charge required.
  byte  Low_Battery_Detected      = 0;                          // Always set to 0
  byte  Low_Battery_Instances_Chg = 14;                         // Instances of low battery detected before a re-charge is called..

  //Sonar Modules
  bool Sonar_1_Activate           = 1;                          // Activate (1) Deactivate (0) Sonar 1
  bool Sonar_2_Activate           = 1;                          // Activate (1) Deactivate (0) Sonar 2
  bool Sonar_3_Activate           = 1;                          // Activate (1) Deactivate (0) Sonar 3
  int  Max_Sonar_Hit              = 3;                          // Maximum number of Sonar hits before object is discovered
  long maxdistancesonar           = 30;                         // distance in cm from the mower that the sonar will activate at.

  //Wheel Motor Setup
  byte Max_Cycles                 = 150;
  byte PWM_MaxSpeed_LH            = 210;                        // Straight line speed LH Wheel (Looking from back of mower)
  byte PWM_MaxSpeed_RH            = 255;                        // Straight line speed RH Wheel - adjust to keep mower tracking straight.
  int Mower_Turn_Delay_Min        = 1500;                       // Min Max Turn time of the Mower after it reverses at the wire.
  int Mower_Turn_Delay_Max        = 2500;                       // A random turn time between these numbers is selected by the software
  int Mower_Reverse_Delay         = 2500;                       // Time the mower revreses at the wire

      

  //Blade Motor Setup
  byte PWM_Blade_Speed            = 252;                        // PWM signal sent to the blade motor (speed of blade) new motor works well at 245.

  // Alarm Setup
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
  byte Alarm_Minute3              = 6;                          // Alarm minute 3

  byte Alarm_Second               = 5;                          // Seconds


  /* Description of how the below values are displayed in the Serial Monitor Print Out for the wire
     function
     (InMax)                   Wire = 0                 (OutMax)
         |      (InMid)           |           (OutMid)     |
         |--------|--------|------|------|--------|--------|
         |        |        |      |      |        |        |
                        (InMin)       (OutMin)
  */

  // Wire detection Values
    /*Negative Values for In*/                                    // These values are based on the signal received by the wire sensor for my perimeter loop
    int InMin = -200;
    int InMid = -700;
    int InMax = -1500;                                            // the maximum received signal value  the wire
    /*General Setup PID numbers for wire tracking*/
    float P               = 0.08;                                 // Multiplication factor to the error measured to the wire center.  if jerky movement when tracking reduce number
    float D               = 10;                                   // Dampening value to avoid the mower snaking on the wire.  
    byte Scale            = 36;                                   // Serial Monitor Line Tracking Print Scale
  
    /*Positive Values for Out*/
    int OutMin = 150;
    int OutMid = 400;
    int OutMax = 1500;                                            // the maximum received signal value outside the wire

    int Outside_Wire_Count_Max          = 10;                      // If the mower is outside the wire this many times the mower is stopped
    int Action_On_Over_Wire_Count_Max   = 2;                      // Set 1 to hibernate mower (Power Off and Stop)   Set 2 to refind garden using sonar and wire detect function

    bool Show_TX_Data                   = 0;                      // Show the values recieved from the Nano / ModeMCU in the serial monitor


/************************************************************************************************************/    



void setup() {
  Serial.begin(115200);
  Serial1.begin(1200);									// Open Serial port 1 for the nano communication
  if (WIFI_Enabled == true) Serial2.begin(9600);					// If WIFI is on open Serial port 2 for the NodeMCU communication
  Serial.println(" ");
  Serial.println(" ");  
  Serial.print("ReP_AL Robot");
  Serial.println(Version);  
  Serial.println("===================");
  Serial.println("");
  Serial.println("Starting Mower Setup");
  Serial.println("===================");
  if (Set_Time == 1 ) Set_Time_On_RTC();
  DisplayTime();
  Create_Alarms();
  Prepare_Mower_from_Settings();
  Setup_Run_LCD_Intro ();
  Setup_Relays();
  Setup_Membrane_Buttons();
  Setup_Motor_Pins();
  Setup_Compass();
  Setup_ADCMan();
  }

void loop() {

// Read the Serial Ports for Data
Read_Serial1_Nano ();									// Read the Serial data from the nano
Print_Mower_Status();                                                                	// Update the Serial monitor with the current mower status.

// Mower is docked waiting for a command to leave and mow.
if (Mower_Docked == 1)          Print_LCD_Volt_Info();                                  // Print the voltage to the LCD screen
if (Mower_Docked == 1)          Check_if_Charging();
if (Mower_Docked == 1)          Check_if_Raining_From_Nano ();  
if (Mower_Docked == 1)          Print_LCD_Info_Docked();                                // Print information to the LCD screen
//if (Mower_Docked == 1)          Print_Time_On_LCD(); 
if (Mower_Docked == 1)          Check_Membrane_Switch_Input_Docked();                   // Check the membrane buttons for any input
if (Mower_Docked == 1)          TestforBoundaryWire();                                  // Test is the boundary wire is live                                 
if (Mower_Docked == 1)          Manouver_Dock_The_Mower();

// Mower is Parked ready to be started / re-started.
if (Mower_Parked == 1)          Print_LCD_Volt_Info();                                  // Print the voltage to the LCD screen
if (Mower_Parked == 1)          Check_if_Charging();
if (Mower_Parked == 1)          Check_if_Raining_From_Nano ();                               // Checks if the water sensor detects Rain
if (Mower_Parked == 1)          Print_LCD_Info_Parked();                                // Print information to the LCD screen
if (Mower_Parked == 1)          Check_Membrane_Switch_Input_Parked();                   // Check the membrane buttons for any input
if (Mower_Parked == 1)          TestforBoundaryWire();
if (Mower_Parked == 1)          Manouver_Park_The_Mower();

// Mower is Parked with Low Battery needing manuel charging
if (Mower_Parked_Low_Batt == 1) Print_LCD_Volt_Info();                                  // Print the battery voltage
if (Mower_Parked_Low_Batt == 1) Print_Recharge_LCD();                                   // Print re-charge on the LCD screen
if (Mower_Parked_Low_Batt == 1) Check_Membrane_Switch_Input_Parked();

// Lost mower is put into standby mode
if (Mower_Lost == 1) Print_Mower_Lost();                                                // Safety mode incase the mower is lost

// Mower is running cutting the grass.
if (Mower_Running == 1)                                                                             Print_LCD_Volt_Info();              // Print the voltage to the LCD screen
if (Mower_Running == 1)                                                                             Process_Volt_Information();         // Take action based on the voltage readings
if (Mower_Running == 1)                                                                             Check_if_Raining_From_Nano();       // Test the rain sensor for rain. If detected sends the mower home
if (Mower_Running == 1)                                                                             Check_Membrane_Switch_Input_Parked();
if (Mower_Running == 1)                                                                             TestforBoundaryWire();              // Test is the boundary wire is live
if ((Mower_Running == 1) && (Wire_Detected == 1))                                                   Check_Wire_In_Out();                // Test if the mower is in or out of the wire fence.
if ((Mower_Running == 1) && (Wire_Detected == 1) && (Outside_Wire == 0))                            Check_Sonar_Sensors();              // If the mower is  the boundary wire check the sonars for obsticles and prints to the LCD
if ((Mower_Running == 1) && (Wire_Detected == 1) && (Outside_Wire == 0) && (Sonar_Hit == 0))        Manouver_Mow_The_Grass();           // Inputs to the wheel motors / blade motors according to surroundings 
if ((Mower_Running == 1) && (Wire_Detected == 1) && (Outside_Wire == 1) && (Loop_Cycle_Mowing > 0)) Manouver_Turn_Around();             // If outside the wire turn around
if ((Mower_Running == 1) && (Wire_Detected == 1) && (Outside_Wire == 0) && (Sonar_Hit == 1))        Manouver_Turn_Around_Sonar();       // If sonar hit is detected and mower is  the wire, manouver around obsticle 

// WIFI Commands from and to APP
if (Manuel_Mode == 1) Receive_WIFI_Manuel_Commands();
if (Manuel_Mode == 1) Print_LCD_Info_Manuel();
if ((WIFI_Enabled == 1) && (Manuel_Mode == 0)) Get_WIFI_Commands();                                   // TX and RX data from NodeMCU

Serial.println(); 
  
}  // End Loop

  
