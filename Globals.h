#ifndef Globals_h
#define Globals_h

#include "Arduino.h"

#define SCL 19
#define SDA 18
#define Data 10
#define Clock 11
#define Latch 12
#define StatsPin 9
#define DiaperPin 8
#define BathPin 13
#define SelectPin 7
#define LeftPin 6
#define RightPin 5
#define UpPin 4
#define DownPin 3
#define BackPin 2
#define DebounceDelay 200

#define MaxHealth 10000
#define MaxHappiness 10000
#define MaxEnergy 200
#define StatusCycles 100
#define BounceCycles 150
#define EnergyCycles 100
#define CleanBodyCycles 13000
#define CleanDiaperCycles 8000
#define YearsCycles 60000
#define HatchCycles 500

unsigned long count = 0;
unsigned long days = 0;
const String animalTypes[] = {"Fish", "Lizard", "Bird", "Koala", "Frog", "Sloth", "Dog", "Cat", "Turtle", "Mouse"};
int screen = 0; // Set this to 5 for diagnostics, 0 for regular operation
int selection = 0;
bool refreshScreen = false;
bool statsPressed = false;
unsigned long lastPress;
int xpos = 1;
int ypos = 0;
int type = 0;
int age = 2;
bool alive = false;
bool cleanBody = false;
bool cleanDiaper = false;
bool diaperOn = true;
bool bathOn = false;
int hunger = 0;
int energy = 0;
int health = 0;
int happiness = 0;
int money = 0;
int dhealth = 0;
int dhappiness = 0;
int incubation = 0;
int bathBrushes = 0;

int preferences[] = {1,1,1,1,1,1,1,1,1,1,1,1};

#endif
