
void Pattern_Mow_Spirals() {
      //analogWrite(ENAPin, PWM_MaxSpeed_RH - (100 - Loop_Cycle_Mowing));             // 255 - 200 = 55 up to 255 again.  (255 is max speed). Speed is set in the settings                        
      
      int PWM_1 = 50;         // diameter 0.4m    
      int PWM_2 = 70;         //                    
      int PWM_3 = 95;
      int PWM_4 = 110;
      int PWM_5 = 125;        //
      int PWM_6 = 135;
      int PWM_7 = 145;        // (diameter 3-4m)

      int End_Linking                     = 10;      // straight line section between spirals  15 is approx 3-4m
      int End_Spiral_1   = End_Linking    + 10;      // sets the number of cycles within Spiral 1
      int End_Spiral_2   = End_Spiral_1   + 30;
      int End_Spiral_3   = End_Spiral_2   + 35;
      int End_Spiral_4   = End_Spiral_3   + 50;      // Sets the number of cycles within Spiral 4
      int End_Spiral_5   = End_Spiral_4   + 70;
      int End_Spiral_6   = End_Spiral_5   + 90;
      int End_Spiral_7   = End_Spiral_6   + 120;     // sets the number of cylces within Spiral 7

      // Total number of cycels in all sections should not exceed the Max_Cycles_Spirals 
      // otherwise the mower will stop before the spiral pattern is completed



      // Spiral_Mow = 1 is a Right Hand Sprial
      // Spiral_Mow = 2 is a left hand Spiral
      // Sprial:Mow = 3 no sprial and a normal straight line move

      Get_Compass_Reading();  // keeps the compass active
      
      if (Spiral_Mow == 1) analogWrite(ENBPin, PWM_MaxSpeed_LH);  
      if (Spiral_Mow == 2) analogWrite(ENAPin, PWM_MaxSpeed_RH);
      if (Spiral_Mow == 3) {
        analogWrite(ENAPin, PWM_MaxSpeed_RH);
        analogWrite(ENBPin, PWM_MaxSpeed_LH);
      }

      if (Spiral_Mow < 3) {
        
      
      Serial.print(F("Wheel:CIRCLE|"));

      #if defined(LCD_KEYPAD)
      lcd.setCursor(9,1);
      if (Spiral_Mow == 1) lcd.print("R");
      if (Spiral_Mow == 2) lcd.print("L");
      if (Spiral_Mow == 3) lcd.print("|");
      #endif
      

      if (Loop_Cycle_Mowing < End_Linking) {
        if (Spiral_Mow == 1) analogWrite(ENAPin, PWM_MaxSpeed_RH);
        if (Spiral_Mow == 2) analogWrite(ENBPin, PWM_MaxSpeed_LH);

        #if defined(LCD_KEYPAD)
        lcd.print("|");
        #endif
        
        }

      //Inside Spiral
      if ((Loop_Cycle_Mowing >= End_Linking) && (Loop_Cycle_Mowing < End_Spiral_1)) {
        if (Spiral_Mow == 1) analogWrite(ENAPin, PWM_1);
        if (Spiral_Mow == 2) analogWrite(ENBPin, PWM_1);

        #if defined(LCD_KEYPAD)
        lcd.print("1");
        #endif
        }

      // Sprial Ring 2
      if ((Loop_Cycle_Mowing >= End_Spiral_1) && (Loop_Cycle_Mowing < End_Spiral_2)) {
        if (Spiral_Mow == 1) analogWrite(ENAPin, PWM_2);
        if (Spiral_Mow == 2) analogWrite(ENBPin, PWM_2);

        #if defined(LCD_KEYPAD)
        lcd.print("2");        
        #endif
        }

      // Sprial Ring 3
      if ((Loop_Cycle_Mowing >= End_Spiral_2) && (Loop_Cycle_Mowing < End_Spiral_3)) {
        if (Spiral_Mow == 1) analogWrite(ENAPin, PWM_3);
        if (Spiral_Mow == 2) analogWrite(ENBPin, PWM_3);

        #if defined(LCD_KEYPAD)
        lcd.print("3");        
        #endif
         
        }

      // Sprial Ring 4
      if ((Loop_Cycle_Mowing >= End_Spiral_3) && (Loop_Cycle_Mowing < End_Spiral_4)) {
        if (Spiral_Mow == 1) analogWrite(ENAPin, PWM_4);
        if (Spiral_Mow == 2) analogWrite(ENBPin, PWM_4);

        #if defined(LCD_KEYPAD)
        lcd.print("4");        
        #endif 
        }
      
      // Sprial Ring 5
      if ((Loop_Cycle_Mowing >= End_Spiral_4) && (Loop_Cycle_Mowing < End_Spiral_5)) {
        if (Spiral_Mow == 1) analogWrite(ENAPin, PWM_5);
        if (Spiral_Mow == 2) analogWrite(ENBPin, PWM_5);
        
        #if defined(LCD_KEYPAD)
        lcd.print("5");        
        #endif
         
        }

      // Sprial Ring 6
      if ((Loop_Cycle_Mowing >= End_Spiral_5) && (Loop_Cycle_Mowing < End_Spiral_6)) {
        if (Spiral_Mow == 1) analogWrite(ENAPin, PWM_6);
        if (Spiral_Mow == 2) analogWrite(ENBPin, PWM_6);

        #if defined(LCD_KEYPAD)
        lcd.print("6");  
        #endif       
        }

      // Sprial Ring 7
      if ((Loop_Cycle_Mowing >= End_Spiral_6) && (Loop_Cycle_Mowing < End_Spiral_7)) {
        if (Spiral_Mow == 1) analogWrite(ENAPin, PWM_7);
        if (Spiral_Mow == 2) analogWrite(ENBPin, PWM_7);
        
        #if defined(LCD_KEYPAD)
        lcd.print("7"); 
        #endif
                
        }
        
      // Mower moves away to new position
      if ((Loop_Cycle_Mowing >= End_Spiral_7) && (Loop_Cycle_Mowing < Max_Cycles_Spirals)) {
        if (Spiral_Mow == 1) analogWrite(ENAPin, PWM_MaxSpeed_RH);
        if (Spiral_Mow == 2) analogWrite(ENBPin, PWM_MaxSpeed_LH);
        
        #if defined(LCD_KEYPAD)
        lcd.print("X");     
        #endif
        
        }
      }

}



