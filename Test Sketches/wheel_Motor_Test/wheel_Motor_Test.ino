
#include <Arduino.h>
#include <Wire.h>
#include <EEPROM.h>


/*Libraries for ic2 Liquid Crystal*/
#include <LiquidCrystal_I2C.h>

//Update Your LCD I2C address here...!!

//LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Mower 1
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);    //Mower 2


/*Pin Setup for the wheel Motion L298N Dual H Bridge Motor Controller.*/
/*Motor A*/
#define ENAPin 7                // EN Pins need a digital pin with PWM
#define IN1Pin 6                // IN Pins dont need digital PWM 
#define IN2Pin 5
/*Motor B*/
#define ENBPin 2                // EN Pins need a digital pin with PWM
#define IN3Pin 4                // IN Pins dont need digital PWM
#define IN4Pin 3


/*Relay Switches*/
#define Relay_Motors 24         // be careful that you really use PIN24.  The order is sometimes labelled
                                // so it looks like 24 is actually 22.




/*Motor Variables*/
 bool Motors_ON = 1;
 int i = 1;
 int PWM_Right;
 int PWM_Left;


 bool Reverse_Steering           = 1;                          // Swap Left and Right Motor inputs (instead of reversing wiring on the motor bridge)
 byte PWM_MaxSpeed_LH            = 248;                        // Straight line speed LH Wheel (Looking from back of mower)
 byte PWM_MaxSpeed_RH            = 255;                        // Straight line speed RH Wheel - adjust to keep mower tracking straight.
 byte PWM_Blade_Speed            = 245;                        // PWM signal sent to the blade motor (speed of blade) new motor works well at 245.

 
  
  /************************************************************************************************************/

void setup() {

  // Set the relay on.
  pinMode(Relay_Motors, OUTPUT);
  delay(5);
  digitalWrite(Relay_Motors, LOW);
  delay(5);
  lcd.begin(16, 2);
  lcd.clear();


  /*Sets up the wheel motor Pins*/
  pinMode(ENAPin, OUTPUT);
  pinMode(ENBPin, OUTPUT);
  pinMode(IN1Pin, OUTPUT);
  pinMode(IN2Pin, OUTPUT);
  pinMode(IN3Pin, OUTPUT);
  pinMode(IN4Pin, OUTPUT);



}

// END SETUP


void loop() {

  
  if (i == 1) {

  lcd.print("Drive Wheel");
  lcd.setCursor(1,0);
  lcd.print("Test");
  delay(2000);
  lcd.clear();

  lcd.print("Remove ALL");
  lcd.setCursor(0,1);
  lcd.print("Blades!!!");
  delay(2000);
  lcd.clear();


  lcd.print("<-- Turn Left");
  delay(500);
  SetPins_ToTurnLeft();
  Motion_GoFullSpeed();
  delay(1000);
  Motion_StopMotors(); 
  delay(1000);
  lcd.clear();

  lcd.print("Turn Right -->");
  delay(500);
  SetPins_ToTurnRight();
  Motion_GoFullSpeed();
  delay(2000);
  Motion_StopMotors(); 
  delay(1000);
  lcd.clear();

  lcd.print("Forwards");
  delay(500);
  SetPins_ToGoForwards();
  Motion_GoFullSpeed();
  delay(1000);
  Motion_StopMotors(); 
  delay(1000);
  lcd.clear();

  lcd.print("Backwards");
  delay(500);
  SetPins_ToGoBackwards();   
  Motion_GoFullSpeed();
  delay(1000);
  Motion_StopMotors(); 
  delay(1000);
  lcd.clear();

  lcd.print("Test Finished");

  i = 2;
  }
  }     //End the Loop Bracket
