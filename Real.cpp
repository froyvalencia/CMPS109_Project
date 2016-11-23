/*
  @author Froylan Valencia
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myfloat,REAL,12.1
*/
#include "Real.h"
std::string Real = "Real";
//constructor
Real::Real() : Real("",0) {}
Real::Real(std::string n,double v){
  name = n;
  type = Real;
  value = v;
}
Real::~Real(){}

void initialize (vector<string> line){
  name = line.at(1);
  type = line.at(2);
  value = stod(line.at(3));
}
VAR* Real::clone (vector<string> line) {
 Real* real = new Real();
real->initialize(line);
return real;
}

//sets value
void Real::setValue(double v){
  value = v;
}

//returns value
double Real::getValue() const{
  return value;
}

//prints the type
//virtual 
void Real::printType(){
  std::cout << type << std::endl;
}

//Operator Overloading
Real Real::operator*(const Real& other){
  int result = value * other.getValue();
  return Real(name, result);
}

Real Real::operator/(const Real& other){
  if(other.getValue() == 0) {
    //std::cout<<"Error: Divide by Zero."<< std::endl;
    //system.exit(1);
  } 
  int result = value / other.getValue();
  return Real(name, result);
}

Real Real::operator-(const Real& other){ //overload +
  int result = value - other.getValue();
  return Real(name, result);
}

Real Real::operator+(const Real& other){ //overload +
  int result = value + other.getValue();
  return Real(name, result);
}

Real& Real::operator=(const Real& other) { // copy assignment
  if (this != &other) { // self-assignment check expected
    //copy data from other's storage to this storage 
    value = other.getValue();
    name = other.name;
  }
  return *this;
}
Real& Real::operator=(const int& n){
