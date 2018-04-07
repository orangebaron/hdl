#ifndef FLIP_FLOP_HPP
#define FLIP_FLOP_HPP

#include "hdl_basic_classes.hpp"

namespace hdl {
  struct FlipFlop: public Gate {  // a rising edge D flip flop with active high async inputs
                                  //inputs: clock, D, PRE, CLR
    virtual std::string getName() const;
  	virtual Pins getInps() const;
  	virtual Pins getOtps() const;
  	virtual PinValues getOtpValues(PinValues inpValues);
  private:
    bool lastClock = false;
    bool storedValue = false;
  };
}

#endif
