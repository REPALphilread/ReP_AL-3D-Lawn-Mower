void Motor_Action_Go_Full_Speed()     {
      analogWrite(ENAPin, PWM_MaxSpeed_RH);                       // Speed = 0-255  (255 is max speed). Speed is set in the settings                        
      analogWrite(ENBPin, PWM_MaxSpeed_LH);                       // Anaolgwirte sends PWM signals Speed = 0-255  (255 is max speed)
      Serial.print(F("Wheel:FULL|"));
      }

void Motor_Action_GoFullSpeed_Out_Garage()     {
  //Speeds can be changed to give the mower a slight curve when exiting the Garage.
  
  PWM_MaxSpeed_LH = PWM_MaxSpeed_LH + 20;                          
  if (PWM_MaxSpeed_LH > 255)  PWM_MaxSpeed_LH = 255;
  if (PWM_MaxSpeed_RH > 255)  PWM_MaxSpeed_RH = 255;
  
  analogWrite(ENAPin, PWM_MaxSpeed_RH);                                       // Speed = 0-255  (255 is max speed). Speed is set in the settings
  analogWrite(ENBPin, PWM_MaxSpeed_LH);   
  Serial.print(F("Wheel:FULL|"));
  }


void SetPins_ToGoForwards()     {                                 // Motor Bridge pins are set for both motors to move forwards.
  digitalWrite(IN1Pin, LOW);                                      // Motor Birdge pins are set to high or low to set the direction of movement
  digitalWrite(IN2Pin, HIGH);
  digitalWrite(IN3Pin, LOW);
  digitalWrite(IN4Pin, HIGH);
  Serial.print(F("Wheel:For|"));
  }


void SetPins_ToGoBackwards()      {                               // Motor Bridge pins are set for both motors to move Backwards
  digitalWrite(IN1Pin, HIGH);                                     // Motor 1
  digitalWrite(IN2Pin, LOW);
  digitalWrite(IN3Pin, HIGH);                                     // Motor 2
  digitalWrite(IN4Pin, LOW);
  Serial.print(F("Wheel:Rev|"));
  delay(20);
  }


void Motor_Action_Stop_Motors()  {                                     // Motor Bridge pins are set for both motors to stop
  digitalWrite(ENAPin, 0);
  digitalWrite(IN1Pin, LOW);                                    //Motor 1
  digitalWrite(IN2Pin, LOW);

  digitalWrite(ENBPin, 0);                                      //Motor 2
  digitalWrite(IN3Pin, LOW);
  digitalWrite(IN4Pin, LOW);

  Serial.print(F("Wheel:0FF|"));
}


void SetPins_ToTurnLeft()       {                              // Pins are set so that Motors drive in opposite directions
    digitalWrite(IN1Pin, LOW);                                   // Motor 1
    digitalWrite(IN2Pin, HIGH);
    digitalWrite(IN3Pin, HIGH);                                  // Motor 2
    digitalWrite(IN4Pin, LOW);
    Serial.print(F("Wheel:TL_|"));  
    }


void SetPins_ToTurnRight() {                                    // Pins are set so that Motors drive in opposite directions
      digitalWrite(IN1Pin, HIGH);                                   // Motor 1
      digitalWrite(IN2Pin, LOW);
      digitalWrite(IN3Pin, LOW);                                    //Motor 2
      digitalWrite(IN4Pin, HIGH);
      Serial.print(F("Wheel:R|"));
      }


// USed to turn the mower at a set speed.
void Motor_Action_Turn_Speed() {
      analogWrite(ENAPin, (PWM_MaxSpeed_RH - Turn_Adjust) );                                  // Change the 0 value to 10 or 20 to recuce the speed
      analogWrite(ENBPin, (PWM_MaxSpeed_LH - Turn_Adjust) );                                  // Change the 0 value to 10 or 20 to recuce the speed
      }


// Turns the mowing blades on
void Motor_Action_Spin_Blades()  {
  if (Cutting_Blades_Activate == 1) {                                       // Blades are turn ON in settings and will spin!
    delay(20);
    digitalWrite(R_EN, HIGH);
    digitalWrite(L_EN, HIGH);
    delay(20);
    analogWrite(RPWM, PWM_Blade_Speed);
    delay(20);
    Serial.print(F("Blades:ON_|"));
   }                 

  if (Cutting_Blades_Activate == 0) {                                     // Blades are turn off in settings and will not spin!
    void StopSpinBlades();

  }
}

void Motor_Action_Stop_Spin_Blades()  {
  delay(20);
  digitalWrite(R_EN, LOW);
  digitalWrite(L_EN, LOW);
  delay(20);
  Serial.print(F("Blades:0FF|"));
}

//Steers the Mower depending on the PID input from the Algorythm
void Motor_Action_Dynamic_PWM_Steering() {
      analogWrite(ENAPin, PWM_Right);                             // ENA low = Right Swerve   ENB low = Left Swerve
      analogWrite(ENBPin, PWM_Left);
      Serial.print(F("PWM_R:"));
      Serial.print(PWM_Right);
      Serial.print(F("|"));
      Serial.print(F("PWM_L:"));
      Serial.print(PWM_Left);
      Serial.print(F("|"));
}
