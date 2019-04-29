
#define BTSerial Serial1
#define BAUD 115200
String Eingabe;
String Losung;
int x;
int error;
int nummer;
String c;

// Funktionen:
int Option(int a, int b) {
  int result;
  result = random(a, b);
  return result;
  }

String Generator() {
  while (Losung.length() <= 4) {
    x = random(1,8);
    while (error == 0) {
      for (int i = 0; i < 4; i = i + 1) {
        if (Losung.charAt(i) == x) {
        error = 1;
        //Serial.println("Error");
        } 
      }
      Losung = Losung + x;
    }
  }
  return Losung;
}








void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUD);
  BTSerial.begin(BAUD);
  Serial.println("Gib deinen Kram ein");

    
}

void loop() {
  // put your main code here, to run repeatedly:
  nummer = random(1,8);
  Serial.println(random(1,8));
  c = Generator();
  //Serial.println(c);
  delay(2000);
  

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
