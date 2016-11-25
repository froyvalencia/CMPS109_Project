#include "Add.h"
Add::Add(){}
Add::~Add(){}
void Add::execute(vector<string> line){
	cout << "executing ADD :" << endl;
	for(string s : line){
		cout << s << " ";
	}
	cout << endl;
}
Instruction * Add::clone(){
	Add * add = new Add();
	return add;
}
