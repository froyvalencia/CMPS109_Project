/*
  Instruction Header File

  Expected Instrution Labels in our instruction lines
 
  INSTRUCTUION, NUM OF PARAMS, PARAMETERS, 
  ADD, SUB, MUL, DIV, ASSIGN, OUT, SET_STR_CHAR, LABEL ,JMP, JMP(Z/NZ), JMP(GT/LT/GTE/LTE), SLEEP
  
  Instruction class will hold and handle all of our instruction methods that we will expect as input.
*/





#ifndef INS_H
#define INS_H
<<<<<<< HEAD
#include <sstream>
=======
#include <map>
#include <vector>
#include <string>
>>>>>>> 00d92d04cf7018416aae0fcc725e40b54b06e133
#include <iostream>
class Instruction {  
private: 
protected:
public:
<<<<<<< HEAD
=======
  
>>>>>>> 00d92d04cf7018416aae0fcc725e40b54b06e133
  //constructor
  Instruction();
  //desctructor
  ~Instruction();
  virual void execute(stringstream & ss)=0;
};
#endif
