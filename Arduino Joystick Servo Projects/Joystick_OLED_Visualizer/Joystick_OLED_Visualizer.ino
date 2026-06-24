#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int xPin = A0;
const int yPin = A1;
const int swPin = 2;

void setup() {
  pinMode(swPin, INPUT_PULLUP);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);
  }

  display.clearDisplay();
  display.display();
}

void loop() {

  int xValue = analogRead(xPin);
  int yValue = analogRead(yPin);
  int swState = digitalRead(swPin);

  // Map joystick values to OLED coordinates
  int dotX = map(xValue, 0, 1023, 0, 127);
  int dotY = map(yValue, 0, 1023, 63, 0);

  display.clearDisplay();

  // Display values
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0, 0);
  display.print("X:");
  display.print(xValue);

  display.setCursor(0, 10);
  display.print("Y:");
  display.print(yValue);

  display.setCursor(0, 20);
  display.print("SW:");
  display.print(swState == LOW ? "PRESSED" : "RELEASED");

  // Coordinate Grid (Bonus)
  for (int x = 0; x < 128; x += 16) {
    display.drawFastVLine(x, 32, 32, SSD1306_WHITE);
  }

  for (int y = 32; y < 64; y += 8) {
    display.drawFastHLine(0, y, 128, SSD1306_WHITE);
  }

  // Draw moving dot
  display.fillCircle(dotX, dotY, 2, SSD1306_WHITE);

  display.display();

  delay(20);
}