int padInput;

void setup() {
  pinMode(A2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  padInput = analogRead(A2);
  Serial.print(input(0));
  Serial.println();
  delay(100);
}

int input(int state){
  if (padInput > 300 and padInput < 305){
    state = 1;
    Serial.print("up");
    Serial.println();
    delay(100);
    return;
    }

  else if (padInput > 13 and padInput < 18){
    state = 2;
    Serial.print("down");
    Serial.println();
    delay(300);
    return;
    }
    
  else if (padInput > 428 and padInput < 433){
    state = 3;
    Serial.print("left");
    Serial.println();
    delay(100);
    return;
  }
  
  else if (padInput > 168 and padInput < 173){
    state = 4;
    Serial.print("right");
    Serial.println();
    delay(100);
    return;
  }
  else if (padInput > 550 and padInput < 555){
    state = 5;
    Serial.print("middle");
    Serial.println();
    delay(100);
    return;
    }
    else {
      state = 0;
      return;
      }
  }
