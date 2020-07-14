
void Transmit_Save_Sonar_Values() {
   
    // Menu Sonar
      Serial.println("TX Sonar to MEGA");
      delay(5);
      
      Serial1.print(Sonar_1_Activate);
      Serial1.println("\a");
      delay(200);  

      Serial1.print(Sonar_2_Activate);
      Serial1.println("\b");
      delay(200);  

      Serial1.print(Sonar_3_Activate);
      Serial1.println("\c");
      delay(200);  

      Serial1.print(maxdistancesonar);
      Serial1.println("\d");
      delay(200);

      Serial1.print(Max_Sonar_Hit);
      Serial1.println("\e");
      delay(200);


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
  
}


void  Transmit_Saved_Battery_Values() {
      Serial.println("TX Battery to MEGA");
      
      Serial1.print(Battery_Min * 10);     // *100 to make a float value volts 12.6 into an int 126
      Serial1.println("\a");
      delay(300);  

      Serial1.print(Low_Battery_Instances_Chg);
      Serial1.println("\b");
      delay(200);  

      Serial.print(F("Battery Min = "));
      Serial.println(Battery_Min);
      Serial.print(F("Battery Sensitivity = "));
      Serial.println(Low_Battery_Instances_Chg);      
      }




void Transmit_Sensor_Menu1_Values() {

      Serial.println("TX Sensor to MEGA");
      
      Serial1.print(Perimeter_Wire_Enabled);
      Serial1.println("\a");
      delay(200);  

      Serial1.print(WIFI_Enabled);
      Serial1.println("\b");
      delay(200);  

      Serial1.print(Bumper_Activate_Frnt);
      Serial1.println("\c");
      delay(200);  


      Serial.print(F("Wire Module Activated = "));
      Serial.println(Perimeter_Wire_Enabled);
      Serial.print(F("WIFI Enabled = "));
      Serial.println(WIFI_Enabled);
      Serial.print(F("Bumper Activated = "));
      Serial.println(Bumper_Activate_Frnt);
      }


void Transmit_Saved_Rain_Sensor_Values () {
      Serial.println("TX Rain to MEGA");
      
      Serial1.print(Rain_Sensor_Installed);
      Serial1.println("\a");
      delay(300);  

      Serial1.print(Rain_Total_Hits_Go_Home);
      Serial1.println("\b");
      delay(200);  

      Serial.print(F("Rain Sensor ON/OFF = "));
      Serial.println(Rain_Sensor_Installed);
      Serial.print(F("Rain Sensor Sensitivity = "));
      Serial.println(Rain_Total_Hits_Go_Home);
      }


void Transmit_Wheel_Motor_Values() {
      Serial.println("TX Wheel Motor to MEGA");
      
      Serial1.print(PWM_MaxSpeed_LH);
      Serial1.println("\a");
      delay(300);  

      Serial1.print(PWM_MaxSpeed_RH);
      Serial1.println("\b");
      delay(200);  

      Serial1.print(PWM_Slow_Speed_LH);
      Serial1.println("\c");
      delay(300);  

      Serial1.print(PWM_Slow_Speed_RH);
      Serial1.println("\d");
      delay(200);  

      Serial1.print(Slow_Speed_MAG / 10);
      Serial1.println("\e");
      delay(200);  
            
      Serial.print(F("Wheel Motor PWM LH = "));
      Serial.println(PWM_MaxSpeed_LH);
      Serial.print(F("Wheel Motor PWM RH = "));
      Serial.println(PWM_MaxSpeed_RH);
      Serial.print(F("Wheel Motor Slow Speed PWM LH = "));
      Serial.println(PWM_Slow_Speed_LH);
      Serial.print(F("Wheel Motor Slow Speed PWM RH = "));
      Serial.println(PWM_Slow_Speed_RH);
      Serial.print(F("Slow Speed MAG = "));
      Serial.println(Slow_Speed_MAG);
      Serial.println(F(" "));
      }

void Transmit_Blade_Motor_Values() {
      Serial.println("TX Blade Motor to MEGA");
      
      Serial1.print(PWM_Blade_Speed);
      Serial1.println("\a");
      delay(300);  

      Serial1.print(Cutting_Blades_Activate );
      Serial1.println("\b");
      delay(200);  
      
      Serial.print(F("Blade Motor PWM = "));
      Serial.println(PWM_Blade_Speed);
      Serial.print(F("Cutting Blade Activated = "));
      Serial.println(Cutting_Blades_Activate);
      Serial.println(F(" "));
      }

