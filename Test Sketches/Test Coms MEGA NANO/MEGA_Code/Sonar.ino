void Ping_Sonars()   {

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

  if ((Error == 0 ) && (Mower_Docked == 0)) {                                        // If no error is in effect then use the Sonars
    delay(15);
    if (Sonar_1_Activate == 1) distance1 = PingSonarX(trigPin1, echoPin1, 1, 1, 1, 1, 0);          //SONAR1
    delay(15);

    if (Sonar_2_Activate == 1) distance2 = PingSonarX(trigPin2, echoPin2, 2, 2, 2, 0, 0);         //SONAR2
    delay(15);

    if (Sonar_3_Activate == 1) distance3 = PingSonarX(trigPin3, echoPin3, 3, 3, 3, 2, 0);          //SONAR3
    delay(15);

  }


  if ((Error > 0) || (Mower_Docked == 1) ) {             // when an Error code is in effect, this stops the mower from moving due to the sonars being triggered
    distance1 = 999;                                  // distances are just set to a high number so they are not triggered in the motion control
    distance2 = 999;
    distance3 = 999;

  }


  /*********************************************************************************************************************
      Collision control logic based on the Sonar readings
      Runs Logic to manouver away from the object
      if Error is >= 5 i.e. Batt Low etc, then this section is skipped otherwise the mower would start if a sonar is triggered

   *********************************************************************************************************************/

  /* Makes sure that sporadic objects are not registered.  */
  if (  (distance1 < maxdistancesonar) ||  (distance2 < maxdistancesonar)  ||  (distance3 < maxdistancesonar)  ) {
    ObjectRegistered = ObjectRegistered + 1;
    Serial.println("**** Object Registered ******");
   }
   else  {
    ObjectRegistered = 0;
  }

  /* Prints the number of objects to the Serial printer and LCD.  If 2 objects are consecztivley detected the mower is stopped and turns. */
  Serial.print("Object Count is: ");
  Serial.println(ObjectRegistered);
  if (ObjectRegistered > 0) {
      lcd.setCursor(5, 0);
      lcd.print(ObjectRegistered);
      }
  else {
      lcd.setCursor(5, 0);
      lcd.print(" ");
      }
  


  if (ObjectRegistered >= 2) {

    if ( distance1 < maxdistancesonar ||  distance2 < maxdistancesonar  ||  distance3 < maxdistancesonar && Error == 0 ) {
      lcd.setCursor(0, 1);
      lcd.print("Object:          ");
      Serial.println("Object Detected by Sonar");
      Serial.println("Reversing.....");
      Motion_StopMotors();
      delay(2000);
      lcd.setCursor(0, 8);
      lcd.print("Reversing");
      SetPins_ToGoBackwards();
      Motion_GoFullSpeed();
      delay (Mower_Reverse_Delay);                                                                               // Time given to Reverse  the Mower
      Motion_StopMotors();
      if ( distance1 < maxdistancesonar ||  distance2 < maxdistancesonar ) {
        Serial.println("Turning Left to avoid Object");
        lcd.setCursor(0, 8);
        lcd.print("<-- Go Left       ");
        SetPins_ToTurnLeft(); Serial.println("");                                                  // Calls the motor function turn Left
        delay(200);
        Motion_TurnSpeed();                                                                     // Sets the speed of the turning motion
        delay(Mower_Turn_Delay_Left);                                                                     // Time motors on to Turn the Mower Left
        Motion_StopMotors();
        delay(50);
        SetPins_ToGoForwards();
        MowerMotionStatus = 3;

        //set the other Sonar distances to high so the second logic loop is not included.
        distance3 = 700;
      }

      if (distance3 < maxdistancesonar) {
        Serial.println("Turning Right to avoid Object");
        lcd.setCursor(0, 8);
        lcd.print("Go Right -->      ");
        SetPins_ToTurnRight(); Serial.println("");                                                                          // Calls the motor funstion turn right
        delay(200);
        Motion_TurnSpeed();
        delay(Mower_Turn_Delay_Right);                                                                          // Time to Turn the Mower Right
        Motion_StopMotors();
        delay(50);
        SetPins_ToGoForwards();
        MowerMotionStatus = 3;
      
      }
    }
    ObjectRegistered = 0;
  }
}

/* SONAR Function
************************************************************************************/
// Function to Ping the Sonar calculate the distance from Object to the Sonars.
// Distance calculated is printed to serial printer and displays X or _ on the LCD Screen
// Distance calculated is then used for the object avoidance logic
// Sonars used can be activated in the settings.

int PingSonarX(int trigPinX, int echoPinX, int distanceX, long durationX, int sonarX, int LCDRow, int LCDColumn) {
  pinMode(trigPinX, OUTPUT);
  pinMode(echoPinX, INPUT);
  //Sets the trigPin at High state for 10 micro secs sending a sound wave
  digitalWrite(trigPinX, HIGH);
  digitalWrite(trigPinX, LOW);
  delayMicroseconds(10);

  /*Reads the echoPin for the bounced wave and records the time in microseconds*/
  durationX = pulseIn(echoPinX, HIGH);

  /*Calculates the distance in cm based on the measured time*/
  distanceX = durationX * 0.034 / 2;
  delay(5);

  /* If a 0 distance is measured normally the Sonar ping has not been received.
    distance is then set to 999cm so the missed ping is not seen as an object detected.*/
  if (distanceX == 0) {
    distanceX = 999;
    Serial.print("SONAR ");
    Serial.print(sonarX);
    Serial.print(": ");
    Serial.println("NO PING ERROR REMOVED");
  }

  /*Prints the Sonar letter and distance measured on the serial Monitor*/
  Serial.print("SONAR ");
  Serial.print(sonarX);
  Serial.print(": ");
  Serial.print(distanceX);
  Serial.println(" cm");
  //Serial.println(maxdistancesonar);

  /*If sonar distance is less than maximum distance then an object is registered to avoid*/
  if (distanceX <= maxdistancesonar ) {
    //Prints that Sonar X has detected an object to the Mower LCD.
    lcd.setCursor(LCDRow, LCDColumn);                //sets location for text to be written
    lcd.print("X");
    delay(10);
  }

  /*If sonar distance is greater than maximum distance then no object is registered to avoid*/
  if (distanceX > maxdistancesonar) {
    //Prints that the path of Sonar X is open.
    lcd.setCursor(LCDRow, LCDColumn);                 //sets location for text to be written
    lcd.print("_");
    delay(10);
  }

  return distanceX;
  return sonarX;

}
