#ifndef CHECK_INPUTS_CPP
#define CHECK_INPUTS_CPP

#include "hdl_basic_classes.hpp"
#include <stdexcept>
#include <iostream>

namespace hdl {
  void checkInputs(const Gate &g,PinValues &inpValues) {
    auto i = g.getInps();
    if (i.size() != inpValues.size()) throw std::invalid_argument(g.getName()+": gate input values 1");
    { size_t counter = 0;
      for (auto v: inpValues) if (v.size()!=i[counter++]) throw std::invalid_argument(g.getName()+": gate input values 2"); }
  }
}

#endif
