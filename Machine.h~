/*
  @author Froylan Valencia a.k.a frvalenc
  Machine class implementation
 */

#include <map>
#include <vector>
#include <iostream>

#include "Parser.h"
#include "Instruction.cpp"

#include "Real.cpp"
#include "Numeric.cpp"
#include "Char.cpp"
#include "String.cpp"

using namespace std;
class Machine {
 private:
  Parser parser;
  Instruction instructionHandler;
  int next;
  vector<std::string> linesOfCode;
  map<std::string, int> labels;
  map<std::string, Numeric> numericMap;
  map<std::string, Real> realMap;
  map<std::string, StringVar> stringMap;
  map<std::string, CharVar> charMap;
 public:
  Machine(std::string filename);  
  //loads mis file to be executed
  void LoadFile(std::string filename);
  //main execution loop
  void executeInstruction();
  //executes variable asignment
  void executeAsignment(vector<std::string> line);
  //helpre 
  auto getVal(std::string s);
  void executeMath(vector<std::string> line);  
  //executes String instrucitons
  executeAlpha(vector<std::string> line);
  //helpr for executeAlpha()
  auto getCharVal(std::string s);
  void executeOut(vector<std::string> line);  
  //helper for executeOut
  auto getOutVal(std::string s);
  }
};
