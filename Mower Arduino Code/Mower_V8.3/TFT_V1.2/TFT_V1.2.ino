// ReP_AL Mower Project Touchscreen Control




#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;
#include <TouchScreen.h>
#include <SPI.h>             // f.k. for Arduino-1.5.2
#define USE_SDFAT
#include <SdFat.h>           // Use the SdFat library
SdFatSoftSpi<12, 11, 13> SD; //Bit-Bang on the Shield pins
#include <EEPROM.h>
#include <ArduinoJson.h>
  
#define MINPRESSURE 485             // if multiple buttons are pressing increase this value
#define MAXPRESSURE 1000

#define SD_CS     10
#define NAMEMATCH ""         // "" matches any name
//#define NAMEMATCH "tiger"    // *tiger*.bmp
#define PALETTEDEPTH   8     // support 256-colour Palette
#define BMPIMAGEOFFSET 54
#define BUFFPIXEL      20

char namebuf[32] = "/";   //BMP files in root directory
//char namebuf[32] = "/bitmaps/";  //BMP directory e.g. files in /bitmaps/*.bmp

File root;
int pathlen;

#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSans12pt7b.h>
#include <Fonts/FreeSerif12pt7b.h>

#include <FreeDefaultFonts.h>


// ALL Touch panels and wiring is DIFFERENT
// copy-paste results from TouchScreen_Calibr_native.ino
const int XP = 8, XM = A2, YP = A3, YM = 9; //ID=0x9341

//const int TS_LEFT = 133, TS_RT = 921, TS_TOP = 964, TS_BOT = 91;   // if the LCD orientation is changed these also need to be changed
const int TS_LEFT = 960, TS_RT = 94, TS_TOP = 910, TS_BOT = 108; 


// Set the PIN OUTS for the Touch Screen Shield.
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

// declare all of the buttons to draw on the screen
Adafruit_GFX_Button up1_btn, down1_btn, up2_btn, down2_btn, up3_btn, down3_btn, up4_btn, down4_btn, up5_btn, down5_btn, up6_btn, down6_btn, 
                    up7_btn, down7_btn, up8_btn, down8_btn, Quick_S_btn, Exit_Dock_btn, Options_btn, Save_btn, Go_Now_btn, hr1_btn, hr2_btn, 
                    Max_Mow_btn, Cancel_btn, Zone1_btn, Zone2_btn, Mow_Line_btn, Stop_btn, Restart_btn, Go_Home_btn, Park_btn,
                    Time_btn, Sensors_btn, Motion_btn, Tracking_btn, Navigation_btn, Done_btn, Sonar_btn, Battery_btn, Wire_btn, Rain_btn,
                    WIFI_btn, Bumper_btn, ONOFF1_btn, ONOFF2_btn, ONOFF3_btn, Done2_btn, Blade_ONOFF_btn, Wheels_btn, Blade_btn, Pattern_btn,
                    Save_Blade_btn, Save_Wheels_btn, Movement_btn, Save_Movement_btn, Save_Tracking_Exit_btn, Done_Tracking_btn, Exit_Point_btn,
                    Find_Wire_btn, Track_PID_btn, Dock_ONOFF_btn, Spare_btn, Save_Tracking_btn, Tracking_Rotation_btn, Compass_ONOFF_btn,
                    Save_Track_Find_Wire_btn, Save_Track_PID_btn, Done_Navigation_btn, HeadHold_btn, PCompass_btn, GPS_btn, Alarm1_btn,
                    Alarm2_btn, Alarm3_btn, SetTime_btn, Done_Time_btn, Save_AlarmX_btn, Save_Set_Time_btn, Next_btn, TFT_btn, Done3_btn, 
                    Tests_btn, Test1_btn, Test2_btn, Test3_btn, Test4_btn, Test5_btn, Done4_btn, Cancel_QG_btn, Cancel_ED_btn, Clear_Error_btn,
                    Tip_btn, Done5_btn, Done6_btn, Tilt_Test_btn, Create_Fence_btn, GPS_Enabled_ONOFF_btn, Save_GPS_Point_btn, Save_Fence_btn;
                    

