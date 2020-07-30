
// Data received from the Main Arduino MEGA Board on the mower
// ************************************************************

void Receive_Sonar_Data()  {
 
  String Serial1_RX_Value  = "";                                            

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c' && recieved != '\d' && recieved != '\e' ) {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Sonar_1_Activate = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      Sonar_2_Activate = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\c') {
      Sonar_3_Activate = Serial1_RX_Value.toInt();                           
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\d') {
      maxdistancesonar = Serial1_RX_Value.toInt();                       
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\e') {
      Max_Sonar_Hit = Serial1_RX_Value.toInt();                          
      Serial1_RX_Value = "";
      } 
    else Serial.print(F("No Data Received|"));
  }

      Serial.print(F("Sonar 2 Activated = "));
      Serial.println(Sonar_2_Activate);
      Serial.print(F("Sonar 1 Activated = "));
      Serial.println(Sonar_1_Activate);
      Serial.print(F("Sonar 3 Activated = "));
      Serial.println(Sonar_3_Activate);
      Serial.print(F("Sonar Max Distance = "));
      Serial.println(maxdistancesonar);
      Serial.print(F("Sonar Sensitivity = "));
      Serial.println(Max_Sonar_Hit);
      Serial.println(F(" "));

}




void Receive_Battery_Data()  {

  String Serial1_RX_Value  = "";                                   

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\a' && recieved != '\b'  ) {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;        
      } 
      else if (recieved == '\a') {
      Battery_Min = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      Low_Battery_Instances_Chg = Serial1_RX_Value.toInt();                          
      Serial1_RX_Value = "";
      } 
    else Serial.print(F("No Data Received|"));
  }

      Serial.print(F("Battery Min = "));
      Battery_Min = Battery_Min / 10;
      Serial.println(Battery_Min);
      Serial.print(F("Battery Sensitivity = "));
      Serial.println(Low_Battery_Instances_Chg);
      Serial.println(F(" "));
}



// Button Data for the Sensor Menu when it has been activated from the Options screen
void Receive_Sensor_Menu1_Data()  {
 
  String Serial1_RX_Value  = "";                                              

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c') {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Perimeter_Wire_Enabled = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      WIFI_Enabled = Serial1_RX_Value.toInt();                        
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\c') {
      Bumper_Activate_Frnt = Serial1_RX_Value.toInt();                        
      Serial1_RX_Value = "";
      } 
    else Serial.print(F("No Data Received|"));
  }

      Serial.print(F("Wire Module Activated = "));
      Serial.println(Perimeter_Wire_Enabled);
      Serial.print(F("WIFI Enabled = "));
      Serial.println(WIFI_Enabled);
      Serial.print(F("Bumper Activated = "));
      Serial.println(Bumper_Activate_Frnt);
      Serial.println(F(" "));


}




void Receive_Rain_Sensor_Data()  {

  String Serial1_RX_Value  = "";                               

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\a' && recieved != '\b'  ) {   
        Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;        
        } 
        else if (recieved == '\a') {
          Rain_Sensor_Installed = Serial1_RX_Value.toInt();                                 
          Serial1_RX_Value = ""; // changed to string
          } 
       else if (recieved == '\b') {
          Rain_Total_Hits_Go_Home = Serial1_RX_Value.toInt();                             
          Serial1_RX_Value = "";
          } 
    else Serial.print(F("No Data Received|"));
    }

      Serial.print(F("Rain Sensor ON/OFF = "));
      Serial.println(Rain_Sensor_Installed);
      Serial.print(F("Rain Sensor Sensitivity = "));
      Serial.println(Rain_Total_Hits_Go_Home);
      Serial.println(F(" "));
    }

