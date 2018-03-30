#ifndef NORMAL_GATES_HPP
#define NORMAL_GATES_HPP

#include "hdl_basic_classes.hpp"
#include <initializer_list>

namespace hdl {
  typedef std::string PinIdentifier;
  struct PinSlice {
    PinIdentifier name;
    Pin start, end;
    PinSlice(PinIdentifier name,Pin start,Pin end);
    PinSlice(PinIdentifier name,Pin pinNum);
    PinSlice(PinIdentifier name);
  };
  typedef std::vector<PinSlice> GateIO;
  struct GateIOs {
    std::vector<GateIO> ios;
    GateIOs(std::vector<GateInput> inps);
    GateIOs(std::vector<PinSlice> inputs);
  };
  struct GateInstance {
  	Gate &gate;
  	GateIO inps, otps;
    GateInstance(Gate &gate,GateIO inps,GateIO otps);
  };
  struct AliasedPin {
  	Pin pin;
  	PinIdentifier name;
    AliasedPin(Pin pin,PinIdentifier name);
  };
  struct AliasedPins {
  	Pins pins;
  	std::vector<PinIdentifier> names;
    AliasedPins(Pin pin,PinIdentifier name);
    AliasedPins(std::initializer_list<AliasedPin>);
    AliasedPins(Pins pins,std::vector<PinIdentifier> names);
  };
  struct NormalGate: public Gate {
    AliasedPins inps;
    AliasedPins otps;
  	std::vector<GateInstance> gates;
    NormalGate(AliasedPins inps,AliasedPins otps,std::vector<GateInstance> gates);
    NormalGate(AliasedPins inps,AliasedPins otps,GateInstance gate);
  	virtual Pins getInps();
    virtual Pins getOtps();
    virtual PinValues getOtpValues(PinValues inpValues);
  };
}

#endif
