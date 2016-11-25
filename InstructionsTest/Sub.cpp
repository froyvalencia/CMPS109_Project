#include "Sub.h"
Sub::Sub(){}
Sub::~Sub(){}
void Sub::execute(vector<string> line){
	cout << "executing Sub :" << endl;
	for(string s : line){
		cout << s << " ";
	}
	cout << endl;
}
Instruction * Sub::clone(){
	Sub * sub = new Sub();
	return sub;
}