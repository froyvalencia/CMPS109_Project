#include "Out.h"
Out::Out(){}
Out::~Out(){}
void Out::execute(Data *d,vector<string> line){
	for(auto s : line){
		VAR* obj = d->getVar(s);
		if(obj!=NULL){
			cout << "Name " << obj->getName() << " Value: ";
			if(Numeric *n = dynamic_cast<Numeric*>(obj))
				cout << n->getValue() << endl;
			else if(Real *r = dynamic_cast<Real*>(obj))
				cout << r->getValue() << endl;
			else if(String *s = dynamic_cast<String*>(obj))
				cout << s->getValue() << endl;
			else if(Char *c = dynamic_cast<Char*>(obj))
				cout << c->getValue() << endl;
		}else cout << "Constant Vale: " << s << endl;
	}
}

Instruction * Out::clone(){
	Out * out = new Out();
	return out;
}
