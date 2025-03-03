
#include "pitches.h"

const int melodyPinkPanther[] = {
    REST, REST, REST, NOTE_DS4,
    NOTE_E4, REST, NOTE_FS4, NOTE_G4, REST, NOTE_DS4,
    NOTE_E4, NOTE_FS4, NOTE_G4, NOTE_C5, NOTE_B4, NOTE_E4, NOTE_G4, NOTE_B4,
    NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D4,
    NOTE_E4, REST, REST, NOTE_DS4,

    NOTE_E4, REST, NOTE_FS4, NOTE_G4, REST, NOTE_DS4,
    NOTE_E4, NOTE_FS4, NOTE_G4, NOTE_C5, NOTE_B4, NOTE_G4, NOTE_B4, NOTE_E5,
    NOTE_DS5,
    NOTE_D5, REST, REST, NOTE_DS4,
    NOTE_E4, REST, NOTE_FS4, NOTE_G4, REST, NOTE_DS4,
    NOTE_E4, NOTE_FS4, NOTE_G4, NOTE_C5, NOTE_B4, NOTE_E4, NOTE_G4, NOTE_B4,

    NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D4,
    NOTE_E4, REST,
    REST, NOTE_E5, NOTE_D5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4,
    NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_A4,
    NOTE_G4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_E4};

int durationsPinkPanther[] = {
    2, 4, 8, 8,
    4, 8, 8, 4, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    2, 16, 16, 16, 16,
    2, 4, 8, 4,

    4, 8, 8, 4, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    1,
    2, 4, 8, 8,
    4, 8, 8, 4, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,

    2, 16, 16, 16, 16,
    4, 4,
    4, 8, 8, 8, 8, 8, 8,
    16, 8, 16, 8, 16, 8, 16, 8,
    16, 16, 16, 16, 16, 2};

void playPinkPanther(const int port)
{
  int size = sizeof(durationsPinkPanther) / sizeof(int);

  for (int note = 0; note < size; note++)
  {
    // to calculate the note duration, take one second divided by the note type.
    // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durationsPinkPanther[note];
    tone(port, melodyPinkPanther[note], duration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);

    // stop the tone playing:
    noTone(port);
  }
}

int melodyTokyoDrift[] = {
    NOTE_AS4, REST, NOTE_AS4, REST, NOTE_AS4, REST, NOTE_AS4, REST,
    NOTE_AS4, NOTE_B4, NOTE_DS5,
    NOTE_AS4, REST, NOTE_AS4, REST,
    NOTE_AS4, NOTE_B4, NOTE_DS5,
    NOTE_AS4, REST, NOTE_AS4, REST,
    NOTE_AS4, NOTE_B4, NOTE_DS5,
    NOTE_AS4, REST, NOTE_AS4, REST,
    NOTE_AS4, NOTE_B4, NOTE_DS5,
    NOTE_F5, REST, NOTE_F5, REST,
    NOTE_GS5, NOTE_FS5, NOTE_F5,
    NOTE_AS4, REST, NOTE_AS4, REST,
    NOTE_GS5, NOTE_FS5, NOTE_F5,
    NOTE_AS4, REST, NOTE_AS4, REST,
    NOTE_AS4, NOTE_B4, NOTE_DS5,
    NOTE_AS4, REST, NOTE_AS4, REST,
    NOTE_AS4, NOTE_B4, NOTE_DS5,
    NOTE_AS4, REST, NOTE_AS4, REST,
    REST};

int durationsTokyoDrift[] = {
    4, 4, 4, 4, 4, 4, 4, 4,
    3, 3, 4,
    4, 4, 4, 4,
    3, 3, 4,
    4, 4, 4, 4,
    3, 3, 4,
    4, 4, 4, 4,
    3, 3, 4,
    4, 4, 4, 4,
    3, 3, 4,
    4, 4, 4, 4,
    3, 3, 4,
    4, 4, 4, 4,
    3, 3, 4,
    4, 4, 4, 4,
    3, 3, 4,
    4, 4, 4, 4,
    1};

