#include "Jump.h"
Jump::Jump(){}
Jump::~Jump(){}
void Jump::execute(Data * d,vector<string> line){
	int n = d->getLabel(line.at(1));
	d->setCurrent(n);//next = labelMap[line.at(1)];
}
Instruction * Jump::clone(){
	Jump * jmp = new Jump();
	return jmp;
}