unsigned long time;
long Minutes_Passed;

int   pixel_x, pixel_y;     //Touch_getXY() updates global vars
bool  down;
int   Loop = 0;
bool  Menu_Complete;
bool  Menu_Complete_2;
bool  Menu_Complete_Main;
bool  Menu_Complete_Mowing;
bool  Menu_Complete_TFT_Setup;
bool  Menu_Complete_Settings;
bool  Menu_Complete_Settings_2;
bool  Menu_Complete_Settings_3;
bool  Menu_Complete_Stop;
bool  Menu_Complete_Motion;
bool  Menu_Complete_Sensors;
bool  Menu_Complete_Sensors_2;
bool  Menu_Complete_Sonar;
bool  Menu_Complete_Battery;
bool  Menu_Complete_Rain;
bool  Menu_Complete_Wheels;
bool  Menu_Complete_Blade;
bool  Menu_Complete_Movement;
bool  Menu_Complete_Tracking;
bool  Menu_Complete_Tracking_Exit;
bool  Menu_Complete_Track_PID;
bool  Menu_Complete_Find_Wire;
bool  Menu_Complete_GPS_Settings;
bool  Menu_Complete_Navigation;
bool  Menu_Complete_Time;
bool  Menu_Complete_AlarmX;
bool  Menu_Complete_Set_Time;
bool  Menu_Complete_Tests;
bool  Menu_Complete_Testing_2;
bool  Menu_Complete_Testing_3;
bool  Menu_Complete_Wire_Test;
bool  Menu_Complete_Sonar_Test;
bool  Menu_Complete_Compass_Test;
bool  Menu_Complete_Volt_Amp_Test;
bool  Menu_Complete_Tilt_Test;
bool  Menu_Complete_Bumper_Test;
bool  Menu_Complete_Quick_Start;
bool  Menu_Complete_Exit_Dock;
bool  Menu_Complete_Tip_Setup;
bool  Menu_Complete_Pattern;
bool  Menu_Complete_GPS_New_Fence;


int  Mower_Status_Value = 1;
int  Mower_Error_Value = 0;

// Docking
bool Docking_Complete;
bool Turn_To_Home;
bool Find_Wire_Track;
bool Go_To_Charging_Station; 
int Charging;

// Mower Running Data
int Sonar_Status;
int Wire_Status;
int Bumper_Status;
int Loops;
int Compass_Steering_Status;
int GPS_In_Out_TX = 1;

// TX Selected Menu Transmission
bool Quick_Go;
bool Exit_Dock;
bool Options;

// Sonar
int distance1;
int distance2;
int distance3;
int Wire_Sensor_Count;
int Sonar_Test_Cycles;

// Bumper
bool Bump_LH;
bool Bump_RH;

//Compass
int   Compass_Heading_Degrees;
float   Heading;


// Motor Menu

int PWM_MaxSpeed_LH;
int PWM_MaxSpeed_RH;
int PWM_Slow_Speed_LH;
int PWM_Slow_Speed_RH;
int Slow_Speed_MAG;
float Bar_Height;
float Gauge_Level_LH_Full;
float Gauge_Level_RH_Full;
float Gauge_Level_LH_Wire;
float Gauge_Level_RH_Wire;
float Gauge_Level_LH_Slow;
float Gauge_Level_RH_Slow;

int Bar_Pos_X;                                 
int Bar_Pos_Y; 
int Bar_Width;
int Button_W;
int LH_RH_Spacing;


