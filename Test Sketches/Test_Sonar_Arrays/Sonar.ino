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
    if (Sonar_1_Activate) distance1 = PingSonarX(trigPin1, echoPin1, 1, 1, 1, 5, 0);          //SONAR1
    delay(15);
    if (Sonar_2_Activate) distance2 = PingSonarX(trigPin2, echoPin2, 2, 2, 2, 0, 0);         //SONAR2
    delay(15);
    if (Sonar_3_Activate) distance3 = PingSonarX(trigPin3, echoPin3, 3, 3, 3, 10, 0);          //SONAR3
    delay(15);
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
    LCDColumn = LCDColumn + 1;    
    lcd.setCursor(LCDRow, LCDColumn);                //sets location for text to be written
    lcd.print("   ");
    lcd.setCursor(LCDRow, LCDColumn);
    lcd.print(distanceX);
    delay(10);
  }

  /*If sonar distance is greater than maximum distance then no object is registered to avoid*/
  if (distanceX > 100) {
    //Prints that the path of Sonar X is open.
    LCDColumn = LCDColumn - 1;   
    lcd.setCursor(LCDRow, LCDColumn);                 //sets location for text to be written
    lcd.print("_");
    delay(10);
  }

  return distanceX;
  return sonarX;

}
