#ifndef DIV_H
#define DIV_H
#include "Instruction.h"
class Div : public Instruction {
 public:
  Div();
  virtual ~Div();
  virtual void execute(vector<string> line);
  virtual Instruction * clone();
};
#endif