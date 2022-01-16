#include "Arduino.h"
#include "interfaces/BoardIo.h"
#include "interfaces/SerialController.h"

#ifndef debug
#define debug 0
#endif

#if (debug)
#include "implementations/virtual/VirtualBoardIo.h"
#include "implementations/virtual/VirtualSerialController.h"
BoardIo board = VirtualBoardIo(VirtualSerialController());
#else
#include "implementations/physical/PhysicalBoardIo.h"
#include "implementations/physical/PhysicalSerialController.h"
BoardIo board = PhysicalSerialController(PhysicalSerialController());
#endif // if(debug)