void playTokyoDrift(const int port)
{
  int size = sizeof(durationsTokyoDrift) / sizeof(int);

  for (int note = 0; note < size; note++)
  {
    // to calculate the note duration, take one second divided by the note type.
    // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durationsTokyoDrift[note];
    tone(port, melodyTokyoDrift[note], duration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);

    // stop the tone playing:
    noTone(port);
  }
}

int melodyStarWars[] = {
    NOTE_AS4, NOTE_AS4, NOTE_AS4,
    NOTE_F5, NOTE_C6,
    NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F6, NOTE_C6,
    NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F6, NOTE_C6,
    NOTE_AS5, NOTE_A5, NOTE_AS5, NOTE_G5, NOTE_C5, NOTE_C5, NOTE_C5,
    NOTE_F5, NOTE_C6,
    NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F6, NOTE_C6,

    NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F6, NOTE_C6,
    NOTE_AS5, NOTE_A5, NOTE_AS5, NOTE_G5, NOTE_C5, NOTE_C5,
    NOTE_D5, NOTE_D5, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F5,
    NOTE_F5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_C5,
    NOTE_D5, NOTE_D5, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F5,

    NOTE_C6, NOTE_G5, NOTE_G5, REST, NOTE_C5,
    NOTE_D5, NOTE_D5, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F5,
    NOTE_F5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_D5, NOTE_E5, NOTE_C6, NOTE_C6,
    NOTE_F6, NOTE_DS6, NOTE_CS6, NOTE_C6, NOTE_AS5, NOTE_GS5, NOTE_G5, NOTE_F5,
    NOTE_C6};

int durationsStarWars[] = {
    8, 8, 8,
    2, 2,
    8, 8, 8, 2, 4,
    8, 8, 8, 2, 4,
    8, 8, 8, 2, 8, 8, 8,
    2, 2,
    8, 8, 8, 2, 4,

    8, 8, 8, 2, 4,
    8, 8, 8, 2, 8, 16,
    4, 8, 8, 8, 8, 8,
    8, 8, 8, 4, 8, 4, 8, 16,
    4, 8, 8, 8, 8, 8,

    8, 16, 2, 8, 8,
    4, 8, 8, 8, 8, 8,
    8, 8, 8, 4, 8, 4, 8, 16,
    4, 8, 4, 8, 4, 8, 4, 8,
    1};

void playStarWars(const int port)
{
  int size = sizeof(durationsStarWars) / sizeof(int);

  for (int note = 0; note < size; note++)
  {
    // to calculate the note duration, take one second divided by the note type.
    // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durationsStarWars[note];
    tone(port, melodyStarWars[note], duration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);

    // stop the tone playing:
    noTone(port);
  }
}

int melodyPiratesOfTheCaribbean[] = {
    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
    NOTE_A4, NOTE_G4, NOTE_A4, REST,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
    NOTE_A4, NOTE_G4, NOTE_A4, REST,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
    NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, REST,
    NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, REST,
    NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, REST,

    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
    NOTE_D5, NOTE_E5, NOTE_A4, REST,
    NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, REST,
    NOTE_C5, NOTE_A4, NOTE_B4, REST,

    NOTE_A4, NOTE_A4,
    // Repeat of first part
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
    NOTE_A4, NOTE_G4, NOTE_A4, REST,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
    NOTE_A4, NOTE_G4, NOTE_A4, REST,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
    NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, REST,
    NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, REST,
    NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, REST,

    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
    NOTE_D5, NOTE_E5, NOTE_A4, REST,
    NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, REST,
    NOTE_C5, NOTE_A4, NOTE_B4, REST,
    // End of Repeat

    NOTE_E5, REST, REST, NOTE_F5, REST, REST,
    NOTE_E5, NOTE_E5, REST, NOTE_G5, REST, NOTE_E5, NOTE_D5, REST, REST,
    NOTE_D5, REST, REST, NOTE_C5, REST, REST,
    NOTE_B4, NOTE_C5, REST, NOTE_B4, REST, NOTE_A4,

    NOTE_E5, REST, REST, NOTE_F5, REST, REST,
    NOTE_E5, NOTE_E5, REST, NOTE_G5, REST, NOTE_E5, NOTE_D5, REST, REST,
    NOTE_D5, REST, REST, NOTE_C5, REST, REST,
    NOTE_B4, NOTE_C5, REST, NOTE_B4, REST, NOTE_A4};

