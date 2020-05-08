// Send the various WIFI codes to the MEGA


void Pause_Mower() {
  #ifdef DEBUG
    Serial.println("");
    Serial.println("Pause/Stop");
  #endif
  transmit_blynk_code = 1;
  Transmit_Blynk_Data_to_Mega();
  }

void Going_Home() {
  #ifdef DEBUG
    Serial.println("");
    Serial.println("Go to Dock");
  #endif
  transmit_blynk_code = 2;
  Transmit_Blynk_Data_to_Mega();
  }

void StartMower() {
  #ifdef DEBUG
    Serial.println("");
    Serial.println("Quick Start");
  #endif
  Mower_Parked = 0;
  Update_Blynk_App_With_Status();
  transmit_blynk_code = 3;                    // Code used to let MEGA know what to do
  Transmit_Blynk_Data_to_Mega();              // Transmits that code to the MEGA
  }

void Exit_Dock() {
  #ifdef DEBUG
    Serial.println("");
    Serial.println("Exit Dock");
  #endif
  Mower_Docked = 0;                           // Forces the APP to show docked as false.
                                              // Otherwise the APP needs to wait for the next update round
  Update_Blynk_App_With_Status();
  transmit_blynk_code = 4;
  Transmit_Blynk_Data_to_Mega();
  }


void Set_To_Manuel_Mode() {
    #ifdef DEBUG
      Serial.println("");
      Serial.println("Manuel Mode Selected");
    #endif
    Update_Blynk_App_With_Status();
    transmit_blynk_code = 5;
    Transmit_Blynk_Data_to_Mega();
    Manuel_Mode = 1;
}

void Set_To_Automatic_Mode_Random() {
    #ifdef DEBUG
      Serial.println("");
      Serial.println("Automatic Mode RANDOM Selected");
    #endif
    Update_Blynk_App_With_Status();
    transmit_blynk_code = 6;
    Transmit_Blynk_Data_to_Mega();
    Automatic_Mode = 1;
}

void Set_To_Automatic_Mode_Spiral() {
    #ifdef DEBUG
      Serial.println("");
      Serial.println("Automatic Mode SPIRAL Selected");
    #endif
    Update_Blynk_App_With_Status();
    transmit_blynk_code = 11;
    Transmit_Blynk_Data_to_Mega();
    Automatic_Mode = 2;
}

void Set_To_Automatic_Mode_Parallel() {
    #ifdef DEBUG
      Serial.println("");
      Serial.println("Automatic Mode PARALLEL Selected");
    #endif
    Update_Blynk_App_With_Status();
    transmit_blynk_code = 12;
    Transmit_Blynk_Data_to_Mega();
    Automatic_Mode = 2;
}
