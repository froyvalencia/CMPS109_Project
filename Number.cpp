/*
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myint,NUMERIC,100
  VAR$myfloat,REAL,12.14
*/
class VAR;
#include "VAR.cpp"
class Number : VAR {
  //string type;
protected:
public:  
  Number(string n, string t); 
  //  virtual void printType();
};
Number::Number(string n, string t): VAR(n,t) {
  type = t;
}
