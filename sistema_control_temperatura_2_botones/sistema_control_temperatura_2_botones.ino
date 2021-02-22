// Include libraries
#include <OneWire.h>
#include <DallasTemperature.h>

// Includes to use display ssd1306
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
// If display dont use reset pin, add -1 in order to not waste one of your pins
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Define pin to use with one wire
#define ONE_WIRE_BUS 7
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensor(&oneWire);

char buffer_temps [SCREEN_WIDTH];
// Define pins
byte led = 6;
byte button_tmp_down = 2;
byte button_tmp_up = 3;

// Global Variables
float temperature;
bool led_activated = false;
byte temp_limit = 25;
bool limit_changed = false;

long previous_time_up;
long difference_up;

long previous_time_down;
long difference_down;

void setup() {
  // Fill array with alot values
  for(int i = 0; i < SCREEN_WIDTH; i++) {
    buffer_temps[i] = 110;
  }
  // Initialize the display for the AxAA address
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  Serial.begin(9600); // Serial port activation
  // Serial.println("Iniciando Sistema Control Temperatura");

  pinMode(led, OUTPUT); // Led pin as digital output

  // pullup  to button down, then activate interruption
  pinMode(button_tmp_down, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button_tmp_down), limit_down, FALLING);

  // pullup  to button up, then activate interruption
  pinMode(button_tmp_up, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button_tmp_up), limit_up, FALLING);

  draw_limit(temp_limit);
}

long counter1 = 0;

void loop() {
  if (millis() - counter1 > 1000)
  {
    counter1 = millis();
    sensor.requestTemperatures();
    temperature = sensor.getTempCByIndex(0);
    fill_buffer(temperature);
    ledAction();
    draw_temp(temperature);
    draw_grid();
    draw_curve();
  }

  if (limit_changed)
  {
    draw_limit(temp_limit);
    limit_changed = false;
  }
}

void ledAction() {
  if (temperature > temp_limit)
  {
    digitalWrite(led, HIGH);
    led_activated = true;
    // Serial.println("Led Prendido -> Temperatura actual: " + String(temperature) + " Celcius");
  }
  else
  {
    digitalWrite(led, LOW);
    led_activated = false;
    // Serial.println("Led Apagado -> Temperatura actual: " + String(temperature) + " Celsius");
  }
}

void limit_up(){
  difference_up = millis() - previous_time_up;
  previous_time_up = millis();

  if (difference_up > 250)
  {
    temp_limit++;
    limit_changed = true;
  }
}

void limit_down(){
  difference_down = millis() - previous_time_down;
  previous_time_down = millis();

  if (difference_down > 250)
  {
    temp_limit--;
    limit_changed = true;
  }
}

void draw_temp(float temp) {
  display.setTextColor(WHITE, BLACK);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("CT = " + String(temp, 1) + "C");
  display.display();
}

void draw_limit(int temp) {
  display.setTextColor(WHITE, BLACK);
  display.setTextSize(1);
  display.setCursor(64, 0);
  display.println("LT = " + String(temp) + "C");
  display.display();
}

void draw_grid() {
  display.fillRect(0,13,SCREEN_WIDTH,64,BLACK);
  // this for repeats each 10 vertical pixels the line of dots that generates the inside for
  for (int j = 13; j < 64; j = j + 10) {
    // This draws a line of dots
    for (int i = 0; i < SCREEN_WIDTH; i = i + 12) {
      display.drawPixel(i, j, WHITE);
    }

    if (j == 43) {
      for (int i = 0; i < SCREEN_WIDTH; i = i + 2) {
        display.drawPixel(i, j, WHITE);
      }
    }
  }
}

void draw_curve() {
  for (int i = 0; i < SCREEN_WIDTH; i++) {
    if(buffer_temps[i] < 109) {
      int y = map(buffer_temps[i], -10, 50, 64, 13);
      display.drawPixel(i, y, WHITE);
    }
  }
}

void fill_buffer(float temp) {
  for (int i = 1; i < SCREEN_WIDTH; i++) {
    buffer_temps[i-1] = buffer_temps[i];
  }
  buffer_temps[127] = temp;
}
