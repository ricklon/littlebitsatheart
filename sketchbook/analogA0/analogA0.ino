//Declare integer to hold value read by analog read 0-1023
int valA0;

void setup() {
//pin mode OUTPUT data or energy out
pinMode(5, OUTPUT);
//usually you don't need to set analog pinmode because they always take data in
}

void loop() {
//get Inputs
//lower case a0, d1 is not defined. d0 is not defined.
valA0 = analogRead(A0);

//interact with world
//scale the values for the proper OUTPUT
//do not have to scale digital INPUT D0
int mapA0 = map(valA0, 0, 1023, 0, 255);

//send Outputs
analogWrite(5, mapA0);

}
