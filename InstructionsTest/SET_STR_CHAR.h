#ifndef  SET_STR_CHAR_H
#define SET_STR_CHAR_H
#include "Instruction.h"
class SET_STR_CHAR : public Instruction {
 public:
  SET_STR_CHAR();
  virtual ~SET_STR_CHAR();
  virtual void execute(Data * d,vector<string> line);
  virtual Instruction * clone();
};
#endif
