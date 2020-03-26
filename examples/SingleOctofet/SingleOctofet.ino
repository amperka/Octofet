// Two libraries have to be included
// to work with the module. Download at
// https://amperka.com/my/octofet
#include <Octofet.h>
#include <SPI.h>

// any GPIO pin can be used as pinCS
constexpr auto pinCS = 10;

// Create an object of Octofet type
// to communicate with Octofet board via hardware SPI
Octofet octofet(pinCS);

// If software SPI needed
// add MOSI and SCK pins numbers, like this:

// constexpr auto pinMOSI = 7;
// constexpr auto pinSCK = 5;
// any GPIO pins can be used as pinMOSI and pinSCK
// Octofet octofet(pinCS, pinMOSI, pinSCK);

void setup() {
    // Start the board for communication
    octofet.begin();
}

void loop() {
    // Set each power switch to "on" state
    // one by one with 1 second interval
    for (int i = 0; i < 8; i++) {
        octofet.digitalWrite(i, HIGH);
        delay(1000);
    }
    // Similarly, set switches to "off" state
    for (int i = 0; i < 8; i++) {
        octofet.digitalWrite(i, LOW);
        delay(1000);
    }
    // Set all power switches at once with one method
    // One bit for one channel: 1 is "on" and 0 is "off"
    // channels 0, 2, 4, 6 to "on" state
    // channels 1, 3, 5, 7 continue to "off" state
    octofet.digitalWrite8(0b01010101);
    delay(1000);
    // Set all of 8 power switches at once to "off" state
    octofet.digitalWrite8(0b00000000);
    delay(1000);
}
