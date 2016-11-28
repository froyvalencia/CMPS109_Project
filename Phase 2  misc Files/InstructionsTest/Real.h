/*
  @author Froylan Valencia, Brian Nguyen
  Real Header class
  Expected instrucion line input:
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myfloat,REAL,12.1
  Real class inherits from Number which will recieve a double as the value parameter after having recognized the type in a VAR
*/
#pragma once
#ifndef REAL_H
#define REAL_H
#include <iostream>
#include "VAR.h"
#include "Numeric.h"
class Real : public VAR {
protected:
  double value;
public:
  Real();
  Real(std::string n, double v);
  virtual ~Real();
  // A method that initializes the object from a stringstream
  virtual void initialize (vector<string> line); 
  VAR * clone (vector<string> line);
  void setValue(double v);
  double getValue() const;
  //overload operators
  // +, -, *, /, =, 
  Real operator*(const Real& other);
  //int operator*(const Real& other,const Real& other2);
  Real operator/(const Real& other);
  Real operator-(const Real& other);
  Real operator+(const Real& other);
  Real& operator=(const Real& other);
  Real& operator=(const int& n);
  Real& operator+=(const Real& other);
  Real& operator+=(const int& i);
  Real& operator+=(const double& d);
  Real& operator+=(const Numeric& num); 
  Real& operator*=(const Real& other);
  Real& operator*=(const int& i);
  Real& operator*=(const double& d); 
  Real& operator*=(const Numeric& num);
  friend std::ostream& operator<<(std::ostream& os, const Real& var); 
};
#endif