int durationsPiratesOfTheCaribbean[] = {
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8,

    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8,

    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 8, 4, 8,

    8, 8, 4, 8, 8,
    4, 8, 4, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 4,

    4, 8,
    // Repeat of First Part
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8,

    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8,

    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 8, 4, 8,

    8, 8, 4, 8, 8,
    4, 8, 4, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 4,
    // End of Repeat

    4, 8, 4, 4, 8, 4,
    8, 8, 8, 8, 8, 8, 8, 8, 4,
    4, 8, 4, 4, 8, 4,
    8, 8, 8, 8, 8, 2,

    4, 8, 4, 4, 8, 4,
    8, 8, 8, 8, 8, 8, 8, 8, 4,
    4, 8, 4, 4, 8, 4,
    8, 8, 8, 8, 8, 2};

const void playPiratesOfTheCaribbean(const int port)
{
  int size = sizeof(durationsPiratesOfTheCaribbean) / sizeof(int);

  for (int note = 0; note < size; note++)
  {
    // to calculate the note duration, take one second divided by the note type.
    // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durationsPiratesOfTheCaribbean[note];
    tone(port, melodyPiratesOfTheCaribbean[note], duration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);

    // stop the tone playing:
    noTone(port);
  }
}

int melodyHarryPotter[] = {
    REST, NOTE_D4,
    NOTE_G4, NOTE_AS4, NOTE_A4,
    NOTE_G4, NOTE_D5,
    NOTE_C5,
    NOTE_A4,
    NOTE_G4, NOTE_AS4, NOTE_A4,
    NOTE_F4, NOTE_GS4,
    NOTE_D4,
    NOTE_D4,

    NOTE_G4, NOTE_AS4, NOTE_A4,
    NOTE_G4, NOTE_D5,
    NOTE_F5, NOTE_E5,
    NOTE_DS5, NOTE_B4,
    NOTE_DS5, NOTE_D5, NOTE_CS5,
    NOTE_CS4, NOTE_B4,
    NOTE_G4,
    NOTE_AS4,

    NOTE_D5, NOTE_AS4,
    NOTE_D5, NOTE_AS4,
    NOTE_DS5, NOTE_D5,
    NOTE_CS5, NOTE_A4,
    NOTE_AS4, NOTE_D5, NOTE_CS5,
    NOTE_CS4, NOTE_D4,
    NOTE_D5,
    REST, NOTE_AS4,

    NOTE_D5, NOTE_AS4,
    NOTE_D5, NOTE_AS4,
    NOTE_F5, NOTE_E5,
    NOTE_DS5, NOTE_B4,
    NOTE_DS5, NOTE_D5, NOTE_CS5,
    NOTE_CS4, NOTE_AS4,
    NOTE_G4};

int durationsHarryPotter[] = {
    2, 4,
    4, 8, 4,
    2, 4,
    2,
    2,
    4, 8, 4,
    2, 4,
    1,
    4,

    4, 8, 4,
    2, 4,
    2, 4,
    2, 4,
    4, 8, 4,
    2, 4,
    1,
    4,

    2, 4,
    2, 4,
    2, 4,
    2, 4,
    4, 8, 4,
    2, 4,
    1,
    4, 4,

    2, 4,
    2, 4,
    2, 4,
    2, 4,
    4, 8, 4,
    2, 4,
    1};

void playHarryPotter(const int buzzer)
{
  int size = sizeof(durationsHarryPotter) / sizeof(int);

  for (int note = 0; note < size; note++)
  {
    // to calculate the note duration, take one second divided by the note type.
    // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durationsHarryPotter[note];
    tone(buzzer, melodyHarryPotter[note], duration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);

    // stop the tone playing:
    noTone(buzzer);
  }
}

