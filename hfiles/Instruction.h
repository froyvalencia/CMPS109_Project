/*
  @author Froylan Valencia
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
#ifndef INS_H
#define INS_H
#include<map>
#include<vector>
#include <string>
#include <iostream>

class Instruction {  
private: 
  //HELPERS
template<typename T> T ADD(T v);// { return v;}
template<typename T> T SUB(T v);// { return v;}
template<typename T> T DIV(T v);// { return v;}
template<typename T> T MULT(T v);// { return v;}
protected:
  std::map<std::string, int> labels;
public:


  Instruction();
  ~Instruction();
  
  bool isAssign(std::string opcode);
  
  bool isMath(std::string opcode);

  //returns true if s is a JUMP Instruction
  bool isJump(std::string opcode);
  
  //returns if Alpha  operation
  bool isAlpha(std::string opcode);

  //checks if valid instruction
  bool valid(std::string opcode);
  /*
    @params 3-13
    1: REAL or Numeric Variable
    Rest: Real or Numeric Variable or Constant.
    
    @description
    Adds all parameters excluding the first one and store the results in the
    first parameter.
  */
  template<typename T, typename... Args>
  T ADD(T first, Args... args);
  
  /*
    @params 3
    1: REAL or Numeric Variable
    Rest: Real or Numeric Variable or Constant.
    
    @description
    Subtract  the  third parameter  from  the second  parameter  and 
    store the result in the first parameter
  */
  template<typename T, typename... Args>
  T SUB(T first, Args... args);
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
  template<typename T, typename... Args>
  T MUL(T first, Args... args);

  /*
    @params 3
    1: REAL or Numeric Variable
    Rest: Real or Numeric Variable or Constant.
    
    @description   
    Divide the  second parameter by the  third parameter and store the 
    result in the first parameter. Note: divide by zero should be detected 
    and reported, and the program should tolerate crashes resulting from divide-by-zero exceptions.
  */
  template<typename T, typename... Args>
  T DIV(T first, Args... args);  
  
  /*
    @params 2
    1: Any Variable.
    2: Variable or constant of the same type as parameter 1.
    
    @description
    Store  the  second parameter  into  the  first parameter.
  */
  template<typename T, typename U>
  void ASSIGN(T var, U val);
  
  /*
    @params out 1-12
    Any variables or constants

    @description
    Prints  out  the  parameters to the standard output.
  */
  template<typename... A>
  void OUT(A... args);

  /*
    @params 3
    1: String variable
    2. Variable or constant representing an index.
    3: A variable or constant character.
    
    @description
    Set  a  string  character  at specific  index  to  a character.
    Note: index range  should  be  checked and  errors  should  be reported.
  */
  //T will likely be StringVar, U is the index, V is either a CharVar or a char 'x'
  template<typename T, typename U, typename V> 
  void SET_STR_CHAR(T var, U pos, V val);
  
  /*@params 3
    1: String variable
    2. Variable or constant representing an index.
    3: A variable character or constant character
    
    @description
    Store the character at the index equivalent to parameter 2 into the third parameters.
  */
  //T is String Var, U is either a index, or numeric var, V is CharVar
  template<typename T, typename U, typename V>
  char GET_STR_CHAR(T var, U pos, V val);
  
  /*
    @params 1
    1: Inline Label.

    @description
    Sets  a  placeholder  that  a  JMP instruction can go to.
  */
  void LABEL(std::string label,int line);

  /*
    @params
    1: Label name to jump to.
    
    @description
    Change  execution sequence  by  setting  the execution  pointer  
    to the first  instruction  after  the label
  */
  int JMP(std::string label);
  
  /*
    @params 2
    1: Label name to jump to.
    2: A numeric variable or constant
    @description
    Apply  the  logic  of  JMP based  on  the  condition result.
    Z:  second  parameter  is  zero
    NZ:  second  parameter  is not zero
  */
  template<typename T>
  void JMP_Z_NZ(std::string label, T val);
  
  /*
    @params 3
    1: Label name to jump to.
    2: A numeric variable or constant.
    3: A numeric variable or constant.

    @description
    Apply  the  logic  of  JMP based  on  the  comparison 
    condition  result  between the  seconds  and  the  third parameters.
    GT: P2 > P3 , GTE: P2 >= P3
    LT: P2< P3, LTE: P2<= P3
  */

  template<typename T, typename U>
  void JMP_GT_LT_GTE_LTE(std::string label, T val, U val2);

  /*
    @params
    1: A numeric variable or constant -> REAL, NUMERIC, 1, 2.3

    @description
    Suspend execution for a number of seconds.
  */
  template<typename T>
  void SLEEP(T var);
};
#endif
