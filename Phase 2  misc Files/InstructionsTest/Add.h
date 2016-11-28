  /*
    @params 3-13
    1: REAL or Numeric Variable
    Rest: Real or Numeric Variable or Constant.
    
    @description
    Adds all parameters excluding the first one and store the results in the
    first parameter.
  */
#ifndef  ADD_H
#define ADD_H
#include "Instruction.h"
class Add : public Instruction {
 public:
  Add();
  virtual ~Add();
  virtual void execute(Data *d, vector<string> line);
  virtual Instruction * clone();
};
#endif
