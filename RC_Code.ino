#include <Servo.h>

const int steeringPin = 2;
const int enA = 3;
const int enB = 10;

const int in1 = 4;
const int in2 = 5;
const int in3 = 12;
const int in4 = 11;

int i, v=0;

Servo steering;

void straight()   {steering.write(106);}
void turnR()      {steering.write(60);} 
void turnL()      {steering.write(140);} 

void maju()     
  {
     analogWrite(enA, 100);
     digitalWrite(in1, HIGH);
     digitalWrite(in2, LOW);

     analogWrite(enB, 100);
     digitalWrite(in3, HIGH);
     digitalWrite(in4, LOW);
  }
void mundur()
  {
     analogWrite(enA, 100);
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);

     analogWrite(enB, 100);
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
  }
void stopmotor()
 {
    analogWrite(enA, 0);
     digitalWrite(in1, LOW);
     digitalWrite(in2, LOW);

     analogWrite(enB, 0);
     digitalWrite(in3, LOW);
     digitalWrite(in4, LOW);
 }
 
void boost()
  {
      analogWrite(enA, 250);
     digitalWrite(in1, HIGH);
     digitalWrite(in2, LOW);

     analogWrite(enB, 250);
     digitalWrite(in3, HIGH);
     digitalWrite(in4, HIGH);
  }

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(steeringPin, INPUT);
  
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  steering.attach(2);

  straight();
  stopmotor();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) 
  {
    int value = Serial.read();
    Serial.println(value);
    
    if      (value==54)   { maju(); straight(); }   // cross button
    else if (value==50)    { mundur(); straight(); } //down button
    else if (value==51)   turnR();      //Right button
    else if (value==52)   turnL();      //Left button
    else if (value==49)   boost();      //up button
    else if (value==55)   stopmotor();  //square button
    else                  straight();
  }
  
  else  {delay(200);straight();}
  
}


