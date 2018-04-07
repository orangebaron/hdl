#ifndef NAND_GATE_HPP
#define NAND_GATE_HPP

#include "hdl_normal_gates.hpp"

namespace hdl {
  struct NandGate: public Gate {
    virtual std::string getName() const;
  	virtual Pins getInps() const;
  	virtual Pins getOtps() const;
  	virtual PinValues getOtpValues(PinValues inpValues);
  } NAND;
}

#endif
