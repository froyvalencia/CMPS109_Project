#include "JumpLT.h"
JumpLT::JumpLT(){}
JumpLT::~JumpLT(){}

void JumpLT::execute(vector<string> line){
	//next = labelMap[line.at(1)];
}

Instruction * JumpLT::clone(){
JumpLT * jmp = new JumpLT();
	return jmp;
}
