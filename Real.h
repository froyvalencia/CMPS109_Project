/*
  @author Froylan Valencia
  Real Header class
  Expected instrucion line input:
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myfloat,REAL,12.1
  Real class inherits from Number which will recieve a double as the value parameter after having recognized the type in a VAR
*/
#ifndef REAL_H
#define REAL_H

#include "VAR.h"
class Real : public VAR {
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
  Real operator=(const Real& other);
  Real operator=(int i);
  
};

#endif
