/*
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myint,NUMERIC,100
*/
#ifndef NUMERIC_H
#define NUMERIC_H
#include <iostream>
//#include <string>

#include "Number.cpp"
class Numeric : public Number {
private:
protected:
  int value;
public:
  Numeric(std::string n);
  Numeric(std::string n,int v);
  ~Numeric();
  void setValue(int v);
  auto getValue() const;
  virtual void printType();  
  //overload operators
  // +, -, *, /, =, 
  Numeric operator*(const Numeric& other);
  Numeric operator/(const Numeric& other);
  Numeric operator-(const Numeric& other);
  Numeric operator+(const Numeric& other);
  Numeric& operator=(const Numeric& other);
  friend std::ostream& operator<<(std::ostream& os, const Numeric& var); 
};
#endif