int melodySimpsons[] = {
    NOTE_C4, NOTE_E4, NOTE_FS4, REST, NOTE_A4,
    NOTE_G4, NOTE_E4, NOTE_C4, NOTE_A3,
    NOTE_FS3, NOTE_FS3, NOTE_FS3, NOTE_G3, REST,
    NOTE_FS3, NOTE_FS3, NOTE_FS3, NOTE_G3, NOTE_AS3,
    NOTE_B3, REST};

int durationsSimpsons[] = {
    2, 4, 4, 32, 8,
    2, 4, 4, 8,
    8, 8, 8, 4, 2,
    8, 8, 8, 4, 2,
    2, 2};

void playSimpsons(const int buzzer)
{
  int size = sizeof(durationsSimpsons) / sizeof(int);

  for (int note = 0; note < size; note++)
  {
    // to calculate the note duration, take one second divided by the note type.
    // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durationsSimpsons[note];
    tone(buzzer, melodySimpsons[note], duration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);

    // stop the tone playing:
    noTone(buzzer);
  }
}

int melodyMario[] = {
    NOTE_E5, NOTE_E5, REST, NOTE_E5, REST, NOTE_C5, NOTE_E5,
    NOTE_G5, REST, NOTE_G4, REST,
    NOTE_C5, NOTE_G4, REST, NOTE_E4,
    NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
    NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5,
    REST, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_B4,
    NOTE_C5, NOTE_G4, REST, NOTE_E4,
    NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
    NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5,
    REST, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_B4,

    REST, NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, NOTE_E5,
    REST, NOTE_GS4, NOTE_A4, NOTE_C4, REST, NOTE_A4, NOTE_C5, NOTE_D5,
    REST, NOTE_DS5, REST, NOTE_D5,
    NOTE_C5, REST,

    REST, NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, NOTE_E5,
    REST, NOTE_GS4, NOTE_A4, NOTE_C4, REST, NOTE_A4, NOTE_C5, NOTE_D5,
    REST, NOTE_DS5, REST, NOTE_D5,
    NOTE_C5, REST,

    NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5,
    NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,

    NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5, NOTE_E5,
    REST,
    NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5,
    NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
    NOTE_E5, NOTE_E5, REST, NOTE_E5, REST, NOTE_C5, NOTE_E5,
    NOTE_G5, REST, NOTE_G4, REST,
    NOTE_C5, NOTE_G4, REST, NOTE_E4,

    NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
    NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5,
    REST, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_B4,

    NOTE_C5, NOTE_G4, REST, NOTE_E4,
    NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
    NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5,
    REST, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_B4,

    NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
    NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
    NOTE_D5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_F5,

    NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
    NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
    NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
    NOTE_B4, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5,
    NOTE_C5, NOTE_E4, NOTE_E4, NOTE_C4,

    NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
    NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
    NOTE_D5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_F5,

    NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
    NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
    NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
    NOTE_B4, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5,
    NOTE_C5, NOTE_E4, NOTE_E4, NOTE_C4,
    NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5, NOTE_E5,
    REST,

    NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5,
    NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
    NOTE_E5, NOTE_E5, REST, NOTE_E5, REST, NOTE_C5, NOTE_E5,
    NOTE_G5, REST, NOTE_G4, REST,
    NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
    NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
    NOTE_D5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_F5,

    NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
    NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
    NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
    NOTE_B4, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5,
    NOTE_C5, NOTE_E4, NOTE_E4, NOTE_C4,

    // Game over sound
    NOTE_C5, NOTE_G4, NOTE_E4,
    NOTE_A4, NOTE_B4, NOTE_A4, NOTE_GS4, NOTE_AS4, NOTE_GS4,
    NOTE_G4, NOTE_D4, NOTE_E4};

