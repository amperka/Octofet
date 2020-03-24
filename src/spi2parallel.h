#ifndef __SPI2PARALLEL_H__
#define __SPI2PARALLEL_H__

#include <Arduino.h>
#include <SPI.h>

class Spi2Parallel {
public:
    Spi2Parallel(uint8_t pinCS, uint8_t deviceCount, uint8_t bitOrder = MSBFIRST);
    Spi2Parallel(uint8_t pinCS, uint8_t pinMOSI, uint8_t pinSCK, uint8_t deviceCount, uint8_t bitOrder = MSBFIRST);
    ~Spi2Parallel();
    void begin();
    void writeBit(uint8_t bit, bool value, uint8_t device);
    void writeByte(uint8_t value, uint8_t device);
    bool readBit(uint8_t bit, uint8_t device) const;
    uint8_t readByte(uint8_t device) const;
    void update();
    uint8_t chainLength() const { return _deviceCount; }

private:
    uint8_t _pinCS;
    uint8_t _pinMOSI;
    uint8_t _pinSCK;
    uint8_t _deviceCount;
    uint8_t _bitOrder;
    uint8_t* _deviceChain;
    bool _hardwareSPI;
};

#endif // __SPI2PARALLEL_H__
