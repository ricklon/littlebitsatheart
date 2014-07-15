//set up the race variables and default state values
#define ENDSCORE 25

boolean started = false;
int score1 = 0;
int score2 = 0;

int valA0 = 0;
int valA1 = 0;
int valD0 = 0;
int lastValA0 = 0;
int lastValA1 = 0;

//set up the race
void setup() {
  Serial.begin(9600);
  //pin mode OUTPUT data or energy out

  pinMode(1, OUTPUT); //motor racer 1
  pinMode(5, OUTPUT); //motor racer 2
  pinMode(9, OUTPUT); //buzzer 

  //pin mode INPUT data or energy in
  pinMode(0, INPUT);
  //use analog pins as digital pins
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);  

  //turn motors to default off
  digitalWrite(1, LOW);
  digitalWrite(5, LOW);
}


void loop() { 
  //get Inputs
  //lower case a0, d1 is not defined. d0 is not defined. use upper case
  //Read all inputs as digital inputs
  valA0 = digitalRead(A0);
  valA1 = digitalRead(A1);
  valD0 = digitalRead(0);

  //interact with world
  if (started)
  {
    //OUTPUT: debug with serial data
    //send Outputs
    digitalWrite(1, HIGH);
    digitalWrite(5, HIGH);


    if (valA0 != lastValA0) 
    {
      if(valA0 == HIGH)
      {
        score1++;
        Serial.print("score1: ");
        Serial.print(score1);
        Serial.print(" score2: ");
        Serial.println(score2);
      }
    }
    if (valA1 != lastValA1) 
    {
      if(valA1 == HIGH)
      {
        score2++;
        Serial.print("score1: ");
        Serial.print(score1);
        Serial.print(" score2: ");
        Serial.println(score2);
      }

    }
    if (score1 >= ENDSCORE)
    {
      digitalWrite(9, HIGH);
      delay(500);
      digitalWrite(9, LOW);
      digitalWrite(5, LOW);
      delay(2000);
      digitalWrite(1, LOW);


      //reset game to play again
      started = false;
      score1 = 0;
      score2 = 0;
      delay(2000);

    }
    if (score2 >= ENDSCORE)
    {
      digitalWrite(9, HIGH);
      delay(500);
      //reset game to play again
      digitalWrite(9, LOW);
      digitalWrite(1, LOW);
      delay(2000);
      digitalWrite(5, LOW);


      started = false;
      score1 = 0;
      score2 = 0;
      delay(2000);

    }
    lastValA0 = valA0;
    lastValA1 = valA1;

  }
  else
  {
    if (valD0 == HIGH)
    {
      started = true; 
      Serial.print("started");
      Serial.println(started);
    }
  }


}
















