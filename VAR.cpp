/*
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  
  VAR$myint,NUMERIC,100
  VAR$myfloat,REAL,12.14
  
  VAR$mychar,CHAR,’c’
  VAR$mystr,STRING,100,”HelloworldMIS!!!”
*/
//template <class T>
class VAR {
private:
protected:
  string name; //unique name associated with var
  string type; //holds string of type i.e. "Numeric", "Real", "Char", "String",
public:
  VAR(string n, string t){
    name = n;
    type = t;
  }
  virtual void printType(){
    cout<<"Calling Class VAR"<<endl;
  }
  
  string getName();
  //virtual auto getValue()=0;
};

/*
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defa\
ultvalue>
  VAR$mychar,CHAR,’c’
  VAR$mystr,STRING,100,”HelloworldMIS!!!”
*/
class Alpha : VAR {
private:
protected:
public:
  Alpha();

  /*
    @params out 1-12
    Any variables or constants

    @description
    Prints  out  the  parameters to the standard output.
  */
  void OUT(VAR& var);

  /*
    @params 3
    1: String variable
    2. Variable or constant representing an index.
    3: A variable or constant character.

    @description
    Set  a  string  character  at specific  index  to  a c\
haracter.
    Note: index range  should  be  checked and  errors  sh\
ould  be reported.
  */
  void SET_STR_CHAR();

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