void Receive_Wheel_Motor_Data()  {

  String Serial1_RX_Value  = "";                                            

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c' && recieved != '\d' && recieved != '\e') {   
        Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
        } 
        else if (recieved == '\a') {
          PWM_MaxSpeed_LH = Serial1_RX_Value.toInt();                                 
          Serial1_RX_Value = ""; // changed to string
          } 
       else if (recieved == '\b') {
          PWM_MaxSpeed_RH = Serial1_RX_Value.toInt();                             
          Serial1_RX_Value = "";
          } 
        else if (recieved == '\c') {
          PWM_Slow_Speed_LH = Serial1_RX_Value.toInt();                                 
          Serial1_RX_Value = ""; // changed to string
          } 
       else if (recieved == '\d') {
          PWM_Slow_Speed_RH = Serial1_RX_Value.toInt();                             
          Serial1_RX_Value = "";
          }     
       else if (recieved == '\e') {
          Slow_Speed_MAG = Serial1_RX_Value.toInt();                             
          Serial1_RX_Value = "";
          }  
    else Serial.print(F("No Data Received|"));
    }

      Serial.print(F("Wheel Motor PWM LH = "));
      Serial.println(PWM_MaxSpeed_LH);
      Serial.print(F("Wheel Motor PWM RH = "));
      Serial.println(PWM_MaxSpeed_RH);
      Serial.print(F("Wheel Motor Slow Speed PWM LH = "));
      Serial.println(PWM_Slow_Speed_LH);
      Serial.print(F("Wheel Motor Slow Speed PWM RH = "));
      Serial.println(PWM_Slow_Speed_RH);
      Serial.print(F("Slow Speed MAG = "));
      Slow_Speed_MAG = Slow_Speed_MAG * 10;
      Serial.println(Slow_Speed_MAG);
      Serial.println(F(" "));
    }


void Receive_Blade_Motor_Data()  {

  String Serial1_RX_Value  = "";                                           

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\a' && recieved != '\b'  ) {   
        Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;        
        } 
        else if (recieved == '\a') {
          PWM_Blade_Speed = Serial1_RX_Value.toInt();                                 
          Serial1_RX_Value = ""; // changed to string
          } 
       else if (recieved == '\b') {
          Cutting_Blades_Activate = Serial1_RX_Value.toInt();                             
          Serial1_RX_Value = "";
          } 
    else Serial.print(F("No Data Received|"));
    }

      Serial.print(F("Blade Motor PWM = "));
      Serial.println(PWM_Blade_Speed);
      Serial.print(F("Cutting Blade Activated = "));
      Serial.println(Cutting_Blades_Activate);
      Serial.println(F(" "));
    }



void Receive_Movement_Menu_Data() {


  String Serial1_RX_Value  = "";                                     

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c' && recieved != '\d') {   
        Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;         
        } 
        else if (recieved == '\a') {
          Max_Cycles_Straight = Serial1_RX_Value.toInt();                                 
          Serial1_RX_Value = ""; // changed to string
          } 
       else if (recieved == '\b') {
          Mower_Turn_Delay_Min = Serial1_RX_Value.toInt();                               
          Serial1_RX_Value = "";
          } 
       else if (recieved == '\c') {
          Mower_Turn_Delay_Max = Serial1_RX_Value.toInt();                           
          Serial1_RX_Value = "";
          }
       else if (recieved == '\d') {
          Mower_Reverse_Delay = Serial1_RX_Value.toInt();                              
          Serial1_RX_Value = "";
          }
    
    else Serial.print(F("No Data Received|"));
    }

      Serial.print(F("Max Mow Length = "));
      Max_Cycles_Straight = Max_Cycles_Straight * 10;
      Serial.println(Max_Cycles_Straight);
      
      Serial.print(F("Turn Angle Min = "));
      Mower_Turn_Delay_Min = Mower_Turn_Delay_Min * 100;
      Serial.println(Mower_Turn_Delay_Min);
      
      Serial.print(F("Turn Angle Max = "));
      Mower_Turn_Delay_Max = Mower_Turn_Delay_Max * 100;
      Serial.println(Mower_Turn_Delay_Max);
      
      Serial.print(F("Reverse Distance = "));
      Mower_Reverse_Delay = Mower_Reverse_Delay * 100;
      Serial.println(Mower_Reverse_Delay);
      Serial.println(F(" "));
    }