int durationsMario[] = {
    8, 8, 8, 8, 8, 8, 8,
    4, 4, 8, 4,
    4, 8, 4, 4,
    4, 4, 8, 4,
    8, 8, 8, 4, 8, 8,
    8, 4, 8, 8, 4,
    4, 8, 4, 4,
    4, 4, 8, 4,
    8, 8, 8, 4, 8, 8,
    8, 4, 8, 8, 4,

    4, 8, 8, 8, 4, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    4, 4, 8, 4,
    2, 2,

    4, 8, 8, 8, 4, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    4, 4, 8, 4,
    2, 2,

    8, 4, 8, 8, 8, 4,
    8, 4, 8, 2,

    8, 4, 8, 8, 8, 8, 8,
    1,
    8, 4, 8, 8, 8, 4,
    8, 4, 8, 2,
    8, 8, 8, 8, 8, 8, 4,
    4, 4, 4, 4,
    4, 8, 4, 4,

    4, 4, 8, 4,
    8, 8, 8, 4, 8, 8,
    8, 4, 8, 8, 4,

    4, 8, 4, 4,
    4, 4, 8, 4,
    8, 8, 8, 4, 8, 8,
    8, 4, 8, 8, 4,

    8, 4, 8, 4, 4,
    8, 4, 8, 2,
    8, 8, 8, 8, 8, 8,

    8, 4, 8, 2,
    8, 4, 8, 4, 4,
    8, 4, 8, 2,
    8, 4, 8, 8, 8, 8,
    8, 4, 8, 2,

    8, 4, 8, 4, 4,
    8, 4, 8, 2,
    8, 8, 8, 8, 8, 8,

    8, 4, 8, 2,
    8, 4, 8, 4, 4,
    8, 4, 8, 2,
    8, 4, 8, 8, 8, 8,
    8, 4, 8, 2,
    8, 4, 8, 8, 8, 8, 8,
    1,

    8, 4, 8, 8, 8, 4,
    8, 4, 8, 2,
    8, 8, 8, 8, 8, 8, 4,
    4, 4, 4, 4,
    8, 4, 8, 4, 4,
    8, 4, 8, 2,
    8, 8, 8, 8, 8, 8,

    8, 4, 8, 2,
    8, 4, 8, 4, 4,
    8, 4, 8, 2,
    8, 4, 8, 8, 8, 8,
    8, 4, 8, 2,

    // game over sound
    4, 4, 4,
    8, 8, 8, 8, 8, 8,
    8, 8, 2};

void playMario(const int buzzer)
{
  int size = sizeof(durationsMario) / sizeof(int);

  for (int note = 0; note < size; note++)
  {
    // to calculate the note duration, take one second divided by the note type.
    // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durationsMario[note];
    tone(buzzer, melodyMario[note], duration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);

    // stop the tone playing:
    noTone(buzzer);
  }
}

int melodyPacman[] = {
    NOTE_B4, NOTE_B5, NOTE_FS5, NOTE_DS5,
    NOTE_B5, NOTE_FS5, NOTE_DS5, NOTE_C5,
    NOTE_C6, NOTE_G6, NOTE_E6, NOTE_C6, NOTE_G6, NOTE_E6,

    NOTE_B4, NOTE_B5, NOTE_FS5, NOTE_DS5, NOTE_B5,
    NOTE_FS5, NOTE_DS5, NOTE_DS5, NOTE_E5, NOTE_F5,
    NOTE_F5, NOTE_FS5, NOTE_G5, NOTE_G5, NOTE_GS5, NOTE_A5, NOTE_B5};

int durationsPacman[] = {
    16, 16, 16, 16,
    32, 16, 8, 16,
    16, 16, 16, 32, 16, 8,

    16, 16, 16, 16, 32,
    16, 8, 32, 32, 32,
    32, 32, 32, 32, 32, 16, 8};

void playPacman(const int buzzer)
{
  int size = sizeof(durationsPacman) / sizeof(int);

  for (int note = 0; note < size; note++)
  {
    // to calculate the note duration, take one second divided by the note type.
    // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durationsPacman[note];
    tone(buzzer, melodyPacman[note], duration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);

    // stop the tone playing:
    noTone(buzzer);
  }
}

