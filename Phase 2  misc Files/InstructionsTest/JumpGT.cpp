#include "JumpGT.h"
JumpGT::JumpGT(){}
JumpGT::~JumpGT(){}

void JumpGT::execute(Data * d,vector<string> line){
	//next = labelMap[line.at(1)];
}

Instruction * JumpGT::clone(){
	JumpGT * jmp = new JumpGT();
	return jmp;
}
