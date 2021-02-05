float numero = 32;
float numero2 = 23;
float resultado;
int residuo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(100);
  Serial.println("Iniciando programa");

  numero++; // Operador mixto suma de uno en uno
  numero--; // Operador mixto resta de uno en uno
  numero = numero - numero2;
  resultado = numero / numero2;

  Serial.println("El resultado es: " + String(resultado, 4));

  residuo = 7 % 5;

  Serial.println("El residuo de dividir 7 entre 5 es: " + String(residuo));

  // Mismos comparadores de siempre < > <= >= != !== == ===
  if (numero == numero2) {
    Serial.println("Si son iguales");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
