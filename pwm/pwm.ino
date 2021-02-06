const int red_led = 6;
const int blue_led = 5;
const int green_led = 3;
const int pause = 100;
int brillo = 0;

void setup() {
  // pinMode(red_led, OUTPUT);
  // analogWrite(red_led,0);
  // delay(1000);
  // analogWrite(red_led,65);
  // delay(1000);
  // analogWrite(red_led,127);
  // delay(1000);
  // analogWrite(red_led,189);
  // delay(1000);
  // analogWrite(red_led,250);
  // delay(1000);
}

void loop() {
  for (int brillo = 0; brillo < 255; brillo++) {
    analogWrite(red_led, brillo);
    delay(10);
  }

  for (int brillo = 255; brillo > 0; brillo--) {
    analogWrite(red_led, brillo);
    delay(10);
  }
  
}
