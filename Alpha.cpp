/*
  @author Froylan valencia
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$mychar,CHAR,’c’
  VAR$mystr,STRING,100,”HelloworldMIS!!!”
*/
#include "Alpha.h"
Alpha::Alpha(std::string n, std::string t): VAR(n,t) { 
  //std::cout << " ALPHA CONSTRUCTOR CALLED " << endl;
}

//int main(){
//return 0;
//}
