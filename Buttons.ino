void readButtons(){
  if(!digitalRead(BathPin)){
    if (!cleanBody){
      cleanBody = true;
      dhappiness = dhappiness + 40;
    } else{
      dhappiness = dhappiness - 1;
    }    
  }
  if(!digitalRead(DiaperPin)){
    if (!cleanDiaper){
      cleanDiaper = true;
      dhappiness = dhappiness + 40;
    } else{
      dhappiness = dhappiness - 1;
    }
  }  
  if(!digitalRead(SelectPin) & millis()>lastPress+DebounceDelay){
    switch (screen) {
      case 0: // Default screen shows bouncing Rowleygotchi
        if(age>0){
          screen = 1;
          selection = 0;
        } else {
          writeEgg();
        }
        break; 
      case 1: // Main menu shows food, fun, and work
        selectMenu();
        break;
      case 2: // Food menu
        selectFood();
        break;
      case 3: // Fun menu
        selectFun();
        break;
      case 4: // Work menu
        selectWork();
        break;
    }
    refreshScreen=true;
    lastPress = millis();
  }
  if(!digitalRead(BackPin) & millis()>lastPress+DebounceDelay){
    switch (screen) {
      case 0: // Default screen shows bouncing Rowleygotchi 
        break; 
      case 1: // Main menu shows food, fun, and work
        screen = 0;
        break;
      case 2: // Food menu
        screen = 1;
        break;
      case 3: // Fun menu
        screen = 1;
        break;
      case 4: // Work menu
        screen = 1;
        break;
    }
    selection=0;
    refreshScreen=true;
    lastPress = millis();
  }
  if(!digitalRead(LeftPin)){
    if (selection==0){
    } else if (selection==1){
      selection = 0;
      refreshScreen=true;
    } else if(selection==2){
    } else{
      selection = 2;
      refreshScreen=true;
    }
    
  }
  if(!digitalRead(UpPin)){
    if (selection==0){
    } else if (selection==1){      
    } else if(selection==2){
      selection = 0;
      refreshScreen=true;
    } else{
      selection = 1;
      refreshScreen=true;
    }   
  }
  if(!digitalRead(RightPin)){
    if (selection==0){
      selection = 1;
      refreshScreen=true;
    } else if (selection==1){ 
      
    } else if(selection==2 & screen !=1){
      selection = 3;
      refreshScreen=true;
    } else{
    }
  }
  if(!digitalRead(DownPin)){
    if (selection==0){
      selection = 2;
      refreshScreen=true;
    } else if (selection==1 & screen !=1){ 
      selection = 3;
      refreshScreen=true;
    } else if(selection==2){
      
    } else{
    }
  }
}

void selectMenu(){
  if (selection==0){
    screen = 2;  // Food
  } else if (selection==1){
    selection = 0;
    screen = 3; // Fun
  } else {
    selection =0;
    screen = 4; // Work
  }
  refreshScreen=true;
}

void selectFood(){
  if (selection==0){ // Donut
    doActivity(0);
    screen = 0;
  } else if (selection==1){ // Nachos
    doActivity(1);
    screen = 0;
  } else if (selection==2){ // Apple
    doActivity(2);
    screen = 0;
  } else { // Scraps
    doActivity(3);
    screen = 0;
  }
  refreshScreen=true;
}

void selectFun(){
  if (selection==0){ // Swing
    doActivity(4);
    screen = 0;
  } else if (selection==1){ // Walk
    doActivity(5);
    screen = 0;
  } else if (selection==2){ // Ballet
    doActivity(6);
    screen = 0;
  } else { // Fetch
    doActivity(7);
    screen = 0;
  }
  refreshScreen=true;
}

void selectWork(){
  if (selection==0){ // Deliver
    doActivity(8);
    screen = 0;
  } else if (selection==1){ // Circus
    doActivity(9);
    screen = 0;
  } else if (selection==2){ // Dig
    doActivity(10);
    screen = 0;
  } else { // Guard
    doActivity(11);
    screen = 0;
  }
  refreshScreen=true;
}

void doActivity(int index){
  if (money + prices[index] < 0){
    writeNoMoney();
  } else if (energy + energies[index] < 0){
    writeNoEnergy();
  } else {
    money = money + prices[index];
    energy = energy + energies[index];
    dhappiness = dhappiness + happinesses[index] * preferences[index];
    dhealth = dhealth + healths[index];
  }
  
}
