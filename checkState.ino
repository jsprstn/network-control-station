void checkState(void)
{
  //Primary logic sub
  //Each discrete program state is assigned to char variable 'state' single character
  //While a given state is TRUE, void(loop) prints that char letter to the serial
  //This ensures the VB program and server code is *always* synced to ardunio program

  switch (state) {
    case 'a':
      //STATE: OFF
      OFFpin(r);
      OFFpin(y);
      OFFpin(g);
      OFFpin(motor1);
      OFFpin(motor2);

      if (startPB == 1) {
        state = 'b';
      }
      break;

    case 'b':
      //STATE: waiting for operator login trigger
      ONpin(r);
      OFFpin(y);
      OFFpin(g);
      OFFpin(motor1);
      OFFpin(motor2);

      if (currkey == '*') {
        state = 'c';
      }
      break;

    case 'c':
      //STATE: waiting for operator ID
      OFFpin(r);
      ONpin(y);
      OFFpin(g);
      OFFpin(motor1);
      OFFpin(motor2);

      if (currkey == '1') {
        cascade(5);
        operatorID = 1;
        sendVar(operatorID);
        state = 'd';
      }
      else if (currkey == '2') {
        cascade(5);
        operatorID = 2;
        sendVar(operatorID);
        state = 'd';
      }
      else if (currkey == '3') {
        cascade(5);
        operatorID = 3;
        sendVar(operatorID);
        state = 'd';
      }
      else if (currkey == '*') {
      }
      else {
        badID();
        state = 'a';
      }
      break;

    case 'd':
      //STATE:ON, waiting for start
      OFFpin(r);
      OFFpin(y);
      ONpin(g);
      OFFpin(motor1);
      OFFpin(motor2);

      if (startPB == 1) {
        state = 'e';
      }
      break;

    case 'e':
      //STATE: motor1 ON, waiting for box limit sensor to trip
      OFFpin(r);
      OFFpin(y);
      ONpin(g);
      ONpin(motor1);
      OFFpin(motor2);

      if (limit1 == 1) {
        goodPart();
        state = 'f';
      }
      break;

    case 'f':
      //STATE: motor1 OFF, motor2 ON, count = 0, waiting for part limit sensor to trip
      partCount = 0;
      OFFpin(r);
      OFFpin(y);
      ONpin(g);
      OFFpin(motor1);
      ONpin(motor2);

      if (limit2 == 1) {
        goodPart();
        state = 'g';
      }
      break;

    case 'g':
      //STATE: motor1 OFF, motor2 ON, count = 1, waiting for part limit sensor to trip
      partCount = 1;
      OFFpin(r);
      OFFpin(y);
      ONpin(g);
      OFFpin(motor1);
      ONpin(motor2);

      if (limit2 == 1) {
        goodPart();
        state = 'h';
      }
      break;

    case 'h':
      //STATE: motor1 OFF, motor2 ON, count = 2, waiting for part limit sensor to trip
      partCount = 2;
      OFFpin(r);
      OFFpin(y);
      ONpin(g);
      OFFpin(motor1);
      ONpin(motor2);

      if (limit2 == 1) {
        goodPart();
        state = 'i';
      }
      break;

    case 'i':
      //STATE: motor1 OFF, motor2 ON, count = 3, waiting for part limit sensor to trip
      partCount = 3;
      OFFpin(r);
      OFFpin(y);
      ONpin(g);
      OFFpin(motor1);
      ONpin(motor2);

      if (limit2 == 1) {
        goodPart();
        state = 'j';
      }
      break;

    case 'j':
      //STATE: motor1 OFF, motor2 ON, count = 4, waiting for part limit sensor to trip
      partCount = 4;
      OFFpin(r);
      OFFpin(y);
      ONpin(g);
      OFFpin(motor1);
      ONpin(motor2);

      if (limit2 == 1) {
        goodPart();
        state = 'k';
      }
      break;

    case 'k':
      //STATE: motor1 OFF, motor2 ON, count = 5, waiting for part limit sensor to trip
      partCount = 5;
      OFFpin(r);
      OFFpin(y);
      ONpin(g);
      OFFpin(motor1);
      ONpin(motor2);

      if (limit2 == 1) {
        goodPart();
        state = 'l';
      }
      break;

    case 'l':
      //STATE: motor1 OFF, motor2 ON, count = 6, waiting for part limit sensor to trip
      partCount = 6;
      OFFpin(r);
      OFFpin(y);
      ONpin(g);
      OFFpin(motor1);
      ONpin(motor2);

      if (limit2 == 1) {
        goodPart();
        state = 'm';
      }
      break;

    case 'm':
      //STATE: motor1 OFF, motor2 ON, count = 7, waiting for part limit sensor to trip
      partCount = 7;
      OFFpin(r);
      OFFpin(y);
      ONpin(g);
      OFFpin(motor1);
      ONpin(motor2);

      if (limit2 == 1) {
        goodPart();
        state = 'n';
      }
      break;

    case 'n':
      //STATE: motor1 OFF, motor2 ON, count = 8, waiting for part limit sensor to trip
      partCount = 8;
      OFFpin(r);
      OFFpin(y);
      ONpin(g);
      OFFpin(motor1);
      ONpin(motor2);

      if (limit2 == 1) {
        goodPart();
        state = 'o';
      }
      break;

    case 'o':
      //STATE: motor1 OFF, motor2 ON, count = 9, waiting for part limit sensor to trip
      partCount = 9;
      OFFpin(r);
      OFFpin(y);
      ONpin(g);
      OFFpin(motor1);
      ONpin(motor2);

      if (limit2 == 1) {
        goodPart();
        state = 'p';
      }
      break;

    case 'p':
      //STATE: motor1 OFF, motor2 ON, count = 10, waiting for part limit sensor to trip
      partCount = 10;
      boxCount++;
      OFFpin(r);
      OFFpin(y);
      ONpin(g);
      OFFpin(motor1);
      OFFpin(motor2);

      if (boxCount < 4) {
        cascade(3);
        state = 'e';
      }
      else {
        palletCount++;
        state = 'q';
      }
      break;

    case 'q':
      //STATE: Waiting for replace pallet
      palletFlash();
      break;

    case 'r':
      OFFpin(r);
      OFFpin(y);
      OFFpin(g);
      OFFpin(motor1);
      OFFpin(motor2);
      break;

    case 's':
      OFFpin(r);
      OFFpin(y);
      OFFpin(g);
      OFFpin(motor1);
      OFFpin(motor2);
      break;

    case 't':
      OFFpin(r);
      OFFpin(y);
      OFFpin(g);
      OFFpin(motor1);
      OFFpin(motor2);
      break;

    case 'u':
      OFFpin(r);
      OFFpin(y);
      OFFpin(g);
      OFFpin(motor1);
      OFFpin(motor2);
      break;

    case 'v':
      OFFpin(r);
      OFFpin(y);
      OFFpin(g);
      OFFpin(motor1);
      OFFpin(motor2);
      break;

    case 'w':
      OFFpin(r);
      OFFpin(y);
      OFFpin(g);
      OFFpin(motor1);
      OFFpin(motor2);
      break;

    case 'x':
      cascade(10);
      boxCount = 0;
      state = 'd';
      break;

    case 'y':
      OFFpin(r);
      OFFpin(y);
      OFFpin(g);
      OFFpin(motor1);
      OFFpin(motor2);
      break;

    case 'z':
      reboot();
      break;

    default:
      OFFpin(r);
      OFFpin(y);
      OFFpin(g);
      OFFpin(motor1);
      OFFpin(motor2);
      break;
  }
}
