#include "JumpLT.h"
JumpLT::JumpLT(){}
JumpLT::~JumpLT(){}

void JumpLT::execute(Data * d,vector<string> line){
	//next = labelMap[line.at(1)];
}

Instruction * JumpLT::clone(){
JumpLT * jmp = new JumpLT();
	return jmp;
}
