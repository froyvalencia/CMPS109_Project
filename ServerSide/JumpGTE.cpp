#include "JumpGTE.h"
JumpGTE::JumpGTE(){}
JumpGTE::~JumpGTE(){}
  /*
    @params 3
    1: Label name to jump to.
    2: A numeric variable or constant.
    3: A numeric variable or constant.

    @description
    Apply  the  logic  of  JMP based  on  the  comparison 
    condition  result  between the  seconds  and  the  third parameters.
    LT: P2 >= P3,
  */
void JumpGTE::execute(Data * d,vector<string> line){
	VAR * first = d->getVar(line.at(2));
	VAR * second = d->getVar(line.at(3));
	int p2;
	int p3;
	if(first!=NULL){
		if(Numeric* n = dynamic_cast<Numeric*>(first)) p2 = n->getValue();
	}else p2 = stoi(line.at(2));
	
	if(second!=NULL){
		if(Numeric* n = dynamic_cast<Numeric*>(second)) p3 = n->getValue();
	} else p3 = stoi(line.at(3));

	if(p2 >= p3) d->setCurrent(d->getLabel(line.at(1)));
}

Instruction * JumpGTE::clone(){
JumpGTE * jmp = new JumpGTE();
	return jmp;
}
