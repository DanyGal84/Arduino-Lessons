void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(100);

  Serial.println("El resultado es: " + String(suma_numeros(20, 15)));
}

void loop() {
  // put your main code here, to run repeatedly:

}

int suma_numeros(int valor_a, int valor_b) {
  int resultado = valor_a + valor_b;
  return resultado;
}
