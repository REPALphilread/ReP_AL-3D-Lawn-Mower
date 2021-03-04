

// Loads the saved values from DueFlash
// to the settings menuu

void Load_DueFlash_Saved_Data() {

#if defined(BOARD_DUE)

Serial.println("Loading DueFlash Settings");
  
  int Alarm_1_Saved_DueFlash = DueFlash.read(1);
  
  if (Alarm_1_Saved_DueFlash == 1) {
    Alarm_1_Hour    = DueFlash.read(2);
    Alarm_1_Minute  = DueFlash.read(3);
    Alarm_1_ON      = DueFlash.read(4);
    Alarm_1_Action  = DueFlash.read(87);
    Serial.print(F("Alarm 1 time from DueFlash "));
    Serial.print(Alarm_1_Hour);
    Serial.print(F(":"));
    if (Alarm_1_Minute < 10) Serial.print("0");
    Serial.println(Alarm_1_Minute);
    Serial.print("Alarm Action 1 =");
    if (Alarm_1_ON == 0) Serial.println(" | Alarm 1 OFF");
    if (Alarm_1_ON == 1) Serial.println(" | Alarm 1 Active");
    if (Alarm_1_Action == 1) Serial.println("Exit Zone 1");
    if (Alarm_1_Action == 2) Serial.println("Exit Zone 2");
    if (Alarm_1_Action == 3) Serial.println("Mow the Line");
    if (Alarm_1_Action == 4) Serial.println("Quick Start");
    if (Alarm_1_Action == 5) Serial.println("Custom");
    }

    
  int Alarm_2_Saved_DueFlash = DueFlash.read(5);
  
  if (Alarm_2_Saved_DueFlash == 1) {
    Alarm_2_Hour    = DueFlash.read(6);
    Alarm_2_Minute  = DueFlash.read(7);
    Alarm_2_ON      = DueFlash.read(8);
    Alarm_2_Action  = DueFlash.read(88);
    Serial.print(F("Alarm 2 time from DueFlash "));
    Serial.print(Alarm_2_Hour);
    Serial.print(F(":"));
    if (Alarm_2_Minute < 10) Serial.print("0");
    Serial.print(Alarm_2_Minute);
    if (Alarm_2_ON == 0) Serial.println(" | Alarm 2 OFF");
    if (Alarm_2_ON == 1) Serial.println(" | Alarm 2 Active");
    if (Alarm_2_Action == 1) Serial.println("Exit Zone 1");
    if (Alarm_2_Action == 2) Serial.println("Exit Zone 2");
    if (Alarm_2_Action == 3) Serial.println("Mow the Line");
    if (Alarm_2_Action == 4) Serial.println("Quick Start");
    if (Alarm_2_Action == 5) Serial.println("Custom");
    }

  int Alarm_3_Saved_DueFlash = DueFlash.read(9);
  
  if (Alarm_3_Saved_DueFlash == 1) {
    Alarm_3_Hour    = DueFlash.read(10);
    Alarm_3_Minute  = DueFlash.read(11);
    Alarm_3_ON      = DueFlash.read(12);
    Alarm_3_Action  = DueFlash.read(89);
    Serial.print(F("Alarm 3 time from DueFlash "));
    Serial.print(Alarm_3_Hour);
    Serial.print(F(":"));
    if (Alarm_3_Minute < 10) Serial.print("0");
    Serial.print(Alarm_3_Minute);
    if (Alarm_3_ON == 0) Serial.println(" | Alarm 3 OFF");
    if (Alarm_3_ON == 1) Serial.println(" | Alarm 3 Active");
    if (Alarm_3_Action == 1) Serial.println("Exit Zone 1");
    if (Alarm_3_Action == 2) Serial.println("Exit Zone 2");
    if (Alarm_3_Action == 3) Serial.println("Mow the Line");
    if (Alarm_3_Action == 4) Serial.println("Quick Start");
    if (Alarm_3_Action == 5) Serial.println("Custom");
    }

    

  int PWM_LEFT_DueFlash = DueFlash.read(13);
  if (PWM_LEFT_DueFlash == 1) {
    PWM_MaxSpeed_LH = DueFlash.read(14);
    Serial.print(F("PWM Wheel Left value from DueFlash : "));
    Serial.println(PWM_MaxSpeed_LH);
  }

  int PWM_RIGHT_DueFlash = DueFlash.read(15);
  if (PWM_RIGHT_DueFlash == 1) {
    PWM_MaxSpeed_RH = DueFlash.read(16); 
    Serial.print(F("PWM Wheel Right value from DueFlash : ")); 
    Serial.println(PWM_MaxSpeed_RH);
  }

  int PWM_LEFT_Slow_DueFlash = DueFlash.read(94);
  if (PWM_LEFT_Slow_DueFlash == 1) {
    PWM_Slow_Speed_LH = DueFlash.read(95);
    Serial.print(F("PWM Wheel Wire Left value from DueFlash : "));
    Serial.println(PWM_Slow_Speed_LH);
  }

  int PWM_RIGHT_Slow_DueFlash = DueFlash.read(96);
  if (PWM_RIGHT_Slow_DueFlash == 1) {
    PWM_Slow_Speed_RH = DueFlash.read(97); 
    Serial.print(F("PWM Wheel Wire Right value from DueFlash : ")); 
    Serial.println(PWM_Slow_Speed_RH);
  }

  int Slow_Speed_MAG_DueFlash = DueFlash.read(98);
  if (Slow_Speed_MAG_DueFlash == 1) {
    Slow_Speed_MAG = DueFlash.read(99); 
    Slow_Speed_MAG = (Slow_Speed_MAG * -1 ) * 10;
    Serial.print(F("Slow Speed MAG from DueFlash : ")); 
    Serial.println(Slow_Speed_MAG);
  }


  int PWM_BLADE_DueFlash = DueFlash.read(17);
  if (PWM_BLADE_DueFlash == 1) {
    PWM_Blade_Speed = DueFlash.read(18); 
    Serial.print(F("PWM Blade value from DueFlash : ")); 
    Serial.println(PWM_Blade_Speed);
  }

  int COMPASS_DueFlash = DueFlash.read(19);
  if (COMPASS_DueFlash == 1) {
    Compass_Activate = DueFlash.read(20);  
    Serial.print(F("Compass Activated from DueFlash : "));
    if (Compass_Activate == 0) Serial.println(F("OFF"));
    if (Compass_Activate == 1) Serial.println(F("ON"));
  }

  int COMPASS_Setup_Mode_DueFlash = DueFlash.read(113);
  if (COMPASS_Setup_Mode_DueFlash == 1) {
    Compass_Setup_Mode = DueFlash.read(114);  
    Serial.print(F("Compass Setup Mode from DueFlash : "));
   if (Compass_Setup_Mode == 1) Serial.println(F("Setup DFRobot_QMC5883 Compass"));
   if (Compass_Setup_Mode == 2) Serial.println(F("Setup QMC5883_Manual Compass"));           
   if (Compass_Setup_Mode == 3) Serial.println(F("Setup QMC5883L Compass"));      
   }

  int Compass_Heading_Hold_Enabled_DueFlash = DueFlash.read(59);
  if (Compass_Heading_Hold_Enabled_DueFlash == 1) {
    Compass_Heading_Hold_Enabled = DueFlash.read(60);  
    Serial.print(F("Compass HEading Hold Settings from DueFlash : "));
    if (Compass_Heading_Hold_Enabled == 0) Serial.println(F("OFF"));
    if (Compass_Heading_Hold_Enabled == 1) Serial.println(F("ON"));
  }

  int CPower_DueFlash = DueFlash.read(61);
  if (CPower_DueFlash == 1) {
    CPower = DueFlash.read(62); 
    CPower = CPower / 10; 
    Serial.print(F("Compass Power from DueFlash : "));
    Serial.println(CPower);
  }



  int Compass_Home_DueFlash = DueFlash.read(27);
  if (Compass_Home_DueFlash == 1) {
    Home_Wire_Compass_Heading = (DueFlash.read(28) * 10);    // *10 as value can be more than 255. Vaule is therefore stored as a tenth value
    Serial.print(F("Compass Home Degrees : ")); 
    Serial.println(Home_Wire_Compass_Heading);
  }

 int Tracking_PID_P_DueFlash = DueFlash.read(21);
  if (Tracking_PID_P_DueFlash == 1) {
    P = DueFlash.read(22); 
    P = P / 100; 
    Serial.print(F("Traking PID P Setting from DueFlash : "));
    Serial.println(P);
  }


  int Pattern_Mow_DueFlash = DueFlash.read(23);
  if (Pattern_Mow_DueFlash == 1) {
    Pattern_Mow = DueFlash.read(24);  
    //Pattern_Mow = 1;
    Serial.print(F("Pattern Mow settings from DueFlash : "));
    if (Pattern_Mow == 0) Serial.println(F("OFF"));
    if (Pattern_Mow == 1) Serial.println(F("ON Parallel"));
    if (Pattern_Mow == 3) Serial.println(F("ON Spiral"));
  }


  int Minimum_Volt_DueFlash = DueFlash.read(25);
  if (Minimum_Volt_DueFlash == 1) {
    Battery_Min = DueFlash.read(26); 
    Battery_Min = Battery_Min / 10; 
    Serial.print(F("Minimum Battery Voltage set from DueFlash : "));
    Serial.println(Battery_Min);
  }



  int Angle_Sensor_Enabled_DueFlash = DueFlash.read(29);
  if (Angle_Sensor_Enabled_DueFlash == 1) {
    Angle_Sensor_Enabled = DueFlash.read(30);  
    Serial.print(F("Angle Sensor Enabled from DueFlash : "));
    if (Angle_Sensor_Enabled == 0) Serial.println(F("OFF"));
    if (Angle_Sensor_Enabled == 1) Serial.println(F("ON"));
  }


  int Tip_Over_Sensor_Enabled_DueFlash = DueFlash.read(92);
  if (Tip_Over_Sensor_Enabled_DueFlash == 1) {
    Tip_Over_Sensor_Enabled = DueFlash.read(93);  
    Serial.print(F("Tip Sensor Enabled from DueFlash :  "));
    if (Tip_Over_Sensor_Enabled == 0) Serial.println(F("OFF"));
    if (Tip_Over_Sensor_Enabled == 1) Serial.println(F("ON"));
  }

  int Mower_Turn_Delay_Min_DueFlash = DueFlash.read(31);
  if (Mower_Turn_Delay_Min_DueFlash == 1) {
    Mower_Turn_Delay_Min = DueFlash.read(32);
    Mower_Turn_Delay_Min = Mower_Turn_Delay_Min * 100;
    Serial.print(F("Mower Turn Delay Min From DueFlash : "));
    Serial.println(Mower_Turn_Delay_Min);
  }

  int Mower_Turn_Delay_Max_DueFlash = DueFlash.read(33);
  if (Mower_Turn_Delay_Max_DueFlash == 1) {
    Mower_Turn_Delay_Max = DueFlash.read(34);
    Mower_Turn_Delay_Max =  Mower_Turn_Delay_Max * 100; 
    Serial.print(F("Mower Turn Delay Max From DueFlash : "));
    Serial.println(Mower_Turn_Delay_Max);
  }

  int Mower_Reverse_Delay_DueFlash = DueFlash.read(35);
  if (Mower_Reverse_Delay_DueFlash == 1) {
    Mower_Reverse_Delay = DueFlash.read(36);
    Mower_Reverse_Delay = (Mower_Reverse_Delay * 100);
    Serial.print(F("Mower Reverse Time Delay/ms: "));
    Serial.println(Mower_Reverse_Delay);
  }

  int Sonar_1_Activate_DueFlash = DueFlash.read(37);
  if (Sonar_1_Activate_DueFlash == 1) {
    Sonar_1_Activate = DueFlash.read(38);
    Serial.print(F("Sonar 1 Activated: "));
    Serial.println(Sonar_1_Activate);
  }

  int Sonar_2_Activate_DueFlash = DueFlash.read(39);
  if (Sonar_2_Activate_DueFlash == 1) {
    Sonar_2_Activate = DueFlash.read(40);
    Serial.print(F("Sonar 2 Activated: "));
    Serial.println(Sonar_2_Activate);
  }

  int Sonar_3_Activate_DueFlash = DueFlash.read(41);
  if (Sonar_3_Activate_DueFlash == 1) {
    Sonar_3_Activate = DueFlash.read(42);
    Serial.print(F("Sonar 3 Activated: "));
    Serial.println(Sonar_3_Activate);
  }

  int Track_Wire_Zone_1_Cycles_DueFlash = DueFlash.read(43);
  if (Track_Wire_Zone_1_Cycles_DueFlash == 1) {
    Track_Wire_Zone_1_Cycles = DueFlash.read(44);
    Track_Wire_Zone_1_Cycles = (Track_Wire_Zone_1_Cycles * 100);
    Serial.print(F("Zone 1 Tracking Cycles "));
    Serial.println(Track_Wire_Zone_1_Cycles);
  }

  int Track_Wire_Zone_2_Cycles_DueFlash = DueFlash.read(45);
  if (Track_Wire_Zone_2_Cycles_DueFlash == 1) {
    Track_Wire_Zone_2_Cycles = DueFlash.read(46);
    Track_Wire_Zone_2_Cycles = (Track_Wire_Zone_2_Cycles * 100);
    Serial.print(F("Zone 2 Tracking Cycles "));
    Serial.println(Track_Wire_Zone_2_Cycles);
  }


  int Use_Charging_Station_DueFlash = DueFlash.read(47);
  if (Use_Charging_Station_DueFlash == 1) {
    Use_Charging_Station = DueFlash.read(48);  
    Serial.print(F("Charge Station from DueFlash : "));
    if (Use_Charging_Station == 0) Serial.println(F("OFF"));
    if (Use_Charging_Station == 1) Serial.println(F("ON"));
  }


  int CW_Tracking_To_Charge_DueFlash = DueFlash.read(49);
  if (CW_Tracking_To_Charge_DueFlash == 1) {
    CW_Tracking_To_Charge = DueFlash.read(50);  
    Serial.print(F("Tracking Direction to Charge : "));
    if (CW_Tracking_To_Charge == 1) Serial.println(F("CW"));
    if (CW_Tracking_To_Charge == 0) Serial.println(F("OFF"));
  }

  int CCW_Tracking_To_Charge_DueFlash = DueFlash.read(51);
  if (CCW_Tracking_To_Charge_DueFlash == 1) {
    CCW_Tracking_To_Charge = DueFlash.read(52);  
    Serial.print(F("Tracking Direction to Charge : "));
    if (CCW_Tracking_To_Charge == 1) Serial.println(F("CCW"));
    if (CCW_Tracking_To_Charge == 0) Serial.println(F("OFF"));
  }

  int CW_Tracking_To_Start_DueFlash = DueFlash.read(53);
  if (CW_Tracking_To_Start_DueFlash == 1) {
    CW_Tracking_To_Start = DueFlash.read(54);  
    Serial.print(F("Tracking Direction to Start : "));
    if (CW_Tracking_To_Start == 1) Serial.println(F("CW"));
    if (CW_Tracking_To_Start == 0) Serial.println(F("OFF"));
  }

  int CCW_Tracking_To_Start_DueFlash = DueFlash.read(55);
  if (CCW_Tracking_To_Start_DueFlash == 1) {
    CCW_Tracking_To_Start = DueFlash.read(56);  
    Serial.print(F("Tracking Direction to Start : "));
    if (CCW_Tracking_To_Start == 1) Serial.println(F("CCW"));
    if (CCW_Tracking_To_Start == 0) Serial.println(F("OFF"));
  }



  int Max_Cycles_Straight_DueFlash = DueFlash.read(57);
  if (Max_Cycles_Straight_DueFlash == 1) {
    Max_Cycles_Straight = DueFlash.read(58);
    Max_Cycles_Straight = (Max_Cycles_Straight * 10);
    Serial.print(F("Straight Line Cycles before turn: "));
    Serial.println(Max_Cycles_Straight);
  }




  int Max_Sonar_Hit_DueFlash = DueFlash.read(63);
  if (Max_Sonar_Hit_DueFlash == 1) {
    Max_Sonar_Hit = DueFlash.read(64); 
    Serial.print(F("Sonar Sensitivoty from DueFlash : "));
    Serial.println(Max_Sonar_Hit);
  }

  int maxdistancesonar_DueFlash = DueFlash.read(65);
  if (maxdistancesonar_DueFlash == 1) {
    maxdistancesonar = DueFlash.read(66); 
    Serial.print(F("Sonar Activation Distance from DueFlash : "));
    Serial.println(maxdistancesonar);
  }


  int Perimeter_Wire_Enabled_DueFlash = DueFlash.read(67);
  if (Perimeter_Wire_Enabled_DueFlash == 1) {
    Perimeter_Wire_Enabled = DueFlash.read(68);  
    Serial.print(F("Wire Module ON/OFF from DueFlash : "));
    if (Perimeter_Wire_Enabled == 0) Serial.println(F("OFF"));
    if (Perimeter_Wire_Enabled == 1) Serial.println(F("ON"));
  }



  int Max_Cycle_Wire_Find_DueFlash = DueFlash.read(69);
  if (Max_Cycle_Wire_Find_DueFlash == 1) {
    Max_Cycle_Wire_Find = DueFlash.read(70);
    Max_Cycle_Wire_Find = (Max_Cycle_Wire_Find * 10);
    Serial.print(F("Track Cycles Forwards to find Wire "));
    Serial.println(Max_Cycle_Wire_Find);
  }

  int Max_Cycle_Wire_Find_Back_DueFlash = DueFlash.read(71);
  if (Max_Cycle_Wire_Find_Back_DueFlash == 1) {
    Max_Cycle_Wire_Find_Back = DueFlash.read(72);
    Max_Cycle_Wire_Find_Back = (Max_Cycle_Wire_Find_Back * 10);
    Serial.print(F("Track Cycles Back to find Wire "));
    Serial.println(Max_Cycle_Wire_Find_Back);
  }



  int Max_Tracking_Turn_Right_DueFlash = DueFlash.read(73);
  if (Max_Tracking_Turn_Right_DueFlash == 1) {
    Max_Tracking_Turn_Right = DueFlash.read(74);
    Max_Tracking_Turn_Right = (Max_Tracking_Turn_Right * 10);
    Serial.print(F("Wheel RH Cycles before restart "));
    Serial.println(Max_Tracking_Turn_Right);
  }

  int Max_Tracking_Turn_Left_DueFlash = DueFlash.read(75);
  if (Max_Tracking_Turn_Left_DueFlash == 1) {
    Max_Tracking_Turn_Left = DueFlash.read(76);
    Max_Tracking_Turn_Left = (Max_Tracking_Turn_Left * 10);
    Serial.print(F("Wheel LH Cycles before restart "));
    Serial.println(Max_Tracking_Turn_Left);
  }

  int Rain_Sensor_Installed_DueFlash = DueFlash.read(77);
  if (Rain_Sensor_Installed_DueFlash == 1) {
    Rain_Sensor_Installed = DueFlash.read(78);  
    Serial.print(F("Rain Sensor ON/OFF from DueFlash : "));
    if (Rain_Sensor_Installed == 0) Serial.println(F("OFF"));
    if (Rain_Sensor_Installed == 1) Serial.println(F("ON"));
  }


  int Rain_Total_Hits_Go_Home_DueFlash = DueFlash.read(79);
  if (Rain_Total_Hits_Go_Home_DueFlash == 1) {
    Rain_Total_Hits_Go_Home = DueFlash.read(80); 
    Serial.print(F("Rain Sensitivoty from DueFlash : "));
    Serial.println(Rain_Total_Hits_Go_Home);
  }

  int WIFI_Enabled_DueFlash = DueFlash.read(81);
  if (WIFI_Enabled_DueFlash == 1) {
    WIFI_Enabled = DueFlash.read(82);  
    Serial.print(F("WIFI Enabled from DueFlash : "));
    if (WIFI_Enabled == 0) Serial.println(F("OFF"));
    if (WIFI_Enabled == 1) Serial.println(F("ON"));
  }

  int Cutting_Blades_Activate_DueFlash = DueFlash.read(83);
  if (Cutting_Blades_Activate_DueFlash == 1) {
    Cutting_Blades_Activate = DueFlash.read(84);  
    Serial.print(F("CUTTING BLADES SET TO : "));
    if (Cutting_Blades_Activate == 0) Serial.println(F("OFF"));
    if (Cutting_Blades_Activate == 1) Serial.println(F("ON"));
  }


  int Low_Battery_Instances_Chg_DueFlash = DueFlash.read(85);
  if (Low_Battery_Instances_Chg_DueFlash == 1) {
    Low_Battery_Instances_Chg = DueFlash.read(86); 
    Serial.print(F("Battery to Charge Sensitivoty from DueFlash : "));
    Serial.println(Low_Battery_Instances_Chg);
  }


  int Bumper_Activate_Frnt_DueFlash = DueFlash.read(90);
  if (Bumper_Activate_Frnt_DueFlash == 1) {
    Bumper_Activate_Frnt = DueFlash.read(91);  
    Serial.print(F("Bumper Bar Enabled from DueFlash : "));
    if (Bumper_Activate_Frnt == 0) Serial.println(F("OFF"));
    if (Bumper_Activate_Frnt == 1) Serial.println(F("ON"));
  }



  int Turn_90_Delay_LH_DueFlash = DueFlash.read(101);
  if (Turn_90_Delay_LH_DueFlash == 1) {
    Turn_90_Delay_LH = DueFlash.read(102);  
    Turn_90_Delay_LH = Turn_90_Delay_LH * 10;
    Serial.print(F("Turn_90_Delay_LH Enabled from DueFlash : "));
    Serial.println(Turn_90_Delay_LH);
  }

  int Turn_90_Delay_RH_DueFlash = DueFlash.read(103);
  if (Turn_90_Delay_RH_DueFlash == 1) {
    Turn_90_Delay_RH = DueFlash.read(104);  
    Turn_90_Delay_RH = Turn_90_Delay_RH * 10;
    Serial.print(F("Turn_90_Delay_RH Enabled from DueFlash : "));
    Serial.println(Turn_90_Delay_RH);
  }

  int Line_Length_Cycles_DueFlash = DueFlash.read(105);
  if (Line_Length_Cycles_DueFlash == 1) {
    Line_Length_Cycles = DueFlash.read(106);  
    Line_Length_Cycles = Line_Length_Cycles * 10;
    Serial.print(F("Line_Length_Cycles Enabled from DueFlash : "));
    Serial.println(Line_Length_Cycles);
  }

  int GPS_Enabled_DueFlash = DueFlash.read(107);
  if (GPS_Enabled_DueFlash == 1) {
    GPS_Enabled = DueFlash.read(108);  
    Serial.print(F("GPS Enabled from DueFlash : "));
    if (GPS_Enabled == 0) Serial.println(F("Disabled"));
    if (GPS_Enabled == 1) Serial.println(F("Enabled"));
  }

  int GYRO_Enabled_DueFlash = DueFlash.read(109);
  if (GYRO_Enabled_DueFlash == 1) {
    GYRO_Enabled = DueFlash.read(110);  
    Serial.print(F("GYRO Enabled from DueFlash : "));
    if (GYRO_Enabled == 0) Serial.println(F("Disabled"));
    if (GYRO_Enabled == 1) Serial.println(F("Enabled"));
  }
  
  int GPower_DueFlash = DueFlash.read(111);
  if (GPower_DueFlash == 1) {
    GPower = DueFlash.read(112); 
    GPower = GPower / 10; 
    Serial.print(F("GYRO PID set from DueFlash : "));
    Serial.println(GPower);
  }


  int Wheel_Amp_Sensor_ON_Enabled_DueFlash = DueFlash.read(115);
  if (Wheel_Amp_Sensor_ON_Enabled_DueFlash == 1) {
    Wheel_Amp_Sensor_ON = DueFlash.read(116);  
    Serial.print(F("Wheel Block Amp Sensor Enabled from DueFlash : "));
    if (Wheel_Amp_Sensor_ON == 0) Serial.println(F("Disabled"));
    if (Wheel_Amp_Sensor_ON == 1) Serial.println(F("Enabled"));
  }
  
  int Max_Wheel_Amps_DueFlash = DueFlash.read(117);
  if (Max_Wheel_Amps_DueFlash == 1) {
    Max_Wheel_Amps = DueFlash.read(118); 
    Max_Wheel_Amps = Max_Wheel_Amps / 10; 
    Serial.print(F("Wheel Block Amps set from DueFlash : "));
    Serial.println(Max_Wheel_Amps);
  }

  int PCB_DueFlash = DueFlash.read(119);
  if (PCB_DueFlash == 1) {
    PCB = DueFlash.read(120); 
    Serial.print(F("PCB Enabled from DueFlash : "));
      if (PCB == 1) Serial.println(F("Enabled"));
      if (PCB == 0) Serial.println(F("Disabled"));
  }


Serial.println(F("*************************"));
 delay(500);

#endif

}


