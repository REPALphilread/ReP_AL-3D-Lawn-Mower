// Loads the saved values from EEPROM
// to the settings menu.

void Load_EEPROM_Saved_Data() {

Serial.println("*** EEPROM Settings ***");
  
  Alarm_1_Saved_EEPROM = EEPROM.read(1);
  
  if (Alarm_1_Saved_EEPROM == 1) {
    Alarm_1_Hour = EEPROM.read(2);
    Alarm_1_Minute = EEPROM.read(3);
    Alarm_1_ON = EEPROM.read(4);
    Serial.print(F("Alarm 1 time from EEPROM "));
    Serial.print(Alarm_1_Hour);
    Serial.print(F(":"));
    if (Alarm_1_Minute < 10) Serial.print("0");
    Serial.print(Alarm_1_Minute);
    if (Alarm_1_ON == 0) Serial.println(" | Alarm 1 OFF");
    if (Alarm_1_ON == 1) Serial.println(" | Alarm 1 Active");
    }

    
  Alarm_2_Saved_EEPROM = EEPROM.read(5);
  
  if (Alarm_2_Saved_EEPROM == 1) {
    Alarm_2_Hour = EEPROM.read(6);
    Alarm_2_Minute = EEPROM.read(7);
    Alarm_2_ON = EEPROM.read(8);
    Serial.print(F("Alarm 2 time from EEPROM "));
    Serial.print(Alarm_2_Hour);
    Serial.print(F(":"));
    if (Alarm_2_Minute < 10) Serial.print("0");
    Serial.print(Alarm_2_Minute);
    if (Alarm_2_ON == 0) Serial.println(" | Alarm 2 OFF");
    if (Alarm_2_ON == 1) Serial.println(" | Alarm 2 Active");
    }

  Alarm_3_Saved_EEPROM = EEPROM.read(9);
  
  if (Alarm_3_Saved_EEPROM == 1) {
    Alarm_3_Hour = EEPROM.read(10);
    Alarm_3_Minute = EEPROM.read(11);
    Alarm_3_ON = EEPROM.read(12);
    Serial.print(F("Alarm 3 time from EEPROM "));
    Serial.print(Alarm_3_Hour);
    Serial.print(F(":"));
    if (Alarm_3_Minute < 10) Serial.print("0");
    Serial.print(Alarm_3_Minute);
    if (Alarm_3_ON == 0) Serial.println(" | Alarm 3 OFF");
    if (Alarm_3_ON == 1) Serial.println(" | Alarm 3 Active");
    }

  PWM_LEFT_EEPROM = EEPROM.read(13);
  if (PWM_LEFT_EEPROM == 1) {
    PWM_MaxSpeed_LH = EEPROM.read(14);
    Serial.print(F("PWM Wheel Left value from EEPROM : "));
    Serial.println(PWM_MaxSpeed_LH);
  }

  PWM_RIGHT_EEPROM = EEPROM.read(15);
  if (PWM_RIGHT_EEPROM == 1) {
    PWM_MaxSpeed_RH = EEPROM.read(16); 
    Serial.print(F("PWM Wheel Right value from EEPROM : ")); 
    Serial.println(PWM_MaxSpeed_RH);
  }

  PWM_BLADE_EEPROM = EEPROM.read(17);
  if (PWM_BLADE_EEPROM == 1) {
    PWM_Blade_Speed = EEPROM.read(18); 
    Serial.print(F("PWM Blade value from EEPROM : ")); 
    Serial.println(PWM_Blade_Speed);
  }

  COMPASS_EEPROM = EEPROM.read(19);
  if (COMPASS_EEPROM == 1) {
    Compass_Activate = EEPROM.read(20);  
    Serial.print(F("Compass Settings from EEPROM : "));
    if (Compass_Activate == 0) Serial.println(F("OFF"));
    if (Compass_Activate == 1) Serial.println(F("ON"));
  }
  //Compass_Activate = 0;

 Traking_PID_P_EEPROM = EEPROM.read(21);
  if (Traking_PID_P_EEPROM == 1) {
    P = EEPROM.read(22); 
    P = P / 100; 
    Serial.print(F("Traking PID P Setting from EEPROM : "));
    Serial.println(P);
  }


  Pattern_Mow_EEPROM = EEPROM.read(23);
  if (Pattern_Mow_EEPROM == 1) {
    Pattern_Mow = EEPROM.read(24);  
    Serial.print(F("Pattern Mow settings from EEPROM : "));
    if (Pattern_Mow == 0) Serial.println(F("OFF"));
    if (Pattern_Mow == 1) Serial.println(F("ON Parallel"));
    if (Pattern_Mow == 3) Serial.println(F("ON Spiral"));
  }


  Minimum_Volt_EEPROM = EEPROM.read(25);
  if (Minimum_Volt_EEPROM == 1) {
    Battery_Min = EEPROM.read(26); 
    Battery_Min = Battery_Min / 10; 
    Serial.print(F("Minimum Battery Voltage set from EEPROM : "));
    Serial.println(Battery_Min);
  }


  Compass_Home_EEPROM = EEPROM.read(27);
  if (Compass_Home_EEPROM == 1) {
    Home_Wire_Compass_Heading = (EEPROM.read(28) * 10);    // *10 as value can be more than 255. Vaule is therefore stored as a tenth value
    Serial.print(F("Compass Home Degrees : ")); 
    Serial.println(Home_Wire_Compass_Heading);
  }

  Tip_Safety_EEPROM = EEPROM.read(29);
  if (Tip_Safety_EEPROM == 1) {
    Tip_Safety = EEPROM.read(30);  
    Serial.print(F("Pattern Mow settings from EEPROM : "));
    if (Tip_Safety == 0) Serial.println(F("OFF"));
    if (Tip_Safety == 1) Serial.println(F("ON"));
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
  Serial.println(F("All EEPROM Settings Cleared"));
  delay(1000);
  
}
