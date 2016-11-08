/*
  @Froylan Valencia
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myint,NUMERIC,100
  VAR$myfloat,REAL,12.14
*/
#include "Number.h"
//Number
Number::Number(string n, string t) : VAR(n,t) {
}
//print type
virtual void Number::printType(){
	std::cout << "Number class -> Char/String" << std::endl;
}