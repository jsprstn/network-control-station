void reboot(void)
{
  //Reboot subroutine for stop/remote shutdown logic

  badID();
  wdt_disable();
  wdt_enable(WDTO_15MS);
  while (1) {}
}
