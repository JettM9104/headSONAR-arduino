#define TRIG_PIN 9
#define ECHO_PIN 10
#define BUZZER_PIN 6

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(TRIG_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  Serial.begin(9600);

}
void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);

  int distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if(distance > 0 && distance < 100) {
    tone(BUZZER_PIN,1000);
       
  }
  else {
    noTone(BUZZER_PIN);
  }
}