void Transmit_Save_Movement_Values() {
      Serial.println("TX Movement to MEGA");
      
      Serial1.print(Max_Cycles_Straight / 10);
      Serial1.println("\a");
      delay(300);  

      Serial1.print(Mower_Turn_Delay_Min / 100);
      Serial1.println("\b");
      delay(200);  

      Serial1.print(Mower_Turn_Delay_Max / 100);
      Serial1.println("\c");
      delay(200);  

      Serial1.print(Mower_Reverse_Delay / 100);
      Serial1.println("\d");
      delay(200);  
      
      Serial.print(F("Max Mow Length = "));
      Max_Cycles_Straight = Max_Cycles_Straight;
      Serial.println(Max_Cycles_Straight);
      
      Serial.print(F("Turn Angle Min = "));
      Mower_Turn_Delay_Min = Mower_Turn_Delay_Min;
      Serial.println(Mower_Turn_Delay_Min);
      
      Serial.print(F("Turn Angle Max = "));
      Mower_Turn_Delay_Max = Mower_Turn_Delay_Max;
      Serial.println(Mower_Turn_Delay_Max);
      
      Serial.print(F("Reverse Distance = "));
      Mower_Reverse_Delay = Mower_Reverse_Delay;
      Serial.println(Mower_Reverse_Delay);
      }


void Transmit_Saved_Tracking_Exit_Values() {
      Serial.println("TX Track Exit MEGA");
      
      Serial1.print(Track_Wire_Zone_1_Cycles / 100);
      Serial1.println("\a");
      delay(300);  
      
      Serial1.print(Track_Wire_Zone_2_Cycles / 100);
      Serial1.println("\b");
      delay(200);
        
      Serial1.print(CCW_Tracking_To_Start);
      Serial1.println("\c");
      delay(200);  

      Serial.print(F("Track Wire Zone 1 = "));
      Serial.println(Track_Wire_Zone_1_Cycles);      
      Serial.print(F("Track Wire Zone 2 = "));
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
        }  
      }

void Transmit_Saved_Tracking_Find_Wire_Values() {
      Serial.println("TX Track Find Wire MEGA");
      
      Serial1.print(Max_Cycle_Wire_Find / 100);
      Serial1.println("\a");
      delay(300);  

      Serial1.print(Max_Cycle_Wire_Find_Back / 10);
      Serial1.println("\b");
      delay(200);  

      Serial1.print(Home_Wire_Compass_Heading);
      Serial1.println("\c");
      delay(200);  

      Serial.print(F("Wire Find Forwards / cylces = "));
      Serial.println(Max_Cycle_Wire_Find);
      
      Serial.print(F("Wire Find Backwards / cylces = "));
      Serial.println(Max_Cycle_Wire_Find_Back);
      
      Serial.print(F("Home Compass Heading / degrees "));
      Serial.println(Home_Wire_Compass_Heading);      
      }


void  Transmit_Tracking_Menu_Values() {
      Serial.println("TX Tracking MEGA");
    
      Serial1.print(Use_Charging_Station);
      Serial1.println("\a");
      delay(300); 
      
      Serial.print(F("Use Charging Station = "));
      Serial.println(Use_Charging_Station); 
      } 

void Transmit_Saved_Tracking_PID_Values() {
      Serial.println("TX Find Wire MEGA");
      
      Serial1.print(Max_Tracking_Turn_Left / 10);
      Serial1.println("\a");
      delay(300);  

      Serial1.print(Max_Tracking_Turn_Right / 10);
      Serial1.println("\b");
      delay(200);  

      Serial1.print(P * 100);
      Serial1.println("\c");
      delay(200);  

      Serial.print(F("Max Cycles Left Wheel = "));
      Serial.println(Max_Tracking_Turn_Left);
      Serial.print(F("Max Cyckes Right Wheel = "));
      Serial.println(Max_Tracking_Turn_Right);         
      Serial.print(F("PID P = "));
      Serial.println(P);
      Serial.println(F(" "));     
      }

void Transmit_Navigation_Menu_Values() {
      Serial.println("TX Nav to MEGA");
      
      Serial1.print(Compass_Activate);
      Serial1.println("\a");
      delay(300);  

      Serial1.print(Compass_Heading_Hold_Enabled);
      Serial1.println("\b");
      delay(200);  

      Serial1.print(CPower * 10);
      Serial1.println("\c");
      delay(200);  

      Serial1.print(GPS_Enabled);
      Serial1.println("\d");
      delay(200);  

      Serial.print(F("Compass Activated = "));
      Serial.println(Compass_Activate);
      Serial.print(F("Heading Hold Enebaled = "));
      Serial.println(Compass_Heading_Hold_Enabled);          
      Serial.print(F("Compass Power = "));
      Serial.println(CPower);    
      Serial.print(F("GPS Enabled = "));
      Serial.println(GPS_Enabled);   
      }

