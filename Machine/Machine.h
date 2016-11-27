/*
  @author Froylan Valencia a.k.a frvalenc
  Machine class implementation
 */
#ifndef MACHINE_H
#define MACHINE_H

#include <map>
#include <vector>
#include <iostream>
#include "Real.h"
#include "Numeric.h"
#include "Char.h"
#include "String.h"
#include "VAR.h"
#include "Parser.h"
#include "Instruction.h"
#include "Add.h"
#include "Sub.h"
#include "Mul.h"
#include "Div.h"
#include "Equals.h"
#include "Assign.h"
//#include "Out.h"
//#include "SET_STR_CHAR.h"
//#include "LABEL"
//#include "JMP.h"
//#include "JMPZ.", "JMPNZ ", "JMPGT ","JMPLT ", 
//     "JMPGTE ", "JMPLTE ", 
//#include "SLEEP.h"
//#include ".h"
//#include ".h"

class Machine {
  friend class Instruction;
 private:
  Parser parser;
  Instruction instructionHandler;
  int next;
  
  std::vector<std::string> linesOfCode;
  std::map<std::string, int> labels;

  std::vector<VAR*> vars;
  std::map<std::string,VAR *> varMap; //
  vector<VAR *> vars;
  std::map<std::string,Instruction *> insMap;
  
  auto helper(int curr, vector<std::string> &line);
  auto helperOut(int curr, vector<std::string> &line);
 protected:

public:
  Machine(std::string filename);  
  //loads mis file to be executed
  void loadFile(std::string filename);
};

#endif
