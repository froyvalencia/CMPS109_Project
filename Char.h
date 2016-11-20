
/*@author Froylan Valencia
  Char Header File
  Expected instruction lines to work with:
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$mychar,CHAR,’c’
  Char inherits from Alpha to obtain a char value instead of a string value. 
*/
#ifndef CHAR_H
#define CHAR_H
#include "Alpha.h"
class CharVar : public Alpha {  
 private:
  char value;
 public:
  //CharVar(std::string n);
  CharVar(const CharVar&& other);
  CharVar(std::string n, char v);
  char getValue();
  void setValue(char c);
  friend std::ostream& operator<<(std::ostream& os, const CharVar& var);
};
#endif
