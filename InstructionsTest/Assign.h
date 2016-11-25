#include "Instruction.h"
class Assign : public Instruction {
 public:
  Assign();
  virtual ~Assign();
  virtual void execute();
  virtual Instruction * clone();
};
