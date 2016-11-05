/*
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myfloat,REAL,12.1
*/

class Real : Number {
private:
  double value;
public:
  Real(string name, double val) : Number(name,"Real"){
    value = val;
  }
  void setValue(double val){
    value = val;
  }
  double getValue(){
    return value;
  }
};
//random
//Real r = new Real();
//Add(r, 1, 2,3, 4, 5,6, 10.6);
