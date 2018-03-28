#ifndef NOR_GATE_CPP
#define NOR_GATE_CPP

#include "nor_gate.hpp"
#include "check_inputs.cpp"

namespace hdl {
  Pins NorGate::getInps() { return {1,1}; }
  Pins NorGate::getOtps() { return {1}; }
  PinValues NorGate::getOtpValues(PinValues inpValues) {
    checkInputs(*this,inpValues);
    return {{inpValues[0][0]==inpValues[1][0]}};
  }
}

#endif
