#include <Arduino.h>
#include "sensors.h"
#include "pinout.h"

bool T1isHalfFilled = false;
bool T1isHalfFilled_laststate = false;
bool T1slidingWindowFilled[5];
bool T1isFilled = false;
bool T1isFilled_laststate = false;
float T1slidingWindowOpen[5];
bool T1isOpen = false;
bool T1isOpen_laststate = false;
float T1slidingWindowTilted[5];
bool T1isTilted = false;
bool T1IsTilted_laststate = false;

bool T2isHalfFilled = false;
bool T2isHalfFilled_laststate = false;
bool T2slidingWindowFilled[5];
bool T2isFilled = false;
bool T2isFilled_laststate = false;
float T2slidingWindowOpen[5];
bool T2isOpen = false;
bool T2isOpen_laststate = false;
float T2slidingWindowTilted[5];
bool T2isTilted = false;
bool T2IsTilted_laststate = false;

bool T3isHalfFilled = false;
bool T3isHalfFilled_laststate = false;
bool T3slidingWindowFilled[5];
bool T3isFilled = false;
bool T3isFilled_laststate = false;
float T3slidingWindowOpen[5];
bool T3isOpen = false;
bool T3isOpen_laststate = false;
float T3slidingWindowTilted[5];
bool T3isTilted = false;
bool T3IsTilted_laststate = false;

bool checkT1()
{
  int USState = readUltrasonicSensor(T1_trigPin, T1_echoPin);
  bool isChanged = false;
  for (int i = 0; i < 3; i++)
  {
    T1slidingWindowOpen[i] = T1slidingWindowOpen[i + 1];
  }
  T1slidingWindowOpen[3] = USState;

  bool isMore = true;
  bool isLess = true;
  const int valueTrig = 6;
  for (int i = 0; i < 4; i++)
  {
    if (T1slidingWindowOpen[i] <= valueTrig)
    {
      isMore = false;
    }
    if (T1slidingWindowOpen[i] > valueTrig)
    {
      isLess = false;
    }
  }

  if (isLess)
  {
    if (T1isOpen == true)
    {
      T1isOpen_laststate = T1isOpen;
      T1isOpen = false;
      isChanged = true;
    }
  }
  else if (isMore)
  {
    if (T1isOpen == false)
    {
      T1isOpen_laststate = T1isOpen;
      T1isOpen = true;
      isChanged = true;
    }
  }

  bool IRState = readInfraredSensor(T1_infraredLedPin, T1_infraredPin);
  isMore = true;
  isLess = true;

  for (int i = 0; i < 2; i++)
  {
    T1slidingWindowFilled[i] = T1slidingWindowFilled[i + 1];
  }
  T1slidingWindowFilled[2] = IRState;

  for (int i = 0; i < 3; i++)
  {
    if (T1slidingWindowFilled[i] == 1)
    {
      isMore = false;
    }
    else
    {
      isLess = false;
    }
  }
  if (isLess)
  {
    if (!T1isFilled)
    {
      T1IsTilted_laststate = T1isFilled;
      T1isFilled = true;
      isChanged = true;
    }
  }
  else if (isMore)
  {
    if (T1isFilled)
    {
      T1IsTilted_laststate = T1isFilled;
      T1isFilled = false;
      isChanged = true;
    }
  }

  bool tiltState = readTiltSensor(T1_tiltPin);
  isMore = true;
  isLess = true;

  for (int i = 0; i < 2; i++)
  {
    T1slidingWindowTilted[i] = T1slidingWindowTilted[i + 1];
  }
  T1slidingWindowTilted[2] = tiltState;

  for (int i = 0; i < 3; i++)
  {
    if (T1slidingWindowTilted[i] == 1)
    {
      isMore = false;
    }
    else
    {
      isLess = false;
    }
  }
  if (isLess)
  {
    if (!T1isTilted)
    {
      T1IsTilted_laststate = T1isTilted;
      T1isTilted = true;
      isChanged = true;
    }
  }
  else if (isMore)
  {
    if (T1isTilted)
    {
      T1IsTilted_laststate = T1isTilted;
      T1isTilted = false;
      isChanged = true;
    }
  }

  return isChanged;
}

bool T1getHalfFiled()
{
  return T1isHalfFilled;
}

bool T1getFilled()
{
  return T1isFilled;
}

bool T1getOpen()
{
  return T1isOpen;
}

bool T1getTilted()
{
  return T1isTilted;
}

