

// Transmit functions to send data to the Main Arduino MEGA on the mower.
//************************************************************************

void Send_Menu_Selected_To_Mower_MEGA() {
    Serial.println(" ");
    Transmit_Active_Menu_Interupt();
    delay(Delay_Transmit);
        
    //Now check that the Transmition was succesfull.
    Check_TX_Received();
    Serial.print("TX Check:");
    Serial.println(Command_Check);
    if (Command_Check == (Menu_Active*3) ) Serial.println("TX Command Confirmed");
    else {
      Serial.println("***  TX Lost ***");
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
    Serial.print("TX Menu Active = ");
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
