 // =================================================================================================
// IoTWmodbusBLE-UARTGateway: Copyright 2025 by IoThingsWare srl
// =================================================================================================
// Includes: <Arduino.h> for Serial etc., WiFi.h for WiFi support
// NOTE NOTE NOTE
// Arduino IDE - Select board: M5Atom
// Reference implementation for: M5Stack Atom Light + Atomic RS485 Base
// Pin Connection
// Type         Tx     Rx
// Atom-Lite    G22    G19
// Atom-Matrix  G22    G19
// AtomS3-Lite  G5     G6
// ATOMS3       G5     G6
// IoThingsWare - Toni Cafiero - For M5Stack Atom following statements must be appended to file:
// D:\arduino-ide_2.3.4_Windows_64bit\portable\arduino15\packages\esp32\hardware\esp32\3.0.5\variants\m5stack_atom\pins_arduino.h
// 
// #define RS485_SERIAL_PORT Serial2
// #define SERIAL_PORT_HARDWARE RS485_SERIAL_PORT
// #define ATOM_RS485_RX (22)
// #define ATOM_RS485_TX (19)
// #define RS485_DEFAULT_TX_PIN (19)
// #define CUSTOM_RS485_DEFAULT_DE_PIN (-1)
// #define CUSTOM_RS485_DEFAULT_RE_PIN (-1)



#include "ioTWMicroShellBLEGlue.h" 
//#include "ioTWMicroShellSerialGlue.h" 
#include "version.h"
#include "values.h"


// IoThingsWare - Toni Cafiero - Following statements appended
// ATOM RS485 
#define RS485_SERIAL_PORT Serial2
#define ATOM_RS485_RX (22)
#define ATOM_RS485_TX (19)


#define PH_SLAVE_ADDRESS 1
const char* versionFormat = "%s version %.2f\n\r";
char servicename[40] = "IoTWmodbusBLE-UARTGateway";

#include <M5Atom.h>
#include <ArduinoModbus.h>
#include "shell.h"


void setup() {
  // Init Serial monitor
  //void M5.begin(bool SerialEnable = true, bool I2CEnable = true, bool DisplayEnable = false);
  M5.begin(true, false, false);
  Serial.begin(115200);
  RS485_SERIAL_PORT.begin(9600, SERIAL_8N1, ATOM_RS485_RX, ATOM_RS485_TX);
  if (!ModbusRTUClient.begin(9600)) {
    Serial.println("Failed to start Modbus RTU Client!");
    delay(1000);
  }
  ModbusRTUClient.setTimeout(1000);
  shell.begin(servicename);
  disableEcho();
}


void loop() {
  shell.run();
  delay(10);
}