void Transmit_Save_Alarm1_Values() {
      Serial.println("TX Alarm1 to MEGA");
      
      Serial1.print(Alarm_1_ON);
      Serial1.println("\a");
      delay(300);  

      Serial1.print(Alarm_1_Hour);
      Serial1.println("\b");
      delay(200);  

      Serial1.print(Alarm_1_Minute);
      Serial1.println("\c");
      delay(200);  

      Serial1.print(Alarm_1_Repeat);
      Serial1.println("\d");
      delay(200);  

      Serial1.print(Alarm_1_Action);
      Serial1.println("\e");
      delay(200); 

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



void Transmit_Save_Alarm2_Values() {
      Serial.println("TX Alarm1 to MEGA");
      
      Serial1.print(Alarm_2_ON);
      Serial1.println("\a");
      delay(300);  

      Serial1.print(Alarm_2_Hour);
      Serial1.println("\b");
      delay(200);  

      Serial1.print(Alarm_2_Minute);
      Serial1.println("\c");
      delay(200);  

      Serial1.print(Alarm_2_Repeat);
      Serial1.println("\d");
      delay(200);  

      Serial1.print(Alarm_2_Action);
      Serial1.println("\e");
      delay(200); 

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

void Transmit_Save_Alarm3_Values() {
      Serial.println("TX Alarm3 to MEGA");
      
      Serial1.print(Alarm_3_ON);
      Serial1.println("\a");
      delay(300);  

      Serial1.print(Alarm_3_Hour);
      Serial1.println("\b");
      delay(200);  

      Serial1.print(Alarm_3_Minute);
      Serial1.println("\c");
      delay(200);  

      Serial1.print(Alarm_3_Repeat);
      Serial1.println("\d");
      delay(200);  

      Serial1.print(Alarm_3_Action);
      Serial1.println("\e");
      delay(200); 

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


void Transmit_Save_Set_Time_Values() {
      Serial.println("TX Time to MEGA");
      
      Serial1.print(Time_Hour);
      Serial1.println("\a");
      delay(100);  

      Serial1.print(Time_Minute);
      Serial1.println("\b");
      delay(100); 

      Serial.print(F("Time Now = "));
      Serial.print(Time_Hour);
      Serial.print(F(":"));
      Serial.println(Time_Minute);
}

void   Transmit_Saved_Pattern_Values() {
      
      Serial.println(F("TX Pattern to MEGA"));
      
      Serial1.print(Pattern_Mow );
      Serial1.println("\a");
      delay(300); 
      
      Serial1.print(Turn_90_Delay_LH / 10);
      Serial1.println("\b");
      delay(300);  

      Serial1.print(Turn_90_Delay_RH / 10);
      Serial1.println("\c");
      delay(300);  

      Serial1.print(Move_to_next_line_delay / 10);
      Serial1.println("\d");
      delay(300);  

      Serial1.print(Line_Length_Cycles);
      Serial1.println("\e");
      delay(300);          
      
      
      Serial.print(F("Pattern Mow"));
      if (Pattern_Mow == 0) Serial.println("OFF");
      if (Pattern_Mow == 1) Serial.println("Parallel");  
      if (Pattern_Mow == 3) Serial.println("Spiral"); 
      
      Serial.print(F("Turn 90° LH= "));
      Serial.println(Turn_90_Delay_LH);
      
      Serial.print(F("Turn 90° RH= "));
      Serial.println(Turn_90_Delay_RH);
      
      Serial.print(F("Distance to next row= "));
      Serial.println(Move_to_next_line_delay);
      
      Serial.print(F("Row Length= "));
      Serial.println(Line_Length_Cycles);      
      
      }


void Transmit_Mower_Start_Conditions_Exit_Dock() {
      Serial.println("TX Start Cond to MEGA");
      
      Serial1.print(Exit_Zone);
      Serial1.println("\a");
      delay(300);  

      Serial1.print(Mow_Time);
      Serial1.println("\b");
      delay(200);  

      Serial.print(F("Exit Zone Selected = "));
      Serial.println(Exit_Zone);
      Serial.print(F("Mow Time Selected = "));
      if ( (Mow_Time == 1) || (Mow_Time == 2 ) ){
          Serial.print(Mow_Time);
          Serial.println(" hrs");
          }
      if (Mow_Time == 3) Serial.println(F("Max Mow Time"));
      
      }



void Transmit_Mower_Start_Conditions_Quick_Start() {
      Serial.println("TX Start Cond to MEGA");
      
      Serial1.print(Mow_Time);
      Serial1.println("\a");
      delay(200);  

      Serial.println(F("Quick Start Selected"));
      Serial.println(Exit_Zone);
      Serial.print(F("Mow Time Selected = "));
      if ( (Mow_Time == 1) || (Mow_Time == 2 ) ){
          Serial.print(Mow_Time);
          Serial.println(" hrs");
          }
      if (Mow_Time == 3) Serial.println(F("Max Mow Time"));
      
      }

      
void Transmit_Saved_Tip_Sensor_Values() {
      Serial.println("TX Tip Sensor to MEGA");
      
      Serial1.print(Angle_Sensor_Enabled);
      Serial1.println("\a");
      delay(300);  

      Serial1.print(Tip_Over_Sensor_Enabled);
      Serial1.println("\b");
      delay(200);  
      
      Serial.print(F("Tilt Angle Sensor = "));
      Serial.println(Angle_Sensor_Enabled);
      Serial.print(F("Tip Over Sensor = "));
      Serial.println(Tip_Over_Sensor_Enabled);
      Serial.println(F(" "));
      }


void Transmit_Saved_GPS_Values() {
      Serial.println(F("TX GPS Settings to ESP32"));
      
      Serial2.print(GPS_WIFI_Enabled);
      Serial2.println("\a");
      delay(200);
      
      Serial2.print(Simulation_Mode);
      Serial2.println("\b");
      delay(200);

      Serial2.print(Fence);
      Serial2.println("\c");
      delay(1000); 
      Serial2.flush();
      
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
