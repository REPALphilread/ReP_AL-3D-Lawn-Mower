  
// ReP_AL GPs Fence Software
// The GPS fence can be defined in the YGPS XGPS Arrays on the TAB GPS_Fence_Coordinates
// Additonal Array points can be added or deleted to create the fence data.
// Please set the GPSMAX value to last array point value
// e.g. Array Points 0-22, GPDMAX = 22.

#include <EEPROM.h>
#include <TinyGPS++.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <HardwareSerial.h>

#define EEPROM_SIZE 512

// Signal Outpin for GPS Fence.
#define GPS_Signal_Pin 26   // GPIO14   INSIDE OUTSIDE FENCE
#define GPS_Lock_Pin 27     // GPIO27   GPS LOCK SIGNAL


#define RX 13    // GPIO13   
#define TX 14    // GPIO12   

HardwareSerial TFT_Serial(1);

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "BLYNK Auth Code";      //Input your Blank Auth Code here.


// Your WiFi credentials. Set password to "" for open networks.
char ssid[] = "WIFI Name";
char pass[] = "WIFI Password";



BlynkTimer timer;
WidgetMap myMap(V1);

// on various boards the LED Pin is different.....
#define LED 2      

// The TinyGPS++ object
TinyGPSPlus gps;

//Special Data Request
TinyGPSCustom FIX(gps, "GPGGA", 6); // $GPGGA sentence, 6th element



// Define the GPS Array to build the fence.
// **********************************************************************************************
#define GPS_Array 90       // Set GPS_Array value to GPSMAX + 1      e.g. GPSY[20] GPS_Array = 21
// **********************************************************************************************




int     GPSMAX;
int     GPSMAX2;

// Arrays are autoamtcially set depending on GPS_Array value defined.
double      GPSX[GPS_Array];                             
double      GPSY[GPS_Array];
double GPSX_Plot[GPS_Array];
double GPSY_Plot[GPS_Array];
int     Boundary[GPS_Array];
double    deltaX[GPS_Array];
double    deltaY[GPS_Array];
double  deltaY_d[GPS_Array];
double      YMYG[GPS_Array];
double        XG[GPS_Array];
double        YG[GPS_Array];
double         n[GPS_Array];
double        XP[GPS_Array];
double        XL[GPS_Array];
double        YL[GPS_Array];
int GPS_Equation[GPS_Array];
int       IN_OUT[GPS_Array];

double X_GPS;
double Y_GPS;

//Fence 6 Data
double      GPSY6[100];
double      GPSX6[100];   

double      GPSY_EEPROM[50];
double      GPSX_EEPROM[50];
int         Fence_Point_EEPROM[50];
int         Boundary_EEPROM[50];

// Calculate range of the incoming values.
double Y_GPS_Range_Values[20];
double X_GPS_Range_Values[20];
double Y_GPS_Range_Max;
double Y_GPS_Range_Min;
double X_GPS_Range_Max;
double X_GPS_Range_Min;

double Y_GPS_Accuracy;
double X_GPS_Accuracy;

bool Range_Go;

int GPS_Cycles = 0;

float  d = 0.000001;

double XL_Q;
double Y_GPS_Q;
double GPS_QX0;
double GPS_QX1;
double GPS_QY0;
double GPS_QY1;
int    Boundary_Q;
int    IN_OUT_Q;

int   print_g;
float print_GPSX;
float print_GPSY;
float print_deltaX;
float print_deltaY;
float print_deltaYd;
float print_YMYG;
float print_XG;
float print_YG;
float print_n;
float print_XP;
float print_YL;
float print_XL;
int   print_IN_OUT;
int   print_Line_Type;
int   print_boundary;
bool  Run_Loop = 0;

double Min_X_GPS_Point;
double Min_Y_GPS_Point;
double Max_X_GPS_Point;
double Max_Y_GPS_Point;

bool  GPS_Lock;
int   Mower_In_Out; 
int   Sats;
int   Blynk_Update_Frequecy;
int   bounce = 1;
int   bounce_back = 0; 
int   First_Plot = 1;
bool  GPS_Locked;
unsigned long FIXED;

float Y_Rng_cm;
float X_Rng_cm;

//Membrane Key Variables
byte  Start_Key_X;
byte  Plus_Key_X;
byte  Minus_Key_X; 
byte  Stop_Key_X;
int   Max_Options_Options;
int   Max_Options_Settings;
byte  Menu_Mode_Selection;
int   Menu_View;
bool  Menu_Complete;
bool  Menu_Complete_Fence;
bool  Menu_Complete_Fence_Edit;
bool  Menu_Complete_Settings;

// Capture Fence Points
int Fence_Point;
int Fence_Type_Create;
int address;
long value;

// Boundary EEPROM Conditions
int Start_Fence;
int End_Fence;
int Max_Fence;
int RXCode;

// TFT Communications
int TFT_Menu_Command = 99;     // 99 is the initial setting to avoid any bad data transfers.
int Menu_Complete_TFT;

int Spare = 5;




// ReP_AL GPS Fence Arduino Sketch Settings
//-------------------------------------------------


bool  GPS_WIFI_Enabled    = 1;    // Activate the WIFI on the NodeMCU board.
int   GPS_BAUD            = 2;    // 1 = 9600 2 = 19200
bool  Show_GPS_Fence      = 1;    // Renders/Plots the coordinates of the GPS Fence onto the Blynk Smartphone APP.
int   GPS_Fence_Update    = 500;  // Loops run before the GPS fence data is re-rendered on the smartphone APP
bool  Simulation_Mode     = 0;    // Simulates the movement of a mower within the GPS fence to test the boundary conditions and GPS points (1 ON  0 OFF)
                                  // In simulation mode the Satellites text box is used to show the movement condition.
