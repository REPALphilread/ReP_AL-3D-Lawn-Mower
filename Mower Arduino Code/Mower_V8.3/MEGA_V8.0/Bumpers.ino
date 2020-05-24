// Routine to check the bumper Switch
// The global variable Bump is then activated so the Mower can react to the bumper being activated
void Check_Bumper() {

if (Bumper_Activate_Frnt == true) {

  if (digitalRead(Bumper_Switch_Frnt_LH))   Bump_Frnt_LH = false;    // The switch is not activated the variable Bump is false
  if (!digitalRead(Bumper_Switch_Frnt_LH))  Bump_Frnt_LH = true;     // The switch is activated the variable Bump is true
  
  if (digitalRead(Bumper_Switch_Frnt_RH))   Bump_Frnt_RH = false;    // The switch is not activated the variable Bump is false
  if (!digitalRead(Bumper_Switch_Frnt_RH))  Bump_Frnt_RH = true;     // The switch is activated the variable Bump is true
  
  if ((Bump_Frnt_LH == false) && (Bump_Frnt_RH == false))  Bumper = false;
  if ((Bump_Frnt_LH == true ) || (Bump_Frnt_RH == true) )  {
    Bumper = true;
    Motor_Action_Stop_Motors();
  }

  }


}