/*
  @author Froylan Valencia
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myint,NUMERIC,100
*/
#include "Numeric.h"
std::string NUMERIC = "Numeric";
//constructor
Numeric::Numeric() {}
Numeric::Numeric(std::string n,int v){
  name = n;
  type = NUMERIC;
  value = v;
}

Numeric::~Numeric(){}

void Numeric::initialize(vector<string> line){
  name = line.at(1);
  type = line.at(2);
  value = stoi(line.at(3));
}
VAR * Numeric::clone(vector<string> line){
  Numeric * numeric = new Numeric();
  numeric->initialize(line);
  return numeric;
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
//virtual 

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
//int Numeric::operator+(const Numeric& other){ //overload +
  //int result = value + other->getValue();
  //return int;
//}

Numeric& Numeric::operator=(const Numeric& other) { // copy assignment
  if (this != &other) { // self-assignment check expected
    //copy data from other's storage to this storage 
    value = other.getValue();
    name = other.name;
  }
  return *this;
}
Numeric* Numeric::operator+=(const Numeric* other){
  value += other->getValue();
  return this;
}
Numeric* Numeric::operator+=(const int& i){
  value += i;
  return this;
}
Numeric* Numeric::operator+=(const double& d){
  value += ((int) d);
  return this;
}

Numeric* Numeric::operator*=(const Numeric* other){
  value *= other->getValue();
  return this;
}
Numeric* Numeric::operator*=(const int& i){
  value *= i;
  return this;
}
Numeric* Numeric::operator*=(const double& d){
  value *= ((int) d);
  return this;
}
