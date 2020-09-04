
void Receive_Data_From_TFT()  {

  // Receive the Sonar Values Back again
  if (TFT_Menu_Command == 910) {
      Serial.println(F("Receiving Sonar Data from TFT ..."));
      delay(1100);
      String Serial3_RX_Value  = "";                                             
    
      while (Serial3.available() > 0) {
        
        char recieved = Serial3.read();
        if ( recieved != '\a' && recieved != '\b' && recieved != '\c' && recieved != '\d' 
        && recieved != '\e') {   
          Serial3_RX_Value = Serial3_RX_Value +  (char)recieved;          
          } 
          else if (recieved == '\a') {
          Sonar_1_Activate = Serial3_RX_Value.toInt();                                 
          Serial3_RX_Value = ""; // changed to string
          } 
          else if (recieved == '\b') {
          Sonar_2_Activate = Serial3_RX_Value.toInt();                                 
          Serial3_RX_Value = "";
          } 
          else if (recieved == '\c') {
          Sonar_3_Activate = Serial3_RX_Value.toInt();                             
          Serial3_RX_Value = "";
          } 
          else if (recieved == '\d') {
          maxdistancesonar = Serial3_RX_Value.toInt();                            
          Serial3_RX_Value = "";
          } 
          else if (recieved == '\e') {
          Max_Sonar_Hit = Serial3_RX_Value.toInt();                              
          Serial3_RX_Value = "";
          } 
      else Serial.print(F("No Data Received|"));
      }

      Serial.print("Sonar 2 Activated = ");
      Serial.println(Sonar_2_Activate);
      Serial.print("Sonar 1 Activated = ");
      Serial.println(Sonar_1_Activate);
      Serial.print("Sonar 3 Activated = ");
      Serial.println(Sonar_3_Activate);
      Serial.print("Sonar Max Distance = ");
      Serial.println(maxdistancesonar);
      Serial.print("Sonar Sensitivity = ");
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
      Serial.println("Saved to EEPROM");    
      Serial.println(" ");
      }

// Receive the Battery Values Back again
  if (TFT_Menu_Command == 911) {
      Serial.println(F("Receiving Battery Data from TFT ..."));
      delay(1100);
      String Serial3_RX_Value  = "";                                              

      while (Serial3.available() > 0) {
    
      char recieved = Serial3.read();
          if ( recieved != '\a' && recieved != '\b'  ) {   
          Serial3_RX_Value = Serial3_RX_Value +  (char)recieved;         
          } 
          else if (recieved == '\a') {
          Battery_Min = Serial3_RX_Value.toInt();                                 
          Serial3_RX_Value = ""; // changed to string
          } 
          else if (recieved == '\b') {
          Low_Battery_Instances_Chg = Serial3_RX_Value.toInt();                                
          Serial3_RX_Value = "";
          } 
        else Serial.print(F("No Data Received|"));
      }

      Serial.print("Battery Min = ");
      Battery_Min = Battery_Min / 10;
      Serial.println(Battery_Min);      
      Serial.print("Battery Sensitivity = ");
      Serial.println(Low_Battery_Instances_Chg);

      EEPROM.write(25, 1);
      EEPROM.write(26, (Battery_Min * 10));   
      EEPROM.write(85, 1);
      EEPROM.write(86, Low_Battery_Instances_Chg); 
      Serial.println("Saved to EEPROM");
      Serial.println(" ");
     }
  
// Receive the Sensor Menu 1 Values Back again
  if (TFT_Menu_Command == 96) {
      Serial.println(F("Receiving Sensor Menu 1 Values from TFT ..."));
      delay(1100);
      String Serial3_RX_Value  = "";                                              

      while (Serial3.available() > 0) {
    
      char recieved = Serial3.read();
      if ( recieved != '\a' && recieved != '\b' && recieved != '\c') {   
          Serial3_RX_Value = Serial3_RX_Value +  (char)recieved;          
          } 
          else if (recieved == '\a') {
          Perimeter_Wire_Enabled = Serial3_RX_Value.toInt();                                 
          Serial3_RX_Value = ""; // changed to string
          } 
          else if (recieved == '\b') {
          WIFI_Enabled = Serial3_RX_Value.toInt();                          
          Serial3_RX_Value = "";
          } 
          else if (recieved == '\c') {
          Bumper_Activate_Frnt = Serial3_RX_Value.toInt();                            
          Serial3_RX_Value = "";
          } 
        else Serial.print(F("No Data Received|"));
      }

      Serial.print("Wire Module Activated = ");
      Serial.println(Perimeter_Wire_Enabled);
      Serial.print("WIFI Enabled = ");
      Serial.println(WIFI_Enabled);
      Serial.print("Bumper Activated = ");
      Serial.println(Bumper_Activate_Frnt);
      
      EEPROM.write(67 , 1);
      EEPROM.write(68 , Perimeter_Wire_Enabled);
      EEPROM.write(81 , 1);
      EEPROM.write(82 , WIFI_Enabled);
      EEPROM.write(90 , 1);
      EEPROM.write(91 , Bumper_Activate_Frnt);
      Serial.println("Saved to EEPROM");
      Serial.println(" ");
  }



// Receive the Rain Sensor Values Back again
  if (TFT_Menu_Command == 912) {
      Serial.println(F("Receiving Rain Sensor Values from TFT ..."));
      delay(1100);
      String Serial3_RX_Value  = "";                                       

      while (Serial3.available() > 0) {
    
      char recieved = Serial3.read();
      if ( recieved != '\a' && recieved != '\b' ) {   
          Serial3_RX_Value = Serial3_RX_Value +  (char)recieved;       
          } 
          else if (recieved == '\a') {
          Rain_Sensor_Installed = Serial3_RX_Value.toInt();                                
          Serial3_RX_Value = ""; // changed to string
          } 
          else if (recieved == '\b') {
          Rain_Total_Hits_Go_Home = Serial3_RX_Value.toInt();                            
          Serial3_RX_Value = "";
          } 
      else Serial.print(F("No Data Received|"));
      }

      Serial.print("Rain Sensor ON/OFF = ");
      Serial.println(Rain_Sensor_Installed);
      Serial.print("Rain Sensor Sensitivity = ");
      Serial.println(Rain_Total_Hits_Go_Home);
      
      EEPROM.write(77 , 1);
      EEPROM.write(78 , Rain_Sensor_Installed);
      EEPROM.write(79, 1);
      EEPROM.write(80, Rain_Total_Hits_Go_Home);   
      Serial.println("Saved to EEPROM");
      Serial.println(" ");
    }


// Receive the Mower Motor Values Back again
  if (TFT_Menu_Command == 914) {
      Serial.println(F("Receiving Mower Motor Values from TFT ..."));
      delay(1100);
      String Serial3_RX_Value  = "";                                              

      while (Serial3.available() > 0) {
    
      char recieved = Serial3.read();
      if ( recieved != '\a' && recieved != '\b'  && recieved != '\c' && recieved != '\d' 
      &&  recieved != '\e' ) {
           
          Serial3_RX_Value = Serial3_RX_Value +  (char)recieved;         
          } 
          else if (recieved == '\a') {
          PWM_MaxSpeed_LH = Serial3_RX_Value.toInt();                                 
          Serial3_RX_Value = ""; // changed to string
          } 
          else if (recieved == '\b') {
          PWM_MaxSpeed_RH = Serial3_RX_Value.toInt();                                
          Serial3_RX_Value = "";
          } 
          else if (recieved == '\c') {
          PWM_Slow_Speed_LH = Serial3_RX_Value.toInt();                                 
          Serial3_RX_Value = ""; // changed to string
          } 
          else if (recieved == '\d') {
          PWM_Slow_Speed_RH = Serial3_RX_Value.toInt();                                
          Serial3_RX_Value = "";
          } 
          else if (recieved == '\e') {
          Slow_Speed_MAG = Serial3_RX_Value.toInt();                              
          Serial3_RX_Value = "";
          } 
      
      else Serial.print(F("No Data Received|"));
      }

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

      Serial.println("Saved to EEPROM");
      Serial.println(" ");
  }

  
// Receive the Mower Motor Values Back again
  if (TFT_Menu_Command == 915) {
      Serial.println(F("Receiving Blade Motor Values from TFT ..."));
      delay(1100);
      String Serial3_RX_Value  = "";                                              

      while (Serial3.available() > 0) {
    
      char recieved = Serial3.read();
      if ( recieved != '\a' && recieved != '\b' ) {   
          Serial3_RX_Value = Serial3_RX_Value +  (char)recieved;          
          } 
          else if (recieved == '\a') {
          PWM_Blade_Speed = Serial3_RX_Value.toInt();                                 
          Serial3_RX_Value = ""; // changed to string
          } 
          else if (recieved == '\b') {
          Cutting_Blades_Activate = Serial3_RX_Value.toInt();                                 
          Serial3_RX_Value = "";
          } 
      else Serial.print(F("No Data Received|"));
      }

      Serial.print("Blade Motor PWM = ");
      Serial.println(PWM_Blade_Speed);
      Serial.print("Cutting Blade Activated = ");
      Serial.println(Cutting_Blades_Activate);
      EEPROM.write(17, 1);
      EEPROM.write(18, PWM_Blade_Speed);   
      EEPROM.write(83 , 1);
      EEPROM.write(84 , Cutting_Blades_Activate);
      Serial.println("Saved to EEPROM");
      Serial.println(" ");
  }



// Receive the Mower Motor Values Back again
  if (TFT_Menu_Command == 916) {
      Serial.println(F("Receiving Movement Values from TFT ..."));
      delay(1100);
      String Serial3_RX_Value  = "";                                              

      while (Serial3.available() > 0) {
    
      char recieved = Serial3.read();
      if ( recieved != '\a' && recieved != '\b' && recieved != '\c' && recieved != '\d' ) {   
          Serial3_RX_Value = Serial3_RX_Value +  (char)recieved;          
          } 
          else if (recieved == '\a') {
          Max_Cycles_Straight = Serial3_RX_Value.toInt();                                 
          Serial3_RX_Value = ""; // changed to string
          } 
          else if (recieved == '\b') {
          Mower_Turn_Delay_Min = Serial3_RX_Value.toInt();                                
          Serial3_RX_Value = "";
          } 
          else if (recieved == '\c') {
          Mower_Turn_Delay_Max = Serial3_RX_Value.toInt();                             
          Serial3_RX_Value = "";
          } 
          else if (recieved == '\d') {
          Mower_Reverse_Delay = Serial3_RX_Value.toInt();                                 
          Serial3_RX_Value = "";
          } 
      else Serial.print(F("No Data Received|"));
      }

      Serial.print("Max Mow Length = ");
      Max_Cycles_Straight = Max_Cycles_Straight * 10;
      Serial.println(Max_Cycles_Straight);
      
      Serial.print("Turn Angle Min = ");
      Mower_Turn_Delay_Min = Mower_Turn_Delay_Min * 100;
      Serial.println(Mower_Turn_Delay_Min);
      
      Serial.print("Turn Angle Max = ");
      Mower_Turn_Delay_Max = Mower_Turn_Delay_Max * 100;
      Serial.println(Mower_Turn_Delay_Max);
      
      Serial.print("Reverse Distance = ");
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
      Serial.println("Saved to EEPROM");
      Serial.println(" ");
  }



// Receive the Mower Motor Values Back again
  if (TFT_Menu_Command == 917) {
      Serial.println(F("Receiving Track Exit Values from TFT ..."));
      delay(1100);
      String Serial3_RX_Value  = "";                                             

      while (Serial3.available() > 0) {
    
      char recieved = Serial3.read();
      if ( recieved != '\a' && recieved != '\b' && recieved != '\c') {   
          Serial3_RX_Value = Serial3_RX_Value +  (char)recieved;          
          } 
          else if (recieved == '\a') {
          Track_Wire_Zone_1_Cycles = Serial3_RX_Value.toInt();                                 
          Serial3_RX_Value = ""; // changed to string
          } 
          else if (recieved == '\b') {
          Track_Wire_Zone_2_Cycles = Serial3_RX_Value.toInt();                                
          Serial3_RX_Value = "";
          } 
          else if (recieved == '\c') {
          CCW_Tracking_To_Start = Serial3_RX_Value.toInt();                                
          Serial3_RX_Value = "";
          } 
      else Serial.print(F("No Data Received|"));
      }
      
      Serial.print("Track Wire Zone 1 = ");
      Track_Wire_Zone_1_Cycles = Track_Wire_Zone_1_Cycles * 100;
      Serial.println(Track_Wire_Zone_1_Cycles);
      
      Serial.print("Track Wire Zone 2 = ");
      Track_Wire_Zone_2_Cycles = Track_Wire_Zone_2_Cycles * 100;
      Serial.println(Track_Wire_Zone_2_Cycles);
      
      if (CCW_Tracking_To_Start == 0) {
        CW_Tracking_To_Start = 1;
        CCW_Tracking_To_Charge = 1;
        CW_Tracking_To_Charge = 0;

        Serial.println("Tracking to Charge = CCW");
        Serial.println("Tracking to Start = CW");
        }
        
      if (CCW_Tracking_To_Start == 1) {
        CW_Tracking_To_Start = 0;
        CCW_Tracking_To_Charge = 0;
        CW_Tracking_To_Charge = 1;
        
        Serial.println("Tracking to Charge = CW");
        Serial.println("Tracking to Start = CCW");
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
      Serial.println("Saved to EEPROM");
      Serial.println(" ");
  }


// Receive the Mower Motor Values Back again
  if (TFT_Menu_Command == 918) {
      Serial.println(F("Receiving Find Wire Values from TFT ..."));
      delay(1100);
      String Serial3_RX_Value  = "";                                              

      while (Serial3.available() > 0) {
    
      char recieved = Serial3.read();
      if ( recieved != '\a' && recieved != '\b' && recieved != '\c') {   
          Serial3_RX_Value = Serial3_RX_Value +  (char)recieved;          
          } 
          else if (recieved == '\a') {
          Max_Cycle_Wire_Find = Serial3_RX_Value.toInt();                                 
          Serial3_RX_Value = ""; // changed to string
          } 
          else if (recieved == '\b') {
          Max_Cycle_Wire_Find_Back = Serial3_RX_Value.toInt();                                
          Serial3_RX_Value = "";
          } 
          else if (recieved == '\c') {
          Home_Wire_Compass_Heading = Serial3_RX_Value.toInt();                                
          Serial3_RX_Value = "";
          } 
      else Serial.print(F("No Data Received|"));
      }
      
      Serial.print("Wire Find Forwards / Cycles = ");
      Max_Cycle_Wire_Find = Max_Cycle_Wire_Find * 100;
      Serial.println(Max_Cycle_Wire_Find);

      Serial.print("Wire Find Forwards / Cycles = ");
      Max_Cycle_Wire_Find_Back = Max_Cycle_Wire_Find_Back * 10;
      Serial.println(Max_Cycle_Wire_Find_Back);
          
      Serial.print("Home Compass Heading / degrees ");
      Serial.println(Home_Wire_Compass_Heading);   


      // EEPROM
      EEPROM.write(69, 1);
      EEPROM.write(70, (Max_Cycle_Wire_Find/10));
      EEPROM.write(71, 1);
      EEPROM.write(72, (Max_Cycle_Wire_Find_Back/10));
      EEPROM.write(27, 1);
      EEPROM.write(28, (Home_Wire_Compass_Heading/10));   
      Serial.println("Saved to EEPROM");
      Serial.println(" ");
  }




// Receive the Mower Motor Values Back again
  if (TFT_Menu_Command == 98) {
      Serial.println(F("Receiving Find Wire Values from TFT ..."));
      delay(1100);
      String Serial3_RX_Value  = "";                                              

      while (Serial3.available() > 0) {
    
      char recieved = Serial3.read();
      if ( recieved != '\a' && recieved != '\b' && recieved != '\c') {   
          Serial3_RX_Value = Serial3_RX_Value +  (char)recieved;          
          } 
          else if (recieved == '\a') {
          Use_Charging_Station = Serial3_RX_Value.toInt();                                 
          Serial3_RX_Value = ""; // changed to string
          } 
      else Serial.print(F("No Data Received|"));
      }
          
      Serial.print("Use Charging Station = ");
      Serial.println(Use_Charging_Station);   

      // EEPROM
      EEPROM.write(47 , 1);
      EEPROM.write(48 , Use_Charging_Station);
      Serial.println("Saved to EEPROM");
      Serial.println(" ");
  }



// Receive the Mower Start Conditions from the TFT Screen
  if (TFT_Menu_Command == 93) {
      Serial.println(F("Receiving Mower Exit Dock Start Data from TFT ..."));
      delay(1100);
      String Serial3_RX_Value  = "";                                              

      while (Serial3.available() > 0) {
    
      char recieved = Serial3.read();
      if ( recieved != '\a' && recieved != '\b' ) {   
          Serial3_RX_Value = Serial3_RX_Value +  (char)recieved;          
          } 
          else if (recieved == '\a') {
          Exit_Zone = Serial3_RX_Value.toInt();                                 
          Serial3_RX_Value = ""; // changed to string
          } 
          else if (recieved == '\b') {
          Mow_Time_Set = Serial3_RX_Value.toInt();                                
          Serial3_RX_Value = "";
          } 
      else Serial.print(F("No Data Received|"));
      }

      Serial.print(F("Exit Zone Selected = "));
      Serial.println(Exit_Zone);
      Serial.print(F("Mow Time Selected = "));
      if ( (Mow_Time_Set == 1) || (Mow_Time_Set == 2 ) ){
          Serial.print(Mow_Time_Set);
          Serial.println(" hrs");
          }
      if (Mow_Time_Set == 3) Serial.println(F("Max Mow Time"));
      Serial.println(" ");

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




// Receive the Mower Motor Values Back again
  if (TFT_Menu_Command == 919) {
      Serial.println(F("Receiving Track PID Values from TFT ..."));
      delay(1100);
      String Serial3_RX_Value  = "";                                             

      while (Serial3.available() > 0) {
    
      char recieved = Serial3.read();
      if ( recieved != '\a' && recieved != '\b' && recieved != '\c') {   
          Serial3_RX_Value = Serial3_RX_Value +  (char)recieved;          
          } 
          else if (recieved == '\a') {
          Max_Tracking_Turn_Left = Serial3_RX_Value.toInt();                                 
          Serial3_RX_Value = ""; // changed to string
          } 
          else if (recieved == '\b') {
          Max_Tracking_Turn_Right = Serial3_RX_Value.toInt();                                 
          Serial3_RX_Value = "";
          } 
          else if (recieved == '\c') {
          P = Serial3_RX_Value.toInt();                                
          Serial3_RX_Value = "";
          } 
      else Serial.print(F("No Data Received|"));
      }
      
      Serial.print(F("Max Cycles Left Wheel = "));
      Max_Tracking_Turn_Left = Max_Tracking_Turn_Left * 10;
      Serial.println(Max_Tracking_Turn_Left);
      
      Serial.print(F("Max Cycles Right Wheel = "));
      Max_Tracking_Turn_Right = Max_Tracking_Turn_Right * 10;
      Serial.println(Max_Tracking_Turn_Right);          
      
      Serial.print(F("PID P = "));
      P = P / 100;
      Serial.println(P);
      Serial.println(" ");


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


// Receive the Navigation data from TFT
  if (TFT_Menu_Command == 99) {
      Serial.println(F("Receiving Navigation Values from TFT ..."));
      delay(1100);
      String Serial3_RX_Value  = "";                                             

  while (Serial3.available() > 0) {
    
    char recieved = Serial3.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c' && recieved != '\d') {   
        Serial3_RX_Value = Serial3_RX_Value +  (char)recieved;          
        } 
        else if (recieved == '\a') {
          Compass_Activate = Serial3_RX_Value.toInt();                                 
          Serial3_RX_Value = ""; // changed to string
          } 
       else if (recieved == '\b') {
          Compass_Heading_Hold_Enabled = Serial3_RX_Value.toInt();                               
          Serial3_RX_Value = "";
          } 
       else if (recieved == '\c') {
          CPower = Serial3_RX_Value.toInt();                               
          Serial3_RX_Value = "";
          }
       else if (recieved == '\d') {
          GPS_Enabled = Serial3_RX_Value.toInt();                               
          Serial3_RX_Value = "";
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

      Serial.print(F("GPS Enabled = "));
      Serial.println(GPS_Enabled);

      if (GPS_Enabled == 1) Setup_ADCMan();

      Serial.println(" ");
      // EEPROM
      EEPROM.write(19 , 1);
      EEPROM.write(20 , Compass_Activate);
      EEPROM.write(59 , 1);
      EEPROM.write(60 , Compass_Heading_Hold_Enabled);
      EEPROM.write(61, 1);
      EEPROM.write(62, (CPower*100)); 
      EEPROM.write(99 , 1);
      EEPROM.write(100, GPS_Enabled);
      
      Serial.println(F("Saved to EEPROM"));
      Serial.println(F(" "));

}



// Receive the Navigation data from TFT
  if (TFT_Menu_Command == 920) {
      Serial.println(F("Receiving Alarm 1 Values from TFT ..."));
      delay(1100);
      String Serial3_RX_Value  = "";                                             

   while (Serial3.available() > 0) {
    
    char recieved = Serial3.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c' && recieved != '\d' && recieved != '\e' ) {   
      Serial3_RX_Value = Serial3_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Alarm_1_ON = Serial3_RX_Value.toInt();                                 
      Serial3_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      Alarm_1_Hour = Serial3_RX_Value.toInt();                         
      Serial3_RX_Value = "";
      } 
      else if (recieved == '\c') {
      Alarm_1_Minute = Serial3_RX_Value.toInt();                           
      Serial3_RX_Value = "";
      } 
      else if (recieved == '\d') {
      Alarm_1_Repeat = Serial3_RX_Value.toInt();                       
      Serial3_RX_Value = "";
      } 
      else if (recieved == '\e') {
      Alarm_1_Action = Serial3_RX_Value.toInt();                          
      Serial3_RX_Value = "";
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
      //EEPROM
      EEPROM.write(1, 1);
      EEPROM.write(2, Alarm_1_Hour);
      EEPROM.write(3, Alarm_1_Minute);
      EEPROM.write(4, Alarm_1_ON);
      EEPROM.write(87, Alarm_1_Action);
      Serial.println(F("Saved to EEPROM"));
      Serial.println(F(" "));    
  }




// Receive the Navigation data from TFT
  if (TFT_Menu_Command == 921) {
      Serial.println(F("Receiving Alarm 2 Values from TFT ..."));
      delay(1100);
      String Serial3_RX_Value  = "";                                             

   while (Serial3.available() > 0) {
    
    char recieved = Serial3.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c' && recieved != '\d' && recieved != '\e' ) {   
      Serial3_RX_Value = Serial3_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Alarm_2_ON = Serial3_RX_Value.toInt();                                 
      Serial3_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      Alarm_2_Hour = Serial3_RX_Value.toInt();                         
      Serial3_RX_Value = "";
      } 
      else if (recieved == '\c') {
      Alarm_2_Minute = Serial3_RX_Value.toInt();                           
      Serial3_RX_Value = "";
      } 
      else if (recieved == '\d') {
      Alarm_2_Repeat = Serial3_RX_Value.toInt();                       
      Serial3_RX_Value = "";
      } 
      else if (recieved == '\e') {
      Alarm_2_Action = Serial3_RX_Value.toInt();                          
      Serial3_RX_Value = "";
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
      //EEPROM
      EEPROM.write(5, 1);
      EEPROM.write(6, Alarm_2_Hour);
      EEPROM.write(7, Alarm_2_Minute);
      EEPROM.write(8, Alarm_2_ON);
      EEPROM.write(88, Alarm_2_Action);
      Serial.println(F("Saved to EEPROM"));
      Serial.println(F(" "));    
  }


// Receive the Navigation data from TFT
  if (TFT_Menu_Command == 922) {
      Serial.println(F("Receiving Alarm 3 Values from TFT ..."));
      delay(1100);
      String Serial3_RX_Value  = "";                                             

   while (Serial3.available() > 0) {
    
    char recieved = Serial3.read();
    if ( recieved != '\a' && recieved != '\b' && recieved != '\c' && recieved != '\d' && recieved != '\e' ) {   
      Serial3_RX_Value = Serial3_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Alarm_3_ON = Serial3_RX_Value.toInt();                                 
      Serial3_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      Alarm_3_Hour = Serial3_RX_Value.toInt();                         
      Serial3_RX_Value = "";
      } 
      else if (recieved == '\c') {
      Alarm_3_Minute = Serial3_RX_Value.toInt();                           
      Serial3_RX_Value = "";
      } 
      else if (recieved == '\d') {
      Alarm_3_Repeat = Serial3_RX_Value.toInt();                       
      Serial3_RX_Value = "";
      } 
      else if (recieved == '\e') {
      Alarm_3_Action = Serial3_RX_Value.toInt();                          
      Serial3_RX_Value = "";
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
      //EEPROM
      EEPROM.write(9, 1);
      EEPROM.write(10, Alarm_3_Hour);
      EEPROM.write(11, Alarm_3_Minute);
      EEPROM.write(12, Alarm_3_ON);
      EEPROM.write(89, Alarm_3_Action);
      Serial.println(F("Saved to EEPROM"));
      Serial.println(F(" "));    
  }



// Receive the Navigation data from TFT
  if (TFT_Menu_Command == 923) {
      Serial.println(F("Receiving Time Values from TFT ..."));
      delay(1100);
      String Serial3_RX_Value  = "";          
      int set_hour;
      int set_min;                                   

   while (Serial3.available() > 0) {
    
    char recieved = Serial3.read();
    if ( recieved != '\a' && recieved != '\b') {   
      Serial3_RX_Value = Serial3_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      set_hour = Serial3_RX_Value.toInt();                                 
      Serial3_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      set_min = Serial3_RX_Value.toInt();                         
      Serial3_RX_Value = "";
      } 
    else Serial.print(F("No Data Received|"));
  }
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
               Serial.println(F("TIME SAVED"));
               delay(2000);
  
  }


  if (TFT_Menu_Command == 924) {
    Serial.println(F("Receiving Tip Setup Values from TFT ..."));                               
    delay(1100);
    String Serial3_RX_Value  = "";      

   while (Serial3.available() > 0) {
    
    char recieved = Serial3.read();
    if ( recieved != '\a' && recieved != '\b') {   
      Serial3_RX_Value = Serial3_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      Angle_Sensor_Enabled = Serial3_RX_Value.toInt();                                 
      Serial3_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\b') {
      Tip_Over_Sensor_Enabled = Serial3_RX_Value.toInt();                         
      Serial3_RX_Value = "";
      } 

    else Serial.print(F("No Data Received|"));
   }
      
      
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
      }



// Receive the Pattern Values Back again
  if (TFT_Menu_Command == 925) {
      delay(1500);
      Serial.println(F("Receiving Pattern Mow Values from TFT ..."));
      String Serial3_RX_Value  = "";                                              

      while (Serial3.available() > 0) {
    
      char recieved = Serial3.read();
      if ( recieved != '\a' && recieved != '\b' && recieved != '\c' && recieved != '\d'
          && recieved != '\e' && recieved != '\f' && recieved != '\g') {   
          Serial3_RX_Value = Serial3_RX_Value +  (char)recieved;          
          } 
          else if (recieved == '\a') {
          Turn_90_Delay_LH = Serial3_RX_Value.toInt();                                 
          Serial3_RX_Value = ""; // changed to string
          } 
          else if (recieved == '\b') {
          Turn_90_Delay_RH = Serial3_RX_Value.toInt();                                
          Serial3_RX_Value = "";
          } 
          else if (recieved == '\c') {
          Move_to_next_line_delay = Serial3_RX_Value.toInt();                                
          Serial3_RX_Value = "";
          } 
          else if (recieved == '\d') {
          Line_Length_Cycles = Serial3_RX_Value.toInt();                                
          Serial3_RX_Value = "";
          } 
          else if (recieved == '\e') {
          Max_Cycles_Spirals = Serial3_RX_Value.toInt();                                
          Serial3_RX_Value = "";
          } 
          else if (recieved == '\f') {
          Pattern_Mow = Serial3_RX_Value.toInt();                                
          Serial3_RX_Value = "";
          } 
          else if (recieved == '\g') {
          Compass_Mow_Direction = Serial3_RX_Value.toInt();                                
          Serial3_RX_Value = "";
          } 
      else Serial.print(F("No Data Received|"));
      }
      

      Serial.print(F("Pattern Mow ON/OFF = "));
      Serial.println(Pattern_Mow);
      
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
      
      Serial.print(F("Max Cycles Spirals= "));
      Max_Cycles_Spirals = Max_Cycles_Spirals * 10;
      Serial.println(Max_Cycles_Spirals); 

      Serial.print(F("***Compass Mow Direction= ***"));
      Serial.println(Compass_Mow_Direction); 
     
      Serial.print(F("Compass Mow Direction= "));

      Compass_Mow_Direction = Compass_Mow_Direction * 10;
      Serial.println(Compass_Mow_Direction); 
      Serial.println(F(" "));


      // EEPROM

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
  if (TFT_Menu_Command == 92) {
      Serial.println(F("Receiving Mower Start Conditions from TFT ..."));
      delay(1100);
      String Serial3_RX_Value  = "";                                              

      while (Serial3.available() > 0) {
    
      char recieved = Serial3.read();
      if ( recieved != '\a') {   
          Serial3_RX_Value = Serial3_RX_Value +  (char)recieved;          
          } 
          else if (recieved == '\a') {
          Mow_Time_Set = Serial3_RX_Value.toInt();                                
          Serial3_RX_Value = "";
          } 
      else Serial.print(F("No Data Received|"));
      }

      Serial.println(F("Quick Start Selected"));
      Serial.print(F("Mow Time Selected = "));
      if ( (Mow_Time_Set == 1) || (Mow_Time_Set == 2 ) ){
          Serial.print(Mow_Time_Set);
          Serial.println(" hrs");
          }
      if (Mow_Time_Set == 3) Serial.println(F("Max Mow Time"));
      Serial.println(" ");

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


// Receive the Mower Start Conditions from the TFT Screen
  if (TFT_Menu_Command == 94) {
      Serial.println(F("TFT Says Go To Dock"));
      delay(1100);
      String Serial3_RX_Value  = "";                                              
    TFT_Menu_Command = 1; 
    if (Use_Charging_Station == 1) Manouver_Go_To_Charging_Station();  // Go to Dock
                        
    }

}



  

  
