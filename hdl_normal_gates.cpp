#ifndef HDL_NORMAL_GATES_CPP
#define HDL_NORMAL_GATES_CPP

#include "hdl_normal_gates.hpp"
#include "check_inputs.cpp"
#include <map>

namespace hdl {
  PinSlice::PinSlice(PinIdentifier name,Pin start,Pin end):
    name(name),start(start),end(end) {}
  PinSlice::PinSlice(PinIdentifier name,Pin pinNum):
    PinSlice(name,pinNum,pinNum+1) {}
  PinSlice::PinSlice(PinIdentifier name):
    PinSlice(name,0,0) {}
  GateInstance::GateInstance(Gate &gate,GateIO inps,GateIO otps):
    gate(gate),inps(inps),otps(otps) {}
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
  void checkNormalGate(NormalGate &n) {
    PinValues inps;
    for (auto p: n.getInps()) {
      inps.push_back({});
      inps.back().resize(p);
    }
    auto otps = n.getOtpValues(inps);
    auto expectedOtps = n.getOtps();
    if (expectedOtps.size() != otps.size()) throw std::invalid_argument("gate output values");
    { size_t counter = 0;
      for (auto v: otps) if (v.size()!=expectedOtps[counter++])  throw std::invalid_argument("gate output values"); }
  }
  NormalGate::NormalGate(AliasedPins inps,AliasedPins otps,std::vector<GateInstance> gates):
    inps(inps),otps(otps),gates(gates) { checkNormalGate(*this); }
  NormalGate::NormalGate(AliasedPins inps,AliasedPins otps,GateInstance gate):
    NormalGate(inps,otps,std::vector<GateInstance>{gate}) {}
  Pins NormalGate::getInps() { return inps.pins; }
  Pins NormalGate::getOtps() { return otps.pins; }
  PinValues NormalGate::getOtpValues(PinValues inpValues) {
    checkInputs(*this,inpValues);
    std::map<PinIdentifier,PinValue> values;
    { char counter = 0;
      for (auto p: inps.names) values[p] = inpValues[counter++]; }
    for (auto g: gates) {
      PinValues inps;
      for (auto p: g.inps) {
        PinValue inpVal;
        for (auto i: p)
          if (i.start==i.end)
            for (size_t j=0;j<values[i.name].size();j++)
              inpVal.push_back(values[i.name][j]);
          else
            for (size_t j = i.start;j<i.end;i.start<i.end?j++:j--)
              inpVal.push_back(values[i.name][j]);
        inps.push_back(inpVal);
      }
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
