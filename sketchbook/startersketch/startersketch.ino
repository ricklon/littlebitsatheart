
  //declare Inputs
  //lower case a0, d1 is not defined. d0 is not defined.
  int valA0;
  int valA1;
  int valD0;
  
void setup() {
  //pin mode OUTPUT data or energy out
  pinMode(1, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);

  //pin mode INPUT data or energy in
  pinMode(0, INPUT);
  //usually you don't need to set analog pinmode because they always take data in

}


void loop() { 
  //get Inputs
  //lower case a0, d1 is not defined. d0 is not defined.
  valA0 = analogRead(A0);
  valA1 = analogRead(A1);
  valD0 = digitalRead(0);


  //interact with world
  //scale the values for the proper OUTPUT
  //do not have to scale digital INPUT D0
  int mapA0 = map(valA0, 0, 1023, 0, 255);
  int mapA1 = map(valA1, 0, 1023, 0, 255);
  
  //send Outputs
  digitalWrite(1, valD0);
  analogWrite(5, mapA0);
  analogWrite(9, mapA1);

}
