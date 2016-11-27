
/*@author Froylan Valencia
  Char Header File
  Expected instruction lines to work with:
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$mychar,CHAR,’c’
  Char inherits from Alpha to obtain a char value instead of a string value. 
*/
#pragma once
#ifndef CHAR_H
#define CHAR_H
#include "VAR.h"
class Char : public VAR {  
 private:
  char value;
 public:
  Char();
  Char(std::string n, char v);
  ~Char();
  void initialize(vector<string> line);
  VAR * clone(vector<string> line);
  char getValue() const;
  void setValue(char c);
  friend std::ostream& operator<<(std::ostream& os, const Char& var);
};
#endif
