void goodPart(void)
{
  //Green/Yellow LED flasher sub for positive visual feedback

  int i;

  for (i = 0; i < 6; i++) {
    ONpin(g);
    delay(50);
    OFFpin(g);
    ONpin(y);
    delay(50);
    OFFpin(y);
  }
}
