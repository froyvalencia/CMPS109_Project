#pragma once
#ifndef Equal_H
#define Equal_H
#include "Instruction.h"
class Equal : public Instruction {
 public:
  Equal();
  virtual ~Equal();
  virtual void execute(Data *d, vector<string> line);
  virtual Instruction * clone();
};
#endif