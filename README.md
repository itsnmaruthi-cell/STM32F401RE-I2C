# 🌡️ STM32 Temperature & Humidity Monitor

> Register-level embedded firmware for STM32 Nucleo F401RE — reads DHT11 sensor data and displays it on an SSD1306 OLED display with UART serial output. No HAL library used for peripheral configuration.

---

## 📸 Demo


<img width="1600" height="921" alt="image" src="https://github.com/user-attachments/assets/1b15bed5-76e1-47d1-8180-45fef5a094b8" />


---

## ⚙️ Features

- Press onboard button → instantly reads temperature & humidity
- Live data displayed on 128x64 OLED screen
- Simultaneous serial output to PC terminal via UART
- Fully register-level implementation — no STM32 HAL for peripherals
- Checksum verification on every DHT11 read with auto-retry

---

## 🛠️ Hardware

| Component | Role |
|---|---|
| STM32 Nucleo F401RE | Main microcontroller |
| DHT11 Sensor | Temperature & humidity measurement |
| SSD1306 OLED 128x64 | Display output |
| PC Terminal | Live serial monitor |

---

## 🔌 Pin Connections

**OLED (SSD1306 — I2C)**
| OLED | Nucleo |
|---|---|
| VDD | 3.3V |
| GND | GND |
| SCK | PB6 |
| SDA | PB7 |

**DHT11**
| DHT11 | Nucleo |
|---|---|
| VCC | 3.3V |
| DATA | PB2 |
| GND | GND |

**User Button → PC13 (active LOW)**

---

## 📡 Protocols Used

| Protocol | Used For |
|---|---|
| I2C | SSD1306 OLED display |
| Single-Wire | DHT11 sensor communication |
| UART | Serial output to PC (9600 baud) |

MCU measures pulse widths to decode bits
↓
Checksum verified → temperature & humidity extracted
↓
OLED displays:        UART sends:
Temp: 33C    →    Temp: 33C  Hum: 50%
Hum:  50%
---

## 💻 Implementation Highlights

### Register-Level Peripheral Setup
All peripherals configured directly via memory-mapped registers — no HAL abstraction layer. This includes RCC clock enables, GPIO mode/type/alternate function registers, I2C timing registers, USART baud rate, and TIM2 prescaler.

### I2C1 Driver (PB6/PB7)
Built from scratch using STM32F401 reference manual:
- START condition via CR1 bit 8, polled via SR1 SB flag
- 7-bit address transmission with ADDR flag polling
- Byte writes with TXE (bit 7) and BTF (bit 2) flag polling
- STOP condition via CR1 bit 9

### SSD1306 OLED Driver
- 26-command initialization sequence
- Full GDRAM clear (1024 bytes over I2C)
- Page/column cursor positioning
- Custom 5×7 ASCII font table — each character is 5 bytes of vertical pixel data

### DHT11 Single-Wire Driver
- 18ms LOW start pulse generated via TIM2 microsecond delay
- Bit decoding via HIGH pulse-width measurement (threshold ~14µs)
- 40-bit read: humidity integer, humidity decimal, temp integer, temp decimal, checksum
- Checksum verification with retry on failure

### TIM2 — Microsecond Delay
- Free-running counter at 1MHz (PSC = 15 at 16MHz HSI clock)
- Used exclusively for DHT11 timing accuracy

### USART2 (PA2/PA3)
- 9600 baud, 8N1
- Polling-based TX using TXE flag
- Sends formatted string on every successful read

---

## 📁 Project Structure
---

## 🔧 Tools & Environment

- STM32CubeIDE
- STM32F401RE Reference Manual
- STM32 Nucleo F401RE board

---

## 📚 What I Learned

- I2C protocol implementation at register level — START, address, data, STOP
- SSD1306 GDRAM organization — 8 pages × 128 columns × 8 pixels per byte
- Single-wire timing protocols and hardware timer-based microsecond delays
- Translating datasheet register descriptions into working firmware
- Hardware debugging using CubeIDE debugger and OLED as a debug output device

---

## 🔗 Related

This project is part of my embedded systems learning roadmap covering:
GPIO → Timers → UART → I2C → SPI → Sensor Integration
---


