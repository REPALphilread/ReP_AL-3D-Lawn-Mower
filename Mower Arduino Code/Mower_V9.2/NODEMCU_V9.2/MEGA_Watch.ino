

void Check_MEGA_Status() {
  if (Mower_Running == 1) {
    
    
    
    // Check the readings coming from the MEGA
    
    Check_MEGA = (Check_MEGA + 1);

    Serial.print("Check MEGA:");
    Serial.print(Check_MEGA);

    if (Check_MEGA == 1) {
      Loop_Cycle_Mowing_Check_1 = Loop_Cycle_Mowing;
      val_VoltNow_Check_1 = val_VoltNow;
      }

    if (Check_MEGA == 2) {
      Loop_Cycle_Mowing_Check_2 = Loop_Cycle_Mowing;
      val_VoltNow_Check_2 = val_VoltNow;
      Check_MEGA = 0;
      } 
      
    // Test to see if the values are the same and therefore maybe indicate a hung MEGA..
    if (Loop_Cycle_Mowing_Check_1 == Loop_Cycle_Mowing_Check_2)   Error_Loop = Error_Loop + 1;
    if (val_VoltNow_Check_1 == val_VoltNow_Check_2)               Error_Volt = Error_Volt + 1;

    if (Loop_Cycle_Mowing_Check_1 != Loop_Cycle_Mowing_Check_2)   Error_Loop = 0;
    if (val_VoltNow_Check_1 != val_VoltNow_Check_2)               Error_Volt = 0;

    
    Total_Error = Error_Loop + Error_Volt;
    

    Serial.print("|L1:");
    Serial.print(Loop_Cycle_Mowing_Check_1);
    Serial.print("|L2:");
    Serial.print(Loop_Cycle_Mowing_Check_1);
    Serial.print("|ErrL:");
    Serial.print(Error_Loop);
    
    Serial.print("|V1:");
    Serial.print(val_VoltNow_Check_1);
    Serial.print("|V2:");
    Serial.print(val_VoltNow_Check_2);            
    Serial.print("|ErrV:");
    Serial.print(Error_Volt);
    
    Serial.print("|Tot Error:");
    Serial.print(Total_Error);    


    if (Total_Error < Max_Error) Serial.print("|MEGA OK");   
    if (Total_Error >= Max_Error) {
      Serial.print("|MEGA ERROR");  
      Blynk.virtualWrite(V11, 1023);
      digitalWrite(D5, HIGH); 
      digitalWrite(D5, LOW); 
      delay(1000);
      digitalWrite(D5, HIGH); 
      delay(2000);
      Total_Error = 0;
      Error_Loop = 0;
      Error_Volt = 0;
      
    }
       
  }
}
