// Creo variable para tal o cual cosa
int edades [5];
int dinero_en_cuenta [] = {12, 50, 66};
char mensaje [10] = "hola";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(100);

  dinero_en_cuenta[0] = 10;
  dinero_en_cuenta[8] = 51;

  int resultado = dinero_en_cuenta[0] + dinero_en_cuenta[8];

  Serial.println (String(resultado);
}

void loop() {
  // put your main code here, to run repeatedly:

}