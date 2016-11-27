Jump::Jump(){}
Jump::~Jump(){}

void Jump::execute(vector<string> line){
	next = labelMap[line.at(1)];
}

Instruction * Jump::clone(){
	Jump * jmp = new Jump();
	return jmp;
}
