#include <Arduino.h>
#include <pulseSimple.h>

const int pulsePin = A0; // Contoh pin untuk sensor denyut jantung
const int tresholdValue = 100; // Nilai ambang batas
const int toleransi = 70; // Nilai toleransi yang digunakan

pulseSimple deteksiPulse(pulsePin, tresholdValue);

void setup() {
    Serial.begin(115200);
    
    deteksiPulse.begin();
    deteksiPulse.hitungTreshold();
    
    Serial.println("Pulse Detection Example");
}

void loop() {
    if (deteksiPulse.deteksiSentuh(toleransi)) { // Menggunakan toleransi sebagai argumen
        int bpm = deteksiPulse.hitungBpm();
        Serial.print("Detected pulse! BPM: ");
        Serial.println(bpm);
        // Lakukan sesuatu dengan nilai bpm
    }

    // Lanjutkan dengan kode lain
    delay(1000);
}
