void Receive_Data_From_TFT()  {

  // Receive the Sonar Values Back again
  if (TFT_Menu_Command == 95) {
      Serial.println("");
      delay(3000);
      Serial.println("Receiving GPS Settings from TFT ...");
      
      String TFT_Serial_RX_Value  = "";                                             
    
      while (TFT_Serial.available() > 0) {
        
        char recieved = TFT_Serial.read();
       if ( recieved != '\a' && recieved != '\b' && recieved != '\c') {   
            TFT_Serial_RX_Value = TFT_Serial_RX_Value +  (char)recieved;          
            } 
            else if (recieved == '\a') {
            GPS_WIFI_Enabled = TFT_Serial_RX_Value.toInt();                                 
            TFT_Serial_RX_Value = ""; // changed to string
            }
            else if (recieved == '\b') {
            Simulation_Mode = TFT_Serial_RX_Value.toInt();                                 
            TFT_Serial_RX_Value = ""; // changed to string
            }        
            else if (recieved == '\c') {
            Fence = TFT_Serial_RX_Value.toInt();                                 
            TFT_Serial_RX_Value = ""; // changed to string
            }  
      else Serial.print(F("No Data Received|"));
      }

      Serial.print(F("GPS_WIFI_Enabled = "));
      if (GPS_WIFI_Enabled == 1) Serial.println("Enabled");
      if (GPS_WIFI_Enabled == 0) Serial.println("Disabled");
      Serial.print(F("Simulation Mode = "));
      if (Simulation_Mode == 1) Serial.println("Enabled");
      if (Simulation_Mode == 0) Serial.println("Disabled");
      Serial.print(F("Fence = "));
      Serial.println(Fence);
      Serial.println(F(" "));

      // ESP 32 EEPROM Write
      EEPROM.write(1, 1);
      EEPROM.commit();
      EEPROM.write(2, GPS_WIFI_Enabled);
      EEPROM.commit();
      EEPROM.write(3, 1);
      EEPROM.commit();
      EEPROM.write(4, Simulation_Mode);
      EEPROM.commit();
      EEPROM.write(5, 1);
      EEPROM.commit();
      EEPROM.write(6, Fence);
      EEPROM.commit();
      Serial.println("Saved to ESP32 EEPROM");    
      Serial.println(" ");

      Serial.print("Activating Settings");
      delay(2000);
      
      if (GPS_WIFI_Enabled == 1) WIFI_Connect();
      Blynk.virtualWrite(V1, "clr");
      First_Plot = 1;
      Activate_GPS_Fence();
      }

}