void Clear_FLASH() {
  
  #if defined(BOARD_DUE)
  
  DueFlash.write(1,0);      // Clear Alarm 1
  DueFlash.write(5,0);      // Clear Alarm 2
  DueFlash.write(9,0);      // Clear Alarm 3
  DueFlash.write(13,0);     // Clear PWM Left Wheel
  DueFlash.write(15,0);     // Clear PWM Right Wheel
  DueFlash.write(17,0);     // Clear PWM Blade
  DueFlash.write(19,0);     // Clear Compass Setting DueFlash
  DueFlash.write(21,0);     // Clear PID Setting
  DueFlash.write(23,0);     // Clear Pattern Mow
  DueFlash.write(25,0);     // Clear Volt Minimum
  DueFlash.write(27,0);     // Clear Compass Home
  DueFlash.write(29,0);     // Clear Tilt Tip Safety
  DueFlash.write(31,0);     // Clear Turn Time Min
  DueFlash.write(33,0);     // Clear Turn Time Max
  DueFlash.write(35,0);     // Clear Reverse Time
  DueFlash.write(37,0);     // Clear Sonar 1
  DueFlash.write(39,0);     // Clear Sonar 2
  DueFlash.write(41,0);     // Clear Sonar 3
  DueFlash.write(43,0);     // Clear Zone 1 Cycles
  DueFlash.write(45,0);     // Clear Zone 2 Cycles
  DueFlash.write(47,0);     // Clear Charging Station Options
  DueFlash.write(49,0);     // Reset CW and CCW Exit and Dock Directions
  DueFlash.write(51,0);     //  CW CCW Tracking
  DueFlash.write(53,0);     //  CW CCW Tracking
  DueFlash.write(55,0);     //  CW CCW Tracking
  DueFlash.write(57,0);     // Max Cycle Straight
  DueFlash.write(59,0);     // Compass Heading HOld ON/OFF
  DueFlash.write(61,0);     // Compass PID reset.
  DueFlash.write(63,0);     // Sonar sensitivity.
  DueFlash.write(65,0);      // MAx distance sonar reset.
  DueFlash.write(67,0);     // Wire Sensor ON/OFF
  DueFlash.write(69,0);     // Track cycles Forwards
  DueFlash.write(71,0);     // Track Cycles Back
  DueFlash.write(73,0);     // RH Cycles to restart
  DueFlash.write(75,0);     // LH Cycles to restart
  DueFlash.write(77,0);     // Rain ON/OFF
  DueFlash.write(79,0);     // Rain sensitivity
  DueFlash.write(81,0);     // WIFI ON/OFF
  DueFlash.write(83,0);     // Cutting Blades ON/OFF
  DueFlash.write(85,0);     // Batt sensitivity;
  DueFlash.write(87,0);     // Alarm Actions 1-3
  DueFlash.write(88,0);
  DueFlash.write(89,0);
  DueFlash.write(90,0);     // Bumper Bar
  DueFlash.write(92,0);     // Tip Over sensor
  DueFlash.write(94,0);     // Wheel Slow Speed LH
  DueFlash.write(96,0);     // Wheel Slow Speed RH
  DueFlash.write(98,0);     // Slow MAG Point
  DueFlash.write(102,0);    // Turn_90_Delay_LH 
  DueFlash.write(104,0);    // Turn_90_Delay_RH
  DueFlash.write(106,0);    // Line_Length_Cycles
  DueFlash.write(107,0);    // GPS Enabled
  DueFlash.write(109,0);    // GYRO Enabled
  DueFlash.write(111,0);    // GYRO Power
  DueFlash.write(113,0);    // Compass Setup Mode
  DueFlash.write(115,0);    // Wheel amp sensor 
  DueFlash.write(117,0);    // Wheel amp sensor value

  #endif
}
