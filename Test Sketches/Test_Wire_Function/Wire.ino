
/* Perimieter Wire Collision Motion
  ************************************************************************************/
  void Check_Wire()  {
  
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
  Serial.print("Inside (1) or Outside (0):  ");
  Serial.print((perimeter.isInside(0)));
  Serial.print("     MAG: ");
  Serial.print((int)perimeter.getMagnitude(0));
  Serial.print("    smag: ");
  Serial.print((int)perimeter.getSmoothMagnitude(0));
  Serial.print("     qaulity: ");
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
