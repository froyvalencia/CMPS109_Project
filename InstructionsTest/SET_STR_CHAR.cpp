#include "SET_STR_CHAR.h"
SET_STR_CHAR::SET_STR_CHAR(){}
SET_STR_CHAR::~SET_STR_CHAR(){}

  /*
    @params 3
    1: String variable
    2. Variable or constant representing an index.
    3: A variable or constant character.
    
    @description
    Set  a  string  character  at specific  index  to  a character.
    Note: index range  should  be  checked and  errors  should  be reported.
  */
void SET_STR_CHAR::execute(Data * d,vector<string> line){
	VAR * target = d->getVar(line.at(1));
	VAR * first = d->getVar(line.at(2));
	VAR * second = d->getVar(line.at(3));
	int i;
	char c;
	if(Numeric * num = dynamic_cast<Numeric*>(first))
		i = num->getValue();
	else //if(Real * num = dynamic_cast<Real*>(first)){
		i = stoi(line.at(2));
	
	if(Char * chr = dynamic_cast<Char*>(second))
		c = chr->getValue();
	else 
		c = ((char)line.at(3)[0]);
	

	if(String * str = dynamic_cast<String*>(target)){
		str->setAt(c,i);	
	}
}

Instruction * SET_STR_CHAR::clone(){
	SET_STR_CHAR * set = new SET_STR_CHAR();
	return set;
}
