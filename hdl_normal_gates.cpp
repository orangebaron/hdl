#ifndef HDL_NORMAL_GATES_CPP
#define HDL_NORMAL_GATES_CPP

#include "hdl_normal_gates.hpp"
#include "check_inputs.cpp"
#include <map>

namespace hdl {
  GateInstance::GateInstance(Gate &gate,std::vector<PinIdentifier> inpNames,std::vector<PinIdentifier> otpNames):
    gate(gate),inpNames(inpNames),otpNames(otpNames) {}
  AliasedPin::AliasedPin(Pin pin,PinIdentifier name):
    pin(pin),name(name) {}
  AliasedPins::AliasedPins(Pin pin,PinIdentifier name):
    pins({pin}),names({name}) {}
  AliasedPins::AliasedPins(Pins pins,std::vector<PinIdentifier> names):
    pins(pins),names(names) {}
  AliasedPins::AliasedPins(std::initializer_list<AliasedPin> args) {
    for (auto p: args) {
      pins.push_back(p.pin);
      names.push_back(p.name);
    }
  }
  NormalGate::NormalGate(AliasedPins inps,AliasedPins otps,GateInstance gate):
    inps(inps),otps(otps),gates({gate}) {}
  NormalGate::NormalGate(AliasedPins inps,AliasedPins otps,std::vector<GateInstance> gates):
    inps(inps),otps(otps),gates(gates) {}
  Pins NormalGate::getInps() { return inps.pins; }
  Pins NormalGate::getOtps() { return otps.pins; }
  PinValues NormalGate::getOtpValues(PinValues inpValues) { //TODO: check if inpValues are right size
    checkInputs(*this,inpValues);
    std::map<PinIdentifier,PinValue> values;
    { char counter = 0;
      for (auto p: inps.names) values[p] = inpValues[counter++]; }
    for (auto g: gates) {
      PinValues inps;
      for (auto p: g.inpNames) inps.push_back(values[p]);
      auto otps = g.gate.getOtpValues(inps);
      { char counter = 0;
        for (auto p: otps) values[g.otpNames[counter++]] = p; }
    }
    PinValues otpValues;
    for (auto p: otps.names) otpValues.push_back(values[p]);
    return otpValues;
  }
}

#endif
