// digital clock display of the time
void DisplayTime()   {
  Serial.print(F("Time:"));
  Time t = rtc.time();
 
  // Name the day of the week.
  const String day = dayAsString(t.day);

  // Format the time and date and insert into the temporary buffer.
  char buf[50];
  snprintf(buf, sizeof(buf), "%s %04d-%02d-%02d %02d:%02d:%02d",
           day.c_str(),
           t.yr, t.mon, t.date,
           t.hr, t.min, t.sec);

  // Print the formatted string to serial so we can see the time.
  Serial.println(buf);
 
  }

void Set_Mower_Time ()     {
  // Sets up time options in the LCD menu
  lcd.setCursor(3,0);
  lcd.print("Mow 1 Hour");
  lcd.setCursor(3,1);
  lcd.print("Mow Max Time");
  Mow_Time_Set = 0;
  while (Mow_Time_Set == 0)  {
      Read_Membrane_Keys();
      if(!Plus_Key_X) {
         DisplayTime();
         lcd.setCursor(0,0);
         lcd.print(">");
         lcd.setCursor(0,1);
         lcd.print(" ");
         Alarm_3_ON = 1;                          // Activate Alarm 3 (1 = ON 0 = OFF)
         Alarm_Hour3 = Time_Hour + 1;                 // Sets time to 1 hour later.
         Alarm_Minute3 = Time_Minute;

         Serial.print(F("Finish Time set to : "));
         Serial.print(Alarm_Hour3);
         Serial.print(F(":"));
         Serial.println(Alarm_Minute3);
         Create_Alarms();
         delay(100);
         Display_Next_Alarm();
         delay(100);
         }
         Read_Membrane_Keys();
         if(!Minus_Key_X) {
           lcd.setCursor(0,0);
           lcd.print(" ");
           lcd.setCursor(0,1);
           lcd.print(">");
           Alarm_3_ON = 0;
           Create_Alarms();
           delay(100);
           Display_Next_Alarm();
           delay(100);
           }
         if(!Start_Key_X) {
           Mow_Time_Set = 1;
           lcd.clear();
           if (Alarm_3_ON == 1) {
             lcd.print("1hr Mow Time");
             lcd.setCursor(0,1);
             lcd.print("Selected");
             }
         if (Alarm_3_ON == 0) {
             lcd.print("Mow Max Time");
             lcd.setCursor(0,1);
             lcd.print("Selected");
             }
         delay(2000);
         Serial.println(F("Alarm Confirmed"));
         delay(500);
         Menu_Mode_Selection = 0;
         }
        if(!Stop_Key_X){
           Serial.println(F("Stop key is pressed"));
           Alarm_3_ON = 0;
           Create_Alarms();
           delay(100);
           Display_Next_Alarm();
           delay(100);
           lcd.clear();
           lcd.setCursor(0,0);
           lcd.print("Menu Cancelled");
           delay(2000);
           lcd.clear(); 
           Menu_Complete = true;
           Menu_Mode_Selection = 0;
           Mow_Time_Set = 2;         
           } 
    }
 }

void Create_Alarms() {
 if (Alarm_1_ON == 1 ) Alarm.alarmRepeat(Alarm_Hour1, Alarm_Minute1, Alarm_Second, Manouver_Start_Mower);
 if (Alarm_2_ON == 1 ) Alarm.alarmRepeat(Alarm_Hour2, Alarm_Minute2, Alarm_Second, Manouver_Start_Mower);
 if (Alarm_3_ON == 1 ) Alarm.alarmOnce(Alarm_Hour3, Alarm_Minute3, Alarm_Second, Timed_Mow);
 }


// Prints the alarms set to the serial monitor
void Display_Next_Alarm()  {
  Serial.print("Alarm:");
  //Print_Day();
  
  if (Alarm_1_ON == 1 ) {
  Serial.print(F(" "));
  Serial.print(Alarm_Hour1);
  Serial.print(F(":"));
  Serial.print(Alarm_Minute1);
  Serial.print("|");
  }
 
  if (Alarm_2_ON == 1) {
  Serial.print(F(" "));
  Serial.print(Alarm_Hour2);
  Serial.print(F(":"));
  Serial.print(Alarm_Minute2);
  Serial.print("|");
  }

  if (Alarm_3_ON == 1) {
  Serial.print(F(" "));
  Serial.print(Alarm_Hour3);
  Serial.print(F(":"));
  Serial.print(Alarm_Minute3);
  Serial.print("|");
  }

  if ((Alarm_1_ON == 0)  && (Alarm_2_ON == 0) && (Alarm_3_ON == 0) ){
    Serial.print("X");
  }
  
}

void Set_Time_On_RTC(){
   // Set_Time to 1 in the setting menu to set time.  Load the sketch then immediatley Set_Time = 0 and reload the sketch.
        rtc.writeProtect(false);
        rtc.halt(false);
        Time t(2019, 06, 23, 13, 30, 00, Time::kSunday);            // Year XXXX, Month XX, Day XX, Hour XX, Minute XX, Second, kXYZday
        rtc.time(t);    
        delay(10);
   }

void Timed_Mow() {
      Alarm_3_ON = 0;
      Create_Alarms();
      lcd.clear();
      lcd.print("1 hour Mow. Job");
      lcd.setCursor(0,1);
      lcd.print("Done. Going Home!");
      Motor_Action_Stop_Motors();
      Motor_Action_Stop_Spin_Blades(); 
      delay(200);
      Serial.println(F("**************************************************"));
      Serial.println(F("                   Mow Time Over"));
      Serial.println(F("                    1 Hour ALARM"));
      Serial.println(F("**************************************************"));
      delay(5000);
      lcd.clear();
      lcd.print("Returning Home");
      Serial.println(F("1hr Mow Complete - Sending Mower Home"));
      if (Use_Charging_Station == 1) Manouver_Go_To_Charging_Station();
      if (Use_Charging_Station == 0) Manouver_Park_The_Mower();
      lcd.clear();
  }
