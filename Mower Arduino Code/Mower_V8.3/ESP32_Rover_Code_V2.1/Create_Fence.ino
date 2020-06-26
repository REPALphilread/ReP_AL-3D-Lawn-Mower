
// Creates a GPs fence either in Serial mode or an EEPROM mode.
//
// Serial mode prints the coordinates in the Serial monitor which can then be copied and pasted into the Arduino Code to 
// create a permanent fence which can be slelected
//
// EEPROM mode saves the coordinates pulled from the GPS to EEPROM. This has a limitation of 50 GPS points.


void Create_GPS_Fence() {

Serial.println(F("*************************************"));
Serial.println(F("    CREATE GPS FENCE          "));
Serial.println(F("*************************************"));

Fence_Type_Create = 1;          // Resets the option to a Serial Fence.

if ( Fence_Type_Create == 1 ) Serial.print("SERIAL");
if ( Fence_Type_Create == 2 ) Serial.print("EEPROM");
delay(1000);

bool Menu_Complete_Fence = false;
int Set = 1;

Serial.println(" ");
Serial.println(" ");
if (Fence_Type_Create == 1) Serial.println("Copy these coordinates to the Arduino IDE sketch to create a Fixed Fence");
if (Fence_Type_Create == 2) Serial.println("            EEPROM FENCE BEING CREATED");
Serial.println("------------------------------------------------------------------------- ");
Serial.println(" ");
Serial.println(" ");
Start_Fence_Input();      
}
  
 



void Start_Fence_Input() {
  /*Fence_Point = 1;
  //lcd.clear();
  delay(1000);
  int Set = 1;
  Menu_Complete_Fence = false;
  Read_GPS_Data();
  Print_LCD_GPS_Data_Create_Fence();
  lcd.setCursor(0,4);
  lcd.print(">Save Point:");
  lcd.print(Fence_Point - 1);
  lcd.setCursor(0,5);
  lcd.print(" Back");
  lcd.print("   End");
  
  while (Menu_Complete_Fence == false) {
    
    if (Set < 3) {
      Read_GPS_Data();
      Y_GPS = gps.location.lat();    
      X_GPS = gps.location.lng();
      Calculate_GPS_Accuracy();
      Print_LCD_GPS_Data_Create_Fence();
      }
    Read_Membrane_Keys();
    
    delay(100);
    
    //Enter Code Here to Cycle until stop key is pressed.
       if(!Start_Key_X){
            
            // If the End menu option is selected
            if (Set == 3) {
              if (Fence_Type_Create == 2) {
                EEPROM.write(501, Fence_Point - 2);                 // - 2 while the counter is always 1 ahead plus 1 less array point as 0 = 1.
                EEPROM.commit();
                }
              
              delay(200);
              Serial.println(" ");
              Serial.print("GPSMAX =");
              Serial.println(Fence_Point - 2);
              Serial.println(" ");
              Serial.println(" ");
              Serial.println("************ INPUT ENDED  *************** ");
              Serial.println(" ");
              Serial.println(" ");
              lcd.clear();
              lcd.print("End of Input");
              delay(2000);
              Menu_Complete_Fence = true; 
              Serial.println(" ");
              if (Fence_Type_Create == 2) Serial.println("************ CONFIRMING EEPROM FENCE DATA  *************** ");
              if (Fence_Type_Create == 2) Print_EEPROM_Fence_To_Serial();
              Serial.println(" ");
              Serial.println(" ");
              Serial.println(" ");
              Serial.println(" ");
              delay(3000);
              }            
            
            // If the start button is pressed the GPs coordinates are cpatured.
            if (Set == 1) {

                //Rules if its an EEPROM Fence = Max 45 point
                if (Fence_Type_Create == 2) {
                     if (Fence_Point <= 45) {
                         LCD_Print_Captured();
                         Capture_Fence_Coordinates();
                         Fence_Point = Fence_Point + 1;   
                     }
                if (Fence_Point > 45) {
                     Fence_Point = 51;                // 1 more than actual as its taken away at the end.
                     Serial.println("EEPROM FULL!!");
                     lcd.clear();
                     lcd.print("EEPROM FULL!!");
                     delay(2000);
                     }
              }

              //Rules if its a Serial Fence = unlimited points
              if (Fence_Type_Create == 1) {
                 LCD_Print_Captured();
                 Capture_Fence_Coordinates();
                 Fence_Point = Fence_Point + 1;  
                 }

              lcd.setCursor(0,4);
              lcd.print(">Save Point:");
              lcd.print(Fence_Point - 1);
              lcd.setCursor(0,5);
              lcd.print(" Back");
              lcd.print("   End");
            }      


            // If start key is pressed while back is selected Set = 2
            if (Set == 2) {
              Fence_Point = Fence_Point - 1 ;
              lcd.clear();
              lcd.print("Last Point");
              lcd.setCursor(0,1);
              lcd.print(Fence_Point - 1);
              lcd.setCursor(0,2);
              lcd.print("DELETED");
              delay(2000);
              lcd.clear();
              lcd.setCursor(0,4);
              lcd.print(">Save Point:");
              lcd.print(Fence_Point - 1);
              lcd.setCursor(0,5);
              lcd.print(" Back");
              lcd.print("   End");
              Set = 1;
            }
            
 
       }

       if (!Plus_Key_X) {
         
         if (Set == 2) {
              lcd.setCursor(0,4);
              lcd.print(">Save Point:");
              lcd.setCursor(0,5);
              lcd.print(" Back");
              lcd.print("   End");
              Set = 1;
              }

          if (Set == 3) {
              lcd.setCursor(0,4);
              lcd.print(" Save Point:");
              lcd.print(Fence_Point - 1);
              lcd.setCursor(0,5);
              lcd.print(">Back");
              lcd.print("   End");
              Set = 2;
              }         
       }
       
       if (!Minus_Key_X) {
         if (Set == 3) {
           
         }
         if (Set == 2) {
              lcd.setCursor(0,4);
              lcd.print(" Save Point:");
              lcd.print(Fence_Point - 1);
              lcd.setCursor(0,5);
              lcd.print(" Back");
              lcd.print("  >End");
              Set = 3;
       }
         
         if (Set == 1) {
              lcd.setCursor(0,4);
              lcd.print(" Save Point:");
              lcd.print(Fence_Point - 1);
              lcd.setCursor(0,5);
              lcd.print(">Back");
              lcd.print("   End");
              Set = 2;
       }
       }
       if(!Stop_Key_X){
          Serial.println(F("Stop key is pressed"));
          Menu_Complete_Fence = true;
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Menu Cancelled");
          delay(1000);
          lcd.clear();          
          Menu_Mode_Selection = 0;
          }
     }
  
  */
  }

