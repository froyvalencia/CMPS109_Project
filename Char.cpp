/*
  @author Froylan Valencia
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$mychar,CHAR,’c’
*/

#include "Char.h"
//CharVar::CharVar(std::string n) : Alpha(n, "CHAR") {}
CharVar::CharVar(std::string n, char v) : Alpha(n, "CHAR") {
  value = v;
}
auto CharVar::getValue(){
	return value;
}


