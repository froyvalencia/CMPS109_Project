/*
	@author Froylan Valencia
	VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  	VAR$myint,NUMERIC,100
  	VAR$myfloat,REAL,12.14
*/
#ifndef NUMBER_H
#define NUMBER_H

#include "VAR.cpp"
class Number : public VAR {
  //string type;
protected:
public:  
  Number(std::string n, std::string t); 
  //virtual auto getValue();
  virtual void printType();
};
#endif