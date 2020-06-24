void Connect_ESP32_to_WIFI() {
  Serial.println();
  Serial.println("Connecting to WIFI");
  Serial.println(ssid);
  digitalWrite(LED, HIGH);                          // Turn off LED Light
  WIFI_Connect();                                   // Connect to the WIFI
  pinMode(LED, OUTPUT);


}



void WIFI_Connect() {
  
  int mytimeout = millis() / 1000;
  Serial.println();
  Serial.println("*********************************************");
  Blynk.begin(auth, ssid, pass);
  
  
  while (Blynk.connected() != WL_CONNECTED) {
    delay(500);
      if((millis() / 1000) > mytimeout + 3){                      // try for less than 4 seconds to connect to WiFi router
      break;
    }
  }
  
  if(!Blynk.connected()) {
    digitalWrite(LED, HIGH);
    Serial.println("NODEMCU Disconnected");
    Serial.println("Reconnecting . . . . . . ");
    WIFI_Connect();

    }
  else {
    digitalWrite(LED, LOW);
    Serial.println("Connected. . . . . .");
    // Setup a function to be called every second
    timer.setInterval(1000L, myTimerEvent);
    }
  }
