#ifndef REPEATER_GATE_HPP
#define REPEATER_GATE_HPP

#include "hdl_basic_classes.hpp"

namespace hdl {
  struct RepeaterGate: public Gate { // repeats some of the bits fed into it; used to screw around with arrays
  	virtual Pins getInps();
  	virtual Pins getOtps();
  	virtual PinValues getOtpValues(PinValues inpValues);
    struct InputSlice {
      size_t fullSize, sampleStart, sampleSize;
      InputSlice(size_t fullSize=1,size_t sampleStart=0,size_t sampleSize=1);
    };
    RepeaterGate(std::vector<InputSlice> inps);
  private:
    std::vector<InputSlice> inps;
  };
}

#endif