int melodyDoom[] = {
    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2,

    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2,

    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2,

    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_FS3, NOTE_D3, NOTE_B2, NOTE_A3, NOTE_FS3, NOTE_B2, NOTE_D3, NOTE_FS3, NOTE_A3, NOTE_FS3, NOTE_D3, NOTE_B2,

    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2,

    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_B3, NOTE_G3, NOTE_E3, NOTE_G3, NOTE_B3, NOTE_E4, NOTE_G3, NOTE_B3, NOTE_E4, NOTE_B3, NOTE_G4, NOTE_B4,

    NOTE_A2, NOTE_A2, NOTE_A3, NOTE_A2, NOTE_A2, NOTE_G3, NOTE_A2, NOTE_A2,
    NOTE_F3, NOTE_A2, NOTE_A2, NOTE_DS3, NOTE_A2, NOTE_A2, NOTE_E3, NOTE_F3,
    NOTE_A2, NOTE_A2, NOTE_A3, NOTE_A2, NOTE_A2, NOTE_G3, NOTE_A2, NOTE_A2,
    NOTE_F3, NOTE_A2, NOTE_A2, NOTE_DS3,

    NOTE_A2, NOTE_A2, NOTE_A3, NOTE_A2, NOTE_A2, NOTE_G3, NOTE_A2, NOTE_A2,
    NOTE_F3, NOTE_A2, NOTE_A2, NOTE_DS3, NOTE_A2, NOTE_A2, NOTE_E3, NOTE_F3,
    NOTE_A2, NOTE_A2, NOTE_A3, NOTE_A2, NOTE_A2, NOTE_G3, NOTE_A2, NOTE_A2,
    NOTE_A3, NOTE_F3, NOTE_D3, NOTE_A3, NOTE_F3, NOTE_D3, NOTE_C4, NOTE_A3, NOTE_F3, NOTE_A3, NOTE_F3, NOTE_D3,

    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2,

    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2,

    NOTE_CS3, NOTE_CS3, NOTE_CS4, NOTE_CS3, NOTE_CS3, NOTE_B3, NOTE_CS3, NOTE_CS3,
    NOTE_A3, NOTE_CS3, NOTE_CS3, NOTE_G3, NOTE_CS3, NOTE_CS3, NOTE_GS3, NOTE_A3,
    NOTE_B2, NOTE_B2, NOTE_B3, NOTE_B2, NOTE_B2, NOTE_A3, NOTE_B2, NOTE_B2,
    NOTE_G3, NOTE_B2, NOTE_B2, NOTE_F3,

    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_B3, NOTE_G3, NOTE_E3, NOTE_G3, NOTE_B3, NOTE_E4, NOTE_G3, NOTE_B3, NOTE_E4, NOTE_B3, NOTE_G4, NOTE_B4,

    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2,

    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_FS3, NOTE_DS3, NOTE_B2, NOTE_FS3, NOTE_DS3, NOTE_B2, NOTE_G3, NOTE_D3, NOTE_B2, NOTE_DS4, NOTE_DS3, NOTE_B2,

    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2,

    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_E4, NOTE_B3, NOTE_G3, NOTE_G4, NOTE_E4, NOTE_G3, NOTE_B3, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_E4, NOTE_G3,

    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2,

    NOTE_A2, NOTE_A2, NOTE_A3, NOTE_A2, NOTE_A2, NOTE_G3, NOTE_A2, NOTE_A2,
    NOTE_F3, NOTE_A2, NOTE_A2, NOTE_DS3, NOTE_A2, NOTE_A2, NOTE_E3, NOTE_F3,
    NOTE_A2, NOTE_A2, NOTE_A3, NOTE_A2, NOTE_A2, NOTE_G3, NOTE_A2, NOTE_A2,
    NOTE_A3, NOTE_F3, NOTE_D3, NOTE_A3, NOTE_F3, NOTE_D3, NOTE_C4, NOTE_A3, NOTE_F3, NOTE_A3, NOTE_F3, NOTE_D3,

    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2,

    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2,

    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2,

    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
    NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
    NOTE_B3, NOTE_G3, NOTE_E3, NOTE_B2, NOTE_E3, NOTE_G3, NOTE_C4, NOTE_B3, NOTE_G3, NOTE_B3, NOTE_G3, NOTE_E3};

