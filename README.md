# Alarm-Timer
A simple arduino-based alarm timer using a 4-digit-7 segment display and an active buzzer, with real-time countdown functionality. Displays a countdown and triggers an alarm sound when the timer reaches zero

## Features
- Countdown timer display
- Audible alarm with buzzer at the end of countdown
- Uses SevSeg library for 7-segment display multiplexing

## Components Used
- Arduino Nano
- 4-Digit 7-Segment Display
- Active Buzzer
- Resistors
- Breadboard and jumper wires

## How It Works
The user sets a countdown time. The Arduino handles the countdown logic and updates the 7-segment display accordingly. When the timer reaches zero, the buzzer sounds for one second with 100ms intervals.

## Libraries Used
- [SevSeg](https://github.com/DeanIsMe/SevSeg)

## Setup
1. Connect the display and buzzer according to the wiring diagram.
2. Upload `AlarmTimer.ino` to your Arduino Nano.
3. Start the timer!

## License
MIT License

Feel free to tweak the code as you wish!

