/*
  @author Froylan Valencia 
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$mystr,STRING,100,”HelloworldMIS!!!”
*/
#include <string>
using namespace std;

class StringVar : Alpha {
private:
  int length;
  string value;
  static const MAX_L = 256;
public:
  StringVar();
  StringVar(string n, string v, int l);
  ~StringVar();
  int getLength();
  int getValue();
  StringVar& StringVar::operator=(const StringVar& other); // copy assignment
  char &StringVar::operator[](int i);  //operator overload used for set_ / get_
};
