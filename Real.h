/*
  @author Froylan Valencia, Brian Nguyen
  Real Header class
  Expected instrucion line input:
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myfloat,REAL,12.1
  Real class inherits from Number which will recieve a double as the value parameter after having recognized the type in a VAR
*/
#ifndef REAL_H
#define REAL_H
#include <iostream>
#include "VAR.h"

class Real : public VAR {
protected:
  double value;
public:
  Real();
  Real(double v);
  virtual ~Real();
  // A method that initializes the object from a stringstream
  virtual void initialize (vector<string> line); 
  VAR * clone (vector<string> line);
  void setValue(double v);
  int getValue() const;
  //overload operators
  // +, -, *, /, =, 
  Real operator*(const Real& other);
  //int operator*(const Real& other,const Real& other2);
  Real operator/(const Real& other);
  Real operator-(const Real& other);
  Real operator+(const Real& other);
  Real& operator=(const Real& other);
  Real& operator=(const int& n);
  friend std::ostream& operator<<(std::ostream& os, const Real& var); 
};
#endif
