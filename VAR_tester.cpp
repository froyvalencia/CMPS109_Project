#include <iostream>
#include "VAR.cpp"
#include "Alpha.cpp"
#include "Numeric.cpp"
#include "Real.cpp"
#include "String.cpp"
#include "Char.cpp"
#include <string>
#include <vector>

using namespace std;

int main(){
  //StringVar object tested with getValue() to obtain value.
  StringVar myvar("STRING","$mystr", 100);
  cout<<myvar.getValue()<<endl;  



}

