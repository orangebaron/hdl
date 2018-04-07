#ifndef GATES_SINGLE_BIT_HPP
#define GATES_SINGLE_BIT_HPP

#include "../hdl_base/hdl_normal_gates.hpp"
#include "../hdl_base/nand_gate.hpp"

namespace hdl_bunch_of_gates {
  using hdl::NormalGate;
  using hdl::NAND;
  NormalGate NOT {
    "NOT",
    {1,"in"},
    {1,"out"},
    {NAND,{"in","in"},{"out"}}
  };
  NormalGate AND {
    "AND",
    {{1,"a"},{1,"b"}},
    {1,"out"},
    { {NAND,{"a","b"},{"!ab"}},
      {NOT,{"!ab"},{"out"}}}
  };
  NormalGate OR {
    "OR",
    {{1,"a"},{1,"b"}},
    {1,"out"},
    { {NOT,{"a"},{"!a"}},
      {NOT,{"b"},{"!b"}},
      {NAND,{"!a","!b"},{"out"}}}
  };
  NormalGate NOR {
    "NOR",
    {{1,"a"},{1,"b"}},
    {1,"out"},
    { {NOT,{"a"},{"!a"}},
      {NOT,{"b"},{"!b"}},
      {AND,{"!a","!b"},{"out"}}}
  };
  NormalGate XOR {
    "XOR",
    {{1,"a"},{1,"b"}},
    {1,"out"},
    { {NAND,{"a","b"},{"!ab"}},
      {NAND,{"a","!ab"},{"1"}},
      {NAND,{"b","!ab"},{"2"}},
      {NAND,{"1","2"},{"out"}}}
  };
  NormalGate XNOR {
    "XNOR",
    {{1,"a"},{1,"b"}},
    {1,"out"},
    { {NAND,{"a","b"},{"!ab"}},
      {NAND,{"a","!ab"},{"1"}},
      {NAND,{"b","!ab"},{"2"}},
      {AND,{"1","2"},{"out"}}}
  };
  NormalGate MUX {
    "MUX",
    {{1,"a"},{1,"b"},{1,"sel"}},
    {1,"out"},
    { {NOT,{"sel"},{"!sel"}},
      {AND,{"a","!sel"},{"1"}},
      {AND,{"b","sel"},{"2"}},
      {OR,{"1","2"},{"out"}}}
  };
  NormalGate DMUX {
    "DMUX",
    {{1,"in"},{1,"sel"}},
    {{1,"a"},{1,"b"}},
    { {NOT,{"sel"},{"!sel"}},
      {AND,{"in","!sel"},{"a"}},
      {AND,{"in","sel"},{"b"}}}
  };
  NormalGate HALFADDER {
    "HALFADDER",
    {{1,"a"},{1,"b"}},
    {{1,"out"},{1,"carry"}},
    { {XOR,{"a","b"},{"out"}},
      {AND,{"a","b"},{"carry"}}}
  };
  NormalGate FULLADDER {
    "FULLADDER",
    {{1,"a"},{1,"b"},{1,"c"}},
    {{1,"out"},{1,"carry"}},
    { {HALFADDER,{"a","b"},{"o1","c1"}},
      {HALFADDER,{"c","o1"},{"out","c2"}},
      {OR,{"c1","c2"},{"out"}}}
  };
}

#endif
