#ifndef HDL_NORMAL_GATES_CPP
#define HDL_NORMAL_GATES_CPP

#include "hdl_normal_gates.hpp"
#include <map>

namespace hdl {
  Pins NormalGate::getInps() { return inps.pins; }
  Pins NormalGate::getOtps() { return otps.pins; }
  PinValues NormalGate::getOtpValues(PinValues inpValues) { //TODO: check if inpValues are right size
    std::map<PinIdentifier,PinValue> values;
    { char counter = 0;
      for (auto p: inps.names) values[p] = inpValues[counter++]; }
    for (auto g: gates) {
      PinValues inps;
      for (auto p: g.inpNames) inps.push_back(values[p]);
      auto otps = g.gate->getOtpValues(inps);
      { char counter = 0;
        for (auto p: otps) values[g.otpNames[counter++]] = p; }
    }
    PinValues otpValues;
    for (auto p: otps.names) otpValues.push_back(values[p]);
    return otpValues;
  }
}

#endif