int   BUF                 = 2;    // Blynk Update Frequency - How often the Blynk APP is updated (flashes) with new information.  
                                  // Sketch will continue to run in the backgroun. For a small garden use 5. for a large area use 15                                  
bool  Sim_Mower_Moves     = 1;    // Simulates random movements of the mower.  If 0 just the actual static X Y coordinates will be calculated.                                
bool  Print_Full_Report   = 0;    // Every loop a full report of every GPS fence point is printed.
int   Fence               = 3;    // More than 1 GPS fence coordinate array can be saved in the GPS_Fence_Data tab.  For each additonal GPS fence Data use the next 
                                  // consecutive number.
int   Min_Sats            = 11;   // Minimum number of locked Sattellites to start mower navigation.  Otherwise the mower will stop and wait. recommended min 11
bool  Print_Summary_Fence = 0;    // Prints the fence summary to determine where the mower is in or out of the fence in the Serial monitor
bool  Print_GPS_Fix_cm    = 1;    // Prints the range of movement of the GPS Signal in the last 10 readings. - Useful to see if the module is accurate when left in one positionint 
int   GPS_Delay           = 1000; // Time between GPs readings

void setup()
{

EEPROM.begin(EEPROM_SIZE);                                                      // Initialises the EEPOM - required on ESP32 Boards...
Serial.begin    (115200);                                                       // Start the Arduino Serial monitor at this BAUD rate
if (GPS_BAUD == 1) Serial2.begin(9600);                 // Start connection using UART2 to the GPS Device at this BAUD rate
if (GPS_BAUD == 2) Serial2.begin(19200);                // Start connection using UART2 to the GPS Device at this BAUD rate
//Serial1.begin(9600); 
TFT_Serial.begin(9600, SERIAL_8N1, RX, TX);// Start the TFT Touchscreen communication Serial                                                                
pinMode(LED, OUTPUT);
delay(100);

// Set the signal Pins
pinMode(GPS_Signal_Pin, OUTPUT);
pinMode(GPS_Lock_Pin, OUTPUT);

//Clear_EEPROM();
Activate_EEPROM_Seetings();                                                   // Reads in the settings for the EEPROM to override the standard setup with the user setup
Activate_GPS_Fence();
if (GPS_WIFI_Enabled == true) {
  Set_Mode_ESP32_WIFI();
  WIFI_Connect();
}

}



void loop() {

Check_TFT_Serial_Input();                                 // Check the TFT Serial for any input command.
if (TFT_Menu_Command < 50)    Activate_TFT_Menu();        // If TFT Menu has requested an input, TX or RX that input.
  
if (Simulation_Mode == 0)  {
  

  Read_GPS_Data();

  // If enough Satellites are detected pull the Lat and Long Coordinates from the module and test if
  // the mower is In(1) or Out(0) of the fence 
  if (gps.satellites.value() >= Min_Sats) {
    GPS_Locked = 1;
    Y_GPS = gps.location.lat();    
    X_GPS = gps.location.lng();
    Sats    = gps.satellites.value();
    Calculate_GPS_Accuracy();
    Calculate_GPS_Data();
    Calculate_X_Projected();
    Calculate_Y_Limited();
    Calculate_X_Limited();
    Calculate_IN_OUT();
    Set_Output_Pins();
    if (Print_Full_Report == 1) Print_X_Y_Max_Min();
    if (Print_Full_Report == 1) Print_Initial_Information();
    Print_Running_Loop_Data();
    if (GPS_WIFI_Enabled == 0) Serial.println("");   // just starts a new line if the WIFI function is not called.
    }

  // If not enough satellites are detected then wait.
  if (gps.satellites.value() < Min_Sats) {
    Serial.print(F("NO GPS Lock|"));
    GPS_Locked = 0;
    Y_GPS = gps.location.lat();    
    X_GPS = gps.location.lng();
    Sats    = gps.satellites.value();
    Print_No_Lock_Data();
    Mower_In_Out = 0;
    GPS_Cycles = 0;
    Set_Output_Pins();
    if (GPS_WIFI_Enabled == 0) Serial.println("");   // just starts a new line if the WIFI function is not called.
    }
  }


 // Simulate the mower within the given GPS fence
 if (Simulation_Mode == 1) {
    Sats    = 0;    
    if (Sim_Mower_Moves == 1) Simulate_Mower_Movements();    //Simulates movement of the mower in different directions
    Calculate_GPS_Data();
    Calculate_X_Projected();
    Calculate_Y_Limited();
    Calculate_X_Limited();
    Calculate_IN_OUT();
    //Plot_GPS_Logic_Limits();
    if (Print_Full_Report == 1) Print_X_Y_Max_Min();
    if (Print_Full_Report == 1) Print_Initial_Information();
    Sats = bounce;
    Serial.print(F("Mower In/Out = "));
    Serial.print(Mower_In_Out);
    if (GPS_WIFI_Enabled == 0) Serial.println("");   // just starts a new line if the WIFI function is not called.
    }
    
if (GPS_WIFI_Enabled == true) {

  // Update the Blynk APP at the frequency given by BUF
  if ((Blynk_Update_Frequecy == BUF) || (Mower_In_Out ==0) ) { 
    Run_Blynk_Data();  
    Serial.print("  Blynk APP updated");
    Blynk_Update_Frequecy = 0;
    }
   
  // Update the Blynk APP. 
  Blynk_Update_Frequecy = Blynk_Update_Frequecy + 1;
  Serial.println("");
  }


    
  
}
