#include "RFIDReader.hpp"
#include <M5Stack.h>

RFIDReader::RFIDReader() : rfid(0x28) {}

RFIDReader::RFIDReader(uint8_t i2cAddress) : rfid(i2cAddress) {}

void RFIDReader::init()
{
    rfid.PCD_Init();
}

void RFIDReader::setDefaultKey()
{
    for (byte i = 0; i < sizeof(key.keyByte); i++)
        key.keyByte[i] = 0xFF;
}

void RFIDReader::showDetails()
{
    byte version = rfid.PCD_ReadRegister(rfid.VersionReg);

    M5.Lcd.printf("MFRC522 Software Version: 0x%02X\n", version);
    if (version == MFRC522_VERSION_1_0)
        M5.Lcd.println(" = v1.0");
    else if (version == MFRC522_VERSION_2_0)
        M5.Lcd.println(" = v2.0");
    else
        M5.Lcd.println(" (unknown)");

    if ((version == COMM_FAILURE_CODE_1) || (version == COMM_FAILURE_CODE_2))
        M5.Lcd.println("WARNING: Communication failure, is the MFRC522 properly connected?");
}

bool RFIDReader::readBlock(char *message)
{
    for (byte blockAddr = FIRST_BLOCK; blockAddr <= NEXT_BLOCK; blockAddr++) {
        byte status = rfid.PCD_Authenticate(PICC_CMD_MF_AUTH_KEY_A, blockAddr, &key, &(rfid.uid));

        if (status != MFRC522::STATUS_OK) {
            M5.Lcd.println("Authenticate Failed");
            return false;
        }

        byte buffer[MIFARE_SANITY_SIZE];
        byte size = sizeof(buffer);
        status = rfid.MIFARE_Read(blockAddr, buffer, &size);
        if (status != MFRC522::STATUS_OK) {
            M5.Lcd.println("Failed to data from block");
            return false;
        }

        strncat(message, (char *)buffer, BLOCK_SIZE);
    }
    return true;
}

void RFIDReader::stopCommunication()
{
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
}

bool RFIDReader::isCardDetected()
{
    return rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial();
}