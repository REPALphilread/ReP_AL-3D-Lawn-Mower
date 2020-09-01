
/* Perimieter Wire Collision Motion
  ************************************************************************************/
  void Test_Mower_Check_Wire()  {
  
  ADCMan.run();
  // ADCMan.setCapture(pinPerimeterLeft, 1, 0);

  if (millis() >= nextTime)  {
    nextTime = millis() + 50;
    if (perimeter.isInside(0) != inside) {
      inside = perimeter.isInside(0);
      counter++;
    }
  }

  /* Prints Values to the Serial Monitor of mag, smag and signal quality.  */
  Serial.print(F("Inside (1) or Outside (0):  "));
  Serial.print((perimeter.isInside(0)));
  Serial.print(F("     MAG: "));
  Serial.print((int)perimeter.getMagnitude(0));
  Serial.print(F("    smag: "));
  Serial.print((int)perimeter.getSmoothMagnitude(0));
  Serial.print(F("     qaulity: "));
  Serial.println((perimeter.getFilterQuality(0)));


  
  lcd.setCursor(0,0);
  lcd.print("IN/Out:");
  lcd.setCursor(8,0);
  lcd.print(perimeter.isInside(0));
  lcd.setCursor(0,1);
  lcd.print("MAG:");
  lcd.setCursor(8,1);
  lcd.print(perimeter.getMagnitude(0)); 


}


void Test_Relay() {
  
  digitalWrite(Relay_Motors, HIGH);
  Serial.println("Relay OFF");
  lcd.print("Relay OFF");
  delay(1000);
  lcd.clear();
  digitalWrite(Relay_Motors, LOW);
  Serial.println("Relay ON");
  lcd.print("Relay ON");
  delay(1000);
  lcd.clear();
  digitalWrite(Relay_Motors, HIGH);
  Serial.println("Relay OFF");
  lcd.print("Relay OFF");

}



void Test_Wheel_Motors() {
  I = 1;
  Serial.println(F("Wheel Test Started"));
  digitalWrite(Relay_Motors, LOW);
  delay(200);
  if (I == 1) {

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Drive Wheel");
  lcd.setCursor(1,0);
  lcd.print("Test");
  delay(1000);
  lcd.clear();

  lcd.print("Remove ALL");
  lcd.setCursor(0,1);
  lcd.print("Blades!!!");
  delay(1000);
  lcd.clear();


  lcd.print("<-- Turn Left");
  delay(500);
  SetPins_ToTurnLeft();
  Motor_Action_Go_Full_Speed();
  delay(2000);
  Motor_Action_Stop_Motors();
  delay(500);
  lcd.clear();

  lcd.print("Turn Right -->");
  delay(500);
  SetPins_ToTurnRight();
  Motor_Action_Go_Full_Speed();
  delay(2000);
  Motor_Action_Stop_Motors();
  delay(500);
  lcd.clear();

  lcd.print("Forwards");
  delay(500);
  SetPins_ToGoForwards();
  Motor_Action_Go_Full_Speed();
  delay(2000);
  Motor_Action_Stop_Motors(); 
  delay(500);
  lcd.clear();

  lcd.print("Backwards");
  delay(500);
  SetPins_ToGoBackwards();   
  Motor_Action_Go_Full_Speed();
  delay(2000);
  Motor_Action_Stop_Motors();  
  delay(5000);
  lcd.clear();

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Dynamic");
  lcd.setCursor(0,1);
  PWM_Left = 150;
  PWM_Right = 150;
  lcd.print("L:");
  lcd.print(PWM_Left);
  lcd.print("  R:");
  lcd.print(PWM_Right);
  SetPins_ToGoForwards();
  Motor_Action_Dynamic_PWM_Steering();
  delay(2000);

  
  lcd.clear();
  lcd.setCursor(0,1);  
  PWM_Left = 255;
  PWM_Right = 0;
  lcd.print("L:");
  lcd.print(PWM_Left);
  lcd.print("  R:");
  lcd.print(PWM_Right);
  SetPins_ToGoForwards();
  Motor_Action_Dynamic_PWM_Steering();
  delay(2000);

  lcd.clear();
  lcd.setCursor(0,1);
  PWM_Left = 155;
  PWM_Right = 0;
  lcd.print("L:");
  lcd.print(PWM_Left);
  lcd.print("  R:");
  lcd.print(PWM_Right);
  SetPins_ToGoForwards();
  Motor_Action_Dynamic_PWM_Steering();
  delay(2000);


  lcd.clear();
  lcd.setCursor(0,1);  
  PWM_Left = 255;
  PWM_Right = 0;
  lcd.print("L:");
  lcd.print(PWM_Left);
  lcd.print("  R:");
  lcd.print(PWM_Right);
  SetPins_ToGoForwards();
  Motor_Action_Dynamic_PWM_Steering();
  delay(2000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Dynamic");
  lcd.setCursor(0,1);
  PWM_Left = 150;
  PWM_Right = 150;
  lcd.print("L:");
  lcd.print(PWM_Left);
  lcd.print("  R:");
  lcd.print(PWM_Right);
  SetPins_ToGoForwards();
  Motor_Action_Dynamic_PWM_Steering();
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0,1);
  PWM_Left = 0;
  PWM_Right = 255;
  lcd.print("L:");
  lcd.print(PWM_Left);
  lcd.print("  R:");
  lcd.print(PWM_Right);
  SetPins_ToGoForwards();
  Motor_Action_Dynamic_PWM_Steering();
  delay(2000);


  lcd.clear();
  lcd.setCursor(0,1);  
  PWM_Left = 0;
  PWM_Right = 155;
  lcd.print("L:");
  lcd.print(PWM_Left);
  lcd.print("  R:");
  lcd.print(PWM_Right);
  SetPins_ToGoForwards();
  Motor_Action_Dynamic_PWM_Steering();
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0,1);  
  PWM_Left = 0;
  PWM_Right = 255;
  lcd.print("L:");
  lcd.print(PWM_Left);
  lcd.print("  R:");
  lcd.print(PWM_Right);
  SetPins_ToGoForwards();
  Motor_Action_Dynamic_PWM_Steering();
  delay(2000);

  
  Motor_Action_Stop_Motors();  
  delay(1000);

  lcd.clear();
  lcd.print("Test Finished");
  delay(1000);
  lcd.clear();

  I = 2;
  }
  digitalWrite(Relay_Motors, HIGH);
  delay(200);

  Serial.println(F("Wheel Test Complete"));
}     



