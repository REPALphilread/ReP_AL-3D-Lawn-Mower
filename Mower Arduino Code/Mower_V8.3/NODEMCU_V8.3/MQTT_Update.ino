void Update_MQTT_With_Status() {
 
    
      if (Charge_Detected == 4 && Charge_old == 1){
          client.publish(CHARGING_TOPIC, "on");        // Charging LED ON
          Charge_old-- ;
      }
      else if (Charge_Detected == 0 && Charge_old == 0)
      {
          client.publish(CHARGING_TOPIC, "off");       // Charging LED OFF
          Charge_old++ ;
      }
      if (Tracking_Wire == 1 && Tracking_old == 1){
          client.publish(TRACKING_TOPIC, "on");        // Tracking LED ON
          Tracking_old-- ;
      }
      else if (Tracking_Wire == 0 && Tracking_old == 0)
      {
          client.publish(TRACKING_TOPIC, "off");       // Tracking LED OFF
          Tracking_old++ ;
      }
      if (Mower_Parked == 1 && Mower_Parked_old == 1){
          client.publish(PARKED_TOPIC, "on");         // Parked LED ON
          Mower_Parked_old-- ;
      }
      else if (Mower_Parked == 0 && Mower_Parked_old == 0)
      {
          client.publish(PARKED_TOPIC, "off");        // Parked LED OFF
          Mower_Parked_old++ ;
      }
      if (Mower_Running_Filter == 2 && Mower_Running_Filter_old == 1){
          client.publish(MOVE_TOPIC, "on");           // Mowing LED ON
          Mower_Running_Filter_old-- ;
      }
      else if (Mower_Running_Filter != 2 && Mower_Running_Filter_old == 0)
      {
          client.publish(MOVE_TOPIC, "off");         // Mowing LED OFF
          Mower_Running_Filter_old++ ;
      }
      if (Mower_Docked_Filter == 2 && Mower_Docked_Filter_old == 1){
          client.publish(DOCKED_TOPIC, "on");           // Docked LED ON
          Mower_Docked_Filter_old-- ;
      }
      else if (Mower_Docked_Filter != 2 && Mower_Docked_Filter_old == 0)
      {
          client.publish(DOCKED_TOPIC, "off");         // Docked LED OFF
          Mower_Docked_Filter_old++ ;
      }


    }




void callback(char* topic, byte* payload, unsigned int length) {
  #ifdef DEBUG
    Serial.println();
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] : ");
  #endif
  String message;
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
    message = message + (char)payload[i];         //Conver *byte to String
  }
  if (message == "1"){
    if (strcmp(topic, QUICKSTART_TOPIC) == 0){               // Quick Start Mowing Function
        StartMower();
        lcd.clear();
        lcd.print(0, 0, "Starting . . ");                    // Print to APP LCD
        delay(100);
         #ifdef DEBUG
          Serial.println();
          Serial.println("Starting . . ");
        #endif
    }
    else if  (strcmp(topic, GODOCK_TOPIC) == 0){            // Go to Docking Station
        Going_Home();
        lcd.clear();
        lcd.print(0, 0, "Docking . . ");                     // Print to APP LCD
        delay(100);
        #ifdef DEBUG
          Serial.println();
          Serial.println("Docking . . ");
        #endif
    }
    else if (strcmp(topic, PAUSESTOP_TOPIC) == 0){           // Pause Mower Function
        Pause_Mower();
        lcd.clear();
        lcd.print(0, 0, "Stopping . . ");                   // Print to APP LCD
        delay(100);
        #ifdef DEBUG
          Serial.println();
          Serial.println("Stopping . . ");
        #endif
    }
    else if  (strcmp(topic, EXITDOCK_TOPIC) == 0){          // Exit Dock Function
        Exit_Dock();
        lcd.clear();
        lcd.print(0, 0, "Exiting . . ");                    // Print to APP LCD
        delay(100);
        #ifdef DEBUG
          Serial.println();
          Serial.println("Exiting . . ");
        #endif
    }
    else if (strcmp(topic, RANDOM_TOPIC) == 0){
        #ifdef DEBUG
          Serial.println();
          Serial.println("Automatic Mode");
        #endif
        Automatic_Mode = 1;
        Manuel_Mode = 0;
        #ifdef DEBUG
          Serial.println("Automatic Mode RANDOM Selected");
        #endif
        transmit_blynk_code = 6;
        Transmit_Blynk_Data_to_Mega();
        Automatic_Mode = 1;
    }
    else if (strcmp(topic, SPIRAL_TOPIC) == 0){
        #ifdef DEBUG
          Serial.println();
          Serial.println("Automatic Spiral");
        #endif
        Automatic_Mode = 2;
        Manuel_Mode = 0;
        #ifdef DEBUG
          Serial.println("");
          Serial.println("Automatic Mode SPIRAL Selected");
        #endif 
        transmit_blynk_code = 11;
        Transmit_Blynk_Data_to_Mega();
        Automatic_Mode = 2;
        Update_MQTT_With_Status();
    }
    else if (strcmp(topic, PARALLEL_TOPIC) == 0){
        #ifdef DEBUG
          Serial.println();
          Serial.println("Automatic Parallel");
        #endif
        Manuel_Mode = 0;
        Automatic_Mode = 1;
        #ifdef DEBUG
          Serial.println("");
          Serial.println("Automatic Mode PARALLEL Selected");
        #endif
        transmit_blynk_code = 12;
        Transmit_Blynk_Data_to_Mega();
        Automatic_Mode = 2;
        Mower_Parked = 0;
        Mower_Docked = 0;
        Mower_Running = 0;
        Update_MQTT_With_Status();
    }
    else if (strcmp(topic, MANUEL_TOPIC) == 0){
        #ifdef DEBUG
          Serial.println();
          Serial.println("Manuel Mode");
        #endif
        Manuel_Mode = 1;
        Automatic_Mode = 0;
        #ifdef DEBUG
          Serial.println("Manuel Mode Selected");
        #endif
        transmit_blynk_code = 5;
        Transmit_Blynk_Data_to_Mega();
        Manuel_Mode = 1;
        Mower_Parked = 0;
        Mower_Docked = 0;
        Mower_Running = 0;
        Update_MQTT_With_Status();
    }
    else if (Manuel_Mode == 1){  
        if  (strcmp(topic, FWD_TOPIC) == 0){                //  Manuel Forward Motion
            transmit_blynk_code = 7;
            #ifdef DEBUG
              Serial.println();
            #endif
            Transmit_Blynk_Data_to_Mega();
        } 
        else if  (strcmp(topic, LEFT_TOPIC) == 0){          // Manuel Left Turn
            transmit_blynk_code = 9;
            #ifdef DEBUG
              Serial.println();
            #endif
            Transmit_Blynk_Data_to_Mega();
        } 
        else if  (strcmp(topic, RIGHT_TOPIC) == 0){         // Manuel Right Turn
            transmit_blynk_code = 10;
            #ifdef DEBUG
              Serial.println();
            #endif
            Transmit_Blynk_Data_to_Mega();
        } 
        else if  (strcmp(topic, REV_TOPIC) == 0){           // Manuel Reverse Motion
            transmit_blynk_code = 8;
            #ifdef DEBUG
              Serial.println();
            #endif
            Transmit_Blynk_Data_to_Mega();
        }  
    }     
  }
}


