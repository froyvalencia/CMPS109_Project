#ifndef  JMPGTE_H
#define JMPGTE_H
#include "Instruction.h"
class JumpGTE : public Instruction {
 public:
  JumpGTE();
  virtual ~JumpGTE();
  virtual void execute(vector<string> line);
  virtual Instruction * clone();
};
#endif