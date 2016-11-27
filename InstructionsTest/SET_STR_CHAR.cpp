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
void SET_STR_CHAR::execute(vector<string> line){
	VAR * target = varMap[line.at(1)];
	VAR * first = varMap[line.at(2)];
	VAR * second = varMap[line.at(3)];
	int i;
	char c;
	if(first != null){
		if(Numeric * num = dynamic_cast<Numeric*>(first))
			i = num->getValue();
		else //if(Real * num = dynamic_cast<Real*>(first)){
			i = stoi(line.at(2));
	}
	if(second != NULL){
		if(Char * chr = dynamic_cast<Char*>(second)){
			c = chr->getValue();
		}else 
			c = ((char)line.at(3));
	}

	if(String * str = dynamic_cast<String*>(target)){
		str[i] = c;	
	}
}

Instruction * SET_STR_CHAR::clone(){
	SET_STR_CHAR * set = new SET_STR_CHAR();
	return set;
}
