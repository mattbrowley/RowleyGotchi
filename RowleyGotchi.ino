#include "Globals.h"
#include "PriceList.h"

void setup() {
  setupLCD();

  randomSeed(analogRead(0));
  delay(random(10, 150));
  randomSeed(analogRead(0));
  newCritter();
  setupPins();
  ax = 1;
  ay = 2;
  az = 3;
  initializeAccelerometer();
}

void loop() {

  frames = frames + 1;
  if (frames % StatusFrames == 0) {   
    updateStats();
  }
  readTemp();
  readButtons();
  readAcceleration();
  writeScreen();
  updateLEDs();
}

void newCritter() {

  health = MaxHealth / 2;
  happiness = MaxHappiness / 2;
  hunger = 10;
  money = 0;
  dhealth = 0;
  dhappiness = 0;
  type = random(0, 10);
  alive = true;
  count = 0;
  incubation = 0;
  screen = 0;
  incubationCycles = random(5, 5);
  age = 0;
  cleanBody = true;
  cleanDiaper = true;
  for (int i = 0; i < 12; i++) {
    preferences[i] = random(-1, 4);
  }
  clearLEDs();
}

void setupPins() {
  pinMode(StatsPin, INPUT_PULLUP);
  pinMode(DiaperPin, INPUT_PULLUP);
  pinMode(BathPin, INPUT_PULLUP);
  pinMode(SelectPin, INPUT_PULLUP);
  pinMode(BackPin, INPUT_PULLUP);
  pinMode(UpPin, INPUT_PULLUP);
  pinMode(DownPin, INPUT_PULLUP);
  pinMode(LeftPin, INPUT_PULLUP);
  pinMode(RightPin, INPUT_PULLUP);
  pinMode(Data, OUTPUT);
  pinMode(Clock, OUTPUT);
  pinMode(Latch, OUTPUT);
  digitalWrite(Data, LOW);
  digitalWrite(Clock, LOW);
  digitalWrite(Latch, LOW);
}
