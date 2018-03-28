#ifndef NORMAL_GATES_HPP
#define NORMAL_GATES_HPP

#include "hdl_basic_classes.hpp"

namespace hdl {
  typedef std::string PinIdentifier;
  struct GateInstance {
  	Gate &gate;
  	std::vector<PinIdentifier> inpNames;
  	std::vector<PinIdentifier> otpNames;
    GateInstance(Gate &gate,std::vector<PinIdentifier> inpNames,std::vector<PinIdentifier> otpNames);
  };
  struct AliasedPins {
  	Pins pins;
  	std::vector<PinIdentifier> names;
    AliasedPins(Pins pins,std::vector<PinIdentifier> names);
  };
  struct NormalGate: public Gate {
    AliasedPins inps;
    AliasedPins otps;
  	std::vector<GateInstance> gates;
    NormalGate(AliasedPins inps,AliasedPins otps,std::vector<GateInstance> gates);
  	virtual Pins getInps();
    virtual Pins getOtps();
    virtual PinValues getOtpValues(PinValues inpValues);
  };
}

#endif
