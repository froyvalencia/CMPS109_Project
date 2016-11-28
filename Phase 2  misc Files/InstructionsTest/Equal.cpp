#include "Equal.h"
Equal::Equal(){}
Equal::~Equal(){}
void Equal::execute(Data *d, vector<string> line){
	cout << "executing Equal :" << endl;
	int i = 0;
	for(string s : line){
		cout << "Paramater " << ++i <<":" ;
		cout << s << endl;
	}
}

Instruction * Equal::clone(){
	Equal * eq = new Equal();
	return eq;
}