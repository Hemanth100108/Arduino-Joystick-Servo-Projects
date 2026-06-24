#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Servo panServo;

const int joyX = A0;
const int servoPin = 9;

int angle = 90;
int lastAngle = -1;

void setup() {
  panServo.attach(servoPin);
  panServo.write(angle);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (1);
  }

  display.clearDisplay();
  display.display();
}

void loop() {

  int xValue = analogRead(joyX);

  // Smooth servo movement
  angle = map(xValue, 0, 1023, 0, 180);
  panServo.write(angle);

  if (abs(angle - lastAngle) > 1) {

    String direction;

    if (xValue < 450)
      direction = "LEFT";
    else if (xValue > 570)
      direction = "RIGHT";
    else
      direction = "CENTER";

    display.clearDisplay();

    display.setTextSize(1);
    display.setCursor(10, 0);
    display.println("Pan Controller");

    display.setCursor(0, 18);
    display.print("Angle: ");
    display.print(angle);
    display.println((char)247);

    display.setCursor(35, 35);
    display.println(direction);

    // Bonus: Direction Arrow
    if (direction == "LEFT") {
      display.fillTriangle(20, 50, 40, 42, 40, 58, SSD1306_WHITE);
    }
    else if (direction == "RIGHT") {
      display.fillTriangle(108, 50, 88, 42, 88, 58, SSD1306_WHITE);
    }
    else {
      display.fillRect(60, 44, 8, 12, SSD1306_WHITE);
    }

    display.display();

    lastAngle = angle;
  }
}