  /*@params 3
    1: String variable
    2. Variable or constant representing an index.
    3: A variable character or constant character
    
    @description
    Store the character at the index equivalent to parameter 2 into the third parameters.
  */
#ifndef  GET_STR_CHAR_H
#define GET_STR_CHAR_H
#include "Instruction.h"
class GET_STR_CHAR : public Instruction {
private:
 public:
  GET_STR_CHAR();
  virtual ~GET_STR_CHAR();
  virtual void execute(Data *d, vector<string> line);
  virtual Instruction * clone();
};
#endif