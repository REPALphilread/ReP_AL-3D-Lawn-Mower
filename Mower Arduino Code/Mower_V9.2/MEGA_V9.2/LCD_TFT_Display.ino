// Infornation to be printed to the Mower LCD screen



void Setup_Run_LCD_Intro () {
  #if defined(LCD_KEYPAD)
  Serial.println(F("Setup LCD"));
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print(F("ReP_AL Robot"));
  lcd.setCursor(0,1);
  lcd.print(Version);  
  if (WIFI_Enabled == 1) {
    lcd.setCursor(7,1);
    lcd.print(F("WIFI ON"));
    }
  delay(1000);
  lcd.clear();
  Serial.println(F("LCD Setup OK"));
  #endif
  }


void Print_Mower_Error() {
  #if defined(LCD_KEYPAD)
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(F("Mower Error"));
  if (Wire_Off > 5) {
    lcd.setCursor(0,1);
    lcd.print("Wire Off");
    }
  if (Wire_Refind_Tries > 4) {
    lcd.setCursor(0,1);
    lcd.print(F("Cant Refind Wire"));
    }
  #endif  
  }
  


void Print_LCD_Volt_Info() {
   #if defined(LCD_KEYPAD)
   lcd.setCursor(10, 0);
   lcd.print("V:");
   lcd.setCursor(12, 0);    
   lcd.print(Volts); 
   #endif 
   }
        

void Print_Charging_LCD()  {
  #if defined(LCD_KEYPAD)
  lcd.setCursor(0,0);
  if (Charge_Detected_MEGA == 1)  lcd.print("Charging");
  if ((Rain_Detected == 0) && (Charge_Detected_MEGA != 1) ) lcd.print("        ");
  #endif
  }

void Print_Raining_LCD()  {
  #if defined(LCD_KEYPAD)
  lcd.setCursor(4,0);
  if (Rain_Detected == 1) lcd.print("Rain");
  // See raining and charging clause if this is not displying correctly.
    if ((Rain_Detected == 0) && (Charging == 0) ) lcd.print("    ");
  #endif
  }

void Print_Recharge_LCD() {
    #if defined(LCD_KEYPAD)
    lcd.setCursor(0,1);
    lcd.print("Recharge Batt");
    #endif
    }

void Print_LCD_Wire()  {
    #if defined(LCD_KEYPAD)
    lcd.setCursor(0, 1);
    lcd.print("WIRE Detect ");     
    #endif
    }

void Print_LCD_Mowing() {
     #if defined(LCD_KEYPAD)
     if (Alarm_Timed_Mow_ON == 0) {
       lcd.setCursor(0, 1);
       lcd.print("Mowing..    ");
       }
     if ((Alarm_Timed_Mow_ON == 1) && ( Loop_Cycle_Mowing < 15)) {
       lcd.setCursor(0,1);
       lcd.print("Timer:");
       lcd.print(Alarm_Timed_Mow_Hour);
       lcd.print(":");
       if (Alarm_Timed_Mow_Minute < 10) lcd.print("0");
       lcd.print(Alarm_Timed_Mow_Minute);
       Mow_Time_Set = 1;
       }         
     #endif
     }

void Print_LCD_Spiral() {
     #if defined(LCD_KEYPAD)
     if (Alarm_Timed_Mow_ON == 0) {
       lcd.setCursor(0, 1);
       lcd.print("Spiral.. ");
       }
     if ((Alarm_Timed_Mow_ON == 1) && ( Loop_Cycle_Mowing < 15)) {
       lcd.setCursor(0,1);
       lcd.print("Timer:");
       lcd.print(Alarm_Timed_Mow_Hour);
       lcd.print(":");
       if (Alarm_Timed_Mow_Minute < 10) lcd.print("0");
       lcd.print(Alarm_Timed_Mow_Minute);
       Mow_Time_Set = 1;
       }          
     #endif
     }

void Print_LCD_Parallel() {
     #if defined(LCD_KEYPAD)
     if (Alarm_Timed_Mow_ON == 0) {
       lcd.setCursor(0, 1);
       lcd.print("Parallel");
       }
     if ((Alarm_Timed_Mow_ON == 1) && ( Loop_Cycle_Mowing < 15)) {
       lcd.setCursor(0,1);
       lcd.print("Timer:");
       lcd.print(Alarm_Timed_Mow_Hour);
       lcd.print(":");
       if (Alarm_Timed_Mow_Minute < 10) lcd.print("0");
       lcd.print(Alarm_Timed_Mow_Minute);
       Mow_Time_Set = 1;
       }         
     #endif
     }
     
