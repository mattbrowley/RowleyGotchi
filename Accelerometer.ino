#include <MPU6050.h>

int16_t axOffset, ayOffset, azOffset;
int16_t gxOffset, gyOffset, gzOffset;

MPU6050 accelgyro;
//MPU6050 accelgyro(0x69); // <-- use for AD0 high

void initializeAccelerometer(){
  accelgyro.initialize();
  axOffset = accelgyro.getXAccelOffset();
  ayOffset = accelgyro.getYAccelOffset();
  azOffset = accelgyro.getZAccelOffset();
  gxOffset = accelgyro.getXGyroOffset();
  gyOffset = accelgyro.getYGyroOffset();
  gzOffset = accelgyro.getZGyroOffset();
  
}

void readAcceleration(){
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  ax = ax - axOffset;
  ay = ay - ayOffset;
  az = az - azOffset;
  gx = gx - gxOffset;
  gy = gy - gyOffset;
  gz = gz - gzOffset;
}

bool getTossed(){
    
}

bool getRotating(){
//  int16_t vector = (gx*gx+gy*gy+gz*gz)**(1/3);
}

void readTemp(){
  temperature = accelgyro.getTemperature() / 340.0 + 36.53;
  if (temperature > 30 & temperature < 40){ // RowleyGotchi is being cuddled
    cuddled = true;
  } else {
    cuddled = false;
  }
  if (false){ // RowleyGotchi is in uncomfortable temperature
    dhealth = dhealth - 2;
    dhappiness = dhappiness -4; 
  }
}
