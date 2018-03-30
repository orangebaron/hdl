#include "hdl_normal_gates.cpp"
#include "nand_gate.cpp"
#include "repeater_gate.cpp"
#include <iostream>
using namespace hdl;
using std::cout;
using std::endl;

void err(int line) {
  cout<<"ERROR AT LINE "<<line<<endl;
}
int main() {
  if (!NAND.getOtpValues({{false},{false}})[0][0]) err(__LINE__);
  if (!NAND.getOtpValues({{false},{true }})[0][0]) err(__LINE__);
  if (!NAND.getOtpValues({{true },{false}})[0][0]) err(__LINE__);
  if ( NAND.getOtpValues({{true },{true }})[0][0]) err(__LINE__);
  NormalGate NOT {
    {1,"in"},
    {1,"out"},
    {NAND,{"in","in"},{"out"}}
  };
  if (!NOT.getOtpValues({{false}})[0][0]) err(__LINE__);
  if ( NOT.getOtpValues({{true }})[0][0]) err(__LINE__);
  NormalGate AND {
    {{1,"a"},{1,"b"}},
    {1,"out"},
    {{NAND,{"a","b"},{"nand"}},
     {NOT,{"nand"},{"out"}}}
  };
  if ( AND.getOtpValues({{false},{false}})[0][0]) err(__LINE__);
  if ( AND.getOtpValues({{false},{true }})[0][0]) err(__LINE__);
  if ( AND.getOtpValues({{true },{false}})[0][0]) err(__LINE__);
  if (!AND.getOtpValues({{true },{true }})[0][0]) err(__LINE__);
  RepeaterGate Merge8{{{},{},{},{},{},{},{},{}}};
  #define repDigDecl(x) RepeaterGate RepeaterDig##x {{{8,x}}};
  repDigDecl(0);
  repDigDecl(1);
  repDigDecl(2);
  repDigDecl(3);
  repDigDecl(4);
  repDigDecl(5);
  repDigDecl(6);
  repDigDecl(7);
  #undef repDigDecl
  NormalGate AND8 {
    {{8,"a"},{8,"b"}},
    {8,"out"},
    #define repDigChip(x) {RepeaterDig##x,{"a"},{"a"#x}},{RepeaterDig##x,{"b"},{"b"#x}}
    #define andChip(x) {AND,{"a"#x,"b"#x},{"ab"#x}}
    { repDigChip(0),
      repDigChip(1),
      repDigChip(2),
      repDigChip(3),
      repDigChip(4),
      repDigChip(5),
      repDigChip(6),
      repDigChip(7),
      andChip(0),
      andChip(1),
      andChip(2),
      andChip(3),
      andChip(4),
      andChip(5),
      andChip(6),
      andChip(7),
      {Merge8,{"ab0","ab1","ab2","ab3","ab4","ab5","ab6","ab7"},{"out"}}
    }
    #undef repDigChip
  };
  auto vals = AND8.getOtpValues({{false,true,false,false,false,false,true,true},
    {true,false,true,false,false,true,true,true}});
  for (size_t i=0;i<=5;i++) if ( vals[0][i]) err(__LINE__);
  for (size_t i=6;i< 8;i++) if (!vals[0][i]) err(__LINE__);
}
