// These fucntions transfer the information back again to the Mower MEGA
// once the values have beend reviewed or modified in the TFT GUI.
// The values


void TX_7_Data_Values() {
      Serial.println("Sending Data Sets");
      delay(200); 
      Serial1.print(Data1);
      Serial1.println("\a");
      delay(200);  
      Serial1.print(Data2);
      Serial1.println("\b");
      delay(200);  
      Serial1.print(Data3);
      Serial1.println("\c");
      delay(200);  
      Serial1.print(Data4);
      Serial1.println("\d");
      delay(200);
      Serial1.print(Data5);
      Serial1.println("\e");
      delay(200);
      Serial1.print(Data6);
      Serial1.println("\f");
      delay(200);
      Serial1.print(Data7);
      Serial1.println("\g");
      delay(200);
      
      Serial.print(F("Data1:"));
      Serial.println(Data1);
      Serial.print(F("Data2:"));
      Serial.println(Data2);
      Serial.print(F("Data3:"));
      Serial.println(Data3);  
      Serial.print(F("Data4:"));
      Serial.println(Data4);
      Serial.print(F("Data5:"));
      Serial.println(Data5);
      Serial.print(F("Data6:"));
      Serial.println(Data6);
      Serial.print(F("Data7:"));
      Serial.println(Data7);    
      }


// Menu Sonar TX
void Transmit_Save_Sonar_Values() {
      Serial.println("TX Sonar");
      delay(5);
      Data1 = Sonar_1_Activate;
      Data2 = Sonar_2_Activate;
      Data3 = Sonar_3_Activate;
      Data4 = maxdistancesonar;
      Data5 = Max_Sonar_Hit;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values();
      Serial.print(F("S2 Activated = "));
      Serial.println(Sonar_2_Activate);
      Serial.print(F("S1 Activated = "));
      Serial.println(Sonar_1_Activate);
      Serial.print(F("S3 Activated = "));
      Serial.println(Sonar_3_Activate);
      Serial.print(F("SMax Distance = "));
      Serial.println(maxdistancesonar);
      Serial.print(F("S Sens'y = "));
      Serial.println(Max_Sonar_Hit);
      }

void  Transmit_Saved_Battery_Values() {
      Serial.println("TX Batt");
      Data1 = Battery_Min * 10;
      Data2 = Low_Battery_Instances_Chg;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values();
      Serial.print(F("Batt Min = "));
      Serial.println(Battery_Min);
      Serial.print(F("Batt Sens'y = "));
      Serial.println(Low_Battery_Instances_Chg);      
      }

void Transmit_Sensor_Menu1_Values() {
      Serial.println("TX Sensor");
      Data1 = Perimeter_Wire_Enabled;
      Data2 = WIFI_Enabled;
      Data3 = Bumper_Activate_Frnt;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values();      
      Serial.print(F("Wire ON = "));
      Serial.println(Perimeter_Wire_Enabled);
      Serial.print(F("WIFI ON = "));
      Serial.println(WIFI_Enabled);
      Serial.print(F("Bumper ON = "));
      Serial.println(Bumper_Activate_Frnt);
      }

void Transmit_Saved_Rain_Sensor_Values () {
      Serial.println("TX Rain");
      Data1 = Rain_Sensor_Installed;
      Data2 = Rain_Total_Hits_Go_Home;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values();            
      Serial.print(F("Rain ON/OFF = "));
      Serial.println(Rain_Sensor_Installed);
      Serial.print(F("Rain Sensy = "));
      Serial.println(Rain_Total_Hits_Go_Home);
      }


void Transmit_Wheel_Motor_Values() {
      Serial.println("TX Wheel Motor");
      Data1 = PWM_MaxSpeed_LH;
      Data2 = PWM_MaxSpeed_RH;
      Data3 = PWM_Slow_Speed_LH;
      Data4 = PWM_Slow_Speed_RH;
      Data5 = Slow_Speed_MAG / 10;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values();  
      Serial.print(F("Wheel PWM LH = "));
      Serial.println(PWM_MaxSpeed_LH);
      Serial.print(F("Wheel PWM RH = "));
      Serial.println(PWM_MaxSpeed_RH);
      Serial.print(F("Wheel Slow PWMLH = "));
      Serial.println(PWM_Slow_Speed_LH);
      Serial.print(F("Wheel Slow PWMRH = "));
      Serial.println(PWM_Slow_Speed_RH);
      Serial.print(F("Slow Speed MAG = "));
      Serial.println(Slow_Speed_MAG);
      Serial.println(F(" "));
      }

void Transmit_Blade_Motor_Values() {
      Serial.println("TX Blade");
      Data1 = PWM_Blade_Speed;
      Data2 = Cutting_Blades_Activate;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values();  
      Serial.print(F("Blade PWM = "));
      Serial.println(PWM_Blade_Speed);
      Serial.print(F("Blade ON = "));
      Serial.println(Cutting_Blades_Activate);
      Serial.println(F(" "));
      }