//Tracking
  bool Use_Charging_Station;       
  bool CW_Tracking_To_Charge;      
  bool CCW_Tracking_To_Charge;     
  bool CW_Tracking_To_Start;   
  bool CCW_Tracking_To_Start;
  int Track_Wire_Zone_1_Cycles;
  int Track_Wire_Zone_2_Cycles;
  int  Max_Tracking_Turn_Right;
  int  Max_Tracking_Turn_Left; 
  int  Max_Cycle_Wire_Find;    
  int  Max_Cycle_Wire_Find_Back;    
  int  Home_Wire_Compass_Heading;
  float P;  
  
  bool Compass_Activate;
  bool Compass_Heading_Hold_Enabled;
  float CPower;


  int Pos_X1;
  int Pos_Y1;

  int Pos_X2;
  int Pos_Y2;
  int Pos_X3;
  int Pos_Y3;
  int Pos_X4;
  int Pos_Y4;  
  int Pos_X5;
  int Pos_Y5;  
  int Button_X1;
  int Button_Y1;
  int Button_X2;
  int Button_Y2;
  int Button_X3;
  int Button_Y3;
  int Button_X4;
  int Button_Y4;
  int Button_X5;
  int Button_Y5;
  
// Blade Menu
bool Cutting_Blades_Activate;
float Gauge_Level_Blade;
int PWM_Blade_Speed;

int  Menu_Active;

int Command_Check;
int Transmission_OK;

// Sonar RX TX Values
bool Sonar_1_Activate;
bool Sonar_2_Activate;
bool Sonar_3_Activate;
int  Max_Sonar_Hit;
int  maxdistancesonar;

// Battery RX TX Values
float Battery;
float Battery_Last;
float Battery_Max; 
float Battery_Min; 
float Volts;
float Amps;
byte  Low_Battery_Instances_Chg;

// Rain RX TX Values
bool Rain_Sensor_Installed;  
int  Rain_Total_Hits_Go_Home;

//Wire WIFI RX TX Values
bool Perimeter_Wire_Enabled;
bool WIFI_Enabled;
bool Bumper_Activate_Frnt;

// Wire Sensor
int INOUT;
int MAG;

// Tilt Sensor
bool Tilt_Angle_Sensed = 1;
bool Tilt_Orientation_Sensed;
int  Angle_Sensor_Enabled;
int  Tip_Over_Sensor_Enabled;

// Movement

int Mower_Turn_Delay_Min;
int Mower_Turn_Delay_Max;
int Mower_Reverse_Delay;
int Max_Cycles_Straight;
int Label_X;
int Label_Y;
int Offset_Btn;

// Pattern_Mow
int Pattern_Mow;

int Turn_90_Delay_LH;           // adjust this number so the mower turns 90° Left
int Turn_90_Delay_RH;           // adjust this number so the mower turns 90° Right
int Move_to_next_line_delay;    // distance between lines
int Line_Length_Cycles;         // length of the line mowed
int Max_Cycles_Spirals;
float Compass_Mow_Direction;

// Exit Dock
int  Exit_Zone;
int  Mow_Time;

int   Value_1;
int   Value_2;
int   Value_3;
int   Value_4;
int   Value_5;
int   Value_6;
int   Value_7;
int   Value_8;


int   Value_All;
float Value_All_Float;
int   Value_X_All;
int   Value_Y_All;
int   Int_Float;

int   Txt_Size_Value;

// Position of the input value in the menu
int   Value_X1;
int   Value_Y1;
int   Value_X2;
int   Value_Y2;
int   Value_X3;
int   Value_Y3;
int   Value_X4;
int   Value_Y4;
int   Value_X5;
int   Value_Y5;
int   Value_X6;
int   Value_Y6;
int   Value_X7;
int   Value_Y7;
int   Value_X8;
int   Value_Y8;

// Time

  int  Alarm_X_Selected;
  bool Alarm_X_ON;                 
  int  Alarm_X_Hour;               
  int  Alarm_X_Minute;             
  bool Alarm_X_Repeat;                
  int  Alarm_X_Action = 1;

  bool Alarm_1_ON;                 
  int  Alarm_1_Hour;               
  int  Alarm_1_Minute;             
  bool Alarm_1_Repeat;                
  int  Alarm_1_Action; 


  bool Alarm_2_ON;                 
  int  Alarm_2_Hour;               
  int  Alarm_2_Minute;             
  bool Alarm_2_Repeat;                
  int  Alarm_2_Action; 

  bool Alarm_3_ON;                 
  int  Alarm_3_Hour;               
  int  Alarm_3_Minute;             
  bool Alarm_3_Repeat;                
  int  Alarm_3_Action; 

  int  Time_Hour;
  int  Time_Minute;
  int  Time_Hour_Last;
  int  Time_Minute_Last;
  int  Time_Loop = 1;


  int Spare = 0;

