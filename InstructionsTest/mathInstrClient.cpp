#include <algorithm>
#include <iostream>
#include <string>    
#include <sstream>
#include <fstream>
#include <map>
#include <vector>
#include "Instruction.h"
#include "Parser.h"
#include "Real.h"
#include "Numeric.h"
#include "Char.h"
#include "String.h"
#include "VAR.h"
#include "Parser.h"
#include "Instruction.h"
#include "Add.h"
#include "Sub.h"
#include "Mul.h"
#include "Div.h"
#include "Equals.h"
#include "Assign.h"
#include "Out.h"
#include "Label.h"
#include "Jump.h"
#include "SET_STR_CHAR.h"
#include "Label.h"
#include "Jump.h"
#include "JMPZ.h" 
#include "JMPNZ.h" 
#include "JMPGT.h"
#include "JMPLT.h" 
#include "JMPGTE.h"
#include "JMPLTE.h" 

using namespace std;
map<int, vector<string> > myMap;
int main(){
  map<string, VAR *> objMap;
  map<string, Instruction *> insMap;
  //holdes Vars created
  map<string, VAR *> varMap;
  //initialize VarMap
  objMap["NUMERIC"] = new Numeric();
  objMap["REAL"] = new Real();
  objMap["STRING"] = new String();
  objMap["CHAR"] = new Char();
  
  //initialize instruction map;
  insMap["EQUAL"] = new Equal(); 
  insMap["ADD"] = new Add();
  insMap["SUB"] = new Sub();
  insMap["MUL"] = new Mul();
  insMap["DIV "] = new Div();
  insMap["ASSIGN "] = new Assign();
  insMap["OUT "] = new Out();
  insMap["LABEL"] = new Label();
  insMap["JMP"] = new Jump();
  insMap["SET_STR_CHAR"] = new SET_STR_CHAR();
  insMap["GET_STR_CHAR"] = new GET_STR_CHAR();



  vector<string> ins = {"EQUAL","ADD","SUB","MUL","DIV","ASSIGN","OUT","GET_STR_CHAR","SET_STR_CHAR","LABEL","JMP","JMPZ","JMPNZ","JMPGT","JMPLT","JMPGTE","JMPLTE","SLEEP"};
  Parser myParse;
  myParse.parseFile("varTxt.txt");
  myMap = myParse.parseInstructions();
  cout<< "-------------------------------------------" <<endl;
  cout<<"before: " << endl;
  for(auto &i : myMap){ //reads each element in myMap. Essentially reads line per line using i.
    if(i.second.at(0) == "VAR"){
      VAR * obj = objMap[i.second.at(2)];
      var = obj->clone(i.second);
      varMap[i.second.at(2)] = var;
      delete obj;//make sure no memory leak.
    }else if(std::find(ins.begin(), ins.end(), i.second.at(0)) != ins.end()){
      cout << "Found: " <<   i.second.at(0) << endl;
      Instruction * obj = insMap[i.second.at(0)];
      if (obj != NULL) { // If can find an object with name index
        obj = obj->clone(); // Clone an object of the same type
        if(Add* op = dynamic_cast<Add*>(obj)){
          op->execute(i.second);
        }else if(Sub* op = dynamic_cast<Sub*>(obj)){
          op->execute(i.second);
        }else if(Div* op = dynamic_cast<Div*>(obj)){
          op->execute(i.second);
        }else if(Mul* op = dynamic_cast<Mul*>(obj)){
          op->execute(i.second);
        }else if(Equal* op = dynamic_cast<Equal*>(obj)){
          op->execute(i.second);
        }else if(Assign* op = dynamic_cast<Assign*>(obj)){
          op->execute(i.second);
        }else if(Label * op = dynamic_cast<Label*>(obj)){
          op->execute(i.second);
        }else if(Jump * op = dynamic_cast<Jump*>(obj)){
          op->execute(i.second);
        }else if(JumpZ * op = dynamic_cast<JumpZ*>(obj)){
          op->execute(i.second);
        }else if(JumpNZ * op = dynamic_cast<JumpNZ*>(obj)){
          op->execute(i.second);
        }else if(JumpGT * op = dynamic_cast<JumpGT*>(obj)){
          op->execute(i.second);
        }else if(JumpGTE * op = dynamic_cast<JumpGTE*>(obj)){
          op->execute(i.second);
        }else if(JumpLT * op = dynamic_cast<JumpLT*>(obj)){
          op->execute(i.second);
        }else if(JumpLTE * op = dynamic_cast<JumpLTE*>(obj)){
          op->execute(i.second);
        }else if(Sleep * op = dynamic_cast<Sleep*>(obj)){
          op->execute(i.second);
        }
        delete (obj); // delete the object
      }else if (std::find(vars.begin(), ins.end(), i.second.at(0)){
      
      } else cout << "Undefined Object Identifier\n"; 
    }
  }
  cout<<"after: "<< endl;
  return 0;
}