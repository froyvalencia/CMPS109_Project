/*
@author Froylan Valencia

*/
#include "Instruction.h"
Instruction::Instruction() { 
   labels = std::map< std::string, int>();
}
//
Instruction::~Instruction() { }

//
bool Instruction::isMath(std::string opcode){
  std::vector<std::string> math = {"ADD", "SUB", "MUL", "DIV", "OUT"}; 
  if ( std::find(math.begin(), math.end(), opcode) != math.end() )
    return true;
  return false;
}
//returns true if s is a JUMP Instruction
bool Instruction::isJump(std::string opcode){
  std::vector<std::string> jumps = {"JMP","JMPZ","JMPNZ","JMPGT","JMPLT","JMPGTE","JMPLTE" };
  if ( std::find(jumps.begin(), jumps.end(), opcode) != jumps.end() )
    return true;
  return false;
}

//returns if Alpha  operation
bool Instruction::isAlpha(std::string opcode){
  std::vector<std::string> alpha = {"SET_STR_CHAR", "GET_STR_CHAR"};
  if ( std::find(alpha.begin(), alpha.end(), opcode) != alpha.end() )
    return true;
  return false;  
}
//checks if valid instruction
bool Instruction::valid(std::string opcode){
  std::vector<std::string> ins = { "ADD","SUB","MUL","DIV","OUT","ASSIGN","SET_STR_CHAR", "GET_STR_CHAR", "LABEL", "JMP", "JMPZ", "JMPNZ","JMPGT","JMPLT","JMPGTE","JMPLTE" };
  if ( std::find(ins.begin(), ins.end(), opcode) != ins.end() )
    return true;
  return false;
}

//HELPERS
template<typename T> T Instruction::ADD(T v) { return v;}
template<typename T> T Instruction::SUB(T v) { return v;}
template<typename T> T Instruction::DIV(T v) { return v;}
template<typename T> T Instruction::MULT(T v) { return v;}

/*
  @params 3-13
  1: REAL or Numeric Variable
  Rest: Real or Numeric Variable or Constant.
  
  @description
  Adds all parameters excluding the first one and store the results in the
  first parameter.
*/
template<typename T, typename... Args>
T Instruction::ADD(T first, Args... args) {
  return first + ADD(args...);
}
 
/*
  @params 3
  1: REAL or Numeric Variable
  Rest: Real or Numeric Variable or Constant.
  
  @description
  Subtract  the  third parameter  from  the second  parameter  and 
  store the result in the first parameter
*/
template<typename T, typename... Args>
T Instruction::SUB(T first, Args... args) {
  return first - SUB(args...);
}

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
T Instruction::MUL(T first, Args... args) {
  return first  *  MULT(args...);
}

//  void MUL(VAR& var, std::vector<VAR> mulList);

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

template<typename T, typename... Args>
T Instruction::DIV(T first, Args... args) {
  return first / DIV(args...);
}

/*
  @params 2
  1: Any Variable.
  2: Variable or constant of the same type as parameter 1.
  
  @description
  Store  the  second parameter  into  the  first parameter.
*/

template<typename T, typename U>
void Instruction::ASSIGN(T var, U val){
  var.setValue(val);
}

//overwrite << for OUT
template<typename T>
std::ostream& operator<<(std::ostream& os, const T& var) {  
  os << var;
  return os;
}  

/*
  @params out 1-12
  Any variables or constants

  @description
  Prints  out  the  parameters to the standard output.
*/

template<typename... A>
void Instruction::OUT(A... args){
  std::vector<A...> vars;
  for(auto var : vars){
    std::cout << var << std::endl;
  }
}

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
void Instruction::SET_STR_CHAR(T var, U pos, V val){
  int index = pos; 
  var[index] = val;
} 
/*@params 3
  1: String variable
  2. Variable or constant representing an index.
  3: A variable character or constant character
  
  Store the character at the index equivalent to parameter 2 into the third parameters.
*/
//T is String Var, U is either a index, or numeric var, V is CharVar
template<typename T, typename U, typename V>
char Instruction::GET_STR_CHAR(T var, U pos, V val) {
  int index = pos;
  char c = var[index];
  val.setValue(c);
}

/*
  @params 1
  1: Inline Label.

  @description
  Sets  a  placeholder  that  a  JMP instruction can go to.
*/
//void LABEL(string label,int line);
void Instruction::LABEL(std::string label,int line){
  labels[label] = line + 1;
}
/*
  @params
  1: Label name to jump to.
  
  @description
  Change  execution sequence  by  setting  the execution  pointer  
  to the first  instruction  after  the label
*/
int Instruction::JMP(std::string label){
  return labels[label];
}

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
void Instruction::JMP_Z_NZ(std::string label, T val){
    if("JMPZ") {

    }else {

    }
}
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
  GT: P2 > P3, GTE: P2 >= P3
  LT: P2< P3, LTE: P2<= P3
*/
template<typename T, typename U>
void Instruction::JMP_GT_LT_GTE_LTE(std::string label, T val, U val2){

}
/*
  @params
  1: A numeric variable or constant
  @description
  Suspend execution for a number of seconds.
*/
template<typename T>
void Instruction::SLEEP(T var){
  //int mSeconds = (1000000) * var;// get mseconds
  //usleep(mSeconds);
}