// Prints the captured coordinates to te serial monitor which can then be copied and pasted to create fence data.
void Capture_Fence_Coordinates() {

  GPSY6[Fence_Point - 1] = gps.location.lat();
  delay(100);
  GPSX6[Fence_Point - 1] = gps.location.lng();

  // Test for Negative Y or X GPS Coordinates (remove //)
  //GPSY6[Fence_Point - 1] = GPSY6[Fence_Point - 1] * -1;
  //GPSX6[Fence_Point - 1] = GPSX6[Fence_Point - 1] * -1;

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

if ( Fence_Type_Create == 2) Write_to_EEPROM_GPS_Coordinates();
if (WIFI_Enabled == true) Blynk_Map_Update();

}




//  The GPS cooridnates are 8 decimal place numbers
//  EEPROM can store number from 0 - 256.
//  This means the GPS Cooridnates need to be broken down into parts to store in consecutive EEPROM storage slots
//  and are then built back together again to produce the GPS number out of EEPROM memory.
 
void   Write_to_EEPROM_GPS_Coordinates()  {
  
  bool Show_Calculations = 0;  // make = 1 if you want to check the GPS Coordinates storage method is working in the Serial monitor
  int YNeg = 0;
  int XNeg = 0;
  //Save GPS Y Coordinates to EEPROM
  


  // EEPROM cant sotre negative numers so this routine takes out the negative number and stores it 
  // in the boundary condition so the negative number can be rebuilt into the GPS coordinate later.
  
  // If the GPS coordinate is a negative number then YNeg or XNeg are 1 for that Array point
  if ( (GPSY6[Fence_Point - 1] * -1 ) > 0) {
    if (Show_Calculations == 1) Serial.println("Negative Y Number Detected");
    YNeg = 1;
    GPSY6[Fence_Point - 1] = (GPSY6[Fence_Point - 1] * -1) ;
  }
  if ( (GPSX6[Fence_Point - 1] * -1 ) > 0)  {
    if (Show_Calculations == 1) Serial.println("Negative X Number Detected");
    XNeg = 1;
    GPSX6[Fence_Point - 1] = (GPSX6[Fence_Point - 1] * -1) ;  
  }
  

  // Part 1 = e.g.  47.00000000
  // First Write the number to EEPROM (only the whole part of the number)
  EEPROM.write( ((Fence_Point*10) - 9) , ((GPSY6[Fence_Point - 1] )));    // Write Y Coordinate Space 1
  EEPROM.commit(); 
  double Part1 = EEPROM.read((Fence_Point * 10) - 9);
  if (Show_Calculations == 1) Serial.print("Y Part 1: ");
  if (Show_Calculations == 1) Serial.println(Part1, 8);
 
  // Part 2 = e.g. 00.12345678
  // Take the double number with all decimal places and minus the whole part of the number away
  double Part2 = GPSY6[Fence_Point - 1] - Part1 ;
    
  // Multiply out the decimal places to make it a whole number for saving to EEPROMLong.
  Part2 = Part2 * 100000000; 
  if (Show_Calculations == 1) Serial.print("Y Part 2 : ");
  if (Show_Calculations == 1) Serial.println(Part2, 8);
  
  // Save the decimal places (now as a whole number to EEPROMLng)
  EEPROMWritelong( ((Fence_Point*10) - 8) , Part2);    // Write Y Coordinate 4 EEPROM Spaces 2-5
  EEPROM.commit();   

  Part2 = EEPROMReadlong((Fence_Point*10) - 8);
  if (Show_Calculations == 1) Serial.print("Y Part 2 Saved: ");
  if (Show_Calculations == 1) Serial.println(Part2, 8);
  
  Part2 = Part2 / 100000000;
  if (Show_Calculations == 1) Serial.print("Y Part 2 Saved /100000000: ");
  if (Show_Calculations == 1) Serial.println(Part2, 8);
  
  
  
  
  //Save GPS X Coordinates to EEPROM

  // Part 1 = e.g.  47.00000000
  // First Write the number to EEPROM (only the whole part of the number)
  EEPROM.write( ((Fence_Point*10) - 4) , ((GPSX6[Fence_Point - 1] )));    // Write X Coordinate Space 1
  EEPROM.commit(); 
  Part1 = EEPROM.read((Fence_Point * 10) - 4);
  if (Show_Calculations == 1) Serial.print("X Part 1: ");
  if (Show_Calculations == 1) Serial.println(Part1, 8);
 
  // Part 2 = e.g. 00.12345678
  // Take the double number with all decimal places and minus the whole part of the number away
  Part2 = GPSX6[Fence_Point - 1] - Part1 ;
    
  // Multiply out the decimal places to make it a whole number for saving to EEPROMLong.
  Part2 = Part2 * 100000000; 
  if (Show_Calculations == 1) Serial.print("X Part 2 : ");
  if (Show_Calculations == 1) Serial.println(Part2, 8);
  
  // Save the decimal places (now as a whole number to EEPROMLng)
  EEPROMWritelong( ((Fence_Point*10) - 3) , Part2);    // Write Y Coordinate 4 EEPROM Spaces 2-5
  EEPROM.commit();   

  Part2 = EEPROMReadlong((Fence_Point*10) - 3);
  if (Show_Calculations == 1) Serial.print("X Part 2 Saved: ");
  if (Show_Calculations == 1) Serial.println(Part2, 8);
  
  Part2 = Part2 / 100000000;
  if (Show_Calculations == 1) Serial.print("X Part 2 Saved /100000000: ");
  if (Show_Calculations == 1) Serial.println(Part2, 8);


  // Save Boundary Condition and negative GPS point data
  int Boundary_Condition;
  if (YNeg == 1 && XNeg ==1)  Boundary_Condition = 111;
  if (YNeg == 1 && XNeg ==0)  Boundary_Condition = 101;
  if (YNeg == 0 && XNeg ==1)  Boundary_Condition = 11;
  if (YNeg == 0 && XNeg ==0)  Boundary_Condition = 1; 
  if (Show_Calculations == 1) Serial.print("Boundary_Condition : ");
  if (Show_Calculations == 1) Serial.println(Boundary_Condition);
  
  EEPROM.write( (Fence_Point + 450)  , Boundary_Condition );                                                   // Boundary Condition Space 451+
  EEPROM.commit();  

  if (Show_Calculations == 1)  Serial.println(" ");
  
  }


