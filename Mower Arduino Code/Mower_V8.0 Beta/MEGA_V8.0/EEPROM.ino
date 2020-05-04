// Loads the saved values from EEPROM
// to the settings menu.

void Load_EEPROM_Saved_Data() {

Serial.println("*** EEPROM Settings ***");
  
  int Alarm_1_Saved_EEPROM = EEPROM.read(1);
  
  if (Alarm_1_Saved_EEPROM == 1) {
    Alarm_1_Hour    = EEPROM.read(2);
    Alarm_1_Minute  = EEPROM.read(3);
    Alarm_1_ON      = EEPROM.read(4);
    Alarm_1_Action  = EEPROM.read(87);
    Serial.print(F("Alarm 1 time from EEPROM "));
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

    
  int Alarm_2_Saved_EEPROM = EEPROM.read(5);
  
  if (Alarm_2_Saved_EEPROM == 1) {
    Alarm_2_Hour    = EEPROM.read(6);
    Alarm_2_Minute  = EEPROM.read(7);
    Alarm_2_ON      = EEPROM.read(8);
    Alarm_2_Action  = EEPROM.read(88);
    Serial.print(F("Alarm 2 time from EEPROM "));
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

  int Alarm_3_Saved_EEPROM = EEPROM.read(9);
  
  if (Alarm_3_Saved_EEPROM == 1) {
    Alarm_3_Hour    = EEPROM.read(10);
    Alarm_3_Minute  = EEPROM.read(11);
    Alarm_3_ON      = EEPROM.read(12);
    Alarm_3_Action  = EEPROM.read(89);
    Serial.print(F("Alarm 3 time from EEPROM "));
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

    

  int PWM_LEFT_EEPROM = EEPROM.read(13);
  if (PWM_LEFT_EEPROM == 1) {
    PWM_MaxSpeed_LH = EEPROM.read(14);
    Serial.print(F("PWM Wheel Left value from EEPROM : "));
    Serial.println(PWM_MaxSpeed_LH);
  }

  int PWM_RIGHT_EEPROM = EEPROM.read(15);
  if (PWM_RIGHT_EEPROM == 1) {
    PWM_MaxSpeed_RH = EEPROM.read(16); 
    Serial.print(F("PWM Wheel Right value from EEPROM : ")); 
    Serial.println(PWM_MaxSpeed_RH);
  }

  int PWM_LEFT_Slow_EEPROM = EEPROM.read(94);
  if (PWM_LEFT_Slow_EEPROM == 1) {
    PWM_Slow_Speed_LH = EEPROM.read(95);
    Serial.print(F("PWM Wheel Wire Left value from EEPROM : "));
    Serial.println(PWM_Slow_Speed_LH);
  }

  int PWM_RIGHT_Slow_EEPROM = EEPROM.read(96);
  if (PWM_RIGHT_Slow_EEPROM == 1) {
    PWM_Slow_Speed_RH = EEPROM.read(97); 
    Serial.print(F("PWM Wheel Wire Right value from EEPROM : ")); 
    Serial.println(PWM_Slow_Speed_RH);
  }

  int Slow_Speed_MAG_EEPROM = EEPROM.read(98);
  if (Slow_Speed_MAG_EEPROM == 1) {
    Slow_Speed_MAG = EEPROM.read(99); 
    Slow_Speed_MAG = (Slow_Speed_MAG * -1 ) * 10;
    Serial.print(F("Slow Speed MAG from EEPROM : ")); 
    Serial.println(Slow_Speed_MAG);
  }


  int PWM_BLADE_EEPROM = EEPROM.read(17);
  if (PWM_BLADE_EEPROM == 1) {
    PWM_Blade_Speed = EEPROM.read(18); 
    Serial.print(F("PWM Blade value from EEPROM : ")); 
    Serial.println(PWM_Blade_Speed);
  }

  int COMPASS_EEPROM = EEPROM.read(19);
  if (COMPASS_EEPROM == 1) {
    Compass_Activate = EEPROM.read(20);  
    Serial.print(F("Compass Settings from EEPROM : "));
    if (Compass_Activate == 0) Serial.println(F("OFF"));
    if (Compass_Activate == 1) Serial.println(F("ON"));
  }
  //Compass_Activate = 0;

 int Tracking_PID_P_EEPROM = EEPROM.read(21);
  if (Tracking_PID_P_EEPROM == 1) {
    P = EEPROM.read(22); 
    P = P / 100; 
    Serial.print(F("Traking PID P Setting from EEPROM : "));
    Serial.println(P);
  }


  int Pattern_Mow_EEPROM = EEPROM.read(23);
  if (Pattern_Mow_EEPROM == 1) {
    Pattern_Mow = EEPROM.read(24);  
    Serial.print(F("Pattern Mow settings from EEPROM : "));
    if (Pattern_Mow == 0) Serial.println(F("OFF"));
    if (Pattern_Mow == 1) Serial.println(F("ON Parallel"));
    if (Pattern_Mow == 3) Serial.println(F("ON Spiral"));
  }


  int Minimum_Volt_EEPROM = EEPROM.read(25);
  if (Minimum_Volt_EEPROM == 1) {
    Battery_Min = EEPROM.read(26); 
    Battery_Min = Battery_Min / 10; 
    Serial.print(F("Minimum Battery Voltage set from EEPROM : "));
    Serial.println(Battery_Min);
  }


  int Compass_Home_EEPROM = EEPROM.read(27);
  if (Compass_Home_EEPROM == 1) {
    Home_Wire_Compass_Heading = (EEPROM.read(28) * 10);    // *10 as value can be more than 255. Vaule is therefore stored as a tenth value
    Serial.print(F("Compass Home Degrees : ")); 
    Serial.println(Home_Wire_Compass_Heading);
  }

  int Angle_Sensor_Enabled_EEPROM = EEPROM.read(29);
  if (Angle_Sensor_Enabled_EEPROM == 1) {
    Angle_Sensor_Enabled = EEPROM.read(30);  
    Serial.print(F("Angle Sensor Enabled from EEPROM : "));
    if (Angle_Sensor_Enabled == 0) Serial.println(F("OFF"));
    if (Angle_Sensor_Enabled == 1) Serial.println(F("ON"));
  }


  int Tip_Over_Sensor_Enabled_EEPROM = EEPROM.read(92);
  if (Tip_Over_Sensor_Enabled_EEPROM == 1) {
    Tip_Over_Sensor_Enabled = EEPROM.read(93);  
    Serial.print(F("Tip Sensor Enabled from EEPROM :  "));
    if (Tip_Over_Sensor_Enabled == 0) Serial.println(F("OFF"));
    if (Tip_Over_Sensor_Enabled == 1) Serial.println(F("ON"));
  }

  int Mower_Turn_Delay_Min_EEPROM = EEPROM.read(31);
  if (Mower_Turn_Delay_Min_EEPROM == 1) {
    Mower_Turn_Delay_Min = EEPROM.read(32);
    Mower_Turn_Delay_Min = Mower_Turn_Delay_Min * 100;
    Serial.print(F("Mower Turn Delay Min From EEPROM : "));
    Serial.println(Mower_Turn_Delay_Min);
  }

  int Mower_Turn_Delay_Max_EEPROM = EEPROM.read(33);
  if (Mower_Turn_Delay_Max_EEPROM == 1) {
    Mower_Turn_Delay_Max = EEPROM.read(34);
    Mower_Turn_Delay_Max =  Mower_Turn_Delay_Max * 100; 
    Serial.print(F("Mower Turn Delay Max From EEPROM : "));
    Serial.println(Mower_Turn_Delay_Max);
  }

  int Mower_Reverse_Delay_EEPROM = EEPROM.read(35);
  if (Mower_Reverse_Delay_EEPROM == 1) {
    Mower_Reverse_Delay = EEPROM.read(36);
    Mower_Reverse_Delay = (Mower_Reverse_Delay * 100);
    Serial.print(F("Mower Reverse Time Delay/ms: "));
    Serial.println(Mower_Reverse_Delay);
  }

  int Sonar_1_Activate_EEPROM = EEPROM.read(37);
  if (Sonar_1_Activate_EEPROM == 1) {
    Sonar_1_Activate = EEPROM.read(38);
    Serial.print(F("Sonar 1 Activated: "));
    Serial.println(Sonar_1_Activate);
  }

  int Sonar_2_Activate_EEPROM = EEPROM.read(39);
  if (Sonar_2_Activate_EEPROM == 1) {
    Sonar_2_Activate = EEPROM.read(40);
    Serial.print(F("Sonar 2 Activated: "));
    Serial.println(Sonar_2_Activate);
  }

  int Sonar_3_Activate_EEPROM = EEPROM.read(41);
  if (Sonar_3_Activate_EEPROM == 1) {
    Sonar_3_Activate = EEPROM.read(42);
    Serial.print(F("Sonar 3 Activated: "));
    Serial.println(Sonar_3_Activate);
  }

  int Track_Wire_Zone_1_Cycles_EEPROM = EEPROM.read(43);
  if (Track_Wire_Zone_1_Cycles_EEPROM == 1) {
    Track_Wire_Zone_1_Cycles = EEPROM.read(44);
    Track_Wire_Zone_1_Cycles = (Track_Wire_Zone_1_Cycles * 100);
    Serial.print(F("Zone 1 Tracking Cycles "));
    Serial.println(Track_Wire_Zone_1_Cycles);
  }

  int Track_Wire_Zone_2_Cycles_EEPROM = EEPROM.read(45);
  if (Track_Wire_Zone_2_Cycles_EEPROM == 1) {
    Track_Wire_Zone_2_Cycles = EEPROM.read(46);
    Track_Wire_Zone_2_Cycles = (Track_Wire_Zone_2_Cycles * 100);
    Serial.print(F("Zone 2 Tracking Cycles "));
    Serial.println(Track_Wire_Zone_2_Cycles);
  }


  int Use_Charging_Station_EEPROM = EEPROM.read(47);
  if (Use_Charging_Station_EEPROM == 1) {
    Use_Charging_Station = EEPROM.read(48);  
    Serial.print(F("Compass Settings from EEPROM : "));
    if (Use_Charging_Station == 0) Serial.println(F("OFF"));
    if (Use_Charging_Station == 1) Serial.println(F("ON"));
  }


  int CW_Tracking_To_Charge_EEPROM = EEPROM.read(49);
  if (CW_Tracking_To_Charge_EEPROM == 1) {
    CW_Tracking_To_Charge = EEPROM.read(50);  
    Serial.print(F("Tracking Direction to Charge : "));
    if (CW_Tracking_To_Charge == 1) Serial.println(F("CW"));
    if (CW_Tracking_To_Charge == 0) Serial.println(F("OFF"));
  }

  int CCW_Tracking_To_Charge_EEPROM = EEPROM.read(51);
  if (CCW_Tracking_To_Charge_EEPROM == 1) {
    CCW_Tracking_To_Charge = EEPROM.read(52);  
    Serial.print(F("Tracking Direction to Charge : "));
    if (CCW_Tracking_To_Charge == 1) Serial.println(F("CCW"));
    if (CCW_Tracking_To_Charge == 0) Serial.println(F("OFF"));
  }

  int CW_Tracking_To_Start_EEPROM = EEPROM.read(53);
  if (CW_Tracking_To_Start_EEPROM == 1) {
    CW_Tracking_To_Start = EEPROM.read(54);  
    Serial.print(F("Tracking Direction to Start : "));
    if (CW_Tracking_To_Start == 1) Serial.println(F("CW"));
    if (CW_Tracking_To_Start == 0) Serial.println(F("OFF"));
  }

  int CCW_Tracking_To_Start_EEPROM = EEPROM.read(55);
  if (CCW_Tracking_To_Start_EEPROM == 1) {
    CCW_Tracking_To_Start = EEPROM.read(56);  
    Serial.print(F("Tracking Direction to Start : "));
    if (CCW_Tracking_To_Start == 1) Serial.println(F("CCW"));
    if (CCW_Tracking_To_Start == 0) Serial.println(F("OFF"));
  }



  int Max_Cycles_Straight_EEPROM = EEPROM.read(57);
  if (Max_Cycles_Straight_EEPROM == 1) {
    Max_Cycles_Straight = EEPROM.read(58);
    Max_Cycles_Straight = (Max_Cycles_Straight * 10);
    Serial.print(F("Straight Line Cycles before turn: "));
    Serial.println(Max_Cycles_Straight);
  }


  int Compass_Heading_Hold_Enabled_EEPROM = EEPROM.read(59);
  if (Compass_Heading_Hold_Enabled_EEPROM == 1) {
    Compass_Heading_Hold_Enabled = EEPROM.read(60);  
    Serial.print(F("Compass HEading Hold Settings from EEPROM : "));
    if (Compass_Heading_Hold_Enabled == 0) Serial.println(F("OFF"));
    if (Compass_Heading_Hold_Enabled == 1) Serial.println(F("ON"));
  }

  int CPower_EEPROM = EEPROM.read(61);
  if (CPower_EEPROM == 1) {
    CPower = EEPROM.read(62); 
    CPower = CPower / 100; 
    Serial.print(F("Traking PID P Setting from EEPROM : "));
    Serial.println(CPower);
  }

  int Max_Sonar_Hit_EEPROM = EEPROM.read(63);
  if (Max_Sonar_Hit_EEPROM == 1) {
    Max_Sonar_Hit = EEPROM.read(64); 
    Serial.print(F("Sonar Sensitivoty from EEPROM : "));
    Serial.println(Max_Sonar_Hit);
  }

  int maxdistancesonar_EEPROM = EEPROM.read(65);
  if (maxdistancesonar_EEPROM == 1) {
    maxdistancesonar = EEPROM.read(66); 
    Serial.print(F("Sonar Activation Distance from EEPROM : "));
    Serial.println(maxdistancesonar);
  }


  int Perimeter_Wire_Enabled_EEPROM = EEPROM.read(67);
  if (Perimeter_Wire_Enabled_EEPROM == 1) {
    Perimeter_Wire_Enabled = EEPROM.read(68);  
    Serial.print(F("Wire Module ON/OFF from EEPROM : "));
    if (Perimeter_Wire_Enabled == 0) Serial.println(F("OFF"));
    if (Perimeter_Wire_Enabled == 1) Serial.println(F("ON"));
  }



  int Max_Cycle_Wire_Find_EEPROM = EEPROM.read(69);
  if (Max_Cycle_Wire_Find_EEPROM == 1) {
    Max_Cycle_Wire_Find = EEPROM.read(70);
    Max_Cycle_Wire_Find = (Max_Cycle_Wire_Find * 10);
    Serial.print(F("Track Cycles Forwards to find Wire "));
    Serial.println(Max_Cycle_Wire_Find);
  }

  int Max_Cycle_Wire_Find_Back_EEPROM = EEPROM.read(71);
  if (Max_Cycle_Wire_Find_Back_EEPROM == 1) {
    Max_Cycle_Wire_Find_Back = EEPROM.read(72);
    Max_Cycle_Wire_Find_Back = (Max_Cycle_Wire_Find_Back * 10);
    Serial.print(F("Track Cycles Back to find Wire "));
    Serial.println(Max_Cycle_Wire_Find_Back);
  }



  int Max_Tracking_Turn_Right_EEPROM = EEPROM.read(73);
  if (Max_Tracking_Turn_Right_EEPROM == 1) {
    Max_Tracking_Turn_Right = EEPROM.read(74);
    Max_Tracking_Turn_Right = (Max_Tracking_Turn_Right * 10);
    Serial.print(F("Wheel RH Cycles before restart "));
    Serial.println(Max_Tracking_Turn_Right);
  }

  int Max_Tracking_Turn_Left_EEPROM = EEPROM.read(75);
  if (Max_Tracking_Turn_Left_EEPROM == 1) {
    Max_Tracking_Turn_Left = EEPROM.read(76);
    Max_Tracking_Turn_Left = (Max_Tracking_Turn_Left * 10);
    Serial.print(F("Wheel LH Cycles before restart "));
    Serial.println(Max_Tracking_Turn_Left);
  }

  int Rain_Sensor_Installed_EEPROM = EEPROM.read(77);
  if (Rain_Sensor_Installed_EEPROM == 1) {
    Rain_Sensor_Installed = EEPROM.read(78);  
    Serial.print(F("Rain Sensor ON/OFF from EEPROM : "));
    if (Rain_Sensor_Installed == 0) Serial.println(F("OFF"));
    if (Rain_Sensor_Installed == 1) Serial.println(F("ON"));
  }


  int Rain_Total_Hits_Go_Home_EEPROM = EEPROM.read(79);
  if (Rain_Total_Hits_Go_Home_EEPROM == 1) {
    Rain_Total_Hits_Go_Home = EEPROM.read(80); 
    Serial.print(F("Rain Sensitivoty from EEPROM : "));
    Serial.println(Rain_Total_Hits_Go_Home);
  }

  int WIFI_Enabled_EEPROM = EEPROM.read(81);
  if (WIFI_Enabled_EEPROM == 1) {
    WIFI_Enabled = EEPROM.read(82);  
    Serial.print(F("WIFI Enabled from EEPROM : "));
    if (WIFI_Enabled == 0) Serial.println(F("OFF"));
    if (WIFI_Enabled == 1) Serial.println(F("ON"));
  }

  int Cutting_Blades_Activate_EEPROM = EEPROM.read(83);
  if (Cutting_Blades_Activate_EEPROM == 1) {
    Cutting_Blades_Activate = EEPROM.read(84);  
    Serial.print(F("CUTTING BLADES SET TO : "));
    if (Cutting_Blades_Activate == 0) Serial.println(F("OFF"));
    if (Cutting_Blades_Activate == 1) Serial.println(F("ON"));
  }


  int Low_Battery_Instances_Chg_EEPROM = EEPROM.read(85);
  if (Low_Battery_Instances_Chg_EEPROM == 1) {
    Low_Battery_Instances_Chg = EEPROM.read(86); 
    Serial.print(F("Battery to Charge Sensitivoty from EEPROM : "));
    Serial.println(Low_Battery_Instances_Chg);
  }


  int Bumper_Activate_Frnt_EEPROM = EEPROM.read(90);
  if (Bumper_Activate_Frnt_EEPROM == 1) {
    Bumper_Activate_Frnt = EEPROM.read(91);  
    Serial.print(F("Bumper Bar Enabled from EEPROM : "));
    if (Bumper_Activate_Frnt == 0) Serial.println(F("OFF"));
    if (Bumper_Activate_Frnt == 1) Serial.println(F("ON"));
  }


Serial.println(F("*************************"));
 delay(500);

}


void Clear_EERPOM() {
  EEPROM.write(1,0);      // Clear Alarm 1
  EEPROM.write(5,0);      // Clear Alarm 2
  EEPROM.write(9,0);      // Clear Alarm 3
  EEPROM.write(13,0);     // Clear PWM Left Wheel
  EEPROM.write(15,0);     // Clear PWM Right Wheel
  EEPROM.write(17,0);     // Clear PWM Blade
  EEPROM.write(19,0);     // Clear Compass Setting EEPROM
  EEPROM.write(21,0);     // Clear PID Setting
  EEPROM.write(23,0);     // Clear Pattern Mow
  EEPROM.write(25,0);     // Clear Volt Minimum
  EEPROM.write(27,0);     // Clear Compass Home
  EEPROM.write(29,0);     // Clear Tilt Tip Safety
  EEPROM.write(31,0);     // Clear Turn Time Min
  EEPROM.write(33,0);     // Clear Turn Time Max
  EEPROM.write(35,0);     // Clear Reverse Time
  EEPROM.write(37,0);     // Clear Sonar 1
  EEPROM.write(39,0);     // Clear Sonar 2
  EEPROM.write(41,0);     // Clear Sonar 3
  EEPROM.write(43,0);     // Clear Zone 1 Cycles
  EEPROM.write(45,0);     // Clear Zone 2 Cycles
  EEPROM.write(47,0);     // Clear Charging Station Options
  EEPROM.write(49,0);     // Reset CW and CCW Exit and Dock Directions
  EEPROM.write(51,0);     //  CW CCW Tracking
  EEPROM.write(53,0);     //  CW CCW Tracking
  EEPROM.write(55,0);     //  CW CCW Tracking
  EEPROM.write(57,0);     // Max Cycle Straight
  EEPROM.write(59,0);     // Compass Heading HOld ON/OFF
  EEPROM.write(61,0);     // Compass PID reset.
  EEPROM.write(63,0);     // Sonar sensitivity.
  EEPROM.write(65,0);      // MAx distance sonar reset.
  EEPROM.write(67,0);     // Wire Sensor ON/OFF
  EEPROM.write(69,0);     // Track cycles Forwards
  EEPROM.write(71,0);     // Track Cycles Back
  EEPROM.write(73,0);     // RH Cycles to restart
  EEPROM.write(75,0);     // LH Cycles to restart
  EEPROM.write(77,0);     // Rain ON/OFF
  EEPROM.write(79,0);     // Rain sensitivity
  EEPROM.write(81,0);     // WIFI ON/OFF
  EEPROM.write(83,0);     // Cutting Blades ON/OFF
  EEPROM.write(85,0);     // Batt sensitivity;
  EEPROM.write(87,0);     // Alarm Actions 1-3
  EEPROM.write(88,0);
  EEPROM.write(89,0);
  EEPROM.write(90,0);     // Bumper Bar
  EEPROM.write(92,0);     // Tip Over sensor
  EEPROM.write(94,0);     // Wheel Slow Speed LH
  EEPROM.write(96,0);     // Wheel Slow Speed RH
  EEPROM.write(98,0);     // Slow MAG Point
  Serial.println(F("All EEPROM Settings Cleared"));
  delay(1000);
  
}
