


void Check_Tilt_Tip_Angle() {

  // CAREFUL Tilt_Angle_Sensed = 0 = ON   1 = OFF
  // Tilt_Orientation_Sensed =   1 = ON   0 = OFF


  // Check Angle Sensor
  if (Angle_Sensor_Enabled == 1)  {  
      Tilt_Angle_Sensed = digitalRead(Tilt_Angle);          // reads the Tilt Angle sensor
      // Check if the Tilt Sensor is active
      Serial.print("|A:");
      Serial.print(Tilt_Angle_Sensed); 
      if ((Mower_Running == 1) && (Tilt_Angle_Sensed == 0) && (Tilt_Orientation_Sensed == 0)) Take_Tilt_Action();
      }
  if (Angle_Sensor_Enabled == 0) {
    Tilt_Angle_Sensed = 1;         // 0 = ON   1 = OFF
    }
  
  // Check Tip Sensor
  if (Tip_Over_Sensor_Enabled == 1) {
    Tilt_Orientation_Sensed = digitalRead(Tilt_Orientation);    // reads the Tilt Orientation sensor
    Serial.print("|O:");
    Serial.print(Tilt_Orientation_Sensed);
    Serial.print("|"); 
    if ((Mower_Running == 1) && (Tilt_Orientation_Sensed == 1)) Take_Orientation_Action();
    }
  if (Tip_Over_Sensor_Enabled == 0) {
    Tilt_Orientation_Sensed = 0;   // 1 = ON   0 = OFF
    }

}


// Action if Angle Sensor is activated
void Take_Tilt_Action() {
  if (Angle_Sensor_Enabled == 1) {        
        Serial.println(" ");
        Serial.println("Tilt Sensed");
        //Motor_Action_Stop_Spin_Blades();
        Motor_Action_Stop_Motors();
        SetPins_ToGoBackwards();
        Motor_Action_Go_Full_Speed();
        delay(1500);
        Motor_Action_Stop_Motors();
        Send_Mower_Running_Data();
        delay(2000);
        
        bool Tip_Stop = true;
    
        while (Tip_Stop == true) {
          Check_Tilt_Tip_Angle();
          if (Tilt_Angle_Sensed == 1) Tip_Stop = false;
        }
    
        Serial.println("Turning Around After Tip Stop");
        SetPins_ToTurnRight(); 
        Motor_Action_Go_Full_Speed();
        delay (random(Mower_Turn_Delay_Min, Mower_Turn_Delay_Max));
        Motor_Action_Stop_Motors();
        }
    }


// Action if Tip Sensor is activated
void Take_Orientation_Action() {
    
    if (Tip_Over_Sensor_Enabled == 1)  {

          // Double check to make sure its not an error message
          Tilt_Orientation_Sensed = digitalRead(Tilt_Orientation);    // reads the Tilt Orientation sensor

          if (Tilt_Orientation_Sensed == 1) {   
              Serial.println(F(" ")); 
              Serial.println(F("***********************************"));
              Serial.println(F("***** TIP OVER PROTECTION !!! *****"));     
              Serial.println(F("***********************************"));
              Serial.println(F(" ")); 
              Motor_Action_Stop_Spin_Blades();
              Motor_Action_Stop_Motors();
              Tilt_Orientation_Sensed = 1;
              Manouver_Hibernate_Mower();
              delay(5000);
              }
           }
    }
