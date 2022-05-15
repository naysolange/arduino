
const int LDRPin = A0;

void setup() {
  pinMode(LDRPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int input = analogRead(LDRPin);
  //sleep(1000);
  Serial.println(input);
}
