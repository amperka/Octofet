// Two libraries have to be included
// to work with the module. Download on
// https://amperka.com/my/octofet
#include <Octofet.h>
#include <SPI.h>

constexpr auto pinCS = 10;
constexpr auto deviceCount = 3;

// Create an object of Octofet type
// to communicate with Octofet board via hardware SPI
Octofet octofet(pinCS, deviceCount);

// If software SPI needed
// add MOSI and SCK pins numbers, like this:
// constexpr auto pinMOSI = 7;
// constexpr auto pinSCK = 5;
// Octofet octofet(pinCS, pinMOSI , pinSCK, deviceCount);

void setup() {
    // Start the board for communication
    octofet.begin();
}

void loop() {
    // Set the "on" state for every switches of every device one by one
    for (int t = 0; t < deviceCount; t++) {
        for (int i = 0; i < 8; i++) {
            octofet.digitalWrite(i, HIGH, t);
            delay(1000);
        }
    }
    // Similarly, set switches to "off" state
    for (int t = 0; t < deviceCount; t++) {
        for (int i = 0; i < 8; i++) {
            octofet.digitalWrite(i, LOW, t);
            delay(1000);
        }
    }
}
