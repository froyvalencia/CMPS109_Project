#include "Div.h"
Div::Div(){}
Div::~Div(){}
void Div::execute(vector<string> line){
	cout << "executing Div :" << endl;
	for(string s : line){
		cout << s << " ";
	}
	cout << endl;
}
Instruction * Div::clone(){
	Div * div = new Div();
	return div;
}