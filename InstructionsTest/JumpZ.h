#ifndef  JMPZ_H
#define JMPZ_H
#include "Instruction.h"
class JumpZ : public Instruction {
 public:
  JumpZ();
  virtual ~JumpZ();
  virtual void execute(vector<string> line);
  virtual Instruction * clone();
};
#endif
