unsigned int counted_people;
float peso_alumno = 56.8;
long numero_grande = 5000000; 
char primera_letra = 'd';

String saludo = "Hola alumnos";
bool activado = true;

int cuenta = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(100);
  Serial.println(saludo);
  delay(2000);
  saludo = "Adios alumnos";
  Serial.println(saludo);
}

void loop() {
  // put your main code here, to run repeatedly:
  cuenta = cuenta + 1;
  Serial.println("El valor de cuenta es -> " + String(cuenta));
  delay(1000);
}
