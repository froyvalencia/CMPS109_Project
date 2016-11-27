/*
  @author Froylan Valencia a.k.a frvalenc
  Machine class implementation
*/
#include "Machine.h"
Machine::Machine(){}
Machine::Machine(std::string filename){
  next = 0;
  loadFile(filename);
}
void Machine::loadFile(std::string filename){
  linesOfCode = parser.parseFile(filename);
}
  