void Transmit_Setup_Other_Values() {
      Serial.println("TX PCB");
      Data1 = PCB;
      Data2 = 0;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values();  
      Serial.print(F("PCB = "));
      if (PCB == 1) Serial.println(F("Enabled"));
      if (PCB == 0) Serial.println(F("Disabled"));
      Serial.println(" ");
      }

void Transmit_Save_Movement_Values() {
      Serial.println("TX Movement");
      Data1 = Max_Cycles_Straight / 10;
      Data2 = Mower_Turn_Delay_Min / 100;
      Data3 = Mower_Turn_Delay_Max / 100;
      Data4 = Mower_Reverse_Delay / 100;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values();  
      Serial.print(F("Max Mow Length = "));
      Serial.println(Max_Cycles_Straight);      
      Serial.print(F("Turn° Min = "));
      Serial.println(Mower_Turn_Delay_Min);
      Serial.print(F("Turn° Max = "));
      Serial.println(Mower_Turn_Delay_Max);
      Serial.print(F("R Distance = "));
      Serial.println(Mower_Reverse_Delay);
      }


void Transmit_Saved_Tracking_Exit_Values() {
      Serial.println("TX Exit");
      Data1 = Track_Wire_Zone_1_Cycles / 100;
      Data2 = Track_Wire_Zone_2_Cycles / 100;
      Data3 = CCW_Tracking_To_Start;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values();  
      Serial.print(F("Zone 1 = "));
      Serial.println(Track_Wire_Zone_1_Cycles);      
      Serial.print(F("Zone 2 = "));
      Serial.println(Track_Wire_Zone_2_Cycles);     
      if (CCW_Tracking_To_Start == 0) {
        CW_Tracking_To_Start = 1;
        CCW_Tracking_To_Charge = 1;
        CW_Tracking_To_Charge = 0;
        Serial.println(F("Track to Charge = CCW"));
        Serial.println(F("Track to Start = CW"));
        }
      if (CCW_Tracking_To_Start == 1) {
        CW_Tracking_To_Start = 0;
        CCW_Tracking_To_Charge = 0;
        CW_Tracking_To_Charge = 1;      
        Serial.println(F("Track to Charge = CW"));
        Serial.println(F("Track to Start = CCW"));        
        }  
      }

void Transmit_Saved_Tracking_Find_Wire_Values() {
      Serial.println("TX Wire");
      Data1 = Max_Cycle_Wire_Find / 100;
      Data2 = Max_Cycle_Wire_Find_Back / 10;
      Data3 = Home_Wire_Compass_Heading;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values();  
      Serial.print(F("Wire Find Forwards= "));
      Serial.println(Max_Cycle_Wire_Find);      
      Serial.print(F("Wire Find Backwards= "));
      Serial.println(Max_Cycle_Wire_Find_Back);
      Serial.print(F("Home Compass Heading°"));
      Serial.println(Home_Wire_Compass_Heading);      
      }


void  Transmit_Tracking_Menu_Values() {
      Serial.println("TX Tracking");
      Data1 = Use_Charging_Station;
      Data2 = 0;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values(); 
      Serial.print(F("Docking ON = "));
      Serial.println(Use_Charging_Station); 
      } 

void Transmit_Saved_Tracking_PID_Values() {
      Serial.println("TX Find");
      Data1 = Max_Tracking_Turn_Left / 10;
      Data2 = Max_Tracking_Turn_Right / 10;
      P = P * 100;
      int PTX = P;
      Data3 = PTX;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values(); 
      Serial.print(F("Max Cycles LWheel = "));
      Serial.println(Max_Tracking_Turn_Left);
      Serial.print(F("Max Cycles RWheel = "));
      Serial.println(Max_Tracking_Turn_Right);         
      Serial.print(F("PID P = "));
      Serial.println(P);
      Serial.println(F(" "));     
      }

void Transmit_Compass_Menu_Values() {
      Serial.println("TX Compass");
      Data1 = Compass_Activate;
      Data2 = Compass_Heading_Hold_Enabled;
      Data3 = CPower * 10;
      Data4 = Compass_Setup_Mode;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values();       
      Serial.print(F("Compass ON = "));
      Serial.println(Compass_Activate);
      Serial.print(F("HHold ON= "));
      Serial.println(Compass_Heading_Hold_Enabled);   
      Serial.print(F("C-Power = "));
      Serial.println(CPower);    
      Serial.print(F("C-Setup Mode = "));
      Serial.println(Compass_Setup_Mode); 

}

void Transmit_GYRO_Menu_Values() {
      Serial.println("TX GYRO");
      Data1 = GYRO_Enabled;
      Data2 = GPower * 10;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values();    
      Serial.print(F("GYRO Enabled = "));
      Serial.println(GYRO_Enabled);   
      Serial.print(F("GPower = "));
      Serial.println(GPower);  
      }


