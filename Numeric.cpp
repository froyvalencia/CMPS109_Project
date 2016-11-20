/*
  @author Froylan Valencia
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myint,NUMERIC,100
*/
#include "Numeric.h"

//No Value constructor
Numeric::Numeric(std::string n): Number(n, "Numeric") {}

//constructor
Numeric::Numeric(std::string n,int v): Number(n, "Numeric") {
  value = v;
}

//sets value
void Numeric::setValue(int v){
  value = v;
}

//returns value
auto Numeric::getValue() const{
  return value;
}

//prints the type
//virtual 
void Numeric::printType(){
  //std::cout <<  << std::endl;
}

//Operator Overloading
Numeric Numeric::operator*(const Numeric& other){
  int result = value * other.getValue();
  return Numeric(name, result);
}

Numeric Numeric::operator/(const Numeric& other){
  if(other.getValue() == 0) {
    //std::cout<<"Error: Divide by Zero."<< std::endl;
    //system.exit(1);
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
    value = other.getValue();
    name = other.name;
  }
  return *this;
}
Numeric& Numeric::operator=(const int& n){
  value += n;
  return *this;
}
