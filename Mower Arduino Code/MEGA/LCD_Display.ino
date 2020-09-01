// Infornation to be printed to the Mower LCD screen

void Setup_Run_LCD_Intro () {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("ReP_AL Robot");
  lcd.setCursor(0,1);
  lcd.print(Version);  
  if (WIFI_Enabled == 1) {
    lcd.setCursor(7,1);
    lcd.print("WIFI ON");
    }
  delay(2000);
  lcd.clear();
  }


void Print_Mower_Lost() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Mower Lost");
  lcd.setCursor(0,1);
  lcd.print("Reset Mower");
  
}

void Print_LCD_Volt_Info() {
    lcd.setCursor(10, 0);
    lcd.print("V:");
    lcd.setCursor(12, 0);    
    lcd.print(VoltsTX);  
    }

void Print_Charging_LCD()  {
  lcd.setCursor(0,0);
  if (Charge_Detected == 4) lcd.print("Charging");
  if ((Rain_Detected == 0) && (Charge_Detected == 0) ) lcd.print("        ");
  }

void Print_Raining_LCD()  {
  lcd.setCursor(4,0);
  if (Rain_Detected == 1) lcd.print("Rain");
  // See raining and charging clause if this is not displying correctly.
    if ((Rain_Detected == 0) && (Charge_Detected == 0) ) lcd.print("    ");
  }

void Print_Recharge_LCD() {
    lcd.setCursor(0,1);
    lcd.print("Recharge Batt");
    }

void Print_LCD_Wire()  {
       lcd.setCursor(0, 1);
       lcd.print("WIRE Detect ");     
    }

void Print_LCD_Mowing() {
       lcd.setCursor(0, 1);
       lcd.print("Mowing..    ");   
     }

void Print_LCD_Compass_Mowing() {
     if (Compass_Heading_Locked == 1) {
         lcd.setCursor(0, 1);
         if (PWM_Right > PWM_Left)  lcd.print("<H-Lock Mow ");      
         if (PWM_Left > PWM_Right)  lcd.print(" H-Lock Mow>"); 
         if (PWM_Left == PWM_Right) lcd.print("|H-Lock Mow|");
         }
     if (Compass_Heading_Locked == 0) {
         lcd.setCursor(0, 1);
         lcd.print("            ");      
         }
     }

void Print_LCD_Info_Parked() {
    lcd.setCursor(0,1);
    lcd.print("Parked");
    }

void Print_LCD_Info_Docked() {
    lcd.setCursor(0,1);
    lcd.print("Docked");  
}

void Print_LCD_NO_Wire() {
    if ( (Mower_Docked == 1) || (Mower_Parked == 1) ) {
      lcd.setCursor(7,1);
      lcd.print(":WIRE OFF");  
      }
    if ( (Mower_Docked == 0) && (Mower_Parked == 0) ) {
      lcd.setCursor(0,1);
      lcd.print("WIRE OFF        ");      
      }
}

void Print_Sonar_Hit()  {
    lcd.setCursor(0,1);
    lcd.print("Sonar Object ");  
    }

void Print_LCD_Compass_Home() {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Compass Home");
    if (Rain_Detected == 1) {
     lcd.setCursor(0,1);
     lcd.print("RAINING");
    }
}

void Print_LCD_Heading_for_Home() {
  lcd.setCursor(0,1);
  lcd.print("Target:");
  lcd.print( ((Heading_Lower_Limit_Compass - Heading_Lower_Limit_Compass) / 2 ) + Heading_Lower_Limit_Compass);
  }


void Print_Time_On_LCD() {
    lcd.setCursor(0,0);            // Spaces to the right & down
    if ((hour()) < 10) {                //moves the cursor to the right otherwise the first hour number from before is left behind on the LCD.
      lcd.print("0");
      lcd.setCursor(1,0);
      }
    lcd.print(hour());
    lcd.print(":");

 
  if ((minute()) < 10) {
      lcd.print("0");
      }
   //lcd.print(minute());
  }
