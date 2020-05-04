


void Check_Tilt_Tip_Angle() {

  if (Angle_Sensor_Enabled == 1)    Tilt_Angle_Sensed = digitalRead(Tilt_Angle);          // reads the Tilt Angle sensor
  if (Angle_Sensor_Enabled == 0)    Tilt_Angle_Sensed = 1;   // 1 = Not Active   0 = Active
  
  if (Tip_Over_Sensor_Enabled == 1) Tilt_Orientation_Sensed = digitalRead(Tilt_Orientation);    // reads the Tilt Orientation sensor


  // Check if the Tilt Sensor is active
  Serial.print("|A:");
  Serial.print(Tilt_Angle_Sensed);


  Serial.print("|O:");
  Serial.print(Tilt_Orientation_Sensed);
  Serial.print("|");  

  delay(200);

  // CAREFUL Tilt_Angle_Sensed = 0 = ON
  // Tilt_Orientation_Sensed = 0 = OFF
  
  if ((Mower_Running == 1) && (Tilt_Angle_Sensed == 0) && (Tilt_Orientation_Sensed == 0))       Take_Tilt_Action();
  if ((Mower_Running == 1) && (Tilt_Orientation_Sensed == 1))                                   Take_Orientation_Action();
   
    
  }



void Take_Tilt_Action() {
  if (Angle_Sensor_Enabled == 1) {        
        Send_Mower_Running_Data();
        Serial.println(" ");
        Serial.println("Tilt Sensed");
        //Motor_Action_Stop_Spin_Blades();
        Motor_Action_Stop_Motors();
        SetPins_ToGoBackwards();
        Motor_Action_Go_Full_Speed();
        delay(1500);
        Motor_Action_Stop_Motors();
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
