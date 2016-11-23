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
CharVar::CharVar(std::string n, char v) : Alpha(n, CHAR) {
  value = v;
}

char CharVar::getValue() const{
  return value;
}

void CharVar::setValue(char c){
  value = c;
}

//int main(){
//return 0;
//}



