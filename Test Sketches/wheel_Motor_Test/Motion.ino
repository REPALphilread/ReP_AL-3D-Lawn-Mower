

/* Motor Functions
************************************************************************************/

void Motion_GoFullSpeed()     {
  if (Reverse_Steering == 0) {
      analogWrite(ENAPin, PWM_MaxSpeed_RH);                       // Speed = 0-255  (255 is max speed). Speed is set in the settings                        
      analogWrite(ENBPin, PWM_MaxSpeed_LH);                       // Anaolgwirte sends PWM signals Speed = 0-255  (255 is max speed)
      }

  if (Reverse_Steering == 1) {
      analogWrite(ENBPin, PWM_MaxSpeed_RH);                             
      analogWrite(ENAPin, PWM_MaxSpeed_LH);
      }

  Serial.println(F("Go Full Speed "));
}


void SetPins_ToGoForwards()     {                                 // Motor Bridge pins are set for both motors to move forwards.
  digitalWrite(IN1Pin, LOW);                                      // Motor Birdge pins are set to high or low to set the direction of movement
  digitalWrite(IN2Pin, HIGH);
  digitalWrite(IN3Pin, LOW);
  digitalWrite(IN4Pin, HIGH);
  Serial.println(F("Set Motor Forwards"));
}


void SetPins_ToGoBackwards()      {                               // Motor Bridge pins are set for both motors to move Backwards
  digitalWrite(IN1Pin, HIGH);                                     // Motor 1
  digitalWrite(IN2Pin, LOW);
  digitalWrite(IN3Pin, HIGH);                                     // Motor 2
  digitalWrite(IN4Pin, LOW);
  Serial.println(F("Set Motor Reverse"));
  delay(20);
}


void Motion_StopMotors()  {                                     // Motor Bridge pins are set for both motors to stop
  digitalWrite(ENAPin, 0);
  digitalWrite(IN1Pin, LOW);                                    //Motor 1
  digitalWrite(IN2Pin, LOW);

  digitalWrite(ENBPin, 0);                                      //Motor 2
  digitalWrite(IN3Pin, LOW);
  digitalWrite(IN4Pin, LOW);

  Serial.println(F("Motor Stop"));
}


void SetPins_ToTurnLeft()       {                              // Pins are set so that Motors drive in opposite directions
  if (Reverse_Steering == 0) {
    digitalWrite(IN1Pin, LOW);                                   // Motor 1
    digitalWrite(IN2Pin, HIGH);
    digitalWrite(IN3Pin, HIGH);                                  // Motor 2
    digitalWrite(IN4Pin, LOW);
    }
 if (Reverse_Steering == 1) {
    digitalWrite(IN1Pin, HIGH);                                   // Motor 1
    digitalWrite(IN2Pin, LOW);
    digitalWrite(IN3Pin, LOW);                                    //Motor 2
    digitalWrite(IN4Pin, HIGH);
    }
 Serial.print(F("Turn Left"));  
  }


void SetPins_ToTurnRight() {                                    // Pins are set so that Motors drive in opposite directions
    if (Reverse_Steering == 0) {
      digitalWrite(IN1Pin, HIGH);                                   // Motor 1
      digitalWrite(IN2Pin, LOW);
      digitalWrite(IN3Pin, LOW);                                    //Motor 2
      digitalWrite(IN4Pin, HIGH);
      }
   if (Reverse_Steering == 1) {
     digitalWrite(IN1Pin, LOW);                                   // Motor 1
     digitalWrite(IN2Pin, HIGH);
     digitalWrite(IN3Pin, HIGH);                                  // Motor 2
     digitalWrite(IN4Pin, LOW);
     }
  
  Serial.print(F("Turn Right"));
}


// USed to turn the mower at a set speed.
void Motion_TurnSpeed() {

  if (Reverse_Steering == 0) {
      analogWrite(ENAPin, (PWM_MaxSpeed_RH - 0) );                                  // Change the 0 value to 10 or 20 to recuce the speed
      analogWrite(ENBPin, (PWM_MaxSpeed_LH - 0) );                                  // Change the 0 value to 10 or 20 to recuce the speed
      }

  if (Reverse_Steering == 1) {
      analogWrite(ENAPin, (PWM_MaxSpeed_LH - 0) );                                  // Change the 0 value to 10 or 20 to recuce the speed
      analogWrite(ENBPin, (PWM_MaxSpeed_RH - 0) );                                  // Change the 0 value to 10 or 20 to recuce the speed
      }
  

  Serial.print(F("Turn Speed RH : ")); Serial.println(PWM_MaxSpeed_RH - 0);
  Serial.print(F("Turn Speed LH : ")); Serial.println(PWM_MaxSpeed_LH - 0);
}


