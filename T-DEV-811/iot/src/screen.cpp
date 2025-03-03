#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include "screen.h"

// Screen
const int rs = 12, en = 11, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

char screen[16][2][16];

void initScreen()
{
  lcd.begin(16, 2);
  sprintf(screen[0][0], "Welcome!");
  for (size_t i = 1; i <= 3; i++)
  {
    changeState(i, false, false, false);
    delay(1);
  }
}

void changeState(const int id, const bool isOpen_, const bool isFilled_, const bool isTilted_)
{
  int screenNumberBegin = 0;
  if (id == 1)
    screenNumberBegin = 1;
  else if (id == 2)
    screenNumberBegin = 4;
  else
    screenNumberBegin = 7;
  char tmpstr[16];
  if (isOpen_)
    sprintf(tmpstr, "true");
  else
    sprintf(tmpstr, "false");
  sprintf(screen[screenNumberBegin][0], "Trash %d :", id);
  sprintf(screen[screenNumberBegin][1], "Is Open? %s", tmpstr);
  if (isFilled_)
    sprintf(tmpstr, "true");
  else
    sprintf(tmpstr, "false");
  sprintf(screen[screenNumberBegin + 1][0], "Trash %d :", id);
  sprintf(screen[screenNumberBegin + 1][1], "Is Filled? %s", tmpstr);
  if (isTilted_)
    sprintf(tmpstr, "true");
  else
    sprintf(tmpstr, "false");
  sprintf(screen[screenNumberBegin + 2][0], "Trash %d :", id);
  sprintf(screen[screenNumberBegin + 2][1], "Is Tilted? %s", tmpstr);
}

bool changeScreen(const int id)
{
  if (strlen(screen[id][0]) <= 0 && strlen(screen[id][1]) <= 0)
    return false;
  delay(5);
  lcd.clear();
  delay(5);
  lcd.setCursor(0, 0);
  delay(5);
  lcd.print(screen[id][0]);
  delay(5);
  lcd.setCursor(0, 1);
  delay(5);
  lcd.print(screen[id][1]);
  return true;
}

int getAmountScreen()
{
  return 16;
}