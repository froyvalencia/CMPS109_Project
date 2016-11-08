/*
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myfloat,REAL,12.1
*/

#include "Number.cpp"
using namespace std;
class Real : Number {
private:
  double value;
public:
  Real(string n, double v);
  ~Real();
  void setValue(double v);
  double getValue() const;
  
  Real operator*(const Real& other);
  Real operator/(const Real& other);
  Real operator-(const Real& other);
  Real operator+(const Real& other);
  Real operator=(const Real& other);
};

Real::Real(string n, double v) : Number(n,"Real") {
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
  return Numeric(name, result);
}

Real Real::operator/(const Real& other){
  if(other.getValue() == 0) {
    //print to .errr
    //exit(1)
  }
  int result = value / other.getValue();
  return Numeric(name, result);
}
Real Real::operator-(const Real& other){
  int result = value - other.getValue();
  return Numeric(name, result);
}
Real Real::operator+(const Real& other){
  int result = value + other.getValue();
  return Numeric(name, result);
}

Real& Real::operator=(const Real& other){
  if (this != &other) { // self-assignment check expected
    //copy data from other's storage to this storage
    this->value = other.getValue();
    this->name = other.getName();
  }
  return *this;
}




//random
//Real r = new Real();
//Add(r, 1, 2,3, 4, 5,6, 10.6);
