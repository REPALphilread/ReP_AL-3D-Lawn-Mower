void Simulate_Mower_Movements() {

    float Speed = 0.0000025;
    float Factor = 2.5;
    
    Serial.print(F("Simuation = Bounce: "));
    Serial.print(bounce);
    Serial.print(F(" | Bounce Back: "));
    Serial.print(bounce_back);
    Serial.print(" | ");
    
    // Simulates the mower moving around the GPS Fence.
    if (Mower_In_Out == 0) { 
      Mower_In_Out = 1;
      bounce = bounce + 1;
      if (bounce == 10) bounce = 1;
      bounce_back = 1;
      }

    // Simulate Movement 1
    if ( (Mower_In_Out == 1) && (bounce == 1)) {
      if (bounce_back == 1) {
        X_GPS = X_GPS - (0);
        Y_GPS = Y_GPS + ( Speed * Factor);
        }      
      if (bounce_back == 0) {
      X_GPS = X_GPS - Speed;                          // retun value from bounce 5
      Y_GPS = Y_GPS + 0;
      }
      bounce_back = 0;
      }

     
    // Simulate Movement 2
    if ( (Mower_In_Out == 1) && (bounce == 2)) {
      if (bounce_back == 1) {
        X_GPS = X_GPS + (Speed * Factor);             // retun value from bounce 1
        Y_GPS = Y_GPS - (0);
        
        }
      if (bounce_back == 0) {
      X_GPS = X_GPS + Speed;
      Y_GPS = Y_GPS - Speed;
      }
      bounce_back = 0;
     }

    // Simulate Movement 3
    if ( (Mower_In_Out == 1) && (bounce == 3)) {
      if (bounce_back == 1) {
        X_GPS = X_GPS - (Speed * Factor);           // return values from bounce 2
        Y_GPS = Y_GPS + (Speed * Factor);
        
        }  
      if (bounce_back == 0) { 
      X_GPS = X_GPS - Speed;
      Y_GPS = Y_GPS + Speed;
      }
      bounce_back = 0;
      }

    // Simulate Movement 4
    if ( (Mower_In_Out == 1) && (bounce == 4)) {
      if (bounce_back == 1) {
        X_GPS = X_GPS + (Speed * Factor);
        Y_GPS = Y_GPS - (Speed * Factor);
        }   
      if (bounce_back == 0) {
      X_GPS = X_GPS + Speed;
      Y_GPS = Y_GPS + Speed;
      }
      bounce_back = 0;
      }
    
    // Simulate Movement 5
    if ( (Mower_In_Out == 1) && (bounce == 5)) {
      if (bounce_back == 1) {
        X_GPS = X_GPS - (Speed * Factor);
        Y_GPS = Y_GPS - (Speed * Factor);
        }   
      if (bounce_back == 0) {
      X_GPS = X_GPS - Speed;
      Y_GPS = Y_GPS + 0;
      }
      bounce_back = 0;
      }


    // Simulate Movement 6
    if ( (Mower_In_Out == 1) && (bounce == 6)) {
      if (bounce_back == 1) {
        X_GPS = X_GPS + (Speed * Factor);
        Y_GPS = Y_GPS - (0);
        }   
      if (bounce_back == 0) {
      X_GPS = X_GPS - Speed;
      Y_GPS = Y_GPS - Speed;
      }
      bounce_back = 0;
      }

    // Simulate Movement 7
    if ( (Mower_In_Out == 1) && (bounce == 7)) {
      if (bounce_back == 1) {
        X_GPS = X_GPS + (Speed * Factor);
        Y_GPS = Y_GPS + (Speed * Factor);
        }   
      if (bounce_back == 0) {
      X_GPS = X_GPS - 0;
      Y_GPS = Y_GPS + Speed;
      }
      bounce_back = 0;
      }


    // Simulate Movement 8
    if ( (Mower_In_Out == 1) && (bounce == 8)) {
      if (bounce_back == 1) {
        X_GPS = X_GPS + (0);
        Y_GPS = Y_GPS - (Speed * Factor);
        }   
      if (bounce_back == 0) {
      X_GPS = X_GPS + Speed;
      Y_GPS = Y_GPS + 0;
      }
      bounce_back = 0;
      }

    // Simulate Movement 9
    if ( (Mower_In_Out == 1) && (bounce == 9)) {
      if (bounce_back == 1) {
        X_GPS = X_GPS - (Speed * Factor);
        Y_GPS = Y_GPS - (0);
        }   
      if (bounce_back == 0) {
      X_GPS = X_GPS + 0;
      Y_GPS = Y_GPS - Speed;
      }
      bounce_back = 0;
      }

}
