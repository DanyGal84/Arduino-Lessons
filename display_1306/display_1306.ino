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

void setup() {
  Serial.begin(9600);
  // Initialize the display for the AxAA address
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  // This generates the splash screen (Adafruit logo at the begining)
  // display.display();
  // delay(2000);

  // delete display
  display.clearDisplay();

  // Draw a pixel in position X Y COLOR
  // display.drawPixel(64, 33, WHITE);

  // Draw a rectangle in start X Y Width Height COLOR
  // display.drawRect(0, 0, 120, 60, WHITE);
  // display.drawRect(5, 5, 110, 50, WHITE);
  // display.drawRect(10, 10, 100, 40, WHITE);

  // Draw a filled rectangle in start X Y Width Height COLOR
  // display.fillRect(0,0,120,60,WHITE);
  // display.drawRect(5,5,110,50,BLACK);
  // display.drawRect(10,10,100,40,BLACK);

  // Draw a rounded border rectangle X Y Width Height Radius COLOR
  // display.drawRoundRect(0, 0, 120, 60, 20, WHITE);

  // Draw a rounded border filled rectangle X Y Width Height Radius COLOR
  // display.fillRoundRect(0, 0, 120, 60, 20, WHITE);

  // Draw a triangle verix1 X Y  vertix2 X Y vertix3 X Y COLOR
  // display.drawTriangle(10, 10, 45, 60, 60, 60, WHITE);

  // Draw a filled triangle verix1 X Y  vertix2 X Y vertix3 X Y COLOR
  // display.fillTriangle(10, 10, 45, 60, 60, 60, WHITE);

  // display.fillRect(0,0,127,63,WHITE);
  display.setTextSize(1);
  display.setTextColor(BLACK, WHITE);
  display.setCursor(0,0);
  display.println("Hola,");
  display.println("chiquitin");
  display.display();
}

void loop() {
  // put your main code here, to run repeatedly:
}
