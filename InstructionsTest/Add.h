#ifndef  ADD_H
#define ADD_H
#include "Instruction.h"
class Add : public Instruction {
 public:
  Add();
  virtual ~Add();
  virtual void execute(vector<string> line);
  virtual Instruction * clone();
};
#endif
