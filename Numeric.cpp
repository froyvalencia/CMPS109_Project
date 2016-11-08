/*
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myint,NUMERIC,100
*/

class Numeric : Number {
private:
  int value;
public:
  Numeric(string n);
  Numeric(string n,int v);
  ~Numeric();
  void setValue(int v);
  int getValue();
  virtual void printType();  
  //overload operators
  // +, -, *, /, =, 
  Numeric Numeric::operator*(const Numeric& other);
  Numeric Numeric::operator/(const Numeric& other);
  Numeric Numeric::operator-(const Numeric& other);
  Numeric Numeric::operator+(const Numeric& other);
  Numeric Numeric::operator=(const Numeric& other);
  friend ostream& operator<<(ostream& os, const Numeric& var); 
};

//No Value constructor
Numeric::Numeric(string n): Number(n, "Numeric") {}
//constructor
Numeric::Numeric(string n,int val): Number(n, "Numeric") {
  value = v;
}
//sets value
void Numeric::setValue(int v){
  value = v;
}
//returns value
int Numeric::getValue(){
  return value;
}
//prints the type
virtual void Numeric::printType(){
  cout<<"Calling Numeric class of type " << type << endl;
}

//Operator Overloading
Numeric Numeric::operator*(const Numeric& other){
  int result = value * other.getValue();
  return Numeric(name, result);
}

Numeric Numeric::operator/(const Numeric& other){
  if(other.getValue() == 0) {
    //print to .errr
    //exit(1)
  } 
  int result = value / other.getValue();
  return Numeric(name, result);
}
Numeric Numeric::operator-(const Numeric& other){ //overload +
  int result = value - other.getValue();
  return Numeric(name, result);
}
Numeric Numeric::operator+(const Numeric& other){ //overload +
  int result = value + other.getValue();
  return Numeric(name, result);
}
Numeric& Numeric::operator=(const Numeric& other) { // copy assignment
  if (this != &other) { // self-assignment check expected
    //copy data from other's storage to this storage 
    this.value = other.getValue();
    this.name = other.name;
  }
  return *this;
}
