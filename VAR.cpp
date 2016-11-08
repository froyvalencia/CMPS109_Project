/*
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myint,NUMERIC,100
  VAR$myfloat,REAL,12.14  
  VAR$mychar,CHAR,’c’
  VAR$mystr,STRING,100,”HelloworldMIS!!!”
*/
#include <iostream>
#include <string>
using namespace std;

class VAR {
private:

protected:
  string name; //unique name associated with var
  string type; //holds string of type i.e. "Numeric", "Real", "Char", "Stringg
public:
  VAR(string n, string t){
    cout << "VAR Constructor CALLED" << endl;
    name = n;
    type = t;
  }
  string getType();
  string getName();
  virtual void printType() const {
    cout<<"Calling Class VAR"<<endl;
  }

  //virtual auto getValue()=0;
};
string VAR::getType(){
  return type;
}
string VAR::getName(){
  return name;
}
