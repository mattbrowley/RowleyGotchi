void updateLEDs() {
  if (age == 0) {
    clearLEDs();
    return;
  }
  if ((dhappiness < -30 | dhealth < -30 | health < 1000 | happiness < 1000) & (frames % 60 > 30)) {
    sendByte(1);
  } else if (!alive) {
    sendByte(1);
  } else {
    sendByte(0);
  }
  if (dhealth < 0) {
    sendByte(1);
  } else {
    sendByte(0);
  }
  if (dhealth > 0) {
    sendByte(1);
  } else {
    sendByte(0);
  }
  if (dhappiness < 0) {
    sendByte(1);
  } else {
    sendByte(0);
  }
  if (dhappiness > 0) {
    sendByte(1);
  } else {
    sendByte(0);
  }
  latchOutputs();
}

void latchOutputs() {
  digitalWrite(Latch, HIGH);
  digitalWrite(Latch, LOW);
}

void sendByte(int val) {
  digitalWrite(Data, val);
  digitalWrite(Clock, HIGH);
  digitalWrite(Clock, LOW);
}

void clearLEDs() {
  sendByte(0);
  sendByte(0);
  sendByte(0);
  sendByte(0);
  sendByte(0);
  sendByte(0);
  sendByte(0);
  sendByte(0);
  latchOutputs();
}
