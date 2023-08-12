# pulseSimple Library

<p align="center"></p>

**pulseSimple** is a simple Arduino library for detecting pulse and measuring heart rate using a heart rate sensor.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

## Installation

1. Download the **pulseSimple** library by clicking the "Code" button above and selecting "Download ZIP".
2. Open the Arduino IDE.
3. Go to "Sketch" > "Include Library" > "Add .ZIP Library..."
4. Select the downloaded ZIP file.

## Usage

1. Connect the heart rate sensor to the appropriate pins on your Arduino or ESP8266.
2. Include the `pulseSimple.h` library in your Arduino sketch.
3. Create an instance of the `pulseSimple` class, specifying the pulse sensor pin and threshold value.
4. Call the `begin()` and `hitungTreshold()` methods to initialize the sensor and calculate the threshold.
5. Use the `deteksiSentuh()` method to detect a pulse, and the `hitungBpm()` method to measure the heart rate.

## Examples

```cpp
#include <Arduino.h>
#include <pulseSimple.h>

const int pulsePin = A0; // Pin for pulse sensor
const int tresholdValue = 100; // Threshold value
const int toleransi = 70; // Tolerance value

pulseSimple pulseSensor(pulsePin, tresholdValue);

void setup() {
    Serial.begin(115200);
    pulseSensor.begin();
    pulseSensor.hitungTreshold();
    Serial.println("Pulse Detection Example");
}

void loop() {
    if (pulseSensor.deteksiSentuh(toleransi)) {
        int bpm = pulseSensor.hitungBpm();
        Serial.print("Detected pulse! BPM: ");
        Serial.println(bpm);
        // Do something with BPM value
    }
}
