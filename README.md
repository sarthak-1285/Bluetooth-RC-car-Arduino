# 🚗 Bluetooth Controlled RC Car using Arduino

![Arduino](https://img.shields.io/badge/Arduino-Uno%2FNano-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue?style=for-the-badge&logo=cplusplus)
![Bluetooth](https://img.shields.io/badge/Bluetooth-HC--05%2FHC--06-0082FC?style=for-the-badge&logo=bluetooth)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)

A DIY Bluetooth-controlled RC car built using an **Arduino**, **L298N motor driver**, **two DC motors**, and an **HC-05/HC-06 Bluetooth module**. Control the car wirelessly from your smartphone using any Bluetooth RC controller app!

---

## 📸 Demo

> 📷 *(Add a photo or GIF of your RC car here)*

---

## ✨ Features

- 🔵 Wireless Bluetooth control from smartphone
- ⬆️ Forward, Backward, Left, Right movement
- 🎮 Speed control (10 levels: 0–9)
- 🛑 Instant Stop command
- ⚡ PWM-based smooth motor speed control
- 🔧 Simple and clean code — easy to modify

---

## 🧰 Components Required

| Component              | Quantity |
|------------------------|----------|
| Arduino Uno / Nano     | 1        |
| L298N Motor Driver     | 1        |
| DC Motors (with wheels)| 2        |
| HC-05 / HC-06 Bluetooth Module | 1 |
| Li-Po / 9V Battery     | 1        |
| Chassis + Wheels       | 1 set    |
| Jumper Wires           | As needed|

---

## 🔌 Circuit / Wiring

### L298N Motor Driver → Arduino

| L298N Pin | Arduino Pin | Description          |
|-----------|-------------|----------------------|
| ENA       | Pin 5 (PWM) | Left motor speed     |
| IN1       | Pin 6       | Left motor forward   |
| IN2       | Pin 7       | Left motor backward  |
| IN3       | Pin 8       | Right motor forward  |
| IN4       | Pin 9       | Right motor backward |
| ENB       | Pin 10 (PWM)| Right motor speed    |
| GND       | GND         | Common ground        |
| VCC       | 5V / Ext.   | Power supply         |

### HC-05/HC-06 Bluetooth → Arduino

| Bluetooth Pin | Arduino Pin | Description     |
|---------------|-------------|-----------------|
| VCC           | 5V          | Power           |
| GND           | GND         | Ground          |
| TX            | Pin 0 (RX)  | Serial receive  |
| RX            | Pin 1 (TX)  | Serial transmit |

> ⚠️ **Important:** Use a **voltage divider** on the BT RX pin (5V → 3.3V) if your module requires 3.3V logic. Also **disconnect the Bluetooth module before uploading code** — it shares RX/TX pins.

---

## 📱 Bluetooth App Commands

| Command | Action       |
|---------|--------------|
| `F`     | Move Forward |
| `B`     | Move Backward|
| `L`     | Turn Left    |
| `R`     | Turn Right   |
| `S`     | Stop         |
| `0`–`9` | Speed Level  |

### Recommended Apps
- 📱 **Arduino Bluetooth RC Car** (Android - Play Store)
- 📱 **Bluetooth RC Controller** (Android - Play Store)
- 📱 **Serial Bluetooth Terminal** (for manual testing)

---

## 📂 Project Structure

```
bluetooth-rc-car-arduino/
│
├── bluetooth_rc_car.ino   # Main Arduino source code
└── README.md              # Project documentation
```

---

## 🚀 How to Upload & Run

1. **Install Arduino IDE** from [arduino.cc](https://www.arduino.cc/en/software)
2. **Clone this repository:**
   ```bash
   git clone https://github.com/YOUR_USERNAME/bluetooth-rc-car-arduino.git
   ```
3. Open `bluetooth_rc_car.ino` in Arduino IDE
4. **Disconnect the Bluetooth module** from RX/TX pins
5. Select your board: `Tools → Board → Arduino Uno`
6. Select the correct port: `Tools → Port → COMX`
7. Click **Upload**
8. Reconnect the Bluetooth module after uploading
9. Pair your phone with **HC-05** (default password: `1234` or `0000`)
10. Open your RC app and **start driving!** 🚗💨

---

## ⚙️ How It Works

```
Smartphone App
     │
     │  (Bluetooth Signal: F / B / L / R / S / 0-9)
     ▼
HC-05 Bluetooth Module
     │
     │  (Serial Communication @ 9600 baud)
     ▼
Arduino Uno / Nano
     │
     │  (Digital & PWM Signals)
     ▼
L298N Motor Driver
     │
     ├──► Left DC Motor  (Forward / Backward)
     └──► Right DC Motor (Forward / Backward)
```

- The **smartphone app** sends single character commands over Bluetooth.
- The **HC-05 module** passes commands to Arduino via Serial (RX/TX).
- Arduino reads the command and drives the **L298N motor driver**.
- The **L298N** controls the direction and speed of both DC motors.

---

## 🛠️ Customization

- **Change default speed:** Edit `int motorSpeed = 180;` (range: 0–255)
- **Adjust turning behavior:** In `turnLeft()`/`turnRight()`, reduce one motor's PWM instead of reversing it for smoother turns
- **Add more commands:** Extend the `switch` statement in `executeCommand()` with new characters

---

## 🐛 Troubleshooting

| Problem | Solution |
|---------|----------|
| Car not moving | Check motor driver wiring and power supply |
| Bluetooth not pairing | Default PIN is `1234` or `0000` |
| Upload fails | Disconnect BT module before uploading |
| One motor goes wrong way | Swap IN1/IN2 or IN3/IN4 connections |
| Car moves but slow | Increase `motorSpeed` value or check battery |

---

## 📜 License

This project is licensed under the **MIT License** — feel free to use, modify, and share!

---

## 🙋‍♂️ Author

**Sarthak Gote**
- GitHub: [@sarthak-1285](https://github.com/YOUR_USERNAME)

---

## ⭐ Support

If you found this project helpful, please give it a **⭐ Star** on GitHub — it means a lot!

---

*Made with ❤️ and Arduino*
