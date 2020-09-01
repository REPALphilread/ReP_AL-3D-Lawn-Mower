
           
// Special Cutting program to cut under the trampoline not using the wire. 
// Code basically runs the mower back and forth and spins it by a certain degree each time.
void Cut_Under_Trampoline_Function() {
    lcd.clear();
    lcd.print("Place Mower at");
    lcd.setCursor(0,1);
    lcd.print("trampoline legs");
    delay(5000);
    lcd.clear();
    lcd.print("Press Start >");
    int GO = 0;
    while (GO == 0) {
          Read_Membrane_Keys();
          delay(100);  
          if(!Start_Key_X){
            GO = 1;  
            }
        }  // end of while loop     
    
    lcd.clear();
    digitalWrite(Relay_Motors, LOW);
    lcd.print("3....");
    SpinBlades();
    delay(1000);
    lcd.clear();
    lcd.print("2....");
    delay(1000);
    lcd.clear();
    lcd.print("1....");
    delay(1000);
    lcd.clear();
    lcd.print("GO!!!!!!");
    delay(1000);
    SetPins_ToGoForwards();
    Motion_GoFullSpeed();
    delay (13500);
    Motion_StopMotors();
    delay(100);
    SetPins_ToGoBackwards();
    delay(100);
    Motion_GoFullSpeed();
    delay(6000);
    Motion_StopMotors();
    
    for (I = 0; I < 10; I++) {     
        SetPins_ToTurnLeft();
        Motion_TurnSpeed();
        delay(800);
        SetPins_ToGoForwards();
        delay(200);
        Motion_GoFullSpeed();
        delay (5000);
        Motion_StopMotors();
        delay(100);
        SetPins_ToGoBackwards();
        delay(100);
        Motion_GoFullSpeed();
        delay(5000);
        Motion_StopMotors();
        delay(100);
        }

  StopSpinBlades();    
  Motion_StopMotors();   
  SetPins_ToGoBackwards();
  delay(100);
  Motion_GoFullSpeed();
  delay(7000);
  digitalWrite(Relay_Motors, HIGH);  
  lcd.clear();
  lcd.print("Finished");
  delay(5000);
  lcd.clear();
}
