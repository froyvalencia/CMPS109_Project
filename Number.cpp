/*
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myint,NUMERIC,100
  VAR$myfloat,REAL,12.14
*/

class Number : VAR {
  string type;
protected:  
public:  
  Number(string n, string t);
  string getType();
  virtual void printType();
  
};

Number::Number(string n, string t): VAR(n) {
  type = t;
}

string Number::getType(){
  return type;
}

virtual void Number::printType(){
  cout<<"Calling Class Number of type " << type << endl;
}


  /*
    @params 3-13
    1: REAL or Numeric Variable
    Rest: Real or Numeric Variable or Constant.
    
    @description
    Adds all parameters excluding the first one and store the results in the
    first parameter.
  */
  //template<typename T, typename ... args>
  //void ADD(typename T, typename... args){
  //T.setValue(T.getValue() + sum_of(args) );
  //}template<typename T, typename ... args>
  
  /*
    @params 3
    1: REAL or Numeric Variable
    Rest: Real or Numeric Variable or Constant.
    
    @description
    Subtract the third parameter from the second parameter  
    and store the result in the first parameter
  */
  //  template<typename V, typename ... args>
  //void SUB(typename V, typename ... args);
  
  /*
    @params 3-13
    1: REAL or Numeric
    Variable
    Rest: Real or Numeric
    Variable or Constant.
    
    @description
    Multiply  all  parameters  excluding the first one and
    store the  results  in  the first parameter.
  */
  //template<typename V, typename ... args>
  //void MUL(typename &V, typename ... args);
  
  /*
    @params 3
    1: REAL or Numeric Variable
    Rest: Real or Numeric Variable or Constant.

    @description
    Divide  the  second parameter  by  the  third parameter  and  store  the
    result in  the  first parameter.  Note: divide by zero should be detected
    and  reported,  and  the program  should  tolerate crashes  resulting  from
    divide-by-zero exceptions.
  */
  //template<typename ... args>
  //void DIV(VAR& var,typename ... args);  


