#ifndef PriceList_h
#define PriceList_h

#include "Arduino.h"

#define DonutPrice -10
#define DonutEnergy -5
#define DonutHappiness 20
#define DonutHealth -10

#define NachosPrice -20
#define NachosEnergy 0
#define NachosHappiness 15
#define NachosHealth 5

#define ApplesPrice -10
#define ApplesEnergy 5
#define ApplesHappiness 5
#define ApplesHealth 10

#define ScrapsPrice 0
#define ScrapsEnergy 0
#define ScrapsHappiness -5
#define ScrapsHealth 5

#define SwingPrice 0
#define SwingEnergy -20
#define SwingHappiness 10
#define SwingHealth 5

#define WalkPrice 0
#define WalkEnergy -20
#define WalkHappiness 5
#define WalkHealth 10

#define BalletPrice -10
#define BalletEnergy -30
#define BalletHappiness 20
#define BalletHealth 10

#define FetchPrice 0
#define FetchEnergy -30
#define FetchHappiness 10
#define FetchHealth 10

#define DeliverPrice 20
#define DeliverEnergy -30
#define DeliverHappiness -5
#define DeliverHealth 5

#define CircusPrice 10
#define CircusEnergy -30
#define CircusHappiness 5
#define CircusHealth 5

#define DigPrice 20
#define DigEnergy -30
#define DigHappiness -5
#define DigHealth 0

#define GuardPrice 30
#define GuardEnergy -20
#define GuardHappiness -10
#define GuardHealth -5

int prices[] = {DonutPrice, NachosPrice, ApplesPrice, ScrapsPrice, SwingPrice, WalkPrice, BalletPrice, FetchPrice, DeliverPrice, CircusPrice, DigPrice, GuardPrice};
int energies[] = {DonutEnergy, NachosEnergy, ApplesEnergy, ScrapsEnergy, SwingEnergy, WalkEnergy, BalletEnergy, FetchEnergy, DeliverEnergy, CircusEnergy, DigEnergy, GuardEnergy};
int happinesses[] = {DonutHappiness, NachosHappiness, ApplesHappiness, ScrapsHappiness, SwingHappiness, WalkHappiness, BalletHappiness, FetchHappiness, DeliverHappiness, CircusHappiness, DigHappiness, GuardHappiness};
int healths[] = {DonutHealth, NachosHealth, ApplesHealth, ScrapsHealth, SwingHealth, WalkHealth, BalletHealth, FetchHealth, DeliverHealth, CircusHealth, DigHealth, GuardHealth};
#endif
