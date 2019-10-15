// All the Transmitted informtion functions


void Transmit_Blynk_Data_to_Mega() {
    i = transmit_blynk_code + 10;           // Transmits the code and adds 10 to the number
      NodeMCU.print(i);
      NodeMCU.println("\p");
      delay(30);
      Serial.print("TX_Code_to_MEGA:");
      Serial.print(i);
      Serial.print("");
      delay(20);
      }
