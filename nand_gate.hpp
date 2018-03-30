#ifndef NAND_GATE_HPP
#define NAND_GATE_HPP

#include "hdl_normal_gates.hpp"

namespace hdl {
  struct NandGate: public Gate {
  	virtual Pins getInps();
  	virtual Pins getOtps();
  	virtual PinValues getOtpValues(PinValues inpValues);
  } NAND;
}

#endif