void Receive_Exit_Point_Data() {


  String Serial1_RX_Value  = "";                                        

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c') {   
        Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;         
        } 
        else if (recieved == '\a') {
          Track_Wire_Zone_1_Cycles = Serial1_RX_Value.toInt();                              
          Serial1_RX_Value = ""; // changed to string
          } 
       else if (recieved == '\b') {
          Track_Wire_Zone_2_Cycles = Serial1_RX_Value.toInt();                             
          Serial1_RX_Value = "";
          } 
       else if (recieved == '\c') {
          CCW_Tracking_To_Start = Serial1_RX_Value.toInt();                              
          Serial1_RX_Value = "";
          }
    
    else Serial.print(F("No Data Received|"));
    }

      Serial.print(F("Track Wire Zone 1 = "));
      Track_Wire_Zone_1_Cycles = Track_Wire_Zone_1_Cycles * 100;
      Serial.println(Track_Wire_Zone_1_Cycles);
      
      Serial.print(F("Track Wire Zone 2 = "));
      Track_Wire_Zone_2_Cycles = Track_Wire_Zone_2_Cycles * 100;
      Serial.println(Track_Wire_Zone_2_Cycles);
      
      if (CCW_Tracking_To_Start == 0) {
        CW_Tracking_To_Start = 1;
        CCW_Tracking_To_Charge = 1;
        CW_Tracking_To_Charge = 0;

        Serial.println(F("Tracking to Charge = CCW"));
        Serial.println(F("Tracking to Start = CW"));
        }
        
      if (CCW_Tracking_To_Start == 1) {
        CW_Tracking_To_Start = 0;
        CCW_Tracking_To_Charge = 0;
        CW_Tracking_To_Charge = 1;
        
        Serial.println(F("Tracking to Charge = CW"));
        Serial.println(F("Tracking to Start = CCW"));
        Serial.println(F(" "));  
        }
    }

void Receive_Find_Wire_Data() {

  String Serial1_RX_Value  = "";                                           

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c') {   
        Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
        } 
        else if (recieved == '\a') {
          Max_Cycle_Wire_Find = Serial1_RX_Value.toInt();                                 
          Serial1_RX_Value = ""; // changed to string
          } 
       else if (recieved == '\b') {
          Max_Cycle_Wire_Find_Back = Serial1_RX_Value.toInt();                         
          Serial1_RX_Value = "";
          } 
       else if (recieved == '\c') {
          Home_Wire_Compass_Heading = Serial1_RX_Value.toInt();                              
          Serial1_RX_Value = "";
          }
    
    else Serial.print(F("No Data Received|"));
    }

      Serial.print(F("Wire Find Forwards / Cycles = "));
      Max_Cycle_Wire_Find = Max_Cycle_Wire_Find * 100;
      Serial.println(Max_Cycle_Wire_Find);

      Serial.print(F("Wire Find Forwards / Cycles = "));
      Max_Cycle_Wire_Find_Back = Max_Cycle_Wire_Find_Back * 10;
      Serial.println(Max_Cycle_Wire_Find_Back);
          
      Serial.print(F("Home Compass Heading / degrees "));
      Serial.println(Home_Wire_Compass_Heading);

      Serial.println(F(" "));

}


void Receive_Tracking_Data() {
   String Serial1_RX_Value  = "";                                           

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\a' ) {   
        Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
        } 
        else if (recieved == '\a') {
          Use_Charging_Station = Serial1_RX_Value.toInt();                                 
          Serial1_RX_Value = ""; // changed to string
          } 
    
    else Serial.print(F("No Data Received|"));
    } 

      Serial.print(F("Use Charging Station = "));
      Serial.println(Use_Charging_Station); 
      
      Serial.println(F(" "));
}


void Receive_Track_PID_Data() {

    String Serial1_RX_Value  = "";                                            

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c') {   
        Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;         
        } 
        else if (recieved == '\a') {
          Max_Tracking_Turn_Left = Serial1_RX_Value.toInt();                                 
          Serial1_RX_Value = ""; // changed to string
          } 
       else if (recieved == '\b') {
          Max_Tracking_Turn_Right = Serial1_RX_Value.toInt();                               
          Serial1_RX_Value = "";
          } 
       else if (recieved == '\c') {
          P = Serial1_RX_Value.toInt();                               
          Serial1_RX_Value = "";
          }
    
    else Serial.print(F("No Data Received|"));
    }

      Serial.print(F("Max Cyckes Left Wheel = "));
      Max_Tracking_Turn_Left = Max_Tracking_Turn_Left * 10;
      Serial.println(Max_Tracking_Turn_Left);

      Serial.print(F("Max Cyckes Right Wheel = "));
      Max_Tracking_Turn_Right = Max_Tracking_Turn_Right * 10;
      Serial.println(Max_Tracking_Turn_Right);
          
      Serial.print(F("PID P = "));
      P = P / 100;
      Serial.println(P);

      Serial.println(F(" "));
}




