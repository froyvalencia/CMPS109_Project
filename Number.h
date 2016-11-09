/*
	@author Froylan Valencia
	VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  	VAR$myint,NUMERIC,100
  	VAR$myfloat,REAL,12.14
*/
#include "VAR.cpp"
class Number : public VAR {
  //string type;
protected:
public:  
  Number(std::string n, std::string t); 
  virtual void printType();
};
