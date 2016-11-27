#include "Instruction.h"
class Assign : public Instruction {
 public:
  Assign();
  virtual ~Assign();
  virtual void execute(vector<string> line);
  virtual Instruction * clone();
};
