
int pin = 2;
int volatile counter = 0;
long volatile timeOfLastInterrupt = 0;
int const MIN_TIME_BETWEEN_INTERRUPTS = 10000; // microseconds

void setup() {
  pinMode(pin, INPUT_PULLUP);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(pin), processButtonPush, FALLING);
}

void loop() {
  Serial.print("Counter: ");
  Serial.println(counter);
  delay(100);

}

void processButtonPush() {
  noInterrupts();
  long currentTime = micros();

  if ((currentTime - timeOfLastInterrupt) > MIN_TIME_BETWEEN_INTERRUPTS) {
    counter++;
    timeOfLastInterrupt = currentTime; 
  }
  interrupts();
}

