#include "JumpZ.h"
JumpZ::JumpZ(){}
JumpZ::~JumpZ(){}

void JumpZ::execute(Data * d,vector<string> line){
	//mnext = labelMap[line.at(1)];
}

Instruction * JumpZ::clone(){
	JumpZ * jmp = new JumpZ();
	return jmp;
}
