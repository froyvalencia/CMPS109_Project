/*
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$mychar,CHAR,’c’
  VAR$mystr,STRING,100,”HelloworldMIS!!!”
*/
#include <iostream>
#include <string>
using namespace std;
class Alpha : VAR {
private:
protected:
public:
  Alpha(string n, string t);
  virtual void printType();
};
