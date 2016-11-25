#pragma once
#ifndef Equal_H
#define Equal_H
#include "Instruction.h"
class Equal : public Instruction {
 public:
  Equal();
  virtual ~Equal();
  virtual void execute(vector<string> line);
  virtual Instruction * clone();
};
#endif