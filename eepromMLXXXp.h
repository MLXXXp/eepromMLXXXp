#ifndef EEPROMMLXXXP_H
#define EEPROMMLXXXP_H

#include "Arduino.h"
#include "EEPROM.h"

#define ARDUBOY_EEPROM_RESERVED 16
#define ARDUBOY_EEPROM_SIZE 1024

// open() return values
#define EEPROM_ALLOCATED 1
#define EEPROM_ERROR_ALLOCATE -1

class ArduboyEeprom
{
  public:
    int begin(unsigned int start, uint16_t userID, uint8_t sketchID, unsigned int length);

    uint8_t read(unsigned int address);
    boolean write(unsigned int address, uint8_t data);
    boolean read(unsigned int address, uint8_t *buffer, size_t size);
    boolean write(unsigned int address, uint8_t *buffer, size_t size);

  private:
    unsigned int eeStart;
    unsigned int eeLength;
};

#endif
