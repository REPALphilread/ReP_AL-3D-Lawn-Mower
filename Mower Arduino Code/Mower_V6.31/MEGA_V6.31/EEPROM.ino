// Loads the saved values from EEPROM
// to the settings menu.

void Load_EEPROM_Saved_Data() {
  
  Alarm_1_Saved_EEPROM = EEPROM.read(1);
  
  if (Alarm_1_Saved_EEPROM == 1) {
    Alarm_1_Hour = EEPROM.read(2);
    Alarm_1_Minute = EEPROM.read(3);
    Alarm_1_ON = EEPROM.read(4);
    Serial.print("Alarm 1 time from EEPROM ");
    Serial.print(Alarm_1_Hour);
    Serial.print(":");
    if (Alarm_1_Minute < 10) Serial.print("0");
    Serial.println(Alarm_1_Minute);
    }

    
  Alarm_2_Saved_EEPROM = EEPROM.read(5);
  
  if (Alarm_2_Saved_EEPROM == 1) {
    Alarm_2_Hour = EEPROM.read(6);
    Alarm_2_Minute = EEPROM.read(7);
    Alarm_2_ON = EEPROM.read(8);
    Serial.print("Alarm 2 time from EEPROM ");
    Serial.print(Alarm_2_Hour);
    Serial.print(":");
    if (Alarm_2_Minute < 10) Serial.print("0");
    Serial.println(Alarm_2_Minute);
    }

  Alarm_3_Saved_EEPROM = EEPROM.read(9);
  
  if (Alarm_3_Saved_EEPROM == 1) {
    Alarm_3_Hour = EEPROM.read(10);
    Alarm_3_Minute = EEPROM.read(11);
    Alarm_3_ON = EEPROM.read(12);
    Serial.print("Alarm 3 time from EEPROM ");
    Serial.print(Alarm_3_Hour);
    Serial.print(":");
    if (Alarm_3_Minute < 10) Serial.print("0");
    Serial.println(Alarm_3_Minute);
    }

  PWM_LEFT_EEPROM = EEPROM.read(13);
  if (PWM_LEFT_EEPROM == 1) {
    PWM_MaxSpeed_LH = EEPROM.read(14);
    Serial.print("PWM Wheel Left value from EEPROM : ");
    Serial.println(PWM_MaxSpeed_LH);
  }

  PWM_RIGHT_EEPROM = EEPROM.read(15);
  if (PWM_RIGHT_EEPROM == 1) {
    PWM_MaxSpeed_RH = EEPROM.read(16); 
    Serial.print("PWM Wheel Right value from EEPROM : "); 
    Serial.println(PWM_MaxSpeed_RH);
  }

  PWM_BLADE_EEPROM = EEPROM.read(17);
  if (PWM_BLADE_EEPROM == 1) {
    PWM_Blade_Speed = EEPROM.read(18); 
    Serial.print("PWM Blade value from EEPROM : "); 
    Serial.println(PWM_Blade_Speed);
  }

  COMPASS_EEPROM = EEPROM.read(19);
  if (COMPASS_EEPROM == 1) {
    Compass_Activate = EEPROM.read(20);  
    Serial.print("Compass Settings from EEPROM : ");
    if (Compass_Activate == 0) Serial.println("OFF");
    if (Compass_Activate == 1) Serial.println("ON");
  }
  //Compass_Activate = 0;

 Traking_PID_P_EEPROM = EEPROM.read(21);
  if (Traking_PID_P_EEPROM == 1) {
    P = EEPROM.read(22); 
    P = P / 100; 
    Serial.print("Traking PID P Setting from EEPROM : ");
    Serial.println(P);
  }
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
  Serial.println("All EEPROM Settings Cleared");
  delay(1000);
  
}
