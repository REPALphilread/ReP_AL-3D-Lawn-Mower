void Run_Pattern_Mow_Code() {
  
    Motor_Action_Stop_Motors(); 
    //Motor_Action_Stop_Spin_Blades(); 
    delay(500);
    SetPins_ToGoBackwards();
    Motor_Action_Go_Full_Speed();
    delay(1000);
    Motor_Action_Stop_Motors(); 
    delay(500);
    
    int Right_Angle_Delay = 1100;                         // delay to turn the mower 90°
    int Forwards_Align = 500;                   // delay to move the mower to a new line    
    
    if (Compass_Leg == 0)  {
      SetPins_ToTurnRight();
      Motor_Action_Go_Full_Speed();
      delay(Right_Angle_Delay);
      Motor_Action_Stop_Motors();
      Get_Compass_Reading();
      
      SetPins_ToGoForwards();
      Motor_Action_Go_Full_Speed();
      delay(Forwards_Align);
      Motor_Action_Stop_Motors();
      Get_Compass_Reading();
      
      SetPins_ToTurnRight();
      Motor_Action_Go_Full_Speed();
      delay(Right_Angle_Delay);
      Motor_Action_Stop_Motors();
      Get_Compass_Reading();
      }
    
    if (Compass_Leg == 1)  {
      SetPins_ToTurnLeft();
      Motor_Action_Go_Full_Speed();
      delay(Right_Angle_Delay);
      Motor_Action_Stop_Motors();
      Get_Compass_Reading();
      
      SetPins_ToGoForwards();
      Motor_Action_Go_Full_Speed();
      delay(Forwards_Align);
      Motor_Action_Stop_Motors();
      Get_Compass_Reading();
      
      SetPins_ToTurnLeft();
      Motor_Action_Go_Full_Speed();
      delay(Right_Angle_Delay);
      Motor_Action_Stop_Motors();
      Get_Compass_Reading();
      }

    //Set the compass leg to the next stage.
    Compass_Leg = Compass_Leg + 1;
    if (Compass_Leg > 1) Compass_Leg = 0;  
    
    }



void Run_Pattern_Mow_Code_Old() {
  
    Motor_Action_Stop_Motors(); 
    Motor_Action_Stop_Spin_Blades(); 
    delay(500);
    SetPins_ToGoBackwards();
    Motor_Action_Go_Full_Speed();
    delay(1000);
    Motor_Action_Stop_Motors(); 
    delay(500);
    
    
    
    if (Compass_Leg == 0)  {
      SetPins_ToTurnRight();
      delay(200);
      Get_Compass_Reading();
      delay(200);
      Get_Compass_Reading();
      // Turn the Mower 90° to the corner
      Serial.println("");
      Serial.print("Compas_Leg = 0 | ");
      Serial.print("Turning 90°|");
      Compass_Target = Compass_Mow_Direction + 90;
      if (Compass_Target > 360) (Compass_Target = Compass_Target - 360); 
      Serial.print("|Target Degree Heading = ");
      Serial.print(Compass_Target);
      Serial.print("|");
      Turn_To_Compass_Heading();  
      
      // Move Forwards at 90° and stop
      SetPins_ToGoForwards();
      Motor_Action_Go_Full_Speed();
      delay(1500);
      Motor_Action_Stop_Motors(); 
      SetPins_ToTurnRight();
      Motor_Action_Go_Full_Speed();
      delay(200);
      Get_Compass_Reading();
      delay(200);
      Get_Compass_Reading();
 

      // Turn 180° to the initial mowing direction.
      Serial.println(""); 
      Serial.print("|Return Leg 1°");
      Compass_Target = Compass_Mow_Direction;
      if (Compass_Target > 360) (Compass_Target = Compass_Target - 360); 
      Serial.print("|Target Degree Heading = ");
      Serial.print(Compass_Target);
      Serial.println("|");
      Turn_To_Compass_Heading();  
      }
    
    if (Compass_Leg == 1)  {
      // Turn the Mower 90° to the corner
      Serial.println("");
      Serial.print("Compass_Leg = 1|");
      Serial.print("Turning 90°");
      SetPins_ToTurnLeft();
      Motor_Action_Go_Full_Speed();
      delay(200);
      Get_Compass_Reading();
      delay(200);
      Get_Compass_Reading();
      Compass_Target = Compass_Mow_Direction + 90;
      if (Compass_Target < 0) (Compass_Target = 360 + Compass_Target); 
      Serial.print("|Target Degree Heading = ");
      Serial.print(Compass_Target);
      Turn_To_Compass_Heading();  

      // Move Forwards at 90° and stop
      SetPins_ToGoForwards();
      Motor_Action_Go_Full_Speed();
      delay(1500);
      Motor_Action_Stop_Motors(); 
      SetPins_ToTurnLeft;
      Motor_Action_Go_Full_Speed();
      delay(200);
      Get_Compass_Reading();
      delay(200);
      Get_Compass_Reading();

      // Turn 180° to the initial mowing direction.
      Serial.println("");
      Serial.print("|Return Leg 0°");
      Compass_Target = Compass_Mow_Direction + 180;
      if (Compass_Target > 360) (Compass_Target = Compass_Target - 360);
      Serial.print("|Target Degree Heading = ");
      Serial.print(Compass_Target);
      Serial.println("|");
      Turn_To_Compass_Heading();  
      }


    //Set the compass leg to the next stage.
    Compass_Leg = Compass_Leg + 1;
    if (Compass_Leg > 1) Compass_Leg = 0;  
    
    }
