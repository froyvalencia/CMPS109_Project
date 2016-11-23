
/*@author Froylan Valencia
  Char Header File
  Expected instruction lines to work with:
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$mychar,CHAR,’c’
  Char inherits from Alpha to obtain a char value instead of a string value. 
*/
#ifndef CHAR_H
#define CHAR_H
#include "VAR.h"
class CharVar : public VAR {  
 private:
  char value;
 public:
  CharVar();
  CharVar(std::string n, char v);
  ~CharVar();
  void initialize(vector<string> line);
  VAR * Numeric::clone(vector<string> line);
  char getValue() const;
  void setValue(char c);
  friend std::ostream& operator<<(std::ostream& os, const CharVar& var);
};
#endif