// GPS Menu

  bool  GPS_Enabled;
  int   GPS_Mode = 0;
  int   Fence = 0;
  int   Min_Sats = 0;
  int   GPS_Lock_OK_TX;


// Set the screen size, calibration
bool Touch_getXY(void) {
    TSPoint p = ts.getPoint();
    pinMode(YP, OUTPUT);      //restore shared pins
    pinMode(XM, OUTPUT);
    digitalWrite(YP, HIGH);   //because TFT control pins
    digitalWrite(XM, HIGH);
    bool pressed = (p.z > MINPRESSURE && p.z < MAXPRESSURE);
    if (pressed) {
        
        //Use this setting for portrait
        //pixel_x = map(p.x, TS_LEFT, TS_RT, 0, tft.width()); //.kbv makes sense to me
        //pixel_y = map(p.y, TS_TOP, TS_BOT, 0, tft.height());
        
        // Use this setting for Landscape
        pixel_x = map(p.y, TS_LEFT, TS_RT, 490, 0); //.kbv makes sense to me
        pixel_y = map(p.x, TS_TOP, TS_BOT, 320, 0);
    
    }
    return pressed;
}

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define GREY    0x8410

// SETTINGS
//*****************************

bool Draw_Pictures = 1;
int  Delay_Transmit = 600;
int  Receive_Values_Delay = 750;
int  Battery_Display = 2;

void setup(void){

    Serial.begin(115200);         // Start the serial monitor
    Serial1.begin(9600);          // 9600 Start the serial for transmitting the commands to the main MEGA on the mower
    Serial2.begin(9600);          // Start the serial to communicate with the GPS NodeMCU board
    uint16_t ID = tft.readID();
    Serial.print(F("TFT ID = 0x"));
    Serial.println(ID, HEX);
    Serial.println(F("ReP_AL Mower Touchscreen"));
    Serial.println(F("Please Wait....."));
    if (ID == 0xD3D3) ID = 0x9486; // write-only shield
    tft.begin(ID);
    //tft.setRotation(1); 
    tft.setRotation(3);            //0 = PORTRAIT USB Top Right   1 = Landscape USB TL   2 =    Portrait USB BL    3 = Landacape USB  BR
    tft.fillScreen(BLACK);
    Load_EEPROM_Values();           // Load saved settings on TFT MEGA

    bool good = SD.begin(SD_CS);
    if (!good) {
        Serial.print(F("cannot start SD"));
      tft.setTextSize(3); 
      tft.setTextColor(GREEN, BLACK);           // Text Colour/ Background Colour
      tft.setCursor(50, 100); 
      tft.println("SD Card Missing ?");
      delay(2000);
      while (1);
    }


tft.setTextSize(2); 
tft.setTextColor(GREEN, BLACK);           // Text Colour/ Background Colour
tft.setCursor(0, 0);                      // Text Coordinates X, Y
tft.println("REP_AL Robot Lawn Mower");
tft.println(" ");
tft.println("STARTING TFT MENU");
tft.println("PLEASE WAIT....");
tft.println(" ");

bmpDraw("logo.bmp", 75, 80);
delay(4000);
Get_Initial_Values();
delay(3000);
tft.fillScreen(BLACK);


}  


