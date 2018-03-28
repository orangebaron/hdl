#ifndef NOR_GATE_HPP
#define NOR_GATE_HPP

#include "hdl_normal_gates.hpp"

namespace hdl {
  struct NorGate: public Gate {
  	virtual Pins getInps();
  	virtual Pins getOtps();
  	virtual PinValues getOtpValues(PinValues inpValues);
  };
}

#endif
