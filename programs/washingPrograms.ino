void programA()
{
  //PREWASH
  lockDoor(true);
  openDrain();
  while (getWaterLevel() != 2)
  {
    //WAITING
  }
  closeDrain();
  setSoap1Led(true);
  SetDirection(0);
  SetSpeed(1);
  delay(5000); //WAIT for 1 minute
  SetSpeed(0); // STOP MOTOR
  SetDirection(1);
  SetSpeed(1);
  delay(5000); //WAIT for 1 minute
  openSink();
  while (getWaterLevel() != 0)
  {
    //WAITING
  }

  //MAIN WASH
  openDrain();
  while (getWaterLevel() != 2)
  {
    //WAITING
  }
}



void testProgram()
{
  client.println("Start machinetests");
  delay(500);

  client.println("Lock door");
  client.println("Start motor");
  client.println("Open drain");

  lockDoor(true);
  SetDirection(0);
  SetSpeed(1);
  openDrain();

  while (getWaterLevel() != 3)
  {
    client.print("Current waterlevel: ");
    client.println(getWaterLevel());
    delay(1500);
  }

  client.print("Current waterlevel: ");
  client.println(getWaterLevel());

  client.println("Close drink");
  closeDrain();

  client.println("Increase motor speed");
  client.println("Turn heater on");
  client.println("use soap 1");

  SetSpeed(2);
  SetHeater(true);
  setSoap1Led(true);

  while (getTemperature() != 3)
  {
    client.print("Current temperature: ");
    client.println(getTemperature());
    delay(1500);
  }

  client.print("Current temperature: ");
  client.println(getTemperature());

  client.println("Increase motor speed");
  client.println("Turn heater off");
  client.println("use soap 2");
  SetSpeed(3);
  SetHeater(false);
  setSoap1Led(false);
  setSoap2Led(true);

  delay(2000);

  client.println("Change motor direction");
  client.println("Open sink");
  SetDirection(1);
  openSink();

  while (getWaterLevel() != 0)
  {
    client.print("Current waterlevel: ");
    client.println(getWaterLevel());
    delay(1500);
  }

  client.print("Current waterlevel: ");
  client.println(getWaterLevel());

  client.println("Close sink");
  client.println("Stop motor");
  client.println("Open door");

  setSoap2Led(false);
  closeSink();
  SetSpeed(0);
  lockDoor(false);
}

