#pragma once
#ifndef MUL_H
#define MUL_H
#include "Instruction.h"
class Mul : public Instruction {
 public:
  Mul();
  virtual ~Mul();
  virtual void execute(Data *d, vector<string> line);
  virtual Instruction * clone();
};
#endif
