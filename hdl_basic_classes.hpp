#ifndef HDL_BASIC_CLASSES_HPP
#define HDL_BASIC_CLASSES_HPP

#include <vector>
#include <string>

namespace hdl {
  typedef int NumBinaryDigits;
  typedef std::vector<NumBinaryDigits> Pins;
  typedef std::vector<bool> PinValue;
  typedef std::vector<PinValue> PinValues;
  struct Gate {
  	virtual Pins getInps() = 0;
  	virtual Pins getOtps() = 0;
  	virtual PinValues getOtpValues(PinValues inpValues) = 0;
  };
}

#endif
