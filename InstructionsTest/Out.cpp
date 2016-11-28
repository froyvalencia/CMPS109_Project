#include "Out.h"
Out::Out(){}
Out::~Out(){}

void Out::execute(Data *d,vector<string> line){
	for(auto s : line){
		VAR* obj = d->getVar(s);
		if(obj!=NULL){
			cout << "Name " << obj->getName();
			if(Numeric *n = dynamic_cast<Numeric*>(obj)){
				cout << " Value: " << n->getValue() << endl;
			}else if(Real *r = dynamic_cast<Real*>(obj)){
				cout << " Value: " << r->getValue() << endl;
			}else if(String *s = dynamic_cast<String*>(obj)){
				cout << " Value: " << s->getValue() << endl;
			}else if(Char *c = dynamic_cast<Char*>(obj)){
				cout << "Name " << c->getName() << " Value: " << c->getValue() << endl;
			}
		}else{
			cout << "Constant: "<< s << endl;
		}
	}
	//next = labelMap[line.at(1)];
}

Instruction * Out::clone(){
	Out * out = new Out();
	return out;
}
