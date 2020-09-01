void Set_Time_On_RTC(){
   // Uncomment the next 4 lines to reset the time on the clock
        rtc.writeProtect(false);
        rtc.halt(false);
        Time t(2019, 03, 24, 10, 36, 00, Time::kSaturday);         // Year XXXX, Month XX, Day XX, Hour XX, Minute XX, Second, kXYZday
        rtc.time(t);    
        delay(10);
   }

void SetTime() {
  setTime(Time_Hour, Time_Minute, Time_Second, Time_Day, Time_Month, Time_Year);
}


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

void Setup_Get_RTC1302_Time() {
  // Get the current time and date from the chip.
  Time t = rtc.time();         // Get the time vlaues from the RTC t.yr, t.mon, t.date, t.hr, t.min, t.sec, t.day);
  delay(5);
  Time_Hour = (t.hr);          // Atribute the time from the RTC to the local variables used.  Get Hour.
  delay(5);
  Time_Minute = (t.min);  
  delay(5);
  Time_Second = (t.sec);
  delay(5);  
  Time_Day = (t.day);
  delay(5);
  Time_Month = (t.mon);
  delay(5);
  Time_Year = (t.yr);
  delay(5);
  
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
        // After Mow time is selected then mower can be started.  
}


// Function to stop mowing at a certain time
void Timed_Mow() {
      Alarm_3_ON = 0;
      Create_Alarms();
      lcd.clear();
      lcd.print("1 hour Mow. Job");
      lcd.setCursor(0,1);
      lcd.print("Done. Going Home!");
      Motion_StopMotors();
      delay(200);
      StopSpinBlades(); 
      delay(200);
      Serial.println(F("**************************************************"));
      Serial.println(F("                   Mow Time Over"));
      Serial.println(F("                    1 Hour ALARM"));
      Serial.println(F("**************************************************"));
      delay(5000);
      lcd.clear();
      lcd.print("Returning Home");
      Serial.println(F("Sending Mower Home"));
      delay(100),
      Serial.println(F("Error Mode Set to 7"));
      Error = 7; // Sets mower into the Error mode to find home
      Mower_Docked = 0;
      MowerMotionStatus = 1;
      delay(100);
      delay(3000);
      lcd.clear();
  
  }

void Create_Alarms() {
 if (Alarm_1_ON == 1 ) Alarm.alarmRepeat(Alarm_Hour1, Alarm_Minute1, Alarm_Second, StartMower);
 if (Alarm_2_ON == 1 ) Alarm.alarmRepeat(Alarm_Hour2, Alarm_Minute2, Alarm_Second, StartMower);
  //Only for testing function switch off in settings
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

void Print_Day () {
  if (Alarm_Day_of_Week == 1) Serial.print(F("Sun"));
  if (Alarm_Day_of_Week == 2) Serial.print(F("Mon"));
  if (Alarm_Day_of_Week == 3) Serial.print(F("Tue"));
  if (Alarm_Day_of_Week == 4) Serial.print(F("Wed"));
  if (Alarm_Day_of_Week == 5) Serial.print(F("Thu"));
  if (Alarm_Day_of_Week == 6) Serial.print(F("Fri"));
  if (Alarm_Day_of_Week == 7) Serial.print(F("Sat"));
}

void printDigits(int digits)
{
  Serial.print(F(":"));
  if (digits < 10)
    Serial.print('0');
  Serial.print(digits);
}
