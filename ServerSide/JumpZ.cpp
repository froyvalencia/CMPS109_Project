#include "JumpZ.h"
JumpZ::JumpZ(){}
JumpZ::~JumpZ(){}
/*
	@params 2
   	1: Label name to jump to.
    2: A numeric variable or constant
    @description
    Apply  the  logic  of  JMP based  on  the  condition result.
    Z:  second  parameter  is  zero
  */
void JumpZ::execute(Data * d,vector<string> line){
	int i;
	VAR * obj = d->getVar(line.at(2));
	if(obj!=NULL){
		if(Numeric* n = dynamic_cast<Numeric*>(obj)) i = n->getValue();
	} else i = stoi(line.at(2));
	if(i==0) d->setCurrent(d->getLabel(line.at(1)));
}

Instruction * JumpZ::clone(){
	JumpZ * jmp = new JumpZ();
	return jmp;
}
