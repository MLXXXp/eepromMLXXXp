#include "eepromMLXXXp.h"

int ArduboyEeprom::begin(unsigned int start, uint16_t userID, uint8_t sketchID, unsigned int length) {
  eeStart = start + 3; // user data starts after user ID and sketch ID
  eeLength = length;

  // check bounds
  if (eeStart < ARDUBOY_EEPROM_RESERVED) {
    return EEPROM_ERROR_ALLOCATE;
  }
  if ((eeStart + eeLength) >= ARDUBOY_EEPROM_SIZE) {
    return EEPROM_ERROR_ALLOCATE;
  }

  // verify IDs (which indicates previously allocated)
  if ((EEPROM.read(start) == (userID >> 8)) &&
      (EEPROM.read(start + 1) == (userID & 0xFF)) &&
      (EEPROM.read(start + 2) == (sketchID))) {
    return 0;
  }

  // indicate area was allocated by setting user ID and sketch ID
  EEPROM.write(start, userID >> 8);
  EEPROM.write(start + 1, userID & 0xFF);
  EEPROM.write(start + 2, sketchID);
  return EEPROM_ALLOCATED;
}

uint8_t ArduboyEeprom::read(unsigned int address) {
  return EEPROM.read(eeStart + address);
}

boolean ArduboyEeprom::write(unsigned int address, uint8_t data) {
  if (address >= eeLength) {
    return false;
  }

  EEPROM.write(eeStart + address, data);
  return true;
}

boolean ArduboyEeprom::read(unsigned int address, uint8_t *buffer, size_t size) {
  unsigned int end = address + size;
  if (end > eeLength) {
    return false;
  }

  end += eeStart;
  for (unsigned int i = eeStart + address; i < end; i++) {
    *buffer++ = EEPROM.read(i);
  }
  return true;
}

boolean ArduboyEeprom::write(unsigned int address, uint8_t *buffer, size_t size) {
  unsigned int end = address + size;
  if (end > eeLength) {
    return false;
  }

  end += eeStart;
  for (unsigned int i = eeStart + address; i < end; i++) {
    EEPROM.write(i, *buffer++);
  }
  return true;
}

