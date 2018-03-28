#ifndef NAND_GATE_CPP
#define NAND_GATE_CPP

#include "nand_gate.hpp"
#include "check_inputs.cpp"

namespace hdl {
  Pins NandGate::getInps() { return {1,1}; }
  Pins NandGate::getOtps() { return {1}; }
  PinValues NandGate::getOtpValues(PinValues inpValues) {
    checkInputs(*this,inpValues);
    return {{!(inpValues[0][0]&&inpValues[1][0])}};
  }
}

#endif
