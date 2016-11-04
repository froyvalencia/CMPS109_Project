/*
  VAR<name>,<type>,<optional:sizeincaseofstringonly>,<defaultvalue>
  VAR$myint,NUMERIC,100
  VAR$myfloat,REAL,12.14
*/
class Number : VAR {  
private:
  string name;
public:  
  /*
    @params 3-13
    1: REAL or Numeric Variable
    Rest: Real or Numeric Variable or Constant.

    @description
    Adds all parameters excluding the first one and store the results in the
    first parameter.
  */
  void ADD(VAR& var, std::vector<VAR> addList);

  /*
    @params 3
    1: REAL or Numeric Variable
    Rest: Real or Numeric Variable or Constant.

    @description
    Subtract  the  third parameter  from  the second  parameter  and
    store the result in the first parameter
  */
  void SUB(VAR& var, VAR v, VAR v2);

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
  void MUL(VAR& var, std::vector<VAR> mulList);
  
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
  void DIV(VAR& var, VAR v, VAR v2);
  

};


