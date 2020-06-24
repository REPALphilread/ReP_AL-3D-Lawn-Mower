

// Transmit functions to send data to the Main Arduino MEGA on the mower.
//************************************************************************

void Send_Menu_Selected_To_Mower_MEGA() {
    Serial.println(" ");

    // Dont print this message if these menus are selected  
    // 96 Sensors immediate button save
    // 55 Start up value tranmission).
    if ((Menu_Active != 96) || (Menu_Active != 55))  {
          tft.fillScreen(BLACK);
          tft.setCursor(0, 0);  
          tft.setTextSize(3); 
          tft.setTextColor(GREEN, BLACK);           // Text Colour/ Background Colour
          tft.setCursor(50, 50); 
          tft.println("Please Wait..");
          }
    Transmit_Active_Menu_Interupt();
    delay(Delay_Transmit - 200);
        
    //Now check that the Transmition was succesfull.
    Check_TX_Received();
    Serial.print("TX Check:");
    Serial.println(Command_Check);
    if (Command_Check == (Menu_Active*3) ) Serial.println("TX Com Conf");
    else {
      Serial.println("*TX Lost*");
      Send_Menu_Selected_To_Mower_MEGA();
    }
    
}


void Send_Menu_Selected_To_Mower_MEGA_No_RX() {
    Serial.println(" ");
    Transmit_Active_Menu_Interupt();
    delay(Delay_Transmit); 
    }


void Transmit_Active_Menu_Interupt() {
  for (int i=1;  i<=1;  i++) {
    Serial1.print(Menu_Active);
    Serial1.println("\g");
    delay(100);
    }
    Serial.print("TX Active=");
    Serial.println(Menu_Active);  
  }

// this TX sends out more than 1 transmittion so the MEGA has time to detect it.



// Feedback Loop to ensure the transmition is sent.
void Check_TX_Received() {

  String Serial1_RX_Value  = "";                                              
  while (Serial1.available() > 0) {
  
    char recieved = Serial1.read();
    if ( recieved != '\h') {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\h') {
      Command_Check = Serial1_RX_Value.toInt();                                 
      Serial1_RX_Value = ""; // changed to string
      }   
   }
}










// Transmit functions to send data to the GPS NodeMCU on the mower.
//************************************************************************

void Send_Menu_Selected_To_GPS_NodeMCU() {
    Command_Check = 0;
    Serial.println(" ");
    tft.fillScreen(BLACK);
    tft.setCursor(0, 0);  
    tft.setTextSize(2); 
    tft.setTextColor(GREEN, BLACK);           // Text Colour/ Background Colour
    tft.setCursor(50, 50); 
    tft.println("Talking to GPS....");
    Transmit_Active_Menu_Interupt_GPS();
    delay(1500);
        
    //Now check that the Transmition was succesfull.
    Check_TX_Received_GPS();

    
    if (Command_Check == ( Menu_Active * 3) ) Serial.println("TX GPS Conf");
    else {
      Serial.println("*TX GPS Lost*");
      Send_Menu_Selected_To_GPS_NodeMCU();
    }
    
}


void Send_Menu_Selected_To_Mower_GPS_NodeMCU_No_RX() {
    Serial.println(" ");
    Transmit_Active_Menu_Interupt_GPS();
    delay(Delay_Transmit); 
    }


void Transmit_Active_Menu_Interupt_GPS() {
  for (int i=1;  i<=1;  i++) {
    Serial2.print(Menu_Active);
    Serial2.println("\g");
    delay(100);
    }
    Serial.print("TX GPS Menu = ");
    Serial.println(Menu_Active);  
  }

// this TX sends out more than 1 transmittion so the MEGA has time to detect it.


// Feedback Loop to ensure the transmition is sent.
void Check_TX_Received_GPS() {

  Serial.print("Check GPS Conf Code");
  String Serial2_RX_Value  = "";                                              
  while (Serial2.available() > 0) {
  
    char recieved = Serial2.read();
    if ( recieved != '\a') {   
      Serial2_RX_Value = Serial2_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\a') {
      //Command_Check = Serial2.parseInt();  
      Command_Check = Serial2_RX_Value.toInt();                                 
      Serial2_RX_Value = ""; // changed to string
      }   
  }

  delay(1000);
  
}
