/*
  @author Froylan Valencia
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$mystr,STRING,100,”HelloworldMIS!!!”
*/
#include "String.h"
using namespace std;
StringVar::StringVar(std::string n, std::string v, int l) : Alpha(n,"STRING"){
  value = v;
}
int StringVar::getLength(){
  return length;
}

using namespace std;
string StringVar::getValue(){
  return value;
}

using namespace std;
void StringVar::setValue(std::string v){
  value = v;
  length = v.length;
}

StringVar& StringVar::operator=(const StringVar& other) { // copy assignment
  if (this != &other) { // self-assignment check expected
    //copy data from other's storage to this storage
    this.value = other.getValue();
    this.name = other.getName();
  }
  return *this;
}

//operator overload used for set_
char &StringVar::operator[](int i) {
  if( i >= SIZE ) {
    //cout << "Index out of bounds" <<endl; ;
    // throw something
    return value[0];
  }
  return value[i];
}