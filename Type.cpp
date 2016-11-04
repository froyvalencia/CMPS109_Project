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
  string type; //holds string of type i.e. "Numeric", "Real", "Char", "String",
  string value;
public:
  VAR(string name, string type, string value){
    this.name = name;
    this.type = type;
    this.value = value;
  }
  
};

class Alpha : VAR {
private:
protected:
public:
  Alpha();
};

class Char : Alpha {
  
private:
  char val;
public:
  Char();
};

class String : Alpha {
private:
  int size;
  string val;
public:
  String();
  
};

class Number : VAR {  
private:
  string name;
public:
  auto add(auto num,auto num2){
    return num+num2;
  }
};

class Real : Number {
private:
  double val;
public:
  Real();
};

class Numeric : Number {
private:
  int val;
public:
  Numeric();

};

