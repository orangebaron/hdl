#include "hdl_normal_gates.cpp"
#include "nand_gate.cpp"
#include <iostream>
using namespace hdl;
using std::cout;
using std::endl;

int main() {
  NandGate NAND;
  cout<<"0 NAND 0: "<<(NAND.getOtpValues({{false},{false}})[0][0]?"1":"0")<<endl;
  cout<<"0 NAND 1: "<<(NAND.getOtpValues({{false},{true}})[0][0]?"1":"0")<<endl;
  cout<<"1 NAND 0: "<<(NAND.getOtpValues({{true},{false}})[0][0]?"1":"0")<<endl;
  cout<<"1 NAND 1: "<<(NAND.getOtpValues({{true},{true}})[0][0]?"1":"0")<<endl;
  NormalGate NOT {
    {1,"in"},
    {1,"out"},
    {NAND,{"in","in"},{"out"}}
  };
  cout<<"NOT 0: "<<(NOT.getOtpValues({{false}})[0][0]?"1":"0")<<endl;
  cout<<"NOT 1: "<<(NOT.getOtpValues({{true}})[0][0]?"1":"0")<<endl;
}
