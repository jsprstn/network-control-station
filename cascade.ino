void cascade(int n1)
{
  //Cascading LED flasher subroutine

  int i;

  for (i = 0; i < n1; i++) {
    ONpin(motor1);
    delay(30);
    OFFpin(motor1);
    ONpin(r);
    delay(30);
    OFFpin(r);
    ONpin(y);
    delay(30);
    OFFpin(y);
    ONpin(g);
    delay(30);
    OFFpin(g);
    ONpin(motor2);
    delay(30);
    OFFpin(motor2);
  }
}
