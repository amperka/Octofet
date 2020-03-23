#ifndef __OCTOFET_H__
#define __OCTOFET_H__

#include "spi2parallel.h"
#include <Arduino.h>
#include <SPI.h>

class Octofet {
public:
    Octofet(uint8_t pinCS, uint8_t deviceCount = 1);
    Octofet(uint8_t pinCS, uint8_t pinMOSI, uint8_t pinSCK, uint8_t deviceCount = 1);
    void begin();
    void digitalWrite(uint8_t channel, bool value, uint8_t device = 0);
    void digitalWrite8(uint8_t value, uint8_t device = 0);
    bool getChannelState(uint8_t channel, uint8_t device = 0);
    uint8_t getChannelState8(uint8_t device = 0);

private:
    Spi2Parallel _spi;
    uint8_t _deviceCount;
};

#endif // __OCTOFET_H__