void Receive_Compass_Data() {

    String Serial1_RX_Value  = "";                                              

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c' && recieved != '\d') {   
        Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
        } 
        else if (recieved == '\a') {
          Compass_Activate = Serial1_RX_Value.toInt();                                 
          Serial1_RX_Value = ""; // changed to string
          } 
       else if (recieved == '\b') {
          Compass_Heading_Hold_Enabled = Serial1_RX_Value.toInt();                                
          Serial1_RX_Value = "";
          } 
       else if (recieved == '\c') {
          CPower = Serial1_RX_Value.toInt();                                
          Serial1_RX_Value = "";
          }
       else if (recieved == '\d') {
          Compass_Setup_Mode = Serial1_RX_Value.toInt();                                
          Serial1_RX_Value = "";
          }

    else Serial.print(F("No Data Received|"));
    }

      Serial.print(F("Compass Activated = "));
      Serial.println(Compass_Activate);

      Serial.print(F("Heading Hold Enabled = "));
      Serial.println(Compass_Heading_Hold_Enabled);
          
      Serial.print(F("Compass Power = "));
      CPower = CPower / 10;
      Serial.println(CPower);
      
      Serial.print(F("Compass Setup Mode = "));
      Serial.println(Compass_Setup_Mode);

      Serial.println(F(" "));
}



          
void Receive_GYRO_Data() {

  String Serial1_RX_Value  = "";                                              

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\a' && recieved != '\b') {   
        Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
        } 
       else if (recieved == '\a') {
          GYRO_Enabled = Serial1_RX_Value.toInt();                                
          Serial1_RX_Value = "";
          }
       else if (recieved == '\b') {
          GPower = Serial1_RX_Value.toInt();                                
          Serial1_RX_Value = "";
          }

    else Serial.print(F("No Data Received|"));
    }

      Serial.print(F("GYRO Enabled = "));
      Serial.println(GYRO_Enabled);
      Serial.print(F("GPower = "));      
      GPower = GPower / 10;
      Serial.println(GPower);
  }


void Receive_Navigation_Data() {

    String Serial1_RX_Value  = "";                                              

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\a') {   
        Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
        } 
       else if (recieved == '\a') {
          GPS_Enabled = Serial1_RX_Value.toInt();                                
          Serial1_RX_Value = "";
          }
    
    else Serial.print(F("No Data Received|"));
    }

      Serial.print(F("GPS Enabled = "));
      Serial.println(GPS_Enabled);
      Serial.println(F(" "));
}


void Receive_Alarm1_Data() {

  String Serial1_RX_Value  = "";                                            

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c' && recieved != '\d' && recieved != '\e' ) {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Alarm_1_ON = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      Alarm_1_Hour = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\c') {
      Alarm_1_Minute = Serial1_RX_Value.toInt();                           
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\d') {
      Alarm_1_Repeat = Serial1_RX_Value.toInt();                       
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\e') {
      Alarm_1_Action = Serial1_RX_Value.toInt();                          
      Serial1_RX_Value = "";
      } 
    else Serial.print(F("No Data Received|"));
  }


      Serial.print(F("Alarm 1 ON = "));
      Serial.println(Alarm_1_ON);

      Serial.print(F("Alarm 1 Time = "));
      Serial.print(Alarm_1_Hour);
      Serial.print(F(":"));
      Serial.println(Alarm_1_Minute);

      Serial.print(F("Alarm 1 Repeat = "));
      Serial.println(Alarm_1_Repeat);
      
      Serial.print(F("Alarm 1 Action = "));
      Serial.println(Alarm_1_Action); 
  
}


void Receive_Alarm2_Data() {

  String Serial1_RX_Value  = "";                                            

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c' && recieved != '\d' && recieved != '\e' ) {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Alarm_2_ON = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      Alarm_2_Hour = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\c') {
      Alarm_2_Minute = Serial1_RX_Value.toInt();                           
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\d') {
      Alarm_2_Repeat = Serial1_RX_Value.toInt();                       
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\e') {
      Alarm_2_Action = Serial1_RX_Value.toInt();                          
      Serial1_RX_Value = "";
      } 
    else Serial.print(F("No Data Received|"));
  }


      Serial.print(F("Alarm 2 ON = "));
      Serial.println(Alarm_2_ON);

      Serial.print(F("Alarm 2 Time = "));
      Serial.print(Alarm_2_Hour);
      Serial.print(F(":"));
      Serial.println(Alarm_2_Minute);

      Serial.print(F("Alarm 2 Repeat = "));
      Serial.println(Alarm_2_Repeat);
      
      Serial.print(F("Alarm 2 Action = "));
      Serial.println(Alarm_2_Action); 
  
}