long EEPROMReadlong(long address) {
  long four  = EEPROM.read(address);
  long three = EEPROM.read(address + 1);
  long two   = EEPROM.read(address + 2);
  long one   = EEPROM.read(address + 3);
 
  return ((four << 0) & 0xFF) + ((three << 8) & 0xFFFF) + ((two << 16) & 0xFFFFFF) + ((one << 24) & 0xFFFFFFFF);
}

void EEPROMWritelong(int address, long value) {
  byte four  = (value & 0xFF);
  byte three = ((value >> 8) & 0xFF);
  byte two   = ((value >> 16) & 0xFF);
  byte one   = ((value >> 24) & 0xFF);
 
  EEPROM.write(address, four);
  EEPROM.write(address + 1, three);
  EEPROM.write(address + 2, two);
  EEPROM.write(address + 3, one);
}




// Checks that the GPS Coordinates (negative and positive) and Boundary Condition can be
// Rebuilt out if of values stored in the 10 EEPROM slots

void   Print_EEPROM_Fence_To_Serial()  {

  Serial.println(" ");
  Serial.println("EEPROM GPS Print Out");
  Serial.println(" ");

  bool Show_Calculations = 0;               // make = 1 if you want to check the GPS Coordinates storage method is working in the Serial monitor
  GPSMAX2 = EEPROM.read(501);          // USe a different GPSMAX2 so not to poluute the GPSMAX variable being used.

  for (int i = 1; i <= ( GPSMAX2 + 1 ); i++) {

  int YNeg;
  int XNeg;
  int Boundary_Calc;
  int Negative_Code;
  

  // Look for X and Y GPS negative Coordinates based on the boundary number
  Negative_Code = EEPROM.read( (i + 450) ); 
  if (Show_Calculations == 1) Serial.print("Negative Code: ");
  if (Show_Calculations == 1) Serial.println(Negative_Code);

  //Both X and Y Coordinates are originally negative
  if (Negative_Code == 111) {
    YNeg = -1;
    XNeg = -1;
    Boundary_Calc = 1;
    if (Show_Calculations == 1) Serial.println("Y Negative   X Negative");
  }

  if (Negative_Code == 112) {
    YNeg = -1;
    XNeg = -1;
    Boundary_Calc = 2;
    if (Show_Calculations == 1) Serial.println("Y Negative   X Negative");
  }

  if (Negative_Code == 101) {
    YNeg = -1;
    XNeg =  1;
    Boundary_Calc = 1;
    if (Show_Calculations == 1) Serial.println("Y Negative   X Positive");
  }

  if (Negative_Code == 102) {
    YNeg = -1;
    XNeg =  1;
    Boundary_Calc = 2;
    if (Show_Calculations == 1) Serial.println("Y Negative   X Positive");
  }

  if (Negative_Code == 11) {
    YNeg =  1;
    XNeg = -1;
    Boundary_Calc = 1;
    if (Show_Calculations == 1) Serial.println("Y Positive   X Negative");
  }

  if (Negative_Code == 12) {
    YNeg =  1;
    XNeg = -1;
    Boundary_Calc = 2;
    if (Show_Calculations == 1) Serial.println("Y Positive   X Negative");
  }

  if (Negative_Code ==  1) {
    YNeg =  1;
    XNeg =  1;
    Boundary_Calc = 1;
    if (Show_Calculations == 1) Serial.println("Y Positive   X Positive");
  }

  if (Negative_Code ==  2) {
    YNeg =  1;
    XNeg =  1;
    Boundary_Calc = 2;
    if (Show_Calculations == 1) Serial.println("Y Positive   X Positive");
  }
  
  // Build the GPS Value back together from the EEPOM storage positions

  // Build GPS Y Coordinate  
  double Part1 = EEPROM.read((i*10) - 9);    // The whole part of the number
  if (Show_Calculations == 1) Serial.print("Y Part 1 :");
  if (Show_Calculations == 1) Serial.println(Part1, 8);


  double Part2 = (EEPROMReadlong((i*10) - 8));
  Part2 = Part2 / 100000000;
  if (Show_Calculations == 1) Serial.print("Y Part 2 /100000000 :");
  if (Show_Calculations == 1) Serial.println(Part2, 8);

  GPSY_EEPROM[i - 1] = (Part1 + Part2) * YNeg;               // The whole part of the number + the decimal part




  // Build GPS X Coordinate  
  Part1 = EEPROM.read((i*10) - 4);    // The whole part of the number
  if (Show_Calculations == 1) Serial.print("X Part 1 :");
  if (Show_Calculations == 1) Serial.println(Part1, 8);

  
  Part2 = (EEPROMReadlong((i*10) - 3));
  Part2 = Part2 / 100000000;
  if (Show_Calculations == 1) Serial.print("X Part 2 /100000000 :");
  if (Show_Calculations == 1) Serial.println(Part2, 8);

  GPSX_EEPROM[i - 1] = (Part1 + Part2) * XNeg;               // The whole part of the number + the decimal part

  Serial.print("GPSY[");
  Serial.print(i -1);
  Serial.print("] = ");
  Serial.print(GPSY_EEPROM[i - 1], 8);   // Print the vlaue to 8 decimal places
  
  Serial.print("  GPSX[");
  Serial.print(i -1);
  Serial.print("] = ");
  Serial.print(GPSX_EEPROM[i - 1], 8);   // Print the vlaue to 8 decimal places


  // Read Boundary Condition
  //Boundary_EEPROM[i - 1] = EEPROM.read( (i + 450) );                             // BOundary Condition
  Serial.print("  Boundary[");
  Serial.print(i -1);
  Serial.print("] = ");
  Serial.println(Boundary_Calc);

  }
Serial.println(" ");
Serial.print("GPSMAX =");
Serial.println(GPSMAX2);

Serial.println(" ");
Serial.println(" ");
Serial.println("EEPROM Load Completed");
Serial.println(" ");
Serial.println(" ");

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
