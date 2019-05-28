
/* ReP_AL Mower Test Sketch
 -------------------------
 
 Ensure ALL the mower blades are removed for this test
 This sketch will test the fdunction of the Mower Motor controller and mower blade motor
 Please modify the I2C address of your LCD display to see the LCD infomation
 The sketch will spin the blade motor to the set PWM speed you set as PWM Blade Speed.
 After a few seconds the blade will stop and then restart.
 Please be careful remove all the blades from the cutting disc and ensure nothing is 
 underneath the mower which can be hit by the cutting disc or motor shaft   */


#include <Arduino.h>
#include <Wire.h>


/*Libraries for ic2 Liquid Crystal*/
#include <LiquidCrystal_I2C.h>
//LCD on test mower stand
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Mower 1
//LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);    //Mower 2


/*Motor Blades*/
#define RPWM 8
#define L_EN 9
#define R_EN 10

/*Relay Switches*/
#define Relay_Motors 24         // be careful that you really use PIN24.  The order is sometimes labelled
                                // so it looks like 24 is actually 22.

/*Motor Variables*/
byte PWM_Blade_Speed =  150;   // PWM signal sent to the blade motor (speed of blade) new motor works well at 245.
bool Blades_ON = 1;
 
  
  /************************************************************************************************************/

void setup() {

  // You can also view the test on the serial monitor
  Serial.begin(115200);

  // Set the relay on.
  // The relay needs to be working.  
  // to check this function run the relay test sketch
  pinMode(Relay_Motors, OUTPUT);
  delay(5);
  digitalWrite(Relay_Motors, LOW);
  delay(5);
  
  // Start the LCD
  lcd.begin(16, 2);
  lcd.clear();

  //Setup the mower motor Arduino Pins
  pinMode(L_EN, OUTPUT);
  pinMode(R_EN, OUTPUT);
  pinMode(RPWM, OUTPUT);


  // Welcome Screen on LCD
  lcd.print("Blade Motor");
  lcd.setCursor(0,1);
  lcd.print("Test..!!");
  delay(1000);
  lcd.clear();

  lcd.print("Remove ALL");
  lcd.setCursor(0,1);
  lcd.print("Blades!!!");
  delay(4000);
  lcd.clear();
  }



void loop() {
  // Spin the blade motor for 7 seconds
  lcd.print("BLADE MOTOR");
  delay(500);
  Serial.println("Blades ON");
  lcd.setCursor(0,1);
  lcd.print("ON ");
  lcd.setCursor(6,1);
  lcd.print("PWM =");
  lcd.print(PWM_Blade_Speed);
  Blades_ON = 1;
  SpinBlades();
  delay(7000);


  // Stop the blade motor spinning for 2 seconds
  lcd.clear();
  Serial.println("Blades OFF");
  lcd.print("BLADE MOTOR");
  lcd.setCursor(0,1);
  lcd.print("OFF..  ");
  StopSpinBlades();
  delay(2000);
  lcd.clear();
  delay(500);

  }
  