void Receive_Alarm3_Data() {

  String Serial1_RX_Value  = "";                                            

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c' && recieved != '\d' && recieved != '\e' ) {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Alarm_3_ON = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      Alarm_3_Hour = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\c') {
      Alarm_3_Minute = Serial1_RX_Value.toInt();                           
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\d') {
      Alarm_3_Repeat = Serial1_RX_Value.toInt();                       
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\e') {
      Alarm_3_Action = Serial1_RX_Value.toInt();                          
      Serial1_RX_Value = "";
      } 
    else Serial.print(F("No Data Received|"));
  }


      Serial.print(F("Alarm 3 ON = "));
      Serial.println(Alarm_3_ON);

      Serial.print(F("Alarm 3 Time = "));
      Serial.print(Alarm_3_Hour);
      Serial.print(F(":"));
      Serial.println(Alarm_3_Minute);

      Serial.print(F("Alarm 3 Repeat = "));
      Serial.println(Alarm_3_Repeat);
      
      Serial.print(F("Alarm 3 Action = "));
      Serial.println(Alarm_3_Action); 

  
}


void Receive_Set_Time_Data() {

  String Serial1_RX_Value  = "";                                            

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\a' && recieved != '\b') {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Time_Hour = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      Time_Minute = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
    else Serial.print(F("No Data Received|"));
  }

      Serial.print(F("Time Now = "));
      Serial.print(Time_Hour);
      Serial.print(F(":"));
      Serial.println(Time_Minute);  
}


void Receive_Start_Up_Data() {

  String Serial1_RX_Value  = "";                                            

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c' 
    && recieved != '\d' && recieved != '\e' && recieved != '\f'
    && recieved != '\g') {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Alarm_1_ON = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      Alarm_2_ON = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\c') {
      Alarm_3_ON = Serial1_RX_Value.toInt();                           
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\d') {
      Time_Hour = Serial1_RX_Value.toInt();                           
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\e') {
      Time_Minute = Serial1_RX_Value.toInt();                           
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\f') {
      GPS_Enabled = Serial1_RX_Value.toInt();                           
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\g') {
      Perimeter_Wire_Enabled = Serial1_RX_Value.toInt();                           
      Serial1_RX_Value = "";
      } 
    else Serial.print(F("No Data Received|"));
  }
      tft.setCursor(0, 100); 
      tft.setTextSize(2); 
      tft.print(F("Alarm 1:"));
      tft.println(Alarm_1_ON);
      tft.print(F("Alarm 2:"));
      tft.println(Alarm_2_ON);
      tft.print(F("Alarm 3:"));
      tft.println(Alarm_3_ON); 
      tft.print(F("Time:"));
      tft.print(Time_Hour);
      tft.print(F(":"));
      if (Time_Minute < 10) tft.print("0");
      tft.println(Time_Minute);     
      tft.print(F("GPS:"));
      if (GPS_Enabled == 1) tft.println("ON");   
      if (GPS_Enabled == 0) tft.println("OFF"); 
      tft.print(F("WIRE:"));
      if (Perimeter_Wire_Enabled == 1) tft.println("ON");   
      if (Perimeter_Wire_Enabled == 0) tft.println("OFF"); 

      Serial.print(F("Alarm 1 ON = "));
      Serial.println(Alarm_1_ON);
      Serial.print(F("Alarm 2 ON = "));
      Serial.println(Alarm_2_ON);
      Serial.print(F("Alarm 3 ON = "));
      Serial.println(Alarm_3_ON);
      Serial.print(F("|Time:"));
      Serial.print(Time_Hour);
      Serial.print(F(":"));
      if (Time_Minute < 10) Serial.print("0");
      Serial.println(Time_Minute);
      Serial.print(F("GPS:"));
      if (GPS_Enabled == 1) Serial.println("ON");   
      if (GPS_Enabled == 0) Serial.println("OFF"); 
      Serial.print(F("WIRE:"));
      if (Perimeter_Wire_Enabled == 1) Serial.println("ON");   
      if (Perimeter_Wire_Enabled == 0) Serial.println("OFF"); 

}



void Receive_Wire_Sensor_Data() {

  String Serial1_RX_Value  = "";                                            

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c') {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      INOUT = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      MAG = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\c') {
      Menu_Complete_Wire_Test = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
    else Serial.print(F("No Data Received|"));
  }
    Serial.print(F("IN/Out:"));
    Serial.print(INOUT);
    Serial.print(F(" MAG:"));
    Serial.print(MAG); 
    Serial.print(F(" Test Complete:"));
    Serial.println(Menu_Complete_Wire_Test); 
}



