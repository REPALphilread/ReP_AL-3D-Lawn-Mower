void Receive_7_Data_Sets_Serial3() {
  
  Serial.println("Receiving Data Sets");
  delay(1100);
  String Serial3_RX_Value  = "";                                            
      
  while (Serial3.available() > 0) {
    
    char recieved = Serial3.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c' && recieved != '\d' && recieved != '\e' 
    && recieved != '\f' && recieved != '\g') {   
      Serial3_RX_Value = Serial3_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Data1 = Serial3_RX_Value.toInt();                                 
      Serial3_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      Data2 = Serial3_RX_Value.toInt();                         
      Serial3_RX_Value = "";
      } 
      else if (recieved == '\c') {
      Data3 = Serial3_RX_Value.toInt();                           
      Serial3_RX_Value = "";
      } 
      else if (recieved == '\d') {
      Data4 = Serial3_RX_Value.toInt();                       
      Serial3_RX_Value = "";
      } 
      else if (recieved == '\e') {
      Data5 = Serial3_RX_Value.toInt();                          
      Serial3_RX_Value = "";
      } 
      else if (recieved == '\f') {
      Data6 = Serial3_RX_Value.toInt();                          
      Serial3_RX_Value = "";
      } 
      else if (recieved == '\g') {
      Data7 = Serial3_RX_Value.toInt();                          
      Serial3_RX_Value = "";
      } 
    
    else Serial.print(F("No Data Received|"));
  }

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
  Serial.println(F(""));
}