int durationsDoom[] = {
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 2,

    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 2,

    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 2,

    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,

    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 2,

    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,

    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 2,

    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,

    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 2,

    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 2,

    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 2,

    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,

    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 2,

    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,

    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 2,

    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,

    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 2,

    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,

    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 2,

    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 2,

    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 2,

    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16};

void playDoom(const int buzzer)
{
  int size = sizeof(durationsDoom) / sizeof(int);

  for (int note = 0; note < size; note++)
  {
    // to calculate the note duration, take one second divided by the note type.
    // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durationsDoom[note];
    tone(buzzer, melodyDoom[note], duration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);

    // stop the tone playing:
    noTone(buzzer);
  }
}

int melodyMarron5[] = {
    REST, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_B4,
    NOTE_G5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_E5, NOTE_F5, NOTE_G5, REST,
    NOTE_E5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5,
    NOTE_A4, NOTE_A4, REST, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_G4, REST, NOTE_G4,
    NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_B4,
    NOTE_G5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_E5, NOTE_F5, NOTE_G5,
    NOTE_E5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5,
    NOTE_A4, NOTE_A4, REST, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_G4, REST, NOTE_G4, NOTE_G4,
    NOTE_A4, NOTE_A4, NOTE_A4, REST, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_C5, REST,
    REST};

int durationsMarron5[] = {
    4, 2, 2, 2, 2, 2, 2, 2, 4,
    4, 8, 8, 4, 8, 8, 2, 2,
    4, 8, 8, 4, 8, 8, 4, 8, 8, 4, 8, 8,
    4, 8, 8, 4, 8, 8, 8, 8, 2, 8, 8,
    8, 8, 4, 4, 4, 1,
    4, 8, 8, 4, 8, 8, 1,
    4, 8, 8, 4, 8, 8, 4, 8, 8, 4, 8, 8,
    4, 8, 8, 4, 8, 8, 8, 8, 4, 4, 8, 8,
    8, 8, 8, 8, 4, 4, 8, 8, 4, 4, 8, 8,
    1};

void playMarron5(const int buzzer)
{
  int size = sizeof(durationsMarron5) / sizeof(int);

  for (int note = 0; note < size; note++)
  {
    // to calculate the note duration, take one second divided by the note type.
    // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durationsMarron5[note];
    tone(buzzer, melodyMarron5[note], duration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);

    // stop the tone playing:
    noTone(buzzer);
  }
}

int melodyNokia[] = {
    NOTE_E5, NOTE_D5, NOTE_FS4, NOTE_GS4,
    NOTE_CS5, NOTE_B4, NOTE_D4, NOTE_E4,
    NOTE_B4, NOTE_A4, NOTE_CS4, NOTE_E4,
    NOTE_A4};

int durationsNokia[] = {
    8, 8, 4, 4,
    8, 8, 4, 4,
    8, 8, 4, 4,
    2};

void playNokia(const int buzzer)
{
  int size = sizeof(durationsNokia) / sizeof(int);

  for (int note = 0; note < size; note++)
  {
    // to calculate the note duration, take one second divided by the note type.
    // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durationsNokia[note];
    tone(buzzer, melodyNokia[note], duration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);

    // stop the tone playing:
    noTone(buzzer);
  }
}

int melodyXmas[] = {
    NOTE_E5, NOTE_E5, NOTE_E5,
    NOTE_E5, NOTE_E5, NOTE_E5,
    NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
    NOTE_E5,
    NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
    NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
    NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
    NOTE_D5, NOTE_G5};

int durationsXmas[] = {
    8, 8, 4,
    8, 8, 4,
    8, 8, 8, 8,
    2,
    8, 8, 8, 8,
    8, 8, 8, 16, 16,
    8, 8, 8, 8,
    4, 4};

void playXmas(const int buzzer)
{
  int size = sizeof(durationsXmas) / sizeof(int);

  for (int note = 0; note < size; note++)
  {
    // to calculate the note duration, take one second divided by the note type.
    // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durationsXmas[note];
    tone(buzzer, melodyXmas[note], duration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);

    // stop the tone playing:
    noTone(buzzer);
  }
}