void Receive_Sonar_Test_Data() {

  String Serial1_RX_Value  = "";                                            

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c' && recieved != '\d') {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      distance1 = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      distance2 = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\c') {
      distance3 = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\d') {
      Menu_Complete_Sonar_Test = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
    else Serial.print(F("No Data Received|"));
  }
    Serial.print(F("Sonar 1:"));
    Serial.print(distance1);
    Serial.print(F("  Sonar 2:"));
    Serial.print(distance2);
    Serial.print(F("  Sonar 3:"));
    Serial.print(distance3);
    Serial.print(F(" Test Complete:"));
    Serial.println(Menu_Complete_Wire_Test); 
}


void Receive_Compass_Sensor_Data() {
  String Serial1_RX_Value  = "";                                            

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c') {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Heading = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      Compass_Heading_Degrees = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\c') {
      Menu_Complete_Compass_Test = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
    else Serial.print(F("No Data Received|"));
  }
    Heading = Heading / 10;
    
    Serial.print("Heading: ");
    Serial.print(Heading);
    Serial.print("  Degrees: ");
    Serial.print(Compass_Heading_Degrees);
    Serial.print("  Test Completed: ");
    Serial.println(Menu_Complete_Compass_Test); 
}


void Receive_GYRO_Sensor_Data() {
  String Serial1_RX_Value  = "";                                            

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c') {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      GYRO_X_Angle = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      GYRO_Y_Angle = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\c') {
      Menu_Complete_GYRO_Test = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
    else Serial.print(F("No Data Received|"));
  }

    
    Serial.print("GYRO X Angle: ");
    Serial.print(GYRO_X_Angle);
    Serial.print("  GYRO_Y_Angle: ");
    Serial.print(GYRO_Y_Angle);
    Serial.print("  Test Completed: ");
    Serial.println(Menu_Complete_GYRO_Test); 
}


void Receive_Tip_Sensor_Motor_Data(){
  String Serial1_RX_Value  = "";                                            

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\a' && recieved != '\b') {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Angle_Sensor_Enabled = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      Tip_Over_Sensor_Enabled = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
    else Serial.print(F("No Data Received|"));
  }
    Heading = Heading / 10;
    
    Serial.print(F("Angle SensorEnabled: "));
    Serial.println(Angle_Sensor_Enabled);
    Serial.print(F("Tip Over Sensor Enabled: "));
    Serial.print(Tip_Over_Sensor_Enabled);

}



void Receive_Volt_Amp_Sensor_Data() {
  String Serial1_RX_Value  = "";                                            

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c') {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Volts = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      Amps = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\c') {
      Menu_Complete_Volt_Amp_Test = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
    else Serial.print(F("No Data Received|"));
  }
    Volts = (Volts * 2) / 100;
    Amps = Amps / 100;
    
    Serial.print("Volt: ");
    Serial.print(Volts);
    Serial.print("  Amps: ");
    Serial.print(Amps);
    Serial.print("  Test Completed: ");
    Serial.println(Menu_Complete_Volt_Amp_Test); 
}



void Receive_Bumper_Sensor_Data() {
  String Serial1_RX_Value  = "";                                            

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c') {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Bump_LH = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      Bump_RH = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\c') {
      Menu_Complete_Bumper_Test = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
    else Serial.print(F("No Data Received|"));
  }
    
    Serial.print("LH: ");
    Serial.print(Bump_LH);
    Serial.print("  RH: ");
    Serial.print(Bump_RH);
    Serial.print("  Test Completed: ");
    Serial.println(Menu_Complete_Bumper_Test); 
}

void Receive_Tilt_Sensor_Data() {
  String Serial1_RX_Value  = "";                                            

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c') {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Tilt_Angle_Sensed = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      Tilt_Orientation_Sensed = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\c') {
      Menu_Complete_Tilt_Test = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
    else Serial.print(F("No Data Received|"));
  }
    
    Serial.print("Tilt: ");
    Serial.print(Tilt_Angle_Sensed);
    Serial.print("  Orientation: ");
    Serial.print(Tilt_Orientation_Sensed);
    Serial.print("  Test Completed: ");
    Serial.println(Menu_Complete_Tilt_Test); 
}



