
// ReP_AL Lawn Mower Arduino Code
// Please make sure you have installed all the library files to the Arduino libraries folder
// You will need to unzip all the libraries from the GitHuB site.
// Instructions on how to do this are available on my webpage
// www.repalmakershop.com



//Libraries for Perimeter Wire Receiver
#include <Arduino.h>
#include <Wire.h>
//#include <EEPROM.h>
#include "drivers.h"
#include "adcman.h"
#include "perimeter.h"


//Libraries for Real Time Clock
#include <stdio.h>
#include <DS1302.h>

//Libraries for ic2 Liquid Crystal
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // 330 Mower
//LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // LAM Test


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

//GPS Fence Signal Pin
#define GPS_Fence_Signal_Pin A7
#define GPS_Lock_Pin A6

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

//Bumper Microswitches
#define Bumper_Switch_Frnt_RH  46               // Define Pin 47 on the MEGA to detect the microswitch
#define Bumper_Switch_Frnt_LH  47               // Define Pin 46 on the MEGA to detect the microswitch

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

//Compass Level
#define X 3
#define Y 7
#define Z 5

// Tilt Sensors
#define Tilt_Angle A8           // measures the angle of the mower
#define Tilt_Orientation A9     // measures if the mower is upside down



//Global Variables

  //Perimeter Variables
  Perimeter perimeter;
  unsigned long nextTime = 0;
  int counter = 0;
  boolean inside = true;
  int Wire_Detected;

  int Loop_Cycle_Mowing = 0;             // was byte before.

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

  // Bumper Variables
  bool Bump_Frnt_LH;
  bool Bump_Frnt_RH;
  bool Bumper;

  //Mower Status Variables
  bool Mower_Docked;
  bool Mower_Parked;
  bool Mower_Running;
  bool Mower_Parked_Low_Batt;
  int  Mower_Error;
  bool Manuel_Mode;
  int  Mower_Status_Value;
  int  Mower_Error_Value;
  bool Exiting_Dock;

  // Mower Running Data
  int Sonar_Status;
  //int Data_Sent_Wire;       // Counter
  int Bumper_Status;
  int Loops;
  int Compass_Steering_Status;


  //Membrane Key Variables
  byte  Start_Key_X;
  byte  Plus_Key_X;
  byte  Minus_Key_X; 
  byte  Stop_Key_X;
  bool  Menu_Complete_Settings;
  bool  Menu_Complete_Alarms;
  bool  Menu_Complete_Sensors;
  bool  Menu_Complete_Motion;
  bool  Menu_Complete_NAVI;
  bool  Menu_Complete_Tracking;  
  bool  Menu_Complete;
  byte  Menu_Mode_Selection;
  int   Menu_View;
  int   Mow_Time_Set;
  int   Max_Options_Timing;
  int   Max_Options_Docked;
  int   Max_Options_Parked;
  int   Max_Options_Settings;
  int   Max_Options_Test;
  int   Max_Options_Alarms;
  int   Max_Options_Sensors;
  int   Max_Options_Motion;
  int   Max_Options_Tracking;
  int   Max_Options_NAVI;
  int   Max_Options_BETA;

  //Serial Communication
  float Volts;
  int   VoltsTX;
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
  int   VoltsTX_Last;
  
  //Mow Calendar Variables
  byte Alarm_Hour_Now;
  byte Time_Hour;
  byte Time_Minute;
  byte Time_Second;
  byte Time_Day;
  byte Time_Month;
  byte Time_Year;
  byte Time_Date;
  bool Alarm_Timed_Mow_ON = 0;
  byte Alarm_Timed_Mow_Hour;                         // Mowing Hour Number 3
  byte Alarm_Timed_Mow_Minute;                       // Alarm minute 3

  int Alarm_1_Saved_EEPROM;
  int Alarm_2_Saved_EEPROM;
  int Alarm_3_Saved_EEPROM;

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
  bool Wire_ON_Printed;
  int Wire_Off;
  int Wire_Refind_Tries = 0;

  int Tracking_Turn_Left;
  int Tracking_Turn_Right;
  bool Mower_Track_To_Charge;
  bool Mower_Track_To_Exit;

  bool Abort_Wire_Find;
  bool No_Wire_Found_Fwd;
  bool No_Wire_Found_Bck;
  int  Wire_Find_Attempt = 0; 

  int  PWM_Right;
  int  PWM_Left;
  int  MAG_Goal;
  int  MAG_Error;
  int  MAG_Start;
  byte PWM_Blade_Speed_Min;
  byte PWM_Blade_Speed_Max;
  bool Blade_Override = 0;

  //Compass Variables
  float   Compass_Heading_Degrees;
  float   Heading;
  bool    Compass_Heading_Locked = 0;
  float   Heading_Lock;
  int     Heading_Upper_Limit_Compass;
  int     Heading_Lower_Limit_Compass;
  float   Compass_Target;
  int     Compass_Leg = 0;
  int     Turn_Adjust = 0;
  int     error = 0;
  float   Calb_XAxis;
  float   Calb_YAxis;
  float   Calb_ZAxis;
  int     Tilt_X;
  int     Tilt_Y;
  int     Tilt_Z;
  float   X_Tilt;
  float   Y_Tilt;
  float   Z_Tilt;
  int     Compass_Detected;

  //GY-521 Compass
  const int MPU_addr=0x68;
  int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

  int minVal=265;
  int maxVal=402;

  // Pattern Mow
  int Spiral_Mow = 1;
  int Linking_Section;
  int Leg = 1;
  float Compass_Last;  

  // GPS
  bool GPS_Inside_Fence;
  int GPS_Fence_Signal;
  int GPS_Lock_Signal;
  bool GPS_Lock_OK;

  //Wire Track Printer
  int PrintInMax;
  int PrintInMid;
  int PrintInMin;
  int PrintOutMin;
  int PrintOutMid;
  int PrintOutMax;
  int PrintMAG_Now;

  // Tilt Sensor
  int Tilt_Angle_Sensed = 1;          // reads the Tilt Angle sensor
  int Tilt_Orientation_Sensed;    // reads the Tilt Orientation sensor

  //WIFI Variables
  float val_WIFI;

  // TFT
  int  TFT_Menu_Command; 
  bool Menu_Complete_TFT;
  bool Mower_Is_Docking;
  bool Turn_To_Home;
  bool Find_Wire_Track;
  bool Go_To_Charging_Station;

 
