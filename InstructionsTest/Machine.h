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
#include "Out.h"
#include "Label.h"
#include "Jump.h"
//#include "SET_STR_CHAR.h"
#include "Label.h"
#include "Jump.h"
#include "JMPZ.h" 
#include "JMPNZ.h" 
#include "JMPGT.h"
#include "JMPLT.h" 
#include "JMPGTE.h"
#include "JMPLTE.h" 
#include "SLEEP.h"
//#include ".h"
//#include ".h"

class Machine {
  friend class Instruction;
 private:
  Parser parser;
  int next;
  bool running;
  std::vector<std::string> linesOfCode;
  std::vector< vector<std::string> > codeMap;
  std::map<std::string, int> labelMap;
  std::map<std::string,VAR *> objMap;//holds base obj REAL,NUM,CHAR,STR
  std::map<std::string,VAR *> varMap;
  std::map<std::string,Instruction *> insMap;//holds base Instruction OBJS
 protected:
public:
  Machine();
  Machine(std::string filename);  
  //loads mis file to be executed
  void loadFile(std::string filename);
  void execute();
};

#endif