/*
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myint,NUMERIC,100
  VAR$myfloat,REAL,12.14  
  VAR$mychar,CHAR,’c’
  VAR$mystr,STRING,100,”HelloworldMIS!!!”
*/
class VAR {
private:
protected:
  string name; //unique name associated with var
  string type; //holds string of type i.e. "Numeric", "Real", "Char", "String"
public:
  VAR(string n, string t){
    cout << "VAR Constructor CALLED" << endl;
    name = n;
    type = t;
  }
  virtual void printType(){
    cout<<"Calling Class VAR"<<endl;
  }
  string getType();
  string getName();
  //virtual auto getValue()=0;
};
string VAR::getType(){
  return type;
}
string VAR::getName(){
  return name;
}
