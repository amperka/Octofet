#include "Octofet.h"

Octofet::Octofet(uint8_t pinCS, uint8_t deviceCount)
    : _spi(pinCS, deviceCount)
    , _deviceCount(deviceCount) {
}

Octofet::Octofet(uint8_t pinCS, uint8_t pinMOSI, uint8_t pinSCK, uint8_t deviceCount)
    : _spi(pinCS, pinMOSI, pinSCK, deviceCount)
    , _deviceCount(deviceCount) {
}

void Octofet::begin() {
    _spi.begin();
    for (uint8_t i = 0; i < _deviceCount; i++) {
        digitalWrite8(0, i);
    }
}

void Octofet::digitalWrite(uint8_t channel, bool value, uint8_t device) {
    _spi.writeBit(channel, value, device);
    _spi.update();
}

void Octofet::digitalWrite8(uint8_t value, uint8_t device) {
    _spi.writeByte(value, device);
    _spi.update();
}

bool Octofet::getChannelState(uint8_t channel, uint8_t device) const {
    return _spi.readBit(channel, device);
}

uint8_t Octofet::getChannelState8(uint8_t device) const {
    return _spi.readByte(device);
}
