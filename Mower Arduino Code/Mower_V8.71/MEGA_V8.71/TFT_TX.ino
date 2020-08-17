//Transmits Data to the TFT e.g. sensor data from EEPROM

void Send_Data_To_TFT() {
    // Depending on the code received the following data set is sent through the Serial 3 port.
    
    // Menu Sonar
    if (TFT_Menu_Command == 10) {
      Serial.println("TX Sonar to TFT");
      
      Serial3.print(Sonar_1_Activate);
      Serial3.println("\a");
      delay(200);  

      Serial3.print(Sonar_2_Activate);
      Serial3.println("\b");
      delay(200);  

      Serial3.print(Sonar_3_Activate);
      Serial3.println("\c");
      delay(200);  

      Serial3.print(maxdistancesonar);
      Serial3.println("\d");
      delay(200);

      Serial3.print(Max_Sonar_Hit);
      Serial3.println("\e");
      delay(200);

      Serial.print(F("Sonar 2 Activated = "));
      Serial.println(Sonar_2_Activate);
      Serial.print(F("Sonar 1 Activated = "));
      Serial.println(Sonar_1_Activate);
      Serial.print(F("Sonar 3 Activated = "));
      Serial.println(Sonar_3_Activate);
      Serial.print(F("Sonar Max Distance = "));
      Serial.println(maxdistancesonar);
      Serial.print(F("Sonar Sensitivity= "));
      Serial.println(Max_Sonar_Hit);
      Serial.println(F(" "));
      }


    if (TFT_Menu_Command == 11) {
      Serial.println("False Command");
      
    }

// Navigation Menu
    if (TFT_Menu_Command == 9) {
      Serial.println("TX Nav to TFT");
      
      Serial3.print(GPS_Enabled);
      Serial3.println("\a");
      delay(200);  

      Serial.print(F("GPS Enabled= "));
      Serial.println(GPS_Enabled);   
      }


// Menu Battery
    if (TFT_Menu_Command == 26) {
      Serial.println("TX Battery to TFT");
      
      Serial3.print(Battery_Min * 10);
      Serial3.println("\a");
      delay(300);  

      Serial3.print(Low_Battery_Instances_Chg);
      Serial3.println("\b");
      delay(200);  

      Serial.print(F("Battery Min = "));
      Serial.println(Battery_Min);
      Serial.print(F("Battery Sensitivity = "));
      Serial.println(Low_Battery_Instances_Chg);
      Serial.println(" ");
      
}

// Setup Other
    if (TFT_Menu_Command == 30) {
      Serial.println("TX Setup Other");
      
      Serial3.print(PCB);
      Serial3.println("\a");
      delay(300);  

      Serial.print(F("PCB = "));
      if (PCB == 1) Serial.println(F("Enabled"));
      if (PCB == 0) Serial.println(F("Disabled"));
      Serial.println(" ");
      
}


    // Menu Sonar
    if (TFT_Menu_Command == 6) {
      Serial.println("TX Sensors to TFT");
      
      Serial3.print(Perimeter_Wire_Enabled);
      Serial3.println("\a");
      delay(200);  

      Serial3.print(WIFI_Enabled);
      Serial3.println("\b");
      delay(200);  

      Serial3.print(Bumper_Activate_Frnt);
      Serial3.println("\c");
      delay(200);  


      Serial.print(F("Wire Module Activated = "));
      Serial.println(Perimeter_Wire_Enabled);
      Serial.print(F("WIFI Enabled = "));
      Serial.println(WIFI_Enabled);
      Serial.print(F("Bumper Activated = "));
      Serial.println(Bumper_Activate_Frnt);
      Serial.println(F(" "));
      }


// Menu Battery
    if (TFT_Menu_Command == 12) {
      Serial.println("TX Rain to TFT");
      
      Serial3.print(Rain_Sensor_Installed);
      Serial3.println("\a");
      delay(300);  

      Serial3.print(Rain_Total_Hits_Go_Home);
      Serial3.println("\b");
      delay(200);  

      Serial.print(F("Rain Sensor ON/OFF = "));
      Serial.println(Rain_Sensor_Installed);
      Serial.print(F("Rain Sensor Sensitivity = "));
      Serial.println(Rain_Total_Hits_Go_Home);
      Serial.println(F(" "));
      }


// Wheel Motor Data
    if (TFT_Menu_Command == 14) {
      Serial.println("TX Wheel Motor to TFT");
      
      Serial3.print(PWM_MaxSpeed_LH);
      Serial3.println("\a");
      delay(300);  

      Serial3.print(PWM_MaxSpeed_RH);
      Serial3.println("\b");
      delay(200);  

      Serial3.print(PWM_Slow_Speed_LH);
      Serial3.println("\c");
      delay(300);  

      Serial3.print(PWM_Slow_Speed_RH);
      Serial3.println("\d");
      delay(200);  

      Slow_Speed_MAG = Slow_Speed_MAG / 10;
      Serial.println("TX:");
      Serial.println(Slow_Speed_MAG);
      Serial3.print(Slow_Speed_MAG);
      Serial3.println("\e");
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
      Serial.println(Slow_Speed_MAG * 10);
      Serial.println(F(" "));
      }


// Blade Motor Data
    if (TFT_Menu_Command == 15) {
      Serial.println("TX Blade Motor to TFT");
      
      Serial3.print(PWM_Blade_Speed);
      Serial3.println("\a");
      delay(300);  

      Serial3.print(Cutting_Blades_Activate);
      Serial3.println("\b");
      delay(200);  
      
      Serial.print(F("Blade Motor PWM = "));
      Serial.println(PWM_Blade_Speed);
      Serial.print(F("Cutting Blade Activated = "));
      Serial.println(Cutting_Blades_Activate);
      Serial.println(F(" "));

}


// Blade Motor Data
    if (TFT_Menu_Command == 16) {
      Serial.println("TX Movement to TFT");
      
      Serial3.print(Max_Cycles_Straight / 10);
      Serial3.println("\a");
      delay(300);  

      Serial3.print(Mower_Turn_Delay_Min / 100);
      Serial3.println("\b");
      delay(200);  

      Serial3.print(Mower_Turn_Delay_Max / 100);
      Serial3.println("\c");
      delay(200);  

      Serial3.print(Mower_Reverse_Delay / 100);
      Serial3.println("\d");
      delay(200);  
      
      Serial.print(F("Max Mow Length = "));
      Serial.println(Max_Cycles_Straight);
      Serial.print(F("Turn Angle Min = "));
      Serial.println(Mower_Turn_Delay_Min);
      Serial.print(F("Turn Angle Max = "));
      Serial.println(Mower_Turn_Delay_Max);
      Serial.print(F("Reverse Distance = "));
      Serial.println(Mower_Reverse_Delay);
      Serial.println(F(" "));

}


// Tracking to Exit Data
    if (TFT_Menu_Command == 17) {
      Serial.println("TX Exit to TFT");
      
      Serial3.print(Track_Wire_Zone_1_Cycles / 100);
      Serial3.println("\a");
      delay(300);  

      Serial3.print(Track_Wire_Zone_2_Cycles / 100);
      Serial3.println("\b");
      delay(200);  

      Serial3.print(CCW_Tracking_To_Start);
      Serial3.println("\c");
      delay(200);  

      Serial.print("Track Wire Zone 1 = ");
      Serial.println(Track_Wire_Zone_1_Cycles);
      
      Serial.print("Track Wire Zone 2 = ");
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


// Tracking Menu Data
    if (TFT_Menu_Command == 8) {
      Serial.println("TX Tracking to TFT");
    
      Serial3.print(Use_Charging_Station);
      Serial3.println("\a");
      delay(300); 

      Serial.print(F("Use Charging Station = "));
      Serial.println(Use_Charging_Station); 
      } 


// Tracking to Exit Data
    if (TFT_Menu_Command == 18) {
      Serial.println("TX Find Wire to TFT");
      
      Serial3.print(Max_Cycle_Wire_Find / 100);
      Serial3.println("\a");
      delay(300);  

      Serial3.print(Max_Cycle_Wire_Find_Back / 10);
      Serial3.println("\b");
      delay(200);  

      Serial3.print(Home_Wire_Compass_Heading);
      Serial3.println("\c");
      delay(200);  
   

      Serial.print(F("Wire Find Forwards / cylces = "));
      Serial.println(Max_Cycle_Wire_Find);
      
      Serial.print(F("Wire Find Backwards / cylces = "));
      Serial.println(Max_Cycle_Wire_Find_Back);
      
      Serial.print(F("Home Compass Heading / degrees "));
      Serial.println(Home_Wire_Compass_Heading);      
      }

// Tracking PID
    if (TFT_Menu_Command == 19) {
      Serial.println("TX Find Wire to TFT");
      
      Serial3.print(Max_Tracking_Turn_Left / 10);
      Serial3.println("\a");
      delay(300);  

      Serial3.print(Max_Tracking_Turn_Right / 10);
      Serial3.println("\b");
      delay(200);  

      Serial3.print(P * 100);
      Serial3.println("\c");
      delay(200);  

      Serial.print(F("Max Cycles Left Wheel = "));
      Serial.println(Max_Tracking_Turn_Left);
      Serial.print(F("Max Cycles Right Wheel = "));
      Serial.println(Max_Tracking_Turn_Right);         
      Serial.print(F("PID P = "));
      Serial.println(P);
      Serial.println(F(" "));     
      }


// Compass
    if (TFT_Menu_Command == 27) {
      Serial.println("TX Compass to TFT");
      
      Serial3.print(Compass_Activate);
      Serial3.println("\a");
      delay(300);  

      Serial3.print(Compass_Heading_Hold_Enabled);
      Serial3.println("\b");
      delay(300);  

      Serial3.print(CPower * 10);
      Serial3.println("\c");
      delay(300);  
      
      Serial3.print(Compass_Setup_Mode);
      Serial3.println("\d");
      delay(200);  

      Serial.print(F("Compass Activated = "));
      Serial.println(Compass_Activate);
      Serial.print(F("Heading Hold Enabled = "));
      Serial.println(Compass_Heading_Hold_Enabled);          
      Serial.print(F("Compass Power = "));
      Serial.println(CPower);    
      Serial.print(F("Compass Setup Mode = "));
      Serial.println(Compass_Setup_Mode); 
      }


// GYRO
    if (TFT_Menu_Command == 28) {

      Serial3.print(GYRO_Enabled);
      Serial3.println("\a");
      delay(300);  

      Serial3.print(GPower * 10);
      Serial3.println("\b");
      delay(300);

      Serial.print(F("GYRO Enabled= "));
      Serial.println(GYRO_Enabled); 
      Serial.print(F("GYRO Power = "));
      Serial.println(GPower);     
    }


// Wheel Block
    if (TFT_Menu_Command == 29) {

      Serial3.print(Wheel_Amp_Sensor_ON);
      Serial3.println("\a");
      delay(300);  

      Serial3.print(Max_Wheel_Amps * 100);
      Serial3.println("\b");
      delay(300);

    Serial.print(F("Wheel Amp ON: "));
        if (Wheel_Amp_Sensor_ON == 1) Serial.println("ON");
        if (Wheel_Amp_Sensor_ON == 0) Serial.println("OFF");
    
    Serial.print(F("Wheel Amps Max: "));
    Serial.print(Max_Wheel_Amps);     
    }

// Alarm 1
    if (TFT_Menu_Command == 20) {
      Serial.println("TX Alarm1 TFT");
      
      Serial3.print(Alarm_1_ON);
      Serial3.println("\a");
      delay(300);  

      Serial3.print(Alarm_1_Hour);
      Serial3.println("\b");
      delay(200);  

      Serial3.print(Alarm_1_Minute);
      Serial3.println("\c");
      delay(200);  

      Serial3.print(Alarm_1_Repeat);
      Serial3.println("\d");
      delay(200);  

      Serial3.print(Alarm_1_Action);
      Serial3.println("\e");
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


// Alarm 2
    if (TFT_Menu_Command == 21) {
      Serial.println("TX Alarm2 TFT");
      
      Serial3.print(Alarm_2_ON);
      Serial3.println("\a");
      delay(300);  

      Serial3.print(Alarm_2_Hour);
      Serial3.println("\b");
      delay(200);  

      Serial3.print(Alarm_2_Minute);
      Serial3.println("\c");
      delay(200);  

      Serial3.print(Alarm_2_Repeat);
      Serial3.println("\d");
      delay(200);  

      Serial3.print(Alarm_2_Action);
      Serial3.println("\e");
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


// Alarm 3
    if (TFT_Menu_Command == 22) {
      Serial.println("TX Alarm3 TFT");
      
      Serial3.print(Alarm_3_ON);
      Serial3.println("\a");
      delay(300);  

      Serial3.print(Alarm_3_Hour);
      Serial3.println("\b");
      delay(200);  

      Serial3.print(Alarm_3_Minute);
      Serial3.println("\c");
      delay(200);  

      Serial3.print(Alarm_3_Repeat);
      Serial3.println("\d");
      delay(200);  

      Serial3.print(Alarm_3_Action);
      Serial3.println("\e");
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


// Set Time
    if (TFT_Menu_Command == 23) {
      Serial.println("Set Time TFT");
      if (PCB == 0) {
        Time t = rtc.time();
        Time_Hour = t.hr;
        Time_Minute = t.min;  
        }
      if (PCB == 1) {
        byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
        Read_DS3231_Time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,
                 &year);
        Time_Hour = hour;
        Time_Minute = minute;
        Time_Second = second;
        }
 
      Serial3.print(Time_Hour);
      Serial3.println("\a");
      delay(300);  

      Serial3.print(Time_Minute);
      Serial3.println("\b");
      delay(200);  

      Serial.print(F("Time Now = "));
      Serial.print(Time_Hour);
      Serial.print(F(":"));
      Serial.println(Time_Minute);
      }



// Tip Sensor Menu
    if (TFT_Menu_Command == 24) {
      Serial.println("TX Tip Sensor to TFT");
      
      Serial3.print(Angle_Sensor_Enabled);
      Serial3.println("\a");
      delay(300);  

      Serial3.print(Tip_Over_Sensor_Enabled);
      Serial3.println("\b");
      delay(200);  
      
      Serial.print(F("Tilt Angle Sensor = "));
      Serial.println(Angle_Sensor_Enabled);
      Serial.print(F("Tip Over Sensor = "));
      Serial.println(Tip_Over_Sensor_Enabled);
      Serial.println(F(" "));

}


// Pattern Mow Menu
    if (TFT_Menu_Command == 25) {
      Serial.println(F("TX Pattern to TFT"));
      
      Serial3.print(Pattern_Mow );
      Serial3.println("\a");
      delay(300); 
      
      Serial3.print(Turn_90_Delay_LH / 10);
      Serial3.println("\b");
      delay(300);  

      Serial3.print(Turn_90_Delay_RH / 10);
      Serial3.println("\c");
      delay(300);  

      Serial3.print(Move_to_next_line_delay / 10);
      Serial3.println("\d");
      delay(300);  

      Serial3.print(Line_Length_Cycles);
      Serial3.println("\e");
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
      
      Serial.print(F("Row Length = "));
      Serial.println(Line_Length_Cycles);  
      
}



// Initial Start Up Values
    if (TFT_Menu_Command == 55) {
      Serial.println("TX Start Up Values TFT");

      if (PCB == 0) {
        Time t = rtc.time();
        Serial.println("PCB = 0 Time ");
        Serial.print(t.hr);
        Serial.print(":");
        Serial.println(t.min);
        Time_Hour = t.hr;
        Time_Minute = t.min;
        }
      if (PCB == 1) {        
        byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
        Read_DS3231_Time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month, &year);
        Time_Hour = hour;
        Time_Minute = minute;
        Time_Second = second;
        }

      Serial3.print(Alarm_1_ON);
      Serial3.println("\a");
      delay(300);  
      
      Serial3.print(Alarm_2_ON);
      Serial3.println("\b");
      delay(300);  
      
      Serial3.print(Alarm_3_ON);
      Serial3.println("\c");
      delay(300); 

      Serial3.print(Time_Hour);
      Serial3.println("\d");         // Sends the time to the Serial Monitor for the TFt to receive
      delay(300);  
          
      Serial3.print(Time_Minute);
      Serial3.println("\e");
      delay(100);

      Serial3.print(GPS_Enabled);
      Serial3.println("\f");
      delay(100);
 
      Serial3.print(Perimeter_Wire_Enabled);
      Serial3.println("\g");
      delay(100);

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



// Test Wire Sensor
    if (TFT_Menu_Command == 41) {
      Serial.println("Test Wire Sensor");

      bool Test_Complete = 0;

      for (int i = 0; i <= 30; i++) {

          if (i > 28) Test_Complete = 1;
            ADCMan.run();
            // ADCMan.setCapture(pinPerimeterLeft, 1, 0);
          
            if (millis() >= nextTime)  {
              nextTime = millis() + 50;
              if (perimeter.isInside(0) != inside) {
                inside = perimeter.isInside(0);
                counter++;
              }
            }
     
          Serial3.print((perimeter.isInside(0)));
          Serial3.println("\a");
          delay(300);  
    
          Serial3.print(perimeter.getMagnitude(0));
          Serial3.println("\b");
          delay(200);  

          Serial3.print(Test_Complete);
          Serial3.println("\c");
          delay(200);  
    
          Serial.print(F("IN/Out:"));
          Serial.print(perimeter.isInside(0));
          Serial.print(F("   MAG:"));
          Serial.print(perimeter.getMagnitude(0)); 
          Serial.print(F("   i:"));
          Serial.println(i);
          }
      Serial.println(F("Test Completed"));
      }


// Start Sonar Test
  if (TFT_Menu_Command == 45) {
    Serial.println(F("Sonar Test"));
    bool Test_Complete = 0;

      for (int i = 0; i <= 30; i++) {

        if (i > 28) Test_Complete = 1;
        if (Sonar_1_Activate == 1) distance1 = PingSonarY(trigPin1, echoPin1, 1, 1, 1, 5, 0);          //SONAR1
        if (Sonar_1_Activate == 0) distance1 = 999;
        delay(15);       
        if (Sonar_2_Activate == 1) distance2 = PingSonarY(trigPin2, echoPin2, 2, 2, 2, 0, 0);         //SONAR2
        if (Sonar_2_Activate == 0) distance1 = 999;
        delay(15);
        if (Sonar_3_Activate == 1) distance3 = PingSonarY(trigPin3, echoPin3, 3, 3, 3, 10, 0);          //SONAR3
        if (Sonar_3_Activate == 0) distance1 = 999;
        delay(15);
        
        Serial3.print(distance1);
        Serial3.println("\a");
        delay(300);  
    
        Serial3.print(distance2);
        Serial3.println("\b");
        delay(200);  

        Serial3.print(distance3);
        Serial3.println("\c");
        delay(200); 

        Serial3.print(Test_Complete);
        Serial3.println("\d");
        delay(200);    

        Serial.print("Test Complete");
        Serial.println(Test_Complete);
      
      
      }
    Serial.println(F("Sonar Test Complete"));
    

    }


// Start Compass Test
  if (TFT_Menu_Command == 48) {
    Serial.println(F("Compass Test"));
    bool Test_Complete = 0;

      int Cycles = 40;

      for (int i = 0; i <= Cycles; i++) {

        if (i > (Cycles - 2) ) Test_Complete = 1;
        Get_Compass_Reading();

        int Compass_Degrees_TX = Compass_Heading_Degrees;
        delay(300);
        
        Serial3.print(Heading * 10);
        Serial3.println("\a");
        delay(300);  
      
        Serial3.print(Compass_Degrees_TX);
        Serial3.println("\b");
        delay(300); 

        Serial.print("Heading: ");
        Serial.print(Heading);
        Serial.print("  Degrees: ");
        Serial.println(Compass_Degrees_TX);
  
     
        Serial3.print(Test_Complete);
        Serial3.println("\c");
        delay(300);    


      }

    Serial.print(F("Compass Test Complete"));
    Serial.println(Test_Complete);
    }


// Start GYRO Test
  if (TFT_Menu_Command == 39) {
    Serial.println(F("GYRO Test"));
    bool Test_Complete = 0;

      int Cycles = 60;

      for (int i = 0; i <= Cycles; i++) {

        if (i > (Cycles - 2) ) Test_Complete = 1;
        Get_GYRO_Reading();
        Print_GYRO_Reading();

       
        Serial3.print(GYRO_Angle_X);
        Serial3.println("\a");
        delay(300);  
      
        Serial3.print(GYRO_Angle_Y);
        Serial3.println("\b");
        delay(300); 
    
        Serial3.print(Test_Complete);
        Serial3.println("\c");
        delay(300);    

        //Serial.print("Angle X: ");
        //Serial.print(GYRO_Angle_X);
        //Serial.print(" Angle Y: ");
        //Serial.println(GYRO_Angle_Y);

      }

    Serial.print(F("Compass Test Complete"));
    Serial.println(Test_Complete);
    }


// Start Volt Amp Test
  if (TFT_Menu_Command == 47) {
    Serial.println(F("Volt Amp Test"));
    bool Test_Complete = 0;

      for (int i = 0; i <= 30; i++) {

        if (i > 28) Test_Complete = 1;
        
        Read_Serial1_Nano();
        delay(200);

        int VoltsRX = (Volts * 100) / 2;
   
        Serial3.print(VoltsRX);
        Serial3.println("\a");
        delay(100);  
    
        Serial3.print(Amps * 100);
        Serial3.println("\b");
        delay(100); 
        
        Serial3.print(Test_Complete);
        Serial3.println("\c");
        delay(300);    

        Serial.print("VoltsRX: ");
        Serial.print(VoltsRX);
        Serial.print("  Volts: ");
        Serial.print(Volts);
        Serial.print("  Amps: ");
        Serial.println(Amps);
      }

    Serial.print(F("Volt Amp Test Complete"));
    Serial.println(Test_Complete);
    }

// Start Tilt Test
  if (TFT_Menu_Command == 40) {
    Serial.println(F("Tilt Test"));
    bool Test_Complete = 0;
    Setup_Tilt_Tip_Safety();

      for (int i = 0; i <= 30; i++) {

        if (i > 28) Test_Complete = 1;
        
        Check_Tilt_Tip_Angle(); 
        delay(200);
   
        Serial3.print(Tilt_Angle_Sensed);
        Serial3.println("\a");
        delay(100);  
    
        Serial3.print(Tilt_Orientation_Sensed);
        Serial3.println("\b");
        delay(100); 
        
        Serial3.print(Test_Complete);
        Serial3.println("\c");
        delay(300);    

        Serial.print(F("   Data sent"));

        Serial.print(F("  Test Completed "));
        Serial.println(Test_Complete);
      }

    Serial.print(F("Tilt Test Complete : "));
    Serial.println(Test_Complete);
    }



// Start Bumper Test
  if (TFT_Menu_Command == 50) {
    Serial.println(F("Bumper Bar Test"));
    bool Test_Complete = 0;
    bool Bump_LH;
    bool Bump_RH;

      for (int i = 0; i <= 30; i++) {

        if (i > 28) Test_Complete = 1;
        
        if (digitalRead(Bumper_Switch_Frnt_LH))  Bump_LH = 0; 
        if (!digitalRead(Bumper_Switch_Frnt_LH)) Bump_LH = 1;
        if (digitalRead(Bumper_Switch_Frnt_RH))  Bump_RH = 0; 
        if (!digitalRead(Bumper_Switch_Frnt_RH)) Bump_RH = 1;
        delay(200);

        int VoltsRX = (Volts * 100) / 2;
   
        Serial3.print(Bump_LH);
        Serial3.println("\a");
        delay(100);  
    
        Serial3.print(Bump_RH);
        Serial3.println("\b");
        delay(100); 
        
        Serial3.print(Test_Complete);
        Serial3.println("\c");
        delay(300);    

        Serial.print("Bump LH: ");
        Serial.print(Bump_LH);
        Serial.print("  Bump RH: ");
        Serial.println(Bump_RH);
      }

    Serial.print(F("Volt Bumper Test Complete"));
    Serial.println(Test_Complete);
    }


}

void Send_Mower_Tracking_Data() {
        Serial3.print(Turn_To_Home);
        Serial3.println("\a");
        delay(100);  
    
        Serial3.print(Find_Wire_Track);
        Serial3.println("\b");
        delay(100); 
        
        Serial3.print(Go_To_Charging_Station);
        Serial3.println("\c");
        delay(300);    

        Serial3.print(Mower_Docked);
        Serial3.println("\d");
        delay(300);    

        Serial3.print(Mower_Status_Value);
        Serial3.println("\e");
        delay(300); 

        Serial3.print(Mower_Error_Value);
        Serial3.println("\f");
        delay(300); 
        

}

void Send_Mower_Error_Data() {
        
        Serial3.print(Mower_Status_Value);
        Serial3.println("\a");
        delay(300); 

        Serial3.print(Mower_Error_Value);
        Serial3.println("\b");
        delay(300); 
        
        Serial.print("Sending Error Data to TFT");

        Serial.print(F("|MS:"));
        Serial.print(Mower_Status_Value); 
        Serial.print(F("|ME:"));
        Serial.print(Mower_Error_Value); 
        }


void Send_Mower_Running_Data() {
        int Delay_running = 200;

        Serial.println("|TFT_Data Running Turn Point");
       
        Serial3.print(Sonar_Status);
        Serial3.println(F("\a"));        
        delay(Delay_running);
    
        Serial3.print(Outside_Wire);
        Serial3.println(F("\b"));
        delay(Delay_running);        
        
        Serial3.print(Bumper_Status);
        Serial3.println("\c");
        delay(Delay_running);    

        Serial3.print(Mower_Status_Value);
        Serial3.println("\d");
        delay(Delay_running);    

        Serial3.print(Mower_Error_Value);      
        Serial3.println("\e");
        delay(Delay_running); 
  
        Serial3.print(Tilt_Angle_Sensed);      
        Serial3.println("\f");
        delay(Delay_running); 

        // Reformet Volts value for transmission
        float VoltsTX1 = Volts * 100;
        VoltsTX = VoltsTX1;
        
        Serial3.print(VoltsTX);      
        Serial3.println("\g");
        delay(Delay_running);

        Serial3.print(GPS_Inside_Fence);      
        Serial3.println("\h");
        delay(Delay_running);

        Serial3.print(GPS_Lock_OK);      
        Serial3.println("\i");
        delay(Delay_running);        

        Calculate_TFT_Mower_Status_Value(); 


        Serial.print(F("|S:"));          
        Serial.print(Sonar_Status);
        Serial.print(F("|W:"));
        Serial.print(Outside_Wire);  
        Serial.print(F("|B:"));
        Serial.print(Bumper_Status); 
        Serial.print(F("|MS:"));
        Serial.print(Mower_Status_Value);  
        Serial.print(F("|ME:"));
        Serial.print(Mower_Error_Value); 
        Serial.print(F("|Tip:"));
        Serial.print(Tilt_Angle_Sensed);     
        Serial.print(F("|VTX:"));
        Serial.println(VoltsTX);          
        Serial.print(F("|GPS Inside Fence:"));
        if (GPS_Inside_Fence == 0) Serial.println("OUT");           
        if (GPS_Inside_Fence == 1) Serial.println("IN");
        Serial.print(F("|GPS Lock:"));
        if (GPS_Lock_OK == 0) Serial.println("No lock");           
        if (GPS_Lock_OK == 1) Serial.println("RTK FIX");
        }


// Sends Wheel Amp Data during Test
void Send_Wheel_Amp_Data() {
        Serial3.print(Wheel_Blocked);      
        Serial3.println("\a");
        delay(300);

      
        Serial.print(F("Wheel Status: "));
        if (Wheel_Blocked == 4) Serial.println("Blocked");
        if (Wheel_Blocked == 0) Serial.println("- - - -");
        }



// Transfers the values to the TFT in Docked Mode.
void Send_Mower_Docked_Data()  {

        Calculate_TFT_Mower_Status_Value(); 
        // Reformet Volts value for transmission
        float VoltsTX1 = Volts * 100;
        VoltsTX = VoltsTX1;
        
        Serial3.print(VoltsTX);      
        Serial3.println("\a");
        delay(300);
      
        Serial3.print(Mower_Status_Value);      
        Serial3.println("\b");
        delay(300); 

        Serial3.print(Mower_Error_Value);      
        Serial3.println("\c");
        delay(300);   

        Serial3.print(Charging);      
        Serial3.println("\d");
        delay(300); 

        int GPS_Lock_OK_Docked_TX;
        if (GPS_Lock_OK == 0) GPS_Lock_OK_Docked_TX = 2;
        if (GPS_Lock_OK == 1) GPS_Lock_OK_Docked_TX = 5;
        Serial3.print(GPS_Lock_OK_Docked_TX);      
        Serial3.println("\e");
        delay(300); 

        Serial.print(F("|VTX:"));
        Serial.print(VoltsTX);
        Serial.print(F("|MS:"));
        Serial.print(Mower_Status_Value);            
        Serial.print(F("|ME:"));
        Serial.print(Mower_Error_Value);                 
        Serial.print(F("|C:"));
        Serial.print(Charging); 
        Serial.print(F("|LOCK:"));
        Serial.print(GPS_Lock_OK);         
        
        } 

void Calculate_TFT_Mower_Status_Value() {

   Mower_Status_Value = 0;

   if ((Wire_Detected == 1) && (Tilt_Orientation_Sensed == 0)) {
      Mower_Error = 0;
      if ((Mower_Docked == 1) || (Mower_Parked == 1)) {   
         Mower_Error_Value = 0;
         }
   }

   
   
   if (Wire_Detected == 0) {

        // If the mower is running and no wire is detected then the full error screen is displayed
        if (Mower_Running == 1) {
              Mower_Error = 1;
              Mower_Error_Value = 1;     // 1 = No Wire Detected
              }
        // If the mower is docked then the Wire Off message is displayed on the docked screen. 
        if ((Mower_Docked == 1) || (Mower_Parked == 1)) {
              Mower_Error_Value = 1;
              }
        }


   if (Mower_Docked == 1)           Mower_Status_Value = 1;
   if (Mower_Parked == 1)           Mower_Status_Value = 2; 
   
   if (Mower_Parked_Low_Batt == 1)  {
     Mower_Status_Value = 4;  // Error Mode
     Mower_Error_Value = 2;   // 2 = Low Battery
     }
   
   if (Mower_Error == 1)                                    Mower_Status_Value = 4;  // Error
   if (Mower_Error == 3) {
        Mower_Status_Value = 4;  // Error
        Mower_Error_Value = 3;   
        }
   if (Mower_Running == 1)                                  Mower_Status_Value = 5;
   if (Manuel_Mode == 1)                                    Mower_Status_Value = 6;
   if (Tracking_Wire == 1)                                  Mower_Status_Value = 7;
   if (Rain_Hit_Detected == 1)                              Mower_Status_Value = 8;
   if (Exiting_Dock == 1)                                   Mower_Status_Value = 9;

   }
