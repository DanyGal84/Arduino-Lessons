int green_led = 3;
int onboard_led = 13;
int tiempo_encendido = 100;
int tiempo_apagado = 500;

void setup() {
  // put your setup code here, to run once:

  pinMode(green_led,OUTPUT); // Función que sirve para determinar el número de pin si se va a utilizar de entrada o salida
  pinMode(onboard_led,OUTPUT); // El pin 13 ya tiene un led la placa arduino
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(onboard_led,HIGH); // enciende led
  delay(tiempo_encendido);  // espera con led 1 segundo
  digitalWrite(onboard_led,LOW); // apaga led
  delay(tiempo_apagado); // espera con el led apagado

  digitalWrite(green_led,HIGH); // enciende led
  delay(tiempo_encendido);  // espera con led 1 segundo
  digitalWrite(green_led,LOW); // apaga led
  delay(tiempo_apagado); // espera con el led apagado
}