void Receive_Pattern_Data()  {
 
  String Serial1_RX_Value  = "";                                            
  while (Serial1.available() > 0) {

  
    char recieved = Serial1.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c' && recieved != '\d' 
    && recieved != '\e') {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Pattern_Mow = Serial1_RX_Value.toInt();                          
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\b') {
      Turn_90_Delay_LH = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\c') {
      Turn_90_Delay_RH = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\d') {
      Move_to_next_line_delay = Serial1_RX_Value.toInt();                           
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\e') {
      Line_Length_Cycles = Serial1_RX_Value.toInt();                       
      Serial1_RX_Value = "";
      } 


     
    else Serial.print(F("No Data Received|"));
  }

 
      Serial.print(F("Pattern Mow"));
      if (Pattern_Mow == 0) Serial.println("OFF");
      if (Pattern_Mow == 1) Serial.println("Parallel");  
      if (Pattern_Mow == 3) Serial.println("Spiral");      
      
      Serial.print(F("Turn 90° LH= "));
      Turn_90_Delay_LH = Turn_90_Delay_LH * 10;
      Serial.println(Turn_90_Delay_LH);
      
      Serial.print(F("Turn 90° RH= "));
      Turn_90_Delay_RH = Turn_90_Delay_RH * 10;
      Serial.println(Turn_90_Delay_RH);
      
      Serial.print(F("Distance to next row= "));
      Move_to_next_line_delay = Move_to_next_line_delay * 10;
      Serial.println(Move_to_next_line_delay);

      Serial.print(F("Row Length= "));
      Serial.println(Line_Length_Cycles);  

}



void Get_Initial_Values() {
    Menu_Active = 55;
    Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
    Serial.println("Recieving Start Up Values from Mower MEGA");
    delay(Receive_Values_Delay + 1200);
    Receive_Start_Up_Data();
    //JSON_Get_Initial_Values();
    delay(1000);
    Menu_Active = 1;
    Send_Menu_Selected_To_Mower_MEGA();         // Tell the Mower MEGA which menu on the TFT is selected
    }   


    

void Receive_Mower_Tracking_Data() {
  String Serial1_RX_Value  = "";                                            

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c' && recieved != '\d' && recieved != '\e' && recieved != '\f') {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Turn_To_Home = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      Find_Wire_Track = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\c') {
      Go_To_Charging_Station = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\d') {
      Docking_Complete = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\e') {
      Mower_Status_Value = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      }  
      else if (recieved == '\f') {
      Mower_Error_Value = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      }  
    else Serial.print(F("No Data Received|"));
  }
    
    Serial.print("Turn To Home");
    Serial.print(Turn_To_Home);
    Serial.print("  Find Wire Track ");
    Serial.print(Find_Wire_Track);
    Serial.print("  Go To Charging Station: ");
    Serial.print(Go_To_Charging_Station); 
    Serial.print("  Docking complete: ");
    Serial.print(Docking_Complete); 
    Serial.print(F("  Mower Status = "));
    Serial.println(Mower_Status_Value);
}



void Receive_Mower_Running_Volt_Data() {

  String Serial1_RX_Value  = "";                                            

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\v') {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\v') {
      Battery = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
    else Serial.print(F("No Data Received|"));
  }
      
      Serial.print(F("Volts% RX = "));
      Serial.print(Battery);


}


void Receive_Mower_Running_Data_Fly() {

  String Serial1_RX_Value  = "";                                            

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\g' && recieved != '\h') { 
              
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\g') {
      Loops = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\h') {
      Compass_Steering_Status = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
    }
        Serial.print(F("|Lo:"));
        Serial.print(Loops);
        Serial.print(F("|CS:"));
        Serial.print(Compass_Steering_Status);
}




void Receive_Mower_Running_Data() {

  int VoltsTX;
  String Serial1_RX_Value  = "";                                            

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c' && recieved != '\d' && recieved != '\e' 
    && recieved != '\f' && recieved != '\g' && recieved != '\h' && recieved != '\i' ) { 
              
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Sonar_Status = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      Wire_Status = Serial1_RX_Value.toInt();                         
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\c') {
      Bumper_Status = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\d') {
      Mower_Status_Value = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\e') {
      Mower_Error_Value = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\f') {
      Tilt_Angle_Sensed = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\g') {
      VoltsTX = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\h') {
      GPS_In_Out_TX = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\i') {
      GPS_Lock_OK_TX = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
    else Serial.print(F("No Data Received|"));
  }
      
        Serial.println(F("Sending Running Data to TFT"));
        Serial.print(F("|S:"));
        Serial.print(Sonar_Status);
        Serial.print(F("|W:"));
        Serial.print(Wire_Status);    
        Serial.print(F("|BU:"));
        Serial.print(Bumper_Status);               
        Serial.print(F("|MS:"));
        Serial.print(Mower_Status_Value);
        Serial.print(F("|Tip:"));
        Serial.print(Tilt_Angle_Sensed);
        Battery = VoltsTX;
        Battery = Battery / 100;
        Serial.print(F("VoltsRX = "));
        if (VoltsTX > 0) Serial.print(Battery);
        else Serial.print("XX.XX");
        Serial.print(F("|GPS:"));
        if (GPS_In_Out_TX == 1) Serial.print("INSIDE");
        if (GPS_In_Out_TX == 0) Serial.print("OUTSIDE");        
        Serial.print(F("|GPS:"));
        if (GPS_Lock_OK_TX == 1) Serial.print("RTKFIX");
        if (GPS_Lock_OK_TX == 0) Serial.print("No Lock");    

}



