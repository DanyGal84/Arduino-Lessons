String nombres [7] = {"Pedro", "Pablo", "Dino", "Daniel", "Jose", "Raul", "Fabian"};
int pet_shops [9] = {10, 23, 5, 0, 11, 55, 23, 24, 1};
char palabra [10] = "Cordoba";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(100);

  int cuenta = 0;

  int tamano = sizeof(nombres)/sizeof(nombres[0]);

  Serial.println("Tamano es: " + String(tamano));

  while (cuenta < tamano) {
    if(cuenta == 3) {
      // continue; 
      break;
    }

    Serial.println("En posición " + String(cuenta) + " exisete el valor: " + nombres[cuenta]);
    cuenta++;
  }

  Serial.println("Aca sigue ejecutando");
}

void loop() {
  // put your main code here, to run repeatedly:

}
