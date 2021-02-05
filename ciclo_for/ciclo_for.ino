String mensajes [4] = {"hola bienvenidos", "adios hasta pronto", "como estas?", "me gusta arduino"};
int mascotas [4] = {10, 23, 5, 0};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(100);

  Serial.println("Cantidad actual:");
  Serial.println("");

  for(int i = 0; i < 4; i++) {
    Serial.println("El mensaje numero: " + String(i) + mensajes[i]);
  }

  for(int i = 0; i < 4; i++) {
    Serial.println("Mascotas en tienda: " + String(i) + " Cantidad: " + mascotas[i]);
  }

  Serial.println("Cantidad futura:");
  Serial.println("");

  for(int i = 0; i < sizeof(mascotas)/sizeof(mascotas[0]); i++) {
    mascotas[i] = mascotas[i] + 5; 
    Serial.println("Mascotas en tienda: " + String(i) + " Nueva Cantidad: " + mascotas[i]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
