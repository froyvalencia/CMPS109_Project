#ifndef  JMPNZ_H
#define JMPNZ_H
#include "Instruction.h"
class JumpNZ : public Instruction {
 public:
  JumpNZ();
  virtual ~JumpNZ();
  virtual void execute(vector<string> line);
  virtual Instruction * clone();
};
#endif
