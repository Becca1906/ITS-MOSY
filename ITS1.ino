String Eingabe;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Gib deinen Kram ein");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    Eingabe = Serial.readString();
    Serial.println(Eingabe);
  
    if (Eingabe.charAt(0) == 's') {
      Serial.print("Start, alle Lichter weiß");
    }
    if (Eingabe.charAt(0) == 'e') {
      Serial.println("Eingabe");
      Serial.print("Der Scheinwerfer "); Serial.print(Eingabe.charAt(1)); Serial.print(" leuchtet in der Farbe "); Serial.println(Eingabe.charAt(2));
    }
    if (Eingabe.charAt(0) == 'f') {
      Serial.println("Feedback");
      Serial.print("Der Scheinwerfer "); Serial.print(Eingabe.charAt(1)); Serial.print(" leuchtet in der Art "); Serial.println(Eingabe.charAt(2));
    }
    if (Eingabe.charAt(0) == 'x') {
      Serial.println("Ende");
      if (Eingabe.charAt(1) == 'g') {
      Serial.println("Du hast gewonnen und alle werden heller");
      }
      if (Eingabe.charAt(1) == 'a') {
      Serial.println("Abbruch und alles aus");
      }
    }
  }
}