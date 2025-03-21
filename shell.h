#ifndef SHELL_H
#define SHELL_H

static char challenge[] = "neversaynever";
static char retValue[50];
#include "values.h"


// Put here function prototype to expose with micro shell
//char* ExampleFunc(int a, char* b)


// Put here wrapper function prototype to expose with micro shell
//char* ExampleFunc_wrapper(int argc, char **argv)
//{
//  int a,b;
//  char b[20];
//  argvscanf("%d %s", &a, b);
//  Interface->printf("a=%s, b=%s\n", a, b);
//}

void askAccess_wrapper(int argc, char **argv)
{
  char passphrase[20];
  argvscanf("%s", passphrase);
  if (strcmp(passphrase, challenge) == 0) {
    enableExecution();
  }
}


void getVersion_wrapper(int argc, char **argv) {
  char version[50];
  snprintf(version, sizeof(version), versionFormat, servicename, FIRMWARE_VERSION);
  shell.ble.print(version);
}

void enableEcho_wrapper(int argc, char **argv) {
  getVersion_wrapper(argc, argv);
  enableEcho();
}

void getAddress_wrapper(int argc, char **argv) {
  int Address, val;
  char buff [30];
  argvscanf("%d", &Address);
  val = ModbusRTUClient.holdingRegisterRead(Address, 0x200);
  if (val != -1) {
    snprintf(buff, sizeof(buff), "getAddress success");
    shell.ble.print(buff);
  } else {
    snprintf(buff, sizeof(buff), "getAddress failed");
    shell.ble.print(buff);
  }
}

void setAddress_wrapper(int argc, char **argv) {
  int oldAddress, newAddress, val;
  char buff [30];
  argvscanf("%d %d", &oldAddress, &newAddress);
  val = ModbusRTUClient.holdingRegisterRead(oldAddress, 0x200);
  if (val != -1) {
    ModbusRTUClient.holdingRegisterWrite(oldAddress, 0x200, newAddress);
    snprintf(buff, sizeof(buff), "New address is %d", ModbusRTUClient.holdingRegisterRead(newAddress, 0x200));
    shell.ble.print(buff);
  } else {
    snprintf(buff, sizeof(buff), "setAddress failed");
    shell.ble.print(buff);
  }
}

void disableEcho_wrapper(int argc, char **argv) {
  disableEcho();
}

// Put here wrapper function prototype to expose with micro shell
void test_wrapper(int argc, char **argv)
{
  int a;
  char b[20];
  const char testmessage[] = "le donne i cavalier l'arme gli amori\n\r";
  argvscanf("%d %s", &a, b);
  Serial.printf("Hello World!\n");
  Serial.printf("a=%d b=%s\n\n", a, b);
  shell.ble.print("OK\n");
  for (int i = 0 ; i < 10; i++) {
    shell.ble.print(testmessage);
  }
  //Interface->printf("a=%s, b=%s\n", a, b);
}

void getVoltage_wrapper(int argc, char **argv)
{
  //snprintf(retValue, sizeof(retValue), "%.0f", (float) ((int16_t)ModbusRTUClient.inputRegisterRead(PH_SLAVE_ADDRESS, 2)) );
  shell.ble.print(ModbusRTUClient.inputRegisterRead(PH_SLAVE_ADDRESS, 2));
}

void isStable_wrapper(int argc, char **argv)
{
  //snprintf(retValue, sizeof(retValue), "%d", 1);
  shell.ble.print(1);
}

void getpH_wrapper(int argc, char **argv)
{
  //snprintf(retValue, sizeof(retValue), "%.2f",  ModbusRTUClient.inputRegisterRead(PH_SLAVE_ADDRESS, 1) / 100.0);
  shell.ble.print(ModbusRTUClient.inputRegisterRead(PH_SLAVE_ADDRESS, 1) / 100.0);
}

void setP0_wrapper(int argc, char **argv)
{
  if(0x0013 == ModbusRTUClient.holdingRegisterRead(PH_SLAVE_ADDRESS, 0x8000))
    ModbusRTUClient.holdingRegisterWrite(PH_SLAVE_ADDRESS, 0x30, 0x7FFF);
  else
    ModbusRTUClient.holdingRegisterWrite(PH_SLAVE_ADDRESS, 0x30, 0xFFFF);  
  shell.ble.print("OK");
}

