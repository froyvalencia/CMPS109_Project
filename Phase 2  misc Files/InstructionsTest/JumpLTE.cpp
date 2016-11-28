#include "JumpLTE.h"
JumpLTE::JumpLTE(){}
JumpLTE::~JumpLTE(){}

void JumpLTE::execute(Data * d,vector<string> line){
	//next = labelMap[line.at(1)];
}

Instruction * JumpLTE::clone(){
JumpLTE * jmp = new JumpLTE();
	return jmp;
}
