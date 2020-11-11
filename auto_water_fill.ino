#include <Stepper.h>
#define STEPS 200
#define motorInterfaceType 1

// defines pins numbers
const int stepPin = 5; 
const int dirPin = 6;
const int relayPin = A3;
const int irPin = A0;

Stepper stepper(STEPS, dirPin, stepPin);

int irVal = 0;

void setup() {
  // Sets the two pins as Outputs
  Serial.begin(9600);
  stepper.setSpeed(500);
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(relayPin,OUTPUT);
  pinMode(irPin,INPUT);
  Serial.println("setup complete");
}

void loop() {
  irVal = analogRead(irPin);
  Serial.println(irVal);
  if (irVal > 0 && irVal < 500) {
    Serial.println(digitalRead(relayPin));
    Serial.println("step 400");
    stepper.step(400);
    delay(1000);
    digitalWrite(relayPin, HIGH);
    delay(5000);
    digitalWrite(relayPin, LOW);
    delay(1000);
    Serial.println("step 800");
    stepper.step(800);   
  }
  else {
    Serial.println(digitalRead(relayPin));
    digitalWrite(relayPin, LOW);
    Serial.println("step 800");
    stepper.step(800);
    delay(1000);
  }  
}
