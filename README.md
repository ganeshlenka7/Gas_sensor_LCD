# ⛽ Gas Leak Detection & Alert System with I2C LCD

This Arduino project monitors gas levels using an **analog + digital gas sensor** and displays live readings on a **16x2 I2C LCD**. It includes a **bar graph visualization**, **custom emojis**, and a **blinking gas alert system** when gas concentration rises above safe limits.

---

## 🧠 Features

* 📟 Real-time analog gas value display
* 📊 Live bar graph of sensor strength (0–10 blocks)
* ⛽ Custom LCD icons for gas, smiley, and skull
* ⚠️ Blinking **“GAS ALERT!”** message when gas is detected
* 😀 “Safe” message when readings are normal
* 💀 Visual skull warning on danger

---

## 🧰 Components Required

| Component                      | Quantity | Description         |
| ------------------------------ | -------- | ------------------- |
| Arduino Uno                    | 1        | Main controller     |
| Gas Sensor (e.g., MQ-2 / MQ-5) | 1        | Detects gas leakage |
| 16x2 LCD with I2C Backpack     | 1        | Displays readings   |
| Jumper Wires                   | —        | For connections     |

---

## ⚡ Circuit Diagram

![Circuit Diagram](Gas_sensor_LCD.png)

---

## 🔌 Circuit Connections

| Gas Sensor Pin   | Arduino Pin |
| ---------------- | ----------- |
| VCC              | 5V          |
| GND              | GND         |
| A0 (Analog Out)  | A0          |
| D0 (Digital Out) | D2          |

| LCD Pin | Arduino Pin |
| ------- | ----------- |
| SDA     | SDA         |
| SCL     | SCL         |

---

## ⚙️ Libraries Used

Install via **Arduino IDE → Library Manager**:

* **LiquidCrystal_I2C** by Frank de Brabander

---

## 💾 Code Overview

* Reads analog and digital signals from the gas sensor.
* Displays analog value and bar graph on LCD.
* If the digital signal = HIGH → gas detected → blinking **“GAS ALERT!”**.
* Otherwise shows **“Safe 😀”**.
* Uses **custom emojis** for a professional UI experience.

---

## 📸 Sample LCD Output

```
⛽ A:452 ██████    
D:1 GAS ALERT! 💀
```

or when safe:

```
⛽ A:122 ██        
D:0 Safe 😀
```