void Test_Mower_Blade_Motor() {
  // Spin the blade motor for 7 seconds
  digitalWrite(Relay_Motors, LOW);
  delay(200);
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
  delay(2000);
  lcd.print("BLADE MOTOR");
  delay(500);
  Serial.println("Blades ON");
  lcd.setCursor(0,1);
  lcd.print("ON ");
  lcd.setCursor(6,1);
  lcd.print("PWM =");
  lcd.print(PWM_Blade_Speed);
  Motor_Action_Spin_Blades();
  delay(7000);


  // Stop the blade motor spinning for 2 seconds
  lcd.clear();
  Serial.println("Blades OFF");
  lcd.print("BLADE MOTOR");
  lcd.setCursor(0,1);
  lcd.print("OFF..  ");
  Motor_Action_Stop_Spin_Blades();
  delay(2000);
  lcd.clear();
  delay(500);

  digitalWrite(Relay_Motors, HIGH);
  delay(200);

  }


void Test_Sonar_Array()   {

  //Clears the Trig Pin
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin3, LOW);


  /*Fires all Sonars to detect objects ahead...
   * Sonars are not fired in order to avoid reflections of sonar in the next sensor.
     distance# reurned (trigpin#, echopin#, distance#, duration#, Sonar#, LCDColumn#, LCD Row#)
   *********************************************************************************************/
    if (Sonar_1_Activate) distance1 = PingSonarY(trigPin1, echoPin1, 1, 1, 1, 5, 0);          //SONAR1
    delay(15);
    if (Sonar_2_Activate) distance2 = PingSonarY(trigPin2, echoPin2, 2, 2, 2, 0, 0);         //SONAR2
    delay(15);
    if (Sonar_3_Activate) distance3 = PingSonarY(trigPin3, echoPin3, 3, 3, 3, 10, 0);          //SONAR3
    delay(15);
  }





/* SONAR Function
************************************************************************************/
// Function to Ping the Sonar calculate the distance from Object to the Sonars.
// Distance calculated is printed to serial printer and displays X or _ on the LCD Screen
// Distance calculated is then used for the object avoidance logic
// Sonars used can be activated in the settings.

int PingSonarY(int trigPinY, int echoPinY, int distanceY, long durationY, int sonarY, int LCDRow, int LCDColumn) {
  pinMode(trigPinY, OUTPUT);
  pinMode(echoPinY, INPUT);
  //Sets the trigPin at High state for 10 micro secs sending a sound wave
  digitalWrite(trigPinY, HIGH);
  digitalWrite(trigPinY, LOW);
  delayMicroseconds(10);

  /*Reads the echoPin for the bounced wave and records the time in microseconds*/
  durationY = pulseIn(echoPinY, HIGH);

  /*Calculates the distance in cm based on the measured time*/
  distanceY = durationY * 0.034 / 2;
  delay(5);

  /* If a 0 distance is measured normally the Sonar ping has not been received.
    distance is then set to 999cm so the missed ping is not seen as an object detected.*/
  if (distanceY == 0) {
    distanceY = 999;
    Serial.print(F("SONAR "));
    Serial.print(sonarY);
    Serial.print(": ");
    Serial.println(F("NO PING ERROR REMOVED"));
  }

  /*Prints the Sonar letter and distance measured on the serial Monitor*/
  Serial.print(F("SONAR "));
  Serial.print(sonarY);
  Serial.print(": ");
  Serial.print(distanceY);
  Serial.println(F(" cm"));
  //Serial.println(maxdistancesonar);

  /*If sonar distance is less than maximum distance then an object is registered to avoid*/
  if (distanceY <= maxdistancesonar ) {
    //Prints that Sonar X has detected an object to the Mower LCD.
    lcd.setCursor(LCDRow, LCDColumn);                //sets location for text to be written
    lcd.print("X");
    LCDColumn = LCDColumn + 1;    
    lcd.setCursor(LCDRow, LCDColumn);                //sets location for text to be written
    lcd.print("   ");
    lcd.setCursor(LCDRow, LCDColumn);
    lcd.print(distanceY);
    delay(10);
  }

  /*If sonar distance is greater than maximum distance then no object is registered to avoid*/
  if (distanceY > 100) {
    //Prints that the path of Sonar X is open.
    LCDColumn = LCDColumn - 1;   
    lcd.setCursor(LCDRow, LCDColumn);                 //sets location for text to be written
    lcd.print("_");
    delay(10);
  }

  return distanceY;
  return sonarY;

}


void Test_Compass_Turn_Function() {
    digitalWrite(Relay_Motors, LOW);
    delay(200);
    SetPins_ToGoForwards();
    Motor_Action_Go_Full_Speed();
    delay(2000);
    Manouver_Turn_Around();
    Turn_To_Compass_Heading();
    SetPins_ToGoForwards();
    Motor_Action_Go_Full_Speed();
    delay(2000); 
    digitalWrite(Relay_Motors, HIGH);
    }
  
