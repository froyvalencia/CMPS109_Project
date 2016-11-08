/*
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$mystr,STRING,100,”HelloworldMIS!!!”
*/
#include <string>
using namespace std;

class StringVar : Alpha {
private:
  int length;
  string value;
  static const MAX_L = 256;
public:
  StringVar();
  int getLength();
  int getValue();
};

StringVar::StringVar(string n, string v, int l) : Alpha(n,"STRING"){
  value = v;
}
int StringVar::getLength(){
  return length;
}

string StringVar::getValue(){
  return value;
}
void StringVar::setValue(string v){
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
    cout << "Index out of bounds" <<endl; ;
    // throw something
    return value[0];
  }
  return value[i];
}
