/*
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$mychar,CHAR,’c’
  VAR$mystr,STRING,100,”HelloworldMIS!!!”
*/
#include "Alpha.h"
Alpha::Alpha(string n, string t): VAR(n,t) { 
  cout << " ALPHA CONSTRUCTOR CALLED " << endl;
}

Virtual void Alpha::printType(){
  cout<<"Calling Class Alpha of type " << type << endl;
}
