/*
  @author Froylan Valencia
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$mystr,STRING,100,”HelloworldMIS!!!”
*/
#include "String.h"
#include <string>
String::String(std::string n, std::string v, int l){
  value = v;
}
String::String(){}
String::~String(){}
void initialize (vector<string> line){
  name = line.at(1);
  type = line.at(2);
  length = stoi(line.at(3));
  value = line.at(4);
}
VAR* String::clone (vector<string> line) {
 String* string = new String();
string->initialize(line);
return string;
}

int String::getLength(){
  return length;
}

auto String::getValue(){
  return value;
}

void String::setValue(std::string v, int l){
  value = v;
  length = l;
}
/*
String& String::operator=(const String& other) { // copy assignment
  if (this != &other) { // self-assignment check expected
    //copy data from other's storage to this storage
    value = other.getValue();
    name = other.getName();
  }
  return *this;
}*/

//operator overload used for set_
char &String::operator[](int i) {
  if( i >= length ) {
    //cout << "Index out of bounds" <<endl; ;
    // throw something
    return value[0];
  }
  return value[i];
}
