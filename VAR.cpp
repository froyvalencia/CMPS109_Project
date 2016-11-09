/*
  @author Froylan Valencia
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myint,NUMERIC,100
  VAR$myfloat,REAL,12.14  
  VAR$mychar,CHAR,’c’
  VAR$mystr,STRING,100,”HelloworldMIS!!!”
*/
#include <iostream>
#include "VAR.h"
VAR::VAR(std::string n, std::string t) {
  name = n;
  type = t;
}
//virtual 
void VAR::printType() const {
  //std::cout << type << std::endl;
}
std::string VAR::getType() const{
  return type;
}
std::string VAR::getName() const{
  return name;
}

//int main(){
//return 0;
//}
