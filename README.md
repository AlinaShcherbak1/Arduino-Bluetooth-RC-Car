# Bluetooth RC Car on Arduino

This is a Bluetooth-controlled RC car based on Arduino UNO, HC-06 Bluetooth module and L298N motor driver.

## Features
- Remote control via Bluetooth using UART (TX/RX) communication between Arduino and HC-06 module at 9600 baud rate
- Supports commands: forward, backward, left, right, and stop
- L298N motor driver controls direction and speed of 4 DC motors via Arduino digital outputs
- Powered by 4 DC motors and motor driver

## Hardware
- Arduino UNO
- HC-06 Bluetooth module
- L298N Motor Driver
- 4 DC Motors
- Power supply (batteries/batteries)

## How to Use
1. Upload the `.ino` file to the Arduino UNO.
2. Connect your phone via Bluetooth to the HC-06 module.
3. Use the control app to move the car.

## Wiring Diagram
![schematic](https://github.com/user-attachments/assets/0bd83453-cc40-401e-b0e2-9d3baa82fc8e)


