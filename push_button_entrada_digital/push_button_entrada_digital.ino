int led = 5;
int button = 3;
String on_off;

void setup() {
  Serial.begin(9600);

  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  bool button_state = digitalRead(button);
  
  if (!button_state) {
    on_off = "APAGADO";
    Serial.println(on_off);
    digitalWrite(led,LOW);
  } else {
    on_off = "ENCENDIDO";
    Serial.println(on_off);
    digitalWrite(led,HIGH);
  }
}
