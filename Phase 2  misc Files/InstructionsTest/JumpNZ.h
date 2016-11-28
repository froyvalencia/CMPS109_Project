#ifndef  JMPNZ_H
#define JMPNZ_H
#include "Instruction.h"
class JumpNZ : public Instruction {
 public:
  JumpNZ();
  virtual ~JumpNZ();
  virtual void execute(Data * d,vector<string> line);
  virtual Instruction * clone();
};
#endif
