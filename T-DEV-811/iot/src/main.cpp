#include <Arduino.h>
#include <Wire.h>
#include <ArduinoJson.h>
#include <LiquidCrystal.h>

#include "json.h"
#include "sensors.h"
#include "trash.h"
#include "screen.h"

const int delayLoop = 50;
const int timeToChangeScreen = 1000 / delayLoop;
int timer = 0;
int actualScreen = 0;

// screen 0 -> Welcome
// screen 1 -> Trash 1 is open
// screen 2 -> Trash 1 is filled
// screen 3 -> Trash 1 is tilted

void setup()
{
  Serial.begin(9600);
  initScreen();
  initSensors();
}

void loop()
{
  // trash 1
  bool T1_isChanged = checkT1();
  if (T1_isChanged)
  {
    changeState(1, T1getOpen(), T1getFilled(), T1getTilted());
    char *j = printJson(1, T1getOpen(), T1getFilled(), T1getTilted());
    Serial.println(j);
    free(j);
  }

  bool T2_isChanged = checkT2();
  if (T2_isChanged)
  {
    changeState(2, T2getOpen(), T2getFilled(), T2getTilted());
    char *j = printJson(2, T2getOpen(), T2getFilled(), T2getTilted());
    Serial.println(j);
    free(j);
  }

  bool T3_isChanged = checkT3();
  if (T3_isChanged)
  {
    changeState(3, T3getOpen(), T3getFilled(), T3getTilted());
    char *j = printJson(3, T3getOpen(), T3getFilled(), T3getTilted());
    Serial.println(j);
    free(j);
  }

  timer++;
  if (timer >= timeToChangeScreen)
  {
    int amountOfScreen = getAmountScreen();
    actualScreen++;
    if (actualScreen >= amountOfScreen)
      actualScreen = 0;
    while (!changeScreen(actualScreen))
    {
      actualScreen++;
      if (actualScreen >= amountOfScreen)
        actualScreen = 0;
    }
    timer = 0;
  }

  delay(delayLoop);
}
