#include "JumpNZ.h"
JumpNZ::JumpNZ(){}
JumpNZ::~JumpNZ(){}

void JumpNZ::execute(Data * d,vector<string> line){
	//next = labelMap[line.at(1)];
}

Instruction * JumpNZ::clone(){
	JumpNZ * jmp = new JumpNZ();
	return jmp;
}
