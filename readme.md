# IoThingsWare Modbus BLE-UART Gateway

## Modbus Functions

### coilRead()

#### Description

Perform a "Read Coils" operation for the specified address for a single coil.

#### Syntax

``
coilRead(int id, int address);
``

#### Parameters
- id (slave) - id of target, defaults to 0x00 if not specified
- address address to use for operation


#### Returns
coil int value on success, -1 on failure.

### discreteInputRead()

#### Description

Perform a "Read Discrete Inputs" operation for the specified address for a single discrete input.

#### Syntax

``
discreteInputRead(int id, int address);
``

#### Parameters
- id (slave) - id of target, defaults to 0x00 if not specified
- address address to use for operation


#### Returns
discrete input int value on success, -1 on failure.

### holdingRegisterRead()

#### Description

Perform a "Read Holding Registers" operation for a single holding register.

#### Syntax

``
holdingRegisterRead(int id, int address);
``

#### Parameters

- id (slave) - id of target, defaults to 0x00 if not specified
- address start address to use for operation

#### Returns
holding register long value on success, -1 on failure.

### inputRegisterRead()

#### Description

Perform a "Read Input Registers" operation for a single input register.

#### Syntax

``
inputRegisterRead(int id, int address);
``

#### Parameters
- id (slave) - id of target, defaults to 0x00 if not specified
- address address to use for operation


#### Returns
input register long value on success, -1 on failure.

### coilWrite()

#### Description

Perform a "Write Single Coil" operation for the specified address and value.

#### Syntax

``
coilWrite(int id, int address, uint8_t value);
``

#### Parameters
- id (slave) - id of target, defaults to 0x00 if not specified
- address address to use for operation
- value coi -l value to write


#### Returns
return an int value: 1 on success; 0 on failure.

### holdingRegisterWrite()

#### Description

Perform a "Write Single Holding Register" operation for the specified address and value.

#### Syntax

``
int holdingRegisterWrite(int id, int address, uint16_t value);
``

#### Parameters
- id (slave) - id of target, defaults to 0x00 if not specified
- address address to use for operation
- value - holding register value to write


#### Returns
Return an int value: 1 on success; 0 on failure.

### registerMaskWrite()

#### Description

Perform a "Mask Write Registers" operation for the specified address, AND mask and OR mask.

#### Syntax

``
registerMaskWrite(int id, int address, uint16_t andMask, uint16_t orMask);
``

#### Parameters
- id (slave) - id of target, defaults to 0x00 if not specified
- address address to use for operation
- andMask - AND mask to use for operation
- orMask - OR mask to use for operation


#### Returns
Return an int value: 1 on success; 0 on failure.
