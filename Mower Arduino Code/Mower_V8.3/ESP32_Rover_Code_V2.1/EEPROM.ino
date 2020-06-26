void Activate_EEPROM_Seetings() {

 
   bool Fence_EEPROM = EEPROM.read(502);
   Serial.print("Fence_EEPROM = "); 
   Serial.println(Fence_EEPROM);
   if (Fence_EEPROM == 1)  {
     Fence = EEPROM.read(503); 
     Serial.print("Fence from EEPROM : ");
     Serial.println(Fence);
     Serial.println(" ");
     Serial.print("Active Fence :");
     Serial.println(Fence);
     }
   

  bool WIFI_Enabled_EEPROM = EEPROM.read(504);
  Serial.print("WIFI_Enabled_EEPROM = "); 
  Serial.println(WIFI_Enabled_EEPROM);
  if (WIFI_Enabled_EEPROM == 1) {
    WIFI_Enabled = EEPROM.read(505);  
    Serial.print(F("WIFI Enabled from EEPROM : "));
    if (WIFI_Enabled == 0) Serial.println(F("OFF"));
    if (WIFI_Enabled == 1) Serial.println(F("ON"));
    }

 bool Min_Sats_EEPROM = EEPROM.read(506);
 Serial.print("Min_Sats_EEPROM = "); 
 Serial.println(Min_Sats_EEPROM);
 if (Min_Sats_EEPROM == 1) {
    Min_Sats = EEPROM.read(507);  
    Serial.print(F("Min Sats Enabled from EEPROM : "));
    Serial.println(Min_Sats);
    }
 


delay(2000);
}





void Clear_EEPROM() {
    EEPROM.write(502, 0);
    EEPROM.write(504, 0);
    EEPROM.write(506, 0);
    EEPROM.write(508, 0);
    EEPROM.commit();
}
