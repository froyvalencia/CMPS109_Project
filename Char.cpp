/*
  @author Froylan Valencia
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$mychar,CHAR,’c’

*/

#include "Char.h"
CharVarCharVar(string n);
CharVar::CharVar(string n) : Alpha(n, "CHAR") {
	value = '';
}
CharVar::CharVar(string n, char v) : Alpha(n, "CHAR") {
  value = v;
}



