// Listens to the serial 3 port if a menu command has been executed.
void Check_TFT_Serial_Input() {
  
  String Serial3_RX_Value  = "";                                     
  int Number_Received;
 
  while (Serial3.available() > 0) {
    char recieved = Serial3.read();
    if ( recieved != '\g' ) {   
      Serial3_RX_Value = Serial3_RX_Value +  (char)recieved;          
      } 
      else if (recieved == '\g') {
        TFT_Menu_Command  = Serial3_RX_Value.toInt();                        
        Serial3_RX_Value  = ""; // changed to string    
        Serial.print("TFT Menu Command: ");
        Serial.print(TFT_Menu_Command );
        Serial.print(" = ");
        Confirm_TX_or_RX_Action();                          // Prints the Menu Selected
        delay(100);

      Confirm_RX();            // Confirms the transmition is received unless 57 (Docked Info)

      if ((Mower_Docked == 1) || (Mower_Parked == 1)) delay(500);
      Send_Data_To_TFT();                                   // Send data to TFT - depends on menu code received
      Receive_Data_From_TFT();                              // Receive Data from TFT - depends on menu code received
      }         
      
    else Serial.print(F("No Data Received|"));
  }

}



void Activate_TFT_Menu() {

        Serial.println();
        Serial.println(F("TFT Menu Activated"));
        Menu_Complete_TFT = false;                                // Menu complete will return to the normal loop
        delay(500);
        Serial.println("waiting for command");
     
     while (Menu_Complete_TFT == false) {                      // holds the program in a loop until a selection has been made in the membrane button menu
          Check_TFT_Serial_Input();
          delay(200);
          if (TFT_Menu_Command == 1) Menu_Complete_TFT = true;  
          }

      }


void Confirm_RX() {      
      // confirms to the TFT that a request for data transfer has been received.
      Serial3.print(TFT_Menu_Command * 3);
      Serial3.println("\h");
      delay(200); 
      Serial.print("Confirmstion Code Sent : ");
      Serial.println(TFT_Menu_Command * 3); 
      }




// Based on the code received this menu confirms the menu item to be used.
void Confirm_TX_or_RX_Action() {

if (TFT_Menu_Command == 1)  Serial.println(F("Main Menu"));
if (TFT_Menu_Command == 2)  Serial.println(F("Quick Start Menu"));
if (TFT_Menu_Command == 3)  Serial.println(F("Exit Dock Menu"));
if (TFT_Menu_Command == 4)  Serial.println(F("Options Menu"));
if (TFT_Menu_Command == 5)  Serial.println(F("Time Menu"));
if (TFT_Menu_Command == 6)  Serial.println(F("Sensors Menu"));
if (TFT_Menu_Command == 7)  Serial.println(F("Motion Menu"));
if (TFT_Menu_Command == 8)  Serial.println(F("Tracking Menu"));
if (TFT_Menu_Command == 9)  Serial.println(F("Navigation Menu"));
if (TFT_Menu_Command == 10) Serial.println(F("Sonar Menu"));
//  Leave 11 Free.
if (TFT_Menu_Command == 12) Serial.println(F("Rain Sensor Menu"));
if (TFT_Menu_Command == 13) Serial.println(F("Stop Menu"));
if (TFT_Menu_Command == 14) Serial.println(F("Wheel Motor Menu"));
if (TFT_Menu_Command == 15) Serial.println(F("Blade Motor Menu"));
if (TFT_Menu_Command == 16) Serial.println(F("Movement Menu"));
if (TFT_Menu_Command == 17) Serial.println(F("Tracking Exit Points"));
if (TFT_Menu_Command == 18) Serial.println(F("Find Wire"));
if (TFT_Menu_Command == 19) Serial.println(F("Track PID"));
if (TFT_Menu_Command == 20) Serial.println(F("Set Alarm 1"));
if (TFT_Menu_Command == 21) Serial.println(F("Set Alarm 2"));
if (TFT_Menu_Command == 22) Serial.println(F("Set Alarm 3"));
if (TFT_Menu_Command == 23) Serial.println(F("Set Time"));
if (TFT_Menu_Command == 24) Serial.println(F("Tip Sensor Menu"));
if (TFT_Menu_Command == 25) Serial.println(F("Pattern Menu"));
if (TFT_Menu_Command == 26) Serial.println(F("Battery Menu"));

if (TFT_Menu_Command == 40) Serial.println(F("Tilt Test"));
if (TFT_Menu_Command == 41) Serial.println(F("Wire Test"));
if (TFT_Menu_Command == 42) Serial.println(F("Relay Test"));
if (TFT_Menu_Command == 43) Serial.println(F("Wheel Test"));
if (TFT_Menu_Command == 44) Serial.println(F("Blade Test"));
if (TFT_Menu_Command == 45) Serial.println(F("Sonar Test"));
if (TFT_Menu_Command == 46) Serial.println(F("Turn Test"));
if (TFT_Menu_Command == 47) Serial.println(F("Volt Amp Test"));
if (TFT_Menu_Command == 48) Serial.println(F("Compass Test"));
if (TFT_Menu_Command == 49) Serial.println(F("Go Home Test"));
if (TFT_Menu_Command == 50) Serial.println(F("Bumper Bar"));
if (TFT_Menu_Command == 55) Serial.println(F("Start-Up Value"));
if (TFT_Menu_Command == 57) Serial.println(F("TX Docked Info"));
if (TFT_Menu_Command == 58) Serial.println(F("Mower Running"));

}
