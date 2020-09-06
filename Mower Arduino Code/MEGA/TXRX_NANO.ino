void Read_Serial1_Nano() {

  String Serial1_RX_Value  = "";                                              // changed to string

  while (Serial1.available() > 0) {
    
    char recieved = Serial1.read();
    if ( recieved != '\q' && recieved != '\j' && recieved != '\w' && recieved != '\s' ) {   
      Serial1_RX_Value = Serial1_RX_Value +  (char)recieved;          // hack to joining chars in correct way to Serial1_Rx_Value
      } 
      else if (recieved == '\q') {
      RawValueAmp = Serial1_RX_Value.toInt();                                 // if end of value found, set AmpsTX and clear Serial1_Rx_Value temp var Serial1_Rx_Value used for holding value until \q or \j
      Serial1_RX_Value = ""; // changed to string
      } 
      else if (recieved == '\j') {
      RawValueVolt = Serial1_RX_Value.toInt();                                // same as upper but for VoltsTX, 
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\w') {
      Rain_Detected = Serial1_RX_Value.toInt();                               // same as upper but for VoltsTX
      Serial1_RX_Value = "";
      } 
      else if (recieved == '\s') {
      RawWheelAmp = Serial1_RX_Value.toInt();                               // same as upper but for VoltsTX
      Serial1_RX_Value = "";
      } 
    else Serial.print(F("No Data Received|"));
  }

  //Serial.print("WAMpRaw: ");
  //Serial.print(RawWheelAmp);
  //Serial.print(" |");

Calculate_Volt_Amp_Charge();

}
