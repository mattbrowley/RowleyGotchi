void updateStats(){
  if (age==0){
    updateEggStats();
  } else if(alive){
    updateHatchedStats();
  }
}

void updateEggStats(){
  checkIncubation();
  if (incubation > incubationCycles){
    age = 1;
    count = 0;
    dhappiness = 0;
    dhealth = 0;
    cleanBody = false;
    cleanDiaper = false;
    refreshScreen = true;
    checkCleanliness();
    //updateLEDs();
  }
}

void updateHatchedStats(){  
  count = count + 1; 
  happiness = happiness + dhappiness;
  checkHappinessLimits();
  health = health + dhealth;
  checkHealthLimits();
  decayChanges();
  if(count % EnergyCycles == 0){
    energy = energy + 1;
  }
  checkEnergyLimits();
  checkHunger();
  checkCleanliness();  
  checkCuddled();
  //updateLEDs();  
  updateCleanliness();
  updateAge();
  if (millis()<lastPress){
    lastPress = millis(); // Overflow protection
  }
}

void checkHunger(){
  if (hunger > 50) {
    dhealth = dhealth - 1;
  }
  if (hunger > 25) {
    dhappiness = dhappiness -1;
  }
}

void checkHappinessLimits(){
  if (happiness <0){
    happiness = 0;
    dhealth = dhealth -1;
  }
  if (happiness > MaxHappiness){
    happiness = MaxHappiness;
  }
}

void checkHealthLimits(){
  if (health <= 0){
    refreshScreen = true;
    alive = false;
    money = 0;
    energy = 0;
    health = 0;
    dhealth = -1;
    dhappiness = -1;
    screen = 5;
  }
  if (health > MaxHealth){
    health = MaxHealth;
  }
}

void checkCleanliness(){
  if (!cleanBody){
    dhealth = dhealth - 1;
    dhappiness = dhappiness - 1;
  }
  if (!cleanDiaper){
    dhealth = dhealth - 1;
    dhappiness = dhappiness - 1;
  }
}

void checkEnergyLimits(){
  if (energy>MaxEnergy){
    energy = MaxEnergy;
  }
  if (energy == 0){
    dhealth = dhealth - 1;
    dhappiness = dhappiness - 1;
  }
}

void updateAge(){
  if (count > YearsCycles){
    age = age + 1;
    count = 0;
  }
}

void updateCleanliness(){
  if (count % CleanBodyCycles == 0){
    cleanBody = false;
    bathBrushes = 0;
  }
  if (count % (CleanDiaperCycles * age * age) == 0){
    cleanDiaper = false;
  }
}

void checkIncubation(){
  if (cuddled){
    incubation = incubation + 1;
  }
}
void checkCuddled(){
  if (cuddled){
    dhappiness = dhappiness + 1;
  }
}

void decayChanges(){
  if (dhappiness < -1){
    dhappiness = dhappiness + 2;
  }else if (dhappiness > 1){
    dhappiness = dhappiness -2;
  } else {
    dhappiness = 0;
  }
  if (dhealth < -1){
    dhealth = dhealth + 2;
  } else if (dhealth > 1){
    dhealth = dhealth - 2;
  } else {
    dhealth = 0;
  }  
}
