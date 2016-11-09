/*
  @author Froylan Valencia
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$mychar,CHAR,’c’
  VAR$mystr,STRING,100,”HelloworldMIS!!!”
*/
//@Status -> VAR compiles and works

#include <iostream>
#include <string>
#include "VAR.h"
using namespace std;
class Alpha : VAR {
private:
protected:
public:
  Alpha(string n, string t);
  virtual void printType();
};
