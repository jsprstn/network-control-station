void palletFlash(void)
{
  //LED flasher subroutine for "waiting for new pallet" program state

  ONpin(motor1);
  ONpin(r);
  ONpin(y);
  ONpin(g);
  ONpin(motor2);
  delay(400);
  OFFpin(motor1);
  OFFpin(r);
  OFFpin(y);
  OFFpin(g);
  OFFpin(motor2);
  delay(400);
}
