String nombres [5] = {"Dino", "Daniel", "Pablo", "Pedro", "Fabian"};
int mascotas [5] = {10, 23, 5, 0, 11};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(100);

  int cuenta = 0;

  while (cuenta < 5) {
    if(nombres[cuenta] == "Dino") {
      Serial.println("Encontre a " + nombres[cuenta]);
      Serial.println("En la posicion " + String(cuenta));
    }

    cuenta++;
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
