void sendVar(int n1)
{
  //Essentially an extended duration version of Serial.print
  //to make sure the VB program catches one-cycle states-to-state transitions

  int i;

  for (i = 0; i < 1000; i++) {
    Serial.print(n1);
    ONpin(13);
    OFFpin(13);
  }
}
