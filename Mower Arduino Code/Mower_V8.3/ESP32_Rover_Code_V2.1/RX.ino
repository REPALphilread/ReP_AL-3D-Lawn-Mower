void Receive_Data_From_TFT()  {

  // Receive the Sonar Values Back again
  if (TFT_Menu_Command == 910) {
      Serial.println(F("Receiving GPS Settings from TFT ..."));
      delay(1100);
      
      String TFT_Serial_RX_Value  = "";                                             
    
      while (TFT_Serial.available() > 0) {
        
        char recieved = TFT_Serial.read();
        if ( recieved != '\a') {   
          TFT_Serial_RX_Value = TFT_Serial_RX_Value +  (char)recieved;          
          } 
          else if (recieved == '\a') {
          Fence = TFT_Serial_RX_Value.toInt();                                 
          TFT_Serial_RX_Value = ""; // changed to string
          } 
      else Serial.print(F("No Data Received|"));
      }

      delay(1000);

      TFT_Serial_RX_Value  = "";
      while (TFT_Serial.available() > 0) {
        
        char recieved = TFT_Serial.read();
        if ( recieved != '\b') {   
          TFT_Serial_RX_Value = TFT_Serial_RX_Value +  (char)recieved;          
          } 
          else if (recieved == '\b') {
          Min_Sats = TFT_Serial_RX_Value.toInt();                                 
          TFT_Serial_RX_Value = ""; // changed to string
          } 
      else Serial.print(F("No Data Received|"));
      }

      Serial.print("Fence Activated = ");
      Serial.println(Fence);
      Serial.print("Min Sats = ");
      Serial.println(Min_Sats);

      //EEPROM.write(37, 1);
      //EEPROM.write(38, Sonar_1_Activate);
      //EEPROM.write(39, 1);
      //EEPROM.write(40, Sonar_2_Activate);
      //EEPROM.write(41, 1);
      //EEPROM.write(42, Sonar_3_Activate);
      //EEPROM.write(65, 1);
      //EEPROM.write(66, maxdistancesonar); 
      //EEPROM.write(63, 1);
      //EEPROM.write(64, Max_Sonar_Hit);         
      Serial.println("Saved to EEPROM");    
      Serial.println(" ");
      }

}
