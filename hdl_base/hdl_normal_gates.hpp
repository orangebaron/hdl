#ifndef NORMAL_GATES_HPP
#define NORMAL_GATES_HPP

#include "hdl_basic_classes.hpp"
#include <initializer_list>

namespace hdl {
  typedef std::string PinIdentifier;
  struct GateInstance {
  	Gate &gate;
  	std::vector<PinIdentifier> inpNames, otpNames;
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
    NormalGate(std::string name,AliasedPins inps,AliasedPins otps,std::vector<GateInstance> gates);
    NormalGate(std::string name,AliasedPins inps,AliasedPins otps,GateInstance gate);
    virtual std::string getName() const;
  	virtual Pins getInps() const;
    virtual Pins getOtps() const;
    virtual PinValues getOtpValues(PinValues inpValues);
  private:
    std::string name;
    AliasedPins inps;
    AliasedPins otps;
  	std::vector<GateInstance> gates;
  };
}

#endif
