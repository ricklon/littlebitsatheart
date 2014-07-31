//Declare integer to hold digital value D0
//Analog inputs are ignored
int valD0;

void setup() {
  //pin mode INPUT data or energy in
  pinMode(0, INPUT);
  //pin mode for OUTPUT pin to send energy out
  pinMode(1, OUTPUT);
}

void loop() {
  //get Inputs
  //lower case a0, d1 is not defined. d0 is not defined.
  valD0 = digitalRead(0);

  //send Outputs
  digitalWrite(1, valD0);

}


