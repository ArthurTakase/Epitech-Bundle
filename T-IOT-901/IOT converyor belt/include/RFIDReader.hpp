#ifndef RFID_READER_H
#define RFID_READER_H

#include <Arduino.h>
#include "MFRC522_I2C.h"

#define MFRC522_VERSION_1_0 0x91
#define MFRC522_VERSION_2_0 0x92
#define COMM_FAILURE_CODE_1 0x00
#define COMM_FAILURE_CODE_2 0xFF

#define PICC_CMD_MF_AUTH_KEY_A 0x60
#define BLOCK_SIZE 16
#define FIRST_BLOCK 4
#define NEXT_BLOCK 5
#define MIFARE_SANITY_SIZE 18

class RFIDReader
{
public:
    RFIDReader();
    RFIDReader(uint8_t i2cAddress);
    ~RFIDReader() = default;

    void init();
    void setDefaultKey();
    void showDetails();
    bool readBlock(char *message);
    void stopCommunication();
    bool isCardDetected();

private:
    MFRC522 rfid;
    MFRC522::StatusCode rfidStatusCode;
    MFRC522::MIFARE_Key key;
};

#endif