void Receive_Data_From_TFT()  {

  // Receive the Sonar Values Back again
  if (TFT_Menu_Command == 910) {     
      Serial.println(F("Receiving Sonar Data from TFT ..."));
      Receive_7_Data_Sets_Serial3();
      Sonar_1_Activate  = Data1;
      Sonar_2_Activate  = Data2;
      Sonar_3_Activate  = Data3;
      maxdistancesonar  = Data4;
      Max_Sonar_Hit     = Data5;
      Data6 = 0;
      Data7 = 0;
      Serial.print(F("S1 ON = "));
      Serial.println(Sonar_1_Activate);
      Serial.print(F("S2 ON = "));
      Serial.println(Sonar_2_Activate);
      Serial.print(F("S3 ON = "));
      Serial.println(Sonar_3_Activate);
      Serial.print(F("Max Distance = "));
      Serial.println(maxdistancesonar);
      Serial.print(F("Sensitivity = "));
      Serial.println(Max_Sonar_Hit);
      EEPROM.write(37, 1);
      EEPROM.write(38, Sonar_1_Activate);
      EEPROM.write(39, 1);
      EEPROM.write(40, Sonar_2_Activate);
      EEPROM.write(41, 1);
      EEPROM.write(42, Sonar_3_Activate);
      EEPROM.write(65, 1);
      EEPROM.write(66, maxdistancesonar); 
      EEPROM.write(63, 1);
      EEPROM.write(64, Max_Sonar_Hit);         
      Serial.println(F("Saved to EEPROM"));    
      Serial.println(F(" "));
      }

// Receive the Battery Values Back again
  if (TFT_Menu_Command == 911) {
      Serial.println(F("Receiving Battery Data from TFT ..."));
      Receive_7_Data_Sets_Serial3();
      Battery_Min               = Data1;
      Low_Battery_Instances_Chg = Data2;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;                                          
      Serial.print(F("Battery Min = "));
      Battery_Min = Battery_Min / 10;    
      Serial.println(Battery_Min);      
      Serial.print(F("Battery Sensitivity = "));
      Serial.println(Low_Battery_Instances_Chg);
      EEPROM.write(25, 1);
      EEPROM.write(26, (Battery_Min * 10));   
      EEPROM.write(85, 1);
      EEPROM.write(86, Low_Battery_Instances_Chg); 
      Serial.println(F("Saved to EEPROM"));
      Serial.println(F(" "));
      }
  
// Receive the Sensor Menu 1 Values Back again
  if (TFT_Menu_Command == 96) {
      Serial.println(F("Receiving Sensor Menu 1 Values from TFT ..."));
      Receive_7_Data_Sets_Serial3();
      Perimeter_Wire_Enabled  = Data1;
      WIFI_Enabled            = Data2;
      Bumper_Activate_Frnt    = Data3;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;  
      Serial.print(F("Wire Module Activated = "));
      Serial.println(Perimeter_Wire_Enabled);
      Serial.print(F("WIFI Enabled = "));
      Serial.println(WIFI_Enabled);
      Serial.print(F("Bumper Activated = "));
      Serial.println(Bumper_Activate_Frnt);     
      EEPROM.write(67 , 1);
      EEPROM.write(68 , Perimeter_Wire_Enabled);
      EEPROM.write(81 , 1);
      EEPROM.write(82 , WIFI_Enabled);
      EEPROM.write(90 , 1);
      EEPROM.write(91 , Bumper_Activate_Frnt);
      Serial.println(F("Saved to EEPROM"));
      Serial.println(F(" "));
  }



// Receive the Rain Sensor Values Back again
  if (TFT_Menu_Command == 912) {
      Serial.println(F("Receiving Rain Sensor Values from TFT ..."));
      Receive_7_Data_Sets_Serial3();
      Rain_Sensor_Installed   = Data1;
      Rain_Total_Hits_Go_Home = Data2;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;  
      Serial.print(F("Rain ON = "));
      Serial.println(Rain_Sensor_Installed);
      Serial.print(F("Sensitivity = "));
      Serial.println(Rain_Total_Hits_Go_Home);     
      EEPROM.write(77 , 1);
      EEPROM.write(78 , Rain_Sensor_Installed);
      EEPROM.write(79, 1);
      EEPROM.write(80, Rain_Total_Hits_Go_Home);   
      Serial.println(F("Saved to EEPROM"));
      Serial.println(F(" "));
    }


// Receive the Mower Motor Values Back again
  if (TFT_Menu_Command == 914) {
      Serial.println(F("Receiving Mower Motor Values from TFT ..."));
      Receive_7_Data_Sets_Serial3();
      PWM_MaxSpeed_LH   = Data1;
      PWM_MaxSpeed_RH   = Data2;
      PWM_Slow_Speed_LH = Data3;
      PWM_Slow_Speed_RH = Data4;
      Slow_Speed_MAG    = Data5;
      Data6 = 0;
      Data7 = 0;  
      Serial.print(F("Wheel Motor PWM LH = "));
      Serial.println(PWM_MaxSpeed_LH);
      Serial.print(F("Wheel Motor PWM RH = "));
      Serial.println(PWM_MaxSpeed_RH);
      Serial.print(F("Wheel Motor Wire Speed PWM LH = "));
      Serial.println(PWM_Slow_Speed_LH);
      Serial.print(F("Wheel Motor Wire Speed PWM RH = "));
      Serial.println(PWM_Slow_Speed_RH);
      Serial.print(F("Slow Speed MAG = "));     
      Slow_Speed_MAG = Slow_Speed_MAG * 10;
      Serial.println(Slow_Speed_MAG);
      Serial.println(F(" "));      
      EEPROM.write(13, 1);
      EEPROM.write(14, PWM_MaxSpeed_LH);
      EEPROM.write(15, 1);
      EEPROM.write(16, PWM_MaxSpeed_RH);    
      EEPROM.write(94, 1);
      EEPROM.write(95, PWM_Slow_Speed_LH);
      EEPROM.write(96, 1);
      EEPROM.write(97, PWM_Slow_Speed_RH);   
      EEPROM.write(98, 1);
      EEPROM.write(99, ((Slow_Speed_MAG * -1 ) / 10));   
      Serial.println(F("Saved to EEPROM"));
      Serial.println(F(" "));
  }

  
// Receive the Mower Motor Values Back again
  if (TFT_Menu_Command == 915) {
      Serial.println(F("Receiving Blade Motor Values from TFT ..."));
      Receive_7_Data_Sets_Serial3();
      PWM_Blade_Speed           = Data1;
      Cutting_Blades_Activate   = Data2;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;   
      Serial.print(F("Blade Motor PWM = "));
      Serial.println(PWM_Blade_Speed);
      Serial.print(F("Cutting Blade Activated = "));
      Serial.println(Cutting_Blades_Activate);
      EEPROM.write(17, 1);
      EEPROM.write(18, PWM_Blade_Speed);   
      EEPROM.write(83 , 1);
      EEPROM.write(84 , Cutting_Blades_Activate);
      Serial.println(F("Saved to EEPROM"));
      Serial.println(F(" "));
  }



// Receive Movement Values from TFT
  if (TFT_Menu_Command == 916) {
      Serial.println(F("Receiving Movement Values from TFT ..."));
      Receive_7_Data_Sets_Serial3();
      Max_Cycles_Straight    = Data1;
      Mower_Turn_Delay_Min   = Data2;
      Mower_Turn_Delay_Max   = Data3;
      Mower_Reverse_Delay    = Data4;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;   
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
      //EEPROM
      EEPROM.write(57, 1);
      EEPROM.write(58, (Max_Cycles_Straight / 10));
      EEPROM.write(31, 1);
      EEPROM.write(32, (Mower_Turn_Delay_Min/100));
      EEPROM.write(33, 1);
      EEPROM.write(34, (Mower_Turn_Delay_Max/100));
      EEPROM.write(35, 1);
      EEPROM.write(36, (Mower_Reverse_Delay/100));
      Serial.println(F("Saved to EEPROM"));
      Serial.println(F(" "));
  }



// Receive the Mower Motor Values Back again
  if (TFT_Menu_Command == 917) {
      Serial.println(F("Receiving Track Exit Values from TFT ..."));
      Receive_7_Data_Sets_Serial3();
      Track_Wire_Zone_1_Cycles  = Data1 * 100;
      Track_Wire_Zone_2_Cycles  = Data2 * 100;
      CCW_Tracking_To_Start     = Data3 * 100;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;  
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
      //EEPROM
      EEPROM.write(43, 1);
      EEPROM.write(44, (Track_Wire_Zone_1_Cycles/100));
      EEPROM.write(45, 1);
      EEPROM.write(46, (Track_Wire_Zone_2_Cycles/100));
      EEPROM.write(49 , 1);
      EEPROM.write(50 , CW_Tracking_To_Charge);                
      EEPROM.write(51 , 1);
      EEPROM.write(52 , CCW_Tracking_To_Charge);       
      EEPROM.write(53 , 1);
      EEPROM.write(54 , CW_Tracking_To_Start);                
      EEPROM.write(55 , 1);
      EEPROM.write(56 , CCW_Tracking_To_Start);  
      Serial.println(F("Saved to EEPROM"));
      Serial.println(F(" "));
  }


// Receive the Mower Motor Values Back again
  if (TFT_Menu_Command == 918) {
      Serial.println(F("Receiving Find Wire Values from TFT ..."));
      Receive_7_Data_Sets_Serial3();
      Max_Cycle_Wire_Find       = Data1 * 100;
      Max_Cycle_Wire_Find_Back  = Data2 * 10;
      Home_Wire_Compass_Heading = Data3;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;   
      Serial.print(F("Wire Find Forwards / Cycles = "));
      Serial.println(Max_Cycle_Wire_Find);
      Serial.print(F("Wire Find Forwards / Cycles = "));
      Serial.println(Max_Cycle_Wire_Find_Back);    
      Serial.print(F("Home Compass Heading / degrees "));
      Serial.println(Home_Wire_Compass_Heading);   
      // EEPROM
      EEPROM.write(69, 1);
      EEPROM.write(70, (Max_Cycle_Wire_Find/10));
      EEPROM.write(71, 1);
      EEPROM.write(72, (Max_Cycle_Wire_Find_Back/10));
      EEPROM.write(27, 1);
      EEPROM.write(28, (Home_Wire_Compass_Heading/10));   
      Serial.println(F("Saved to EEPROM"));
      Serial.println(F(" "));
  }


// Charging Station Options
  if (TFT_Menu_Command == 98) {
      Serial.println(F("Charging Station"));
      Receive_7_Data_Sets_Serial3();
      Use_Charging_Station = Data1;
      Data2 = 0;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0; 
      Serial.print(F("Use Charging Station = "));
      Serial.println(Use_Charging_Station);   
      // EEPROM
      EEPROM.write(47 , 1);
      EEPROM.write(48 , Use_Charging_Station);
      Serial.println(F("Saved to EEPROM"));
      Serial.println(F(" "));
      }



// Receive the Mower Start Conditions from the TFT Screen
  if (TFT_Menu_Command == 93) {
      Serial.println(F("RX Mower Exit Dock Start"));
      Receive_7_Data_Sets_Serial3();
      Exit_Zone     = Data1;
      Mow_Time_Set  = Data2;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0; 
      Serial.print(F("Exit Zone Selected = "));
      Serial.println(Exit_Zone);
      Serial.print(F("Mow Time Selected = "));
      if ( (Mow_Time_Set == 1) || (Mow_Time_Set == 2 ) ){
          Serial.print(Mow_Time_Set);
          Serial.println(F(" hrs"));
          }
      if (Mow_Time_Set == 3) Serial.println(F("Max Mow Time"));
      Serial.println(F(" "));

    if (Exit_Zone == 1) Track_Wire_Itterations = Track_Wire_Zone_1_Cycles;
    if (Exit_Zone == 2) Track_Wire_Itterations = Track_Wire_Zone_2_Cycles;

    if (Mow_Time_Set ==3) Alarm_Timed_Mow_ON = 0;
    if (Mow_Time_Set < 3) {
        Time t = rtc.time();
        Alarm_Timed_Mow_ON = 1;                          // Activate the Mow Timer Alarm
        Alarm_Timed_Mow_Hour = t.hr +  Mow_Time_Set;     // Sets time to (+Mow_Time_Set 1 or 2 )hour later.
        Alarm_Timed_Mow_Minute = t.min;                  // Minutes are the same
        }
    
    TFT_Menu_Command = 1; 
    Manouver_Exit_To_Zone_X();                           // Exit the Dock
                        
    }


// Receive PID Values
  if (TFT_Menu_Command == 919) {
      Serial.println(F("RX PID Values from TFT"));
      Receive_7_Data_Sets_Serial3();
      Max_Tracking_Turn_Left  = Data1 * 10;
      Max_Tracking_Turn_Right = Data2 * 10;
      P                       = Data3;
      P = P / 100;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0; 
      Serial.print(F("Max Cycles Left Wheel = "));
      Serial.println(Max_Tracking_Turn_Left);      
      Serial.print(F("Max Cycles Right Wheel = "));
      Serial.println(Max_Tracking_Turn_Right);               
      Serial.print(F("PID P = "));
      Serial.println(P);
      // EEPROM
      EEPROM.write(73, 1);
      EEPROM.write(74, (Max_Tracking_Turn_Right/10));
      EEPROM.write(75, 1);
      EEPROM.write(76, (Max_Tracking_Turn_Left/10));
      EEPROM.write(21, 1);
      EEPROM.write(22, (P*100));  
      Serial.println(F("Saved to EEPROM"));
      Serial.println(F(" "));
      }


// Receive the Compass data from TFT
  if (TFT_Menu_Command == 926) {
      Serial.println(F("RX Compass from TFT ..."));
      Receive_7_Data_Sets_Serial3();
      Compass_Activate              = Data1;
      Compass_Heading_Hold_Enabled  = Data2;
      CPower                        = Data3 / 10;
      Compass_Setup_Mode            = Data4;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0; 
      Serial.print(F("Compass Activated = "));
      Serial.println(Compass_Activate);
      Serial.print(F("Heading Hold Enabled = "));
      Serial.println(Compass_Heading_Hold_Enabled);        
      Serial.print(F("Compass Power = "));
      Serial.println(CPower);
      Serial.print(F("Compas Setup Mode = "));
      Serial.println(Compass_Setup_Mode); 
      // EEPROM
      EEPROM.write(19 , 1);
      EEPROM.write(20 , Compass_Activate);
      EEPROM.write(59 , 1);
      EEPROM.write(60 , Compass_Heading_Hold_Enabled);
      EEPROM.write(61, 1);
      EEPROM.write(62, (CPower*10)); 
      EEPROM.write(113, 1);
      EEPROM.write(114, Compass_Setup_Mode); 
      Serial.println(F("Saved to EEPROM"));
      Serial.println(F(" "));
      }



// Receive the GYRO data from TFT
  if (TFT_Menu_Command == 928) {
      Serial.println(F("RX GYRO from TFT ..."));
      Receive_7_Data_Sets_Serial3();
      GYRO_Enabled  = Data1;
      GPower        = Data2 / 10;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0; 
      Serial.print(F("GYRO Enabled = "));
      Serial.println(GYRO_Enabled);
      Serial.print(F("GYRO Power = "));
      Serial.println(GPower);      
      if (GYRO_Enabled == 1) Setup_Gyro();
      EEPROM.write(109 , 1);
      EEPROM.write(110, GYRO_Enabled);
      EEPROM.write(111, 1);
      EEPROM.write(112, (GPower*10)); 
      Serial.println(F("Saved to EEPROM"));
      Serial.println(F(" ")); 
      }



// Receive the Time Alarm data from TFT
  if (TFT_Menu_Command == 920) {
      Serial.println(F("RX Alarm 1 TFT ..."));
      Receive_7_Data_Sets_Serial3();
      Alarm_1_ON     = Data1;
      Alarm_1_Hour   = Data2;
      Alarm_1_Minute = Data3;
      Alarm_1_Repeat = Data4;
      Alarm_1_Action = Data5;
      Data6 = 0;
      Data7 = 0; 
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
      //EEPROM
      EEPROM.write(1, 1);
      EEPROM.write(2, Alarm_1_Hour);
      EEPROM.write(3, Alarm_1_Minute);
      EEPROM.write(4, Alarm_1_ON);
      EEPROM.write(87, Alarm_1_Action);
      Serial.println(F("Saved to EEPROM"));
      Serial.println(F(" "));    
  }




// Receive the Alarm 2 data from TFT
  if (TFT_Menu_Command == 921) {
      Serial.println(F("RX Alarm 2 TFT ..."));
      Receive_7_Data_Sets_Serial3();
      Alarm_2_ON     = Data1;
      Alarm_2_Hour   = Data2;
      Alarm_2_Minute = Data3;
      Alarm_2_Repeat = Data4;
      Alarm_2_Action = Data5;
      Data6 = 0;
      Data7 = 0; 
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
      //EEPROM
      EEPROM.write(5, 1);
      EEPROM.write(6, Alarm_2_Hour);
      EEPROM.write(7, Alarm_2_Minute);
      EEPROM.write(8, Alarm_2_ON);
      EEPROM.write(88, Alarm_2_Action);
      Serial.println(F("Saved to EEPROM"));
      Serial.println(F(" "));    
      }


// Receive the Alarm 3 data from TFT
  if (TFT_Menu_Command == 922) {
      Serial.println(F("RX Alarm 3 TFT ..."));
      Receive_7_Data_Sets_Serial3();
      Alarm_3_ON     = Data1;
      Alarm_3_Hour   = Data2;
      Alarm_3_Minute = Data3;
      Alarm_3_Repeat = Data4;
      Alarm_3_Action = Data5;
      Data6 = 0;
      Data7 = 0; 
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
      //EEPROM
      EEPROM.write(9, 1);
      EEPROM.write(10, Alarm_3_Hour);
      EEPROM.write(11, Alarm_3_Minute);
      EEPROM.write(12, Alarm_3_ON);
      EEPROM.write(89, Alarm_3_Action);
      Serial.println(F("Saved to EEPROM"));
      Serial.println(F(" "));    
      }



// Receive the Time data from TFT
  if (TFT_Menu_Command == 923) {
      Serial.println(F("RX Time from TFT ..."));
      String Serial3_RX_Value  = "";          
      int set_hour;
      int set_min;                                   
      Receive_7_Data_Sets_Serial3();
      set_hour   = Data1;
      set_min    = Data2;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0; 

       if (PCB == 0) {           
          rtc.writeProtect(false);
          rtc.halt(false);
          Serial.print(F("Clock : "));
          Serial.print(set_hour);
          Serial.print(":");
          if (set_min < 10) Serial.print("0");
          Serial.println(set_min);
          Time t(2019, 07, 19, set_hour, set_min, 00, Time::kFriday);            // Year XXXX, Month XX, Day XX, Hour XX, Minute XX, Second, kXYZday
          rtc.time(t);    
          delay(200);
          rtc.writeProtect(true);
          rtc.halt(true);
          rtc.time(t); 
          }

      if (PCB == 1) {
          Set_DS3231_Time(00,set_min, set_hour, 2,14,7,20);    //second, minute, hour, dayof week, day of month, month, year
          Serial.println(F("TIME SAVED"));
          delay(2000);
          }
  
  }



  if (TFT_Menu_Command == 929) {
        Serial.println(F("RX Wheel Block"));                               
        Receive_7_Data_Sets_Serial3();
        Wheel_Amp_Sensor_ON   = Data1;
        Max_Wheel_Amps        = Data2 / 10;
        Data3 = 0;
        Data4 = 0;
        Data5 = 0;
        Data6 = 0;
        Data7 = 0;   
        Serial.print(F("Wheel Amp ON: "));
        if (Wheel_Amp_Sensor_ON == 1) Serial.println(F("ON"));
        if (Wheel_Amp_Sensor_ON == 0) Serial.println(F("OFF"));   
        Serial.print(F("Wheel Amps Max: "));
        Serial.print(Max_Wheel_Amps);
        //EEPROM Saved Values
        EEPROM.write(115, 1);
        EEPROM.write(116, Wheel_Amp_Sensor_ON);
        EEPROM.write(117, 1);
        EEPROM.write(118, Max_Wheel_Amps * 10);
        Serial.println(F("Saved to EEPROM"));
        Serial.println(F(" "));  
       }


  if (TFT_Menu_Command == 924) {
      Serial.println(F("RX Tip from TFT ..."));                               
      Receive_7_Data_Sets_Serial3();
      Angle_Sensor_Enabled    = Data1;
      Tip_Over_Sensor_Enabled = Data2;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0;   
      Serial.print(F("Tilt Angle Sensor = "));
      Serial.println(Angle_Sensor_Enabled);
      Serial.print(F("Tip Over Sensor = "));
      Serial.println(Tip_Over_Sensor_Enabled);
      Serial.println(F(" "));
      //EEPROM Saved Values
      EEPROM.write(29, 1);
      EEPROM.write(30, Angle_Sensor_Enabled);
      EEPROM.write(92, 1);
      EEPROM.write(93, Tip_Over_Sensor_Enabled);
      Serial.println(F("Saved to EEPROM"));
      Serial.println(F(" "));  
      }



// Receive the Pattern Values Back again
  if (TFT_Menu_Command == 925) {
      Serial.println(F("RX Pattern from TFT"));
      Receive_7_Data_Sets_Serial3();
      Pattern_Mow             = Data1;
      Turn_90_Delay_LH        = Data2 * 10;
      Turn_90_Delay_RH        = Data3 * 10;
      Move_to_next_line_delay = Data4 * 10;
      Line_Length_Cycles      = Data5;
      Data6 = 0;
      Data7 = 0; 
      Serial.print(F("Pattern Mow: "));
      if (Pattern_Mow == 0) Serial.println(F("OFF"));
      if (Pattern_Mow == 1) Serial.println(F("Parallel"));  
      if (Pattern_Mow == 3) Serial.println(F("Spiral"));      
      Serial.print(F("Turn 90° LH= "));
      Serial.println(Turn_90_Delay_LH);
      Serial.print(F("Turn 90° RH= "));
      Serial.println(Turn_90_Delay_RH);
      Serial.print(F("Distance to next row= "));
      Serial.println(Move_to_next_line_delay);          
      Serial.print(F("Line_Length_Cycles= "));
      Serial.println(Line_Length_Cycles); 
      //EEPROM Saved Values
      EEPROM.write(23, 1);
      EEPROM.write(24, Pattern_Mow);
      EEPROM.write(101, 1);
      EEPROM.write(102, Turn_90_Delay_LH / 10);
      EEPROM.write(103, 1);
      EEPROM.write(104, Turn_90_Delay_RH / 10);
      EEPROM.write(105, 1);
      EEPROM.write(106, Line_Length_Cycles / 10);
      Serial.println(F("Saved to EEPROM"));
      Serial.println(F(" "));  
  }



// Receive the Navigation data from TFT
  if (TFT_Menu_Command == 930) {
      Serial.println(F("RX PCB from TFT ..."));
      Receive_7_Data_Sets_Serial3();
      PCB   = Data1;
      Data2 = 0;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0; 
      Serial.print(F("PCB = "));
      if (PCB == 1) Serial.println(F("Enabled"));
      if (PCB == 0) Serial.println(F("Disabled"));
      // EEPROM
      EEPROM.write(119 , 1);
      EEPROM.write(120, PCB);      
      Serial.println(F("Saved to EEPROM"));
      Serial.println(F(" "));

}



// Receive the Navigation data from TFT
  if (TFT_Menu_Command == 299) {
      Serial.println(F("Receiving Navigation Values from TFT ..."));
      Receive_7_Data_Sets_Serial3();
      GPS_Enabled             = Data1;
      Data2 = 0;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0; 
      Serial.print(F("GPS Enabled = "));
      Serial.println(GPS_Enabled);
      if (GPS_Enabled == 1) Setup_ADCMan();
      Serial.println(" ");
      // EEPROM
      EEPROM.write(99 , 1);
      EEPROM.write(100, GPS_Enabled);     
      Serial.println(F("Saved to EEPROM"));
      Serial.println(F(" "));
      }
  

// Receive the Mower Start Conditions from the TFT Screen
  if (TFT_Menu_Command == 92) {
      Serial.println(F("RX Mower Start Values"));
      Receive_7_Data_Sets_Serial3();
      Mow_Time_Set = Data1;
      Data2 = 0;
      Data3 = 0;
      Data4 = 0;
      Data5 = 0;
      Data6 = 0;
      Data7 = 0; 
      Serial.println(F("Quick Start Selected"));
      Serial.print(F("Mow Time Selected = "));
      if ( (Mow_Time_Set == 1) || (Mow_Time_Set == 2 ) ){
          Serial.print(Mow_Time_Set);
          Serial.println(" hrs");
          }
      if (Mow_Time_Set == 3) Serial.println(F("Max Mow Time"));

      else { 
          (Mow_Time_Set = 2);
          Serial.print(Mow_Time_Set);
          Serial.println(" hrs");          
          }      
      Serial.println(F(" "));

    if (Mow_Time_Set == 3) Alarm_Timed_Mow_ON = 0;
    if (Mow_Time_Set < 3) {
        Time t = rtc.time();
        Alarm_Timed_Mow_ON = 1;                          // Activate the Mow Timer Alarm
        Alarm_Timed_Mow_Hour = t.hr +  Mow_Time_Set;     // Sets time to (+Mow_Time_Set 1 or 2 )hour later.
        Alarm_Timed_Mow_Minute = t.min;                  // Minutes are the same
        }
    
    TFT_Menu_Command = 1; 
    Manouver_Start_Mower();                              // Quick Start
                        
    }

// Start Relay Test
  if (TFT_Menu_Command == 42) {
    Serial.println(F("Running Relay Test"));
    Test_Relay();
    }

// Start Wheel Motor Test
  if (TFT_Menu_Command == 43) {
    Serial.println(F("Running Wheel Test"));
    Test_Wheel_Motors();

    }

// Start Wheel Amp Test
  if (TFT_Menu_Command == 38) {
    Serial.println(F("Running Wheel Amp Test"));
    Test_Wheel_Amps();
    }

// Start Motor Test
  if (TFT_Menu_Command == 44) {
    Serial.println(F("Running Blade Motor Test"));
    Test_Mower_Blade_Motor();
    }

  
// Receive the Mower Start Conditions from the TFT Screen
  if (TFT_Menu_Command == 13) {
      Manouver_Park_The_Mower();
      }



// Receive the Mower Start Conditions from the TFT Screen
  if (TFT_Menu_Command == 94) {
      Serial.println(F("TFT Says Go To Dock"));
      delay(1100);
      String Serial3_RX_Value  = "";                                              
    TFT_Menu_Command = 1; 
    if (Use_Charging_Station == 1) Manouver_Go_To_Charging_Station();  // Go to Dock
                        
    }

}



  

  
