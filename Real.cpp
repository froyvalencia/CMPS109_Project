/*
  @author Froylan Valencia
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myfloat,REAL,12.1
*/
#include "Real.h"
Real::Real(std::string n, double v) : VAR(n,"Real") {
  value = v;
}

void Real::setValue(double v){
  value = v;
}

double Real::getValue() const {
  return value;
}

//Operator Overloading
Real Real::operator*(const Real& other){
  int result = value * other.getValue();
  return Real(name, result);
}

Real Real::operator/(const Real& other){
  if(other.getValue() == 0) {
    //print to .errr
    //exit(1)
  }
  int result = value / other.getValue();
  return Real(name, result);
}

Real Real::operator-(const Real& other){
  int result = value - other.getValue();
  return Real(name, result);
}

Real Real::operator+(const Real& other){
  int result = value + other.getValue();
  return Real(name, result);
}

Real Real::operator=(const Real& other){
  if (this != &other) { // self-assignment check expected
    //copy data from other's storage to this storage
    value = other.getValue();
    name = other.getName();
  }
  return *this;
}
//Real Real::operator=(int i){

//}


//random
//Real r = new Real();
//Add(r, 1, 2,3, 4, 5,6, 10.6);
