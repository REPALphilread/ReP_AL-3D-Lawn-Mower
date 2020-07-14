// Listens to the serial 3 port if a menu command has been executed.
void Check_TFT_Serial_Input() {
  
  String TFT_Serial_RX_Value  = "";                                     
  while (TFT_Serial.available() > 0) {
    
    char recieved = TFT_Serial.read();
    if ( recieved != '\g' ) {   
      TFT_Serial_RX_Value = TFT_Serial_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\g') {
        TFT_Menu_Command  = TFT_Serial_RX_Value.toInt();                        
        TFT_Serial_RX_Value  = ""; // changed to string    
        if (TFT_Menu_Command != 17) {                       // Dont print this when entering a GPS Fence.
            if (TFT_Menu_Command != 18) {            
            Serial.print("TFT Menu Command: ");
            Serial.print(TFT_Menu_Command );
            Serial.print(" = ");
            }
        }
        Confirm_TX_or_RX_Action();                            // Prints the Menu Selected
        delay(100);
        Confirm_RX();                                         // Confirms the transmition is received
        Send_Data_To_TFT();                                   // Send data to TFT - depends on menu code received
        Receive_Data_From_TFT();                              // Receive Data from TFT - depends on menu code received
        }         
      
    else Serial.print(F("No Data Received|"));
  }

}



void Activate_TFT_Menu() {

    if (TFT_Menu_Command != 17) {      
        if (TFT_Menu_Command != 18) {
        Serial.println();
        Serial.println(F("TFT Menu Activated"));
        Menu_Complete_TFT = false;                                // Menu complete will return to the normal loop
        delay(500);
        Serial.println("waiting for command");
        }
        }
     
     while (Menu_Complete_TFT == false) {                      // holds the program in a loop until a selection has been made in the membrane button menu
          Check_TFT_Serial_Input();
          delay(200);
          if (TFT_Menu_Command == 95) {
            Menu_Complete_TFT = true;  
            Serial.println("Menu Completed");
            }   
          }

      }


void Confirm_RX() {      
      // confirms to the TFT that a request for data transfer has been received.
      
      RXCode = TFT_Menu_Command * 3 ;      
      TFT_Serial.print(RXCode);
      TFT_Serial.println("\j");     
      delay(200);
      TFT_Serial.flush();
      if (TFT_Menu_Command != 17) {   
          Serial.print("Confirmstion Code Sent : ");
          Serial.println(TFT_Menu_Command * 3);  
          }
      }




// Based on the code received this menu confirms the menu item to be used.
void Confirm_TX_or_RX_Action() {

if (TFT_Menu_Command == 15)  Serial.println(F("GPS Settings"));
if (TFT_Menu_Command == 16)  Serial.println(F("Create GPS Fence "));

}
