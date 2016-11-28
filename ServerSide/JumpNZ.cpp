#include "JumpNZ.h"
JumpNZ::JumpNZ(){}
JumpNZ::~JumpNZ(){}
  
  /*
    @params 2
    1: Label name to jump to.
    2: A numeric variable or constant
    @description
    Apply  the  logic  of  JMP based  on  the  condition result.
    Z:  second  parameter  is  zero
    NZ:  second  parameter  is not zero
  */
void JumpNZ::execute(Data * d, vector<string> line) {
	VAR * obj = d->getVar(line.at(2));
	int i;
	if(obj!=NULL){
		if(Numeric* n = dynamic_cast<Numeric*>(obj)) i = n->getValue();
	} else i = stoi(line.at(2));
	
	if(i != 0) d->setCurrent(d->getLabel(line.at(1)));
}

Instruction * JumpNZ::clone(){
	JumpNZ * jmp = new JumpNZ();
	return jmp;
}
