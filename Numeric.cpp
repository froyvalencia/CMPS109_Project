/*
  @author Froylan Valencia
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myint,NUMERIC,100
*/
#include "Numeric.h"

//No Value constructor
Numeric (string n): Number(n, "Numeric") {}

//constructor
Numeric::Numeric(string n,int v): Number(n, "Numeric") {
  value = v;
}

//sets value
void Numeric::setValue(int v){
  value = v;
}

//returns value
int Numeric::getValue() const{
  return value;
}

//prints the type
virtual void Numeric::printType(){
  cout<<"Calling Numeric class of type " << type << endl;
}

//Operator Overloading
Numeric Numeric::operator*(const Numeric& other){
  int result = value * other.getValue();
  return Numeric(name, result);
}

Numeric Numeric::operator/(const Numeric& other){
  if(other.getValue() == 0) {
    cout<<"Error: Divide by Zero."<<endl;
    system.exit(1);
  } 
  int result = value / other.getValue();
  return Numeric(name, result);
}

Numeric Numeric::operator-(const Numeric& other){ //overload +
  int result = value - other.getValue();
  return Numeric(name, result);
}

Numeric Numeric::operator+(const Numeric& other){ //overload +
  int result = value + other.getValue();
  return Numeric(name, result);
}

Numeric& Numeric::operator=(const Numeric& other) { // copy assignment
  if (this != &other) { // self-assignment check expected
    //copy data from other's storage to this storage 
    this.value = other.getValue();
    this.name = other.name;
  }
  return *this;
}
