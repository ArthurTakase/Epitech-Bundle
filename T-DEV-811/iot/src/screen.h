#ifndef SCREEN_H
#define SCREEN_H

void initScreen();

void changeState(const int id, const bool isOpen_, const bool isFilled_, const bool isTilted_);
bool changeScreen(const int id);

int getAmountScreen();

#endif