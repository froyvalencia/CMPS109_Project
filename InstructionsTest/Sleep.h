#pragma once
#ifndef Sleep_H
#define Sleep_H
#include "Instruction.h"
class Sleep : public Instruction {
public:
  Sleep();
  virtual ~Sleep();
  virtual void execute(vector<std::string> line);
  virtual Instruction * clone();
};
#endif
