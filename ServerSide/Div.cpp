#include "Div.h"
Div::Div(){}
Div::~Div(){}
void Div::execute(Data *d,vector<string> line) {
	cout << "executing Div :" << endl;
	VAR * target = d->getVar(line.at(1));
	VAR * first = d->getVar(line.at(2));
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

	if(y == 0) return;
	if(Numeric* var = dynamic_cast<Numeric*>(target)) var->setValue(x/y);
	else if(Real* var = dynamic_cast<Real*>(target)) var->setValue(x/y);
	cout << "finished executing Div :" << endl;
}

Instruction * Div::clone(){
	Div * div = new Div();
	return div;
}