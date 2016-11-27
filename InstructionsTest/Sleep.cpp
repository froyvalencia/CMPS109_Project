#include "Sleep.h"
Sleep::Sleep(){}
Sleep::~Sleep(){}

void Sleep::execute(vector<string> line){
	VAR * first = varMap[line.at(1)];
	int i;
	if(first != null){
		if(Numeric * num = dynamic_cast<Numeric*>(first))
			i = num->getValue();
		else //if(Real * num = dynamic_cast<Real*>(first)){
			i = stoi(line.at(2));
	}
	sleep(i);
}

Instruction * Sleep::clone(){
	Sleep * set = new Sleep();
	return set;
}