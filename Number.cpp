/*
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myint,NUMERIC,100
  VAR$myfloat,REAL,12.14
*/

class Number : VAR {  
protected:
  string name;
public:  
  Number(string name) : VAR(name);
  string getName();
  
  /*
    @params 3-13
    1: REAL or Numeric Variable
    Rest: Real or Numeric Variable or Constant.
    
    @description
    Adds all parameters excluding the first one and store the results in the
    first parameter.
    
  */
  template<typename ... args>
  void ADD(VAR& var, typename... args);
    
  /*
    @params 3
    1: REAL or Numeric Variable
    Rest: Real or Numeric Variable or Constant.
    
    @description
    Subtract  the  third parameter  from  the second  parameter  and
    store the result in the first parameter
  */
  template<typename ... args>
  void SUB(VAR& var, typename ... args);

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
  template<typename ... args>
  void MUL(VAR& var, typename ... args);
  
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
<<<<<<< HEAD
  template<typename ... args>
  void DIV(VAR& var,typename ... args);
=======
  void DIV(VAR& var, VAR v, VAR v2);
  void DIV(VAR& var, double v, double v2);
  void DIV(VAR& var, int v, int v2);
>>>>>>> refs/remotes/origin/master
  
};


