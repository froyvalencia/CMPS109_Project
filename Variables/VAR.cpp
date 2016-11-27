/*
  @author Froylan Valencia, Brian Nguyen
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myint,NUMERIC,100
  VAR$myfloat,REAL,12.14  
  VAR$mychar,CHAR,’c’
  VAR$mystr,STRING,100,”HelloworldMIS!!!”
*/
#include <iostream>
#include "VAR.h"
using namespace std;
VAR::VAR() {}
VAR::~VAR() {}
string VAR::getType() const{ return type;}
string VAR::getName() const{ return name;}
