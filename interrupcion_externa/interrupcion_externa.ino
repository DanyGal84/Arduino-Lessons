int led = 5;
int button = 3;
String on_off;
bool button_state;

long previous_time;
long difference;

void setup() {
  Serial.begin(9600);

  pinMode(button, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(button), check_state, FALLING);
}

void loop() {
  //Serial.println(millis());
}

void check_state() {
  difference = millis() - previous_time;
  previous_time = millis();

  Serial.println(difference);

  if(difference > 500) {
    button_state = digitalRead(button);
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
}
