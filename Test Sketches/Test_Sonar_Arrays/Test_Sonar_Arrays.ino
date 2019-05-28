 
/************************************************************************************
        SONAR TESTING SKETCH
     ==========================================

    This test sketch will check the installation of the Sonar Array.
    It is very important that the Sonar array works correctly.  1. to avoid stuff and 2. if the sonar is not working
    correctly it will increase the loop time of the software considerably.

    The software will wait for the sonar to ping.  If there is not return signal the software will wait around looking for it.
    This is not good for the performance of the mower.  It needs to detect wires etc immediatley.

    In the setup you can tuen on or off the individual sonars.

    LCD Displays following
    Sonar 2       Sonar 1         Sonar  3
    distance 2    distance 1      distance 3
    
    All OK
    ======
    If you place your hand in front of each sonar the distance decraeses on the correspoding LCD display
    this happens for all 3 sonars and the position of the sonar reading on the LCD corresponds to the sonar module
    being tested.

    Sonar registers but the LCD display changes in the wrong place.
    ===============================================================
    Your wiring is switched.  Pleaese check the Tri and Echo pins for each sonar are connected to the right PIN
    on the MEGA.  If you run like this the mower will turn into the obsticle its trying to avoid

    SONAR Reads 999
    ===============
    The sonar signal is not being read by the software.  
      Check wiring  (refernec diagram on the website)
      Check 5V is present at that sonar
      Check that Trig and Echo pins are not mixed up.

      

    


************************************************************************************/



/* Libraries Used
************************************************************************************/

/*Libraries for Perimeter Wire Receiver*/
#include <Arduino.h>
#include <Wire.h>
#include <EEPROM.h>

/*Libraries for ic2 Liquid Crystal*/
#include <LiquidCrystal_I2C.h>
//LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);    //LCD on test mower stand


/* Pin setup for Arduino MEGA
************************************************************************************/


/*Sonar Setup for Front Sonars 1-5*/
#define echoPin1 34   //S1               
#define trigPin1 35
#define echoPin2 36   //S2 
#define trigPin2 37
#define echoPin3 38   //S3
#define trigPin3 39


/***********************************************************************************
                       Global Variables
************************************************************************************/


/*Sonar Variables*/
long duration1 = 0;               // Time required for the sonar ping to be recieved by the echo pin.
long duration2 = 0;
long duration3 = 0;

int distance1 = 999;                    // Distance caculated  by the Sonar
int distance2 = 999;
int distance3 = 999;

long maxdistancesonar = 999;             // used to set the max distance before sonar is triggered to X
bool Mower_Stopped ;




/***********************************************************************************************

                   SETUP OF MOWER
                   ====================================

 ***********************************************************************************************/

 
  /* User defined parameters to switch on or off parts of the code depending on the Setup of the Mower
     Useful for testing e.g. to switch the blades off if testing indoors.
  ****************************************************************************************************/

  /*  1 = Turned ON      0 = Turned OFF       Value = Value set for variable.*/

  //Main settings for the Mower Operation

  bool Sonar_1_Activate           = 1;                          // Activate the Sonar #1 - More sonars = a slower loop time and slugish reactions but better obsticle avoidance.
  bool Sonar_2_Activate           = 1;                          // Activate the Sonar #2
  bool Sonar_3_Activate           = 1;                          // Activate the Sonar #3
  
  
  
  /************************************************************************************************************/

void setup() {
    //Setup is placed in a function so the setup can be ran once the Mower is docked 
    //to reset the board as best as possible to the beginning.

  /* Starts the Communication to the Serial Monitor baud 115200. */
  Serial.begin(115200);
  Serial.println("");
  Serial.println("          SETTING UP THE MOWER..... Please Wait ........");
  Serial.println("************************************************************");
  Serial.println(" ");
  lcd.begin(16, 2);
  lcd.print("SONAR TEST..");
  lcd.setCursor(0,1);
  lcd.print("S2     S1     S3");
  delay(2000);
  lcd.clear();



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


}

// END SETUP








/************************************************************************************************

                        THE LOOP

 ************************************************************************************************/

void loop() {

   Ping_Sonars();
          
  }     //End the Loop Bracket
