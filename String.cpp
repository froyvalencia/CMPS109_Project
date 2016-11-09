/*
  @author Froylan Valencia
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$mystr,STRING,100,”HelloworldMIS!!!”
*/
#include "String.h"
StringVar::StringVar(std::string n, std::string v, int l) : Alpha(n,"STRING"){
  value = v;
}

int StringVar::getLength(){
  return length;
}

auto StringVar::getValue(){
  return value;
}

void StringVar::setValue(std::string v, int l){
  value = v;
  length = l;
}
/*
StringVar& StringVar::operator=(const StringVar& other) { // copy assignment
  if (this != &other) { // self-assignment check expected
    //copy data from other's storage to this storage
    value = other.getValue();
    name = other.getName();
  }
  return *this;
}*/

//operator overload used for set_
char &StringVar::operator[](int i) {
  if( i >= length ) {
    //cout << "Index out of bounds" <<endl; ;
    // throw something
    return value[0];
  }
  return value[i];
}