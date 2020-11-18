void checkAll(void) {
  //Checks for inputs across all types

  IR();
  startPB = !digitalRead(startPin);
  stopPB = !digitalRead(stopPin);
  char keypressed = myKeypad.getKey();

  if (keypressed != NO_KEY) {
    currkey = keypressed;
  }

  if ((state != 'a') && (stopPB == 1)) {
    reboot();
  }

  //Checks for incoming serial data from VB program
  if (Serial.available() > 0) {
    // read the incoming byte:
    val = Serial.read();
  }

  //Performs remote stop
  if (val == 'z') {
    state = val;
    val = 0;
  }

  //Clears "Pallet Full" hold condition
  if ((val == 'x') && (state == 'q')) {
    state = val;
    val = 0;
  }
}
