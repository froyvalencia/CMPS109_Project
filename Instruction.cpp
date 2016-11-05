/*
  Instruction class  
  INSTRUTUION, NUM OF PARAMS, PARAMETERS, 
  ADD, 
  SUB,
  MUL,
  DIV,
  ASSIGN
  OUT
  SET_STR_CHAR
  LABEL
  JMP
  JMP(Z/NZ)
  JMP(GT/LT/GTE/LTE)
  SLEEP
*/

class Instruction : Machine {

private:    
protected:
  List<string>;
public:
  /*
   */
  Instruction();

  /*    
   */
  ~Instruction();
  
  
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
  

  /*
    @params 2
    1: Any Variable.
    2: Variable or constant of the same type as parameter 1.
    
    @description
    Store  the  second parameter  into  the  first parameter.
  */
  void ASSIGN(); //here is where create a var
  
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
    Set  a  string  character  at specific  index  to  a character.
    Note: index range  should  be  checked and  errors  should  be reported.
  */
  void SET_STR_CHAR();

  
  
  /*
    @params 1
    1: Inline Label.

    @description
    Sets  a  placeholder  that  a  JMP instruction can go to.
  */
  void LABEL();

  /*
    @params
    1: Label name to jump to.

    @description
    Change  execution sequence  by  setting  the execution  pointer  
    to the first  instruction  after  the label
  */
  void JMP();
  
  /*
    @params 2
    1: Label name to jump to.
    2: A numeric variable or constant
    @description
    Apply  the  logic  of  JMP based  on  the  condition result.
    Z:  second  parameter  is  zero
    NZ:  second  parameter  is not zero
   */
  void JMP_Z_NZ();

  /*
    @params 3
    1: Label name to jump to.
    2: A numeric variable or 
    constant.
    3: A numeric variable or 
    constant.
    @description
    Apply  the  logic  of  JMP based  on  the  comparison 
    condition  result  between the  seconds  and  the  third parameters.
    GT: P2 > P3
    LT: P2< P3
    GTE: P2 >= P3
    LTE: P2<= P3
  */
  void JMP_GT_LT_GTE_LTE();
  
  /*
    @params
    1: A numeric variable or 
constant
    @description
    Suspend execution for a number of seconds.
   */
  void SLEEP();
};


