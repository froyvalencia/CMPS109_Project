#include "Assign.h"
Assign::Assign(){}
Assign::~Assign(){}
void Assign::execute(vector<string> line) {
	cout << "executing Assign :" << endl;
	VAR * target = varsMap[i.second.at(1)];
	VAR * first = varMap[i.second.at(2)];
	//get value from first
	if(Numeric* var = dynamic_cast<Numeric*>(target)){
		if(first == NULL){
			var = stoi(i.second.at(2));
		}else{
			Numeric* var2 = dynamic_cast<Numeric*>(first);
			var->setValue(var2->getValue());
		}
	}
	else if(Real* var = dynamic_cast<Real*>(target)) {
		if(first == NULL){
			var = stoi(i.second.at(2));
		}else{
			Real* var2 = dynamic_cast<Real*>(first);
			var->setValue(var2->getValue());
		}
	}
	else if(String* var = dynamic_cast<String*>(target)){
		if(first == NULL){
			var = stoi(i.second.at(2));
		}else{
			String* var2 = dynamic_cast<String*>(first);
			var->setValue(var2->getValue());
		}
	}
	else if(Char* var = dynamic_cast<Char*>(target)) {
		if(first == NULL){
			var = stoi(i.second.at(2));
		}else{
			Char* var2 = dynamic_cast<Char*>(first);
			var->setValue(var2->getValue());
		}
	}
	cout << "finished executing Assign :" << endl;
}

Instruction * Assign::clone(){
	Assign * Assign = new Assign();
	return Assign;
}