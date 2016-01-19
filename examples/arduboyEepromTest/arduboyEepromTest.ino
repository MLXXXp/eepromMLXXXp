#include <Arduboy.h>
#include "localEEPROM.h"
#include <EEPROM.h>

Arduboy aboy;
ArduboyEeprom savedData; 

uint8_t eeBuf[4];

void setup() {
  int retVal;

  aboy.start();
  aboy.clearDisplay();
  aboy.setCursor(0, 0);

  if ((retVal = savedData.EEPROM_BEGIN) != 0) {
    if (retVal == EEPROM_ALLOCATED) {
      aboy.println("Allocated. Init...");
      savedData.write(0, 10);
      savedData.write(1, 11);
      savedData.write(2, 12);
      savedData.write(3, 20);

      printEE();

    }
    else {
      aboy.print("Allocate Error: ");
      aboy.println(retVal);
    }
  }
  else {
    aboy.println("EEPROM begin OK");
  }

  aboy.println("Block read to buffer");
  savedData.read(0, eeBuf, 4);
  printBuf();

  aboy.println("Increment last 3");
  for (byte i = 1; i < 4; i++) {
    eeBuf[i]++;
  }
  aboy.println("Block write last 3");
  savedData.write(1, &eeBuf[1], 3);
  printEE();

  aboy.display();
}
  
void loop() {
}

void printEE() {
  aboy.print("Read:");
  for (byte i = 0; i < 4; i++) {
    aboy.print(" ");
    aboy.print(savedData.read(i));
  }
  aboy.println("");
}

void printBuf() {
  aboy.print("Buff:");
  for (byte i = 0; i < 4; i++) {
    aboy.print(" ");
    aboy.print(eeBuf[i]);
  }
  aboy.println("");
}

