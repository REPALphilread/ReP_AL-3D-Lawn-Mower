void Activate_EEPROM_Seetings() {

Serial.println(" ");
Serial.println(" ");
Serial.println("Loading Saved Settings from EEPROM");
Serial.println("---------------------------------- ");
 
   bool Fence_EEPROM = EEPROM.read(5);
   Serial.print("Fence_EEPROM = "); 
   Serial.println(Fence_EEPROM);
   if (Fence_EEPROM == 1)  {
     Fence = EEPROM.read(6); 
     Serial.print("Fence Selected : ");
     Serial.println(Fence);
     Serial.println(" ");
     }
   

  bool GPS_WIFI_Enabled_EEPROM = EEPROM.read(1);
  Serial.print("WIFI_Enabled_EEPROM = "); 
  Serial.println(GPS_WIFI_Enabled_EEPROM);
  if (GPS_WIFI_Enabled_EEPROM == 1) {
    GPS_WIFI_Enabled = EEPROM.read(2);  
    Serial.print(F("WIFI Enabled : "));
    if (GPS_WIFI_Enabled == 0) Serial.println(F("OFF"));
    if (GPS_WIFI_Enabled == 1) Serial.println(F("ON"));
         Serial.println(" ");
    }

 bool Simulation_Mode_EEPROM = EEPROM.read(3);
 Serial.print("Simulation Mode = "); 
 Serial.println(Simulation_Mode_EEPROM);
 if (Simulation_Mode_EEPROM == 1) {
    Simulation_Mode = EEPROM.read(4);  
    Serial.print(F("Simulation Mode : "));
    if (Simulation_Mode == 0) Serial.println(F("OFF"));
    if (Simulation_Mode == 1) Serial.println(F("ON"));
    Serial.println(" ");
    }
 
Serial.println("---------------------------------- ");
Serial.println(" ");
Serial.println(" ");
Serial.println(" ");
delay(2000);
}





void Clear_EEPROM() {
    EEPROM.write(502, 0);
    EEPROM.write(504, 0);
    EEPROM.write(506, 0);
    EEPROM.write(508, 0);
    EEPROM.commit();
}
