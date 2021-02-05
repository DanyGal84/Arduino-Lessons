const int green_led = 3;
const int blue_led = 5;
const int red_led = 6;
const int pausa = 200;

void setup() {
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
  pinMode(red_led, OUTPUT);
}

void loop() {

  for (int i = 0; i < 5; i++) {
    derecha();
  }

  apagado();
  delay(pausa * 3);

  for (int i = 0; i < 5; i++) {
    izquierda();
  }
  
  apagado();
  delay(pausa * 3);

}

void apagado() {
  digitalWrite(green_led, LOW);
  digitalWrite(blue_led, LOW);
  digitalWrite(red_led, LOW);
}

void derecha() {
  digitalWrite(green_led, HIGH);
  digitalWrite(blue_led, LOW);
  digitalWrite(red_led, LOW);
  delay(pausa);

  digitalWrite(green_led, LOW);
  digitalWrite(blue_led, HIGH);
  digitalWrite(red_led, LOW);
  delay(pausa);
  
  digitalWrite(green_led, LOW);
  digitalWrite(blue_led, LOW);
  digitalWrite(red_led, HIGH);
  delay(pausa);
}

void izquierda() {
  digitalWrite(green_led, LOW);
  digitalWrite(blue_led, LOW);
  digitalWrite(red_led, HIGH);
  delay(pausa);

  digitalWrite(green_led, LOW);
  digitalWrite(blue_led, HIGH);
  digitalWrite(red_led, LOW);
  delay(pausa);
  
  digitalWrite(green_led, HIGH);
  digitalWrite(blue_led, LOW);
  digitalWrite(red_led, LOW);
  delay(pausa);
}