/***********************************************************************************************

                   SETUP OF MOWER

  The following setup parameters will setup the mower for your garden
  Turn on or off the settings to defien how you like the mower to behave.
  
  Settings marked with EEPROM can be adjusted using the mower LCD menu.  Once changes and saved
  the EEPROM settings will override the settings in this menu.  
  
  To clear these settings you need to clear the EEPROM
    
  1 = Turned ON      0 = Turned OFF       Value = Value set for variable.

****************************************************************************************************/

  char Version[16] = "V8.3";

  bool TFT_Screen_Menu            = 1;                          // Set to 1 to use TFT  and 0 when not used
  bool LCD_Screen_Keypad_Menu     = 0;                          // Set to 1 to use LCD  and 0 when not used
  bool PCB                        = 1;                          // USE Printed Circuit Board Relay

  bool Cutting_Blades_Activate    = 1;     // EEPROM            // Activates the cutting blades and disc in the code
  bool WIFI_Enabled               = 1;     // EEPROM            // Activates the WIFI Fucntions
  bool Perimeter_Wire_Enabled     = 1;     // EEPROM            // Activates use of the perimeter boundary wire
  bool GPS_Enabled                = 0;     // EEPROM            // Activates the GPS Fence Module

  //Docking Station
  bool Use_Charging_Station       = 1;      //EEPROM            // 1 if you are using the docking/charging station     0 if not
  bool CW_Tracking_To_Charge      = 1;      //EEPROM            // Clock-Wise         tracking around the boundary wire to the charging station
  bool CCW_Tracking_To_Charge     = 0;      //EEPROM            // Counter-Clock-Wise tracking around the boundary wire to the charging station
  bool CW_Tracking_To_Start       = 0;      //EEPROM            // Clock-Wise         tracking around the boundary wire when tracking to the start position
  bool CCW_Tracking_To_Start      = 1;      //EEPORM            // Counter-Clock-Wise tracking around the boundary wire to the charging station
  byte Docked_Filter_Hits         = 1;                          // Number of charge signals to be detected before mower powers off


  // Wire Tracking
  int Track_Wire_Zone_1_Cycles    = 1300;   //EEPROM            // Zone 1 - Number of Itterations the PID function does before the mower exits the wire track
  int Track_Wire_Zone_2_Cycles    = 2200;   //EEPROM            // Zone 2 - Therefore how long the mower is tracking the wire can be set = distance tracked.
  int Max_Tracking_Turn_Right     = 270;    //EEPROM            // The maximum number of turn right commands during wire tracking before a renewed wire find function is called (wheel spins)
  int Max_Tracking_Turn_Left      = 270;    //EEPROM            // a re-find the wire sub-routine is called if this value is reached.
  int Max_Cycle_Wire_Find         = 300;    //EEPROM            // Maximum number of forward tracking cycles in finding wire before the mower restarts a compass turn and wire find.
  int Max_Cycle_Wire_Find_Back    = 50;     //EEPROM            // Maximum number of Backward tracking cycles in finding wire before the mower restarts a compass turn and wire find.  

  //Compass Settings
  bool Compass_Activate               = 0;       //EEPROM       // Turns on the Compass (needs to be 1 to activate further compass features)
  int  Compass_Type                   = 1;                      // 1 = HMC QMC   2 = GY-521 ** Experimental Dont Use**
  bool Compass_Heading_Hold_Enabled   = 1;       //EEPROM       // Activates the compass heading hold function to keep the mower straight
  int  Home_Wire_Compass_Heading      = 110;     //EEPROM       // Heading the Mower will search for the wire once the mowing is completed.
  float CPower                        = 2;       //EEPROM       // Magnification of heading to PWM - How strong the mower corrects itself in Compass Mowing

  // Pattern Mow
  int  Pattern_Mow                = 0;       //EEPROM       // 0 = OFF |  1 = Parallel (not working!!) | 3 = Sprials |
    
    // Pattern Spiral
    int    Max_Cycles_Spirals    = 500;      // Overrides the Max_Cycles for straught line mowing as the spirals requires more loops to complete
    float  Compass_Mow_Direction = 110;      // Mow Direction of line when pattern mow is activated

    // Pattern Parallel
    int Turn_90_Delay_LH        = 1150;      // EEPROM          // adjust this number so the mower turns 90° Left
    int Turn_90_Delay_RH        = 1250;      // EEPROM          // adjust this number so the mower turns 90° Right
    int Move_to_next_line_delay = 1000;      // distance between lines
    int Line_Length_Cycles      = 25;        // length of the line mowed


  // Safety Tilt Feature
  int  Angle_Sensor_Enabled           = 0;      //EEPROM       // Prvents Mower from climibing steep hills
  int  Tip_Over_Sensor_Enabled        = 0;      //EEPROM       // Turns mower off if turned over

  //Rain sensor 
  bool Rain_Sensor_Installed          = 1;  //EEPROM            // 1  = Rain sensor installed    0 = no sensor installed.
  int  Rain_Total_Hits_Go_Home        = 10; //EEPROM            // This sensor only makes sense in combination with a mower docking station
                                                                // as the mower is sent there to get out of the rain.
  //Battery Settings
  float Battery_Max               = 12.6;                       // Max battery volts in Volts. 3S = 12.6V
  float Battery_Min               = 11.4;   //EEPROM            // Lower Limit of battery charge before re-charge required.
  byte  Low_Battery_Detected      = 0;                          // Always set to 0
  byte  Low_Battery_Instances_Chg = 14;     //EEPROM            // Instances of low battery detected before a re-charge is called..

  //Sonar Modules
  bool Sonar_1_Activate           = 1;      //EEPROM            // Activate (1) Deactivate (0) Sonar 1
  bool Sonar_2_Activate           = 1;      //EEPROM            // Activate (1) Deactivate (0) Sonar 2
  bool Sonar_3_Activate           = 1;      //EEPROM            // Activate (1) Deactivate (0) Sonar 3
  int  Max_Sonar_Hit              = 3;      //EEPROM            // Maximum number of Sonar hits before object is discovered
  long maxdistancesonar           = 30;     //EEPROM            // distance in cm from the mower that the sonar will activate at.

  // Bumper Module
  bool Bumper_Activate_Frnt       = 0;      //EEPROM            // Activates the bumper bar on the front facia - defualt is off.  Enable in the LCD settings menu.

  //Wheel Motors Setup
  int Max_Cycles_Straight        = 150;     //EEPROM            // Number of loops the Sketch will run before the mower just turns around anyway. Adjust according to your garden length
  int PWM_MaxSpeed_LH            = 240;     //EEPROM            // Straight line speed LH Wheel (Looking from back of mower)  Will be overidden if saved in EEPROM
  int PWM_MaxSpeed_RH            = 255;     //EEPROM            // Straight line speed RH Wheel - adjust to keep mower tracking straight.  Will be overridden if saved in EEPROM

  bool MAG_Speed_Adjustment      = 0;   //** Experimental
  int Slow_Speed_MAG             = -900;                        // MAG Value that Slow Speed Kicks In
  int PWM_Slow_Speed_LH          = 160;                         // Straight line speed when the mower is almost over the wire Left Wheel.
  int PWM_Slow_Speed_RH          = 175;                         // Straight line speed when the mower is almost over the wire Right Wheel.
  
  int Mower_Turn_Delay_Min       = 1000;    //EEPROM            // Min Max Turn time of the Mower after it reverses at the wire. 1000 = 1 second
  int Mower_Turn_Delay_Max       = 2500;    //EEPROM            // A random turn time between these numbers is selected by the software
  int Mower_Reverse_Delay        = 1800;    //EEPORM            // Time the mower reverses before making a turn.

      

  //Blade Motor Setup
  //Blade Speed can be modified in the settings menu and will be written to EEPROM
  //The number below will then be overidden
  int PWM_Blade_Speed            = 250;     //EEPROM           // PWM signal sent to the blade motor (speed of blade) new motor works well at 245.

  // Alarm Setup
  bool Set_Time                   = 0;       //EEPROM           // Turn to 1 to set time on RTC (Set time in Time tab Set_Time_On_RTC)  After setting time turn to 0 and reload sketch.


  // If the Alarm is changed in settings it will be written to EEPROM and the settings below will be overriden.
  // Action for Alarm 1 is set to exit the dock and mow at this time.
  // To change this action go to "void Activate_Alarms()" 
  bool Alarm_1_ON                 = 0;       //EEPROM            // Activate Alarm 1  (1 = ON 0 = OFF)
  int  Alarm_1_Hour               = 12;      //EEPROM            // Mowing Hour Number 1
  int  Alarm_1_Minute             = 00;      //EEPROM            // Alarm Minute 1
  bool Alarm_1_Repeat             = 0;                           // Repeat the Alarm at the same time
  int  Alarm_1_Action             = 1;       //EEPROM            // Sets the actions to be performed when the alarm is called

  // Action for Alarm 2 can be set in "void Activate_Alarms()" 
  bool Alarm_2_ON                 = 0;       //EEPROM            // Activate Alarm 2 (1 = ON 0 = OFF)
  int  Alarm_2_Hour               = 12;      //EEPROM            // Mowing Hour Number 2
  int  Alarm_2_Minute             = 00;      //EEPROM            // Alarm minute 2
  bool Alarm_2_Repeat             = 0;                           // Repeat the Alarm at the same time
  int  Alarm_2_Action             = 1;       //EEPROM            // Sets the actions to be performed when the alarm is called

  // Action for Alarm 3 can be set in "void Activate_Alarms()" 
  // Go Home Alarm
  bool Alarm_3_ON                 = 0;       //EEPROM            // Activate Alarm 3 (1 = ON 0 = OFF)
  int  Alarm_3_Hour               = 12;      //EEPROM            // Mowing Hour Number 3
  int  Alarm_3_Minute             = 00;      //EEPROM            // Alarm minute 3
  bool Alarm_3_Repeat             = 0;                           // Repeat the Alarm at the same time
  int  Alarm_3_Action             = 1;       //EEPROM            // Sets the actions to be performed when the alarm is called

  byte Alarm_Second               = 5;                            // Seconds


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
    float P               = 0.08;              //EEPROM           // Multiplication factor to the error measured to the wire center.  if jerky movement when tracking reduce number
    float D               = 10;                                   // Dampening value to avoid the mower snaking on the wire.  
    byte Scale            = 36;                                   // Serial Monitor Line Tracking Print Scale
  
    // These values set the scale for the wire print out in the serial monitor once tracking
    int OutMin = 150;
    int OutMid = 400;
    int OutMax = 1500;                                            

    int Outside_Wire_Count_Max          = 15;                     // If the mower is outside the wire this many times the mower is stopped
    int Action_On_Over_Wire_Count_Max   = 3;                      // Set 1 to hibernate mower (Power Off and Stop)   Set 2 to refind garden using sonar and wire detect function
                                                                  // 3 to do a refind wire function

    bool Show_TX_Data                   = 0;                      // Show the values recieved from the Nano / ModeMCU in the serial monitor


