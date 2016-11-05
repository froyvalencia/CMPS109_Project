/*
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myint,NUMERIC,100
*/

class Numeric : Number {
private:
  int value;
public:
  Numeric(string name,int val);
  void setValue(int val);
  int getValue();
  virtual void printType();  
};

Numeric::Numeric(string name,int val): Number(name, "Numeric") {
  value = val;
}
void Numeric::setValue(int val){
  value = val;
}
int Numeric::getValue(){
  return value;
}
virtual void Numeric::printType(){
  cout<<"Calling Numeric class of type "  << endl;
}


