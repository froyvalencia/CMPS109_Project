#include "Mul.h"
Mul::Mul(){}
Mul::~Mul(){}
void Mul::execute(vector<string> line){

	cout << "executing Mul :" << endl;
	VAR * target = varsMap[i.second.at(1)]; //get VAR* by name

	for(size_t i=2;i<line.size();++i){
		VAR * obj = varMap[i.second.at(1)];
		if(obj == NULL){
			if(Numeric* var = dynamic_cast<Numeric*>(target)){
				var *= stoi(i.second.at(i));
			}else if(Real* var = dynamic_cast<Real*>(target)){
				var *= stod(i.second.at(i));
			}else{
				//error
			}
		}else{
			if(Numeric* var = dynamic_cast<Numeric*>(target)){
				if(Numeric* var2 = dynamic_cast<Numeric*>(obj)){
	          		 var *= var2;
				}
				else if(Real* var2 = dynamic_cast<Real*>(obj)){
					var *= var2->getValue();
				}
			}else if(Real* var = dynamic_cast<Real*>(target) ){
				if(Numeric* var2 = dynamic_cast<Numeric*>(obj)){
	          		 var *= var2->getValue();
				}
				else if(Real* var = dynamic_cast<Real*>(obj)){
					var *= var2;
				}
			}

		}
	}

	int i = 0;
	for(string s : line){
		cout << "Paramater " << ++i <<":" ;
		cout << s << endl;
	}
}
Instruction * Mul::clone(){
	Mul * mul = new Mul();
	return mul;
}