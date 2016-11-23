/*
  @author Froylan Valencia
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$mychar,CHAR,’c’
*/

#include "Char.h"
//CharVar::CharVar(std::string n) : Alpha(n, "CHAR") {}
//CharVar::CharVar(const CharVar&& other) : Alpha(name,"CHAR") { 
//value = other.getValue();}
std::string CHAR = "CHAR";
CharVar::CharVar(std::string n, char v) {
  value = v;
}
<<<<<<< HEAD

char CharVar::getValue() const{
  return value;
=======
auto CharVar::getValue(){
	return value;
>>>>>>> 00d92d04cf7018416aae0fcc725e40b54b06e133
}

void CharVar::setValue(char c){
  value = c;
}

int main(){
return 0;
}
