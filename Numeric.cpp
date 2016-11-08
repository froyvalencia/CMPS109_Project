/*
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myint,NUMERIC,100
*/
#include <iostream>
#include <string>

#include "Number.cpp"
using namespace std;
class Numeric : public Number {

private:
protected:
  int value;
public:
  //Numeric(string n);
  Numeric(string n,int v);
  ~Numeric();
  void setValue(int v);
  int getValue() const;
  virtual void printType();  
  //overload operators
  // +, -, *, /, =, 
  Numeric operator*(const Numeric& other);
  Numeric operator/(const Numeric& other);
  Numeric operator-(const Numeric& other);
  Numeric operator+(const Numeric& other);
  Numeric operator=(const Numeric& other);
  friend ostream& operator<<(ostream& os, const Numeric& var); 

};

//No Value constructor
//Numeric (string n): Number(n, "Numeric") {;}
//constructor
Numeric (string n,int v): Number(n, "Numeric") {
  value = v;
}
//sets value
void setValue(int v){
  value = v;
}
//returns value
int getValue() const{
  return value;
}
//prints the type
virtual void printType(){
  cout<<"Calling Numeric class of type " << type << endl;
}
//Operator Overloading
Numeric operator*(const Numeric& other){
  int result = value * other.getValue();
  return Numeric(name, result);
}

Numeric operator/(const Numeric& other){
  if(other.getValue() == 0) {
    cout<<"Error: Divide by Zero."<<endl;
    system.exit(1);
  } 
  int result = value / other.getValue();
  return Numeric(name, result);
}
Numeric operator-(const Numeric& other){ //overload +
  int result = value - other.getValue();
  return Numeric(name, result);
}
Numeric operator+(const Numeric& other){ //overload +
  int result = value + other.getValue();
  return Numeric(name, result);
}
Numeric& operator=(const Numeric& other) { // copy assignment
  if (this != &other) { // self-assignment check expected
    //copy data from other's storage to this storage 
    this.value = other.getValue();
    this.name = other.name;
  }
  return *this;
}
