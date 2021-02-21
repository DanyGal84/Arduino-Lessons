// Include libraries
#include <OneWire.h>
#include <DallasTemperature.h>

// Define pin to use with one wire
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensor (&oneWire);

int led = 6;
int button = 3;
int fan = 5;
float temperature;
bool fan_activated = false;
int temp_limit = 25;

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando Sistema Control Temperatura");

  pinMode(fan,OUTPUT);
  pinMode(led,OUTPUT);
}

void loop() {
  sensor.requestTemperatures();
  temperature = sensor.getTempCByIndex(0);
  // Serial.println("La temperatura es: " + String(temperature));

  if(temperature > temp_limit) {
    digitalWrite(fan,HIGH);
    digitalWrite(led,HIGH);
    fan_activated = true;
    Serial.println("Led Prendido -> " + String(temperature));
  } else {
    digitalWrite(fan,LOW);
    digitalWrite(led,LOW);
    fan_activated = false;
    Serial.println("Led Apagado -> " + String(temperature));
  }
}
