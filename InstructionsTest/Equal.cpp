#include "Equal.h"
Equal::Equal(){}
Equal::~Equal(){}
void Equal::execute(vector<string> line){
	cout << "executing Equal :" << endl;
	for(string s : line){
		cout << s << " ";
	}
	cout << endl;
}
Instruction * Equal::clone(){
	Equal * eq = new Equal();
	return eq;
}