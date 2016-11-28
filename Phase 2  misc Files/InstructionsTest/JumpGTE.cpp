#include "JumpGTE.h"
JumpGTE::JumpGTE(){}
JumpGTE::~JumpGTE(){}

void JumpGTE::execute(Data * d,vector<string> line){
	//next = labelMap[line.at(1)];
}

Instruction * JumpGTE::clone(){
JumpGTE * jmp = new JumpGTE();
	return jmp;
}