void setP1_wrapper(int argc, char **argv)
{
  //ModbusRTUClient.holdingRegisterWrite(PH_SLAVE_ADDRESS, 0x31, 0x7FFF);
  if(0x0013 == ModbusRTUClient.holdingRegisterRead(PH_SLAVE_ADDRESS, 0x8000))
    ModbusRTUClient.holdingRegisterWrite(PH_SLAVE_ADDRESS, 0x31, 0x7FFF);
  else
    ModbusRTUClient.holdingRegisterWrite(PH_SLAVE_ADDRESS, 0x31, 0xFFFF);  
  shell.ble.print("OK");
}

void setP2_wrapper(int argc, char **argv)
{
  //ModbusRTUClient.holdingRegisterWrite(PH_SLAVE_ADDRESS, 0x32, 0x7FFF);
  if(0x0013 == ModbusRTUClient.holdingRegisterRead(PH_SLAVE_ADDRESS, 0x8000))
    ModbusRTUClient.holdingRegisterWrite(PH_SLAVE_ADDRESS, 0x32, 0x7FFF);
  else
    ModbusRTUClient.holdingRegisterWrite(PH_SLAVE_ADDRESS, 0x32, 0xFFFF);  
  shell.ble.print("OK");
}

void calibrationCommit_wrapper(int argc, char **argv)
{
}

void coilRead(int argc, char **argv) {
  int id;
  int address;
  argvscanf("%d %d", &id, &address);
  shell.ble.print(ModbusRTUClient.coilRead(id, address));
}

void discreteInputRead(int argc, char **argv) {
  int id;
  int address;
  argvscanf("%d %d", &id, &address);
  shell.ble.print(ModbusRTUClient.discreteInputRead(id, address));
}

void holdingRegisterRead(int argc, char **argv) {
  int id;
  int address;
  argvscanf("%d %d", &id, &address);
  shell.ble.print(ModbusRTUClient.holdingRegisterRead(id, address));
}

void inputRegisterRead(int argc, char **argv) {
  int id;
  int address;
  argvscanf("%d %d", &id, &address);
  shell.ble.print(ModbusRTUClient.inputRegisterRead(id, address));
}

void coilWrite(int argc, char **argv) {
  int id;
  int address;
  uint8_t  value;
  argvscanf("%d %d %d", &id, &address, &value);
  shell.ble.print(ModbusRTUClient.coilWrite(id, address, value));
}

void holdingRegisterWrite(int argc, char **argv) {
  int id;
  int address;
  uint16_t  value;
  argvscanf("%d %d %d", &id, &address, &value);
  shell.ble.print(ModbusRTUClient.holdingRegisterWrite(id, address, value));
}

void registerMaskWrite(int argc, char **argv) {
  int id;
  int address;
  uint16_t  andMask;
  uint16_t  orMask;
  argvscanf("%d %d %d %d", &id, &address, &andMask, &orMask);
  shell.ble.print(ModbusRTUClient.registerMaskWrite(id, address, andMask, orMask));
}

void exit_wrapper(int argc, char **argv) {
}

//Put here Publish function table
PublishFunctionStruct PublishFunction[] =
{
  {"askAccess", askAccess_wrapper},
  {"enableEcho", enableEcho_wrapper},
  {"disableEcho", disableEcho_wrapper},
  {"setP0", setP0_wrapper},
  {"setP1", setP1_wrapper},
  {"setP2", setP2_wrapper},
  {"calibrationCommit", calibrationCommit_wrapper},
  {"getVoltage", getVoltage_wrapper},
  {"getpH", getpH_wrapper},
  {"isStable", isStable_wrapper},
  {"getVersion", getVersion_wrapper},
  {"getAddress", getAddress_wrapper},
  {"setAddress", setAddress_wrapper},
  {"coilRead", coilRead},
  {"discreteInputRead", discreteInputRead},
  {"holdingRegisterRead", holdingRegisterRead},
  {"inputRegisterRead", inputRegisterRead},
  {"coilWrite", coilWrite},
  {"holdingRegisterWrite", holdingRegisterWrite},
  {"registerMaskWrite", registerMaskWrite},
  {"test", test_wrapper},
  {"exit", exit_wrapper},
  {"", 0}
};
#endif
