
// Tests the relay funciton on PIN24.
// make sure the pin is inserted in 24.  It can be confusing looking at the board
// which is actually PIN24...


/*Relay Switches*/
#define Relay_Motors 24


void setup() {
  // put your setup code here, to run once:

pinMode(Relay_Motors, OUTPUT);
Serial.begin (115200);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(Relay_Motors, HIGH);
  Serial.println("Relay ON");
  delay(1000);
  digitalWrite(Relay_Motors, LOW);
  Serial.println("Relay OFF");
  delay(1000);


}
