#include "JumpGT.h"
JumpGT::JumpGT(){}
JumpGT::~JumpGT(){}

void JumpGT::execute(vector<string> line){
	//next = labelMap[line.at(1)];
}

Instruction * JumpGT::clone(){
	JumpGT * jmp = new JumpGT();
	return jmp;
}
