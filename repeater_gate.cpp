#ifndef REPEATER_GATE_CPP
#define REPEATER_GATE_CPP

#include "repeater_gate.hpp"
#include "check_inputs.cpp"
#include <stdexcept>

namespace hdl {
  Pins RepeaterGate::getInps() {
    Pins returnVal;
    for (auto i: inps) returnVal.push_back(i.fullSize);
    return returnVal;
  }
  Pins RepeaterGate::getOtps() {
    size_t returnVal;
    for (auto i: inps) returnVal += i.sampleSize;
    return {returnVal};
  }
  PinValues RepeaterGate::getOtpValues(PinValues inpValues) {
    checkInputs(*this,inpValues);
    PinValue returnVal;
    for (size_t i=0;i<inps.size();i++)
      for (size_t j=0;j<inps[i].sampleSize;j++)
        returnVal.push_back(inpValues[i][inps[i].sampleStart+j]);
    return {returnVal};
  }
  RepeaterGate::RepeaterGate(std::vector<InputSlice> inps): inps(inps) {
    for (auto i: inps) if (i.sampleStart+i.sampleSize > i.fullSize) throw std::invalid_argument("repeater gate has too small a fullSize");
  }
  RepeaterGate::InputSlice::InputSlice(size_t fullSize,size_t sampleStart,size_t sampleSize):
    fullSize(fullSize), sampleStart(sampleStart), sampleSize(sampleSize) {}
}

#endif