void Receive_Docked_Data() {

  int VoltsTX;
  
  String Serial1_RX_Value  = "";                                            

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c' && recieved != '\d' && recieved != '\e') { 
      
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      VoltsTX = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      Mower_Status_Value = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      }       
      else if (recieved == '\c') {
      Mower_Error_Value = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      }    
      else if (recieved == '\d') {
      Charging = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      }     
      else if (recieved == '\e') {
      GPS_Lock_OK_TX = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      }  
    else Serial.print(F("No Data Received|"));
  }
      
      
      Battery = VoltsTX;
      Battery = Battery / 100;
      Serial.print(F("VoltsRX = "));
      if (VoltsTX > 0) Serial.print(Battery);
      else Serial.print("XX.XX");

      Serial.print(F("|ME:"));
      Serial.print(Mower_Error_Value);
      Serial.print(F("|C: "));
      Serial.print(Charging);
      Serial.print(F("|"));
      Serial.print(F("MS "));
      if (Mower_Status_Value == 0) Serial.print("----");
      if (Mower_Status_Value == 1) Serial.print("Dock");
      if (Mower_Status_Value == 2) Serial.print("Park");
      if (Mower_Status_Value == 3) Serial.print("LowB");
      if (Mower_Status_Value == 4) Serial.print("Err ");
      if (Mower_Status_Value == 5) Serial.print("Run ");
      if (Mower_Status_Value == 9) Serial.print("Exit");
      Serial.print(F("|"));
      Serial.print(F("GPS:"));
      Serial.print(GPS_Lock_OK_TX);
      if (GPS_Lock_OK_TX == 5) Serial.print("RTKFIX");
      if (GPS_Lock_OK_TX == 2) Serial.print("No Lock");
      if (GPS_Lock_OK_TX == 0) Serial.print(" ");    
      
      
}


void Receive_Error_Data() {

  String Serial1_RX_Value  = "";                                            

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\a' && recieved != '\b') {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Mower_Status_Value = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      Mower_Error_Value = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      } 
    
    else Serial.print(F("No Data Received|"));
  }
      
      Serial.print(F("Mower Status = "));
      Serial.print(Mower_Status_Value);
      Serial.print(F("  Mower Error = "));
      Serial.println(Mower_Error_Value);

}





void Receive_GPS_Data() {

String Serial2_RX_Value  = "";                                              
  while (Serial2.available() > 0) {
  
    char recieved = Serial2.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c') {   
      Serial2_RX_Value = Serial2_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      GPS_WIFI_Enabled = Serial2_RX_Value.toInt();                                 
      Serial2_RX_Value = ""; // changed to string
      }
      else if (recieved == '\b') {
      Simulation_Mode = Serial2_RX_Value.toInt();                                 
      Serial2_RX_Value = ""; // changed to string
      }        
      else if (recieved == '\c') {
      Fence = Serial2_RX_Value.toInt();                                 
      Serial2_RX_Value = ""; // changed to string
      }  
   else Serial.print(F("No Data Received|"));   
   }
      Serial.print(F("GPS_WIFI_Enabled = "));
      if (GPS_WIFI_Enabled == 1) Serial.println("Enabled");
      if (GPS_WIFI_Enabled == 0) Serial.println("Disabled");
      Serial.print(F("Simulation Mode = "));
      if (Simulation_Mode == 1) Serial.println("Enabled");
      if (Simulation_Mode == 0) Serial.println("Disabled");
      Serial.print(F("Fence = "));
      Serial.println(Fence);
      Serial.println(F(" "));
}
