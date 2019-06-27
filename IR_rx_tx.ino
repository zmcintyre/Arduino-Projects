int irRX;
void setup() {
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(A1, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(2, HIGH);  
  irRX = analogRead(A1);
  if (irRX < 175) {
    digitalWrite(4, HIGH);
    Serial.println(irRX);  
    } 
  else {
    digitalWrite(4, LOW);
    }
  delay(25);                  
}
