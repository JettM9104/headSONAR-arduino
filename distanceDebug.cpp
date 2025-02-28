const int trigPin = 9;
const int echoPin = 10;

#include "arduino.h" // comment this out when compiling

float duration, distance;
float distances[5];
float average;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
 
    duration = pulseIn(echoPin, HIGH);
    distance = (duration*.0343)/2;
    distances[i] = distance;
    delay(100);
  }
  for (int i = 0; i < 5; i++) {
    average += distances[i];
  }
  average /= 5;

 

  Serial.println(average);
 
}