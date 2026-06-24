#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int joyY = A1;
const int swPin = 2;

String menuItems[] = {
  "Servo",
  "OLED Test",
  "About",
  "Exit"
};

const int menuCount = 4;
int selectedItem = 0;

bool lastButtonState = HIGH;

void drawMenu() {

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(25, 0);
  display.println("MAIN MENU");

  for (int i = 0; i < menuCount; i++) {

    if (i == selectedItem) {
      display.fillRect(0, 16 + i * 12, 128, 10, SSD1306_WHITE);
      display.setTextColor(BLACK);
      display.setCursor(10, 18 + i * 12);
      display.println(menuItems[i]);
      display.setTextColor(WHITE);
    }
    else {
      display.setCursor(10, 18 + i * 12);
      display.println(menuItems[i]);
    }
  }

  display.display();
}

void showPage(String item) {

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 20);

  if (item == "Servo") {
    display.println("Servo Menu");
  }
  else if (item == "OLED Test") {
    display.println("OLED Working!");
  }
  else if (item == "About") {
    display.println("Arduino OLED");
    display.println("Menu System");
  }
  else if (item == "Exit") {
    display.println("Good Bye!");
  }

  display.display();
  delay(1500);

  drawMenu();
}

void setup() {

  pinMode(swPin, INPUT_PULLUP);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (1);
  }

  drawMenu();
}

void loop() {

  int yValue = analogRead(joyY);

  // Move Up
  if (yValue < 300) {
    selectedItem--;

    if (selectedItem < 0)
      selectedItem = menuCount - 1;

    drawMenu();
    delay(200);
  }

  // Move Down
  if (yValue > 700) {
    selectedItem++;

    if (selectedItem >= menuCount)
      selectedItem = 0;

    drawMenu();
    delay(200);
  }

  // Select Item
  bool buttonState = digitalRead(swPin);

  if (lastButtonState == HIGH && buttonState == LOW) {
    showPage(menuItems[selectedItem]);
  }

  lastButtonState = buttonState;
}