/************************************************************************************************************/    



void setup() {
  Serial.begin(115200);
  Serial1.begin(1200);									                  // Open Serial port 1 for the nano communication
  if (WIFI_Enabled == true) Serial2.begin(9600);					// If WIFI is on open Serial port 2 for the NodeMCU communication
  if (TFT_Screen_Menu == 1) Serial3.begin(9600);          // 1200 before
  Wire.begin();                                           // start the i2c interface
  Serial.println(" ");
  Serial.println(" ");  
  Serial.print(F("ReP_AL Robot :"));
  Serial.println(Version);  
  Serial.println(F("==================="));
  Serial.println("");
  Serial.println(F("Starting Mower Setup"));
  Serial.println(F("==================="));
  Load_EEPROM_Saved_Data();
  if (Set_Time == 1 ) {
    Serial.print(F("Setting Time"));
    Set_Time_On_RTC();
  }
  DisplayTime();
  Serial.println("");
  Prepare_Mower_from_Settings();
  if (LCD_Screen_Keypad_Menu == 1) Setup_Run_LCD_Intro ();
  Setup_Compass();
  delay(100);
  Setup_Relays();
  Setup_Tilt_Tip_Safety();
  if (LCD_Screen_Keypad_Menu == 1) Setup_Membrane_Buttons();
  Setup_Motor_Pins();
  Setup_ADCMan();
  Setup_Check_Pattern_Mow();
  if (Bumper_Activate_Frnt == true) Setup_Bumper_Bar();
  }

