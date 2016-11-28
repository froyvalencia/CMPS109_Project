#ifndef  JMPLTE_H
#define JMPLTE_H
#include "Instruction.h"
class JumpLTE : public Instruction {
 public:
  JumpLTE();
  virtual ~JumpLTE();
  virtual void execute(Data * d,vector<string> line);
  virtual Instruction * clone();
};
#endif