void Print_LCD_Compass_Mowing() {
     #if defined(LCD_KEYPAD)
     if (Compass_Heading_Locked == 1) {
         if ( Loop_Cycle_Mowing > 15) {
             lcd.setCursor(0, 1);
             if (PWM_Right > PWM_Left)  lcd.print("<Mow         ");      
             if (PWM_Left > PWM_Right)  lcd.print(" Mow>        "); 
             if (PWM_Left == PWM_Right) lcd.print("|Mow|        ");
             }
     }
     if (Compass_Heading_Locked == 0) {
         lcd.setCursor(0, 1);
         lcd.print("           ");      
         }
     #endif
     }

void Print_LCD_Parallel_Mowing() {
     #if defined(LCD_KEYPAD)
     if (Compass_Heading_Locked == 1) {
         lcd.setCursor(0, 1);
         if (PWM_Right > PWM_Left)  lcd.print("< P Mow         ");      
         if (PWM_Left > PWM_Right)  lcd.print(" P Mow >        "); 
         if (PWM_Left == PWM_Right) lcd.print("| P Mow |       ");
         }
     if (Compass_Heading_Locked == 0) {
         lcd.setCursor(0, 1);
         lcd.print(" Parllel ");      
         }
     #endif
     }

void Print_LCD_Info_Parked() {
    #if defined(LCD_KEYPAD)
    lcd.setCursor(0,1);
    lcd.print("Parked");
    #endif
    }

void Print_LCD_Info_Manuel() {
    #if defined(LCD_KEYPAD)
    lcd.setCursor(0,1);
    lcd.print("Manuel");
    #endif
    }

void Print_LCD_Info_Docked() {
    #if defined(LCD_KEYPAD)
    lcd.setCursor(0,1);
    lcd.print("Docked");  
    #endif
    }

void Print_LCD_NO_Wire() {
    #if defined(LCD_KEYPAD)
    if ( (Mower_Docked == 1) || (Mower_Parked == 1) ) {
      lcd.setCursor(7,1);
      lcd.print(":WIRE OFF");  
      Wire_ON_Printed = 0;
      }
    if ( (Mower_Docked == 0) && (Mower_Parked == 0) ) {
      lcd.setCursor(0,1);
      lcd.print(":WIRE OFF        ");      
      Wire_ON_Printed = 0;
      }
    #endif
}

void Print_LCD_Wire_ON() {
    #if defined(LCD_KEYPAD)
    if ( (Mower_Docked == 1) || (Mower_Parked == 1)  && (Wire_ON_Printed = 0)) {
      lcd.setCursor(7,1);
      lcd.print(":               ");  
      Wire_ON_Printed = 1; 
      }
    if ( (Mower_Docked == 0) && (Mower_Parked == 0) && (Wire_ON_Printed = 0) ) {
      lcd.setCursor(0,1);
      lcd.print(":               ");   
      Wire_ON_Printed = 1;    
      }
    #endif
}

void Print_Sonar_Hit()  {
    #if defined(LCD_KEYPAD)
    lcd.setCursor(0,1);
    lcd.print("Sonar Object ");  
    #endif
    }

void Print_LCD_Compass_Home() {
    #if defined(LCD_KEYPAD)
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Compass Home");
    if (Rain_Detected == 1) {
       lcd.setCursor(0,1);
       lcd.print("RAINING");
       }
    #endif
    }



void Print_Time_On_LCD() {
    #if defined(LCD_KEYPAD)
    if ((Charge_Detected_MEGA == 0) && (Mower_Running == 0) && (Rain_Detected == 0)) {      
      
      if (PCB == 1) {
          Display_DS3231_Time();  
          //Time_Hour = hour;
          //Time_Minute = minute;
          //Time_Second = second;     
          lcd.setCursor(0,0);
          lcd.print(Time_Hour);
          lcd.print(":");
          if (Time_Minute < 10) lcd.print ("0");
          lcd.print(Time_Minute);
          }
       if (PCB == 0) {
          lcd.setCursor(0,0);            // Spaces to the right & down
          Time t = rtc.time();
          lcd.print(t.hr);
          lcd.print(":");
          if (t.min < 10) lcd.print ("0");
          lcd.print(t.min);
          }
    }
    #endif
}


    
   
