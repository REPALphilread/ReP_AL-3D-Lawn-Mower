

// Turns the mowing blades on
void SpinBlades()  { 
    delay(20);
    digitalWrite(R_EN, HIGH);
    digitalWrite(L_EN, HIGH);
    delay(20);
    analogWrite(RPWM, PWM_Blade_Speed);
    delay(20);
    Serial.println(F("Blade Motor Spinning.. Mind your fingers!"));
  }                 


// Turns the mowing blades off
void StopSpinBlades()  {
  delay(20);
  digitalWrite(R_EN, LOW);
  digitalWrite(L_EN, LOW);
  delay(20);
  Serial.println(F("Blades Motor Stopped...!"));
  }
