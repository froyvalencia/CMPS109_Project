#include "Mul.h"
Mul::Mul(){}
Mul::~Mul(){}
void Mul::execute(vector<string> line){
	cout << "executing Mul :" << endl;
	for(string s : line){
		cout << s << endl;
	}
}
Instruction * Mul::clone(){
	Instruction * mul = new Mul();
	return mul;
}