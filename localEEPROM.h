// This file should be copied to the folder containing the sketch

#ifndef LOCALEEPROM_H
#define LOCALEEPROM_H

// == Change the values to define a unique area to save data for the sketch ==

// Number of EEPROM bytes required by this sketch, in decimal
#define SKETCH_EEPROM_SIZE 20

// This is the start address for the block of EEPROM space used by
// this sketch, in decimal.
// This must be set so that areas used by all desired sketches don't overlap.
// When determining the size of the area used by a sketch, 3 must be added to
// SKETCH_EEPROM_SIZE to account for a header.
#define MLXXXP_EEPROM_START 992

// The combination of user ID and sketch ID must be unique amongst all
// sketches using EEPROM.
// Change these as necessary.
#define ARDUBOY_USER_ID 1234
#define USER_SKETCH_ID 1

// ========== DO NOT CHANGE ANYTHING BEYOND THIS POINT ==========
#include <eepromMLXXXp.h>
#define EEPROM_BEGIN begin(MLXXXP_EEPROM_START, ARDUBOY_USER_ID, USER_SKETCH_ID, SKETCH_EEPROM_SIZE)

#endif
