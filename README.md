# Arduino Distance Indicator — IoT Project

An Arduino-based distance-measurement project that combines an ultrasonic sensor, a seven-segment display, and three LEDs to provide a visual proximity indicator.

## Overview

This repository contains the Arduino project and supporting material used in an IoT workshop presented by **Yousef and Reem**. The Arduino sketch measures distance using an ultrasonic sensor, converts the result to inches, displays the measured value on a single-digit seven-segment display, and activates LEDs according to distance thresholds.

## How It Works

The sketch uses:

- An ultrasonic sensor connected through trigger and echo pins
- A one-digit common-cathode seven-segment display
- Green, yellow, and red LEDs
- The `SevenSeg.h` Arduino library

The configured maximum distance is 10 inches.

As an object gets closer:

- Green turns on below 10 inches
- Yellow turns on below roughly 6.6 inches
- Red turns on below roughly 3.3 inches

Because each threshold is evaluated independently, multiple LEDs can be illuminated at the same time.

## Hardware / Pin Configuration

```text
Ultrasonic trigger: pin 3
Ultrasonic echo:    pin 2

Green LED:          pin 7
Yellow LED:         pin 8
Red LED:            pin 6

Seven-segment pins: 4, 5, 10, 11, 12, 13, 9
```

## Requirements

- Arduino-compatible board
- Ultrasonic distance sensor
- Common-cathode seven-segment display
- Green, yellow, and red LEDs
- Appropriate resistors and wiring
- Arduino IDE
- `SevenSeg.h` library

## Setup

1. Build the circuit according to the pin mapping above.
2. Install the Arduino IDE.
3. Install the library that provides `SevenSeg.h`.
4. Open `Code.ino`.
5. Select the correct Arduino board and serial port.
6. Upload the sketch.

A document named `How to upload Code to Arduino.docx` is also included in the repository.

## Repository Contents

```text
IoT/
├── Code.ino
├── How to upload Code to Arduino.docx
├── image.png
└── README.md
```

## Project Context

This project was created as a hands-on workshop demonstration. It introduces basic IoT and embedded concepts: reading sensor data, converting physical measurements into digital values, controlling visual outputs, and presenting data through a simple display.


# Important links
- IDE: https://www.arduino.cc/en/software
- Circuit: https://www.circuito.io/
 
