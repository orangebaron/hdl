#ifndef NORMAL_GATES_HPP
#define NORMAL_GATES_HPP

#include "hdl_basic_classes.hpp"
#include <initializer_list>

namespace hdl {
  typedef std::string PinIdentifier;
  struct GateInstance {
  	Gate &gate;
  	std::vector<PinIdentifier> inpNames;
  	std::vector<PinIdentifier> otpNames;
    GateInstance(Gate &gate,std::vector<PinIdentifier> inpNames,std::vector<PinIdentifier> otpNames);
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
    NormalGate(AliasedPins inps,AliasedPins otps,GateInstance gate);
    NormalGate(AliasedPins inps,AliasedPins otps,std::vector<GateInstance> gates);
  	virtual Pins getInps();
    virtual Pins getOtps();
    virtual PinValues getOtpValues(PinValues inpValues);
  };
}

#endif
