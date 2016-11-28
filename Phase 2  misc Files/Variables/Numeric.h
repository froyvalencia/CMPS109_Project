/*
  @author Froylan Valencia
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myint,NUMERIC,100
*/

#pragma once
#ifndef NUMERIC_H
#define NUMERIC_H
#include <iostream>
#include "VAR.h"

class Numeric : public VAR {
protected:
  int value;
public:
  Numeric();
  Numeric(string n, int v );
  virtual ~Numeric();  
  // A method that initializes the object from a stringstream
  virtual void initialize (vector<string> line); 
  virtual VAR * clone(vector<string> line);
  void setValue(int v);
  int getValue() const;
  //overload operators
  // +, -, *, /, =, 
  Numeric operator*(const Numeric& other);
  //int operator*(const Numeric& other,const Numeric& other2);
  Numeric operator/(const Numeric& other);
  Numeric operator-(const Numeric& other);
  Numeric operator+(const Numeric& other);
  Numeric& operator=(const Numeric& other);
  Numeric& operator=(const int& n);
  Numeric& operator+=(const Numeric& other);
  Numeric& operator+=(const int& i);
  Numeric& operator+=(const double& d);  
  Numeric& operator*=(const Numeric& other);
  Numeric& operator*=(const int& i);
  Numeric& operator*=(const double& d); 
  friend std::ostream& operator<<(std::ostream& os, const Numeric& var); 
};
#endif
