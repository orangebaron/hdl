#include "hdl_normal_gates.cpp"
#include "nand_gate.cpp"
#include <iostream>
using namespace hdl;
using std::cout;
using std::endl;

void err(int line) {
  cout<<"ERROR AT LINE "<<line<<endl;
}
int main() {
  NandGate NAND;
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
}
