#include "pitches.h"

const int PIN_SPEAKER = 8;

// notes in the melody:
int melody[] = {
  0, NOTE_D5, NOTE_CS5, NOTE_C5, NOTE_B4, 0, NOTE_G4, NOTE_D4, NOTE_G4, NOTE_B4, NOTE_G4, NOTE_D5, NOTE_B4, NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_D5, NOTE_B4, NOTE_G4, NOTE_FS4, NOTE_E4, NOTE_FS4, NOTE_G4,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4, /**/NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_E5, /**/NOTE_FS5, NOTE_D5, NOTE_C5, NOTE_A4, /**/NOTE_B4, 0, NOTE_G4, NOTE_D4, NOTE_G4, /**/NOTE_B4, NOTE_G4, NOTE_D5, NOTE_B4, /**/NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_FS5, /**/NOTE_G5, NOTE_D5, NOTE_B4, NOTE_G4,
  NOTE_B4, NOTE_C5, NOTE_D5, NOTE_G5, NOTE_D5, /**/NOTE_C5, NOTE_A4, NOTE_FS4, NOTE_G4, /**/NOTE_A4, NOTE_G4, NOTE_G4, NOTE_FS4, /**/NOTE_G4, NOTE_D5, NOTE_CS5, NOTE_C5, /**/NOTE_B4, 0, NOTE_G4, NOTE_D4, NOTE_G4, /**/NOTE_B4, NOTE_G4, NOTE_D5, NOTE_B4,
  NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_FS5, /**/NOTE_G5, NOTE_D5, NOTE_B4, NOTE_G4, /**/NOTE_FS4, NOTE_E4, NOTE_FS4, NOTE_G4, /**/NOTE_A4, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4, /**/NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_E5, /**/NOTE_FS5, NOTE_D5, NOTE_C5, NOTE_A4, /**/NOTE_B4, 0, NOTE_G4, NOTE_D4, NOTE_G4,
  NOTE_B4, NOTE_G4, NOTE_D5, NOTE_B4, /**/NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_FS5, /**/NOTE_G5, NOTE_D5, NOTE_B4, NOTE_G4, /**/NOTE_B4, NOTE_C5, NOTE_D5, NOTE_G5, NOTE_D5, /**/NOTE_C5, NOTE_A4, NOTE_FS4, NOTE_G4, /**/NOTE_A4, NOTE_G4, NOTE_G4, NOTE_FS4, /**/NOTE_G4, 0, 0
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
float noteDurations[] = {
  2.666666666, 8, 8, 8, /**/8, 8, 8, 4, 8, /**/4, 8, 4, 8, /**/8, 8, 8, 8, 8, 8, /**/4, 8, 4, 8, /**/4, 8, 4, 8,
  4, 8, 8, 8, 8, /**/4, 8, 4, 8, /**/4, 8, 4, 8, /**/8, 8, 8, 4, 8, /**/4, 8, 4, 8, /**/8, 8, 8, 8, 8, 8, /**/4, 8, 4, 8,
  8, 8, 8, 4, 8, /**/4, 8, 4, 8, /**/4, 8, 4, 8, /**/ 2.666666666, 8, 8, 8, /**/8, 8, 8, 4, 8, /**/4, 8, 4, 8,
  8, 8, 8, 8, 8, 8, /**/4, 8, 4, 8, /**/4, 8, 4, 8, /**/4, 8, 8, 8, 8, /**/4, 8, 4, 8, /**/4, 8, 4, 8, /**/8, 8, 8, 4, 8,
  4, 8, 4, 8, /**/8, 8, 8, 8, 8, 8, /**/4, 8, 4, 8, /**/8, 8, 8, 4, 8, /**/4, 8, 4, 8, /**/4, 8, 4, 8, /**/2.666666666, 4, 8
};

void playBGM() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < sizeof(melody) / sizeof(melody[0]); thisNote++) {
    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(PIN_SPEAKER, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(PIN_SPEAKER);
  }
}

void setup() {
  pinMode(PIN_SPEAKER, OUTPUT);
}

void loop() {
  playBGM();
}

