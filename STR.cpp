/*
  @author Froylan Valencia
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myint,NUMERIC,100
  VAR$myfloat,REAL,12.14  
  VAR$mychar,CHAR,’c’
  VAR$mystr,STRING,100,”HelloworldMIS!!!”
*/
#include <iostream>
#include "STR.h"

using namespace std;

STR::VAR (string n, string t, string v, string m) {
  
  msg = m;
}




