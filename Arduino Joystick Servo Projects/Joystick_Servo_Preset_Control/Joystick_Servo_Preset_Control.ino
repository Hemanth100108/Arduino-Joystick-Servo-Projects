#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Servo myServo;

const int swPin = 2;
const int servoPin = 9;

int positions[] = {0, 45, 90, 135, 180};
int currentPreset = 0;

bool lastButtonState = HIGH;

void setup() {
  pinMode(swPin, INPUT_PULLUP);

  myServo.attach(servoPin);
  myServo.write(positions[currentPreset]);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (1);
  }

  updateDisplay();
}

void loop() {

  bool buttonState = digitalRead(swPin);

  // Detect button press
  if (lastButtonState == HIGH && buttonState == LOW) {

    currentPreset++;
    if (currentPreset > 4)
      currentPreset = 0;

    myServo.write(positions[currentPreset]);

    updateDisplay();

    delay(200); // debounce
  }

  lastButtonState = buttonState;
}

void updateDisplay() {

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(20, 5);
  display.println("Preset Mode");

  display.setCursor(15, 25);
  display.println("Position:");

  display.setTextSize(2);
  display.setCursor(40, 45);
  display.print(positions[currentPreset]);
  display.print((char)247);

  display.display();
}