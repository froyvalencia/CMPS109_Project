
#include "Mul.h"
Mul::Mul(){}
Mul::~Mul(){}
/*
    @params 3-13
    1: REAL or Numeric 
    Variable
    Rest: Real or Numeric 
    Variable or Constant.
    
    @description
    Multiply  all  parameters  excluding the first one and 
    store the  results  in  the first parameter.
*/
void Mul::execute(Data *d,vector<string> line){
	cout << "executing Mul :" << endl;
	VAR * target = d->getVar(line.at(1)); //get VAR* by name
	//double min = 0;
	for(size_t i=2;i<line.size();++i){
		VAR * obj = d->getVar(line.at(i));
		if(obj == NULL){
			if(Numeric* var = dynamic_cast<Numeric*>(target))
				*var *= stoi(line.at(i));
			else if(Real* var = dynamic_cast<Real*>(target))
				*var *= stod(line.at(i));
		}else {
			if(Numeric* var = dynamic_cast<Numeric*>(target)){
				if(Numeric* var2 = dynamic_cast<Numeric*>(obj))
	          		 *var *= var2->getValue();
				else if(Real* var2 = dynamic_cast<Real*>(obj))
					*var *= var2->getValue();
			}else if(Real* var = dynamic_cast<Real*>(target) ){
				if(Numeric* var2 = dynamic_cast<Numeric*>(obj)) 
					*var *= var2->getValue();
				else if(Real* var2 = dynamic_cast<Real*>(obj))
					*var *= var2->getValue();
			}
		}
	}
}

Instruction * Mul::clone(){
	Mul * mul = new Mul();
	return mul;
}