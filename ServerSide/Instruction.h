/*
  Froylan Valencia
  Abstract base class for instructions
  Instruction Header File
  Expected Instrution Labels in our instruction lines
  INSTRUCTUION, NUM OF PARAMS, PARAMETERS, 
  ADD, SUB, MUL, DIV, ASSIGN, OUT, SET_STR_CHAR, LABEL ,JMP, JMP(Z/NZ), JMP(GT/LT/GTE/LTE), SLEEP
  Instruction class will be the base class for all instruction operations.
*/
#ifndef INS_H
#define INS_H
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include "VAR.h"
#include "Real.h"
#include "Numeric.h"
#include "Char.h"
#include "String.h"
#include "Data.h"
class Instruction {
public:
  //constructor
  Instruction();
  //desctructor
  virtual ~Instruction();
  virtual void execute(Data * d,vector<string> line)=0;
  // virtual string getType() const;
  virtual Instruction* clone()=0;
};
#endif
