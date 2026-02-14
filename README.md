# VL53L0X Proximity Motor Control

A compact, battery-powered Arduino project that activates a vibration motor when an object comes within 200mm of the VL53L0X time-of-flight distance sensor. Perfect for wearable projects, proximity alerts, or interactive installations.

## Features

- Non-contact distance measurement up to ~2000mm
- Automatic vibration motor activation when object is detected within 200mm
- Battery-powered and portable (3.7V Li-Po with TP4056 charging module)
- Low power consumption with Arduino Pro Mini
- Serial output for real-time distance monitoring
- 10Hz update rate (100ms delay)

## Hardware Requirements

### Components List
- Arduino Pro Mini or Nano (1 pc)
- VL53L0X Time-of-Flight distance sensor (1 pc)
- 3V vibration motor (1 pc)
- 2N2222 NPN transistor (or S8050/BC337) (1 pc)
- 1kΩ resistor (1 pc)
- 1N4148 diode (1 pc)
- 3.7V Li-Po battery 300-500mAh (1 pc)
- TP4056 charging and protection module (1 pc)
- ON/OFF switch (1 pc)
- Jumper wires

## Wiring

### VL53L0X Sensor
- VCC → 3.3V (Arduino)
- GND → GND
- SDA → A4 (on Pro Mini/Nano)
- SCL → A5 (on Pro Mini/Nano)

### Vibration Motor Circuit (NPN Transistor)
```
Arduino Pin 9 → 1kΩ Resistor → Base (2N2222)
Emitter (2N2222) → GND
Collector (2N2222) → Vibration Motor (-)
Vibration Motor (+) → VCC (3.7V)
1N4148 Diode across motor (cathode to +, anode to -)
```

**Circuit Diagram:**
```
         +3.7V
           |
           +--- Motor (+)
           |       |
         [1N4148]  |
           |       |
           +-------+--- Collector (2N2222)
                   |
                Emitter --- GND
                   |
Pin 9 ---[1kΩ]--- Base
```

### Power Supply
```
Li-Po Battery (3.7V) → TP4056 Module → Switch → Arduino VCC/GND
                                              ↘ Motor Circuit VCC
```

**Note:** The 1N4148 diode protects the transistor from voltage spikes when the motor turns off (flyback diode).

## Software Requirements

### Libraries
Install via Arduino Library Manager:
- `Adafruit_VL53L0X`
- `Wire` (included with Arduino IDE)

## Installation

1. Clone this repository:
```bash
git clone https://github.com/yourusername/vl53l0x-motor-control.git
```

2. Open the `.ino` file in Arduino IDE

3. Install required libraries (see above)

4. Connect your hardware

5. Upload to your Arduino board

## Usage

1. Power on the Arduino
2. Open Serial Monitor (9600 baud) to view distance readings
3. Move objects near the sensor
4. Motor activates when distance < 200mm

## Configuration

Adjust the trigger distance by modifying this line:
```cpp
const int distanceLimit = 200; // Distance in millimeters
```

Change the motor control pin:
```cpp
const int motorPin = 9; // Any digital pin
```

## Troubleshooting

- **"Error connect VL53L0X"**: Check I2C wiring (SDA/SCL), ensure sensor has power (3.3V)
- **Motor doesn't vibrate**: Verify transistor connections, check battery charge level
- **Erratic readings**: Ensure sensor has clear line of sight, avoid reflective surfaces
- **Battery drains quickly**: Check for short circuits, consider adding sleep mode in code
- **Motor vibrates weakly**: Battery may be low, check TP4056 charge status LED

## License

MIT License - feel free to use and modify!

## Contributing

Pull requests welcome! Feel free to open issues for bugs or feature requests.