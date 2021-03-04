void Get_GYRO_Reading() {
         Wire.beginTransmission(MPU_addr);
         Wire.write(0x3B);
         //Wire.endTransmission(false);                 // try to remove the false
         Wire.endTransmission(true); 
         Wire.requestFrom(MPU_addr,7*2,true);

         if (Wire.available() <= 14) {         
             AcX = Wire.read()<<8 | Wire.read();
             AcY = Wire.read()<<8 | Wire.read();
             AcZ = Wire.read()<<8 | Wire.read();
             Temp = Wire.read()<<8 | Wire.read();
             GyX = Wire.read()<<8 | Wire.read(); // reading registers: 0x43 (GYRO_XOUT_H) and 0x44 (GYRO_XOUT_L)
             GyY = Wire.read()<<8 | Wire.read(); // reading registers: 0x45 (GYRO_YOUT_H) and 0x46 (GYRO_YOUT_L)
             GyZ = Wire.read()<<8 | Wire.read(); // reading registers: 0x47    
             } 
             
         int xAng = map(AcX,minVal,maxVal,-90,90);
         int yAng = map(AcY,minVal,maxVal,-90,90);
         int zAng = map(AcZ,minVal,maxVal,-90,90);
              
         GYRO_Angle_X = RAD_TO_DEG * (atan2(-yAng, -zAng)+PI);
         GYRO_Angle_Y = RAD_TO_DEG * (atan2(-xAng, -zAng)+PI);
         GYRO_Angle_Z = RAD_TO_DEG * (atan2(-yAng, -xAng)+PI);
        
         Heading = atan2(yAng, xAng);
                
         Serial.print("|GX=");
         Serial.print(GYRO_Angle_X);
         Serial.print("|GY=");
         Serial.print(GYRO_Angle_Y);             
         Serial.print("|GZ=");
         Serial.print(GYRO_Angle_Z);
         //delay(100);
         } 

void Print_GYRO_Reading() {              
         Serial.print(" | tmp = ");    Serial.print(Temp/340.00+36.53);
         Serial.print(" | Gyro X = "); Serial.print(convert_int16_to_str(GyX));
         Serial.print(" | Gyro Y = "); Serial.print(convert_int16_to_str(GyY));
         Serial.print(" | Gyro Z = "); Serial.println(convert_int16_to_str(GyZ));
         delay(100);
         } 


void Calculate_GYRO_Wheel_Compensation() {

  int GYRO_Error_X = 0;
  
  if (GYRO_Angle_X > 180) GYRO_Error_X = (360 - GYRO_Angle_X);        // Calculates the error in compass heading from the saved lock heading
  if (GYRO_Angle_X <= 180) GYRO_Error_X = GYRO_Angle_X;        // Calculates the error in compass heading from the saved lock heading

  
  // Mower is tipping to the Left
  // Left Wheel needs to be at full power and less power to the right wheel to steer right.
  if (GYRO_Angle_X > 180) {                                             // Steer Right
     Serial.print(F("GR|"));
    
    
    // With no adjustment of wheel speed according to MAG Level    
    if (MAG_Speed_Adjustment == 0) {
      PWM_Left = PWM_MaxSpeed_LH;         
      PWM_Right = PWM_MaxSpeed_RH - (GPower * GYRO_Error_X);            // Multiply the difference by D to increase the power then subtract from the PWM
      if (PWM_Right < 0) PWM_Right = PWM_MaxSpeed_RH - 50;
      }
    
    GYRO_Steering_Status = 2;
    } 




  // Mower is tipping to the Right  
  // Right Wheel needs to be at full power and less power to the left wheel to steer left.
  if (GYRO_Angle_X <= 180) {      
    Serial.print(F("GL|"));

    // With no adjustment of wheel speed according to MAG Level
    if (MAG_Speed_Adjustment == 0) {
      PWM_Right = PWM_MaxSpeed_RH; 
      PWM_Left = PWM_MaxSpeed_LH - (GPower * GYRO_Error_X);            // Multiply the difference by D to increase the power then subtract from the PWM
      if (PWM_Left < 0) PWM_Left = PWM_MaxSpeed_LH - 50;
      }
    

    GYRO_Steering_Status = 3;
    }

}
