# Streaming Serial Data & INA219 Current Sensor Project

## Overview
This repository contains two programs:

1. **Streaming_Serial_Data**: A Jupyter Notebook to stream serial data.
2. **currentINA219.ino**: An Arduino sketch that reads current data from the INA219 sensor and sends it via serial communication.

---

## Table of Contents
- [Overview](#overview)
- [Project Features](#project-features)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Code Details](#code-details)
  - [Streaming_Serial_Data.ipynb](#streaming_serial_datainb)
  - [currentINA219.ino](#currentina219ino)
- [Contributing](#contributing)
- [Author](#author)

---

## Project Features
- Real-time current measurement using the **INA219 sensor**.
- Data transmission through serial communication.
- Data visualization and analysis using Jupyter Notebook.

---

## Hardware Requirements
- **Arduino** (e.g., Arduino Nano, Uno etc.)
- **INA219 Current Sensor Module**
- Breadboard and Jumper Wires
- Power Source
- USB Cable for communication with a PC

---

## Software Requirements
- **Arduino IDE** (for `.ino` files)
- **Python Environment** with:
  - `pyserial` library
  - `pandas` for data handling
  - `matplotlib` for visualization
- Jupyter Notebook (for running the streaming notebook)

---

## Installation

### Arduino Program
1. Install the **Arduino IDE**: [Download Here](https://www.arduino.cc/en/software).
2. Install the **Adafruit INA219 Library** from the Arduino Library Manager.
3. Connect your Arduino board to the PC using a USB cable.
4. Open `currentINA219.ino` in the Arduino IDE.
5. Upload the sketch to the Arduino.

### Python Setup
1. Install Python 3.8+.
2. Install required libraries:
   ```bash
   pip install pyserial pandas matplotlib notebook
   ```

## Usage

### Hardware Connections
1. Connect the INA219 sensor to the Arduino:
   - **VCC** → 5V
   - **GND** → GND
   - **SCL** → A5 (SCL pin on Arduino)
   - **SDA** → A4 (SDA pin on Arduino)
2. Ensure the load is connected to the INA219 sensor for current measurement.

### Running the Programs
1. **Arduino Program**: Upload `currentINA219.ino` to the Arduino. It starts sending current readings over the serial port.
2. **Python Program**:
   - Launch `Streaming_Serial_Data.ipynb`.
   - Ensure the correct COM port is set to read data from the Arduino.
   - Run the notebook to stream and visualize the data.

---

## Code Details

### `Streaming_Serial_Data.ipynb`
- Reads real-time data from the serial port.
- Visualizes the incoming current measurements.
- Includes options for data logging into CSV files.

### `currentINA219.ino`
- Configures the INA219 sensor for current measurement.
- Reads data at intervals.
- Sends the data via the serial port for further processing.

---

## Contributing
Feel free to contribute to improve or expand this project. Fork the repository, make changes, and submit a pull request.

---

## Author
For questions or suggestions, contact:
-  Raghav Sharma
-  Mohammad Saifullah
   
