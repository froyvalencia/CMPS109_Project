/*
  Instruction Header File

  Expected Instrution Labels in our instruction lines
 
  INSTRUCTUION, NUM OF PARAMS, PARAMETERS, 
  ADD, SUB, MUL, DIV, ASSIGN, OUT, SET_STR_CHAR, LABEL ,JMP, JMP(Z/NZ), JMP(GT/LT/GTE/LTE), SLEEP
  
  Instruction class will hold and handle all of our instruction methods that we will expect as input.

Is friend class to machine
*/
#ifndef INS_H
#define INS_H
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
//#include "Machine.h"
#include "VAR.h"
#include "Real.h"
#include "Numeric.h"
#include "Char.h"
#include "String.h"
#include "Data.h"

class Instruction {
//friend class Machine;
private: 
protected:
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
