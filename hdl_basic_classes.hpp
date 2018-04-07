#ifndef HDL_BASIC_CLASSES_HPP
#define HDL_BASIC_CLASSES_HPP

#include <vector>
#include <string>

namespace hdl {
  typedef size_t Pin; //number of digits in this pin
  typedef std::vector<Pin> Pins;
  typedef std::vector<bool> PinValue;
  typedef std::vector<PinValue> PinValues;
  struct Gate {
  	virtual std::string getName() const = 0;
  	virtual Pins getInps() const = 0;
  	virtual Pins getOtps() const = 0;
  	virtual PinValues getOtpValues(PinValues inpValues) = 0;
  };
}

#endif
