// Include libraries
#include <OneWire.h>
#include <DallasTemperature.h>

// Define pin to use with one wire
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensor (&oneWire);

float temperature;

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando Sensor de temperatura Dallas");
}

void loop() {
  sensor.requestTemperatures();
  temperature = sensor.getTempCByIndex(0);
  Serial.println("La temperatura es: " + String(temperature));
}
