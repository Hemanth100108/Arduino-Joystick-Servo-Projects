# Arduino Joystick OLED Projects

## Objective

To develop and implement a collection of Arduino-based joystick-controlled projects that demonstrate analog input processing, OLED visualization, servo motor control, menu navigation, robotic movement, racing dashboards, and real-time user interaction.

This repository contains a collection of Arduino projects developed using Joystick Modules, SSD1306 OLED Displays, and SG90 Servo Motors.

---

## Projects Included

1. Joystick OLED Visualizer
2. Joystick Servo Control
3. Joystick Servo Preset Control
4. Joystick Servo Pan Controller
5. Joystick OLED Menu Controller
6. Racing Mode Controller

---

## Components Used

### Hardware

* Arduino Uno R3
* Joystick Module (KY-023)
* SSD1306 OLED Display (128×64)
* SG90 Servo Motor
* Breadboard
* Jumper Wires
* USB Cable

### Software

* Arduino IDE
* Wire Library
* Adafruit GFX Library
* Adafruit SSD1306 Library
* Servo Library

---

## Circuit Diagram

### OLED Connections

| OLED Pin | Arduino Uno |
| -------- | ----------- |
| VCC      | 5V          |
| GND      | GND         |
| SDA      | A4          |
| SCL      | A5          |

### Joystick Connections

| Joystick Pin | Arduino Uno |
| ------------ | ----------- |
| VCC          | 5V          |
| GND          | GND         |
| VRX          | A0          |
| VRY          | A1          |
| SW           | D2          |

### Servo Connections

| Servo Pin | Arduino Uno |
| --------- | ----------- |
| Signal    | D9          |
| VCC       | 5V          |
| GND       | GND         |

---

## Code Explanation

### Project 1 – Joystick OLED Visualizer

* Reads joystick X and Y axis values.
* Displays coordinates on the OLED.
* Draws a moving dot that follows joystick movement.
* Demonstrates real-time analog input visualization.

### Project 2 – Joystick Servo Control

* Controls an SG90 servo using joystick movement.
* Maps joystick values to servo angles.
* Displays servo angle and joystick value on OLED.
* Includes a graphical angle meter.

### Project 3 – Joystick Servo Preset Control

* Uses the joystick button to cycle through preset servo positions.
* Presets include 0°, 45°, 90°, 135°, and 180°.
* Displays the selected preset position on OLED.

### Project 4 – Joystick Servo Pan Controller

* Creates a camera or robot pan mechanism.
* Uses joystick X-axis for directional control.
* Displays servo angle and movement direction.
* Includes animated direction indicators.

### Project 5 – Joystick OLED Menu Controller

* Implements a menu navigation system.
* Uses joystick movement for scrolling.
* Uses joystick button for selection.
* Demonstrates embedded user interface development.

### Project 6 – Racing Mode Controller

* Simulates a racing dashboard.
* Uses joystick X-axis for steering.
* Uses joystick Y-axis as a speed controller.
* Displays steering direction and speed percentage.
* Demonstrates real-time dashboard visualization.

---

## Output Images

### Joystick OLED Visualizer

<img width="1600" height="1200" alt="WhatsApp Image 2026-06-24 at 6 31 58 AM" src="https://github.com/user-attachments/assets/a5ce2e8d-3524-4bfb-a1d3-2e60cd170e90" />


### Joystick Servo Control

<img width="1600" height="1200" alt="WhatsApp Image 2026-06-24 at 6 31 58 AM (1)" src="https://github.com/user-attachments/assets/021aabc7-75eb-4aac-94cd-1fb352d6335d" />


### Joystick Servo Preset Control

<img width="1600" height="1200" alt="WhatsApp Image 2026-06-24 at 6 31 58 AM" src="https://github.com/user-attachments/assets/f9323ded-1072-4a87-a2d1-643d47fce7af" />
<img width="1600" height="1200" alt="WhatsApp Image 2026-06-24 at 6 31 59 AM" src="https://github.com/user-attachments/assets/e577cf49-6677-4adf-bc38-d5644271f7e9" />


### Joystick Servo Pan Controller

<img width="1600" height="1200" alt="WhatsApp Image 2026-06-24 at 6 32 00 AM" src="https://github.com/user-attachments/assets/e679f2e8-359e-4149-850d-3a2817a4303a" />
<img width="1600" height="1200" alt="WhatsApp Image 2026-06-24 at 6 31 59 AM" src="https://github.com/user-attachments/assets/07eaa46d-f8b7-44f0-adac-97e287ac33e2" />


### Joystick OLED Menu Controller

<img width="1600" height="1200" alt="WhatsApp Image 2026-06-24 at 6 32 00 AM" src="https://github.com/user-attachments/assets/756aad7f-f16f-4c9c-ae79-9ad1ca9bfb92" />


### Racing Mode Controller

<img width="1600" height="1200" alt="WhatsApp Image 2026-06-24 at 6 32 01 AM" src="https://github.com/user-attachments/assets/9a748b4d-b109-4751-8347-1e9a169072c3" />


## Learning Outcome

Through these projects, the following concepts were learned:

* Arduino Programming Fundamentals
* Analog Input Processing
* Joystick Module Interfacing
* OLED Display Interfacing
* Servo Motor Control
* PWM Signal Generation
* Real-Time Data Visualization
* Embedded User Interface Design
* Menu Navigation Systems
* Robotic Motion Control
* Interactive Dashboard Design
* Hardware and Software Integration
* Problem Solving using Arduino

---

Hemanth A S
