int number = 1;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
    }
  pinMode(2, INPUT);
}

void loop() {
  if (analogRead(2) == HIGH) {    
    Serial.println("pushed " + String(number));
    digitalWrite(8, HIGH);
    delay(200);
    digitalWrite(8, LOW);
    number++;
    return;
  }
}
