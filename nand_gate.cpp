#ifndef NAND_GATE_CPP
#define NAND_GATE_CPP

#include "nand_gate.hpp"
#include "check_inputs.cpp"

namespace hdl {
  std::string NandGate::getName() const { return "NAND"; }
  Pins NandGate::getInps() const { return {1,1}; }
  Pins NandGate::getOtps() const { return {1}; }
  PinValues NandGate::getOtpValues(PinValues inpValues) {
    checkInputs(*this,inpValues);
    return {{!(inpValues[0][0]&&inpValues[1][0])}};
  }
}

#endif
