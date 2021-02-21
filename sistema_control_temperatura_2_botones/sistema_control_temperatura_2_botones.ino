// Include libraries
#include <OneWire.h>
#include <DallasTemperature.h>

// Define pin to use with one wire
#define ONE_WIRE_BUS 7
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensor (&oneWire);

// Define pins
int led = 6;
int button_tmp_down = 2;
int button_tmp_up = 3;

// Global Variables
float temperature;
bool led_activated = false;
int temp_limit = 25;

long previous_time_up;
long difference_up;

long previous_time_down;
long difference_down;

long counter1 = 0;

void setup() {
  Serial.begin(9600); // Serial port activation
  delay(100);
  Serial.println("Iniciando Sistema Control Temperatura");

  pinMode(led,OUTPUT); // Led pin as digital output
  
  // pullup  to button down, then activate interruption
  pinMode(button_tmp_down,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button_tmp_down), limit_down, FALLING);

  // pullup  to button up, then activate interruption
  pinMode(button_tmp_up,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button_tmp_up), limit_up, FALLING);
}

void loop() {
  if(millis() - counter1 > 1000) {
    counter1 = millis();

    sensor.requestTemperatures();
    temperature = sensor.getTempCByIndex(0);
    ledAction();
  }
}

void ledAction() {
  if(temperature > temp_limit) {
    digitalWrite(led,HIGH);
    led_activated = true;
    Serial.println("Led Prendido -> Temperatura actual: " + String(temperature) + " Celcius");
  } else {
    digitalWrite(led,LOW);
    led_activated = false;
    Serial.println("Led Apagado -> Temperatura actual: " + String(temperature) + " Celsius");
  }
}

void limit_up() {
  difference_up = millis() - previous_time_up;
  previous_time_up = millis();

  if(difference_up > 250) {
    temp_limit++;
    Serial.println("Limite Subido a ->" + String(temp_limit));
  }
}

void limit_down() {
  difference_down = millis() - previous_time_down;
  previous_time_down = millis();

  if(difference_down > 250) {
    temp_limit--;
    Serial.println("Limite Bajado a ->" + String(temp_limit));
  }
}
