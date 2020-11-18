void IR(void)
{
  //Translates decoded IR data to usable inputs

  limit1 = 0;
  limit2 = 0;

  if (irrecv.decode(&results)) {
    if (results.value == 0xFD08F7) {
      limit1 = 1;
    }
    if (results.value == 0xFD8877) {
      limit2 = 1;
    }
    irrecv.resume();
  }
}
