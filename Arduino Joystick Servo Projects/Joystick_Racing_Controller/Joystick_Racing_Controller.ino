#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  -1
);

Servo steeringServo;

const int joyX = A0;
const int joyY = A1;
const int servoPin = 9;

void setup() {

  steeringServo.attach(servoPin);

  if(!display.begin(
      SSD1306_SWITCHCAPVCC,
      0x3C))
  {
    while(1);
  }

  display.clearDisplay();
  display.display();
}

void loop() {

  int xValue = analogRead(joyX);
  int yValue = analogRead(joyY);

  // Steering Angle
  int angle = map(
      xValue,
      0,
      1023,
      0,
      180);

  steeringServo.write(angle);

  // Speed %
  int speedPercent = map(
      yValue,
      0,
      1023,
      0,
      100);

  // Direction
  String direction;

  if(xValue < 400)
    direction = "LEFT";
  else if(xValue > 600)
    direction = "RIGHT";
  else
    direction = "CENTER";

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(15,0);
  display.println("RACING MODE");

  display.setCursor(0,18);
  display.println("Steering:");

  display.setCursor(70,18);
  display.println(direction);

  display.setCursor(0,36);
  display.println("Speed:");

  display.setCursor(50,36);
  display.print(speedPercent);
  display.println("%");

  // Speed Bar
  display.drawRect(
      0,
      54,
      128,
      8,
      SSD1306_WHITE);

  int barWidth = map(
      speedPercent,
      0,
      100,
      0,
      126);

  display.fillRect(
      1,
      55,
      barWidth,
      6,
      SSD1306_WHITE);

  display.display();

  delay(20);
}