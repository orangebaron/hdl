#ifndef GATES_MULTI_BIT_HPP
#define GATES_MULTI_BIT_HPP

#include "gates_single_bit.hpp"
#include "../hdl_base/repeater_gate.hpp"

namespace hdl_bunch_of_gates {
  using hdl::RepeaterGate;

  RepeaterGate r8_0 {{{8,0}}};
  RepeaterGate r8_1 {{{8,1}}};
  RepeaterGate r8_2 {{{8,2}}};
  RepeaterGate r8_3 {{{8,3}}};
  RepeaterGate r8_4 {{{8,4}}};
  RepeaterGate r8_5 {{{8,5}}};
  RepeaterGate r8_6 {{{8,6}}};
  RepeaterGate r8_7 {{{8,7}}};
  RepeaterGate MERGE8{{{},{},{},{},{},{},{},{}}};
  #define repDigChip(bit,numBits) /*repeat digit chip; repeats a certain digit of input*/ \
    {r##numBits##_##bit,{"a"},{"a"#bit}},{r##numBits##_##bit,{"b"},{"b"#bit}}
  #define gateChip(name,bit) /*gate that acts on a certain bit of input*/ \
    {name,{"a"#bit,"b"#bit},{"ab"#bit}}
  #define bitwiseGate8(name) NormalGate name##bw8 { \
    #name "bw2",\
    {{8,"a"},{8,"b"}},\
    {{8,"out"}},\
    { repDigChip(0,8),\
      repDigChip(1,8),\
      repDigChip(2,8),\
      repDigChip(3,8),\
      repDigChip(4,8),\
      repDigChip(5,8),\
      repDigChip(6,8),\
      repDigChip(7,8),\
      gateChip(name,0),\
      gateChip(name,1),\
      gateChip(name,2),\
      gateChip(name,3),\
      gateChip(name,4),\
      gateChip(name,5),\
      gateChip(name,6),\
      gateChip(name,7),\
      {MERGE8,{"ab0","ab1","ab2","ab3","ab4","ab5","ab6","ab7"},{"out"}}}\
  };

  NormalGate NOTbw8 {
    "NOTbw8",
    {8,"in"},
    {8,"out"},
    { {r8_0,{"in"},{"in0"}},
      {r8_1,{"in"},{"in1"}},
      {r8_2,{"in"},{"in2"}},
      {r8_3,{"in"},{"in3"}},
      {r8_4,{"in"},{"in4"}},
      {r8_5,{"in"},{"in5"}},
      {r8_6,{"in"},{"in6"}},
      {r8_7,{"in"},{"in7"}},
      {NOT,{"in0"},{"out0"}},
      {NOT,{"in1"},{"out1"}},
      {NOT,{"in2"},{"out2"}},
      {NOT,{"in3"},{"out3"}},
      {NOT,{"in4"},{"out4"}},
      {NOT,{"in5"},{"out5"}},
      {NOT,{"in6"},{"out6"}},
      {NOT,{"in7"},{"out7"}},
      {MERGE8,{"out0","out1","out2","out3","out4","out5","out6","out7"},{"out"}}}
  };
  bitwiseGate8(AND);
  bitwiseGate8(NAND);
  bitwiseGate8(OR);
  bitwiseGate8(NOR);
  bitwiseGate8(XOR);
  bitwiseGate8(XNOR);
}

#endif
