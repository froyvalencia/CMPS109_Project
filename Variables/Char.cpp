/*
  @author Froylan Valencia
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$mychar,CHAR,’c’
*/

#include "Char.h"
Char::Char(){ }
Char::Char(std::string n, char v) {
  value = v;
}
Char::~Char(){}
void Char::initialize(vector<string> line){
  name = line.at(1);
  type = line.at(2);
  value = line.at(3).c_str()[0];
}

VAR * Char::clone(vector<string> line){
  Char * chr = new Char();
  chr->initialize(line);
  return chr;
}

char Char::getValue() const {
  return value;
}

void Char::setValue(char c){
  value = c;
}

