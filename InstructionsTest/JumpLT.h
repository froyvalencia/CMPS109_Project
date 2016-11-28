#ifndef  JMPLT_H
#define JMPLT_H
#include "Instruction.h"
class JumpLT : public Instruction {
 public:
  JumpLT();
  virtual ~JumpLT();
  virtual void execute(Data * d,vector<string> line);
  virtual Instruction * clone();
};
#endif
