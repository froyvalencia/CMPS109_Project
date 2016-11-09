/*
  @author Froylan Valencia
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$mychar,CHAR,’c’
*/
#ifndef CHAR_H
#define CHAR_H
#include "Alpha.h"
class CharVar : public Alpha {  
private:
  char value;
public:
  //CharVar(std::string n);
  CharVar(std::string n, char v);
  auto getValue();
  friend std::ostream& operator<<(std::ostream& os, const CharVar& var);
};
#endif