bool checkT2()
{
  int USState = readUltrasonicSensor(T2_trigPin, T2_echoPin);
  bool isChanged = false;
  for (int i = 0; i < 3; i++)
  {
    T2slidingWindowOpen[i] = T2slidingWindowOpen[i + 1];
  }
  T2slidingWindowOpen[3] = USState;

  bool isMore = true;
  bool isLess = true;
  const int valueTrig = 6;
  for (int i = 0; i < 4; i++)
  {
    if (T2slidingWindowOpen[i] <= valueTrig)
    {
      isMore = false;
    }
    if (T2slidingWindowOpen[i] > valueTrig)
    {
      isLess = false;
    }
  }

  if (isLess)
  {
    if (T2isOpen == true)
    {
      T2isOpen_laststate = T2isOpen;
      T2isOpen = false;
      isChanged = true;
    }
  }
  else if (isMore)
  {
    if (T2isOpen == false)
    {
      T2isOpen_laststate = T2isOpen;
      T2isOpen = true;
      isChanged = true;
    }
  }

  bool IRState = readInfraredSensor(T2_infraredLedPin, T2_infraredPin);
  isMore = true;
  isLess = true;

  for (int i = 0; i < 2; i++)
  {
    T2slidingWindowFilled[i] = T2slidingWindowFilled[i + 1];
  }
  T2slidingWindowFilled[2] = IRState;

  for (int i = 0; i < 3; i++)
  {
    if (T2slidingWindowFilled[i] == 1)
    {
      isMore = false;
    }
    else
    {
      isLess = false;
    }
  }
  if (isLess)
  {
    if (!T2isFilled)
    {
      T2IsTilted_laststate = T2isFilled;
      T2isFilled = true;
      isChanged = true;
    }
  }
  else if (isMore)
  {
    if (T2isFilled)
    {
      T2IsTilted_laststate = T2isFilled;
      T2isFilled = false;
      isChanged = true;
    }
  }

  bool tiltState = readTiltSensor(T2_tiltPin);
  isMore = true;
  isLess = true;

  for (int i = 0; i < 2; i++)
  {
    T2slidingWindowTilted[i] = T2slidingWindowTilted[i + 1];
  }
  T2slidingWindowTilted[2] = tiltState;

  for (int i = 0; i < 3; i++)
  {
    if (T2slidingWindowTilted[i] == 1)
    {
      isMore = false;
    }
    else
    {
      isLess = false;
    }
  }
  if (isLess)
  {
    if (!T2isTilted)
    {
      T2IsTilted_laststate = T2isTilted;
      T2isTilted = true;
      isChanged = true;
    }
  }
  else if (isMore)
  {
    if (T2isTilted)
    {
      T2IsTilted_laststate = T2isTilted;
      T2isTilted = false;
      isChanged = true;
    }
  }

  return isChanged;
}

bool T2getHalfFiled()
{
  return T2isHalfFilled;
}

bool T2getFilled()
{
  return T2isFilled;
}

bool T2getOpen()
{
  return T2isOpen;
}

bool T2getTilted()
{
  return T2isTilted;
}

bool checkT3()
{
  int USState = readUltrasonicSensor(T3_trigPin, T3_echoPin);
  bool isChanged = false;
  for (int i = 0; i < 3; i++)
  {
    T3slidingWindowOpen[i] = T3slidingWindowOpen[i + 1];
  }
  T3slidingWindowOpen[3] = USState;

  bool isMore = true;
  bool isLess = true;
  const int valueTrig = 12;
  for (int i = 0; i < 4; i++)
  {
    if (T3slidingWindowOpen[i] <= valueTrig)
    {
      isMore = false;
    }
    if (T3slidingWindowOpen[i] > valueTrig)
    {
      isLess = false;
    }
  }

  if (isLess)
  {
    if (T3isOpen == true)
    {
      T3isOpen_laststate = T3isOpen;
      T3isOpen = false;
      isChanged = true;
    }
  }
  else if (isMore)
  {
    if (T3isOpen == false)
    {
      T3isOpen_laststate = T3isOpen;
      T3isOpen = true;
      isChanged = true;
    }
  }

  bool IRState = readInfraredSensor(T3_infraredLedPin, T3_infraredPin);
  isMore = true;
  isLess = true;

  for (int i = 0; i < 2; i++)
  {
    T3slidingWindowFilled[i] = T3slidingWindowFilled[i + 1];
  }
  T3slidingWindowFilled[2] = IRState;

  for (int i = 0; i < 3; i++)
  {
    if (T3slidingWindowFilled[i] == 1)
    {
      isMore = false;
    }
    else
    {
      isLess = false;
    }
  }
  if (isLess)
  {
    if (!T3isFilled)
    {
      T3IsTilted_laststate = T3isFilled;
      T3isFilled = true;
      isChanged = true;
    }
  }
  else if (isMore)
  {
    if (T3isFilled)
    {
      T3IsTilted_laststate = T3isFilled;
      T3isFilled = false;
      isChanged = true;
    }
  }

  bool tiltState = readTiltSensor(T3_tiltPin);
  isMore = true;
  isLess = true;

  for (int i = 0; i < 2; i++)
  {
    T3slidingWindowTilted[i] = T3slidingWindowTilted[i + 1];
  }
  T3slidingWindowTilted[2] = tiltState;

  for (int i = 0; i < 3; i++)
  {
    if (T3slidingWindowTilted[i] == 1)
    {
      isMore = false;
    }
    else
    {
      isLess = false;
    }
  }
  if (isLess)
  {
    if (!T3isTilted)
    {
      T3IsTilted_laststate = T3isTilted;
      T3isTilted = true;
      isChanged = true;
    }
  }
  else if (isMore)
  {
    if (T3isTilted)
    {
      T3IsTilted_laststate = T3isTilted;
      T3isTilted = false;
      isChanged = true;
    }
  }

  return isChanged;
}

bool T3getHalfFiled()
{
  return T3isHalfFilled;
}

bool T3getFilled()
{
  return T3isFilled;
}

bool T3getOpen()
{
  return T3isOpen;
}

bool T3getTilted()
{
  return T3isTilted;
}
