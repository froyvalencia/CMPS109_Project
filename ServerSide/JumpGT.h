#ifndef  JMPGT_H
#define JMPGT_H
#include "Instruction.h"
class JumpGT : public Instruction {
 public:
  JumpGT();
  virtual ~JumpGT();
  virtual void execute(Data * d,vector<string> line);
  virtual Instruction * clone();
};
#endif
