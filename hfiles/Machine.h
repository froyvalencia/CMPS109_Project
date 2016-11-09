/*
  @author Froylan Valencia a.k.a frvalenc
  Machine class implementation
 */
#ifndef MACHINE_H
#define MACHINE_H

#include <map>
#include <vector>
#include <iostream>
#include "Parser.h"
#include "Instruction.cpp"
#include "Real.cpp"
#include "Numeric.cpp"
#include "Char.cpp"
#include "String.cpp"

class Machine {
 private:
  Parser parser;
  Instruction instructionHandler;
  int next;
  std::vector<std::string> linesOfCode;
  std::map<std::string, int> labels;

  std::map<std::string, Numeric> numericMap;
  std::map<std::string, Real> realMap;
  std::map<std::string, StringVar> stringMap;
  std::map<std::string, CharVar> charMap;
  auto helper(int curr, vector<std::string> &line);
  auto helperOut(int curr, vector<std::string> &line);
protected:
public:
  Machine(std::string filename);  
  //loads mis file to be executed
  void loadFile(std::string filename);
  //main execution loop
  void executeInstruction();
  //executes variable asignment
  void executeAsignment(std::vector<std::string> line);
  //helpre
  auto getVal(std::string s);
  void executeMath(std::vector<std::string> line);  
  //executes String instrucitons
  void executeAlpha(std::vector<std::string> line);
  //helpr for executeAlpha()
  auto getCharVal(std::string s);
  void executeOut(std::vector<std::string> line);  
  //helper for executeOut
  auto getOutVal(std::string s);
};

#endif
