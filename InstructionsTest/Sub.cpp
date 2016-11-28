#include <string>
#include "Sub.h"
Sub::Sub(){}
Sub::~Sub(){}
void Sub::execute(Data *d, vector<string> line){
	cout << "executing Sub :" << endl;
	VAR * target = d->getVar(line.at(1));
	if(target == NULL) cout << "targert == NULL\n";
	VAR * first = d->getVar(line.at(2));
	if(first == NULL) cout << "First == NULL\n";
	VAR * second = d->getVar(line.at(3));

	double x,y;
	//get value from first
	if(Numeric* var = dynamic_cast<Numeric*>(first)) x = var->getValue();
	else if(Real* var = dynamic_cast<Real*>(first)) x = var->getValue();
	else x = stod(line.at(2));
	//get value from second
	if(Numeric* var = dynamic_cast<Numeric*>(second)) y = var->getValue();
	else if(Real* var = dynamic_cast<Real*>(second)) y = var->getValue();
	else y = stod(line.at(3));

	if(Numeric* var = dynamic_cast<Numeric*>(target)) var->setValue(x-y);
	else if(Real* var = dynamic_cast<Real*>(target)) var->setValue(x-y);
	cout << "executing Sub finished:" << endl;
}

Instruction * Sub::clone(){
	Sub * sub = new Sub();
	return sub;
}
