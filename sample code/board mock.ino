#define debug 0

#if (debug)
#include "implementations/virtual/VirtualBoardIo.h"
#include "implementations/virtual/VirtualSerialController.h"

BoardIo board = ViritualSerialController(ViritualSerialController());
#else
#include "implementations/physical/PhysicalBoardIo.h"
#include "implementations/physical/PhysicalSerialController.h"
BoardIo board = PhysicalBoardIo(PhysicalSerialController());
#endif

physicalBoardIo.analogRead(0);
