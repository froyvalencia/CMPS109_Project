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
#include "Equal.h"
#include "Assign.h"
#include "Out.h"
#include "Label.h"
#include "Jump.h"
#include "SET_STR_CHAR.h"
#include "GET_STR_CHAR.h"
#include "Label.h"
#include "Jump.h" 
#include "JumpZ.h"
#include "JumpNZ.h" 
#include "JumpGT.h"
#include "JumpLT.h" 
#include "JumpGTE.h"
#include "JumpLTE.h" 
#include "Sleep.h"
#include "Data.h"
class Machine {
  //friend class Instruction;
 private:
  Parser parser;
  int next;
  bool run;
  std::vector<std::string> codeLines;
  std::vector< vector<std::string> > code;
  std::map<std::string,VAR *> objMap;//holds base obj REAL,NUM,CHAR,STR
  //std::map<std::string,VAR *> varMap;
  Data * data;
  std::map<std::string,Instruction *> insMap;//holds base Instruction OBJS
 protected:
public:
  Machine();
  Machine(std::string filename);  
  //loads mis file to be executed
  void loadFile(std::string filename);
  VAR * getVar(string varName);
  bool running();
  void executeNext();
  void executeAll();

};

#endif
