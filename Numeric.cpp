/*
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myint,NUMERIC,100
*/

class Numeric : Number {
  
private:
  int value;
public:
  Numeric(string name,int value) : Number(name) {
  }
  
  
  
};


