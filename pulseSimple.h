#ifndef pulseSimple_h
#define pulseSimple_h

#include <Arduino.h>

class pulseSimple {
public:
    pulseSimple(int pulsePin, int tresholdValue) {
        this->pulsePin = pulsePin;
        this->tresholdValue = tresholdValue;
    }

    void begin() {
        pinMode(pulsePin, INPUT);
    }

    void hitungTreshold() {
        int totalReading = 0;
        int numReadings = 50;

        for (int i = 0; i < numReadings; i++) {
            totalReading += analogRead(pulsePin);
            delay(50);
        }

        tresholdValue = totalReading / numReadings;
    }

    bool deteksiSentuh(int toleransi) {
        return (analogRead(pulsePin) - tresholdValue) >= toleransi;
    }

    int hitungBpm() {
        int totalPulse = 0;
        int numReadings = 100;

        for (int i = 0; i < numReadings; i++) {
            int reading = analogRead(pulsePin);
            if (reading > 0) {
                totalPulse += reading;
            } else {
                numReadings--;
            }
            delay(100);
        }

        if (numReadings > 0) {
            return (totalPulse / numReadings) / 10;
        } else {
            return 0;
        }
    }

private:
    int pulsePin;
    int tresholdValue;
};

#endif