#include "Instruction.h"
class Assign : public Instruction {
 public:
  Assign();
  virtual ~Assign();
  virtual void execute(Data *d, vector<string> line);
  virtual Instruction * clone();
};
