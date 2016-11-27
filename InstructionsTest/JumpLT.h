#ifndef  JMPLT_H
#define JMPLT_H
#include "Instruction.h"
class JumpLT : public Instruction {
 public:
  JumpLT();
  virtual ~JumpLT();
  virtual void execute(vector<string> line);
  virtual Instruction * clone();
};
#endif
