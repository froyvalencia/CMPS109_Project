/*
  @author Froylan Valencia
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$mychar,CHAR,’c’
*/

#include "Char.h"
//Char::Char(std::string n) : Alpha(n, "CHAR") {}
//Char::Char(const Char&& other) : Alpha(name,"CHAR") { 
//value = other.getValue();}
Char::Char(){}
Char::Char(std::string n, char v) {
  value = v;
}
Char::~Char(){}
void initialize(vector<string> line){
  name = line.at(1);
  type = line.at(2);
  value = line.at(3);
}

VAR * Numeric::clone(vector<string> line){
  Numeric * numeric = new Numeric();
  numeric->initialize(line);
  return numeric;
}

char Char::getValue() const{
  return value;
}

void Char::setValue(char c){
  value = c;
}

int main(){
return 0;
}
