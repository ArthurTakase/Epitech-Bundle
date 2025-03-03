#include <M5Stack.h>
#include <Wire.h>
#include <FastLED.h>
#include <vector>
#include "Module_GRBL_13.2.h"

#include "RFIDReader.hpp"
#include "NodeManager.hpp"
#include "WiFiRequestHandler.hpp"
#include "ServoMotor.hpp"
#include "Motor.hpp"
#include "Motion.hpp"

// Classes
Motion motion;
Motor motor;
ServoMotor servoMotor;
WiFiRequestHandler wifiRequestHandler;
RFIDReader rfidReader;
NodeManager nodeManager;

// LED Control
#define NUM_LEDS 10
#define DATA_PIN 15
CRGB leds[NUM_LEDS];

bool shouldMotorBeActive = false;
bool isProductReferenced = true;
bool isMotorPaused = motor.isPaused();

void setup()
{
    M5.begin(true, true, true, true);
    M5.Power.begin();

    motor.initialize();

    rfidReader.init();
    rfidReader.showDetails();

    wifiRequestHandler.connectWiFi();

    motion.initialize();

    servoMotor.initialize();

    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    FastLED.show();
}

void clearScreen()
{
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(0, 0);
    M5.Lcd.setTextColor(YELLOW);
    M5.Lcd.setTextSize(2);
}

void setLEDColor(CRGB color, int numLeds = NUM_LEDS, uint32_t delayMs = 300)
{
    fill_solid(leds, numLeds, color);
    FastLED.show();

    delay(delayMs);

    fill_solid(leds, numLeds, CRGB::Black);
    FastLED.show();
}

void checkForServoUpdate()
{
    NodeManager::Node_t *node = nodeManager.getFirstNode();

    if (!node)
        return;

    if (time(NULL) >= node->time) {
        nodeManager.removeNode();
        NodeManager::Node_t *newFirstNode = nodeManager.getFirstNode();
        if (newFirstNode)
            servoMotor.setAngle(newFirstNode->val);
        return;
    }

    servoMotor.setAngle(node->val);
    M5.Lcd.printf("Setting angle to %d\n", node->val);
}

void handleProduct(int id)
{
    Product product = wifiRequestHandler.getProductById(id);
    if (product.id == "" || product.warehouse_id == "") {
        setLEDColor(CRGB::Orange);
        isProductReferenced = false;
        shouldMotorBeActive = false;
        M5.Lcd.println("Product not found or invalid warehouse id");
        return;
    }
    wifiRequestHandler.postStockMovement(product);

    int angle = servoMotor.calculateAngle(id);

    nodeManager.pushNode(angle);
}

bool handleRFIDSensor()
{
    if (!rfidReader.isCardDetected()) return false;

    rfidReader.setDefaultKey();

    char message[BLOCK_SIZE * 3];
    memset(message, 0, sizeof(message));

    rfidReader.readBlock(message);

    rfidReader.stopCommunication();

    int id = atoi(message);
    handleProduct(id);

    return true;
}

void handleMotionSensor()
{
    bool isMotionDetected = motion.isMotionDetected();

    if (isMotionDetected)
        shouldMotorBeActive = true;

    motor.handleMotorInstructions(isProductReferenced, shouldMotorBeActive);
    handleRFIDSensor();
    checkForServoUpdate();

    if (nodeManager.isEmpty() && !isMotionDetected && nodeManager.getLastTime() <= time(NULL)) {
        shouldMotorBeActive = false;
        setLEDColor(CRGB::Red);
        M5.Lcd.println("No more products to handle.");
    }
}

void loop()
{
    clearScreen();
    nodeManager.printNodes();
    handleMotionSensor();
    delay(500);
}