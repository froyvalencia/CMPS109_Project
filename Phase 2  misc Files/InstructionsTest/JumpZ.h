#ifndef  JMPZ_H
#define JMPZ_H
#include "Instruction.h"
class JumpZ : public Instruction {
 public:
  JumpZ();
  virtual ~JumpZ();
  virtual void execute(Data * d,vector<string> line);
  virtual Instruction * clone();
};
#endif
