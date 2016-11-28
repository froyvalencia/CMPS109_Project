/*
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myfloat,REAL,12.1
*/
#ifndef REAL_H
#define REAL_H
#include "Number.h"
class Real : public Number {
private:
  double value;
public:
  Real(std::string n, double v);
  ~Real();
  void setValue(double v);
  double getValue() const;
  Real operator*(const Real& other);
  Real operator/(const Real& other);
  Real operator-(const Real& other);
  Real operator+(const Real& other);
  Real& operator=(const Real& other);
};
#endif
