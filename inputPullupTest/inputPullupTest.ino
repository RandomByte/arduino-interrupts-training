
int pin = 2;

void setup() {
  pinMode(pin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int value = digitalRead(pin);
  Serial.println(value);
  delay(100);

}
