const short int TRIG_PIN = 9;
const short int ECHO_PIN = 10;
const short int BUZZER_PIN = 6;
const short int BUTTON_PIN = 5;

bool enabled;
bool buttonState;

#include "arduino.h"

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(TRIG_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  Serial.begin(9600);

}
void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, LOW);

  long int duration = pulseIn(ECHO_PIN, HIGH);

  buttonState = digitalRead(BUTTON_PIN);

  if (buttonState) {
    while (buttonState) delay(20);

    if (enabled) {
      enabled = 0;
    }
    else {
      enabled = 1;
    }
  }

  float distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if (enabled) {
    if(distance > 0 && distance < 100) {
      tone(BUZZER_PIN, 1000);
    }
    else {
      noTone(BUZZER_PIN);
    }
  }
}