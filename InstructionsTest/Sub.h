#pragma once
#ifndef Sub_H
#define Sub_H
#include "Instruction.h"
class Sub : public Instruction {
public:
  Sub();
  virtual ~Sub();
  virtual void execute(Data *d, vector<std::string> line);
  virtual Instruction * clone();
};
#endif
