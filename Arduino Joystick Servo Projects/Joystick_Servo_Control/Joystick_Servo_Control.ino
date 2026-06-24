#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Servo myServo;

const int joystickX = A0;
const int servoPin = 9;

int lastAngle = -1;

void setup() {
  myServo.attach(servoPin);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (1);
  }

  display.clearDisplay();
  display.display();
}

void loop() {

  int xValue = analogRead(joystickX);

  // Map joystick directly to angle
  int angle = map(xValue, 0, 1023, 0, 180);

  // Update only if angle changes
  if (angle != lastAngle) {

    myServo.write(angle);
    lastAngle = angle;

    display.clearDisplay();

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(0, 0);
    display.println("Servo Control");

    display.setCursor(0, 18);
    display.print("Angle: ");
    display.print(angle);
    display.println((char)247);

    display.setCursor(0, 32);
    display.print("X: ");
    display.println(xValue);

    // Angle meter
    display.drawRect(0, 50, 128, 10, SSD1306_WHITE);

    int barWidth = map(angle, 0, 180, 0, 126);
    display.fillRect(1, 51, barWidth, 8, SSD1306_WHITE);

    display.display();
  }
}