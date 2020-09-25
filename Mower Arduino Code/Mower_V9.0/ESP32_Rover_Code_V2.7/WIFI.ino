


void WIFI_Connect() {
  
  int connect_attempts = 0;
  int max_connect_attempts = 20;
  Serial.println();
  Serial.println("*********************************************");
  Serial.println("Connecting to WIFI");
  Serial.println(ssid);
  Serial.print("WIFI Connection Try:");
  
  while (!Blynk.connected())  {    //!= WL_CONNECTED
      delay(500);
      WiFi.begin(auth, ssid);
      Blynk.begin(auth, ssid, pass);
      connect_attempts = connect_attempts + 1;      
      Serial.print(".");
      if (!Blynk.connected()) {
        delay(2000);
        Set_Mode_ESP32_WIFI();
        }
      
      if (connect_attempts > max_connect_attempts) {
           ESP.restart();
           Serial.println("Restarting ESP");                     // try for less than 4 seconds to connect to WiFi router
           }
      }
  
  if(!Blynk.connected()) {
    //digitalWrite(LED, HIGH);
    Serial.println("");
    Serial.println("ESP32 Did not connect");
    Serial.println("Trying Again to connect . . . . . . ");
    Set_Mode_ESP32_WIFI();
    WIFI_Connect();
    }
  
  else {
    Serial.println("");
    Serial.println("ESP32 and Blynk are Connected. . . . . .");
    Serial.print("http://");
    Serial.print(WiFi.localIP());
    Serial.println("");
    Serial.println("");
    Serial.println("");
    // Setup a function to be called every second
    timer.setInterval(1000L, myTimerEvent);
    }
  }

void Set_Mode_ESP32_WIFI() {
  Serial.print("WIFI Status:");
  Serial.println(WiFi.getMode());
  WiFi.disconnect(true);
  delay(1000);
  WiFi.mode(WIFI_STA);
  delay(1000);
  Serial.print("WIFI Status:");
  Serial.println(WiFi.getMode());
  delay(2000);
  
}