void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    #ifdef DEBUG
      Serial.print("Attempting MQTT connection...");
    #endif
    // Attempt to connect
    if (client.connect("ESP8266Client", mqtt_username, mqtt_password)) {
      #ifdef DEBUG
        Serial.println("");
        Serial.println("connected");
      #endif
      client.subscribe(PAUSESTOP_TOPIC);                    //Subscribe to pausestop topic
      client.subscribe(EXITDOCK_TOPIC);                     //Subscribe to exit dock topic 
      client.subscribe(QUICKSTART_TOPIC);                   //Subscribe to quick start topic
      client.subscribe(GODOCK_TOPIC);                       //Subscribe to go to dock topic
      //client.subscribe(CHARGING_TOPIC);                     //Subscribe to charging topic
      //client.subscribe(TRACKING_TOPIC);                     //Subscribe to tracking topic 
      //client.subscribe(PARKED_TOPIC);                       //Subscribe to parked topic
      //client.subscribe(MOVE_TOPIC);                         //Subscribe to move topic
      //client.subscribe(DOCKED_TOPIC);                       //Subscribe to docked topic
      client.subscribe(FWD_TOPIC);                          //Subscribe to fwd topic
      client.subscribe(LEFT_TOPIC);                         //Subscribe to left topic
      client.subscribe(RIGHT_TOPIC);                        //Subscribe to right topic
      client.subscribe(REV_TOPIC);                          //Subscribe to rev topic
      client.subscribe(SPIRAL_TOPIC);                       //Subscribe to Auto @ topic
      client.subscribe(RANDOM_TOPIC);                       //Subscribe to Auto || topic
      client.subscribe(PARALLEL_TOPIC);                     //Subscribe to Auto # topic
      client.subscribe(MANUEL_TOPIC);                       //Subscribe to manuel topic
    } else {
      #ifdef DEBUG
        Serial.print("failed, rc=");
        Serial.print(client.state());
        Serial.println(" try again in 5 seconds");
      #endif
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
void Clear_MQTT() {
  #ifdef DEBUG
    Serial.println("Clear MQTT");
  #endif
  client.publish(AVAILABILITY_TOPIC, "online");         // Once connected, publish online to the availability topic
  client.publish(MOVE_TOPIC, "off");                    // Mow LED
  client.publish(DOCKED_TOPIC, "off");                  // Dock LED Off
  client.publish(TRACKING_TOPIC, "off");                // Tracking LED OFF
  client.publish(PARKED_TOPIC, "off");                  // Parked LED OFF
  client.publish(CHARGING_TOPIC, "off");                // Charging LED OFF  
}
