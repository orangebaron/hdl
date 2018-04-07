#ifndef FLIP_FLOP_CPP
#define FLIP_FLOP_CPP

#include "flip_flop.hpp"
#include "check_inputs.cpp"

namespace hdl {
  std::string FlipFlop::getName() const {
    return "D flip flop";
  }
  Pins FlipFlop::getInps() const {
    return {1,1,1,1};
  }
  Pins FlipFlop::getOtps() const {
    return {1};
  }
  PinValues FlipFlop::getOtpValues(PinValues inpValues) {
    checkInputs(*this,inpValues);
    if (inpValues[2][0]) storedValue = true; //PRE
    else if (inpValues[3][0]) storedValue = false; //CLR
    else if (!lastClock && inpValues[0][0]) storedValue = inpValues[1][0];
    lastClock = inpValues[0][0];
    return {{storedValue}};
  }
}

#endif