void Pattern_Mow_Parallel() {
  

  int Parallel_Compass_Assist = 1;         // compass tries to keep the mowed line straight
  int Turning_Compass_Assist  = 0;         // compass assists to turn the mower 90° at each corner - DOESNT WORK YET!!!
       


// if the line length hasnt been achieved then keep on going straight.
  if (Loop_Cycle_Mowing < Line_Length_Cycles)  {
    SetPins_ToGoForwards();

    // USe compass assist to keep the mower in a straight line hopefully parallel to the last 
    if (Parallel_Compass_Assist == 1) {  
        
     if (Loop_Cycle_Mowing < 3) {
        if ((Compass_Heading_Hold_Enabled == 1) && (Compass_Activate == 1))  {         // use the heading hold funtion for Parallel Mowing
           Get_Compass_Reading();                                                      // Gets the latest compass reading
           Heading_Lock = Compass_Heading_Degrees;                                     // saves this compass reading to the heading lock
           Compass_Heading_Locked = 1;                                                 // Turns on the heading lock feature
           Compass_Last = Heading_Lock;
           Motor_Action_Go_Mowing_Speed();
           }
        }
    
     if (Loop_Cycle_Mowing >= 3) {
        if ((Compass_Heading_Hold_Enabled == 1) && (Compass_Activate == 1)) {            // if the Mower is tracking using the compass steer here
          if ( (Loop_Cycle_Mowing % 2) == 0 ) {
          Get_Compass_Reading(); 
          Calculate_Compass_Wheel_Compensation();
          Motor_Action_Dynamic_PWM_Steering();              // Removes the full speed function if the mower is trying to hold to the compass heading.
          Print_LCD_Parallel_Mowing();
          Serial.print(F("C-Lock:ON_"));
          Serial.print("|");
          }
        }
     }
    }
     
    // No use of compass assist
    if (Parallel_Compass_Assist == 0) {
        Motor_Action_Go_Mowing_Speed();
        Serial.println("Compass not activated in the settings");
       }
    }

// if the line length has been achieved then turn around.
  if (Loop_Cycle_Mowing > Line_Length_Cycles) {
    Motor_Action_Stop_Motors();
    delay(300);
    
    // Turn 90°
    if (Leg == 1) {
      SetPins_ToTurnLeft();
      Motor_Action_Go_Full_Speed();
      delay(Turn_90_Delay_LH);
      Get_Compass_Reading(); 
    }
    if (Leg == 2) {
      SetPins_ToTurnRight();
      Motor_Action_Go_Full_Speed();
      delay(Turn_90_Delay_RH); 
      Get_Compass_Reading(); 
      }

    Motor_Action_Stop_Motors();
    delay(300);
    
    // Go to the next line
    SetPins_ToGoForwards();
    Motor_Action_Go_Full_Speed();
    delay(Move_to_next_line_delay);
    Get_Compass_Reading(); 
    Motor_Action_Stop_Motors();
    delay(300);
    
    // Turn Final 90° to face in the next parallel direction just using the timing given on the LH and RH wheels 
    // this will give an innaczrate turn but it runs stabkle
    if (Turning_Compass_Assist  == 0) {
      if (Leg == 1) {
        SetPins_ToTurnLeft();
        Motor_Action_Go_Full_Speed();
        delay(Turn_90_Delay_LH);
        Get_Compass_Reading(); 
        Motor_Action_Stop_Motors();
      }
      if (Leg == 2) {
        SetPins_ToTurnRight();
        Motor_Action_Go_Full_Speed();
        delay(Turn_90_Delay_RH); 
        Get_Compass_Reading(); 
        Motor_Action_Stop_Motors();
        }
      }

    //Adjusts the final direction of the mower using the compass turning feature
    if (Turning_Compass_Assist  == 1) {
      
    
      // Sets the target compass degrees to 180° from the last line
      Compass_Target = Heading_Lock + 180;
      if (Compass_Target > 360) (Compass_Target = Compass_Target - 360);

      
      if (Leg == 1) {
        SetPins_ToTurnLeft();
        Motor_Action_Go_Full_Speed();
        delay(Turn_90_Delay_LH);
        Motor_Action_Stop_Motors();
        Get_Compass_Reading(); 
        delay(500);
        #if defined(LCD_KEYPAD)
        lcd.clear();
        lcd.print("Turn Assist");
        lcd.setCursor(0,1);
        lcd.print("Target");
        lcd.print(Compass_Target);
        delay(1000);
        lcd.clear();
        #endif
        
        Turn_To_Compass_Heading();

        #if defined(LCD_KEYPAD)
        lcd.clear();
        #endif
        
      }
      if (Leg == 2) {
        SetPins_ToTurnRight();
        Motor_Action_Go_Full_Speed();
        delay(Turn_90_Delay_RH); 
        Motor_Action_Stop_Motors();
        Get_Compass_Reading(); 
        delay(500);
        #if defined(LCD_KEYPAD)
        lcd.clear();
        lcd.print("Turn Assist");
        lcd.setCursor(0,1);
        lcd.print("Target");
        lcd.print(Compass_Target);
        delay(1000);
        lcd.clear();
        #endif
        
        Turn_To_Compass_Heading();
        
        #if defined(LCD_KEYPAD)
        lcd.clear();
        #endif
        
        }
      }
    
    Motor_Action_Stop_Motors();
    delay(300);
    SetPins_ToGoForwards();


    Loop_Cycle_Mowing   = 0;          // Reset the Loop counter
    
    #if defined(LCD_KEYPAD)
    lcd.setCursor(13, 1);
    lcd.print("   ");
    #endif
    
    Leg = Leg + 1;                    // Advances the leg so the mower turns in the othe direction next.
    if (Leg > 2) Leg = 1;             // Keeps the leg variable to 1 or 2
     
    }

  
}



void Pattern_Mow_Wire() {

  // Find the wire (unless already found)
  if (Wire_Found == 0) {
    Manouver_Find_Wire_Track();
    Wire_Found = 1;
    }
  // Log the signal strength
  
  // Follow this strength for a number of cycles
  // Turn Left ir Right depending on the direction
  // Follow the wire in the other direction at the new signal strength
  // Turn Left ir Right depending on the direction
  // Follow the wire in the other direction at the new signal strength etc... etc...
  
}

    
