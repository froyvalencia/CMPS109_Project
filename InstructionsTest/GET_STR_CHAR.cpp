  /*@params 3
    1: String variable
    2. Variable or constant representing an index.
    3: A variable character
    
    @description
    Store the character at the index equivalent to parameter 2 into the third parameters.
  */
#include "GET_STR_CHAR.h"
GET_STR_CHAR::GET_STR_CHAR(){}
GET_STR_CHAR::~GET_STR_CHAR(){}

void GET_STR_CHAR::execute(Data *d, vector<string> line){
	VAR * target = d->getVar(line.at(1));
	VAR * first = d->getVar(line.at(2));
	VAR * second = d->getVar(line.at(3));
	int i;
	char c;
	//get index
	if(Numeric * num = dynamic_cast<Numeric*>(first)) 
		i = num->getValue();
	else i = stoi(line.at(2));

	//get String variable
	if(String * str = dynamic_cast<String*>(target)){
		c = str->getChar(i);
	}else{
		cout << "error target String is not a String obj" << endl;
		//exit(1);
	}
	//get Char variable and set it.
	//if(second != NULL){
	if(Char * chr = dynamic_cast<Char*>(second)){
		chr->setValue(c);
	}else{
		cout << " error second is not char object" << endl;
		//exit(1);
	} 

}

Instruction * GET_STR_CHAR::clone(){
	GET_STR_CHAR * get = new GET_STR_CHAR();
	return get;
}
