#ifndef CHECK_INPUTS_CPP
#define CHECK_INPUTS_CPP

#include "hdl_basic_classes.hpp"
#include <stdexcept>
#include <iostream>
using std::cout;
using std::endl;

namespace hdl {
  void checkInputs(Gate &g,PinValues &inpValues) {
    auto i = g.getInps();
    if (i.size() != inpValues.size()) throw std::invalid_argument("gate input values");
    { size_t counter = 0;
      for (auto v: inpValues) if (v.size()!=i[counter++])  throw std::invalid_argument("gate input values"); }
  }
}

#endif
