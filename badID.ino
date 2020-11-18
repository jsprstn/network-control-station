void badID(void)
{
  //Red/Yellow LED flasher sub for negative visual feedback

  int i;
  for (i = 0; i < 10; i++) {
    ONpin(r);
    delay(50);
    OFFpin(r);
    ONpin(y);
    delay(50);
    OFFpin(y);
  }
}