void loop() {


// Mower is in the Docked Status
//*************************************************************************************************
if ((Mower_Status_Value == 1) || (Mower_Status_Value ==2)) {
    if (Mower_Status_Value == 1) Serial.println(F("Mower is Docked"));
    if (Mower_Status_Value == 2) Serial.println(F("Mower is Parked"));
    if (Draw_Pictures == 1) bmpDraw("mower1.bmp", 150, 90);      //Draw the mower picture
    delay(100);
    Print_Main_Menu_Graphic();
    Check_For_Active_Alarms();       
    Menu_Complete_Main = false;

    // Loop this code until the touchscreen is pressed
    while (Menu_Complete_Main == false) {
                  
              Receive_Docked_Data();     //  Recieve the dock data from the MEGA
              Calculate_TFT_Time();
              Print_Time_TFT();
              if (Battery > 8 ) Print_Battery_Graphic();                                                                //  Print the volts.
              Print_Error_Messages_Docked();
              Print_Mower_Status();
              
          // Wait a while to see if the TFT screen is touched.  (3100 Good)
          for (int i=0;  i<=500;  i++) {
              Sense_Button_Press_Main();
              React_to_Button_Press_Main();
              }  
          
          if ((Mower_Status_Value > 2) && (Mower_Status_Value != 0)) {
              Serial.println(F("Mower Status Command Received"));
              Menu_Complete_Main = true;  //  Break the while loop if the mower is not docked anymore but not for a missed RX = 0
              }

          }
    
    tft.fillScreen(BLACK);
    }

//Mower is in an Error State.
//*************************************************************************************************
if (Mower_Status_Value == 4) {
    Serial.println(F("Mower is in Error State"));
    Print_Confirmation_Text_ERROR(); 
    // Print Clear Error Button
    // Clear_Error_btn.initButton(&tft, 400, 260, 100, 60, WHITE, CYAN, BLACK, "CLEAR", 2);
    // Clear_Error_btn.drawButton(false);
    
    while (Mower_Status_Value== 4) {      
          Receive_Error_Data();
          Print_Confirmation_Text_ERROR();                                               
          for (int i=0;  i<=600;  i++) {
              Sense_Button_Press_Errors();
              React_to_Button_Press_Errors();
              }
          }
    tft.fillScreen(BLACK);
    }


// Mower is Running and Mowing the Lawn
//*************************************************************************************************
if (Mower_Status_Value == 5) {
    Serial.println(F("Mower is Mowing"));
    Menu_Complete_Mowing = false;
    Loop = 0;
    Print_Mowing_Menu_Graphic();

    // Actions to continously monitor while mowing
    while (Menu_Complete_Mowing == false) { 
        Clear_TFT_Loop_Info_Mowing();                 // Clear the last Loop Value
        Receive_Mower_Running_Data();                 // Large update when mower is stopped
        if (Battery > 8 ) Print_Battery_Graphic();             
        Update_TFT_Loop_Info_Mowing();                // Print the new Loop value
        Update_TFT_Mower_Messages_Mowing();  
        //Receive_Mower_Running_Data_Fly();             // Small Update
        if ((Mower_Status_Value != 5) && (Mower_Status_Value != 0))  Menu_Complete_Mowing = true;
     
        // Give time for the touch screen to sense the STOP button being pressed
        for (int i=0;  i<=1500;  i++) {
            Sense_Button_Press_Mowing();
            React_to_Button_Press_Mowing();
            }
          
      }
  tft.fillScreen(BLACK);
  }


//Mower is Tracking Home
//*************************************************************************************************
if (Mower_Status_Value == 7) {
    Serial.println(F("Mower is Tracking"));
    Print_Menu_Docking_Screen();
    
    while (Docking_Complete == false) {
       Receive_Mower_Tracking_Data();
       delay(200);
       Print_Docking_Stage();      
       }
  tft.fillScreen(BLACK);
 }

//Mower is Exiting Dock
//*************************************************************************************************
if (Mower_Status_Value == 9) {
    Serial.println(F("Mower is Exiting the Dock")); 
    while (Mower_Status_Value == 9) {          
          Receive_Mower_Tracking_Data();
          Print_Confirmation_Text_Exit_Dock(); 
          }
    tft.fillScreen(BLACK);
    }



 }
