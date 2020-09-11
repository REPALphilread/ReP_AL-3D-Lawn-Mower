
// Creates a GPs fence either in Serial mode or an EEPROM mode.
//
// Serial mode prints the coordinates in the Serial monitor which can then be copied and pasted into the Arduino Code to 
// create a permanent fence which can be slelected
//
// EEPROM mode saves the coordinates pulled from the GPS to EEPROM. This has a limitation of 50 GPS points.


void Create_GPS_Fence() {

Serial.println("");
Serial.println("");
Serial.println("");
Serial.println("");
Serial.println("");
Serial.println("");
Serial.println("");
Serial.println("");
Serial.println("");
Serial.println("");
Serial.println(F("*************************************"));
Serial.println(F("    CREATE GPS FENCE          "));
Serial.println(F("*************************************"));

Fence_Type_Create = 1;          // Resets the option to a Serial Fence.

if ( Fence_Type_Create == 1 ) Serial.print("SERIAL Fence");
if ( Fence_Type_Create == 2 ) Serial.print("EEPROM");
delay(1000);

bool Menu_Complete_Fence = false;
int Set = 1;

Serial.println(" ");
Serial.println(" ");
if (Fence_Type_Create == 1) Serial.println("Copy this code and coordinates to the Arduino IDE sketch to create a Fixed Fence");
if (Fence_Type_Create == 1) Serial.println("Paste it into the GPS_Fence_Coordinates Tab in the sketch ESP32_Rover_Code_VX.X");
if (Fence_Type_Create == 1) Serial.println("Add a free fence number (Fence =) and GPSMAX = which is given at the end of the fence input");
if (Fence_Type_Create == 2) Serial.println("            EEPROM FENCE BEING CREATED");
Serial.println("------------------------------------------------------------------------- ");
Serial.println(" ");
Serial.println(" ");     
}
  

// Prints the captured coordinates to te serial monitor which can then be copied and pasted to create fence data.
void Capture_Fence_Coordinates() {

  Read_GPS_Data();
  GPSY6[Fence_Point - 1] = gps.location.lat();
  delay(100);
  GPSX6[Fence_Point - 1] = gps.location.lng();
  delay(100);

  Serial.print("GPSY[");
  Serial.print(Fence_Point - 1);
  Serial.print("] = ");
  Serial.print(GPSY6[Fence_Point - 1],8);
  Serial.print(";  ");
  
  Serial.print("GPSX[");
  Serial.print(Fence_Point - 1);
  Serial.print("] = ");
  Serial.print(GPSX6[Fence_Point - 1],8);
  Serial.print(";  ");

  Serial.print("Boundary [");
  Serial.print(Fence_Point - 1);
  Serial.print("] = 1;");

  Serial.print("      //");
  Serial.print("  Sattelites:");
  Serial.print(gps.satellites.value());
  Serial.print("  FIX Type:");
  FIXED = strtoul( FIX.value(), NULL, 10 );   // changes the CHAR Value to an Int value
  if (FIXED == 0) Serial.println("0/5");
  if (FIXED == 1) Serial.println("1/5");
  if (FIXED == 2) Serial.println("2/5");
  if (FIXED == 4) Serial.println("3/5");
  if (FIXED == 5) Serial.println("4/5");
  if (FIXED == 6) Serial.println("5/5");

if (GPS_WIFI_Enabled == true) Blynk_Map_Update();

}


void Scroll_Boundary_List() {
  
  int Cursor_Position = 0;

for (int i = (Start_Fence); i <= (End_Fence); i++) {

  Boundary_EEPROM[i] = EEPROM.read( (i + 450) );

  if (Boundary_EEPROM[i] == 111) Boundary_EEPROM[i] = 1;  
  if (Boundary_EEPROM[i] == 101) Boundary_EEPROM[i] = 1;
  if (Boundary_EEPROM[i] ==  11) Boundary_EEPROM[i] = 1;
  if (Boundary_EEPROM[i] ==   1) Boundary_EEPROM[i] = 1;

  if (Boundary_EEPROM[i] == 112) Boundary_EEPROM[i] = 2;
  if (Boundary_EEPROM[i] == 102) Boundary_EEPROM[i] = 2;
  if (Boundary_EEPROM[i] ==  12) Boundary_EEPROM[i] = 2;
  if (Boundary_EEPROM[i] ==   2) Boundary_EEPROM[i] = 2;

  Serial.print("Boundary[");
  Serial.print(i-1);
  Serial.print("]=");
  Serial.println(Boundary_EEPROM[i]);
  Cursor_Position = Cursor_Position + 1;
 }
  
}


