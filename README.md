# pid-controller-emulated-feedback
This project implements a PI controller (Proportional-Integral) on an Arduino Uno. It controls a servo motor and an LED using an emulated plant – a first‑order lag that simulates sensor inertia. The goal is to demonstrate closed‑loop control principles without real sensors, making it ideal for learning and experimentation.
# PID Controller with Emulated Feedback (Arduino Uno)

This project implements a **PID (Proportional-Integral) controller** on an Arduino Uno R3. It controls a servo motor and an LED (PWM) based on an **emulated plant** – a first‑order lag system that simulates the inertia of a real sensor. The controller can be started, stopped, and reset using two push buttons. PID coefficients (Kp and Ki) are adjusted in real time via potentiometers.

The purpose is to demonstrate the principle of a closed‑loop control system without needing an actual physical sensor. It's ideal for learning, experimenting with PID tuning, or as a foundation for real automation projects.

## Author
- **Name:** Andrei Dykunets  
- **Aliases:** Andreas Agassias, christty  
- **GitHub:** https://github.com/Agassias 
- **Objective:** Aspiring to work at Apple as an instrumentation and automation specialist.

## Repository Contents
- `PID_emulated_feedback.ino` – main Arduino sketch
- `README.md` – this file  

## Requirements
- Arduino Uno R3 (or compatible)  
- Servo motor (e.g., SG90, MG996R)  
- 3x potentiometers (10 kΩ):  
  - Setpoint (desired value)  
  - Kp (proportional gain)  
  - Ki (integral gain)  
- 2x push buttons (Stop and Reset)  
- LED with current‑limiting resistor (~220 Ω)  
- OLED display is **not** used in this version – feedback is visualized via servo and LED.  
- Breadboard and jumper wires  
- Arduino IDE (with built‑in Servo library)

## Wiring / Pinout
| Component          | Arduino Pin | Notes                                    |
|--------------------|-------------|------------------------------------------|
| Servo signal       | 9           | PWM pin                                  |
| LED (PWM indicator)| 11          | PWM (brightness shows output level)      |
| Stop button        | 2           | Pull‑up internal; LOW when pressed       |
| Reset button       | 3           | Pull‑up internal; LOW when pressed       |
| Setpoint pot       | A0          | 0–1023 → desired servo angle (scaled)    |
| Kp pot             | A1          | 0–1023 → proportional gain (0…~20)       |
| Ki pot             | A2          | 0–1023 → integral gain (0…~0.5)          |

**Power:**  
- Servo VCC → 5V (or external power if high‑torque)  
- Servo GND → GND (common with Arduino)  
- LED anode → 11 (through resistor)  
- LED cathode → GND  
- Buttons: one leg to GND, the other to the respective pin (2 or 3)