void loop() {

if (TFT_Screen_Menu == 1)                                 Check_TFT_Serial_Input();   // Check the TFT Serial for any input command.
if ((TFT_Screen_Menu == 1) && (TFT_Menu_Command > 1))     Activate_TFT_Menu();        // If TFT Menu has requested an input, TX or RX that input.

// Read the Serial Ports for Data
Read_Serial1_Nano();                                                                  // Read the Serial data from the nano
Print_Mower_Status();                                                                 // Update the Serial monitor with the current mower status.


// Mower is docked, docking station is enabled and waiting for a command to leave and mow.
if ((Mower_Docked == 1) && (LCD_Screen_Keypad_Menu == 1))         Print_LCD_Volt_Info();                                  // Print the voltage to the LCD screen
if  (Mower_Docked == 1)                                           Check_if_Charging();
if ((Mower_Docked == 1) && (LCD_Screen_Keypad_Menu == 1))         Print_LCD_Info_Docked();                                // Print information to the LCD screen
if ((Mower_Docked == 1) && (LCD_Screen_Keypad_Menu == 1))         Print_Time_On_LCD(); 
if ((Mower_Docked == 1) && (LCD_Screen_Keypad_Menu == 1))         Check_Membrane_Switch_Input_Docked();                   // Check the membrane buttons for any input
if ((Mower_Docked == 1) && (GPS_Enabled == 1))                    Check_GPS_In_Out();                                     // Get the GPS Signal In / Out of Fence                                
if (Mower_Docked == 1)                                            TestforBoundaryWire();                                  // Test is the boundary wire is live                                 
if (Mower_Docked == 1)                                            Manouver_Dock_The_Mower();
if (Mower_Docked == 1)                                            Print_Time_On_Serial_Monitor();
if (Mower_Docked == 1)                                            Display_Next_Alarm();
if (Mower_Docked == 1)                                            Activate_Alarms();
if ((Mower_Docked == 1) && (TFT_Screen_Menu == 1))                Send_Mower_Docked_Data();                               // Send Data to TFT Display


// Mower is Parked ready to be started / re-started / or the mower has no docking station enabled.
if ((Mower_Parked == 1) && (LCD_Screen_Keypad_Menu == 1))         Print_LCD_Volt_Info();                                  // Print the voltage to the LCD screen
if (Mower_Parked == 1)                                            Check_if_Charging();
if (Mower_Parked == 1)                                            Check_if_Raining_From_Nano ();                          // Checks if the water sensor detects Rain
if ((Mower_Parked == 1) && (LCD_Screen_Keypad_Menu == 1))         Print_LCD_Info_Parked();                                // Print information to the LCD screen
if ((Mower_Parked == 1) && (LCD_Screen_Keypad_Menu == 1))         Check_Membrane_Switch_Input_Parked();                   // Check the membrane buttons for any input
if ((Mower_Parked == 1) && (GPS_Enabled == 1))                    Check_GPS_In_Out();
if (Mower_Parked == 1)                                            TestforBoundaryWire();
if (Mower_Parked == 1)                                            Manouver_Park_The_Mower();
if ((Mower_Parked == 1) && (TFT_Screen_Menu == 1))                Send_Mower_Docked_Data();                               // Send Data to TFT Display


// Mower is Parked with Low Battery needing manuel charging
if ((Mower_Parked_Low_Batt == 1) && (LCD_Screen_Keypad_Menu == 1)) Print_LCD_Volt_Info();                                  // Print the battery voltage
if ((Mower_Parked_Low_Batt == 1) && (LCD_Screen_Keypad_Menu == 1)) Print_Recharge_LCD();                                   // Print re-charge on the LCD screen
if ((Mower_Parked_Low_Batt == 1) && (LCD_Screen_Keypad_Menu == 1)) Check_Membrane_Switch_Input_Parked();
// Lost mower is put into standby mode

if ((Mower_Error == 1)  && (LCD_Screen_Keypad_Menu == 1))         Print_Mower_Error();                     // Safety mode incase the mower is lostor in an error state
if ((Mower_Error == 1)  && (LCD_Screen_Keypad_Menu == 1))         Check_Membrane_Switch_Input_Parked();
if ((Mower_Error == 1)  && (TFT_Screen_Menu == 1))                Send_Mower_Error_Data();                               // Send Data to TFT Display


// Mower is running cutting the grass.
if ((Mower_Running == 1) && (LCD_Screen_Keypad_Menu == 1))                                                                Print_LCD_Volt_Info();              // Print the voltage to the LCD screen
if  (Mower_Running == 1)                                                                                                  Process_Volt_Information();         // Take action based on the voltage readings
if  (Mower_Running == 1)                                                                                                  Check_if_Raining_From_Nano();       // Test the rain sensor for rain. If detected sends the mower home
if ((Mower_Running == 1) && (LCD_Screen_Keypad_Menu == 1))                                                                Check_Membrane_Keys_Running();      // Check to see if the mower needs to be stopped via keypad
if  (Mower_Running == 1)                                                                                                  Check_Timed_Mow();                  // Check to see if the time to go home has come.
if  (Mower_Running == 1)                                                                                                  TestforBoundaryWire();              // Test is the boundary wire is live
if  (Mower_Running == 1)                                                                                                  Check_Tilt_Tip_Angle();             // Tests to see if the mower is overturned.
if ((Mower_Running == 1) && (Wire_Detected == 1))                                                                         Check_Wire_In_Out();                // Test if the mower is in or out of the wire fence.
if ((Mower_Running == 1) && (GPS_Enabled == 1))                                                                           Check_GPS_In_Out();                 // Test is the GPS Fence has been crossed
if ((Mower_Running == 1) && (Wire_Detected == 1) && (Outside_Wire == 0))                                                  Check_Sonar_Sensors();              // If the mower is  the boundary wire check the sonars for obsticles and prints to the LCD
if ((Mower_Running == 1) && (Wire_Detected == 1) && (Outside_Wire == 0) && (Sonar_Hit == 0))                              Manouver_Mow_The_Grass();           // Inputs to the wheel motors / blade motors according to surroundings 
if ((Mower_Running == 1) && (Wire_Detected == 1) && (Outside_Wire == 0) && (Sonar_Hit == 0))                              Check_Bumper();                     // If the mower is  the boundary wire check the Bumper for activation
if ((Mower_Running == 1) && (Wire_Detected == 1) && ((Outside_Wire == 1) || (Bumper == 1))  && (Loop_Cycle_Mowing > 0))   Manouver_Turn_Around();             // If the bumper is activated or the mower is outside the boundary wire turn around
if ((Mower_Running == 1) && (GPS_Enabled == 1) && (GPS_Inside_Fence == 0))                                                Manouver_Turn_Around();             // If the GPS Fence is activated Turn Around
if ((Mower_Running == 1) && (Wire_Detected == 1) && (Outside_Wire == 0) && (Sonar_Hit == 1))                              Manouver_Turn_Around_Sonar();       // If sonar hit is detected and mower is  the wire, manouver around obsticle 

// WIFI Commands from and to APP
if (Manuel_Mode == 1) Receive_WIFI_Manuel_Commands();
if (Manuel_Mode == 1) Print_LCD_Info_Manuel();
if ((WIFI_Enabled == 1) && (Manuel_Mode == 0)) Get_WIFI_Commands();                                   // TX and RX data from NodeMCU

Serial.println(); 
  
}  // End Loop

  