void Edit_Boundary_Condition() {

int Fence_Origin;
int Fence_Delta;
int Fence_New;
 
  Serial.println("Edit Fence Boundary Conditions");
  Serial.println("------------------------------");

  int Fence_No = EEPROM.read( (Start_Fence + 450) );
  Serial.print("Start_Fence = ");
  Serial.println(Start_Fence);  
  Serial.print("Fence_No = ");
  Serial.println(Fence_No);
  
  // Decycpher the Boundary code of Ypos/neg Xpos/neg and Boundary type 1 or 2 
  if (Fence_No == 111) {
    Serial.print ("Y-ve | X-ve | B:1");
    Fence_Origin = 1;
    }
  if (Fence_No == 101) {
    Serial.print ("Y-ve | X+ve | B:1");
    Fence_Origin = 1;
    }
  if (Fence_No ==  11) {
    Serial.print ("Y+ve | X-ve | B:1");
    Fence_Origin = 1;
    }
  if (Fence_No ==   1) {
    Serial.print ("Y+ve | X+ve | B:1");
    Fence_Origin = 1;
    }

  if (Fence_No == 112) {
    Serial.print ("Y-ve | X-ve | B:2");
    Fence_Origin = 2;
  }
  if (Fence_No == 102) {
    Serial.print ("Y-ve | X+ve | B:2");
    Fence_Origin = 2;
  }
  if (Fence_No == 12) {
    Serial.print ("Y+ve | X-ve | B:2");
    Fence_Origin = 2;
  }
  if (Fence_No ==   2) {
    Serial.print ("Y+ve | X+ve | B:2");
    Fence_Origin = 2;
  }

  Serial.print("Boundary[");
  Serial.print(Start_Fence-1);
  Serial.print("]=");
  Serial.print(Fence_Origin);
  Serial.print("<");

  
  Menu_Complete_Fence_Edit = false;
  delay(100);

  Fence_New = Fence_Origin;
  
  while (Menu_Complete_Fence_Edit == false) {
          //Read_Membrane_Keys();
          delay(100);
          
            //Enter Code Here to Cycle until stop key is pressed.
            if(!Start_Key_X){
                if ((Fence_No == 111) && (Fence_New == 1)) Fence_No = 111;
                if ((Fence_No == 111) && (Fence_New == 2)) Fence_No = 112;
                if ((Fence_No == 112) && (Fence_New == 1)) Fence_No = 111;
                if ((Fence_No == 112) && (Fence_New == 2)) Fence_No = 112;

                if ((Fence_No == 101) && (Fence_New == 1)) Fence_No = 101;
                if ((Fence_No == 101) && (Fence_New == 2)) Fence_No = 102;
                if ((Fence_No == 102) && (Fence_New == 1)) Fence_No = 101;
                if ((Fence_No == 102) && (Fence_New == 2)) Fence_No = 102; 

                if ((Fence_No == 11) && (Fence_New == 1)) Fence_No = 11;
                if ((Fence_No == 11) && (Fence_New == 2)) Fence_No = 12;
                if ((Fence_No == 12) && (Fence_New == 1)) Fence_No = 11;
                if ((Fence_No == 12) && (Fence_New == 2)) Fence_No = 12;                               


                if ((Fence_No == 1) && (Fence_New == 1)) Fence_No = 1;
                if ((Fence_No == 1) && (Fence_New == 2)) Fence_No = 2;
                if ((Fence_No == 2) && (Fence_New == 1)) Fence_No = 1;
                if ((Fence_No == 2) && (Fence_New == 2)) Fence_No = 2; 
                
                Serial.print("Boundary Updated to:");
                Serial.println(Fence_No);
                EEPROM.write( (Start_Fence + 450)  , Fence_No );    // Boundary Condition Space 451+
                EEPROM.commit();  
                Menu_Complete_Fence_Edit = true;

                Serial.print("Boundary SAVED");
                Serial.println("Boundary Condition Updated");
                delay(1000);
                }
            if (!Plus_Key_X) {
                Fence_New = Fence_New + 1;
                if (Fence_New > 2) Fence_New = 2;
                /*lcd.setCursor(0,3);
                lcd.print("Boundary[");
                lcd.print(Start_Fence-1);
                lcd.print("]=");
                lcd.print(Fence_New);
                lcd.print("<");
                */

                }

            if (!Minus_Key_X) {
                Fence_New = Fence_New - 1;
                if (Fence_New < 1) Fence_New = 1;
                /*lcd.setCursor(0,3);
                lcd.print("Boundary[");
                lcd.print(Start_Fence-1);
                lcd.print("]=");
                lcd.print(Fence_New);
                lcd.print("<");
                */
                }
                
                
           if(!Stop_Key_X){

               }    
     }
  }
