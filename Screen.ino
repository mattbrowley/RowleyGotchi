#include <LiquidCrystal_I2C.h>
#define LCD_Address 0x27 // The I2C address for the 16x2 LCD

const uint8_t heart[8] = {0x0,0xa,0x1f,0x1f,0xe,0x4,0x0};
const uint8_t smile[8] = {0x0,0xa,0xa,0xa,0x0,0x11,0xe};
const uint8_t lightning[8] = {0x00,0x1E,0x04,0x08,0x1F,0x02,0x04,0x08};
//const uint8_t lightning[8] = {0x1F,0x02,0x04,0x08,0x1F,0x02,0x04,0x08};
//const uint8_t lightning[8] = {0x01,0x1E,0x04,0x09,0x1E,0x04,0x08,0x10};
//const uint8_t lightning[8] = {0x01,0x1E,0x04,0x08,0x1F,0x02,0x04,0x8};
const uint8_t lstink1[8] = {0x12,0x0A,0x09,0x04,0x04,0x03,0x00,0x00};
const uint8_t lstink2[8] = {0x14,0x12,0x0A,0x09,0x04,0x04,0x03,0x00};
const uint8_t rstink1[8] = {0x09,0x09,0x0A,0x12,0x02,0x0C,0x10,0x00};
const uint8_t rstink2[8] = {0x05,0x09,0x09,0x0A,0x12,0x02,0x0C,0x10};
const uint8_t poo1[8] = {0x02,0x02,0x01,0x01,0x02,0x04,0x0E,0x1F};
const uint8_t poo2[8] = {0x04,0x04,0x08,0x08,0x04,0x04,0x0E,0x1F};

LiquidCrystal_I2C lcd(LCD_Address, 16, 2);

void setupLCD(){  
  lcd.init(); 
  lcd.backlight(); // Turn on the backlight
  lcd.createChar(0, heart);
  lcd.createChar(1, smile);
  lcd.createChar(2, lstink1);
  lcd.createChar(3, lstink2);
  lcd.createChar(4, rstink1);
  lcd.createChar(5, rstink2);
  lcd.createChar(6, poo1);
  lcd.createChar(7, poo2);
}
void writeScreen(){
  if (refreshScreen){
    refreshScreen=!refreshScreen;
    lcd.clear();
  }
  
  if(!digitalRead(StatsPin)){
    if(!statsPressed){
      statsPressed=true;
      refreshScreen=true;
    }
    writeHealth();
    writeHappiness();
    writeMoney();
    writeEnergy();
  } else {
    if(statsPressed){
      statsPressed=false;
      refreshScreen=true;
    }
    switch (screen) {
      case 0: // Default screen shows bouncing Rowleygotchi
        writeName();      
        break; 
      case 1: // Main menu shows food, fun, and work
        writeMenu();
        writeCursor();
        break;
      case 2: // Food menu
        writeFood();
        writeCursor();
        break;
      case 3: // Fun menu
        writeFun();
        writeCursor();
        break;
      case 4: // Work menu
        writeWork();
        writeCursor();
        break;
    }
  }
}


void writeMenu(){
  lcd.setCursor(1,0);
  lcd.print("Food");
  lcd.setCursor(9,0);
  lcd.print("Fun");
  lcd.setCursor(1,1);
  lcd.print("Work");
}

void writeFood(){
  lcd.setCursor(1,0);
  lcd.print("Donut");
  lcd.setCursor(9,0);
  lcd.print("Nachos");
  lcd.setCursor(1,1);
  lcd.print("Apple");
  lcd.setCursor(9,1);
  lcd.print("Scraps");
}

void writeFun(){
  lcd.setCursor(1,0);
  lcd.print("Swing");
  lcd.setCursor(9,0);
  lcd.print("Walk");
  lcd.setCursor(1,1);
  lcd.print("Ballet");
  lcd.setCursor(9,1);
  lcd.print("Fetch");
}

void writeWork(){
  lcd.setCursor(1,0);
  lcd.print("Deliver");
  lcd.setCursor(9,0);
  lcd.print("Circus");
  lcd.setCursor(1,1);
  lcd.print("Dig");
  lcd.setCursor(9,1);
  lcd.print("Guard");
}

void writeName(){
  if (count%BounceCycles==0){
    refreshScreen = true;
    if(random(0,3)==1){
      if (ypos == 0){
        ypos = 1;
      } else{
        ypos = 0;
      }
    } else{
      xpos = xpos + random(-1,2);
      if (xpos < 1){
        xpos = 2;
      } else if (xpos > 3){
        xpos = 2;
      }      
    }
  }  
  if(!cleanBody){
    if(count%10==0){
      lcd.setCursor(xpos-1,ypos);
      if (random(0,2)==0){
        lcd.write(2);
      } else {
        lcd.write(3);
      }
    }
  }
  lcd.setCursor(xpos,ypos);
  if (age<1){
    lcd.print("Egg");
    return;
  }
  if (age<2){
    lcd.print("Baby ");
  } else if (age<3){
    lcd.print("Young ");
  } else if (age>10){
    lcd.print("Old ");
  }
  lcd.print(animalTypes[type]);
  if(!cleanBody){
    if(count%10==0){
      if (random(0,2)==0){
        lcd.write(4);
      } else {
        lcd.write(5);
      }
    }
  }
  if(!cleanDiaper){
    lcd.setCursor(15,1);
     if(count%10==0){
      if (random(0,2)==0){
        lcd.write(6);
      } else {
        lcd.write(7);
      }
    }
  }
  
}

void writeMoney(){
  if (money>999){
    lcd.setCursor(11,0);
  } else if (money>99){
    lcd.setCursor(12,0);
  } else if (money>9){
    lcd.setCursor(13,0);
  } else {
    lcd.setCursor(14,0);
  }
  lcd.print(money);
  lcd.print("$");
}

void writeEnergy(){
  if (energy>99){
    lcd.setCursor(12,1);
  } else if (energy>9){
    lcd.setCursor(13,1);
  } else {
    lcd.setCursor(14,1);
  }
  lcd.print(energy);
  lcd.print("E");
}

void writeHealth(){
  lcd.setCursor(0,0);
  lcd.write(0);
  lcd.print(":");
  lcd.print(health);
}

void writeHappiness(){
  lcd.setCursor(0,1);
  lcd.write(1);
  lcd.print(":");
  lcd.print(happiness);
}

void writeCursor(){
  if (selection==0){
    lcd.setCursor(0,0);
  } else if (selection==1){
    lcd.setCursor(8,0);
  } else if(selection==2){
    lcd.setCursor(0,1);
  } else{
    lcd.setCursor(8,1);
  }
  lcd.print("*");
}

void writeEgg(){
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Just Keep Your");
  lcd.setCursor(4,1);
  lcd.print("Egg Warm");
  delay(1000);
}

void writeNoMoney(){
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Not Enough");
  lcd.setCursor(5,1);
  lcd.print("Money");
  delay(1000);
}

void writeNoEnergy(){
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Not Enough");
  lcd.setCursor(4,1);
  lcd.print("Energy");
  delay(1000);
}
