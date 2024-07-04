# Turtle-Arduino-Controller

## Project Overview

This project involves creating a physical controller using Arduino, Python, and CAD design. The goal was to build an interactive system where the Arduino communicates with a Python-based software through serial communication to control  a software, which I created using the Turtle library. Additionally, I designed and manufactured a custom Arduino shield to house all the wiring and circuits.

### Components

1. **Arduino**: The microcontroller used to interface with the physical controller and handle serial communication with the Python software.
2. **Python**: Used to create a graphical interface using the Turtle library. The Python code reads serial data from the Arduino.
3. **Serial Communication**: Facilitates the data exchange between the Arduino and the Python software.
4. **CAD Design**: Designed the physical controller using OnShape, a CAD software.
5. **Arduino Shield**: A custom shield made from a blank board to manage all wiring and circuits, placed directly on top of the Arduino.

### Project Structure

- **Arduino Code**: The code to control the Arduino, manage inputs from the physical controller, and send data to the Python software.
- **Python Code**: The code to create a software using the Turtle library and read data from the Arduino via serial communication.
- **CAD Files**: Design files for the physical controller created using OnShape.

### Files

- **Arduino Code**: [Arduino_Code/arduino_code.ino.ino]
- **Python Code**: [Python_Code/python_code.py]
- **CAD Files**: [OnShape_Design]

### Installation

1. **Arduino Setup**:
    - Install the Arduino IDE from [Arduino's official website](https://www.arduino.cc/en/software).
    - Open the provided Arduino code file (`arduino_code.ino.ino`) in the Arduino IDE.
    - Connect your Arduino to your computer via USB and upload the code.

2. **Python Setup**:
    - Make sure you have Python installed on your system. You can download it from [Python's official website](https://www.python.org/downloads/).
    - Install the necessary Python libraries using pip:
      ```bash
      pip install pyserial
      pip install turtle
      ```
    - Run the provided Python code file (`python_code.py`).

3. **CAD Design**:
    - Open the provided CAD files in OnShape or any compatible CAD software to view or modify the physical controller design.

### Usage

1. Connect your physical controller to the Arduino.
2. Power on the Arduino and ensure it is connected to your computer via USB.
3. Run the Python script to start the software.
4. Interact with the physical controller and observe the software on the Turtle interface.

### Contributing

Feel free to fork this repository and submit pull requests. Any contributions, whether in the form of bug reports, feature requests, or code improvements, are welcome.


### Contact

For any questions or suggestions, please contact Arathana Nagarajah at nagarajah68@gmail.com.