void Transmit_Navigation_Menu_Values() {
      Serial.println("TX Nav");
      Data1 = GPS_Enabled;
      Data2 = 0;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values();  
      Serial.print(F("GPS ON = "));
      Serial.println(GPS_Enabled);   
      }


      

void Transmit_Save_Alarm1_Values() {
      Serial.println("TX A1");
      Data1 = Alarm_1_ON;
      Data2 = Alarm_1_Hour;
      Data3 = Alarm_1_Minute;
      Data4 = Alarm_1_Repeat;
      Data5 = Alarm_1_Action;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values();  
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
      Serial.println("TX A2");
      Data1 = Alarm_2_ON;
      Data2 = Alarm_2_Hour;
      Data3 = Alarm_2_Minute;
      Data4 = Alarm_2_Repeat;
      Data5 = Alarm_2_Action;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values();  
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
      Serial.println("TX A3");
      Data1 = Alarm_3_ON;
      Data2 = Alarm_3_Hour;
      Data3 = Alarm_3_Minute;
      Data4 = Alarm_3_Repeat;
      Data5 = Alarm_3_Action;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values();        
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
      Serial.println("TX Time");
      Data1 = Time_Hour;
      Data2 = Time_Minute;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values(); 
      Serial.print(F("Time Now = "));
      Serial.print(Time_Hour);
      Serial.print(F(":"));
      Serial.println(Time_Minute);
      }

void Transmit_Saved_Pattern_Values() {      
      Serial.println(F("TX Pattern"));
      Data1 = Pattern_Mow;
      Data2 = Turn_90_Delay_LH / 10;
      Data3 = Turn_90_Delay_RH / 10;
      Data4 = Move_to_next_line_delay / 10;
      Data5 = Line_Length_Cycles;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values(); 
      Serial.print(F("P-Mow"));
      if (Pattern_Mow == 0) Serial.println(F("OFF"));
      if (Pattern_Mow == 1) Serial.println(F("Parallel"));  
      if (Pattern_Mow == 3) Serial.println(F("Spiral"));      
      Serial.print(F("Turn90° LH= "));
      Serial.println(Turn_90_Delay_LH);     
      Serial.print(F("Turn90° RH= "));
      Serial.println(Turn_90_Delay_RH);      
      Serial.print(F("Row Space= "));
      Serial.println(Move_to_next_line_delay);      
      Serial.print(F("Row Length= "));
      Serial.println(Line_Length_Cycles);            
      }


void Transmit_Mower_Start_Conditions_Exit_Dock() {
      Serial.println("TX Start");
      Data1 = Exit_Zone;
      Data2 = Mow_Time;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values(); 
      Serial.print(F("Exit Zone = "));
      Serial.println(Exit_Zone);
      Serial.print(F("Mow Time = "));
      if ( (Mow_Time == 1) || (Mow_Time == 2 ) ){
          Serial.print(Mow_Time);
          Serial.println(" hrs");
          }
      if (Mow_Time == 3) Serial.println(F("Max Mow Time"));      
      }



void Transmit_Mower_Start_Conditions_Quick_Start() {
      Serial.println("TX QStart");
      Data1 = Mow_Time;
      Data2 = 0;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values();       
      Serial.println(F("Quick Start: "));
      Serial.println(Exit_Zone);
      Serial.print(F("Mow Time = "));
      if ( (Mow_Time == 1) || (Mow_Time == 2 ) ){
          Serial.print(Mow_Time);
          Serial.println(" hrs");
          }
      if (Mow_Time == 3) Serial.println(F("Max Mow Time"));      
      }

      
void Transmit_Saved_Tip_Sensor_Values() {
      Serial.println("TX Tip");
      Data1 = Angle_Sensor_Enabled;
      Data2 = Tip_Over_Sensor_Enabled;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values(); 
      Serial.print(F("Tilt° Sensor = "));
      Serial.println(Angle_Sensor_Enabled);
      Serial.print(F("Flip Sensor = "));
      Serial.println(Tip_Over_Sensor_Enabled);
      Serial.println(F(" "));
      }


void Transmit_Saved_Wheel_Block_Values() {
      Serial.println("TX Wheel Amp");
      Data1 = Wheel_Amp_Sensor_ON;
      Data2 = Max_Wheel_Amps * 10;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;
      TX_7_Data_Values(); 
    Serial.print(F("Wheel Amp: "));
        if (Wheel_Amp_Sensor_ON == 1) Serial.println("ON");
        if (Wheel_Amp_Sensor_ON == 0) Serial.println("OFF");    
    Serial.print(F("Wheel Amps Max: "));
    Serial.print(Max_Wheel_Amps);
    }



// GPS is on serial 2
void Transmit_Saved_GPS_Values() {
      Serial.println(F("TX GPS ESP32"));
      
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

      Serial1.print(GPS_Enabled);
      Serial1.println("\d");
      delay(200);  

      
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
