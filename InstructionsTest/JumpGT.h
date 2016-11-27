#ifndef  JMPGT_H
#define JMPGT_H
#include "Instruction.h"
class JumpGT : public Instruction {
 public:
  JumpGT();
  virtual ~JumpGT();
  virtual void execute(vector<string> line);
  virtual Instruction * clone();
};
#endif
