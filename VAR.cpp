/*
  @author Froylan Valencia
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myint,NUMERIC,100
  VAR$myfloat,REAL,12.14  
  VAR$mychar,CHAR,’c’
  VAR$mystr,STRING,100,”HelloworldMIS!!!”
*/
#include "VAR.h"
VAR::VAR(string n, string t) {
  cout << "VAR Constructor CALLED" << endl;
  name = n;
  type = t;
}
//virtual 
void VAR::printType() const {
  cout<<"Calling Class VAR"<<endl;
}

//virtual auto getValue()=0;
std::string VAR::getType() const{
  return type;
}

std::string VAR::getName() const{
  return name;
}

int main(){
return 0;
}
