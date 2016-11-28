#include "Assign.h"
Assign::Assign(){}
Assign::~Assign(){}
void Assign::execute(Data *d,vector<string> line) {
	cout << "executing Assign :" << endl;
	VAR * target = d->getVar(line.at(1));
	VAR * first = d->getVar(line.at(2));
	//get value from first
	if(Numeric* var = dynamic_cast<Numeric*>(target)){
		if(first == NULL){
			var->setValue(stoi(line.at(2)));
		}else{
			Numeric* var2 = dynamic_cast<Numeric*>(first);
			var->setValue(var2->getValue());
		}
	}
	else if(Real* var = dynamic_cast<Real*>(target)) {
		if(first == NULL){
			var->setValue(stod(line.at(2)));
		}else{
			Real* var2 = dynamic_cast<Real*>(first);
			var->setValue(var2->getValue());
		}
	}
	else if(String* var = dynamic_cast<String*>(target)){
		if(first == NULL){
			var->setValue(line.at(2));
		}else{
			String* var2 = dynamic_cast<String*>(first);
			var->setValue(var2->getValue());
		}
	}
	else if(Char* var = dynamic_cast<Char*>(target)) {
		if(first == NULL){
			var->setValue(line.at(2)[0]);
		}else{
			Char* var2 = dynamic_cast<Char*>(first);
			var->setValue(var2->getValue());
		}
	}
	cout << "finished executing Assign :" << endl;
}

Instruction * Assign::clone(){
	Assign * assign = new Assign();
	return assign;
}
