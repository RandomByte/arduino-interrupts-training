
int pin = 2;
int timerPin = 3;
int volatile counter = 0;
long volatile timeOfLastInterrupt = 0;
int const MIN_TIME_BETWEEN_INTERRUPTS = 10000; // microseconds
volatile byte state = HIGH;

void setup() {
  pinMode(pin, INPUT_PULLUP);
  pinMode(timerPin, INPUT_PULLUP);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(pin), processButtonChange, CHANGE);
  
  attachInterrupt(digitalPinToInterrupt(timerPin), timerTick, FALLING);
  //tone(timerPin, 1000);
}

void loop() {
  Serial.print("Counter: ");
  Serial.println(counter);
  delay(100);

}

void processButtonChange() {
  noInterrupts();
  tone(timerPin, 1000);

  interrupts();
}

void processButtonPush() {
  long currentTime = micros();

  if ((currentTime - timeOfLastInterrupt) > MIN_TIME_BETWEEN_INTERRUPTS) {
    counter++;
    timeOfLastInterrupt = currentTime; 
  }
}

void processButtonPushEnd() {
  timeOfLastInterrupt = micros();
}

void timerTick() {
  noInterrupts();
  noTone(timerPin);
  int value = digitalRead(pin);
  if (value == LOW) {
    counter++;
  }
  interrupts();
  
}

