Out::Out(){}
Out::~Out(){}

void Out::execute(vector<string> line){
	next = labelMap[line.at(1)];
}

Instruction * Out::clone(){
	Out * out = new Out();
	return out;
}
